#include<cstring>
#include<time.h>
using namespace std;
#include "AutoHeader.h"
#include<stdlib.h>
int test_entrance(const char* output_path);
int main(int argc, char* argv[])
{
	int info;
	//ParaFile pf;
	int amount_of_cores;
	const char* output_path;
	output_path = argv[1];
	//amount_of_cores = cores_amount_from_input(argv[2]);
	info = 0;
	info = test_entrance(output_path);
	return info;
}

namespace hyperlex
{
	typedef long long int IntegerDefault;
	class DFA00;

	class CharBuffer;
	class UnitBuffer;
	union content
	{
		IntegerDefault integer;
		double real;
		char C;
		char* S;
	};
	struct unit
	{
		//type = 0; long long int integer;
		//type = 1; double real;
		//type = 2; char C;
		//type = 3; char* string;
		size_t length;
		content C;
		char* origin;
		int lexical;
		int type;
		void initial(void);
		void ruin(void);
		void print(FILE* fp);
		void operator=(double e);
		void operator=(long long int e);
		void operator=(std::string e);
	};
	class UnitBuffer
	{
	public:
		UnitBuffer();
		~UnitBuffer();
		size_t Site(void);
		void Append(CharBuffer& result, int state);
		void add(long long int c);
		void print(FILE* fp);
		void print(FILE* fp, size_t count);
		unit& operator[](size_t target);
		void build(CharBuffer& in);
		void clear(void);
		//ERROR
		//0: NoError
		//1 :
		//2 :
		//3 ;
	protected:
		int ERROR;
		size_t size;
		size_t site;
		unit* content;
		size_t add(void);
	};
	class CharBuffer
	{
	public:
		CharBuffer();
		~CharBuffer();
		size_t Site(void);
		size_t Length(void);
		void Append(char c);
		void Append(const char* c);
		void Append(CharBuffer& in);
		void Print(FILE* fp);
		void Print(FILE* fp, int count);
		void Copy(char* to);
		char* CopyMalloc(void);
		char Pop(void);
		bool Pop(char& out);

		void Clear(void);

		char Dequeue(void);
		char Dequeue(CharBuffer& backspace);
		char QueueHead(void);

		void operator<<(char c);
		void operator<<(const char* c);
		void operator<<(double e);
		void operator<<(int e);
		void operator<<(long long int e);
		void operator<<(CharBuffer& in);
		void operator<<(FILE* fp);

		bool operator==(size_t length);
		bool operator!=(size_t length);

		IntegerDefault DequeueInt(void);
		double DequeueReal(void);
		char DequeueChar(void);
		char* DequeueString(void);
		char* DequeueId(void);
	private:
		size_t size;
		size_t site;
		size_t head;
		char* content;
	};

	
	IntegerDefault IntGet(const char* list, size_t end, size_t& head);
	double RealGet(int& state, const char* list, size_t end, size_t& head);
	char CharGet(const char* list, size_t end, size_t& head);
	

	enum type
	{
		integer = 0,
		octonary = 1,
		hexadecimal = 2,//hexadecimal integer 
		real = 3,//double type without e&E
		RealWithE = 4, //double type with e& E
		id = 5,//type = 5: identifier, type = 6: space
		space = 6,//space
		OperatorPlus = 7,//type = 7: operator +
		OperatorPlusPlus = 8,//type = 8: operator ++
		OperatorMinus = 9, //type = 9: operator -, type = 10: operator --
		OperatorMinusMinus = 10,
		Cstring = 11, //type = 11: string, type = 12 string without an end, error
		ErrorEndlessString = 12,
		annotation = 13,//type = 13: annotation //, type = 14 sign of division /,
		division = 14,
		star = 15,//type = 15: star *, type = 16 double star,
		StarStar = 16,
		assign = 17,//type = 17: =, type = 18 ==,
		equal = 18,
		dot = 19,//type = 19: dot . , type = 20: , , type = 21: ? , type = 22: &, 
		comma = 20,
		question = 21,
		BitwiseAnd = 22,
		RoundBra = 23,//type = 23: (, type = 24: ),type = 25: [, type = 26: ]
		RoundBKet = 24,
		SquareBra = 25,
		SquareKet = 26,
		OpeBrace = 27,//type = 27: {, type = 28: },type = 29: ;, type = 30: : 
		CloseBrace = 28,
		semicolon = 29,
		colon = 30,
		to = 31, //type = 31: ->, type = 32: &&, type = 33 |: , type = 34: || :
		And = 32,
		BitwiseOr = 33,
		Or = 34,
		Greater = 35,//type = 35: >, type = 36: >=, type = 37 <: , type = 38: <=:
		GreaterEq = 36,
		Less = 37,
		LessEq = 38,
		StreamOut = 39,//type = 39: >>, type = 40: <<, type = 41: <<=, type = 42: >>=
		StreamIn = 40,
		StreamOut2 = 41,
		StreamIn2 = 42,
		Not = 43, //type = 43: !, type = 44: !=, type = 45: ^, type = 46: ^=
		NotEq = 44,
		//type = 47: +=, type = 48: -=, type = 49: *=, type = 50: /=
		//type = 51: %, type = 52: %=, type = 53: &=, type = 54: |=
		//type = 55: annotation /**/, type = 56 annotation without an end, error
		//type = 57: char '��'����\����, type = 58 char without an end, error
		//type = 59: >>>, type = 60: <<<
		//type = 61: #* pretreatment
		//type = 62: \t, //type = 63: \n
	};
	enum reserved
	{
		If = 64,//type = 64: if           , type = 65: else
		Else = 65,
		For = 66,//type = 66: for          , type = 67: do
		Do = 67,
		While = 68,//type = 68: while        , type = 69: switch
		Switch = 69,
		Case = 70,//type = 70: case         , type = 71: goto
		Goto = 71,
		Continue = 72,//type = 72: continue     , type = 73: break
		Break = 73,
		Return = 74,//type = 74: return       , type = 75: default
		Default = 75,
		Typedef = 76,//type = 76: typedef      , type = 77: int
		Int = 77,
		Char = 78,//type = 78: char         , type = 79: double
		Double = 79,
		Float = 80, //type = 80: float        , type = 81: long 
		Long = 81,
		Short = 82, //type = 82: short        , type = 83: unsigned
		Unsigned = 83,
		Signed = 84, //type = 84: signed       , type = 85: const
		Const = 85,
		Void = 86,//type = 86: void         , type = 87: volatile
		Volatile = 87,
		Enum = 88,//type = 88: enum         , type = 89: struct
		Struct = 89,
		Union = 90, //type = 90: union        , type = 91: auto
		Auto = 91,
		Register = 92,//type = 92: register     , type = 93: extern
		Extern = 93,
		Static = 94, //type = 94: static       , type = 95: sizeof
		Sizeof = 95
	};

	//=====================================================================================
	//--------------------------------lexical analyzer ------------------------------------
	//=====================================================================================
	//type = 0: int, type = 1: octonary, type = 2: hexadecimal integer , 
	//type = 3: double type without e&E, type = 4: double type with e&E,
	//type = 5: identifier, type = 6: space
	//type = 7: operator +, type = 8: operator ++
	//type = 9: operator -, type = 10: operator --
	//type = 11: string, type = 12 string without an end, error
	//type = 13: annotation //, type = 14 sign of division /,
	//type = 15: star *, type = 16 double star,
	//type = 17: =, type = 18 ==,
	//type = 19: dot . , type = 20: , , type = 21: ? , type = 22: &, 
	//type = 23: (, type = 24: ),type = 25: [, type = 26: ]
	//type = 27: {, type = 28: },type = 29: ;, type = 30: : 
	//type = 31: ->, type = 32: &&, type = 33 |: , type = 34: || :
	//type = 35: >, type = 36: >=, type = 37 <: , type = 38: <=:
	//type = 39: >>, type = 40: <<, type = 41: <<=, type = 42: >>=
	//type = 43: !, type = 44: !=, type = 45: ^, type = 46: ^=
	//type = 47: +=, type = 48: -=, type = 49: *=, type = 50: /=
	//type = 51: %, type = 52: %=, type = 53: &=, type = 54: |=
	//type = 55: annotation /**/, type = 56 annotation without an end, error
	//type = 57: char '��'����\����, type = 58 char without an end, error
	//type = 59: >>>, type = 60: <<<
	//type = 61: #* pretreatment
	//type = 62: \t, //type = 63: \n
	//=================================================================
	//type = 64: if           , type = 65: else
	//type = 66: for          , type = 67: do
	//type = 68: while        , type = 69: switch
	//type = 70: case         , type = 71: goto
	//type = 72: continue     , type = 73: break
	//type = 74: return       , type = 75: default
	//type = 76: typedef      , type = 77: int
	//type = 78: char         , type = 79: double
	//type = 80: float        , type = 81: long
	//type = 82: short        , type = 83: unsigned
	//type = 84: signed       , type = 85: const
	//type = 86: void         , type = 87: volatile
	//type = 88: enum         , type = 89: struct
	//type = 90: union        , type = 91: auto
	//type = 92: register     , type = 93: extern
	//type = 94: static       , type = 95: sizeof
	class DFA00
	{
	private:
		int state;
		int former_state;
		int last_success;
	public:
		enum action
		{
			wait,
			add,
			record,
			retrieve,
			halt
		};
		DFA00();
		~DFA00();
		void DFA_swicth(char c);
		enum action should(void);
		int success_get(int State);
		int DFA_state(void);
		int DFA_former_state(void);
		void lexical_analyse(CharBuffer& in);
		int result(void);
		int if_error(int type);
	};

	void ExitWarning(int error, FILE* fp);
	void Ruin(char** list, size_t length);
	bool IfLetter(char c);
	bool StringToBool(const char* c_t_f);//true_false_judge

	class CFile
	{
	public:
		CFile();
		~CFile();
		FILE* Open(const char* name, const char* mode);
		FILE* OpenRead(const char* s);//SH_read_from_file__(const char* s);
		FILE* OpenWriteAtRear(const char* s);//fp_write_at_rear(const char* s);
		FILE* OpenWritePlus(const char* s);//fp_write_plus
		std::string FusePathAndName(const std::string& path, const std::string& name);//path_add_file_name
		std::string FusePathAndName(const char* path, const std::string& name);//path_add_file_name
		std::string ChangeSuffix(const std::string& file, const char* new_one);//string suffix_change(const string& file, const char* new_one);
	private:

	};

	class Bitwise
	{
	public:
		Bitwise();
		~Bitwise();
		void Open(const char* name);
		void StoreOpen(const char* name);
		void LoadOpen(const char* name);
		void SetDMatrix(const double* mat, size_t row, size_t column);
		double* GetDMatrix(size_t* row, size_t* column);

		void store(size_t value);
		void store(const size_t* vector, size_t length);
		void store(const bool* vector, size_t length);
		void store(const int* vector, size_t length);
		void store(const void* vector, size_t byte);

		void store(const char* list);
		void store(const char** list, size_t length);

		size_t loadllu(void);
		char* loadstring(void);
		char** loadlist(void);
		void* load(size_t byte);
		void* load(size_t EleAmount, size_t ContainerAmount, size_t EleSize);
	private:
		FILE* fp;
		CFile FP;
	};

	class MatFile
	{
	public:
		MatFile();
		~MatFile();
		int MatrixGet(double** list, size_t* row, size_t* column, CharBuffer& in);
		int MatrixGet(double** list, size_t* row, size_t* column, const char* file);
		int MatrixGet(double** list, size_t* row, size_t* column, FILE* fp);
		void MatrixSet(const double* mat, size_t ld, size_t row, size_t column, const char* file);
		void MatrixSet(const double* mat, size_t ld, size_t row, size_t column, FILE* fp);
	private:

	};



	class ParaFile : public UnitBuffer
	{
	public:
		ParaFile();
		~ParaFile();
		int initial(CharBuffer& in);
		int initial(FILE* fp);
		int initial(const char* file);
		enum ParaType
		{
			Int,
			Real,
			Id,
			String,
			Char,
			Mix,
			MixString
		};
		void demo(FILE* Fp);
		size_t Amount(void);
		size_t Amount(size_t i);
		size_t SearchKey(const char* Key);
		size_t SearchKey(const char* Key, ParaType T);
		ParaType GetType(size_t i);
		IntegerDefault FirstInt(size_t i);
		double FirstReal(size_t i);
		std::string FirstString(size_t i);
		std::string GetString(const char* Key, const char* Default);
		void IntList(IntegerDefault*& list, size_t& length, size_t i);
		void CharList(char**& list, size_t& length, size_t i);
	private:
		int construct(CharBuffer& in);
		size_t KeyAmount;
		size_t Target;
		size_t ContainerSize;
		size_t* key;
		size_t* FirstElem;
		size_t* ElemAmount;
		ParaType* Type;
		size_t* Next;
		void append(size_t No);
		bool IfContent(int T);
		ParaType SwitchType(int T);
	};



}

using namespace hyperlex;

