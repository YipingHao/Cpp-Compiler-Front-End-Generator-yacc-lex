# C++编译器前端生成器（lex yacc）

## 介绍
C++编译器前端生成器:按照编译器领域经典教科书——龙书上描述的算法编写的编译器前端生成器，包含词法分析器生成器和文法分析器生成器。支持LR(0)和LR(1)两种文法分析方式。
它只有两个文件，automata.cpp,automata.h。词法分析不支持向前看（话说这个功能需要的人很多吗？）词法分析目前也不支持中文，只支持ASCII编码的文件。对于一般用户，这可能是个大问题。目前还没来得及改进。词法分析器支持NFA,到DFA的转换并支持DFA的状态缩减。
## 软件架构
项目用到了一些模板类，均为作者手写并包含在了automata.h中，这些类被包含在了一个命名空间中。
就像cjson一样只有两个代码文件，对于用户而言相当轻量化。这个生成器没有名字，简称为无名生成器。无名生成器已经可以供用户使用，但是用户手册没有写完。

## 安装教程

1.  使用它的人只需要编译automata.cpp，链接编译后的结果就可以使用。另外用户需要在代码文件中#include"automata.h"。
2.  在 automata.h中定义的全部内容都在`namespace hyperlex`里面，使用者请勿在自己的代码中使用`using namespace hyperlex`。作者定义了自己的模板比如`vector`模板，所以使用命名空间可能会引起冲突。
2.  作者使用的测试代码写在main.cpp，AutoHeader.h里面。这个文件包含了之前某些项目内的无用代码所以显得十分庞大。如果对测试项目的正确性不感兴趣无需了解main.cpp。
3.  测试用的参数文件是test_item.txt,测试用的数据文件有很多都在目录TestFile里面。测试用的文法规则大部分来自龙书的例子。

## 使用说明

### 您可以在三种不同的深度上使用本软件。
####     1. 简单使用级别:
简单使用仅需了解接口类`InputPanel`。通过调用`InputPanel`的`public`成员函数，用户就可以完成输入文件到词法分析器DFA和文法分析表的转换。
#### 	2. 语法树与词法表级别：
软件内部有两个`class`分别叫`Morpheme`和`GrammarTree`。它们是简易的词法表模板和语法树模板，有了程序输出的词法分析器和文法分析表。这两个类可以方便的从源代码计算得到对应的文法树。这两个类的使用说明见后文。
#### 	3. 深入挖掘级别：
调用内部的`NFA`, `regExp`等功能来完成更深层次功能。
###  class InputPanel简介：
`InputPanel`声明在 automata.h文件 564行它有目前有六个公有成员函数作为接口供用户调用。分别是

```
int build(FILE* fp);
int build(const char* input);
void demo(FILE* fp) const;
void ErrorDemo(FILE* fp) const;
int printL(FILE* fp, const char* nameL)const;
int printG(FILE* output, FILE* infor, const char* nameG)const;
```

####        1.  编码规则与build
build方法接受一个可以读的输入文件或者一个字符串(不是文件名而是完整的文件内容)作为输入，文件中字符编码格式应为ASCII.
####        2.  输入信息展示
demo方法展示读入文件的信息，如果发现输入文件有一些错误，那么它可以自动调用`ErrorDemo`方法展示错误。用户也可以主动使用`ErrorDemo`方法输出错误信息。
####        3. 输出打印
 `printL`方法打印Cpp风格的DFA代码，这个DFA封装在一个名字为`nameL`的类中. `printG`打印一个LR分析器对应的分析表（状态转移表等等），这个表格封装在一个名字为`nameG`的类中。这个类对应的代码输出在`FILE*output`中，而`FILE* infor`是文法分析对应的信息。
目前这两个文件指针都不可以为NULL。
####        4.  返回信息
如果`InputPanel`没有正确的完成对输入文件的解析，调用`printL`返回-1，没有发现错误返回0。其次如果用户没有合理的设置正则表达式优先级返回-2。
用户输入的文法如果是lr0的`printG`返回LR0分析表（状态转移表等等），此时`printG`返回 0。用户输入的文法如果是lr1的`printG`返回LR1分析表（状态转移表等等），此时`printG`返回 1。
如果用户输入的文法超过了这两种文法分析器生成器的能力，`printG`返回2。此时`FILE*output`不会有任何输出。如果`InputPanel`没有正确的完成对输入文件的解析，调用`printG`返回-1。

