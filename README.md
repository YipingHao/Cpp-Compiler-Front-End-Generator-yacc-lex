# C++编译器前端生成器（lex yacc）

## 介绍
C++编译器前端生成器:按照编译器领域经典教科书——龙书上描述的算法编写的编译器前端生成器，包含词法分析器生成器和文法分析器生成器。支持LR(0)和LR(1)两种文法分析方式。
它只有两个文件，automata.cpp,automata.h。词法分析不支持向前看（话说这个功能需要的人很多吗？）词法分析目前也不支持中文，只支持ASCII编码的文件。对于一般用户，这可能是个大问题。目前还没来得及改进。词法分析器支持NFA,到DFA的转换并支持DFA的状态缩减。
## 软件架构
项目用到了一些模板类，均为作者手写并包含在了automata.h中，这些类被包含在了一个命名空间中。
就像cjson一样只有两个代码文件，对于用户而言相当轻量化。这个生成器没有名字，简称为无名生成器。无名生成器已经可以供用户使用，但是用户手册没有写完。

## 安装教程

1.  使用它的人只需要编译automata.cpp，链接编译后的结果就可以使用。另外用户需要在代码文件中#include"automata.h"。
2.  在 automata.h中定义的全部内容都在namespace hyperlex里面，使用者请勿在自己的代码中使用using namespace hyperlex。作者定义了自己的模板比如vector模板，所以使用命名空间可能会引起冲突。
2.  测试代码写在main.cpp，AutoHeader.h里面。这个文件包含了之前某些项目内的无用代码所以显得十分庞大。如果对测试项目的正确性不感兴趣无需了解main.cpp。
3.  测试用的参数文件是test_item.txt,测试用的数据文件有很多。测试用的文法规则大部分来自龙书的例子。

## 使用说明

### 您可以在三种不同的深度上使用本软件。
####         1. 简单使用级别:
简单使用仅需了解接口类 InputPanel。通过调用InputPanel的public成员函数，用户就可以完成输入文件到词法分析器DFA和文法分析表的转换。
#### 	2. 语法树与词法表级别：
软件内部有两个class 分别叫 Morpheme 和 GrammarTree。它们是简易的词法表模板和语法树模板，有了程序输出的词法分析器和文法分析表。这两个类可以方便的从源代码计算得到对应的文法树。
#### 	3. 深入挖掘级别：
调用内部的NFA, regExp等功能来完成更深层次功能。
###  class InputPanel简介：
InputPanel 声明在 automata.h文件 564行它有目前有六个公有成员函数作为接口供用户调用。分别是

```
int build(FILE* fp);
int build(const char* input);
void demo(FILE* fp) const;
void ErrorDemo(FILE* fp) const;
void printL(FILE* fp, const char* nameL)const;
int printG(FILE* output, FILE* infor, const char* nameG)const;
```

####        1.  编码规则与build
build方法接受一个可以读的输入文件或者一个字符串作为输入，编码最好为ASCII.
####        2.  输入信息展示
demo方法展示读入文件的信息，如果发现输入文件有一些错误，那么它可以自动调用ErrorDemo方法展示错误。用户也可以主动使用 ErrorDemo方法输出错误信息。
####        3. 输出打印
 printL方法打印Cpp风格的DFA代码，这个DFA封装在一个名字为nameL的类中. printG打印一个LR分析器对应的分析表（状态转移表等等），这个表格封装在一个名字为nameG的类中。这个类对应的代码输出在FILE*output中，而FILE* infor是文法分析对应的信息。
目前这两个文件指针都不可以为NULL。
####        4.  返回信息
用户输入的文法如果是lr0的printG返回LR0分析表（状态转移表等等），此时printG返回 0。用户输入的文法如果是lr1的printG返回LR1分析表（状态转移表等等），此时printG返回 1。
如果用户输入的文法超过了这两种文法分析器生成器的能力，printG返回2，此时FILE*output。不会有任何输出。
####        5.  


## 输入文件格式