static int test_01(const char* output_path, ParaFile& pf);
static int test_02(const char* output_path, ParaFile& pf);
static int test_03(const char* output_path, ParaFile& pf);
static int test_04(const char* output_path, ParaFile& pf);
static int test_05(const char* output_path, ParaFile& pf);
static int test_06(const char* output_path, ParaFile& pf);
static int test_07(const char* output_path, ParaFile& pf);
static int test_08(const char* output_path, ParaFile& pf);
static int test_09(const char* output_path, ParaFile& pf);
static int test_10(const char* output_path, ParaFile& pf);
static int test_11(const char* output_path, ParaFile& pf);
static int test_12(const char* output_path, ParaFile& pf);
static int test_13(const char* output_path, ParaFile& pf);
static int test_14(const char* output_path, ParaFile& pf);
static int test_15(const char* output_path, ParaFile& pf);
static int test_16(const char* output_path, ParaFile& pf);
static int test_17(const char* output_path, ParaFile& pf);
static int test_18(const char* output_path, ParaFile& pf);
static int test_19(const char* output_path, ParaFile& pf);
int test_entrance(const char* output_path)
{
    int item;
    int info;
    ParaFile pf;
    size_t sitePF;
    pf.initial("./parameter/test_item.txt");
    sitePF = pf.SearchKey("item", ParaFile::Int);
    if (sitePF != pf.Amount())
        item = pf.FirstInt(sitePF);
    else
        item = 1;
    cout << "item: " << item << endl;
    info = 0;

    switch (item)
    {
    case 1:
        info = test_01(output_path, pf);
        break;
    case 2:
        info = test_02(output_path, pf);
        break;
    case 3:
        info = test_03(output_path, pf);
        break;
    case 4:
        info = test_04(output_path, pf);
        break;
    case 5:
        std::cout << "Test RegTree; " << std::endl;
        info = test_05(output_path, pf);
        break;
    case 6:
        std::cout << "Test RegTree To nfa; " << std::endl;
        info = test_06(output_path, pf);
        break;
    case 7:
        std::cout << "Test DFA , nfa; " << std::endl;
        info = test_07(output_path, pf);
        break;
    case 8:
        std::cout << "Test grammer 11; " << std::endl;
        info = test_08(output_path, pf);
        break;
    case 9:
        std::cout << "test print; " << std::endl;
        info = test_09(output_path, pf);
        break;
    case 10:
        std::cout << "Test grammer 2; " << std::endl;
        info = test_10(output_path, pf);
        break;
    case 11:
        std::cout << "Test grammer 2; " << std::endl;
        info = test_11(output_path, pf);
        break;
    case 12:
        std::cout << "Test grammer 2; " << std::endl;
        info = test_12(output_path, pf);
        break;
    case 13:
        std::cout << "Test grammer LR0 LR1 from input file; " << std::endl;
        info = test_13(output_path, pf);
        break;
    case 14:
        std::cout << "Test template; " << std::endl;
        info = test_14(output_path, pf);
        break;
    case 15:
        std::cout << "Test grammer LR0 from input file; " << std::endl;
        info = test_15(output_path, pf);
        break;
    case 16:
        std::cout << "Test grammer LR1 from input file; " << std::endl;
        info = test_16(output_path, pf);
        break;
    case 17:
        std::cout << "Test LP reg; " << std::endl;
        info = test_17(output_path, pf);
        break;
    case 18:
        std::cout << "Test grammer 2; " << std::endl;
        info = test_18(output_path, pf);
        break;
    case 19:
        std::cout << "Test grammer 2; " << std::endl;
        info = test_19(output_path, pf);
        break;
    default:
        info = test_01(output_path, pf);
        break;
    }
    return info;
}
static int test_01(const char* output_path, ParaFile& pf)
{
    printf("test_01\n");
}
static int test_02(const char* output_path, ParaFile& pf)
{
    hyperlex::ParaFile PF;
    FILE* fp;
    hyperlex::CFile F;
    std::string file;
    hyperlex::CharBuffer Buffer;
    file = "./data/struct.txt";
    fp = F.Open(file.c_str(), "r");
    Buffer << fp;
    fclose(fp);
    printf("test_02\n");
    Buffer.Print(stdout);
    printf("test_02\n");
    PF.initial(file.c_str());
    printf("Amount: %llu\n", PF.Amount());

    size_t length;
    long long int* list = NULL;
    size_t i, j;
    i = PF.SearchKey("MoleculeOfAtom", hyperlex::ParaFile::Int);
    //printf("i: %llu\n", i);
    PF.demo(stdout);
    PF.IntList(list, length, i);
    printf("MoleculeOfAtom: %llu, length: %llu\n", i, length);
    for (j = 0; j < length; j++)
        printf("%lld, ", list[j]);
    free(list);
    char** L;
    i = PF.SearchKey("MoleculeLabel");
    PF.CharList(L, length, i);
    printf("MoleculeLabel: %llu, length: %llu\n", i, length);
    for (j = 0; j < length; j++)
        printf("%s, ", L[j]);
    hyperlex::Ruin(L, length);
    return 0;
}
static int test_03(const char* output_path, ParaFile& pf)
{
    class inner
    {
    public:
        int i;
        inner(int a)
        {
            i = a;
            std::cout << "inner(): " << i << std::endl;
        }
        inner()
        {
            i = 0;
            std::cout << "inner(): default" << i << std::endl;
        }
        ~inner() { std::cout << "~inner()" << std::endl; }

    };
    class outer
    {
    public:
        inner a;
        inner b;
        outer() :a(1), b(2) { std::cout << "outer()" << std::endl; }
        ~outer() { std::cout << "~outer()" << std::endl; }

    };
    outer test;
    char a[128];
    char* b;
    b = a;
    std::cout << "char a[128];: " << "sizeof(char[128]) = " << sizeof(char[128]) << "sizeof(a) = " << sizeof(a) << std::endl;
    std::cout << "char *b; b = a;: " << "sizeof(b) = " << sizeof(b) << std::endl;
    std::cout << "#define CharSize ((size_t)1 << (sizeof(char) * 8 - 1)): " << ((size_t)(1 << (sizeof(char) * 8 - 1))) << std::endl;
    //#define CharSize 
}
using namespace hyperlex;
static int test_04(const char* output_path, ParaFile& pf)
{
    Bitree<int> tree;
    Bitree<int>::node* temp;
    hyperlex::buffer<size_t> output;

    size_t i;
    for (i = 0; i < 9; i++)
    {
        std::cout << "tree.NewNode() " << tree.NewNode() << ";" << std::endl;
        tree[i].content = i + 1;
        std::cout << "tree[" << i << "].content = " << tree[i].content << ";" << std::endl;

    }
    tree.SetHead(0);
    std::cout << "asdasda " << std::endl;
    tree[0].left = 1;
    tree[0].right = 2;
    tree[1].left = 3;
    tree[1].right = 4;
    tree[4].left = 5;
    tree[4].right = 6;
    tree[5].left = 7;
    tree[7].left = 8;
    std::cout << "tree.postorderTraversal(output); " << std::endl;
    tree.postorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    output.refresh();
    std::cout << "tree.inorderTraversal(output); " << std::endl;
    tree.inorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    output.refresh();
    tree.SetHead(1);
    std::cout << "tree.SetHead(1); " << std::endl;
    std::cout << "tree.postorderTraversal(output); " << std::endl;
    tree.postorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    output.refresh();
    std::cout << "tree.inorderTraversal(output); " << std::endl;
    tree.inorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    tree.SetHead(1);
}
static int test_05(const char* output_path, ParaFile& pf)
{
    RegTree RT, Id, res;
    std::cout << "RegTree RT; " << std::endl;
    RT.Int();
    std::cout << "T.Int(); " << std::endl;
    RT.Demo(stdout);
    std::cout << std::endl;

    std::cout << "T.Identifier(); " << std::endl;
    Id.Identifier();
    Id.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"if\"); " << std::endl;
    res.Reserved("if");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"else\"); " << std::endl;
    res.Reserved("else");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"const\"); " << std::endl;
    res.Reserved("const");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"class\"); " << std::endl;
    res.Reserved("class");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"namespace\"); " << std::endl;
    res.Reserved("namespace");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"typename\"); " << std::endl;
    res.Reserved("typename");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"A\"); " << std::endl;
    res.Reserved("A");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"for\"); " << std::endl;
    res.Reserved("for");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.Identifier(\"Yuziyudafanrenjing\"); " << std::endl;
    res.Reserved("Yuziyudafanrenjing");
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.IdentifierHead(); " << std::endl;
    res.IdentifierHead();
    res.Demo(stdout);
    std::cout << std::endl;

    std::cout << "res.IdentifierInner(); " << std::endl;
    res.IdentifierInner();
    res.Demo(stdout);
    std::cout << std::endl;
}
static int test_06(const char* output_path, ParaFile& pf)
{
    RegTree RT, Id, res;
    //sNFA nfa, nfa2;
    NFA* ff;
    sNFA* nfa[2];
    sheetDFA* dfa;
    DFA* ddfa;
    std::cout << "RegTree RT; " << std::endl;
    RT.Int();
    std::cout << "T.Int(); " << std::endl;
    RT.Demo(stdout);
    std::cout << std::endl;
    nfa[0] = new sNFA();
    nfa[0]->build(&RT);
    nfa[0]->Demo(stdout);

    std::cout << "T.Identifier(); " << std::endl;
    Id.Identifier();
    Id.Demo(stdout);
    std::cout << std::endl;
    nfa[1] = new sNFA();
    nfa[1]->build(&Id);
    nfa[1]->Demo(stdout);

    ff = new NFA(nfa, 2);
    ff->Demo(stdout);

    dfa = new sheetDFA(*ff);
    dfa->Demo(stdout);

    ddfa = new DFA(dfa);
    ddfa->Demo(stdout);

    dfa->shrink();
    dfa->Demo(stdout);

    std::cout << "all " << std::endl;
    delete nfa[0];
    std::cout << "all " << std::endl;
    delete nfa[1];
    std::cout << "delete ff; " << std::endl;
    delete ff;
    std::cout << "delete dfa; " << std::endl;
    delete dfa;
    std::cout << "delete ddfa; " << std::endl;
    delete ddfa;
}
static int test_07(const char* output_path, ParaFile& pf)
{
    RegTree RT, Id, res;
    //sNFA nfa, nfa2;
    NFA* ff;
    sNFA* nfa[3];
    sheetDFA* dfa;
    DFA* ddfa;

    std::cout << "T.Reserved(\"const\"); " << std::endl;
    res.Reserved("const");
    res.Demo(stdout);
    std::cout << std::endl;
    nfa[0] = new sNFA();
    nfa[0]->build(&res);
    nfa[0]->Demo(stdout);

    std::cout << "RegTree RT; " << std::endl;
    RT.Int();
    std::cout << "T.Int(); " << std::endl;
    RT.Demo(stdout);
    std::cout << std::endl;
    nfa[1] = new sNFA();
    nfa[1]->build(&RT);
    nfa[1]->Demo(stdout);

    std::cout << "T.Identifier(); " << std::endl;
    Id.Identifier();
    Id.Demo(stdout);
    std::cout << std::endl;
    nfa[2] = new sNFA();
    nfa[2]->build(&Id);
    nfa[2]->Demo(stdout);

    ff = new NFA(nfa, 3);
    ff->Demo(stdout);

    dfa = new sheetDFA(*ff);
    dfa->Demo(stdout);


    dfa->shrink();
    dfa->Demo(stdout);
    std::cout << "ddfa = new DFA(dfa);" << std::endl;
    ddfa = new DFA(dfa);
    ddfa->Demo(stdout);
    std::cout << "ddfa->Cprint(stdout, \"test\"); " << std::endl;
    ddfa->Cprint(stdout, "test");
    std::cout << "all " << std::endl;
    delete nfa[0];
    std::cout << "all " << std::endl;
    delete nfa[1];
    std::cout << "delete ff; " << std::endl;
    delete ff;
    std::cout << "delete dfa; " << std::endl;
    delete dfa;
    std::cout << "delete ddfa; " << std::endl;
    delete ddfa;
}
static int test_08(const char* output_path, ParaFile& pf)
{
    lexicalPanel lP;
    NFA* nfa;
    sheetDFA* dfa;
    DFA* ddfa;
    lP.SetGrammer();
    lP.Demo(stdout);
    nfa = new NFA(lP);
    std::cout << "==============================================" << std::endl;
    nfa->Demo(stdout);
    std::cout << "==============================================" << std::endl;

    dfa = new sheetDFA(*nfa);
    dfa->Demo(stdout);


    dfa->shrink();
    dfa->Demo(stdout);
    std::cout << "ddfa = new DFA(dfa);" << std::endl;
    ddfa = new DFA(dfa);
    ddfa->Demo(stdout);
    std::cout << "ddfa->Cprint(stdout, \"test\"); " << std::endl;
    ddfa->Cprint(stdout, "test");

    delete nfa;
    std::cout << "delete dfa; " << std::endl;
    delete dfa;
    std::cout << "delete ddfa; " << std::endl;
    delete ddfa;
}
static int test_09(const char* output_path, ParaFile& pf)
{
    size_t i;
    for (i = 10; i < 20; i++)
    {
        std::cout << "static int test_" << i << "(const char* output_path, ParaFile& pf);" << std::endl;
    }
    for (i = 10; i < 20; i++)
    {
        std::cout << "\tcase " << i << ":" << std::endl;
        std::cout << "\t\tstd::cout << \"Test grammer 2; \" << std::endl;" << std::endl;
        std::cout << "\t\tinfo = test_" << i << "(output_path, pf);" << std::endl;
        std::cout << "\t\tbreak;" << std::endl;
    }
    for (i = 10; i < 20; i++)
    {
        std::cout << "static int test_" << i << "(const char* output_path, ParaFile& pf)" << std::endl;
        std::cout << "{" << std::endl;
        std::cout << "\treturn 0;" << std::endl;
        std::cout << "}" << std::endl;
    }
}
static int test_10(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    //fp = CF.OpenRead("./data/grammerT.txt");
    fp = CF.OpenRead("./data/if.txt");
    G.build(fp);
    fclose(fp);
    G.Demo(stdout);
    return 0;
}
static int test_11(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    fp = CF.OpenRead("./data/grammerT.txt");
    //fp = CF.OpenRead("./data/if.txt");
    G.build(fp);
    fclose(fp);
    G.Demo(stdout);
    return 0;
}
static int test_12(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    LR0* lr;
    fp = CF.OpenRead("./data/grammerP.txt");
    //fp = CF.OpenRead("./data/if.txt");
    G.build(fp);
    fclose(fp);
    G.Demo(stdout);
    lr = new LR0(&G);
    lr->Demo(stdout, &G);
    delete lr;
    return 0;
    return 0;
}
static int test_13(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    LR0* lr;
    LR1* lr1;
    string file;
    int infor;
    BufferChar temp;
    Gsheet Gsheet0, Gsheet1;
    lr1 = NULL;


    //file = pf.first_string("InputFileName", "./data/grammerT.txt");
    file = pf.GetString("InputFileName", "./data/grammerT.txt");


    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    input << fp;
    temp.append(input);
    std::cout << temp.vector() << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    //fp = CF.OpenRead("./data/if.txt");
    infor = G.build(input);
    std::cout << "infor = G.build(input);" << infor << std::endl;
    fclose(fp);
    if (infor != 0) return infor;
    G.Demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+++++++++++++lr = new LR(&G);++++++++++++++++" << std::endl;
    lr = new LR0(&G);
    lr->Demo(stdout, &G);

    Gsheet0.build(lr, &G);
    Gsheet0.Demo(stdout);
    Gsheet0.Cprint("Heihei", stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "++++++++++++lr1 = new LR1(&G);+++++++++++++++" << std::endl;
    lr1 = new LR1(&G);
    lr1->Demo(stdout, &G);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Gsheet1.build(lr1, &G);
    Gsheet1.Demo(stdout);
    Gsheet1.Cprint("Heihei", stdout);

    Gsheet0.CppPrint("Retree", stdout);
    Gsheet0.CppStructPrint("Retree", stdout);

    G.Cprint(stdout);
    delete lr1;
    delete lr;
    return 0;
    return 0;
}
struct testh
{
    size_t a;
    size_t b;
    bool operator==(const testh& R) const
    {
        std::cout << "\ta: " << a << ", b: " << b << std::endl;
        std::cout << "\tR.a: " << R.a << ", R.b: " << R.b << std::endl;
        return (a == R.a) && (b == R.b);
    }
    void demo(void)const
    {
        std::cout << "demo a: " << a << ", b: " << b << std::endl;
    }
};
struct testh2
{
    int a;
    int b;
};
static int test_14(const char* output_path, ParaFile& pf)
{
    size_t site;
    list<testh> aa;
    testh hh, gg;
    hh.a = 1;
    hh.b = 1;
    hh.demo();
    std::cout << "aa.SearchAppend(hh):\n";
    site = aa.SearchAppend(hh);
    std::cout << "\t site = " << site << std::endl;
    std::cout << "aa.SearchAppend(hh):\n";
    site = aa.SearchAppend(hh);
    std::cout << "\t site = " << site << std::endl;
    hh.b = 2;
    hh.demo();
    std::cout << "aa.SearchAppend(hh):\n";
    site = aa.SearchAppend(hh);
    std::cout << "\t site = " << site << std::endl;
    std::cout << "aa.SearchAppend(hh):\n";
    site = aa.SearchAppend(hh);
    std::cout << "\t site = " << site << std::endl;

    //hh == gg;
    list<testh2> cc;
    testh2 dd, ww;
    dd.a = 1;
    dd.b = 1;
    ww = dd;
    cc.append(dd);
    //ww == dd;
    //cc.SearchAppend(dd);

    //n == m;
    return 0;
}
static int test_15(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    LR0* lr;
    string file;
    BufferChar temp;
    Gsheet Gsheet0;


    //file = pf.first_string("InputFileName", "./data/grammerT.txt");
    file = pf.GetString("InputFileName", "./data/grammerT.txt");


    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    input << fp;
    temp.append(input);
    std::cout << temp.vector() << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    //fp = CF.OpenRead("./data/if.txt");
    G.build(input);
    fclose(fp);
    G.Demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+++++++++++++lr = new LR(&G);++++++++++++++++" << std::endl;
    lr = new LR0(&G);
    lr->Demo(stdout, &G);

    Gsheet0.build(lr, &G);
    Gsheet0.Demo(stdout);
    Gsheet0.Cprint("Heihei", stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    delete lr;
    return 0;
}
static int test_16(const char* output_path, ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    CFile CF;
    grammerS G;
    LR1* lr1;
    string file;
    BufferChar temp;
    Gsheet Gsheet1;
    lr1 = NULL;


    //file = pf.first_string("InputFileName", "./data/grammerT.txt");
    file = pf.GetString("InputFileName", "./data/grammerT.txt");


    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    input << fp;
    temp.append(input);
    std::cout << temp.vector() << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    //fp = CF.OpenRead("./data/if.txt");
    G.build(input);
    fclose(fp);
    G.Demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "++++++++++++lr1 = new LR1(&G);+++++++++++++++" << std::endl;
    lr1 = new LR1(&G);
    lr1->Demo(stdout, &G);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Gsheet1.build(lr1, &G);
    Gsheet1.Demo(stdout);
    Gsheet1.Cprint("Heihei", stdout);
    delete lr1;
    return 0;
}


static int test_17(const char* output_path, ParaFile& pf)
{
    lexicalPanel lP;
    NFA* nfa;
    sheetDFA* dfa;
    DFA* ddfa;
    
    
    lP.SetReg();
    //lP.Demo(stdout);
    if (0) 
    {
        nfa = new NFA(lP);
        std::cout << "==============================================" << std::endl;
        nfa->Demo(stdout);
        std::cout << "==============================================" << std::endl;

        std::cout << "dfa = new sheetDFA(*nfa);" << std::endl;
        dfa = new sheetDFA(*nfa);
        std::cout << "dfa->Demo(stdout);" << std::endl;
        dfa->Demo(stdout);
        std::cout << "dfa->shrink();" << std::endl;

        dfa->shrink();
        std::cout << "dfa->Demo(stdout);" << std::endl;
        dfa->Demo(stdout);
        std::cout << "ddfa = new DFA(dfa);" << std::endl;
        ddfa = new DFA(dfa);
        ddfa->Demo(stdout);
        std::cout << "ddfa->Cprint(stdout, \"test\"); " << std::endl;
        ddfa->Cprint(stdout, "Reg");

        delete nfa;
        std::cout << "delete dfa; " << std::endl;
        delete dfa;
        std::cout << "delete ddfa; " << std::endl;
        delete ddfa;
    }
    else
    {
        lP.BuildDemo(stdout);
        lP.Cprint(stdout, "Reg");
        lP.CppPrint(stdout, "Reg");
        lP.Demo(stdout);
       
    }
    //lP.Demo(stdout);
    return 0;
}
static int test_18(const char* output_path, ParaFile& pf)
{
    RegTree RT;
    RT.EscapeChar();
    RT.Demo(stdout);
    std::cout << std::endl;
    RegTree all;
    all.EscapeAll();
    std::cout << "all.EscapeAll();" << std::endl;
    all.Demo(stdout);
    std::cout << std::endl;

    RegTree Char;
    Char.ConstChar();
    std::cout << "Char.ConstChar;" << std::endl;
    Char.Demo(stdout);
    std::cout << std::endl;

    lexicalPanel lP;
    lP.SetReg();
    lP.Demo(stdout);
    return 0;
}

struct aa1
{
    static const size_t a;
    static const size_t b;
    static const int w[4];
    aa1(void)
    {
        //a = 11;
        //b = 12;
        //w[0] = 1;
        //w[1] = 11;
        //w[2] = 111;
       //w[3] = 1111;
    }
    void value(void)
    {
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        std::cout << "w[0]: " << w[0] << std::endl;
        std::cout << "w[1]: " << w[1] << std::endl;
        std::cout << "w[2]: " << w[2] << std::endl;
        std::cout << "w[3]: " << w[3] << std::endl;
    }
};

const size_t aa1::a = 11;
const size_t aa1::b = 12;
const int aa1::w[4] = { 1, \
11, 111, 1111 };


template<class T> class sheetDemo
{
public:
    void demo(void);
};
template<class T> void sheetDemo<T>::demo(void)
{
    size_t i, j;
    std::cout << "GOTO[" << T::StateCount << "][" << T::NonTerminalCount << "]" << std::endl;
    for (i = 0; i < T::StateCount; i++)
    {
        for (j = 0; j < T::NonTerminalCount; j++)
        {
            std::cout << T::GOTO[i][j] << "  ";

        }
        std::cout << std::endl;
    }
    std::cout << "ACTION[" << T::StateCount << "][" << T::TerminalCount + 1 << "]" << std::endl;
    for (i = 0; i < T::StateCount; i++)
    {
        for (j = 0; j < T::TerminalCount + 1; j++)
        {
            std::cout << T::ACTION[i][j] << "  ";

        }
        std::cout << std::endl;
    }
}
static int test_19(const char* output_path, ParaFile& pf)
{
    struct aa
    {
        const size_t a;
        const size_t b;
    };

    


    struct aa2
    {
        //const size_t a = 11;
        //const size_t b = 12;
        int w[64];
    };

    struct aa3
    {
        const size_t a;
        const size_t b;
        //const int w[4] = {1, 2, 3, 4};
    };
    

    aa1 A;
    size_t i, j;
    //sheetDemo<Retree> fdg;

    std::cout << "sizeof(aa): " << sizeof(aa) << std::endl;
    std::cout << "sizeof(aa1): " << sizeof(aa1) << std::endl;
    std::cout << "aa1.a: " << A.a << std::endl;
    A.value();
    std::cout << "aa1.w[2]: " << A.w[2] << std::endl;
    '/';
    //fdg.demo();
    //for (i = 0; i < Retree::StateCount; i++)
    //{
    //    for (j = 0; j < Retree::NonTerminalCount; j++)
     //   {
     //       std::cout << Retree::GOTO[i][j] << "  ";

     //   }
    //    std::cout << std::endl;
    //}
    //A.w[3] = 5;
    //A.a = 5;

    std::cout << "sizeof(aa2): " << sizeof(aa2) << std::endl;
    std::cout << "sizeof(aa3): " << sizeof(aa3) << std::endl;

    RegTree RTTE, RTTF, RTTD;
    RTTE.build("([a-z]|[A-Z]|_)([a-z]|[A-Z]|_|[0-9])*");
    
    RTTE.Demo(stdout);
    std::cout << std::endl;
    RTTD.build("('+'|'-')?([0-9])+");
    RTTD.Demo(stdout);
    std::cout << std::endl;
    RTTF.build("('+'|'-')?([0-9])+'.'([0-9])+((e|E)('+'|'-')?([0-9])+)?");
    RTTF.Demo(stdout);
    std::cout << std::endl;

    RTTE.build("'+'?[0-9]+");
    RTTE.Demo(stdout);
    std::cout << std::endl;
    RTTE.build("lexical");
    RTTE.Demo(stdout); 
    std::cout << std::endl;

    RTTE.build("\'/\'\'/\'([\'\\0\'-\'\\11\']|[\'\\13\'-\'\\177\'])*\'\\n\'");
    RTTE.Demo(stdout);
    std::cout << std::endl;
    RTTE.build("\'/\'\'*\'((\'*\'([\'\\0\'-\'.\']|[\'0\'-\'\\177\']))|([\'\\0\'-\')\']|[\'+\'-\'\\177\']))*\'*\'\'/\'");
    RTTE.Demo(stdout);
    std::cout << std::endl;

    return 0;
}






using namespace hyperlex;
#include<stdlib.h>

static char* CopyMalloc(const char* s);
static bool isIdBegin(char c);
static bool isIdNumber(char c);

void unit::initial(void)
{
    origin = NULL;
    C.S = NULL;
}
void unit::ruin(void)
{
    if (type == 3)
        free(C.S);
    free(origin);
}
void unit::print(FILE* fp)
{
    fprintf(fp, "<%3d|%d>: ", lexical, type);
    if (type == 0)
        fprintf(fp, "<%lld>", C.integer);
    else if (type == 1)
        fprintf(fp, "<%lf>", C.real);
    else if (type == 2)
        fputc(C.C, fp);
    else
        fprintf(fp, "<%s>", C.S);
}
void unit::operator=(double e)
{
    C.real = e;
    type = 1;
}
void unit::operator=(long long int e)
{
    C.integer = e;
    type = 0;
}
void unit::operator=(std::string e)
{
    size_t i;
    C.S = (char*)malloc((e.length() + 1) * sizeof(char));
    for (i = 0; e[i] != '\0'; i++) C.S[i] = e[i];
    C.S[i] = e[i];
    type = 3;
}
UnitBuffer::UnitBuffer()
{
    size_t i;
    size = 128;
    //head = 0;
    content = (unit*)malloc(sizeof(unit) * size);
    for (i = 0; i < size; i++)
        content[i].initial();
    site = 0;
}
UnitBuffer::~UnitBuffer()
{
    size_t i;
    for (i = 0; i < site; i++)
        content[i].ruin();
    free((void*)content);
    size = 0;
    site = 0;
}
size_t UnitBuffer::Site(void)
{
    return site;
}
size_t UnitBuffer::add(void)
{
    size_t should, i, new_size;
    if (site >= size)
    {
        new_size = (size + size / 4 + 8);
        content = (unit*)realloc(content, new_size * sizeof(unit));
        for (i = size; i < new_size; i++) content[i].initial();
        size = new_size;
    }
    should = site;
    site += 1;
    return should;
}
void UnitBuffer::add(long long int c)
{
    content[add()] = c;
}
void UnitBuffer::print(FILE* fp)
{
    size_t i;
    for (i = 0; i < site; i++)
    {
        if (content[i].lexical != 63)
        {
            content[i].print(fp);
        }
        else
        {
            fprintf(fp, "<%3d|%d>: \\n", 63, content[i].type);
        }
        //fprintf(fp, "lexical: %d\n", content[i].lexical);
        fprintf(fp, "\n");
    }
    return;
}
void UnitBuffer::print(FILE* fp, size_t count)
{
    size_t i;
    for (i = 0; i < site && i < count; i++)
    {
        content[i].print(fp);
        fprintf(fp, "\n");
    }
    return;
}
unit& UnitBuffer::operator[](size_t target)
{
    return content[target];
}





CharBuffer::CharBuffer()
{
    size = 128;
    head = 0;
    content = (char*)malloc(sizeof(char) * size);
    site = 0;
}
CharBuffer::~CharBuffer()
{
    //printf("~CharBuffer()\n");
    free((void*)content);
    size = 0;
    site = 0;
    head = 0;
}
size_t CharBuffer::Site(void)
{
    return site;
}
size_t CharBuffer::Length(void)
{
    return (size_t)(site - head);
}
void CharBuffer::Append(char c)
{
    if (site >= size)
    {
        content = (char*)realloc(content, (size + size / 4 + 8) * sizeof(char));
        size = size + size / 4 + 8;
    }
    *(content + site) = c;
    site += 1;
}
void CharBuffer::Append(const char* c)
{
    size_t strsize, i;
    for (strsize = 0; c[strsize] != '\0'; strsize++);
    if (site + strsize > size)
    {
        content = (char*)realloc(content, size + strsize + 4);
        size = size + strsize + 4;
    }
    for (i = 0; i < strsize; i++) content[i + site] = c[i];
    site += strsize;
    return;
}
void CharBuffer::Append(CharBuffer& in)
{
    size_t L, i;
    L = in.Length();
    if (site + L > size)
    {
        content = (char*)realloc(content, size + L + 4);
        size = size + L + 4;
    }
    for (i = 0; i < L; i++) content[i + site] = in.content[i + in.head];
    site += L;
    return;
}
void CharBuffer::Print(FILE* fp)
{
    size_t i;
    for (i = head; i < site; i++)
    {
        fprintf(fp, "%c", content[i]);
    }
    fprintf(fp, "\n");
    return;
}
void CharBuffer::Print(FILE* fp, int count)
{
    size_t i;
    for (i = 0; i < site && i < count; i++)
    {
        fprintf(fp, "%c", content[i]);
    }
    fprintf(fp, "\n");
    return;
}
void CharBuffer::Copy(char* to)
{
    size_t i;
    for (i = head; i < site; i++)
        to[i - head] = content[i];
    to[i - head] = '\0';
    return;
}
char* CharBuffer::CopyMalloc(void)
{
    size_t i, L;
    char* to;
    L = (size_t)((site - head) * ((site - head) > 0));
    to = (char*)malloc(sizeof(char) * (L + 1));
    for (i = 0; i < L; i++)
        to[i] = content[i + head];
    to[L] = '\0';
    return to;
}
char CharBuffer::Pop(void)
{
    if (site == head) return EOF;
    site -= 1;
    return content[site];
}
bool CharBuffer::Pop(char& out)
{
    if (site == head) return false;
    site -= 1;
    out = content[site];
    return true;
}

void CharBuffer::Clear(void)
{
    site = 0;
    head = 0;
}
void CharBuffer::operator<<(char c)
{
    Append(c);
    return;
}
void CharBuffer::operator<<(const char* c)
{
    Append(c);
}
void CharBuffer::operator<<(double e)
{
    char temp[32];
    sprintf(temp, "%+24.16e", e);
    Append(temp);
    return;
}
void CharBuffer::operator<<(int e)
{
    char temp[32];
    sprintf(temp, "%d", e);
    Append(temp);
    return;
}
void CharBuffer::operator<<(long long int e)
{
    char temp[32];
    sprintf(temp, "%lld", e);
    Append(temp);
    return;
}
void CharBuffer::operator<<(CharBuffer& in)
{
    size_t L, i;
    Append(in);
    in.Clear();
    return;
}
void CharBuffer::operator<<(FILE* fp)
{
    while (feof(fp) == 0)
        Append((char)getc(fp));
    //if (site == 0) Append(EOF);
    //else if (content[site - 1] != ((char)(EOF))) Append(EOF);
}
bool CharBuffer::operator==(size_t length)
{
    if ((site - head) <= 0) return length == 0;
    else return (site - head) == length;
}
bool CharBuffer::operator!=(size_t length)
{
    if ((site - head) <= 0) return length != 0;
    else return (site - head) != length;
}


char CharBuffer::Dequeue(void)
{
    if (head >= site) return EOF;
    head += 1;
    return content[head - 1];
}
char CharBuffer::Dequeue(CharBuffer& backspace)
{
    if (backspace.head >= backspace.site)
    {
        if (head >= site) return EOF;
        head += 1;
        return content[head - 1];
    }
    backspace.head += 1;
    return *(backspace.content + backspace.head - 1);
}
char CharBuffer::QueueHead(void)
{
    if (head >= site) return EOF;
    return content[head];
}


IntegerDefault hyperlex::IntGet(const char* list, size_t end, size_t& head)
{
    char c, state;
    IntegerDefault number;
    IntegerDefault Sign = 1;
    number = 0;
    state = 0;
    do
    {
        c = dequeue(list, end, head);
        switch (state)
        {
        case 0:
            if (c >= '0' && c <= '9') number = c - '0';
            else if (c == '-') Sign = -1;
            state = 1;
            break;
        case 1:
            if (c >= '0' && c <= '9') number = number * 10 + c - '0';
            else state = 2;
            break;
        }
    } while (state != 2);
    return number * Sign;
}
double hyperlex::RealGet(int& state, const char* list, size_t end, size_t& head)
{
    char c;
    double number, digit;
    int num_sign = 1;
    int index;
    int index_sign;
    number = 0.0;
    digit = 1.0;
    num_sign = 1.0;
    index_sign = 1;
    index = 0;
    state = 0;
    do
    {
        c = dequeue(list, end, head);
        switch (state)
        {
        case 0:
            if (c == '-') { num_sign = 0; state = 1; }
            else if (c == '+') { num_sign = 1; state = 1; }
            else if (c == '.') state = 2;
            else if (c >= '0' && c <= '9') { number = (double)(c - '0'); state = 3; }
            else state = -1;
            break;
        case 1:
            if (c >= '0' && c <= '9') { number = (double)(c - '0'); state = 3; }
            else if (c == '.') state = 2;
            else state = -1;
            break;
        case 2:
            if (c >= '0' && c <= '9')
            {
                digit *= 0.1;
                number = number + digit * (double)(c - '0');
                state = 4;
            }
            else if (c == 'e' || c == 'E') state = 5;
            else state = -1;
            break;
        case 3:
            if (c >= '0' && c <= '9') { number = number * 10.0 + (double)(c - '0'); state = 3; }
            else if (c == '.') state = 2;
            else state = -1;
            break;
        case 4:
            if (c >= '0' && c <= '9')
            {
                digit *= 0.1;
                number = number + digit * (double)(c - '0');
                state = 4;
            }
            else if (c == 'e' || c == 'E') state = 5;
            else state = -1;
            break;
        case 5:
            if (c == '-') { index_sign = -1; state = 6; }
            else if (c == '+') { index_sign = 1; state = 6; }
            else if (c >= '0' && c <= '9') { index = (int)(c - '0'); state = 7; }
            else state = -1;
            break;
        case 6:
            if (c >= '0' && c <= '9') { index = (int)(c - '0'); state = 7; }
            else state = -1;
            break;
        case 7:
            if (c >= '0' && c <= '9') { index = index * 10 + (int)(c - '0'); state = 7; }
            else state = -1;
            break;
        }
    } while (state != -1);
    number = num_sign ? number : -number;
    digit = (index_sign == 1 ? 10.0 : 0.1);
    while (index != 0)
    {
        index--;
        number *= digit;
    }
    return number;
}
char hyperlex::CharGet(const char* list, size_t end, size_t& head)
{
    char c, result;
    int error;
    result = EOF;
    c = dequeue(list, end, head);
    error = 10;
    if (c == '\'') result = CharGet(error, list, end, head);
    else return EOF;
    c = dequeue(list, end, head);
    if (c == '\'') return result;
    else return EOF;
}




IntegerDefault CharBuffer::DequeueInt(void)
{
    return IntGet(content, site, head);
}
double CharBuffer::DequeueReal(void)
{
    int state;
    return RealGet(state, content, site, head);
}
char CharBuffer::DequeueChar(void)
{
    return CharGet(content, site, head);
}
char* CharBuffer::DequeueString(void)
{
    CharBuffer middle;
    char* temp, c, index;
    int state, error;
    state = 0;
    do
    {
        switch (state)
        {
        case 0:
            index = Dequeue();
            if (index == '\"') state = 1;
            else if (index == (char)EOF) state = -1;
            break;
        case 1:
            index = QueueHead();
            if (index == '\"') state = -2;
            else if (index == (char)EOF) state = -3;
            else
            {
                c = CharGet(error, content, site, head);
                if (c != (char)EOF) middle << c;
            }
            break;
        }
    } while (state >= 0);
    temp = middle.CopyMalloc();
    return temp;
}
char* CharBuffer::DequeueId(void)
{
    CharBuffer middle;
    char* temp, c;
    int state, error;
    state = 0;
    do
    {
        switch (state)
        {
        case 0:
            c = Dequeue();
            if (isIdBegin(c))
            {
                state = 1;
                middle << c;
            }
            else if (c == (char)EOF) state = -2;
            break;
        case 1:
            c = Dequeue();
            if (isIdBegin(c) || isIdNumber(c))
            {
                state = 1;
                middle << c;
            }
            else state = -1;
            break;
        }
    } while (state >= 0);
    temp = middle.CopyMalloc();
    return temp;
}

void UnitBuffer::build(CharBuffer& in)
{
    DFA00 dfa;
    CharBuffer backspace;
    CharBuffer result;
    CharBuffer intermediate;
    char c;
    int state = 0;
    enum DFA00::action Ac;
    c = in.Dequeue(backspace);
    ERROR = 0;
    clear();
    for (; c != ((char)(EOF)); )
    {
        dfa.DFA_swicth(c);
        Ac = dfa.should();
        switch (Ac)
        {
        case DFA00::add:
            result << intermediate;
            result << c;
            c = in.Dequeue(backspace);
            break;
        case DFA00::wait:
            c = in.Dequeue(backspace);
            break;
        case DFA00::record:
            intermediate << c;
            c = in.Dequeue(backspace);
            break;
        case DFA00::retrieve:
            if (result != 0)
            {
                Append(result, dfa.result());
                result.Clear();
                backspace << intermediate;
                break;
            }
        case DFA00::halt:
            std::cout << " HALT ";
            break;
        default:
            c = in.Dequeue();
            break;
        }
    }
}
void UnitBuffer::Append(CharBuffer& result, int state)
{
    //int state;
    size_t target;
    ERROR += (state == 12);
    ERROR += (state == 56);
    ERROR += (state == 58);
    target = add();
    content[target].lexical = state;
    content[target].length = result.Length() + 1;
    content[target].origin = result.CopyMalloc();
    if (state == 0)
    {
        content[target].type = 0;
        content[target].C.integer = result.DequeueInt();
    }
    else if (state == 3 || state == 4)
    {
        content[target].type = 1;
        content[target].C.real = result.DequeueReal();
    }
    else if (state == 57)
    {
        content[target].type = 2;
        content[target].C.C = result.DequeueChar();
    }
    else if (state == 11)
    {
        content[target].type = 3;
        content[target].C.S = result.DequeueString();
    }
    else
    {
        content[target].type = 3;
        content[target].C.S = result.CopyMalloc();
    }
}
void UnitBuffer::clear(void)
{
    size_t i;
    for (i = 0; i < size; i++)
    {
        content[i].ruin();
        content[i].initial();
    }
    site = 0;
}

DFA00::DFA00()
{
    state = 0;
    former_state = 0;
    last_success = -1;
}
DFA00::~DFA00()
{
    state = 0;
    former_state = 0;
    last_success = -1;
}
//=====================================================================================
//--------------------------------lexical analyzer ------------------------------------
//=====================================================================================
    //type = 0: int, type = 1: octonary, type = 2: hexadecimal integer , 
    //type = 3: double type without e&E, type = 4: double type with e&E,
    //type = 5: identifier, type = 6: space
    //type = 7: operator +, type = 8: operator ++
    //type = 9: operator -, type = 10: operator --
    //type = 11: string, type = 12 string without an end, error
    //type = 13: annotation //, type = 14 sign of division /,
    //type = 15: star *, type = 16 double star,
    //type = 17: =, type = 18 ==,
    //type = 19: dot . , type = 20: , , type = 21: ? , type = 22: &, 
    //type = 23: (, type = 24: ),type = 25: [, type = 26: ]
    //type = 27: {, type = 28: },type = 29: ;, type = 30: : 
    //type = 31: ->, type = 32: &&, type = 33 |: , type = 34: || :
    //type = 35: >, type = 36: >=, type = 37 <: , type = 38: <=:
    //type = 39: >>, type = 40: <<, type = 41: <<=, type = 42: >>=
    //type = 43: !, type = 44: !=, type = 45: ^, type = 46: ^=
    //type = 47: +=, type = 48: -=, type = 49: *=, type = 50: /=
    //type = 51: %, type = 52: %=, type = 53: &=, type = 54: |=
    //type = 55: annotation /**/, type = 56 annotation without an end, error
    //type = 57: char '��'����\����, type = 58 char without an end, error
    //type = 59: >>>, type = 60: <<<
    //type = 61: #* pretreatment
    //type = 62: \t, //type = 63: \n
//=================================================================
    //type = 64: if           , type = 65: else
    //type = 66: for          , type = 67: do
    //type = 68: while        , type = 69: switch
    //type = 70: case         , type = 71: goto
    //type = 72: continue     , type = 73: break
    //type = 74: return       , type = 75: default
    //type = 76: typedef      , type = 77: int
    //type = 78: char         , type = 79: double
    //type = 80: float        , type = 81: long
    //type = 82: short        , type = 83: unsigned
    //type = 84: signed       , type = 85: const
    //type = 86: void         , type = 87: volatile
    //type = 88: enum         , type = 89: struct
    //type = 90: union        , type = 91: auto
    //type = 92: register     , type = 93: extern
    //type = 94: static       , type = 95: sizeof

void DFA00::DFA_swicth(char c)
{
    int temp;
    former_state = state;
    switch (state)
    {
    case 0:
        //=================================number and operator begins with + -
        if (c == '+') state = 1;
        else if (c == '-') state = 15;
        else if (c > '0' && c <= '9') state = 2;
        else if (c == '0') state = 9;
        else if (c == '.') state = 8;
        //=================================identifier
        else if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            if (c == 'i') state = 110;
            else if (c == 'e') state = 112;
            else if (c == 'f') state = 116;
            else if (c == 'd') state = 119;
            else if (c == 'w') state = 121;
            else if (c == 's') state = 126;
            else if (c == 'c') state = 132;
            else if (c == 'g') state = 136;
            else if (c == 'b') state = 147;
            else if (c == 'r') state = 152;
            else if (c == 't') state = 164;
            else if (c == 'l') state = 184;
            else if (c == 'u') state = 192;
            else if (c == 'v') state = 207;
            else if (c == 'a') state = 228;
            else state = 14;
        }
        //state = 14;
        //=================================string & char
        else if (c == '\"') state = 18;
        else if (c == '\'') state = 31;
        //=================================annotation & pretreatment
        else if (c == '/') state = 21;
        else if (c == '#') state = 35;
        //=================================single char
        else if (c == ' ') state = 64;
        else if (c == '*') state = 65;
        else if (c == '=') state = 67;
        else if (c == ',') state = 69;
        else if (c == '?') state = 70;
        else if (c == '&') state = 71;
        else if (c == '(') state = 72;
        else if (c == ')') state = 73;
        else if (c == '[') state = 74;
        else if (c == ']') state = 75;
        else if (c == '{') state = 76;
        else if (c == '}') state = 77;
        else if (c == ';') state = 78;
        else if (c == ':') state = 79;
        else if (c == '|') state = 82;
        else if (c == '>') state = 84;
        else if (c == '<') state = 88;
        else if (c == '!') state = 92;
        else if (c == '^') state = 94;
        else if (c == '%') state = 97;
        else if (c == '\t') state = 103;
        else if (c == '\n') state = 104;
        //=================================
        //else begin = -1;
        break;
    case 1://
        if (c >= '0' && c <= '9') state = 2;
        else if (c == '.') state = 8;
        else if (c == '+') state = 16;
        else if (c == '=') state = 24;
        else state = 0;
        break;
    case 2:
        if (c >= '0' && c <= '9') state = 2;
        else if (c == '.') state = 3;
        else if (c == 'e' || c == 'E') state = 5;
        else state = 0;
        break;
    case 3:// actually it's the same with 4
        if (c >= '0' && c <= '9') state = 4;
        else if (c == 'e' || c == 'E') state = 5;
        else state = 0;
        break;
    case 4:
        if (c >= '0' && c <= '9') state = 4;
        else if (c == 'e' || c == 'E') state = 5;
        else state = 0;
        break;
    case 5:
        if (c >= '0' && c <= '9') state = 7;
        else if (c == '+' || c == '-') state = 6;
        else state = 0;
        break;
    case 6:
        if (c >= '0' && c <= '9') state = 7;
        else state = 0;
        break;
    case 7:
        if (c >= '0' && c <= '9') state = 7;
        else state = 0;
        break;
    case 8:
        if (c >= '0' && c <= '9') state = 4;
        else state = 0;
        break;
    case 9:
        if (c >= '1' && c <= '7') state = 10;
        else if (c == '0') state = 13;
        else if (c == '.') state = 3;
        else if (c == 'e' || c == 'E') state = 5;
        else if (c == 'x' || c == 'X') state = 11;
        else state = 0;
        break;
    case 10:
        if (c >= '0' && c <= '7') state = 10;
        else state = 0;
        break;
    case 11:
        if (c >= '0' && c <= '9') state = 12;
        else if (c >= 'a' && c <= 'f') state = 12;
        else if (c >= 'A' && c <= 'F') state = 12;
        else state = 0;
        break;
    case 12:
        if (c >= '0' && c <= '9') state = 12;
        else if (c >= 'a' && c <= 'f') state = 12;
        else if (c >= 'A' && c <= 'F') state = 12;
        else state = 0;
        break;
    case 13:
        if (c == '0') state = 13;
        else if (c >= '1' && c <= '7') state = 10;
        else if (c == '.') state = 3;
        else if (c == 'e' || c == 'E') state = 5;
        else state = 0;
        break;
    case 14:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 15://-
        if (c >= '0' && c <= '9') state = 2;
        else if (c == '.') state = 8;
        else if (c == '-') state = 17;
        else if (c == '>') state = 80;
        else if (c == '=') state = 25;
        else state = 0;
        break;
    case 16:
        state = 0;
        break;
    case 17:
        state = 0;
        break;
    case 18:
        if (c == '\"') state = 20;
        else if (c == '\\') state = 27;
        else state = 19;
        break;
    case 19:
        if (c == '\"') state = 20;
        else if (c == '\\') state = 27;
        else state = 19;
        break;
    case 20:
        state = 0;
        break;
    case 21:// /
        if (c == '/') state = 22;
        else if (c == '=') state = 26;
        else if (c == '*') state = 28;
        else state = 0;
        break;
    case 22:
        if (c == '\n') state = 0;
        else if (c == '\r') state = 23;
        break;
    case 23:
        if (c == '\n') state = 0;
        else state = 22;
        break;
    case 24://+=
        state = 0;
        break;
    case 25://-=
        state = 0;
        break;
    case 26:// /=
        state = 0;
        break;
    case 27:
        state = 19;
        break;
    case 28:
        if (c == '*') state = 29;
        else state = 28;
        break;
    case 29:
        if (c == '/') state = 30;
        else if (c == '*') state = 29;
        else state = 28;
        break;
    case 30:
        state = 0;
        break;
    case 31:
        if (c == '\\') state = 32;
        else state = 33;
        break;
    case 32:
        state = 33;
        break;
    case 33:
        if (c == '\'') state = 34;
        else state = 0;
        break;
    case 34:
        state = 0;
        break;
        //===
    case 35:
        if (c == '\n') state = 36;
        else state = 35;
        break;
    case 36:
        state = 0;
        break;
        //=================================single char
    case 64:
        state = 0;
        break;
    case 65:
        if (c == '*') state = 66;
        else if (c == '=') state = 96;
        else state = 0;
        break;
    case 66:
        state = 0;
        break;
    case 67://=
        if (c == '=') state = 68;
        else state = 0;
        break;
    case 68://==
        state = 0;
        break;
    case 69://,
        state = 0;
        break;
    case 70://?
        state = 0;
        break;
    case 71://&
        if (c == '&') state = 81;
        else if (c == '=') state = 99;
        else state = 0;
        break;
    case 72://(
        state = 0;
        break;
    case 73://)
        state = 0;
        break;
    case 74://[
        state = 0;
        break;
    case 75://]
        state = 0;
        break;
    case 76://{
        state = 0;
        break;
    case 77://}
        state = 0;
        break;
    case 78://;
        state = 0;
        break;
    case 79://:
        state = 0;
        break;
    case 80://->
        state = 0;
        break;
    case 81://&&
        state = 0;
        break;
    case 82://|
        if (c == '|') state = 83;
        else if (c == '=') state = 100;
        else state = 0;
        break;
    case 83://||
        state = 0;
        break;
        //=========>
    case 84://>
        if (c == '>') state = 85;
        else if (c == '=') state = 86;
        else state = 0;
        break;
    case 85://>>
        if (c == '=') state = 87;
        else if (c == '>') state = 101;
        else state = 0;
        break;
    case 86://>=
        state = 0;
        break;
    case 87://>>=
        state = 0;
        break;
        //=========< 
    case 88://<
        if (c == '<') state = 89;
        else if (c == '=') state = 90;
        else state = 0;
        break;
    case 89://<<
        if (c == '=') state = 91;
        else if (c == '<') state = 102;
        else state = 0;
        break;
    case 90://<=
        state = 0;
        break;
    case 91://<<=
        state = 0;
        break;
        //=========
    case 92://!
        if (c == '=') state = 93;
        else state = 0;
        break;
    case 93://!=
        state = 0;
        break;
    case 94://^
        if (c == '=') state = 95;
        else state = 0;
        break;
    case 95://^=
        state = 0;
        break;
    case 96://*=
        state = 0;
        break;
    case 97://%
        if (c == '=') state = 98;
        else state = 0;
        break;
    case 98://%=
        state = 0;
        break;
    case 99://&=
        state = 0;
        break;
    case 100://|=
        state = 0;
        break;
    case 101://>>>
        state = 0;
        break;
    case 102://<<<
        state = 0;
        break;
    case 103://\t
        state = 0;
        break;
    case 104://\n
        state = 0;
        break;
        //======================================
    case 110:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'f') state = 111;
            else if (c == 'n') state = 171;
            else state = 14;
        }
        else state = 0;
        break;
    case 112:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'l') state = 113;
            else if (c == 'n') state = 217;
            else if (c == 'x') state = 238;
            else state = 14;
        }
        else state = 0;
        break;
    case 116:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 117;
            else if (c == 'l') state = 180;
            else state = 14;
        }
        else state = 0;
        break;
    case 119:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 120;
            else if (c == 'e') state = 158;
            else state = 14;
        }
        else state = 0;
        break;
    case 121:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'h') state = 122;
            else state = 14;
        }
        else state = 0;
        break;
    case 126:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'w') state = 127;
            else if (c == 'h') state = 188;
            else if (c == 'i') state = 200;
            else if (c == 't') state = 220;
            else state = 14;
        }
        else state = 0;
        break;
    case 132:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 133;
            else if (c == 'o') state = 140;
            else if (c == 'h') state = 173;
            else state = 14;
        }
        else state = 0;
        break;
    case 136:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 137;
            else state = 14;
        }
        else state = 0;
        break;
    case 147:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 148;
            else state = 14;
        }
        else state = 0;
        break;
    case 152:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 153;
            else state = 14;
        }
        else state = 0;
        break;
    case 164:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'y') state = 165;
            else state = 14;
        }
        else state = 0;
        break;
    case 184:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 185;
            else state = 14;
        }
        else state = 0;
        break;
    case 192:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 193;
            else state = 14;
        }
        else state = 0;
        break;
    case 207:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 208;
            else state = 14;
        }
        else state = 0;
        break;
    case 228:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 229;
            else state = 14;
        }
        else state = 0;
        break;
    case 111://if
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 171:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 172;
            else state = 14;
        }
        else state = 0;
        break;
    case 113:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 's') state = 114;
            else state = 14;
        }
        else state = 0;
        break;
    case 217:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 218;
            else state = 14;
        }
        else state = 0;
        break;
    case 238:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 239;
            else state = 14;
        }
        else state = 0;
        break;
    case 117:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 118;
            else state = 14;
        }
        else state = 0;
        break;
    case 180:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 181;
            else state = 14;
        }
        else state = 0;
        break;
    case 120:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 176;
            else state = 14;
        }
        else state = 0;
        break;
    case 158:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'f') state = 159;
            else state = 14;
        }
        else state = 0;
        break;
    case 122:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 123;
            else state = 14;
        }
        else state = 0;
        break;
    case 127:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 128;
            else state = 14;
        }
        else state = 0;
        break;
    case 188:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 189;
            else state = 14;
        }
        else state = 0;
        break;
    case 200:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'g') state = 201;
            else if (c == 'z') state = 247;
            else state = 14;
        }
        else state = 0;
        break;
    case 220:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 221;
            else if (c == 'a') state = 243;
            else state = 14;
        }
        else state = 0;
        break;
    case 133:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 's') state = 134;
            else state = 14;
        }
        else state = 0;
        break;
    case 140:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 141;
            else state = 14;
        }
        else state = 0;
        break;
    case 173:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 174;
            else state = 14;
        }
        else state = 0;
        break;
    case 137:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 138;
            else state = 14;
        }
        else state = 0;
        break;
    case 148:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 149;
            else state = 14;
        }
        else state = 0;
        break;
    case 153:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 154;
            else if (c == 'g') state = 232;
            else state = 14;
        }
        else state = 0;
        break;
    case 165:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'p') state = 166;
            else state = 14;
        }
        else state = 0;
        break;
    case 185:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 186;
            else state = 14;
        }
        else state = 0;
        break;
    case 193:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 's') state = 194;
            else if (c == 'i') state = 225;
            else state = 14;
        }
        else state = 0;
        break;
    case 208:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 209;
            else if (c == 'l') state = 211;
            else state = 14;
        }
        else state = 0;
        break;
    case 229:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 230;
            else state = 14;
        }
        else state = 0;
        break;
    case 172://int
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 114:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 115;
            else state = 14;
        }
        else state = 0;
        break;
    case 218:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'm') state = 219;
            else state = 14;
        }
        else state = 0;
        break;
    case 239:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 240;
            else state = 14;
        }
        else state = 0;
        break;
    case 118://for
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 181:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 182;
            else state = 14;
        }
        else state = 0;
        break;
    case 176:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'b') state = 177;
            else state = 14;
        }
        else state = 0;
        break;
    case 159:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 160;
            else state = 14;
        }
        else state = 0;
        break;
    case 123:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'l') state = 124;
            else state = 14;
        }
        else state = 0;
        break;
    case 128:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 129;
            else state = 14;
        }
        else state = 0;
        break;
    case 189:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 190;
            else state = 14;
        }
        else state = 0;
        break;
    case 201:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 202;
            else state = 14;
        }
        else state = 0;
        break;
    case 247:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 248;
            else state = 14;
        }
        else state = 0;
        break;
    case 221:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 222;
            else state = 14;
        }
        else state = 0;
        break;
    case 243:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 244;
            else state = 14;
        }
        else state = 0;
        break;
    case 134:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 135;
            else state = 14;
        }
        else state = 0;
        break;
    case 141:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 142;
            else if (c == 's') state = 205;
            else state = 14;
        }
        else state = 0;
        break;
    case 174:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 175;
            else state = 14;
        }
        else state = 0;
        break;
    case 138:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 139;
            else state = 14;
        }
        else state = 0;
        break;
    case 149:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 150;
            else state = 14;
        }
        else state = 0;
        break;
    case 154:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 155;
            else state = 14;
        }
        else state = 0;
        break;
    case 232:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 233;
            else state = 14;
        }
        else state = 0;
        break;
    case 166:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 167;
            else state = 14;
        }
        else state = 0;
        break;
    case 186:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'g') state = 187;
            else state = 14;
        }
        else state = 0;
        break;
    case 194:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 195;
            else state = 14;
        }
        else state = 0;
        break;
    case 225:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 226;
            else state = 14;
        }
        else state = 0;
        break;
    case 209:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'd') state = 210;
            else state = 14;
        }
        else state = 0;
        break;
    case 211:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'a') state = 212;
            else state = 14;
        }
        else state = 0;
        break;
    case 230:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 231;
            else state = 14;
        }
        else state = 0;
        break;
    case 115://else
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 219://enum
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 240:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 241;
            else state = 14;
        }
        else state = 0;
        break;
    case 182:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 183;
            else state = 14;
        }
        else state = 0;
        break;
    case 177:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'l') state = 178;
            else state = 14;
        }
        else state = 0;
        break;
    case 160:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 161;
            else state = 14;
        }
        else state = 0;
        break;
    case 124:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 125;
            else state = 14;
        }
        else state = 0;
        break;
    case 129:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'c') state = 130;
            else state = 14;
        }
        else state = 0;
        break;
    case 190:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 191;
            else state = 14;
        }
        else state = 0;
        break;
    case 202:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 203;
            else state = 14;
        }
        else state = 0;
        break;
    case 248:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'o') state = 249;
            else state = 14;
        }
        else state = 0;
        break;
    case 222:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'c') state = 223;
            else state = 14;
        }
        else state = 0;
        break;
    case 244:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 245;
            else state = 14;
        }
        else state = 0;
        break;
    case 135://case
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 142:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 143;
            else state = 14;
        }
        else state = 0;
        break;
    case 205:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 206;
            else state = 14;
        }
        else state = 0;
        break;
    case 175://char
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 139://goto
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 150:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'k') state = 151;
            else state = 14;
        }
        else state = 0;
        break;
    case 155:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 156;
            else state = 14;
        }
        else state = 0;
        break;
    case 233:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 's') state = 234;
            else state = 14;
        }
        else state = 0;
        break;
    case 167:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'd') state = 168;
            else state = 14;
        }
        else state = 0;
        break;
    case 187://long
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 195:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'g') state = 196;
            else state = 14;
        }
        else state = 0;
        break;
    case 226:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 227;
            else state = 14;
        }
        else state = 0;
        break;
    case 210://void
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 212:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 213;
            else state = 14;
        }
        else state = 0;
        break;
    case 231://auto
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 241:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 242;
            else state = 14;
        }
        else state = 0;
        break;
    case 183://float
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 178:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 179;
            else state = 14;
        }
        else state = 0;
        break;
    case 161:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'l') state = 162;
            else state = 14;
        }
        else state = 0;
        break;
    case 125://while
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 130:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'h') state = 131;
            else state = 14;
        }
        else state = 0;
        break;
    case 191://short
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 203:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'd') state = 204;
            else state = 14;
        }
        else state = 0;
        break;
    case 249:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'f') state = 250;
            else state = 14;
        }
        else state = 0;
        break;
    case 223:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 224;
            else state = 14;
        }
        else state = 0;
        break;
    case 245:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'c') state = 246;
            else state = 14;
        }
        else state = 0;
        break;
    case 143:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 144;
            else state = 14;
        }
        else state = 0;
        break;
    case 206://const
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 151://break
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 156:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 157;
            else state = 14;
        }
        else state = 0;
        break;
    case 234:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 235;
            else state = 14;
        }
        else state = 0;
        break;
    case 168:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 169;
            else state = 14;
        }
        else state = 0;
        break;
    case 196:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'n') state = 197;
            else state = 14;
        }
        else state = 0;
        break;
    case 227://union
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 213:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'i') state = 214;
            else state = 14;
        }
        else state = 0;
        break;
    case 242://extern
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 179://double
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 162:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 't') state = 163;
            else state = 14;
        }
        else state = 0;
        break;
    case 131://switch
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 204://signed
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 250://sizeof
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 224://struct
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 246://static
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 144:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'u') state = 145;
            else state = 14;
        }
        else state = 0;
        break;
    case 157://return
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 235:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 236;
            else state = 14;
        }
        else state = 0;
        break;
    case 169:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'f') state = 170;
            else state = 14;
        }
        else state = 0;
        break;
    case 197:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 198;
            else state = 14;
        }
        else state = 0;
        break;
    case 214:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'l') state = 215;
            else state = 14;
        }
        else state = 0;
        break;
    case 163://default
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 145:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 146;
            else state = 14;
        }
        else state = 0;
        break;
    case 236:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'r') state = 237;
            else state = 14;
        }
        else state = 0;
        break;
    case 170://typedef
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 198:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'd') state = 199;
            else state = 14;
        }
        else state = 0;
        break;
    case 215:
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            if (c == 'e') state = 216;
            else state = 14;
        }
        else state = 0;
        break;
    case 146://continue
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 237://register
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 199://unsigned
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
    case 216://volatile
        if (c == '_' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) state = 14;
        else state = 0;
        break;
        //======================================
    }
    temp = this->success_get(state);
    if (temp != -1) last_success = temp;
}
int DFA00::success_get(int State)
{
    int succeed;
    switch (State)
    {
    case 1:
        succeed = 7;
        break;
    case 2:
        succeed = 0;
        break;
    case 3:
        succeed = 3;
        break;
    case 4:
        succeed = 3;
        break;
        //case 5:
            //succeed =  4;
            //break;
    case 7:
        succeed = 4;
        break;
    case 8:
        succeed = 19;
        break;
    case 9:
        succeed = 0;
        break;
    case 10:
        succeed = 1;
        break;
    case 11:
        succeed = 2;
        break;
    case 13:
        succeed = 0;
        break;
    case 14:
        succeed = 5;
        break;
    case 15:
        succeed = 9;
        break;
    case 16:
        succeed = 8;
        break;
    case 17:
        succeed = 10;
        break;
    case 18:
        succeed = 12;
        break;
    case 19:
        succeed = 12;
        break;
    case 20:
        succeed = 11;
        break;
    case 21:
        succeed = 14;
        break;
    case 22:
        succeed = 13;
        break;
    case 23:
        succeed = 13;
        break;
    case 24:
        succeed = 47;
        break;
    case 25:
        succeed = 48;
        break;
    case 26:
        succeed = 50;
        break;
    case 27:
        succeed = 12;
        break;
    case 28:
        succeed = 56;
        break;
    case 29:
        succeed = 56;
        break;
    case 30:
        succeed = 55;
        break;
    case 31:
        succeed = 58;
        break;
    case 32:
        succeed = 58;
        break;
    case 33:
        succeed = 58;
        break;
    case 34:
        succeed = 57;
        break;
    case 35:
        succeed = 61;
        break;
    case 36:
        succeed = 61;
        break;
    case 64:
        succeed = 6;
        break;
    case 65:
        succeed = 15;
        break;
    case 66:
        succeed = 16;
        break;
    case 67:
        succeed = 17;
        break;
    case 68:
        succeed = 18;
        break;
    case 69:
        succeed = 20;
        break;
    case 70:
        succeed = 21;
        break;
    case 71:
        succeed = 22;
        break;
    case 72:
        succeed = 23;
        break;
    case 73:
        succeed = 24;
        break;
    case 74:
        succeed = 25;
        break;
    case 75:
        succeed = 26;
        break;
    case 76:
        succeed = 27;
        break;
    case 77:
        succeed = 28;
        break;
    case 78:
        succeed = 29;
        break;
    case 79:
        succeed = 30;
        break;
    case 80:
        succeed = 31;
        break;
    case 81:
        succeed = 32;
        break;
    case 82:
        succeed = 33;
        break;
    case 83:
        succeed = 34;
        break;
    case 84:
        succeed = 35;
        break;
    case 85:
        succeed = 39;
        break;
    case 86:
        succeed = 36;
        break;
    case 87:
        succeed = 42;
        break;
    case 88:
        succeed = 37;
        break;
    case 89:
        succeed = 40;
        break;
    case 90:
        succeed = 38;
        break;
    case 91:
        succeed = 41;
        break;
    case 92:
        succeed = 43;
        break;
    case 93:
        succeed = 44;
        break;
    case 94:
        succeed = 45;
        break;
    case 95:
        succeed = 46;
        break;
    case 96:
        succeed = 49;
        break;
    case 97:
        succeed = 51;
        break;
    case 98:
        succeed = 52;
        break;
    case 99:
        succeed = 53;
        break;
    case 100:
        succeed = 54;
        break;
    case 101:
        succeed = 59;
        break;
    case 102:
        succeed = 60;
        break;
    case 103:
        succeed = 62;
        break;
    case 104:
        succeed = 63;
        break;
    case 110:
        succeed = 5;
        break;
    case 112:
        succeed = 5;
        break;
    case 116:
        succeed = 5;
        break;
    case 119:
        succeed = 5;
        break;
    case 121:
        succeed = 5;
        break;
    case 126:
        succeed = 5;
        break;
    case 132:
        succeed = 5;
        break;
    case 136:
        succeed = 5;
        break;
    case 147:
        succeed = 5;
        break;
    case 152:
        succeed = 5;
        break;
    case 164:
        succeed = 5;
        break;
    case 184:
        succeed = 5;
        break;
    case 192:
        succeed = 5;
        break;
    case 207:
        succeed = 5;
        break;
    case 228:
        succeed = 5;
        break;
    case 111:
        succeed = 64;
        break;
    case 171:
        succeed = 5;
        break;
    case 113:
        succeed = 5;
        break;
    case 217:
        succeed = 5;
        break;
    case 238:
        succeed = 5;
        break;
    case 117:
        succeed = 5;
        break;
    case 180:
        succeed = 5;
        break;
    case 120:
        succeed = 5;
        break;
    case 158:
        succeed = 5;
        break;
    case 122:
        succeed = 5;
        break;
    case 127:
        succeed = 5;
        break;
    case 188:
        succeed = 5;
        break;
    case 200:
        succeed = 5;
        break;
    case 220:
        succeed = 5;
        break;
    case 133:
        succeed = 5;
        break;
    case 140:
        succeed = 5;
        break;
    case 173:
        succeed = 5;
        break;
    case 137:
        succeed = 5;
        break;
    case 148:
        succeed = 5;
        break;
    case 153:
        succeed = 5;
        break;
    case 165:
        succeed = 5;
        break;
    case 185:
        succeed = 5;
        break;
    case 193:
        succeed = 5;
        break;
    case 208:
        succeed = 5;
        break;
    case 229:
        succeed = 5;
        break;
    case 172:
        succeed = 77;
        break;
    case 114:
        succeed = 5;
        break;
    case 218:
        succeed = 5;
        break;
    case 239:
        succeed = 5;
        break;
    case 118:
        succeed = 66;
        break;
    case 181:
        succeed = 5;
        break;
    case 176:
        succeed = 5;
        break;
    case 159:
        succeed = 5;
        break;
    case 123:
        succeed = 5;
        break;
    case 128:
        succeed = 5;
        break;
    case 189:
        succeed = 5;
        break;
    case 201:
        succeed = 5;
        break;
    case 247:
        succeed = 5;
        break;
    case 221:
        succeed = 5;
        break;
    case 243:
        succeed = 5;
        break;
    case 134:
        succeed = 5;
        break;
    case 141:
        succeed = 5;
        break;
    case 174:
        succeed = 5;
        break;
    case 138:
        succeed = 5;
        break;
    case 149:
        succeed = 5;
        break;
    case 154:
        succeed = 5;
        break;
    case 232:
        succeed = 5;
        break;
    case 166:
        succeed = 5;
        break;
    case 186:
        succeed = 5;
        break;
    case 194:
        succeed = 5;
        break;
    case 225:
        succeed = 5;
        break;
    case 209:
        succeed = 5;
        break;
    case 211:
        succeed = 5;
        break;
    case 230:
        succeed = 5;
        break;
    case 115:
        succeed = 65;
        break;
    case 219:
        succeed = 88;
        break;
    case 240:
        succeed = 5;
        break;
    case 182:
        succeed = 5;
        break;
    case 177:
        succeed = 5;
        break;
    case 160:
        succeed = 5;
        break;
    case 124:
        succeed = 5;
        break;
    case 129:
        succeed = 5;
        break;
    case 190:
        succeed = 5;
        break;
    case 202:
        succeed = 5;
        break;
    case 248:
        succeed = 5;
        break;
    case 222:
        succeed = 5;
        break;
    case 244:
        succeed = 5;
        break;
    case 135:
        succeed = 70;
        break;
    case 142:
        succeed = 5;
        break;
    case 205:
        succeed = 5;
        break;
    case 175:
        succeed = 78;
        break;
    case 139:
        succeed = 71;
        break;
    case 150:
        succeed = 5;
        break;
    case 155:
        succeed = 5;
        break;
    case 233:
        succeed = 5;
        break;
    case 167:
        succeed = 5;
        break;
    case 187:
        succeed = 81;
        break;
    case 195:
        succeed = 5;
        break;
    case 226:
        succeed = 5;
        break;
    case 210:
        succeed = 86;
        break;
    case 212:
        succeed = 5;
        break;
    case 231:
        succeed = 91;
        break;
    case 241:
        succeed = 5;
        break;
    case 183:
        succeed = 80;
        break;
    case 178:
        succeed = 5;
        break;
    case 161:
        succeed = 5;
        break;
    case 125:
        succeed = 68;
        break;
    case 130:
        succeed = 5;
        break;
    case 191:
        succeed = 82;
        break;
    case 203:
        succeed = 5;
        break;
    case 249:
        succeed = 5;
        break;
    case 223:
        succeed = 5;
        break;
    case 245:
        succeed = 5;
        break;
    case 143:
        succeed = 5;
        break;
    case 206:
        succeed = 85;
        break;
    case 151:
        succeed = 73;
        break;
    case 156:
        succeed = 5;
        break;
    case 234:
        succeed = 5;
        break;
    case 168:
        succeed = 5;
        break;
    case 196:
        succeed = 5;
        break;
    case 227:
        succeed = 90;
        break;
    case 213:
        succeed = 5;
        break;
    case 242:
        succeed = 93;
        break;
    case 179:
        succeed = 79;
        break;
    case 162:
        succeed = 5;
        break;
    case 131:
        succeed = 69;
        break;
    case 204:
        succeed = 84;
        break;
    case 250:
        succeed = 95;
        break;
    case 224:
        succeed = 89;
        break;
    case 246:
        succeed = 94;
        break;
    case 144:
        succeed = 5;
        break;
    case 157:
        succeed = 74;
        break;
    case 235:
        succeed = 5;
        break;
    case 169:
        succeed = 5;
        break;
    case 197:
        succeed = 5;
        break;
    case 214:
        succeed = 5;
        break;
    case 163:
        succeed = 75;
        break;
    case 145:
        succeed = 5;
        break;
    case 236:
        succeed = 5;
        break;
    case 170:
        succeed = 76;
        break;
    case 198:
        succeed = 5;
        break;
    case 215:
        succeed = 5;
        break;
    case 146:
        succeed = 72;
        break;
    case 237:
        succeed = 92;
        break;
    case 199:
        succeed = 83;
        break;
    case 216:
        succeed = 87;
        break;
    default:
        succeed = -1;
        break;
    }
    return succeed;
}
int DFA00::DFA_state(void)
{
    return state;
}
int DFA00::DFA_former_state(void)
{
    return former_state;
}
enum DFA00::action DFA00::should(void)
{
    if (state < 0) return halt;
    if (this->success_get(state) != -1) return add;
    if (former_state == 0)
    {
        if (state == 0) return wait;
        else return record;
    }
    //else if (this->success_get(former_state) != -1)
    //{
        //if(state == 0) return retrieve;
        //else return record;
    //}
    else
    {
        if (state == 0) return retrieve;
        else return record;
    }
}
int DFA00::result(void)
{
    return last_success;
}
int  DFA00::if_error(int type)
{
    return (type == 12) || (type == 56) || (type == 58);
}
void DFA00::lexical_analyse(CharBuffer& in)
{
    CharBuffer backspace;
    CharBuffer result;
    CharBuffer intermediate;
    char c;
    int state = 0, next;
    enum action Ac;
    char* temp;
    c = in.Dequeue(backspace);
    std::cout << this->DFA_state() << " " << c << " : \n";
    for (; c != ((char)(EOF)); )
    {
        this->DFA_swicth(c);
        Ac = this->should();
        //cout << this->DFA_state() << " : " << c << Endl;
        switch (Ac)
        {
        case add:
            result << intermediate;
            result << c;
            //cout << c; 
            c = in.Dequeue(backspace);
            break;
        case wait:
            //cout << c; 
            c = in.Dequeue(backspace);
            break;
        case record:
            intermediate << c;
            c = in.Dequeue(backspace);
            break;
        case retrieve:
            if (result != 0)
            {
                temp = result.CopyMalloc();
                std::cout << '<' << temp << "> ";
                free(temp);
                result.Clear();
                backspace << intermediate;
                break;
            }
        case halt:
            std::cout << " HALT ";
            break;
        default:
            c = in.Dequeue();
            break;
        }
    }
}