####  5.使用范例
```
int sample(void) {
    InputPanel panel;
    FILE* input = fopen("sample.txt", "r");
    if (!input) return -5;

    // 解析输入文件
    int buildResult = panel.build(input);
    if (buildResult != 0) {
        panel.ErrorDemo(stderr); // 输出错误信息
        fclose(input);
        return buildResult;
    }
    panel.Demo(stdout);// 输出输入信息

    // 生成DFA代码
    FILE* dfaOut = fopen("DFA.cpp", "w");
    if (!dfaOut) return -6;
    int printLResult = panel.printL(dfaOut, "LexerDFA");
    if (printLResult != 0) {
        fclose(dfaOut);
        return printLResult;
    }

    // 生成LR分析表
    FILE* parserOut = fopen("ParserTable.cpp", "w");
    FILE* infoOut = fopen("ParserInfo.txt", "w");
    if (!parserOut) return -7;
    if (!infoOut) return -8;

    int printGResult = panel.printG(parserOut, infoOut, "ParserTable");
    
    fclose(input);
    fclose(dfaOut);
    fclose(parserOut);
    fclose(infoOut);
    return printGResult;
}
```

## 输入文件格式

### 1.  完整的输入文件例子
这是一个完整的输入文件的例子，这个文件在Testfile目录中，是sample.txt。这个文件对应的输出在本文件最后部分。
```
lexical:{
    void:
    {
        num: [0-9];
        letter: [a-z]|[A-Z];
    }
    id: id(+5): (<letter> | _) (<letter> | _ | <num>)+;
    number: {integer: ('-'|'+')?<num>+;}
    operator:
    {
        sum: '+';
        multi: '*';
    }
    value: value: '=';
    braket:
    {
        left:'(';
        right: ')';
    };
};
grammar: EXP:
{
    LEFT: id;
    EXP: LEFT value RIGHT;
    RIGHT:{
        single: MULTI;
        multi: RIGHT sum MULTI; //(MULTI * UNIT)
    }
    MULTI:
    {
        single: UNIT;
        multi: MULTI multi UNIT; //(MULTI * UNIT)
    }
    UNIT:
    {
        const: integer;
        xyz: id;
        alot: left RIGHT right;//(RIGHT)
    }
}

```

### 2.  禁止单独输入文法规则
用户可以选择在文件中，只写词法规则，也可以选择在文件中同时写词法和文法规则，但是不能单独的写文法规则。如果用户需要单独的文法规则，那么可以随便写一个补位性质的词法分析规则。词法规则的定义由关键字lexical加上一个冒号开头，所有的词法规则需要被花括号括起来。文法规则的定义由关键字`grammar`加上一个冒号开头，所有的文法规则需要被花括号括起来。此外文法规则需要在关键字之后指定一个非终结符号作为接受的符号。
```
lexical:{
    void: 
    {
        num: [0-9];
        letter: [a-z]|[A-Z];
    }
    id: id(+5): (<letter> | _) (<letter> | _ | <num>)+;
    void: hexa: [0-9] | [a-f] | [A-F];
}
grammar: TEXT:
{
    TEXT：
    {
        rules1: ****;
        rules2: ****;  
    }
}
```
### 3.  输入文件的词法与文法
无名生成器分析用户文件所用的词法分析器和文法分析器也是由无名生成器自动生成的。所以在Testfile目录里面，你可以看到本分析器的词法分析和文法分析规则文件input.txt。用户可以从此文件实际上包含了大部分输入文件的格式细节与格式规范。
### 4.  保留字与标识符
输入文件接受C语言风格的标识符，但是与C语言不同的是，无名生成器接受的标识符的最小长度是2，单字母不能作为合法的标识符。此外输入文件有四个保留字`all`，`grammar`，`lexical`，`void`。
### 5.  格式细则：
输入文件广泛使用C语言风格的花括号，右花括号后面是否跟着一个分号都可以，但是不能跟着多个。
输入文件的词法分析之后丢弃所有的空格换行和水平制表符号。输入文件支持C语言风格的注释，这个注释由词法分析器识别后丢弃，具体注释的词法请参阅input.txt。