### 1.  禁止单独输入文法规则
用户可以选择在文件中，只写词法规则，也可以选择在文件中同时写词法和文法规则，但是不能单独的写文法规则。如果用户需要单独的文法规则，那么可以随便写一个补位性质的词法分析规则。
### 2.  输入文件的词法与文法
无名生成器分析用户文件所用的词法分析器和文法分析器也是由无名生成器自动生成的。所以在Testfile目录里面，你可以看到本分析器的词法分析和文法分析规则文件input.txt。用户可以从此文件实际上包含了大部分输入文件的格式细节与格式规范。
### 3.  保留字与标识符
输入文件接受C语言风格的标识符，但是与C语言不同的是，无名生成器接受的标识符的最小长度是2，单字母不能作为合法的标识符。此外输入文件有四个保留字all，grammar，lexical，void。
### 4.  输入文件广泛使用C语言风格的花括号，右花括号后面是否跟着一个分号都可以，但是不能跟着多个。
### 5.  注释与换行
分析输入文件的时候会丢弃所有的空格换行和水平制表符号。输入文件支持C语言风格的注释，这个注释由词法分析器识别后丢弃，具体注释的词法请参阅input.txt。
### 6.  文法分析输入格式；
#### 正则表达式的命名       
 每一个输入的正则表达式都需要被命名，它们的名字可以是保留字或者标识符。每一个被输入的正则表达式都需要被指定一个类型或者说群组，群组名必须是标识符或者保留字void。void群组的正则表达式不会作为词法分析器的输出，而只成为预制的模块，用于简化后续的正则表达式的输入。。除了void组,任何两个群组的名字不能重名，任何两个正则表达式的名字也不能重名。所有viod群组内的表达式会被合并。
```
void: 
{
num: [0-9];
letter: [a-z]|[A-Z];
}
id: id（+5）: (<letter> | _) (<letter> | _ | num)+;
void: hexa: [0-9] | [a - f] | [A-F];
```
#### 正则表达式的优先级
可以用名称后跟随括号的方法为任何一个非void群组或者任何一个非void群组内正则表达式指定一个优先级。优先级必须是正整数并且显式的使用正号。

```
reserved(+6): 
{
    int: int;// 最终优先级被识别为6
    double: double(+5); // 最终优先级被识别为5
    char: char; // 最终优先级被识别为6
}

```

### 7.  文法分析输入格式；
####   命名规则  
文法分析接受的词法单元（终结符号）正是词法规则中全体非void群组的正则表达式名。所有文法规则依据规则定义的文法符号(非终结符号)自然分组。每一组内的每一个产生式都必须被命名，与词法规则不同的是，同一组内的两个产生式不能重名，而不同组内的两个产生式可以重名。 当然任意两个组名不能重名。
####   保留字规则
 如果all 没有被用户输入的词法规则定义为词法单元(终结符号)那么all不能出现在文法产生式体内，否则报错。反之all 被定义为词法单元，当all出现在文法产生式体内它会被视为一个终结符号。如果void被用户输入的词法规则定义为一个词法单元(终结符号)，那么它将不能表达一个空产生式，换言之整个，输入文件系统不能再接受空符号。


## 输出文件格式

1.  词法分析器输出格式
2.  文法分析表输出格式

## 软件架构简介与版本

### 代码中的垃圾
  由于无名生成器分析用户文件所用的词法分析器和文法分析器也是由无名生成器自动生成的。为了完成这一自举，代码中留下了很多无用的脚手架。
### 已知问题
目前版本为1.0也就是刚刚可以用的地步。目前有两个小bug没有修，首先死状态软件在缩减DFA状态的过程中会崩溃。如果设置两个正则表达式可以接受相同的串，请设置不同的权限区分它们，使得任意一个正则表达式都有可以接受的串。举个例子如果保留字void也能被识别标识符的正则表达式识别，那么请保证void的权限高于标识符，否则遇到void会被识别成标识符，导致任何情况void不可被识别，进而导致状态缩减时崩溃。其次空产生式会导致打印的文法分析表的产生式长度一项有一些异常。下个小版本修理这两个东西。
### 异常与内存管理
本软件不抛出任何异常，内部混合使用malloc与new。并且使用时不检查返回值。