Bitwise::Bitwise()
{
    fp = NULL;
}
Bitwise::~Bitwise()
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
}

CFile::CFile()
{
}
CFile::~CFile()
{
}
void hyperlex::ExitWarning(int error, FILE* fp)
{
    if (error == 0) return;
    fprintf(fp, "\n\n\n");
    fprintf(fp, "=============================================================================================================================\n");
    fprintf(fp, "-----------------------------------------------------------ALARM!!!----------------------------------------------------------\n");
    fprintf(fp, "---------------------------------------------The hyperlex system meets a mistake!--------------------------------------------\n");
    fprintf(fp, "----------------------------------It can't compute the reslut, and must be terminated at once.-------------------------------\n");
    fprintf(fp, "====================================================The error code is:%4d===================================================\n", error);
    fprintf(fp, "=============================================================================================================================\n");
    fprintf(fp, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    fprintf(fp, "\n\n\n");
    exit(error);
    return;
}
void hyperlex::Ruin(char** list, size_t length)
{
    size_t i;
    for (i = 0; i < length; i++)
        free(list[i]);
    free(list);
}
bool hyperlex::IfLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool hyperlex::StringToBool(const char* c_t_f)
{
    size_t i;
    for (i = 0; c_t_f[i] != '\0'; i++)
        if (IfLetter(c_t_f[i]))
            return c_t_f[i] == 'y' || c_t_f[i] == 'Y' || c_t_f[i] == 't' || c_t_f[i] == 'T';
    return false;
}


void Bitwise::Open(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "ab+");
}
void Bitwise::StoreOpen(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "wb");
}
void Bitwise::LoadOpen(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "rb");
}
void Bitwise::SetDMatrix(const double* mat, size_t row, size_t column)
{
    if (fp == NULL) return;
    fwrite(&row, sizeof(size_t), 1, fp);
    fwrite(&column, sizeof(size_t), 1, fp);
    fwrite(mat, sizeof(double), row * column, fp);
}
double* Bitwise::GetDMatrix(size_t* row, size_t* column)
{
    double* mat;
    size_t size;
    if (fp == NULL) return NULL;
    fread(row, sizeof(size_t), 1, fp);
    fread(column, sizeof(size_t), 1, fp);
    size = row[0] * column[0];
    mat = (double*)malloc(sizeof(double) * size);
    fread(mat, sizeof(double), size, fp);
    return mat;
}