### 6.  词法分析输入格式
#### 正则表达式的命名       
 每一个输入的正则表达式都需要被命名，它们的名字可以是保留字或者标识符。每一个被输入的正则表达式都需要被指定一个类型或者说群组，群组名必须是标识符或者保留字`void`。`void`群组的正则表达式不会作为词法分析器的输出，而只成为预制的模块，用于简化后续的正则表达式的输入。除了`void`组,任何两个群组的名字不能重名，任何两个正则表达式的名字也不能重名。所有`void`群组内的表达式会被合并。命名后跟随的冒号不可省略不可重复。
```
void: 
{
    num: [0-9];
    letter: [a-z]|[A-Z];
}
id: id(+5): (<letter> | _) (<letter> | _ | <num>)+;
void: hexa: [0-9] | [a-f] | [A-F];//两个void组是合法的
```
以下的定义是不合法的，视为两个组的重名:
```
reserved: reserved: int；
reserved: {
    double(+5): double;
    char: char;
}
```
如果某个组的正则表达式唯一，则可以省略花括号。但是以下的定义是不合法的，组名不会自动成为唯一的正则表达式的名字:
```
id: (<letter> | _) (<letter> | _ | <num>)+;
```
#### 正则表达式的优先级
可以用名称后跟随括号的方法为任何一个非`void`群组或者任何一个非`void`群组内正则表达式指定一个优先级。优先级必须是正整数并且显式的使用正号。为群组指定了优先级后依旧可以额外指定群组内的任意一个正则表达式的优先级，覆盖群组的优先级。

```
reserved(+6): 
{
    int: int;// 最终优先级被识别为6
    double(+5): double; // 最终优先级被识别为5
    char: char; // 最终优先级被识别为6
    wrong(7): wrong; //这是不合法的输入， 7前面没有显式的使用正号
}

```

不显式的指定优先级则默认优先级为0。

```
reserved: 
{
    int: int;// 最终优先级被识别为0
    double: double(+5); // 最终优先级被识别为5
    char: char; // 最终优先级被识别为0
}
operator:plus:'+'; // 最终优先级被识别为0
value(+7):plus(+5):'+'; // 最终优先级被识别为5
```

如果两个正则表达式接受相同的的字符串，则最终串会被识别为优先级数值更大的正则表达式。优先级不影响最长可接受原则。假定一个正则表达式A接受C语言的保留字`int`另一个正则表达式B接受C语言风格的标识符。那么遇到`"inta"`的时候，无论两者优先级如何，都会被识别为标识符。但是如果B的优先级更高那么会导致无论如何A都不会被接受，进而导致一个接受状态死掉。软件会自动检测这种情况是否出现，如果出现调用`printL`时返回-2。


#### 正则表达式的格式

输入文件接受一般字符和不保留字符：一般字符格式和C语言的字符常量格式相同,所以需要两个单引号。而不保留字是全体可以合法出现在C语言风格标识符中的字符，比如英文字母。使用不保留字不需要单引号。本程序和常见的正则表达式系统完全相反，常见的正则表达式系统只有保留字符和一般字符，保留字符需要转义。可以用方括号和减号表示字符范围，也可以给单个字符套一个方括号，但是无法直接在方括号内并列字符。

```
single_char: 
{
    common_example_01: '*';     // 一般字符例子1
    common_example_02: '\n';    // 一般字符例子2
    common_example_03: '\x2a';  // 一般字符例子3
    common_example_04: 'a';     // 一般字符例子4

    unreserved: [a-z] | [A-Z] | [0-9] | _ ;// 不保留字符
   
    range_example_01: ['a'-z];    //字符范围表示例子
    range_example_02: ['a'];      //字符范围表示例子
    range_example_03: ['a'-zA-Z]; //不合法
    range_example_04: [ABCD];     //不合法
}
```
可以用`*`后缀表示重复0次或者任意多次,可以用`+`后缀表示重复1次或者任意多次,可以用`?`后缀表示重复0次或者1次,可以用`|`表示逻辑或,可以直接连接两个正则表达式表示正则表达式的拼接。后缀的优先级最高，逻辑或的优先级最低，拼接的优先级居中。可以用圆括号`()`将正则表达式的一部分变成整体，可以用尖括号中标识符的方式`<id>`引用上文中已经定义的正则表达式，其中标识符对应正则表达式名，正则表达式名可以是保留字，但是无法对保留字对应的正则表达式形成引用。

```
void: 
{
    num: [0-9];
    letter: [a-z]|[A-Z];
}
id: id（+5）: (<letter> | _) (<letter> | _ | <num>)+;
integer: integer: '+'<num>+;
```
如果定义的正则表达式名字正是正则表达式本身，那么可以将正则表达式本身和冒号省略，这种情况多见于保留字的定义中。

```
C_reserved: 
{
    int: int;
    double: double;
}
C_reserved_another_defination: 
{
    int;
    double;
}
```


### 7.  文法规则输入格式
####   命名规则  
文法分析器生成器接受的词法单元（终结符号）正是词法规则中全体非`void`群组的正则表达式名。所有文法规则依据规则定义的文法符号(非终结符号)自然分组。每一组内的每一个产生式都必须被命名，与词法规则不同的是，同一组内的两个产生式不能重名，而不同组内的两个产生式可以重名。 当然任意两个组名不能重名。非终结符号名必须是标识符，保留字是不合法的。命名后跟随的冒号不可省略不可重复。非终结符号名也不可和终结符号名重名，产生式名字可以和终结符号名重名。
```
grammar: TEXT: {
	LEXICAL: {
		single: RegGROUP; 
		multi: LEXICAL RegGROUP;};
	TEXT: {
		OnlyL: lexical BEGIN LEXICAL END;
		LG: lexical BEGIN LEXICAL END grammar colon identifier BEGIN GRAMMAR END;};
	RegGROUP: {
		single: RegGROUPNAME colon RegDEF;
		multi: RegGROUPNAME BEGIN REGDEFS END;
        };
        BEGIN: colon braceL; 
        //未完

};
```
上述例子中`TEXT`, `LEXICAL`, `RegGROUP`, `BEGIN`是定义的非终结符号。注意到`grammar: `后面跟的 `TEXT:`，它是文法分析器最终接受的文法单元对应的非终结符号，这个终结符号的产生式不必定义在最开头。可以将它看作是对整个文法分析规则系统的命名，这是不可缺少的。 
一组内可以只有一个产生式。此时可以将花括号去掉，同时规则名自动是非终结符号名。
```
grammar: ****: {
        WRONG: wrong: colon braceL;     //非法
        CORRECT: colon braceL;          //合法
        CORRECT: wrong: {colon braceL;} //合法
}
```
以下的定义是不合法的，视为两个组(非终结符号)的重名:
```
    END:{
	    full: braceR semicolon;
	    half: braceR;
    }
    END:{
	    extra: braceR semicolon semicolon;
    }
```

####   保留字规则
 如果`all`没有被用户输入的词法规则定义为词法单元(终结符号)那么all不能出现在文法产生式体内，否则报错。反之`all`被定义为词法单元，当`all`出现在文法产生式体内它会被视为一个终结符号。如果`void`被用户输入的词法规则定义为一个词法单元(终结符号)，那么它将不能表达一个空产生式，换言之整个，输入文件系统不能再接受空符号。

####   产生式定义
每一个产生式体都是单纯的重复非终结符号和终结符号对应的标识符和保留字。当然需要用空格分割它们。定义结束后分号是必要的，不可缺少。产生式体中的标识符如果不是词法单元，那么就会被识别为非终结符号，如果分析结束后没有找到此符号的定义则会报错。

## 输出文件格式
相较于输出一个词法分析器加上文法分析器的完整代码，我们更倾向于输出词法分析器和文法分析器的”驱动表“。这种做法有更高的灵活度。如果用户不像动手写分析器，我们提供两个类将输出的”驱动表“转化为完整代码。
### 1.  词法分析器输出格式
InputPanel的成员函数`int printL(FILE* fp, const char* nameL)const`输出的词法分析器的驱动表是一个结构体`struct nameL`，的声明和定义，声明格式如下:
```
struct <nameL>
{
	enum regular
	{
		_reg_name_01_ = 1,
		_reg_name_02_ = 2,
        // more and more
	};
	enum group
	{
		_reg_group_01___ = 1,
		_reg_group_02___ = 2,
		// more and more
	};
	static int next(int state, const char c);
	static int action(int state);
	static int GroupGet(int state);
};
```
其中枚举类型`regular`可以帮助将定义的正则表达式名字和它们的编号对应起来，枚举类型`group`可以帮助将定义的正则表达式种类和它们的编号对应起来。两个编号都从1开始。在代码中使用枚举类型代替具体的编号有更好的可读性和可维护性。`static int next(int state, const char c)`则是正则表达式对应的DFA的状态转移函数。它接受当前状态和一个字符，返回DFA的下一个状态。`static int action(int state);`的输入是DFA的状态，返回值是当前DFA的接受状态，如果当前状态没有识别出任何东西则返回0。除了0其余返回值和`enum regular`相对应。`static int GroupGet(int state);`输入一个接受状态，换言之一个`enum regular`，返回当前此法单元对应的群组。三个成员函数内部都无`static`类型变量不申请堆内存，是”纯函数“。