void Bitwise::store(size_t value)
{
    fwrite(&value, sizeof(size_t), 1, fp);
}
void Bitwise::store(const size_t* vector, size_t length)
{
    fwrite(vector, sizeof(size_t), length, fp);
}
void Bitwise::store(const bool* vector, size_t length)
{
    fwrite(vector, sizeof(bool), length, fp);
}
void Bitwise::store(const int* vector, size_t length)
{
    fwrite(vector, sizeof(int), length, fp);
}
void Bitwise::store(const void* vector, size_t byte)
{
    fwrite(vector, 1, byte, fp);
}

void Bitwise::store(const char* list)
{
    size_t length;
    length = 0;
    if (list == NULL)
    {
        fwrite(&length, sizeof(size_t), 1, fp);
        return;
    }
    for (length = 0; list[length] != '\0'; length++);
    length++;
    fwrite(&length, sizeof(size_t), 1, fp);
    fwrite(list, sizeof(char), length, fp);
}
void Bitwise::store(const char** list, size_t length)
{
    size_t i;
    fwrite(&length, sizeof(size_t), 1, fp);
    for (i = 0; i < length; i++)
        store((const char*)(list[i]));
}


size_t Bitwise::loadllu(void)
{
    size_t value;
    fread(&value, sizeof(size_t), 1, fp);
    return value;
}
char* Bitwise::loadstring(void)
{
    char* list;
    size_t length;
    fread(&length, sizeof(size_t), 1, fp);
    if (length == 0) return NULL;
    list = (char*)malloc(sizeof(char) * length);
    fread(list, sizeof(char), length, fp);
    return list;
}
char** Bitwise::loadlist(void)
{
    char** list;
    size_t length, i;
    fread(&length, sizeof(size_t), 1, fp);
    list = (char**)malloc(sizeof(char*) * length);
    for (i = 0; i < length; i++)
        list[i] = loadstring();
    return list;
}
void* Bitwise::load(size_t byte)
{
    void* vector;
    vector = malloc(byte);
    fread(vector, 1, byte, fp);
    return vector;
}
void* Bitwise::load(size_t EleAmount, size_t ContainerAmount, size_t EleSize)
{
    void* vector;
    vector = malloc(ContainerAmount * EleSize);
    fread(vector, EleSize, EleAmount, fp);
    return vector;
}