如果`InputPanel`没有正确的完成对输入文件的解析，调用`int printL`返回-1，如果优先级设置问题则返回-2其余返回0。样例输入文件输出的结构体作为一个例子出现在说明的最后部分的附录中。


### 2.  文法分析表输出格式
InputPanel的成员函数`int printG(FILE* output, FILE* infor, const char* nameG)const;`输出的文法分析器驱动表是一个结构体`struct nameG`，的声明和定义，声明格式如下:
```
struct <nameG>
{
	enum type
	{
		accept = 0,
		error = 1,
		push = 2,
		reduce = 3
	};
    enum nonterminal
    {
		nonterminal_name00 = 0,
		nonterminal_name01 = 1,
		//大量重复
        nonterminal_namelast = NonTerminalCount - 1
	};
    enum rules
    {
		rules_name00 = 0,
		rules_name01 = 1,
		//大量重复
        rules_namelast = RulesCount - 1
	};
	static const size_t StateCount;
	static const size_t NonTerminalCount;
	static const size_t TerminalCount;
	static const size_t RulesCount;
	static const int GOTO[StateCount][NonTerminalCount];
	static const int ACTION[StateCount][TerminalCount];
	static const int RulesToSymbol[RulesCount];
	static const int RulesLength[RulesCount];
	static const char* const RulesName[RulesCount];
};
```
其中枚举类型`type`是文法分析动作种类与整数的关系。成员数组`ACTION[StateCount][TerminalCount]`存储当前状态下，当前终结符号下该有的动作。成员数组`GOTO[StateCount][NonTerminalCount]`存储当前状态下，当前非终结符号下该有的动作。存储的`int`值是对4取模得到动作种类，除以整数4才得到具体的动作。对于`GOTO`而言有意义的动作种类只有两个`push`和`error`，然而存储是还是用了四个状态。`RulesToSymbol`存储当前产生式对应的非终结符号，`RulesToSymbol`存储当前产生式的长度，`RulesName` 存储当前产生式的名字。

其中枚举类型`nonterminal`可以帮助将定义的非终结符号和程序产生的编号对应起来。其中枚举类型`rules`可以帮助将定义的文法产生式和它们的编号对应起来。可以用枚举类型`rules`寻址`RulesToSymbol`，`RulesToSymbol`和`RulesName`。可以用枚举类型`nonterminal`寻址`GOTO[StateCount][NonTerminalCount]`第二个维度。样例输入文件输出的结构体作为一个例子出现在说明的最后部分的附录中。

```
int temp = <nameG>::ACTION[top][input[head].accept];
int information = temp / 4;
<nameG>::type type = (typename <nameG>::type)(temp % 4);
switch (type)
{
case <nameG>::accept:
	//分析完成
	break;
case <nameG>::error:
    //报错
	break;
case <nameG>::push:
	//移入状态information
	break;
case <nameG>::reduce:
    //规约状态到information
    int symbol = T::RulesToSymbol[information];
    int length = T::RulesLength[information];
    //弹出栈顶length个元素，我们规约得到的符号是symbol
    temp = <nameG>::GOTO[stack.top()][symbol];
    nextState = temp / 4;
    nextAction = temp % 4;
    if(nextAction == <nameG>::push) 
        //将nextState压入栈
    else
        //报错
    break;
}
```
### 3. `class Morpheme` 使用简介
在得到程序输出的DFA之后可以使用`class Morpheme`对输入的文件或者字符串进行简单的词法分析。
#### 1. 定义概览
在automata.h定义如下:
```
class Morpheme
{
public:
	struct result
	{
		int accept;
		int category;
		size_t length;
		size_t begin;
	};
	Morpheme();
	~Morpheme();
	char* Copy(size_t site) const;
	void append(const BufferChar& input, int accept, int category);
	void AppendEnd(int TerminalCount);
	void UnitMove(size_t from, size_t to);
	void CountReset(size_t count);
	void Demo(FILE* fp) const;
	size_t GetCount(void) const;
	const char* GetWord(size_t site) const;
	const result& operator[](const size_t target) const;

	char GetChar(size_t site) const;

	template<typename T> int Build(const char* reg);
	template<typename T> int Build(FILE* fp);
protected:
	size_t count;
	//list<size_t> begin;
	//list<size_t> length;
	vector<result> lex;
	vector<char> storage;
	template<typename T> bool RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate);
};
```
其中 `struct result` 是每一个词法单元的信息， `int accept`是词法单元的编号，对应`struct <nameL>`中的`enum regular`， `category`是词法单元的种类，对应`struct <nameL>`中的`enum group`。 `size_t length`是词法单元的字符串长度， `size_t begin`是它在存储中首地址的偏移。所有的词法单元对应的字符串按输入文件的顺序存储在`protected:vector<char> storage`中。
其中每一个词法单元对应的字符串末尾都添加了`'\0'`。`size_t count;`是识别到的词法单元数目，等于`lex.count()`。`lex`存储全体词法单元信息。
#### 2. 对输入进行词法分析
```
template<typename T> int Build(const char* reg);
template<typename T> int Build(FILE* fp);
```
它拥有两个成员函数，分别接受待词法分析输入文件的文件指针或者直接输入一个待词法分析的串。`typename T`即是`printL`打印的类`struct <nameL>`。
调用例子如下:
```
struct Reg
{
	enum regular{/*definations*/};
	enum group{/*definations*/};
	static int next(int state, const char c);
	static int action(int state);
	static int GroupGet(int state);
};
int sample(input)
{
    Morpheme eme;
    int error;
    error = eme.Build<Reg>(input);
    eme.Demo(stdout);
    return error;
}
```

#### 3. 常用成员函数

`void Demo(FILE* fp) const;`展示词法分析的结果。
`const result& operator[](const size_t target) const;`返回第`target`个词法单元信息，合法范围是从`0`到`count-1`。不做范围检测。
`const char* GetWord(size_t site) const;`返回第`target`个词法单元对应的字符串在`all`中的首地址。`target`合法范围是从`0`到`count-1`。不做范围检测。不可以对返回的指针释放内存。
`char* Copy(size_t site) const;`返回第`target`个词法单元对应的字符串。`target`合法范围是从`0`到`count-1`。不做范围检测。使用结束后应该对返回的指针释放内存。此成员函数返回的字符串指针的内存由`malloc`分配。
`size_t GetCount(void) const;` 返回成员变量`size_t count;`的值。
### 4. `class GrammarTree` 使用简介
#### 1. 定义概览
在automata.h定义如下:
```
class GrammarTree
{
public:
	GrammarTree();
	~GrammarTree();
	struct TreeInfor
	{
		bool rules;// rules: false —— 此为叶子节点，对应词法终结符（lexical terminal symbol），
		size_t site;// site 表示该词法单元在词法表中的位置（即 Morpheme::storage 中的索引） 
		size_t label;// rules: true  —— 此节点可能为非叶子节点（对应产生式规则），
		void* infor; // site 表示对应的产生式规则编号（即 T::RulesToSymbol 中的索引）  
	};
	void Demo(FILE* fp, const Morpheme& input, const char* const* RulesName) const;
	void clear(void);
	template<typename T> int build(const Morpheme& input);

	tree<TreeInfor>* GT;
protected:
};

template <class T> class tree
{
public:
	tree();
	~tree();
	void clear(void);
	void build(vector<tree<T>*>& input);
	void build(vector<tree<T>*>& input, size_t offset);
	void PostOrderTraversal(vector<tree<T>*>& output);
	T& root(void);
	const T& root(void) const;
	size_t ChildCount(void) const;
	tree<T>* child(size_t No) const;
	struct Iterator
	{
		tree<T>* target;
		int state;
	};
	class PostIterator
	{
	public:
		PostIterator() {}
		~PostIterator() {}
		void initial(tree<T>* root);
		int& state(void);
		tree<T>*& target(void);
		void next(void);
		bool still(void);
	protected:
		vector<Iterator> stack;
		
	};
private:
	array<tree<T>*> childs;
	T content;
	tree<T>* parent;
	size_t No;
};
```
#### 2. 对输入进行文法分析
```
template<typename T> int build(const Morpheme& input);
```
它拥有一个成员函数别接受待词法分析结果`const Morpheme& input`作为输入的串。`typename T`即是`printG`打印的类`struct <nameG>`。它通过`void Demo(FILE* fp, const Morpheme& input, const char* const* RulesName) const;` 可以在屏幕打印输出，输出需要一个字符串数组`const char* const* RulesName`作为参数。
调用例子如下:
```
struct Reg
{
	enum regular{/*definations*/};
	enum group{/*definations*/};
	static int next(int state, const char c);
	static int action(int state);
	static int GroupGet(int state);
};
struct Panel
{
	enum type{/*definations*/};
    enum nonterminal{/*definations*/};
    enum rules{/*definations*/};
	static const size_t StateCount;
	static const size_t NonTerminalCount;
	static const size_t TerminalCount;
	static const size_t RulesCount;
	static const int GOTO[StateCount][NonTerminalCount];
	static const int ACTION[StateCount][TerminalCount];
	static const int RulesToSymbol[RulesCount];
	static const int RulesLength[RulesCount];
	static const char* const RulesName[RulesCount];
};
int sample(input)
{
    Morpheme eme;
    GrammarTree Tree;
    int error;
    error = eme.Build<Reg>(input);
    if (error != 0) return error;
    eme.Demo(stdout);
    
    error = Tree.build<Panel>(eme);
    if (error != 0) return error;
    Tree.Demo(stdout, eme, Panel::RulesName);

    return error;
}
```
#### 3. 遍历语法树做您想做的