ParaFile::ParaFile()
{
    //printf("giuirefgds\n");
    KeyAmount = 0;
    ContainerSize = 0;
    key = NULL;
    FirstElem = NULL;
    ElemAmount = NULL;
    Next = NULL;
    Type = NULL;
}
ParaFile::~ParaFile()
{
    free(key);
    free(FirstElem);
    free(ElemAmount);
    free(Next);
    free(Type);
}
int ParaFile::initial(FILE* fp)
{
    CharBuffer Buffer;
    Buffer << fp;
    return initial(Buffer);
}
int ParaFile::initial(const char* file)
{
    FILE* fp;
    CFile F;
    //printf("adfereqw111111r\n");
    fp = F.Open(file, "r");
    CharBuffer Buffer;
    Buffer << fp;
    fclose(fp);
    //printf("adfereqw112222211r\n");
    return initial(Buffer);
}
int ParaFile::initial(CharBuffer& in)
{
    size_t i;
    build(in);
    //print(stdout);
    if (ERROR != 0) return ERROR;
    Next = (size_t*)malloc(sizeof(size_t) * site);
    for (i = 0; i < site; i++) Next[i] = site;
    return construct(in);
}
int ParaFile::construct(CharBuffer& in)
{
    int state, T;
    size_t i, rear, stack;
    size_t head;
    state = 0;
    ParaType Typetemp;
    //printf("adfereqw133331r\n");
    for (i = 0; i < site; i++)
    {
        T = content[i].lexical;
        switch (state)
        {
        case 0:
            if (T == 5)
            {
                append(i);
                state = 1;
            }
            break;
        case 1:
            if (IfContent(T)) // 3
            {
                i = site;
                ERROR = 100;
            }
            else if (T == 17) state = 2;
            break;
        case 2:
            if (IfContent(T))
            {
                FirstElem[Target] = i;
                ElemAmount[Target] = 1;
                Type[Target] = SwitchType(T);
                state = 0;
            }
            else if (T == 25)
            {
                stack = 1;
                state = 3;
            }
            break;
        case 3:
            if (IfContent(T))
            {
                ElemAmount[Target] += 1;
                if (ElemAmount[Target] == 1)
                {
                    rear = i;
                    FirstElem[Target] = i;
                    Type[Target] = SwitchType(T);
                }
                else
                {
                    Next[rear] = i;
                    rear = i;
                    Typetemp = SwitchType(T);
                    if (Type[Target] != Typetemp) Type[Target] = Mix;
                }
            }
            else if (T == 25) stack += 1;
            else if (T == 26)
            {
                stack -= 1;
                if (stack == 0) state = 0;
            }
            else if (T == 17)
            {
                i = site;
                ERROR = 101;
            }
        }
    }
    if (state != 0) ERROR = 103;
    //printf("adfereqwr, ERROR: %d\n", ERROR);
    for (i = 0; i < KeyAmount; i++)
        if (Type[i] == Mix)
        {
            Type[i] = MixString;
            head = FirstElem[i];
            do
            {
                Typetemp = SwitchType(content[site].lexical);
                if (Typetemp != Id && Typetemp != String) Type[i] = Mix;
                head = Next[head];
            } while (head != site);
        }
    return ERROR;
}
void ParaFile::append(size_t No)
{
    size_t NewSize;
    Target = KeyAmount;
    KeyAmount += 1;
    if (ContainerSize <= KeyAmount)
    {
        NewSize = ContainerSize + ContainerSize / 4 + 4;
        key = (size_t*)realloc(key, sizeof(size_t) * NewSize);
        FirstElem = (size_t*)realloc(FirstElem, sizeof(size_t) * NewSize);
        ElemAmount = (size_t*)realloc(ElemAmount, sizeof(size_t) * NewSize);
        Type = (ParaType*)realloc(Type, sizeof(ParaType) * NewSize);
        ContainerSize = NewSize;
    }
    key[Target] = No;
    ElemAmount[Target] = 0;
    FirstElem[Target] = site;
}
bool ParaFile::IfContent(int T)
{
    return T == 5 || T == 3 || T == 4 || T == 11 || T == 0 || T == 57;
}
ParaFile::ParaType ParaFile::SwitchType(int T)
{
    if (T == 5) return Id;
    else if (T == 3 || T == 4) return Real;
    else if (T == 0) return Int;
    else if (T == 57) return Char;
    else if (T == 11) return String;
    else return Mix;
}

void ParaFile::demo(FILE* fp)
{
    size_t i;
    for (i = 0; i < KeyAmount; i++)
    {
        fprintf(fp, "Key[%llu] = %s, FirstElem: %llu, Amount: %llu\n", i, content[key[i]].origin, FirstElem[i], ElemAmount[i]);
    }
    for (i = 0; i < site; i++)
        fprintf(fp, "Next[%llu] = %llu\n", i, Next[i]);
}
size_t ParaFile::Amount(void)
{
    return KeyAmount;
}
size_t ParaFile::Amount(size_t i)
{
    return i < KeyAmount ? ElemAmount[i] : 0;
}
#include <string.h>
size_t ParaFile::SearchKey(const char* Key)
{
    const char* targat;
    size_t i;
    for (i = 0; i < KeyAmount; i++)
    {
        targat = content[key[i]].origin;
        if (strcmp(Key, targat) == 0)
            return i;
    }
    return KeyAmount;
}
size_t ParaFile::SearchKey(const char* Key, ParaFile::ParaType T)
{
    const char* targat;
    size_t i;
    for (i = 0; i < KeyAmount; i++)
    {
        targat = content[key[i]].origin;
        if (T == Type[i])
            if (strcmp(Key, targat) == 0)
                return i;
    }
    return KeyAmount;
}
ParaFile::ParaType ParaFile::GetType(size_t i)
{
    return Type[i];
}
IntegerDefault ParaFile::FirstInt(size_t i)
{
    if (i < KeyAmount)
        if (Int == Type[i]) return content[FirstElem[i]].C.integer;
    return 0;
}
double ParaFile::FirstReal(size_t i)
{
    if (i < KeyAmount)
        if (Real == Type[i]) return content[FirstElem[i]].C.real;
    return 0;
}
std::string ParaFile::FirstString(size_t i)
{
    std::string SSS;
    if (i < KeyAmount)
        if (String == Type[i]) SSS = content[FirstElem[i]].C.S;
    return SSS;
}
std::string ParaFile::GetString(const char* Key, const char* Default)
{
    std::string temp;
    size_t site;
    ParaType T;
    site = SearchKey(Key);
    if (site == Amount())
    {
        temp = Default;
    }
    else
    {
        T = Type[site];
        if (T != String && T != Id && T != MixString)
            temp = Default;
        else
            temp = content[FirstElem[site]].C.S;
    }
    return temp;
}