可以使用类型`iterator`帮助遍历语法树，示例代码如下。
```
void sample(GrammarTree & input)
{
    tree<TreeInfor>* now;
    hyperlex::tree<GrammarTree::TreeInfor>* Tree;
    hyperlex::tree<GrammarTree::TreeInfor>::PostIterator iterator;
    iterator.initial(input.GT);
    while (iterator.still())
    {
	    now = iterator.target();
	    if (iterator.state() == 0)
	    {
            //  先序经过now节点
	    }
        else
        {
            //  后序经过now节点
        }
	    iterator.next();
    }
}

```

## 软件架构简介与版本

### 代码中的垃圾
  由于无名生成器分析用户文件所用的词法分析器和文法分析器也是由无名生成器自动生成的。为了完成这一自举，代码中留下了很多无用的脚手架。
### 已知问题
目前版本为1.0也就是刚刚可以用的地步。目前有一个小bug没有修：空产生式会导致打印的文法分析表的产生式长度一项有一些异常。下个小版本修理这个东西。
### 异常与内存管理
本软件不抛出任何异常。内部混合使用malloc与new，并且使用时不检查返回值是否为NULL。可以做到malloc与free绑定，new与delete绑定。

### 线程安全
本软件内无任何静态变量，全局变量。线程安全。

### C++版本
依据C++03版本，没有现代C++的高级特性。

## 附录

### 1. 输出样例

#### 读入文件sample.txt后软件输出的词法分析器