void ParaFile::IntList(IntegerDefault*& list, size_t& length, size_t i)
{
    size_t head, j;
    if (i >= KeyAmount) return;
    if (Int != Type[i]) return;
    length = ElemAmount[i];
    list = (IntegerDefault*)malloc(sizeof(IntegerDefault) * length);
    j = 0;
    head = FirstElem[i];
    while (head != site)
    {
        list[j] = content[head].C.integer;
        j += 1;
        head = Next[head];
    }
}
void ParaFile::CharList(char**& list, size_t& length, size_t i)
{
    size_t head, j;
    if (i >= KeyAmount) return;
    if (String != Type[i] && Id != Type[i] && MixString != Type[i]) return;
    length = ElemAmount[i];
    list = (char**)malloc(sizeof(char*) * length);
    j = 0;
    head = FirstElem[i];
    while (head != site)
    {
        list[j] = CopyMalloc(content[head].C.S);
        j += 1;
        head = Next[head];
    }
}
static char* CopyMalloc(const char* s)
{
    char* v;
    size_t size;
    size = strlen(s);
    v = (char*)malloc(sizeof(char) * (size + 4));
    strcpy(v, s);
    return v;
}
#include<errno.h>
#include <string.h>
FILE* CFile::Open(const char* name, const char* mode)
{
    FILE* fp;
    int error;
    errno = 0;
#ifdef  _WIN64
    error = fopen_s(&fp, name, mode);
    if (error != 0)
    {
        fprintf(stderr, "WARNING: FAILURE OPEN:%s, errno_t:%d\n", name, error);
        fp = NULL;
    }
#else
    fp = fopen(name, mode);
    if (fp == NULL)
        fprintf(stderr, "WARNING: FAILURE OPEN:%s, Error no.%d: %s\n", name, errno, strerror(errno));
#endif
    ExitWarning((fp == NULL), stderr);
    return fp;
}
FILE* CFile::OpenRead(const char* name)
{
    return Open(name, "r");
}
FILE* CFile::OpenWriteAtRear(const char* name)
{
    return Open(name, "a+");
}
FILE* CFile::OpenWritePlus(const char* name)
{
    return Open(name, "w+");
}
std::string CFile::FusePathAndName(const std::string& path, const std::string& name)
{
    std::string fusion;
    if (path[path.length() - 1] == '/')
        fusion = path + name;
    else
        fusion = path + '/' + name;
    return fusion;
}
std::string CFile::FusePathAndName(const char* path, const std::string& name)
{
    std::string PPP;
    PPP = path;
    return FusePathAndName(PPP, name);
}
std::string CFile::ChangeSuffix(const std::string& file, const char* new_one)
{
    size_t i, j;
    std::string name;
    name = "";
    for (i = file.length(); i != 0; i--)
        if (file[i - 1] == '.') break;
    if (i == 0)
    {
        name = file;
        name += '.';
    }
    else
    {
        for (j = 0; j < i; j++)
            name += file[j];
    }
    if (new_one[0] == '.') name += (new_one + 1);
    else name += new_one;
    return name;
}