```
struct regular
{
        enum regular
        {
                _id_ = 1,
                _integer_ = 2,
                _sum_ = 3,
                _multi_ = 4,
                _value_ = 5,
                _left_ = 6,
                _right_ = 7
        };
        enum group
        {
                _id___ = 1,
                _number___ = 2,
                _operator___ = 3,
                _value___ = 4,
                _braket___ = 5
        };
        static int next(int state, const char c);
        static int action(int state);
        static int GroupGet(int state);
};
int regular::next(int state, const char c)
{
        switch (state)
        {
        case 0:
                if(c == '(') return 6;
                else if(c == ')') return 7;
                else if(c == '*') return 4;
                else if(c == '+') return 3;
                else if(c == '-') return 8;
                else if('0' <= c && c <= '9') return 2;
                else if(c == '=') return 5;
                else if('A' <= c && c <= 'Z') return 9;
                else if(c == '_') return 9;
                else if('a' <= c && c <= 'z') return 9;
                else return 0;
        case 1:
                if('0' <= c && c <= '9') return 1;
                else if('A' <= c && c <= 'Z') return 1;
                else if(c == '_') return 1;
                else if('a' <= c && c <= 'z') return 1;
                else return 0;
        case 2:
                if('0' <= c && c <= '9') return 2;
                else return 0;
        case 3:
                if('0' <= c && c <= '9') return 2;
                else return 0;
        case 4:
                return 0;
        case 5:
                return 0;
        case 6:
                return 0;
        case 7:
                return 0;
        case 8:
                if('0' <= c && c <= '9') return 2;
                else return 0;
        case 9:
                if('0' <= c && c <= '9') return 1;
                else if('A' <= c && c <= 'Z') return 1;
                else if(c == '_') return 1;
                else if('a' <= c && c <= 'z') return 1;
                else return 0;
        }
        return 0;
}
int regular::action(int state)
{
        switch (state)
        {
        case 1:
                return 1;//id: id
        case 2:
                return 2;//number: integer
        case 3:
                return 3;//operator: sum
        case 4:
                return 4;//operator: multi
        case 5:
                return 5;//value: value
        case 6:
                return 6;//braket: left
        case 7:
                return 7;//braket: right
        }
        return 0;
}
int regular::GroupGet(int accept)
{
        switch (accept)
        {
        case 1:
                return 1;//id: id
        case 2:
                return 2;//number: integer
        case 3:
                return 3;//operator: sum
        case 4:
                return 3;//operator: multi
        case 5:
                return 4;//value: value
        case 6:
                return 5;//braket: left
        case 7:
                return 5;//braket: right
        }
        return 0;
}
```
#### 读入文件sample.txt后软件输出的文法分析器
```
struct panel
{
        enum type
        {
                accept = 0,
                error = 1,
                push = 2,
                reduce = 3
        };
        enum nonterminal
        {
                _all_ = 0,
                _LEFT_ = 1,
                _EXP_ = 2,
                _RIGHT_ = 3,
                _MULTI_ = 4,
                _UNIT_ = 5
        };
        enum rules
        {
                _all_all_ = 0,
                _LEFT_LEFT_ = 1,
                _EXP_EXP_ = 2,
                _RIGHT_multi_ = 3,
                _RIGHT_single_ = 4,
                _MULTI_multi_ = 5,
                _MULTI_single_ = 6,
                _UNIT_alot_ = 7,
                _UNIT_xyz_ = 8,
                _UNIT_const_ = 9
        };
        static const size_t StateCount;
        static const size_t NonTerminalCount;
        static const size_t TerminalCount;
        static const size_t RulesCount;
        static const int GOTO[17][6];
        static const int ACTION[17][8];
        static const int RulesToSymbol[10];
        static const int RulesLength[10];
        static const char* const RulesName[10];
};
const size_t panel::StateCount = 17;
const size_t panel::NonTerminalCount = 6;
const size_t panel::TerminalCount = 7;
const size_t panel::RulesCount = 10;
const int panel::GOTO[17][6] = { \
{1, 6, 10, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 22, 26, 30}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 46, 26, 30}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 58, 30}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 66}, \
{1, 1, 1, 1, 1, 1}};
//==============================
const int panel::ACTION[17][8] = { \
{1, 14, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 18, 1, 1}, \
{0, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 7, 1, 1}, \
{1, 34, 38, 1, 1, 1, 42, 1}, \
{11, 1, 1, 50, 1, 1, 1, 1}, \
{19, 1, 1, 19, 62, 1, 1, 19}, \
{27, 1, 1, 27, 27, 1, 1, 27}, \
{35, 1, 1, 35, 35, 1, 1, 35}, \
{39, 1, 1, 39, 39, 1, 1, 39}, \
{1, 34, 38, 1, 1, 1, 42, 1}, \
{1, 1, 1, 50, 1, 1, 1, 54}, \
{1, 34, 38, 1, 1, 1, 42, 1}, \
{31, 1, 1, 31, 31, 1, 1, 31}, \
{15, 1, 1, 15, 62, 1, 1, 15}, \
{1, 34, 38, 1, 1, 1, 42, 1}, \
{23, 1, 1, 23, 23, 1, 1, 23}};
//==============================
const int panel::RulesToSymbol[10] = { \
0,\
1,\
2,\
3,\
3,\
4,\
4,\
5,\
5,\
5};
//==============================
const int panel::RulesLength[10] = { \
1,\
1,\
3,\
3,\
1,\
3,\
1,\
3,\
1,\
1};
//==============================
const char* const panel::RulesName[10] = { \
"all->EXP ",\
"LEFT->id ",\
"EXP->LEFT value RIGHT ",\
"RIGHT->RIGHT sum MULTI ",\
"RIGHT->MULTI ",\
"MULTI->MULTI multi UNIT ",\
"MULTI->UNIT ",\
"UNIT->left RIGHT right ",\
"UNIT->id ",\
"UNIT->integer "};

```