static bool isIdBegin(char c)
{
    return (c >= 'a' && c <= 'z') || c == '_' || (c >= 'A' && c <= 'Z');
}
static bool isIdNumber(char c)
{
    return c >= '0' && c <= '9';
}


MatFile::MatFile()
{
}
MatFile::~MatFile()
{
}


int MatFile::MatrixGet(double** list, size_t* row, size_t* column, CharBuffer& in)
{
    double* List;
    size_t L, site;
    DFA00 dfa;
    CharBuffer backspace;
    CharBuffer result;
    CharBuffer intermediate;
    char c;
    int state = 0, type;
    enum DFA00::action Ac;
    int mstate, judge;
    size_t Record, Now;
    c = in.Dequeue(backspace);
    L = 8;
    site = 0;
    List = (double*)malloc(sizeof(double) * L);
    Record = 0;
    Now = 0;
    mstate = 0;
    judge = 1;
    for (; c != ((char)(EOF)); )
    {
        dfa.DFA_swicth(c);
        Ac = dfa.should();
        //cout << c;
        switch (Ac)
        {
        case DFA00::add:
            result << intermediate;
            result << c;
            c = in.Dequeue(backspace);
            break;
        case DFA00::wait:
            c = in.Dequeue(backspace);
            break;
        case DFA00::record:
            intermediate << c;
            c = in.Dequeue(backspace);
            break;
        case DFA00::retrieve:
            if (result != 0)
            {
                type = dfa.result();
                if (type == 3 || type == 4)
                {
                    if (site >= L)
                    {
                        L = (L + L / 4 + 8);
                        List = (double*)realloc(List, sizeof(double) * L);
                    }
                    List[site] = result.DequeueReal();
                    site++;
                    if (mstate == 0) Record++;
                    else Now++;
                }
                else if (type == 63)
                {
                    if (mstate == 0 && Record != 0) mstate = 1;
                    else if (Now != 0)
                    {
                        judge = judge && Now == Record;
                        Now = 0;
                    }
                }
                result.Clear();
                backspace << intermediate;
                break;
            }
        case DFA00::halt:
            std::cout << " HALT ";
            break;
        default:
            c = in.Dequeue();
            break;
        }
    }
    *list = (double*)realloc(List, sizeof(double) * site);
    judge = judge && (site % Record == 0);
    if (judge)
    {
        *row = site / Record;
        *column = Record;
    }
    else
    {
        *row = site;
        *column = 1;
    }
    return judge;
}
int MatFile::MatrixGet(double** list, size_t* row, size_t* column, const char* file)
{
    int error;
    FILE* fp;
    CFile CF;

    fp = CF.OpenRead(file);
    error = MatrixGet(list, row, column, fp);
    fclose(fp);

    return error;
}
int MatFile::MatrixGet(double** list, size_t* row, size_t* column, FILE* fp)
{
    CharBuffer in;
    in << fp;
    return MatrixGet(list, row, column, in);
}
void MatFile::MatrixSet(const double* mat, size_t ld, size_t row, size_t column, const char* file)
{
    FILE* fp;
    CFile CF;
    fp = CF.OpenWriteAtRear(file);
    MatrixSet(mat, ld, row, column, fp);
    fclose(fp);
    return;
}
void MatFile::MatrixSet(const double* mat, size_t ld, size_t row, size_t column, FILE* fp)
{
    size_t i, j;
    const double* Line;
    for (i = 0; i < row; i++)
    {
        Line = mat + i * ld;
        for (j = 0; j < column; j++)
            fprintf(fp, "%+25.16E ", Line[j]);
        fprintf(fp, "\n");
    }
    return;
}





