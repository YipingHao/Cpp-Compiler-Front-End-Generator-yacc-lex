#include<cstring>
#include<time.h>
using namespace std;
#include "AutoHeader.h"
#include<stdlib.h>
int test_entrance(const char* output_path);
int main(int argc, char* argv[])
{
	int info;
	//hyperlex_old::ParaFile pf;
	int amount_of_cores;
	const char* output_path;
	output_path = argv[1];
	//amount_of_cores = cores_amount_from_input(argv[2]);
	info = 0;
	info = test_entrance(output_path);
	return info;
}

namespace hyperlex_old
{
	typedef long long int IntegerDefault;
	class DFA00;
    bool static true_false_judge(const char* c_t_f);

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
		size_t Amount(void)const;
		size_t Amount(size_t i)const;
		size_t SearchKey(const char* Key)const;
		size_t SearchKey(const char* Key, ParaType T)const;
		ParaType GetType(size_t i);
		IntegerDefault FirstInt(size_t i);
		double FirstReal(size_t i);
		std::string FirstString(size_t i);
		std::string GetString(const char* Key, const char* Default);
        bool GetBool(const char* Key) const;
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
        //bool option1;
		void append(size_t No);
		bool IfContent(int T);
		ParaType SwitchType(int T);
	};
    inline int if_letter_judge(char c)
    {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
    bool static true_false_judge(const char* c_t_f)
    {
        int i;
        for (i = 0; c_t_f[i] != '\0'; i++)
            if (if_letter_judge(c_t_f[i]))
                return c_t_f[i] == 'y' || c_t_f[i] == 'Y' || c_t_f[i] == 't' || c_t_f[i] == 'T';
        return false;
    }


}
hyperlex_old::IntegerDefault hyperlex_old::IntGet(const char* list, size_t end, size_t& head)
{
    char c, state;
    IntegerDefault number;
    IntegerDefault Sign = 1;
    number = 0;
    state = 0;
    do
    {
        c = hyperlex::dequeue(list, end, head);
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
double hyperlex_old::RealGet(int& state, const char* list, size_t end, size_t& head)
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
        c = hyperlex::dequeue(list, end, head);
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
char hyperlex_old::CharGet(const char* list, size_t end, size_t& head)
{
    char c, result;
    int error;
    result = EOF;
    c = hyperlex::dequeue(list, end, head);
    error = 10;
    if (c == '\'') result = hyperlex::CharGet(error, list, end, head);
    else return EOF;
    c = hyperlex::dequeue(list, end, head);
    if (c == '\'') return result;
    else return EOF;
}




hyperlex_old::IntegerDefault hyperlex_old::CharBuffer::DequeueInt(void)
{
    return IntGet(content, site, head);
}
using namespace hyperlex;

static int test_01(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_02(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_03(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_04(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_05(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_06(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_07(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_08(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_09(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_10(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_11(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_12(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_13(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_14(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_15(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_16(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_17(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_18(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_19(const char* output_path, hyperlex_old::ParaFile& pf);
static int test_20(const char* output_path, hyperlex_old::ParaFile& pf);
int test_entrance(const char* output_path)
{
    int item;
    int info;
    hyperlex_old::ParaFile pf;
    size_t sitePF;
    pf.initial("./parameter/test_item.txt");
    pf.demo(stdout);
    sitePF = pf.SearchKey("item", hyperlex_old::ParaFile::Int);
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
    case 20:
        std::cout << "Test Tree; " << std::endl;
        info = test_20(output_path, pf);
        break;
    default:
        info = test_01(output_path, pf);
        break;
    }
    return info;
}
static int test_01(const char* output_path, hyperlex_old::ParaFile& pf)
{
    printf("test_01\n");
}
static int test_02(const char* output_path, hyperlex_old::ParaFile& pf)
{
    hyperlex_old::ParaFile PF;
    FILE* fp;
    hyperlex_old::CFile F;
    std::string file;
    hyperlex_old::CharBuffer Buffer;
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
    i = PF.SearchKey("MoleculeOfAtom", hyperlex_old::ParaFile::Int);
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
    hyperlex_old::Ruin(L, length);
    return 0;
}
static int test_03(const char* output_path, hyperlex_old::ParaFile& pf)
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
static int test_04(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /*Bitree<int> tree;
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
    output.clear();
    std::cout << "tree.inorderTraversal(output); " << std::endl;
    tree.inorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    output.clear();
    tree.SetHead(1);
    std::cout << "tree.SetHead(1); " << std::endl;
    std::cout << "tree.postorderTraversal(output); " << std::endl;
    tree.postorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    output.clear();
    std::cout << "tree.inorderTraversal(output); " << std::endl;
    tree.inorderTraversal(output);
    for (i = 0; i < output.count(); i++)
    {
        std::cout << "No.[" << i << "].content = " << tree[output[i]].content << ";" << std::endl;
    }
    tree.SetHead(1);*/
    return 0;
}
static int test_05(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /*RegTree RT, Id, res;
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
    std::cout << std::endl;*/
    return 0;
}
static int test_06(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /*RegTree RT, Id, res;
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
    delete ddfa;*/
    return 0;
}
static int test_07(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /*RegTree RT, Id, res;
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
    //nfa[0]->build(&res);
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
    delete ddfa;*/
    return 0;
}
static int test_08(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /* lexicalPanel lP;
    NFA* nfa;
    sheetDFA* dfa;
    DFA* ddfa;
    lP.SetGrammer();
    lP.Demo(stdout);
   // nfa = new NFA(lP);
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
    delete ddfa; */
    return 0;
}
static int test_09(const char* output_path, hyperlex_old::ParaFile& pf)
{
    size_t i;
    for (i = 10; i < 20; i++)
    {
        std::cout << "static int test_" << i << "(const char* output_path, hyperlex_old::ParaFile& pf);" << std::endl;
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
        std::cout << "static int test_" << i << "(const char* output_path, hyperlex_old::ParaFile& pf)" << std::endl;
        std::cout << "{" << std::endl;
        std::cout << "\treturn 0;" << std::endl;
        std::cout << "}" << std::endl;
    }
}
static int test_10(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    hyperlex_old::CFile CF;
    grammerS G;
    //fp = CF.OpenRead("./data/grammerT.txt");
    fp = CF.OpenRead("./data/if.txt");
    G.build(fp);
    fclose(fp);
    G.Demo(stdout);
    return 0;
}
static int test_11(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    hyperlex_old::CFile CF;
    grammerS G;
    fp = CF.OpenRead("./data/grammerT.txt");
    //fp = CF.OpenRead("./data/if.txt");
    G.build(fp);
    fclose(fp);
    G.Demo(stdout);
    return 0;
}
static int test_12(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    hyperlex_old::CFile CF;
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
static int test_13(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp, *Out;
    hyperlex_old::CFile CF;
    grammerS G;
    LR0* lr;
    LR1* lr1;
    std::string file, output, OutputLabel;
    int infor;
    BufferChar temp;
    Gsheet Gsheet0, Gsheet1;
    lr1 = NULL;


    //file = pf.first_string("InputFileName", "./data/grammerT.txt");
    file = pf.GetString("InputFileName", "./data/grammerT.txt");
    output = pf.GetString("OutputFileName", "./output/G.txt");
    OutputLabel = pf.GetString("OutputLabel", "casual");
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    input << fp;
    temp.append(input);
    std::cout << "/*" << std::endl;
    std::cout << temp.ptr() << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    Out = CF.OpenWritePlus(output.c_str());
    std::cout << "OutputFileName: " << output << std::endl;
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
    if (pf.GetBool("lr0demo"))lr->Demo(stdout, &G);

    Gsheet0.build(lr, &G);
    if(pf.GetBool("lr0Gdemo"))Gsheet0.Demo(stdout);
    if (pf.GetBool("lr0Cdemo"))Gsheet0.Cprint(OutputLabel.c_str(), stdout);

    if (pf.GetBool("lr0Cppdemo"))Gsheet0.CppPrint(OutputLabel.c_str(), stdout);
    if (pf.GetBool("PrintToFile")) Gsheet0.CppStructPrint(OutputLabel.c_str(), Out, &G);
    else Gsheet0.CppStructPrint(OutputLabel.c_str(), stdout, &G);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "++++++++++++lr1 = new LR1(&G);+++++++++++++++" << std::endl;
    lr1 = new LR1(&G);
    if (pf.GetBool("lr1demo"))lr1->Demo(stdout, &G);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    Gsheet1.build(lr1, &G);
    if (pf.GetBool("lr1Gdemo")) Gsheet1.Demo(stdout);
    if (pf.GetBool("lr1Cdemo")) Gsheet1.Cprint(OutputLabel.c_str(), stdout);

    if (pf.GetBool("lr1Cppdemo")) Gsheet1.CppPrint(OutputLabel.c_str(), stdout);
    if (pf.GetBool("PrintToFile")) Gsheet1.CppStructPrint(OutputLabel.c_str(), Out, &G);
    else Gsheet1.CppStructPrint(OutputLabel.c_str(), stdout, &G);
    G.Cprint(stdout);
    fclose(Out);
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
static int test_14(const char* output_path, hyperlex_old::ParaFile& pf)
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
static int test_15(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    hyperlex_old::CFile CF;
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
    std::cout << temp.ptr() << std::endl;

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
static int test_16(const char* output_path, hyperlex_old::ParaFile& pf)
{
    BufferChar input;
    FILE* fp;
    hyperlex_old::CFile CF;
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
    std::cout << temp.ptr() << std::endl;

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


static int test_17(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /*lexicalPanel lP;
    NFA* nfa;
    sheetDFA* dfa;
    DFA* ddfa;
    std::string file, output, OutputLabel;
    output = pf.GetString("OutputFileName", "./output/G.txt");
    OutputLabel = pf.GetString("OutputLabel", "casual");
    //pf.SearchKey("option1");
    if (pf.GetBool("regs")) lP.SetRegS();
    else lP.SetRegFinal();
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
        if (pf.GetBool("lr0Cdemo"))lP.Cprint(stdout, OutputLabel.c_str());
        if (pf.GetBool("Cppdemo"))lP.CppPrint(stdout, OutputLabel.c_str());
        lP.Demo(stdout);
       
    }
    //lP.Demo(stdout);*/
    return 0;
}
static int test_18(const char* output_path, hyperlex_old::ParaFile& pf)
{
    /* RegTree RT;
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
    lP.Demo(stdout);*/
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
static int test_19(const char* output_path, hyperlex_old::ParaFile& pf)
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
    /*
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
    //RTTE.build("\'/\'\'*\'((\'*\'([\'\\0\'-\'.\']|[\'0\'-\'\\177\']))|([\'\\0\'-\')\']|[\'+\'-\'\\177\']))*\'*\'+\'/\'");

    RTTE.build("\'/\'\'*\'([\'\\0\'-\'\\177\'])*\'*\'+\'/\'");
    RTTE.Demo(stdout);
    std::cout << std::endl;*/

    return 0;
}



static int test_20(const char* output_path, hyperlex_old::ParaFile& pf)
{
    RegularExp ee;
    InputPanel IP;
    std::string file;
    FILE* fp;
    BufferChar input;
    BufferChar temp;
    hyperlex_old::CFile CF;
    int error;
    //int 哈哈哈;
    //哈哈哈;
    if (false)
    {
        ee.set(44, 55);
        ee.Demo(stdout);
        printf("\n");
        ee.set("([a-z]|[A-Z]|_)([a-z]|[A-Z]|_|[0-9])*");
        ee.Demo(stdout);
        printf("\n");
        ee.set("('+'|'-')?[0-9]+");
        ee.Demo(stdout);
        printf("\n");
        ee.set("(0x|0X)([0-9]|[a-f]|[A-F])+");
        ee.Demo(stdout);
        printf("\n");

        ee.set("('+'|'-')?[0-9]+'.'[0-9]*((e|E)('+'|'-')?[0-9]+)?");
        ee.Demo(stdout);
        printf("\n");
        ee.set("PikaPikachu");
        ee.Demo(stdout);
        printf("\n");
    }
    

    file = pf.GetString("InputFileName", "./data/grammerT.txt");
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    input << fp;
    temp.append(input);
    std::cout << "/*" << std::endl;
    std::cout << temp.ptr() << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fclose(fp);
    error = IP.build(input.ptr());
    std::cout << "error: " << error << std::endl;
    IP.demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    error = IP.printL(stdout, "regular");
    std::cout << "error: " << error << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    error = IP.printG(stdout, stdout, "panel");
    std::cout << "error: " << error << std::endl;
}


class dictionary
{
public:
    enum Ktype
    {
        null_ = 0,
        int_ = 1,
        float_ = 2,
        string_ = 3,
        bool_ = 4,
        dictionary_ = 5,
    };
    union element
    {
        long long int ii;
        double ff;
        char* ss;
        bool bb;
        dictionary* dd;
    };
    struct KV
    {
        char* key;
        Ktype T;
        element * Content;
        size_t Capacity;
        size_t Count;
    public:
        KV();
        ~KV();
        void ruin(void);
        void clear(void);
        void initial(void);
        void recapacity(size_t NewSize);
        void append(const element& e);
        void setType(Ktype newType);
        void setName(const char* newKey);

        size_t capacity() const;
        size_t count() const;
        element& operator[](size_t i);
        const element& operator[](size_t i) const;
    };



    dictionary();
    ~dictionary();
    void print(FILE* fp) const;
    int build(FILE* fp);
    int build(const char* input);
    void move(dictionary* source);
    void clear(void);
private:
    vector<KV> Content;
    void print(FILE* fp, size_t indent) const;  // 递归打印核心
    void PrintTab(FILE* fp, size_t count) const; // 缩进工具函数

    // 类型专用打印函数
    //void PrintValue(FILE* fp, const element& e, Ktype T, size_t indent) const;
    void PrintArray(FILE* fp, const KV& kv, size_t indent) const;

    void NeglectNullToken(Morpheme& eme) const;
};

dictionary::dictionary()
{

}
dictionary::~dictionary()
{
    clear();
}
void dictionary::clear(void)
{
    size_t i;
    for (i = 0; i < Content.count(); i++)
    {
        Content[i].ruin();
    }
    Content.clear();
}
dictionary::KV::KV()
{
    initial();
}
dictionary::KV::~KV()
{
    ruin();
    free(key);
}
void dictionary::KV::ruin(void)
{
    clear();
    free(Content);
    Content = NULL;
    free(key);
}
void dictionary::KV::clear(void)
{
    size_t i;
    for (i = 0; i < Count; ++i) 
    {
        switch (T) 
        {
            case string_: free(Content[i].ss); break;
            case dictionary_: delete Content[i].dd; break;
            default: break;
        }
    }
    Count = 0;
}
void dictionary::KV::initial(void)
{
    key = NULL;
    T = null_;
    Content = NULL;
    Capacity = 0;
    Count = 0;
}
void dictionary::KV::recapacity(size_t NewSize) 
{
    size_t i;
    element* newContent = (element*)malloc(sizeof(element) * NewSize);
    if (NewSize <= Count)
    {
        for (i = NewSize; i < Count; ++i)
        {
            switch (T) {
            case string_:
                free(Content[i].ss);
                break;
            case dictionary_:
                delete Content[i].dd;
                break;
            }
        }
        Count = NewSize;
    }
    else
    {
        for (i = 0; i < Count; ++i) {
            newContent[i] = Content[i];
        }
    }
    free(Content);
    Content = newContent;
    Capacity = NewSize;
}
void dictionary::KV::append(const element& e) 
{
    if (Count >= Capacity) recapacity(Capacity ? (Capacity + Capacity / 4 + 4) : 1);
    Content[Count] = e;
    Count++;
}
void dictionary::KV::setType(Ktype newType)
{
    if (T != newType) {  
        clear();
        T = newType;
    }
}
void dictionary::KV::setName(const char* newKey)
{
    size_t i;
    free( key); 
    key = NULL;
    if (!newKey) return;

    size_t len = 0;
    while (newKey[len] != '\0') ++len;

    key = (char*)(malloc((len + 1) * sizeof(char)));
    for (i = 0; i <= len; ++i) 
    { 
        key[i] = newKey[i];
    }
}

size_t dictionary::KV::capacity() const { return Capacity; }
size_t dictionary::KV::count() const { return Count; }
dictionary::element& dictionary::KV::operator[](size_t i) { return Content[i]; }
const dictionary::element& dictionary::KV::operator[](size_t i) const { return Content[i]; }


void dictionary::print(FILE* fp) const 
{
    print(fp, 0);
    fprintf(fp, "\n");
}
void dictionary::PrintTab(FILE* fp, size_t count) const
{
    for (size_t i = 0; i < count; ++i) {
        fprintf(fp, "    ");
    }
}
void dictionary::print(FILE* fp, size_t indent) const 
{
    PrintTab(fp, indent);
    fprintf(fp, "{\n");

    for (size_t i = 0; i < Content.count(); ++i) 
    {
        const KV& kv = Content[i];
        PrintTab(fp, indent + 1);
        fprintf(fp, "\"%s\": ", kv.key ? kv.key : "(null)");

        // 根据类型打印内容
        if (kv.T == dictionary_ && kv.Count > 0) {
            PrintArray(fp, kv, indent + 1); // 处理字典数组的特殊缩进
        }
        else {
            PrintArray(fp, kv, 0);          // 基础类型紧凑打印
        }

        if (i != Content.count() - 1) fprintf(fp, ",");
        fprintf(fp, "\n");
    }

    PrintTab(fp, indent);
    fprintf(fp, "}");
}
void dictionary::PrintArray(FILE* fp, const KV& kv, size_t indent) const 
{
    const bool isComplexType = (kv.T == dictionary_ || kv.T == string_);

    if (kv.Count == 0) {
        fprintf(fp, "[]");
        return;
    }

    fprintf(fp, "[%s", isComplexType ? "\n" : "");

    for (size_t j = 0; j < kv.Count; ++j) {
        if (isComplexType) PrintTab(fp, indent);

        // 打印单个元素
        switch (kv.T) {
        case int_:
            fprintf(fp, "%lld", kv.Content[j].ii);
            break;
        case float_:
            fprintf(fp, "%g", kv.Content[j].ff);
            break;
        case string_:
            fprintf(fp, "\"%s\"", kv.Content[j].ss ? kv.Content[j].ss : "");
            break;
        case bool_:
            fprintf(fp, "%s", kv.Content[j].bb ? "true" : "false");
            break;
        case dictionary_:
            if (kv.Content[j].dd) {
                kv.Content[j].dd->print(fp, indent);
            }
            else {
                fprintf(fp, "{}");
            }
            break;
        default:
            fprintf(fp, "null");
        }

        // 元素分隔符
        if (j != kv.Count - 1) {
            fprintf(fp, ",%s", isComplexType ? "\n" : " ");
        }
    }

    if (isComplexType) {
        fprintf(fp, "\n");
        PrintTab(fp, indent - 1);
    }
    fprintf(fp, "]");
}

struct DictReg
{
    enum regular
    {
        _id_ = 1,
        _integer_ = 2,
        _real_ = 3,
        _string_ = 4,
        _false_ = 5,
        _true_ = 6,
        _null_ = 7,
        _NULL_ = 8,
        _semicolon_ = 9,
        _colon_ = 10,
        _dot_ = 11,
        _comma_ = 12,
        _value_ = 13,
        _braceL_ = 14,
        _braceR_ = 15,
        _left_ = 16,
        _right_ = 17,
        _squareL_ = 18,
        _squareR_ = 19,
        _anntationS_ = 20,
        _anntationM_ = 21,
        _spaces_ = 22,
        _enters_ = 23,
        _tab_ = 24
    };
    enum group
    {
        _id___ = 1,
        _number___ = 2,
        _string___ = 3,
        _reserved___ = 4,
        _division___ = 5,
        _value___ = 6,
        _braket___ = 7,
        _anntation___ = 8,
        _format___ = 9
    };
    static int next(int state, const char c);
    static int action(int state);
    static int GroupGet(int state);
};
struct DictPraser
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
        _DICTIONARY_ = 1,
        _KVS_ = 2,
        _KV_ = 3,
        _VALUE_ = 4,
        _UNITS_ = 5,
        _UNIT_ = 6
    };
    enum rules
    {
        _all_all_ = 0,
        _DICTIONARY_DICTIONARY_ = 1,
        _KVS_multi_ = 2,
        _KVS_single_ = 3,
        _KV_colon_ = 4,
        _KV_value_ = 5,
        _VALUE_multi_ = 6,
        _VALUE_single_ = 7,
        _VALUE_nul_ = 8,
        _UNITS_multi_ = 9,
        _UNITS_single_ = 10,
        _UNIT_NULL_ = 11,
        _UNIT_null_ = 12,
        _UNIT_true_ = 13,
        _UNIT_false_ = 14,
        _UNIT_dictionary_ = 15
    };
    static const size_t StateCount;
    static const size_t NonTerminalCount;
    static const size_t TerminalCount;
    static const size_t RulesCount;
    static const int GOTO[27][7];
    static const int ACTION[27][25];
    static const int RulesToSymbol[16];
    static const int RulesLength[16];
    static const char* const RulesName[16];
};



int dictionary::build(FILE* fp)
{
    Morpheme eme;
    int error;
    clear();
    error = eme.Build<DictReg>(fp);
    if (error != 0)
    {
        //errorCode = ErrorinputLEXICAL;
        return error;
    }
    NeglectNullToken(eme);
    //eme.Demo(stdout);
    //error = buildGanalysis(eme);
    if (error != 0) return error;
    //errorCode = NoError;
    return 0;
}
int dictionary::build(const char* input)
{
    Morpheme eme;
    int error;
    clear();
    //initial();
    error = eme.Build<DictReg>(input);
    if (error != 0)
    {
        //errorCode = ErrorinputLEXICAL;
        return error;
    }
    NeglectNullToken(eme);
    //eme.Demo(stdout);
    //error = buildGanalysis(eme);
    if (error != 0) return error;
    //errorCode = NoError;
    return 0;
}
void dictionary::move(dictionary* source)
{
    size_t i;
    clear();
    Content.recount(source->Content.count());
    for (i = 0; i < source->Content.count(); i++)
    {
        Content.append(source->Content[i]);
    }
    source->clear();
}


void dictionary::NeglectNullToken(Morpheme& eme) const
{
    size_t i;
    DictReg::regular T;
    DictReg::group G;
    for (i = 0; i < eme.GetCount(); i++)
    {
        T = (DictReg::regular)(eme[i].accept);
        G = (DictReg::group)(eme[i].category);
        if (G == DictReg::_format___ || G == DictReg::_anntation___)
        {
            eme.valid(i) = false;
        }
    }
    return;
}


int DictReg::next(int state, const char c)
{
    switch (state)
    {
    case 0:
        if (c == (char)9) return 24;
        else if (c == (char)10) return 23;
        else if (c == ' ') return 22;
        else if (c == '\"') return 25;
        else if (c == '(') return 16;
        else if (c == ')') return 17;
        else if (c == '+') return 39;
        else if (c == ',') return 12;
        else if (c == '-') return 39;
        else if (c == '.') return 11;
        else if (c == '/') return 45;
        else if ('0' <= c && c <= '9') return 2;
        else if (c == ':') return 10;
        else if (c == ';') return 9;
        else if (c == '=') return 13;
        else if ('A' <= c && c <= 'M') return 1;
        else if (c == 'N') return 28;
        else if ('O' <= c && c <= 'Z') return 1;
        else if (c == '[') return 18;
        else if (c == ']') return 19;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'e') return 1;
        else if (c == 'f') return 34;
        else if ('g' <= c && c <= 'm') return 1;
        else if (c == 'n') return 35;
        else if ('o' <= c && c <= 's') return 1;
        else if (c == 't') return 36;
        else if ('u' <= c && c <= 'z') return 1;
        else if (c == '{') return 14;
        else if (c == '}') return 15;
        else return 0;
    case 1:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 2:
        if (c == '.') return 47;
        else if ('0' <= c && c <= '9') return 2;
        else return 0;
    case 3:
        if ('0' <= c && c <= '9') return 3;
        else if (c == 'E') return 46;
        else if (c == 'e') return 46;
        else return 0;
    case 4:
        return 0;
    case 5:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 6:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 7:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 8:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 9:
        return 0;
    case 10:
        return 0;
    case 11:
        return 0;
    case 12:
        return 0;
    case 13:
        return 0;
    case 14:
        return 0;
    case 15:
        return 0;
    case 16:
        return 0;
    case 17:
        return 0;
    case 18:
        return 0;
    case 19:
        return 0;
    case 20:
        return 0;
    case 21:
        if ((char)0 <= c && c <= ')') return 38;
        else if (c == '*') return 44;
        else if ('+' <= c && c <= (char)127) return 38;
        else return 0;
    case 22:
        if (c == ' ') return 22;
        else return 0;
    case 23:
        if (c == (char)10) return 23;
        else return 0;
    case 24:
        return 0;
    case 25:
        if (' ' <= c && c <= '!') return 40;
        else if ('#' <= c && c <= '~') return 40;
        else return 0;
    case 26:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'K') return 1;
        else if (c == 'L') return 8;
        else if ('M' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 27:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'K') return 1;
        else if (c == 'L') return 26;
        else if ('M' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 28:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'T') return 1;
        else if (c == 'U') return 27;
        else if ('V' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'z') return 1;
        else return 0;
    case 29:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'd') return 1;
        else if (c == 'e') return 6;
        else if ('f' <= c && c <= 'z') return 1;
        else return 0;
    case 30:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'k') return 1;
        else if (c == 'l') return 7;
        else if ('m' <= c && c <= 'z') return 1;
        else return 0;
    case 31:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'k') return 1;
        else if (c == 'l') return 30;
        else if ('m' <= c && c <= 'z') return 1;
        else return 0;
    case 32:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'r') return 1;
        else if (c == 's') return 41;
        else if ('t' <= c && c <= 'z') return 1;
        else return 0;
    case 33:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'k') return 1;
        else if (c == 'l') return 32;
        else if ('m' <= c && c <= 'z') return 1;
        else return 0;
    case 34:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if (c == 'a') return 33;
        else if ('b' <= c && c <= 'z') return 1;
        else return 0;
    case 35:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 't') return 1;
        else if (c == 'u') return 31;
        else if ('v' <= c && c <= 'z') return 1;
        else return 0;
    case 36:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'q') return 1;
        else if (c == 'r') return 42;
        else if ('s' <= c && c <= 'z') return 1;
        else return 0;
    case 37:
        if ('0' <= c && c <= '9') return 37;
        else return 0;
    case 38:
        if ((char)0 <= c && c <= ')') return 38;
        else if (c == '*') return 44;
        else if ('+' <= c && c <= (char)127) return 38;
        else return 0;
    case 39:
        if ('0' <= c && c <= '9') return 2;
        else return 0;
    case 40:
        if (' ' <= c && c <= '!') return 40;
        else if (c == '\"') return 4;
        else if ('#' <= c && c <= '~') return 40;
        else return 0;
    case 41:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 'd') return 1;
        else if (c == 'e') return 5;
        else if ('f' <= c && c <= 'z') return 1;
        else return 0;
    case 42:
        if ('0' <= c && c <= '9') return 1;
        else if ('A' <= c && c <= 'Z') return 1;
        else if (c == '_') return 1;
        else if ('a' <= c && c <= 't') return 1;
        else if (c == 'u') return 29;
        else if ('v' <= c && c <= 'z') return 1;
        else return 0;
    case 43:
        if ((char)0 <= c && c <= (char)9) return 43;
        else if (c == (char)10) return 20;
        else if ((char)11 <= c && c <= (char)127) return 43;
        else return 0;
    case 44:
        if ((char)0 <= c && c <= ')') return 38;
        else if (c == '*') return 44;
        else if ('+' <= c && c <= '.') return 38;
        else if (c == '/') return 21;
        else if ('0' <= c && c <= (char)127) return 38;
        else return 0;
    case 45:
        if (c == '*') return 38;
        else if (c == '/') return 43;
        else return 0;
    case 46:
        if (c == '+') return 48;
        else if (c == '-') return 48;
        else if ('0' <= c && c <= '9') return 37;
        else return 0;
    case 47:
        if ('0' <= c && c <= '9') return 3;
        else return 0;
    case 48:
        if ('0' <= c && c <= '9') return 37;
        else return 0;
    }
    return 0;
}
int DictReg::action(int state)
{
    switch (state)
    {
    case 1:
        return 1;//id: id
    case 2:
        return 2;//number: integer
    case 3:
        return 3;//number: real
    case 4:
        return 4;//string: string
    case 5:
        return 5;//reserved: false
    case 6:
        return 6;//reserved: true
    case 7:
        return 7;//reserved: null
    case 8:
        return 8;//reserved: NULL
    case 9:
        return 9;//division: semicolon
    case 10:
        return 10;//division: colon
    case 11:
        return 11;//division: dot
    case 12:
        return 12;//division: comma
    case 13:
        return 13;//value: value
    case 14:
        return 14;//braket: braceL
    case 15:
        return 15;//braket: braceR
    case 16:
        return 16;//braket: left
    case 17:
        return 17;//braket: right
    case 18:
        return 18;//braket: squareL
    case 19:
        return 19;//braket: squareR
    case 20:
        return 20;//anntation: anntationS
    case 21:
        return 21;//anntation: anntationM
    case 22:
        return 22;//format: spaces
    case 23:
        return 23;//format: enters
    case 24:
        return 24;//format: tab
    case 26:
        return 1;//id: id
    case 27:
        return 1;//id: id
    case 28:
        return 1;//id: id
    case 29:
        return 1;//id: id
    case 30:
        return 1;//id: id
    case 31:
        return 1;//id: id
    case 32:
        return 1;//id: id
    case 33:
        return 1;//id: id
    case 34:
        return 1;//id: id
    case 35:
        return 1;//id: id
    case 36:
        return 1;//id: id
    case 37:
        return 3;//number: real
    case 41:
        return 1;//id: id
    case 42:
        return 1;//id: id
    }
    return 0;
}
int DictReg::GroupGet(int accept)
{
    switch (accept)
    {
    case 1:
        return 1;//id: id
    case 2:
        return 2;//number: integer
    case 3:
        return 2;//number: real
    case 4:
        return 3;//string: string
    case 5:
        return 4;//reserved: false
    case 6:
        return 4;//reserved: true
    case 7:
        return 4;//reserved: null
    case 8:
        return 4;//reserved: NULL
    case 9:
        return 5;//division: semicolon
    case 10:
        return 5;//division: colon
    case 11:
        return 5;//division: dot
    case 12:
        return 5;//division: comma
    case 13:
        return 6;//value: value
    case 14:
        return 7;//braket: braceL
    case 15:
        return 7;//braket: braceR
    case 16:
        return 7;//braket: left
    case 17:
        return 7;//braket: right
    case 18:
        return 7;//braket: squareL
    case 19:
        return 7;//braket: squareR
    case 20:
        return 8;//anntation: anntationS
    case 21:
        return 8;//anntation: anntationM
    case 22:
        return 9;//format: spaces
    case 23:
        return 9;//format: enters
    case 24:
        return 9;//format: tab
    }
    return 0;
}
const size_t DictPraser::StateCount = 27;
const size_t DictPraser::NonTerminalCount = 7;
const size_t DictPraser::TerminalCount = 24;
const size_t DictPraser::RulesCount = 16;
const int DictPraser::GOTO[27][7] = { \
{1, 6, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 14, 18, 1, 1, 1}, \
{1, 1, 1, 102, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 34, 1, 1, 94, 1, 42}, \
{1, 34, 1, 1, 38, 1, 42}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 34, 1, 1, 1, 66, 70}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 34, 1, 1, 1, 1, 86}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1} };
//==============================
const int DictPraser::ACTION[27][25] = { \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 22, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 22, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 106, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 15, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 15, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 26, 1, 1, 30, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 46, 50, 54, 58, 1, 1, 1, 1, 1, 10, 1, 1, 1, 62, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 46, 50, 54, 58, 1, 1, 1, 1, 1, 10, 1, 1, 1, 62, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 63, 1, 1, 63, 1, 1, 1, 1, 1, 1, 63, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 90, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 31, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 59, 1, 1, 59, 1, 1, 1, 1, 1, 1, 59, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 55, 1, 1, 55, 1, 1, 1, 1, 1, 1, 55, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 51, 1, 1, 51, 1, 1, 1, 1, 1, 1, 51, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 47, 1, 1, 47, 1, 1, 1, 1, 1, 1, 47, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 46, 50, 54, 58, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 74, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 78, 1, 1, 1, 1, 1, 1, 82, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 43, 1, 1, 1, 1, 1, 1, 43, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 35, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 46, 50, 54, 58, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 27, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 39, 1, 1, 1, 1, 1, 1, 39, 1, 1, 1, 1, 1}, \
{1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 23, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 98, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 19, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 19, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 11, 1, 1, 1, 1, 1, 1, 1, 1, 1}, \
{7, 1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 7, 1, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1} };
//==============================
const int DictPraser::RulesToSymbol[16] = { \
0,\
1,\
2,\
2,\
3,\
3,\
4,\
4,\
4,\
5,\
5,\
6,\
6,\
6,\
6,\
6 };
//==============================
const int DictPraser::RulesLength[16] = { \
1,\
3,\
2,\
1,\
4,\
4,\
3,\
1,\
2,\
3,\
1,\
1,\
1,\
1,\
1,\
1 };
//==============================
const char* const DictPraser::RulesName[16] = { \
"all->DICTIONARY ",\
"DICTIONARY->braceL KVS braceR ",\
"KVS->KVS KV ",\
"KVS->KV ",\
"KV->id colon VALUE semicolon ",\
"KV->id value VALUE semicolon ",\
"VALUE->squareL UNITS squareR ",\
"VALUE->UNIT ",\
"VALUE->squareL squareR ",\
"UNITS->UNITS comma UNIT ",\
"UNITS->UNIT ",\
"UNIT->NULL ",\
"UNIT->null ",\
"UNIT->true ",\
"UNIT->false ",\
"UNIT->DICTIONARY " };


using namespace hyperlex;
#include<stdlib.h>

static char* CopyMalloc(const char* s);
static bool isIdBegin(char c);
static bool isIdNumber(char c);

void hyperlex_old::unit::initial(void)
{
    origin = NULL;
    C.S = NULL;
}
void hyperlex_old::unit::ruin(void)
{
    if (type == 3)
        free(C.S);
    free(origin);
}
void hyperlex_old::unit::print(FILE* fp)
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
void hyperlex_old::unit::operator=(double e)
{
    C.real = e;
    type = 1;
}
void hyperlex_old::unit::operator=(long long int e)
{
    C.integer = e;
    type = 0;
}
void hyperlex_old::unit::operator=(std::string e)
{
    size_t i;
    C.S = (char*)malloc((e.length() + 1) * sizeof(char));
    for (i = 0; e[i] != '\0'; i++) C.S[i] = e[i];
    C.S[i] = e[i];
    type = 3;
}
hyperlex_old::UnitBuffer::UnitBuffer()
{
    size_t i;
    size = 128;
    //head = 0;
    content = (unit*)malloc(sizeof(unit) * size);
    for (i = 0; i < size; i++)
        content[i].initial();
    site = 0;
}
hyperlex_old::UnitBuffer::~UnitBuffer()
{
    size_t i;
    for (i = 0; i < site; i++)
        content[i].ruin();
    free((void*)content);
    size = 0;
    site = 0;
}
size_t hyperlex_old::UnitBuffer::Site(void)
{
    return site;
}
size_t hyperlex_old::UnitBuffer::add(void)
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
void hyperlex_old::UnitBuffer::add(long long int c)
{
    content[add()] = c;
}
void hyperlex_old::UnitBuffer::print(FILE* fp)
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
void hyperlex_old::UnitBuffer::print(FILE* fp, size_t count)
{
    size_t i;
    for (i = 0; i < site && i < count; i++)
    {
        content[i].print(fp);
        fprintf(fp, "\n");
    }
    return;
}
hyperlex_old::unit& hyperlex_old::UnitBuffer::operator[](size_t target)
{
    return content[target];
}





hyperlex_old::CharBuffer::CharBuffer()
{
    size = 128;
    head = 0;
    content = (char*)malloc(sizeof(char) * size);
    site = 0;
}
hyperlex_old::CharBuffer::~CharBuffer()
{
    //printf("~hyperlex_old::CharBuffer()\n");
    free((void*)content);
    size = 0;
    site = 0;
    head = 0;
}
size_t hyperlex_old::CharBuffer::Site(void)
{
    return site;
}
size_t hyperlex_old::CharBuffer::Length(void)
{
    return (size_t)(site - head);
}
void hyperlex_old::CharBuffer::Append(char c)
{
    if (site >= size)
    {
        content = (char*)realloc(content, (size + size / 4 + 8) * sizeof(char));
        size = size + size / 4 + 8;
    }
    *(content + site) = c;
    site += 1;
}
void hyperlex_old::CharBuffer::Append(const char* c)
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
void hyperlex_old::CharBuffer::Append(hyperlex_old::CharBuffer& in)
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
void hyperlex_old::CharBuffer::Print(FILE* fp)
{
    size_t i;
    for (i = head; i < site; i++)
    {
        fprintf(fp, "%c", content[i]);
    }
    fprintf(fp, "\n");
    return;
}
void hyperlex_old::CharBuffer::Print(FILE* fp, int count)
{
    size_t i;
    for (i = 0; i < site && i < count; i++)
    {
        fprintf(fp, "%c", content[i]);
    }
    fprintf(fp, "\n");
    return;
}
void hyperlex_old::CharBuffer::Copy(char* to)
{
    size_t i;
    for (i = head; i < site; i++)
        to[i - head] = content[i];
    to[i - head] = '\0';
    return;
}
char* hyperlex_old::CharBuffer::CopyMalloc(void)
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
char hyperlex_old::CharBuffer::Pop(void)
{
    if (site == head) return EOF;
    site -= 1;
    return content[site];
}
bool hyperlex_old::CharBuffer::Pop(char& out)
{
    if (site == head) return false;
    site -= 1;
    out = content[site];
    return true;
}

void hyperlex_old::CharBuffer::Clear(void)
{
    site = 0;
    head = 0;
}
void hyperlex_old::CharBuffer::operator<<(char c)
{
    Append(c);
    return;
}
void hyperlex_old::CharBuffer::operator<<(const char* c)
{
    Append(c);
}
void hyperlex_old::CharBuffer::operator<<(double e)
{
    char temp[32];
    sprintf(temp, "%+24.16e", e);
    Append(temp);
    return;
}
void hyperlex_old::CharBuffer::operator<<(int e)
{
    char temp[32];
    sprintf(temp, "%d", e);
    Append(temp);
    return;
}
void hyperlex_old::CharBuffer::operator<<(long long int e)
{
    char temp[32];
    sprintf(temp, "%lld", e);
    Append(temp);
    return;
}
void hyperlex_old::CharBuffer::operator<<(hyperlex_old::CharBuffer& in)
{
    size_t L, i;
    Append(in);
    in.Clear();
    return;
}
void hyperlex_old::CharBuffer::operator<<(FILE* fp)
{
    while (feof(fp) == 0)
        Append((char)getc(fp));
    //if (site == 0) Append(EOF);
    //else if (content[site - 1] != ((char)(EOF))) Append(EOF);
}
bool hyperlex_old::CharBuffer::operator==(size_t length)
{
    if ((site - head) <= 0) return length == 0;
    else return (site - head) == length;
}
bool hyperlex_old::CharBuffer::operator!=(size_t length)
{
    if ((site - head) <= 0) return length != 0;
    else return (site - head) != length;
}


char hyperlex_old::CharBuffer::Dequeue(void)
{
    if (head >= site) return EOF;
    head += 1;
    return content[head - 1];
}
char hyperlex_old::CharBuffer::Dequeue(hyperlex_old::CharBuffer& backspace)
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
char hyperlex_old::CharBuffer::QueueHead(void)
{
    if (head >= site) return EOF;
    return content[head];
}



double hyperlex_old::CharBuffer::DequeueReal(void)
{
    int state;
    return RealGet(state, content, site, head);
}
char hyperlex_old::CharBuffer::DequeueChar(void)
{
    return CharGet(content, site, head);
}
char* hyperlex_old::CharBuffer::DequeueString(void)
{
    hyperlex_old::CharBuffer middle;
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
                c = hyperlex::CharGet(error, content, site, head);
                if (c != (char)EOF) middle << c;
            }
            break;
        }
    } while (state >= 0);
    temp = middle.CopyMalloc();
    return temp;
}
char* hyperlex_old::CharBuffer::DequeueId(void)
{
    hyperlex_old::CharBuffer middle;
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

void hyperlex_old::UnitBuffer::build(hyperlex_old::CharBuffer& in)
{
    DFA00 dfa;
    hyperlex_old::CharBuffer backspace;
    hyperlex_old::CharBuffer result;
    hyperlex_old::CharBuffer intermediate;
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
void hyperlex_old::UnitBuffer::Append(hyperlex_old::CharBuffer& result, int state)
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
void hyperlex_old::UnitBuffer::clear(void)
{
    size_t i;
    for (i = 0; i < size; i++)
    {
        content[i].ruin();
        content[i].initial();
    }
    site = 0;
}

hyperlex_old::DFA00::DFA00()
{
    state = 0;
    former_state = 0;
    last_success = -1;
}
hyperlex_old::DFA00::~DFA00()
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

void hyperlex_old::DFA00::DFA_swicth(char c)
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
int hyperlex_old::DFA00::success_get(int State)
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
int hyperlex_old::DFA00::DFA_state(void)
{
    return state;
}
int hyperlex_old::DFA00::DFA_former_state(void)
{
    return former_state;
}
enum hyperlex_old::DFA00::action hyperlex_old::DFA00::should(void)
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
int hyperlex_old::DFA00::result(void)
{
    return last_success;
}
int  hyperlex_old::DFA00::if_error(int type)
{
    return (type == 12) || (type == 56) || (type == 58);
}
void hyperlex_old::DFA00::lexical_analyse(hyperlex_old::CharBuffer& in)
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


hyperlex_old::Bitwise::Bitwise()
{
    fp = NULL;
}
hyperlex_old::Bitwise::~Bitwise()
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
}

hyperlex_old::CFile::CFile()
{
}
hyperlex_old::CFile::~CFile()
{
}
void hyperlex_old::ExitWarning(int error, FILE* fp)
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
void hyperlex_old::Ruin(char** list, size_t length)
{
    size_t i;
    for (i = 0; i < length; i++)
        free(list[i]);
    free(list);
}
bool hyperlex_old::IfLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool hyperlex_old::StringToBool(const char* c_t_f)
{
    size_t i;
    for (i = 0; c_t_f[i] != '\0'; i++)
        if (IfLetter(c_t_f[i]))
            return c_t_f[i] == 'y' || c_t_f[i] == 'Y' || c_t_f[i] == 't' || c_t_f[i] == 'T';
    return false;
}


void hyperlex_old::Bitwise::Open(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "ab+");
}
void hyperlex_old::Bitwise::StoreOpen(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "wb");
}
void hyperlex_old::Bitwise::LoadOpen(const char* name)
{
    if (fp != NULL)
    {
        fclose(fp);
        fp = NULL;
    }
    fp = FP.Open(name, "rb");
}
void hyperlex_old::Bitwise::SetDMatrix(const double* mat, size_t row, size_t column)
{
    if (fp == NULL) return;
    fwrite(&row, sizeof(size_t), 1, fp);
    fwrite(&column, sizeof(size_t), 1, fp);
    fwrite(mat, sizeof(double), row * column, fp);
}
double* hyperlex_old::Bitwise::GetDMatrix(size_t* row, size_t* column)
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

void hyperlex_old::Bitwise::store(size_t value)
{
    fwrite(&value, sizeof(size_t), 1, fp);
}
void hyperlex_old::Bitwise::store(const size_t* vector, size_t length)
{
    fwrite(vector, sizeof(size_t), length, fp);
}
void hyperlex_old::Bitwise::store(const bool* vector, size_t length)
{
    fwrite(vector, sizeof(bool), length, fp);
}
void hyperlex_old::Bitwise::store(const int* vector, size_t length)
{
    fwrite(vector, sizeof(int), length, fp);
}
void hyperlex_old::Bitwise::store(const void* vector, size_t byte)
{
    fwrite(vector, 1, byte, fp);
}

void hyperlex_old::Bitwise::store(const char* list)
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
void hyperlex_old::Bitwise::store(const char** list, size_t length)
{
    size_t i;
    fwrite(&length, sizeof(size_t), 1, fp);
    for (i = 0; i < length; i++)
        store((const char*)(list[i]));
}


size_t hyperlex_old::Bitwise::loadllu(void)
{
    size_t value;
    fread(&value, sizeof(size_t), 1, fp);
    return value;
}
char* hyperlex_old::Bitwise::loadstring(void)
{
    char* list;
    size_t length;
    fread(&length, sizeof(size_t), 1, fp);
    if (length == 0) return NULL;
    list = (char*)malloc(sizeof(char) * length);
    fread(list, sizeof(char), length, fp);
    return list;
}
char** hyperlex_old::Bitwise::loadlist(void)
{
    char** list;
    size_t length, i;
    fread(&length, sizeof(size_t), 1, fp);
    list = (char**)malloc(sizeof(char*) * length);
    for (i = 0; i < length; i++)
        list[i] = loadstring();
    return list;
}
void* hyperlex_old::Bitwise::load(size_t byte)
{
    void* vector;
    vector = malloc(byte);
    fread(vector, 1, byte, fp);
    return vector;
}
void* hyperlex_old::Bitwise::load(size_t EleAmount, size_t ContainerAmount, size_t EleSize)
{
    void* vector;
    vector = malloc(ContainerAmount * EleSize);
    fread(vector, EleSize, EleAmount, fp);
    return vector;
}


hyperlex_old::ParaFile::ParaFile()
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
hyperlex_old::ParaFile::~ParaFile()
{
    free(key);
    free(FirstElem);
    free(ElemAmount);
    free(Next);
    free(Type);
}
int hyperlex_old::ParaFile::initial(FILE* fp)
{
    CharBuffer Buffer;
    Buffer << fp;
    return initial(Buffer);
}
int hyperlex_old::ParaFile::initial(const char* file)
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
int hyperlex_old::ParaFile::initial(CharBuffer& in)
{
    size_t i;
    build(in);
    //print(stdout);
    if (ERROR != 0) return ERROR;
    Next = (size_t*)malloc(sizeof(size_t) * site);
    for (i = 0; i < site; i++) Next[i] = site;
    return construct(in);
}
int hyperlex_old::ParaFile::construct(CharBuffer& in)
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
void hyperlex_old::ParaFile::append(size_t No)
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
bool hyperlex_old::ParaFile::IfContent(int T)
{
    return T == 5 || T == 3 || T == 4 || T == 11 || T == 0 || T == 57;
}
hyperlex_old::ParaFile::ParaType hyperlex_old::ParaFile::SwitchType(int T)
{
    if (T == 5) return Id;
    else if (T == 3 || T == 4) return Real;
    else if (T == 0) return Int;
    else if (T == 57) return Char;
    else if (T == 11) return String;
    else return Mix;
}

void hyperlex_old::ParaFile::demo(FILE* fp)
{
    size_t i;
    for (i = 0; i < KeyAmount; i++)
    {
        fprintf(fp, "Key[%llu] = %s, FirstElem: %llu, Amount: %llu\n", i, content[key[i]].origin, FirstElem[i], ElemAmount[i]);
    }
    for (i = 0; i < site; i++)
        fprintf(fp, "Next[%llu] = %llu\n", i, Next[i]);
}
size_t hyperlex_old::ParaFile::Amount(void)const
{
    return KeyAmount;
}
size_t hyperlex_old::ParaFile::Amount(size_t i)const
{
    return i < KeyAmount ? ElemAmount[i] : 0;
}
#include <string.h>
size_t hyperlex_old::ParaFile::SearchKey(const char* Key) const
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
size_t hyperlex_old::ParaFile::SearchKey(const char* Key, hyperlex_old::ParaFile::ParaType T)const
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
hyperlex_old::ParaFile::ParaType hyperlex_old::ParaFile::GetType(size_t i)
{
    return Type[i];
}
hyperlex_old::IntegerDefault hyperlex_old::ParaFile::FirstInt(size_t i)
{
    if (i < KeyAmount)
        if (Int == Type[i]) return content[FirstElem[i]].C.integer;
    return 0;
}
double hyperlex_old::ParaFile::FirstReal(size_t i)
{
    if (i < KeyAmount)
        if (Real == Type[i]) return content[FirstElem[i]].C.real;
    return 0;
}
std::string hyperlex_old::ParaFile::FirstString(size_t i)
{
    std::string SSS;
    if (i < KeyAmount)
        if (String == Type[i]) SSS = content[FirstElem[i]].C.S;
    return SSS;
}
std::string hyperlex_old::ParaFile::GetString(const char* Key, const char* Default)
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
bool hyperlex_old::ParaFile::GetBool(const char* Key) const
{
    std::string temp;
    size_t site;
    ParaType T;
    site = SearchKey(Key);
    if (site == Amount()) return false;
    else
    {
        T = Type[site];
        if (T != String && T != Id && T != MixString)
            temp = "F";
        else
            temp = content[FirstElem[site]].C.S;
    }
    return true_false_judge(temp.c_str());
}

void hyperlex_old::ParaFile::IntList(IntegerDefault*& list, size_t& length, size_t i)
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
void hyperlex_old::ParaFile::CharList(char**& list, size_t& length, size_t i)
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
FILE* hyperlex_old::CFile::Open(const char* name, const char* mode)
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
FILE* hyperlex_old::CFile::OpenRead(const char* name)
{
    return Open(name, "r");
}
FILE* hyperlex_old::CFile::OpenWriteAtRear(const char* name)
{
    return Open(name, "a+");
}
FILE* hyperlex_old::CFile::OpenWritePlus(const char* name)
{
    return Open(name, "w+");
}
std::string hyperlex_old::CFile::FusePathAndName(const std::string& path, const std::string& name)
{
    std::string fusion;
    if (path[path.length() - 1] == '/')
        fusion = path + name;
    else
        fusion = path + '/' + name;
    return fusion;
}
std::string hyperlex_old::CFile::FusePathAndName(const char* path, const std::string& name)
{
    std::string PPP;
    PPP = path;
    return FusePathAndName(PPP, name);
}
std::string hyperlex_old::CFile::ChangeSuffix(const std::string& file, const char* new_one)
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


hyperlex_old::MatFile::MatFile()
{
}
hyperlex_old::MatFile::~MatFile()
{
}


int hyperlex_old::MatFile::MatrixGet(double** list, size_t* row, size_t* column, hyperlex_old::CharBuffer& in)
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
int hyperlex_old::MatFile::MatrixGet(double** list, size_t* row, size_t* column, const char* file)
{
    int error;
    FILE* fp;
    CFile CF;

    fp = CF.OpenRead(file);
    error = MatrixGet(list, row, column, fp);
    fclose(fp);

    return error;
}
int hyperlex_old::MatFile::MatrixGet(double** list, size_t* row, size_t* column, FILE* fp)
{
    CharBuffer in;
    in << fp;
    return MatrixGet(list, row, column, in);
}
void hyperlex_old::MatFile::MatrixSet(const double* mat, size_t ld, size_t row, size_t column, const char* file)
{
    FILE* fp;
    CFile CF;
    fp = CF.OpenWriteAtRear(file);
    MatrixSet(mat, ld, row, column, fp);
    fclose(fp);
    return;
}
void hyperlex_old::MatFile::MatrixSet(const double* mat, size_t ld, size_t row, size_t column, FILE* fp)
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



#define SizeMax ((size_t)0xffffffffffffffff)
#define CharSize ((size_t)(1 << (sizeof(char) * 8 - 1)))

template <class T> class bitree
{
    bitree<T>* left;
    bitree<T>* right;
    T content;
public:
    bitree();
    ~bitree();
    const bitree<T>*& L(void) const;
    const bitree<T>*& R(void) const;
    bitree<T>*& L(void);
    bitree<T>*& R(void);
    const T& C(void) const;
    T& C(void);
    void postorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
    void postorderTraversal(buffer<size_t>& output) const;
    void inorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
    void inorderTraversal(buffer<size_t>& output) const;
    bool IfLeaf(size_t site)const;
};
template <class T> class Bitree
{
public:
    struct node
    {
        size_t left;
        size_t right;
        T content;
    };
    Bitree();
    ~Bitree();
    void move(Bitree<T>& source);
    void clear(void);
    void SetHead(size_t head);
    size_t NewNodeOffset(void);
    node* NewNode(void);
    node* Node(size_t site)const;
    node* LeftChild(const node* now)const;
    node* RightChild(const node* now)const;
    const node& operator[](size_t target) const;
    node& operator[](size_t target);
    void postorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
    void postorderTraversal(buffer<size_t>& output) const;
    void inorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
    void inorderTraversal(buffer<size_t>& output) const;
    bool IfLeaf(size_t site)const;
    void Demo(FILE* fp)const;


    void removal(size_t site);
    void removal(size_t site, buffer<size_t>& output, list<size_t>& s);
    void append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, size_t& NewSite);

    void append(const Bitree<T>& left, size_t parent);
    void append(const Bitree<T>& left, const Bitree<T>& right, size_t parent);

    //size_t append_t(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, bool key);
    //void append_t(const Bitree<T>& left, const Bitree<T>& right, size_t parent, bool key);
    size_t Head;
private:

    size_t Size;
    size_t Count;
    size_t FirstEmpty;
    node* Nodes;
};

template <class T> class StaticTree
{
public:
    struct node
    {
        size_t offset;
        size_t degree;
        T content;
    };
    StaticTree();
    ~StaticTree();
    void clear(void);
    void build(tree<T>* input);
private:
    size_t Head;
    list<node> Nodes;
    list<size_t> next;
};
template <class T> class Tree
{
public:
    struct node
    {
        vec<node*> childs;
        T content;
        node() {}
        ~node() {}
        void build(list<Tree>& input);
    };
    Tree();
    ~Tree();
    void move(Tree<T>& source);
    void clear(void);
    void build(list<Tree>& input);
    void PostOrderTraversal(list<node*>& output) const;
    T& head(void);
    const T& head(void) const;
private:
    node* Head;
    void RuinSelf(void);
};
template <class T> bitree<T>::bitree()
{
    left = NULL;
    right = NULL;
}
template <class T> bitree<T>::~bitree()
{

}
template <class T> const bitree<T>*& bitree<T>::L(void) const
{
    return left;
}
template <class T> const bitree<T>*& bitree<T>::R(void) const
{
    return right;
}
template <class T> bitree<T>*& bitree<T>::L(void)
{
    return left;
}
template <class T> bitree<T>*& bitree<T>::R(void)
{
    return right;
}
template <class T> const T& bitree<T>::C(void) const
{
    return content;
}
template <class T> T& bitree<T>::C(void)
{
    return content;
}
template <class T> void bitree<T>::postorderTraversal(buffer<size_t>& output, list<size_t>& s) const
{

}
template <class T> void bitree<T>::postorderTraversal(buffer<size_t>& output) const
{
    list<size_t> s;
    postorderTraversal(output, s);
}
template <class T> void bitree<T>::inorderTraversal(buffer<size_t>& output, list<size_t>& s) const
{
    bitree<T>* LeftMost;
    bitree<T>* now;
    now = this;
    while (now != NULL || s.count() != 0)
    {
        while (now != NULL)
        {
            s.append(now);
            now = now->left;
        }
        s.pop(LeftMost);
        output.append(LeftMost);
        now = LeftMost->right;
    }
}
template <class T> void bitree<T>::inorderTraversal(buffer<size_t>& output) const
{
    list<size_t> s;
    inorderTraversal(output, s);
}
template <class T> bool bitree<T>::IfLeaf(size_t site)const
{
    return left == NULL && right == NULL;
}



template <class T> Bitree<T>::Bitree()
{
    Nodes = NULL;
    Count = 0;
    Size = 0;
    Head = SizeMax;
    FirstEmpty = SizeMax;
}
template <class T> Bitree<T>::~Bitree()
{
    free(Nodes);
    Nodes = NULL;
    Count = 0;
    Size = 0;
    Head = SizeMax;
    FirstEmpty = SizeMax;
}
template <class T> void Bitree<T>::move(Bitree<T>& source)
{
    Nodes = source.Nodes;
    Count = source.Count;
    Size = source.Size;
    Head = source.Head;
    FirstEmpty = source.FirstEmpty;

    source.Nodes = NULL;
    source.Count = 0;
    source.Size = 0;
    source.Head = SizeMax;
    source.FirstEmpty = SizeMax;
}
template <class T> void Bitree<T>::clear(void)
{
    size_t i;
    if (Nodes == NULL)return;
    Head = SizeMax;
    Count = 0;
    FirstEmpty = 0;
    for (i = 0; i < Size; i++)
    {
        Nodes[i].right = SizeMax;
        Nodes[i].left = i + 1;
    }
    Nodes[Size - 1].left = SizeMax;
}
template <class T> void Bitree<T>::SetHead(size_t head)
{
    Head = head;
}
template <class T> typename Bitree<T>::node* Bitree<T>::NewNode(void)
{
    return Nodes + NewNodeOffset();
}
template <class T> size_t Bitree<T>::NewNodeOffset(void)
{
    size_t result, NewSize__, i;
    if (FirstEmpty == SizeMax)
    {
        NewSize__ = (Size + Size / 4 + 8);
        Nodes = (node*)realloc(Nodes, NewSize__ * sizeof(node));
        for (i = Size; i < NewSize__; i++)
        {
            Nodes[i].right = SizeMax;
            Nodes[i].left = i + 1;
        }
        Nodes[NewSize__ - 1].left = SizeMax;
        FirstEmpty = Size;
        Size = NewSize__;
    }
    result = FirstEmpty;
    FirstEmpty = Nodes[FirstEmpty].left;
    Nodes[result].left = SizeMax;
    Count += 1;
    //if (result == 0) Head = 0;
    return result;
}
template <class T> typename Bitree<T>::node* Bitree<T>::Node(size_t site)const
{
    return Nodes + site;
}
template <class T> typename Bitree<T>::node* Bitree<T>::LeftChild(const Bitree<T>::node* now)const
{
    return Nodes + now->left;
}
template <class T> typename Bitree<T>::node* Bitree<T>::RightChild(const Bitree<T>::node* now)const
{
    return Nodes + now->right;
}
template <class T> void Bitree<T>::postorderTraversal(buffer<size_t>& output) const
{
    list<size_t> s;
    postorderTraversal(output, s);
}
template <class T> void Bitree<T>::postorderTraversal(buffer<size_t>& output, list<size_t>& s) const
{
    size_t previous;
    size_t LeftMost;
    size_t now;
    now = Head;
    previous = SizeMax;
    while (now != SizeMax || s.count() != 0)
    {
        while (now != SizeMax)
        {
            s.append(now);
            now = (Nodes + now)->left;
        }
        LeftMost = s.top();
        if (Nodes[LeftMost].right == SizeMax || Nodes[LeftMost].right == previous)
        {
            output.append(LeftMost);
            previous = LeftMost;
            s.pop();
        }
        else
            now = Nodes[LeftMost].right;
    }
}
template <class T> const typename Bitree<T>::node& Bitree<T>::operator[](size_t target) const
{
    return Nodes[target];
}
template <class T> typename Bitree<T>::node& Bitree<T>::operator[](size_t target)
{
    return Nodes[target];
}
template <class T> void Bitree<T>::inorderTraversal(buffer<size_t>& output, list<size_t>& s) const
{
    size_t LeftMost;
    size_t now;
    now = Head;
    LeftMost = Head;
    while (now != SizeMax || s.count() != 0)
    {
        while (now != SizeMax)
        {
            s.append(now);
            now = (Nodes + now)->left;
        }
        s.pop(LeftMost);
        output.append(LeftMost);
        now = Nodes[LeftMost].right;
    }
}
template <class T> void Bitree<T>::inorderTraversal(buffer<size_t>& output) const
{
    list<size_t> s;
    inorderTraversal(output, s);
}
template <class T> bool Bitree<T>::IfLeaf(size_t site)const
{
    return Nodes[site].left == SizeMax && Nodes[site].right == SizeMax;
}
template <class T> void Bitree<T>::Demo(FILE* fp)const
{
    size_t i;
    fprintf(fp, "Head = %zu\n", Head);
    fprintf(fp, "Size = %zu\n", Size);
    fprintf(fp, "Count = %zu\n", Count);
    fprintf(fp, "FirstEmpty = %zu\n", FirstEmpty);
    if (Nodes == NULL)
    {
        fprintf(fp, "Nodes == NULL\n");
        return;
    }
    for (i = 0; i < Size; i++)
    {
        fprintf(fp, "Nodes[%zu].left = %22zu, ", i, Nodes[i].left);
        fprintf(fp, "Nodes[%zu].right = %22zu  ", i, Nodes[i].right);
        Nodes[i].content.Demo(fp);
        //fprintf(fp, "\n");
    }
}


template <class T> void Bitree<T>::removal(size_t site)
{
    buffer<size_t>& output;
    list<size_t>& s;
    removal(site, output, s);
}
template <class T> void Bitree<T>::removal(size_t site, buffer<size_t>& output, list<size_t>& s)
{
    if (site == SizeMax) return;
    size_t now;
    s.refresh();
    output.clear();
    inorderTraversal(output, s);
    while (output.dequeue(now))
    {
        Count -= 1;
        (Nodes + now)->right = SizeMax;
        (Nodes + now)->left = FirstEmpty;
        FirstEmpty = now;
    }
}
template <class T> void Bitree<T>::append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, size_t& NewSite)
{
    //size_t newHead;
    size_t now, new_node, temp;
    s.refresh();
    output.clear();
    new_node = SizeMax;
    source.postorderTraversal(output, s);
    s.refresh();
    s.renew(source.Size);
    while (output.dequeue(now))
    {
        new_node = NewNodeOffset();
        //std::cout << "new_node: " << new_node << std::endl;
        //std::cout << "now: " << now << std::endl;
        temp = source.Nodes[now].left;
        (Nodes + new_node)->left = (temp == SizeMax ? SizeMax : s[temp]);
        //std::cout << "source.Nodes[now].left: " << temp << std::endl;
        //std::cout << "(Nodes + new_node)->left: " << (Nodes + new_node)->left << std::endl;
        temp = source.Nodes[now].right;
        (Nodes + new_node)->right = (temp == SizeMax ? SizeMax : s[temp]);
        //std::cout << "source.Nodes[now].right: " << temp << std::endl;
        //std::cout << "(Nodes + new_node)->right: " << (Nodes + new_node)->right << std::endl;
        (Nodes + new_node)->content = source.Nodes[now].content;
        s[now] = new_node;
        //if (newHead == SizeMax) newHead = new_node;
        //newHead = new_node;
    }
    //std::cout << "newHead: " << new_node << std::endl;
    //std::cout << "newHead: " << newHead << std::endl;

    NewSite = new_node;
    //std::cout << "return NewSite: " << NewSite << "\n\n" << std::endl;
}
template <class T> void Bitree<T>::append(const Bitree<T>& L, size_t parent)
{
    buffer<size_t> output;
    list<size_t> s;
    size_t NewSite;
    removal((Nodes + parent)->left, output, s);
    append(L, output, s, NewSite);
    (Nodes + parent)->left = NewSite;
}
template <class T> void Bitree<T>::append(const Bitree<T>& L, const Bitree<T>& R, size_t parent)
{
    buffer<size_t> output;
    list<size_t> s;
    size_t NewSite;
    //size_t temp;
    //size_t as[15];
    removal((Nodes + parent)->left, output, s);
    removal((Nodes + parent)->right, output, s);
    //std::cout << "parent: " << parent << std::endl;
    //std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
    append(L, output, s, NewSite);
    (Nodes + parent)->left = NewSite;
    //std::cout << "parent: " << parent << std::endl;
    //temp = (Nodes + parent)->right;
    //std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
    //std::cout << "(Nodes + parent)->right: " << temp << std::endl;
    //(Nodes + parent)->right = 10007;
    //std::cout << "(Nodes + parent)->right: " << (Nodes + parent)->right << std::endl;
    //std::cout << "temp ptr: " << &temp << std::endl;
    //std::cout << "(Nodes + parent) ptr: " << (Nodes + parent) << std::endl;
    //std::cout << "(Nodes + parent)->left ptr: " << (size_t) & ((Nodes + parent)->left) << std::endl;
    //std::cout << "(Nodes + parent)->right ptr: " << &((Nodes + parent)->right) << std::endl;

    append(R, output, s, NewSite);
    (Nodes + parent)->right = NewSite;// the style that produced the bug.
    //temp = append(R, output, s);// the style that produced no bug.
    //Nodes[parent].right = temp;// the style that produced no bug. 

    //std::cout << "parent: " << parent << std::endl;
    //std::cout << "(Nodes + parent)->right: " << (Nodes + parent)->right << std::endl;
}


template <class T> StaticTree<T>::StaticTree()
{

}
template <class T> StaticTree<T>::~StaticTree()
{

}
template <class T> void StaticTree<T>::clear(void)
{

}
template <class T> void StaticTree<T>::build(tree<T>* input)
{

}

template <class T> Tree<T>::Tree()
{
    Head = NULL;
}
template <class T> Tree<T>::~Tree()
{
    RuinSelf();
}
template <class T> void Tree<T>::RuinSelf(void)
{
    list<node*> deleted;
    size_t i;
    if (Head == NULL) return;
    PostOrderTraversal(deleted);
    for (i = 0; i < deleted.count(); i++)
        delete deleted[i];
    Head = NULL;
}
template <class T> void Tree<T>::move(Tree<T>& source)
{
    Head = source.Head;
    source.Head = NULL;
}
template <class T> void Tree<T>::clear(void)
{
    RuinSelf();
}
template <class T> void Tree<T>::PostOrderTraversal(list<node*>& output) const
{
    /*struct infor
    {
        node* site;
        bool state;
    };
    list<infor> stack;
    infor now;
    node* here;
    size_t i;
    now.site = Head;
    now.state = false;
    stack.append(now);
    while (stack.pop(now) != 0)
    {
        here = now.site;
        if (here == NULL) continue;
        if (now.state) output.append(here);
        else
        {
            now.state = true;
            stack.append(now);
            now.state = false;
            for (i = 0; i < here->childs.size(); i++)
            {
                now.site = here->childs[i];
                stack.append(now);
            }
        }
    }
*/
}
template <class T> void Tree<T>::build(list<Tree>& input)
{
    size_t i;
    clear();
    Head = new node();
    Head->childs.Realloc(input.count());
    for (i = 0; i < input.count(); i++)
    {
        Head->childs[i] = input[i].Head;
        input[i].Head = NULL;
    }
}
template <class T> void Tree<T>::node::build(list<Tree>& input)
{
    size_t i;
    node* now;
    Tree<T> temp;
    for (i = 0; i < childs.size(); i++)
    {
        temp.Head = childs[i];
        temp.clear();
    }
    childs.Realloc(input.count());
    for (i = 0; i < input.count(); i++)
    {
        childs[i] = input[i].Head;
        input[i].Head = NULL;
    }
}
template <class T> T& Tree<T>::head(void)
{
    return Head->content;
}
template <class T> const T& Tree<T>::head(void) const
{
    return Head->content;
}
class DirectedGraph
{
public:
    DirectedGraph();
    ~DirectedGraph();
    struct vortex
    {
        size_t first;
        size_t rear;
        //size_t site;
    };
    struct arc
    {
        size_t from;
        size_t to;
        size_t next;
        size_t site;
    };
    void refresh(void);
    void refresh(size_t newlength);
    size_t append(size_t from, size_t to, size_t site);
    void append(DirectedGraph& right, size_t VerticeOffset, size_t ArcsOffset, size_t siteOffset);
    list<vortex> vertice;
    buffer<arc> arcs;
private:
};

class RegTree
{
public:
    friend class sNFA;
    enum NodeType
    {
        Concatenation = 0,
        Alternation = 1,
        ZeroOrMore = 2,
        OneOrMore = 3,
        ZeroOrOne = 4,
        Range = 5,
    };
    struct info
    {
        char upper;
        char lower;
        NodeType type;
        void Demo(FILE* fp)const;
    };

    static int next_Reg(int state, const char c);
    static int action_Reg(int state);
    static int GroupGet_Reg(int accept);
private:
    Bitree<info> tree;
    struct traverse
    {
        int state;
        size_t site;
    };
public:
    RegTree();
    ~RegTree();
    void build(const char* reg);
    void build(BufferChar& input);
    bool RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate);


    void grow(const RegTree* reg, NodeType T);
    void grow(const RegTree* regL, const RegTree* regR, NodeType T);
    //void grow_t(const RegTree* regL, const RegTree* regR, NodeType T, bool key);
    void grow(char L, char U);
    void grow(char C);
    void value(const RegTree* regL);

    void Reserved(const char* res);
    void Int(void);
    void Identifier(void);
    void IdentifierHead(void);
    void IdentifierInner(void);
    void ConstChar(void);
    void CommonChar(void);
    void EscapeAll(void);
    void EscapeChar(void);
    void HexaChar(void);
    void OctaChar(void);
    void spaces(void);
    void LineFeeds(void);

    static void swap(const RegTree*& regL, const RegTree*& regR);
    void Demo(FILE* fp) const;
    static void Demo(FILE* fp, NodeType T);
    static void Demo(FILE* fp, char L, char U);
private:
    void value(size_t site, char LU);
    void value(size_t site, char L, char U);
    void link(size_t site, size_t L, size_t R, NodeType T);
    void link(size_t site, size_t L, NodeType T);
};
class lexicalPanel
{
public:
    class infor
    {
    public:
        size_t priority;
        //When two distinct regular expressions match simultaneously, 
        //the regular expression with the higher priority number is accepted.
        RegTree* reg;
        const char* name;
        const char* attribute;
        size_t group;
        infor();
        ~infor();
        void Demo(FILE* fp);
        void SetName(const char* input);
        void SetAttribute(const char* input);
    };
    friend class NFA;
    lexicalPanel();
    ~lexicalPanel();

    void build(void);
    void BuildDemo(FILE* fp);

    void Cprint(FILE* fp, const char* name);
    void CppPrint(FILE* fp, const char* name);

    void SetGrammer(void);
    void SetReg(void);
    void SetRegS(void);
    void SetRegFinal(void);
    void append(infor* II);

    void Demo(FILE* fp) const;

    const char** GetName(void)const;
    const char** GetAttribute(void)const;
    //void append(const char* Name, const char* Attri, RegTree* Reg, size_t Priority);
    //void expand(void);
private:
    list<infor*> regular;
    void SetAll(void);
    //size_t AttributeCount;
    list<const char*> attribute;
    //size_t count;
    //size_t capacity;
    //RegTree** reg;
    //const char**name;
    //const char**attribute;
    //size_t* priority;

    NFA* nfa;
    sheetDFA* DFAsheet;
    DFA* DFAgraph;
    void Cgroup(FILE* fp, const char* name)const;
    void CppGroup(FILE* fp, const char* name)const;
    void CppGroupCore(FILE* fp, const char* name)const;
};

DirectedGraph::DirectedGraph()
{
}
DirectedGraph::~DirectedGraph()
{
}
void DirectedGraph::refresh(void)
{
    vertice.refresh();
    arcs.clear();
}
void DirectedGraph::refresh(size_t newlength)
{
    size_t i;
    vertice.refresh(newlength);
    arcs.clear();
    for (i = 0; i < vertice.count(); i++)
    {
        vertice[i].first = SizeMax;
        vertice[i].rear = SizeMax;
    }
}
size_t DirectedGraph::append(size_t from, size_t to, size_t site)
{
    size_t should;
    should = arcs.expand();
    arcs[should].from = from;
    arcs[should].to = to;
    arcs[should].site = site;
    arcs[should].next = SizeMax;
    if (vertice[from].first == SizeMax)
    {
        vertice[from].first = should;
        vertice[from].rear = should;
    }
    else
    {
        arcs[vertice[from].rear].next = should;
        vertice[from].rear = should;
    }
    return should;
}
void DirectedGraph::append(DirectedGraph& right, size_t VerticeOffset, size_t ArcsOffset, size_t siteOffset)
{
    size_t i, length, temp, begin;
    length = right.vertice.count();
    for (i = 0; i < length; i++)
    {
        temp = (right.vertice[i].first == SizeMax ? SizeMax : right.vertice[i].first + ArcsOffset);
        vertice[i + VerticeOffset].first = temp;
        temp = (right.vertice[i].rear == SizeMax ? SizeMax : right.vertice[i].rear + ArcsOffset);
        vertice[i + VerticeOffset].rear = temp;
    }
    begin = arcs.rear();
    arcs.append(right.arcs);
    //arcs.expand(right.arcs.count());
    length = right.arcs.count();
    for (i = begin; i < length; i++)
    {
        arcs[i].from += VerticeOffset;
        arcs[i].to += VerticeOffset;
        arcs[i].site += siteOffset;
        temp = (arcs[i].next == SizeMax ? SizeMax : arcs[i].next + ArcsOffset);
        arcs[i].next = temp;
    }
}




RegTree::RegTree()
{
}
RegTree::~RegTree()
{
}

int RegTree::next_Reg(int state, const char c)
{
    switch (state)
    {
    case 0:
        if (c == '\'') return 14;
        else if (c == '(') return 1;
        else if (c == ')') return 2;
        else if (c == '*') return 6;
        else if (c == '+') return 7;
        else if (c == '-') return 5;
        else if ('0' <= c && c <= '9') return 9;
        else if (c == '\?') return 8;
        else if ('A' <= c && c <= 'Z') return 9;
        else if (c == '[') return 3;
        else if (c == ']') return 4;
        else if (c == '_') return 9;
        else if ('a' <= c && c <= 'z') return 9;
        else if (c == '|') return 11;
        else return 0;
    case 1:
        return 0;
    case 2:
        return 0;
    case 3:
        return 0;
    case 4:
        return 0;
    case 5:
        return 0;
    case 6:
        return 0;
    case 7:
        return 0;
    case 8:
        return 0;
    case 9:
        return 0;
    case 10:
        return 0;
    case 11:
        return 0;
    case 12:
        if (c == '\'') return 10;
        else return 0;
    case 13:
        if (c == (char)0) return 12;
        else if (c == '\"') return 12;
        else if (c == '\'') return 12;
        else if ('0' <= c && c <= '7') return 16;
        else if (c == '\?') return 12;
        else if (c == 'X') return 15;
        else if (c == '\\') return 12;
        else if ('a' <= c && c <= 'b') return 12;
        else if (c == 'f') return 12;
        else if (c == 'n') return 12;
        else if (c == 'r') return 12;
        else if (c == 't') return 12;
        else if (c == 'v') return 12;
        else if (c == 'x') return 15;
        else return 0;
    case 14:
        if (' ' <= c && c <= '!') return 12;
        else if ('#' <= c && c <= '&') return 12;
        else if ('(' <= c && c <= '[') return 12;
        else if (c == '\\') return 13;
        else if (']' <= c && c <= '~') return 12;
        else return 0;
    case 15:
        if ('0' <= c && c <= '9') return 17;
        else if ('A' <= c && c <= 'F') return 17;
        else if ('a' <= c && c <= 'f') return 17;
        else return 0;
    case 16:
        if (c == '\'') return 10;
        else if ('0' <= c && c <= '7') return 18;
        else return 0;
    case 17:
        if (c == '\'') return 10;
        else if ('0' <= c && c <= '9') return 12;
        else if ('A' <= c && c <= 'F') return 12;
        else if ('a' <= c && c <= 'f') return 12;
        else return 0;
    case 18:
        if (c == '\'') return 10;
        else if ('0' <= c && c <= '7') return 12;
        else return 0;
    }
    return 0;
}
int RegTree::action_Reg(int state)
{
    switch (state)
    {
    case 1:
        return 1;//braket: left
    case 2:
        return 2;//braket: right
    case 3:
        return 3;//braket: begin
    case 4:
        return 4;//braket: end
    case 5:
        return 5;//braket: range
    case 6:
        return 6;//superscript: star
    case 7:
        return 7;//superscript: plus
    case 8:
        return 8;//superscript: ZeroOrOne
    case 9:
        return 9;//char: reserved
    case 10:
        return 10;//char: CommonChar
    case 11:
        return 11;//Or: Or
    }
    return 0;
}
int RegTree::GroupGet_Reg(int accept)
{
    switch (accept)
    {
    case 1:
        return 0;//braket: left
    case 2:
        return 0;//braket: right
    case 3:
        return 0;//braket: begin
    case 4:
        return 0;//braket: end
    case 5:
        return 0;//braket: range
    case 6:
        return 1;//superscript: star
    case 7:
        return 1;//superscript: plus
    case 8:
        return 1;//superscript: ZeroOrOne
    case 9:
        return 2;//char: reserved
    case 10:
        return 2;//char: CommonChar
    case 11:
        return 3;//Or: Or
    }
    return -1;
}

struct Retree
{
    enum type
    {
        accept = 0,
        error = 1,
        push = 2,
        reduce = 3,
    };
    static const size_t StateCount;
    static const size_t NonTerminalCount;
    static const size_t TerminalCount;
    static const size_t RulesCount;
    static const int GOTO[23][7];
    static const int ACTION[23][12];
    static const int RulesToSymbol[15];
    static const int RulesLength[15];
};
const size_t Retree::StateCount = 23;
const size_t Retree::NonTerminalCount = 7;
const size_t Retree::TerminalCount = 11;
const size_t Retree::RulesCount = 15;
const int Retree::GOTO[23][7] = { \
{1, 6, 10, 14, 18, 22, 26}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 78, 18, 22, 26}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 62, 10, 14, 18, 22, 26}, \
{1, 1, 1, 1, 1, 1, 46}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 54}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 74, 14, 18, 22, 26}, \
{1, 1, 1, 78, 18, 22, 26}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1} };
//==============================
const int Retree::ACTION[23][12] = { \
{30, 1, 34, 1, 1, 1, 1, 1, 38, 42, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 70, 0}, \
{30, 7, 34, 1, 1, 1, 1, 1, 38, 42, 7, 7}, \
{15, 15, 15, 1, 1, 82, 86, 90, 15, 15, 15, 15}, \
{23, 23, 23, 1, 1, 23, 23, 23, 23, 23, 23, 23}, \
{39, 39, 39, 1, 1, 39, 39, 39, 39, 39, 39, 39}, \
{47, 47, 47, 1, 1, 47, 47, 47, 47, 47, 47, 47}, \
{30, 1, 34, 1, 1, 1, 1, 1, 38, 42, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 38, 42, 1, 1}, \
{55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55, 55}, \
{59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59, 59}, \
{1, 1, 1, 1, 50, 1, 1, 1, 1, 1, 1, 1}, \
{1, 1, 1, 1, 1, 1, 1, 1, 38, 42, 1, 1}, \
{1, 1, 1, 58, 1, 1, 1, 1, 1, 1, 1, 1}, \
{51, 51, 51, 1, 1, 51, 51, 51, 51, 51, 51, 51}, \
{1, 66, 1, 1, 1, 1, 1, 1, 1, 1, 70, 1}, \
{43, 43, 43, 1, 1, 43, 43, 43, 43, 43, 43, 43}, \
{30, 1, 34, 1, 1, 1, 1, 1, 38, 42, 1, 1}, \
{30, 11, 34, 1, 1, 1, 1, 1, 38, 42, 11, 11}, \
{19, 19, 19, 1, 1, 82, 86, 90, 19, 19, 19, 19}, \
{31, 31, 31, 1, 1, 31, 31, 31, 31, 31, 31, 31}, \
{27, 27, 27, 1, 1, 27, 27, 27, 27, 27, 27, 27}, \
{35, 35, 35, 1, 1, 35, 35, 35, 35, 35, 35, 35} };
//==============================
const int Retree::RulesToSymbol[15] = { \
0,\
1,\
1,\
2,\
2,\
3,\
3,\
3,\
3,\
4,\
4,\
5,\
5,\
6,\
6 };
//==============================
const int Retree::RulesLength[15] = { \
1,\
1,\
3,\
1,\
2,\
1,\
2,\
2,\
2,\
1,\
3,\
1,\
5,\
1,\
1 };


void RegTree::build(const char* reg)
{
    BufferChar input;
    input = reg;
    build(input);
}
void RegTree::build(BufferChar& input)
{
    BufferChar result;
    //BufferChar input;
    BufferChar intermediate;
    Morpheme eme;
    size_t head;
    list<int> stack;
    list<RegTree*> SrcTree;
    RegTree* L, * R, * M;
    int top;
    int information, temp;
    Retree::type type;
    size_t length, i, begin_;
    int accept, symbol;
    bool DoNext;
    char now;
    int GoFull, GoD, GoI;
    bool demo_buttom;
    demo_buttom = false;
    tree.clear();
    while (RunBuild(accept, result, input, intermediate))
    {
        if (accept != 0) eme.append(result, accept, GroupGet_Reg(accept));
        else
        {
            input.dequeue(now);
            result.append(now);
            eme.append(result, 0, GroupGet_Reg(0));
        }
    }
    eme.AppendEnd(Retree::TerminalCount + 1);
    if (demo_buttom)  eme.Demo(stdout);
    stack.append(0);
    SrcTree.append(NULL);
    head = 0;
    DoNext = true;
    do
    {
        top = stack.top();
        temp = Retree::ACTION[top][eme[head].accept - 1];
        information = temp / 4;
        type = (Retree::type)(temp % 4);

        if (demo_buttom)fprintf(stdout, "\n\nT = %5d, top = %5d, information = %5d, type = %5d, ", eme[head].accept - 1, top, information, (int)type);
        if (demo_buttom)fprintf(stdout, "head = %5zu, lex = %s, ", head, eme.GetWord(head));
        if (demo_buttom)fprintf(stdout, "stack.count() = %5zu, top = %5zu\n//================================\n", stack.count(), SrcTree.count());
        for (i = 0; (i < stack.count()) && demo_buttom; i++)
        {
            fprintf(stdout, "%5d, ", stack[i]);
            if (SrcTree[i] == NULL)
                fprintf(stdout, "SrcTree[%5zu]: NULL\n", i);
            else
            {
                fprintf(stdout, "SrcTree[%5zu]: ", i);
                SrcTree[i]->Demo(stdout);
                fprintf(stdout, "\n");
            }
        }
        switch (type)
        {
        case Retree::accept:
            if (demo_buttom)SrcTree[SrcTree.count() - 1]->Demo(stdout);
            tree.move(SrcTree[SrcTree.count() - 1]->tree);
            for (i = 0; i < SrcTree.count(); i++) delete SrcTree[i];
            DoNext = false;
            break;
        case Retree::error:
            DoNext = false;
            break;
        case Retree::push:
            stack.append(information);
            M = new RegTree;
            M->grow(eme.GetChar(head));
            SrcTree.append(M);
            if (demo_buttom) fprintf(stdout, "\tchar = %c\n", eme.GetChar(head));
            head += 1;
            break;
        case Retree::reduce:
            symbol = Retree::RulesToSymbol[information];
            length = Retree::RulesLength[information];
            begin_ = SrcTree.count() - length;
            if (demo_buttom) fprintf(stdout, "\tsymbol = %5d, length = %5zu, begin_ = %5zu\n", symbol, length, begin_);
            switch (information)
            {
                //No[0], case Ep: prefix: 0, degeneracy: 1
            case 0: //0: Ep, No[0] production rules: Ep->RegOr
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
                //No[1], case RegOr: prefix: 1, degeneracy: 2
            case 1: //1: RegOr, No[0] production rules: RegOr->Reg
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 2: //1: RegOr, No[1] production rules: RegOr->Reg Or Reg
                M = new RegTree;
                M->grow(SrcTree[begin_], SrcTree[begin_ + 2], RegTree::Alternation);
                break;
                //No[2], case Reg: prefix: 3, degeneracy: 2
            case 3: //2: Reg, No[0] production rules: Reg->Complex
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 4: //2: Reg, No[1] production rules: Reg->Complex Reg
                M = new RegTree;
                M->grow(SrcTree[begin_], SrcTree[begin_ + 1], RegTree::Concatenation);
                break;
                //No[3], case Complex: prefix: 5, degeneracy: 4
            case 5: //3: Complex, No[0] production rules: Complex->Node
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 6: //3: Complex, No[1] production rules: Complex->Complex plus
                M = new RegTree;
                M->grow(SrcTree[begin_], RegTree::OneOrMore);
                break;
            case 7: //3: Complex, No[2] production rules: Complex->Complex star
                M = new RegTree;
                M->grow(SrcTree[begin_], RegTree::ZeroOrMore);
                break;
            case 8: //3: Complex, No[3] production rules: Complex->Complex ZeroOrOne
                M = new RegTree;
                M->grow(SrcTree[begin_], RegTree::ZeroOrOne);
                break;
                //No[4], case Node: prefix: 9, degeneracy: 2
            case 9: //4: Node, No[0] production rules: Node->Range
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 10: //4: Node, No[1] production rules: Node->left RegOr right
                M = SrcTree[begin_ + 1];
                SrcTree[begin_ + 1] = NULL;
                break;
                //No[5], case Range: prefix: 11, degeneracy: 2
            case 11: //5: Range, No[0] production rules: Range->Char
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 12: //5: Range, No[1] production rules: Range->begin Char range Char end
                M = new RegTree;
                L = SrcTree[begin_ + 1];
                R = SrcTree[begin_ + 3];
                M->grow(L->tree[L->tree.Head].content.lower, R->tree[R->tree.Head].content.upper);
                break;
                //No[6], case Char: prefix: 13, degeneracy: 2
            case 13: //6: Char, No[0] production rules: Char->reserved
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            case 14: //6: Char, No[1] production rules: Char->CommonChar
                M = SrcTree[begin_];
                SrcTree[begin_] = NULL;
                break;
            }
            for (i = 0; i < length; i++) stack.pop();
            for (i = 0; i < length; i++) delete SrcTree[begin_ + i];
            for (i = 0; i < length; i++) SrcTree.pop();
            GoFull = Retree::GOTO[stack.top()][symbol];
            GoD = GoFull / 4;
            GoI = GoFull % 4;
            stack.append(GoD);
            SrcTree.append(M);
            if (demo_buttom)fprintf(stdout, "\tGOTO[%5d][%5d] = (%5d, %5d)\n", stack.top(), symbol, GoD, GoI);
            break;
        }
    } while (DoNext);

    //for (i = 0; i < eme.GetCount(); i++)
    //{
    //	top;
    //}
    //size_t i;
    //fprintf(stdout, "count = %zu\n", eme.GetCount());
    //for (i = 0; i < eme.GetCount(); i++)
    //{
    //	fprintf(stdout, "<%d : %d, %s>\n", eme.GetCategory(i), eme.GetAccept(i), eme.GetWord(i));
    //}
}
bool RegTree::RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate)
{
    /*
    example:
    1 aa
    2 aaBB
    3 Bcc
    input: aaBcc
    */
    char now;
    //char cc;
    int state, acc;
    int action;
    intermediate.clear();
    state = 0;
    acc = 0;
    action = 0;
    accept = 0;
    result.clear();
    while (input.dequeue(now))
    {
        /*state switch*/
        /*change here to get a different automata*/
        state = next_Reg(state, now);
        acc = action_Reg(state);
        /*change here to get a different automata*/
        accept = acc != 0 ? acc : accept;
        switch (action)
        {
        case 0://initial
            if (state != 0 && acc == 0)
            {
                intermediate.append(now);
                action = 1;
            }
            else if (state != 0 && acc != 0)
            {
                result.append(now);
                action = 2;
            }
            else
            {
                input.backspace(now);
                return true;
            }
            break;
        case 1://run and waiting for accept
            if (state == 0)
            {
                input.backspace(now);
                input.backspace(intermediate);
                return true;
            }
            else if (acc != 0)
            {
                result.append(intermediate);
                result.append(now);
                intermediate.clear();
                action = 2;
            }
            else intermediate.append(now);//continue 
            break;
        case 2://accept
            if (state == 0)//accept
            {
                input.backspace(now);
                //accept = last;
                return true;
            }
            else if (acc == 0)
            {
                intermediate.append(now);
                action = 1;
            }
            else result.append(now);
            break;
        }
    }
    if (action == 1)
        input.backspace(intermediate);
    return action != 0;
}

void RegTree::grow(const RegTree* reg, NodeType T)
{
    size_t site;
    tree.clear();
    site = tree.NewNodeOffset();
    tree.SetHead(site);
    tree.append(reg->tree, site);
    tree[site].content.type = T;
}
void RegTree::grow(const RegTree* regL, const RegTree* regR, NodeType T)
{
    size_t site;
    tree.clear();
    site = tree.NewNodeOffset();
    tree.SetHead(site);
    tree.append(regL->tree, regR->tree, site);
    tree[site].content.type = T;
}
void RegTree::grow(char C)
{
    grow(C, C);
}
void RegTree::grow(char L, char U)
{
    size_t site;
    tree.clear();
    site = tree.NewNodeOffset();
    tree.SetHead(site);
    value(site, L, U);
}
void RegTree::value(const RegTree* reg)
{
    size_t site;
    buffer<size_t> output;
    list<size_t> s;

    //std::cout << "\n\n====++++++====== " << std::endl;
    //reg->Demo(stdout);
    //std::cout << "\ntree.clear();" << std::endl;
    tree.clear();
    //std::cout << "site = tree.append(reg->tree, output, s);" << std::endl;
    tree.append(reg->tree, output, s, site);
    //std::cout << "tree.SetHead(site);" << std::endl;
    tree.SetHead(site);

    //std::cout << "\nsite: "<< site << std::endl;
    //Demo(stdout);
    //std::cout << "\n=============== \n" << std::endl;
}

void RegTree::Reserved(const char* res)
{
    size_t i, length, inner, remain, L, R, parent;
    tree.clear();
    tree.SetHead(0);
    for (length = 0; res[length] != '\0'; length++);
    for (i = 0; i < length * 2 - 1; i++)
        tree.NewNodeOffset();
    parent = length - 1;
    for (i = 0; i < length; i++)
        value(i + parent, res[i]);
    inner = 0;
    remain = parent;
    while (remain > 1)
    {
        remain >>= 1;
        inner <<= 1;
        inner += 1;
    }
    remain = parent - inner;
    //std::cout << "void RegTree::Reserved(" << res << ");" << std::endl;
    //std::cout << "Binary representation of parent = " << parent << " is: ";
    //std::cout << std::bitset<sizeof(parent) * 8> (parent) << std::endl;
    //std::cout << "Binary representation of inner = " << inner << " is: ";
    //std::cout << std::bitset<sizeof(inner) * 8>(inner) << std::endl;
    //std::cout << "remain = " << remain << std::endl;
    for (i = 0; i < parent; i++)
    {
        //site = length - 2 - i;
        //link(site, last - 1, last, Concatenation);
        //last -= 2;
        L = 2 * i + 1;
        R = 2 * i + 2;
        if (R < parent)
            link(i, L, R, Concatenation);
        else if (R == parent) link(i, L, R + remain * 2, Concatenation);
        else if (i < inner) link(i, L + remain * 2, R + remain * 2, Concatenation);
        else link(i, 2 * (i - inner) + parent, 2 * (i - inner) + length, Concatenation);
    }
}
void RegTree::Int(void)
{
    size_t i;
    tree.clear();
    tree.SetHead(0);
    for (i = 0; i < 7; i++)
        tree.NewNodeOffset();
    tree[0].left = 1;
    tree[0].right = 2;
    tree[1].left = 3;
    tree[2].left = 6;

    tree[3].left = 4;
    tree[3].right = 5;

    tree[0].content.type = Concatenation;
    tree[1].content.type = ZeroOrOne;
    tree[2].content.type = OneOrMore;
    tree[3].content.type = Alternation;

    value(4, '-');
    value(5, '+');
    value(6, '0', '9');
}
void RegTree::value(size_t site, char LU)
{
    value(site, LU, LU);
}
void RegTree::value(size_t site, char L, char U)
{
    tree[site].content.type = Range;
    tree[site].content.lower = L;
    tree[site].content.upper = U;
}
void RegTree::link(size_t site, size_t L, size_t R, RegTree::NodeType T)
{
    tree[site].left = L;
    tree[site].right = R;
    tree[site].content.type = T;
}
void RegTree::link(size_t site, size_t L, NodeType T)
{
    tree[site].left = L;
    tree[site].right = SizeMax;
    tree[site].content.type = T;
}
void RegTree::Identifier(void)
{
    size_t i;
    tree.clear();
    tree.SetHead(0);
    for (i = 0; i < 14; i++)
        tree.NewNodeOffset();
    link(0, 1, 6, Concatenation);
    link(1, 2, 5, Alternation);
    link(2, 3, 4, Alternation);
    value(3, 'a', 'z');
    value(4, 'A', 'Z');
    value(5, '_');

    link(6, 7, ZeroOrMore);
    link(7, 8, 9, Alternation);
    link(8, 10, 11, Alternation);
    link(9, 12, 13, Alternation);
    value(10, 'a', 'z');
    value(11, 'A', 'Z');
    value(12, '_');
    value(13, '0', '9');
}
void RegTree::IdentifierHead(void)
{
    RegTree* left, * right, * middle;
    left = new RegTree();
    left->grow('a', 'z');
    right = new RegTree();
    right->grow('A', 'Z');
    middle = new RegTree();
    //left->Demo(stdout);
    //right->Demo(stdout);
    //std::cout << "\nmiddle = new RegTree();\n" << std::endl;
    middle->grow(left, right, Alternation);
    //std::cout << "grow(left, right, Alternation);\n\n" << std::endl;
    //middle->Demo(stdout);
    delete left;
    left = middle;
    right->grow('_', '_');
    grow(left, right, Alternation);
    delete right;
    delete left;
}
void RegTree::IdentifierInner(void)
{
    RegTree* left, * right, * middle, * temp;
    left = new RegTree();
    left->grow('a', 'z');
    right = new RegTree();
    right->grow('A', 'Z');
    middle = new RegTree();
    temp = new RegTree();
    middle->grow(left, right, Alternation);
    left->grow('_', '_');
    right->grow('0', '9');
    temp->grow(left, right, Alternation);
    grow(middle, temp, Alternation);
    delete right;
    delete left;
    delete temp;
    delete middle;
}
void RegTree::ConstChar(void)
{
    RegTree LR, ESC, common__;
    RegTree temp1, temp2;
    LR.grow('\'', '\'');
    ESC.EscapeAll();
    common__.CommonChar();

    temp2.grow(&ESC, &common__, Alternation);
    temp1.grow(&LR, &temp2, Concatenation);
    grow(&temp1, &LR, Concatenation);
    //temp1.grow('', '');
}
void RegTree::CommonChar(void)
{
    RegTree range1, range2, range3, range4, range5;
    RegTree temp1, temp2, temp3;
    range1.grow(' ', '!');//32, 33 34:"
    range2.grow('#', '&');//35, 38 39:'
    range3.grow('(', '/');//40, 47
    range4.grow('0', '[');//48, 91 92: '\\'
    range5.grow(']', '~');//93, 126

    temp1.grow(&range1, &range2, Alternation);
    temp2.grow(&range3, &range4, Alternation);
    temp3.grow(&temp1, &temp2, Alternation);
    grow(&temp3, &range5, Alternation);
}
void RegTree::EscapeAll(void)
{
    RegTree all__, ESC, Octa, Hexa, num;
    Hexa.HexaChar();
    Octa.OctaChar();
    ESC.EscapeChar();
    num.grow(&Octa, &Hexa, Alternation);
    all__.grow(&num, &ESC, Alternation);
    ESC.grow('\\', '\\');
    grow(&ESC, &all__, Concatenation);
}
void RegTree::EscapeChar(void)
{
    int ele;
    bool temp;
    RegTree temp1, temp2, temp3;
    temp = false;
    for (ele = 0; (size_t)ele < CharSize; ele++)
    {
        if (PostfixSwitch((char)ele) == -1) continue;
        //std::cout << "ele: " << ele << std::endl;
        temp1.grow((char)ele, (char)ele);
        //std::cout << "ele: " << (char)ele << std::endl;
        if (temp)
        {
            //std::cout << "temp1.Demo(stdout);"  << std::endl;
            //temp1.Demo(stdout);
            //std::cout << "\ntemp2.Demo(stdout);" << std::endl;
            //temp2.Demo(stdout);
            //std::cout << "\ntemp3.grow(&temp1, &temp2, Alternation);" << std::endl;
            temp3.grow(&temp1, &temp2, Alternation);
            //std::cout << "temp3.tree.Demo(stdout);" << std::endl;
            //temp3.tree.Demo(stdout);
            //std::cout << "temp3.Demo(stdout);" << std::endl;
            //temp3.Demo(stdout);

            //std::cout << "\ntemp2.value(&temp3);"  << std::endl;
            temp2.value(&temp3);

        }
        else
        {
            temp2.value(&temp1);
            temp = !temp;
        }
        //std::cout << "end"<< std::endl;
    }
    value(&temp2);
}
void RegTree::HexaChar(void)
{
    RegTree temp1, temp2, temp3, temp4;
    temp1.grow('0', '9');
    temp2.grow('a', 'f');
    temp3.grow(&temp1, &temp2, Alternation);
    temp2.grow('A', 'F');
    temp1.grow(&temp3, &temp2, Alternation);
    temp3.grow(&temp1, &temp1, Concatenation);
    temp4.grow(&temp3, &temp1, Alternation);
    temp1.grow('x', 'x');
    temp2.grow('X', 'X');
    temp3.grow(&temp1, &temp2, Alternation);
    grow(&temp3, &temp4, Concatenation);
}
void RegTree::OctaChar(void)
{
    RegTree temp1, temp2, temp3, temp4;
    temp1.grow('0', '7');
    temp2.grow(&temp1, &temp1, Concatenation);
    temp3.grow(&temp2, &temp1, Concatenation);
    temp4.grow(&temp1, &temp2, Alternation);
    grow(&temp3, &temp4, Alternation);
}
void RegTree::swap(const RegTree*& regL, const RegTree*& regR)
{
    const RegTree* middle;
    middle = regL;
    regL = regR;
    regR = middle;
    return;
}
void RegTree::spaces(void)
{
    size_t i;
    tree.clear();
    tree.SetHead(0);
    for (i = 0; i < 2; i++)
        tree.NewNodeOffset();
    link(0, 1, OneOrMore);
    value(1, ' ');
}
void RegTree::LineFeeds(void)
{
    size_t i;
    tree.clear();
    tree.SetHead(0);
    for (i = 0; i < 6; i++)
        tree.NewNodeOffset();
    link(0, 1, OneOrMore);
    link(1, 2, 3, Alternation);
    link(3, 4, 5, Concatenation);
    value(2, '\n');
    value(4, '\r');
    value(5, '\n');
}
void RegTree::Demo(FILE* fp) const
{
    //tree.inorderTraversal(output);
    list<traverse> s;
    traverse temp;
    NodeType T;
    char U, L;
    temp.site = tree.Head;
    temp.state = 0;
    if (temp.site != SizeMax)s.append(temp);
    while (s.count())
    {
        switch (s.top().state)
        {
        case 0:
            if (tree[s.top().site].content.type == Alternation && s.top().site != 0)
                fputc('(', fp);
            s.top().state = 1;
            temp.site = tree[s.top().site].left;
            if (temp.site != SizeMax)
            {
                //fprintf(fp, "\n   temp.site: %llu, s.top().site: %llu  \n", temp.site, s.top().site);
                s.append(temp);
                break;
            }

        case 1:
            T = tree[s.top().site].content.type;
            if (T == Alternation)
                fputc('|', fp);
            else if (T == OneOrMore)
                fprintf(fp, "^{+}");
            else if (T == ZeroOrMore)
                fprintf(fp, "^{*}");
            else if (T == ZeroOrOne)
                fputc('?', fp);
            else if (T == Range)
            {
                U = tree[s.top().site].content.upper;
                L = tree[s.top().site].content.lower;
                if (U != L)
                {
                    if ((int)L < 32 || (int)L == 127) fprintf(fp, "[\'\\%d\'-", (int)L);
                    else fprintf(fp, "[\'%c\'-", L);
                    if ((int)U < 32 || (int)U == 127) fprintf(fp, "\'\\%d\']", (int)U);
                    else fprintf(fp, "\'%c\']", U);
                }
                else
                {
                    if ((int)L < 32 || (int)L == 127) fprintf(fp, "[\'\\%d\']", (int)L);
                    else fprintf(fp, "\'%c\'", L);
                }

            }
            s.top().state = 2;
            temp.site = tree[s.top().site].right;
            if (temp.site != SizeMax)
            {
                s.append(temp);
                break;
            }
        case 2:
            if (tree[s.top().site].content.type == Alternation && s.top().site != 0)
                fputc(')', fp);
            s.pop();
            break;
        }
    }
}
void RegTree::Demo(FILE* fp, RegTree::NodeType T)
{
    switch (T)
    {
    case RegTree::Concatenation:
        fprintf(fp, "Concatenation\n");
        break;
    case RegTree::Alternation:
        fprintf(fp, "Alternation\n");
        break;
    case RegTree::ZeroOrMore:
        fprintf(fp, "ZeroOrMore\n");
        break;
    case RegTree::OneOrMore:
        fprintf(fp, "OneOrMore\n");
        break;
    case RegTree::ZeroOrOne:
        fprintf(fp, "ZeroOrOne\n");
        break;
    case RegTree::Range:
        fprintf(fp, "Range\n");
        break;
    default:
        fprintf(fp, "???????????\n");
        break;
    }
}
void RegTree::Demo(FILE* fp, char L, char U)
{
    if (U != L)
    {
        if ((int)L < 32 || (int)L == 127) fprintf(fp, "[\\%d-", (int)L);
        else fprintf(fp, "[%c-", L);
        if ((int)U < 32 || (int)U == 127) fprintf(fp, "\\%d]", (int)U);
        else fprintf(fp, "%c]", U);
    }
    else
    {
        if ((int)L < 32 || (int)L == 127) fprintf(fp, "[\\%d]", (int)L);
        else fputc(L, fp);
    }
}

void RegTree::info::Demo(FILE* fp) const
{
    RegTree::Demo(fp, lower, upper);
    RegTree::Demo(fp, type);
}

static bool compare(const char* str1, const char* str2);
static size_t strlength(const char* str);
static void strfree(const char** strs, size_t length);
static void inverse(list<size_t>& out, const list<size_t>& in);
static int PostfixSwitch_small(char c);
static const char* Copy(const char* input)
{
    char* nnnn;
    size_t length, i;
    for (length = 0; input[length] != '\0'; length++);
    length += 1;
    nnnn = (char*)malloc(sizeof(char) * length);
    for (i = 0; i < length; i++) nnnn[i] = input[i];
    return nnnn;
}
lexicalPanel::lexicalPanel()
{
    nfa = NULL;
    DFAsheet = NULL;
    DFAgraph = NULL;
    /*
    count = 0;
    capacity = 0;
    reg = NULL;
    name = NULL;
    attribute = NULL;
    priority = NULL;
    */
}
lexicalPanel::~lexicalPanel()
{
    size_t i;
    for (i = 0; i < regular.count(); i++)
        delete regular[i];
    delete nfa;
    delete DFAsheet;
    delete DFAgraph;

    for (i = 0; i < attribute.count(); i++)
    {
        free((void*)attribute[i]);
    }

    /*
    for (i = 0; i < count; i++)
    {
        delete reg[i];
        free((void*)name[i]);
        free((void*)attribute[i]);
    }
    free((void*)priority);
    free((void*)name);
    free((void*)attribute);
    free((void*)reg);
    */
}
const char** lexicalPanel::GetName(void) const
{
    const char** name;
    size_t i;
    name = (const char**)malloc(regular.count() * sizeof(const char*));
    for (i = 0; i < regular.count(); i++)
    {
        name[i] = Copy(regular[i]->name);
    }
    return name;
}
const char** lexicalPanel::GetAttribute(void) const
{
    const char** atrribute;
    size_t i;
    atrribute = (const char**)malloc(regular.count() * sizeof(const char*));
    for (i = 0; i < regular.count(); i++)
    {
        atrribute[i] = Copy(regular[i]->attribute);
    }
    return atrribute;
}
/*
void lexicalPanel::expand(void)
{
    size_t newCapacity;

    newCapacity = (capacity + capacity / 4 + 8);

    priority = (size_t*)realloc(priority, newCapacity * sizeof(size_t));
    name = (const char**)realloc(name, newCapacity * sizeof(const char*));
    attribute = (const char**)realloc(attribute, newCapacity * sizeof(const char*));
    reg = (RegTree**)realloc(reg, newCapacity * sizeof(RegTree*));

    capacity = newCapacity;

}
void lexicalPanel::append(const char* Name, const char* Attri, RegTree* Reg, size_t Priority)
{
    if (count >= capacity) expand();
    name[count] = Copy(Name);
    attribute[count] = Copy(Attri);
    reg[count] = Reg;
    priority[count] = Priority;
    count += 1;
}*/
lexicalPanel::infor::infor()
{
    priority = 0;
    reg = NULL;
    name = NULL;
    attribute = NULL;
    group = 0;
}
lexicalPanel::infor::~infor()
{

    delete reg;
    reg = NULL;
    free((void*)name);
    free((void*)attribute);


}
void lexicalPanel::infor::SetName(const char* input)
{
    name = Copy(input);
}
void lexicalPanel::infor::SetAttribute(const char* input)
{
    attribute = Copy(input);
}
void lexicalPanel::build(void)
{
    SetAll();
    //nfa = new NFA(*this);
    DFAsheet = new sheetDFA(*nfa);
    DFAsheet->shrink();
    DFAgraph = new DFA(DFAsheet);

    //ddfa->Demo(stdout);
}
void lexicalPanel::BuildDemo(FILE* fp)
{
    SetAll();
    fprintf(fp, "================nfa = new NFA(*this);=================\n");
    //nfa = new NFA(*this);
    nfa->Demo(stdout);
    fprintf(fp, "===========DFAsheet = new sheetDFA(*nfa);=============\n");
    DFAsheet = new sheetDFA(*nfa);
    DFAsheet->Demo(stdout);
    fprintf(fp, "=================DFAsheet->shrink();==================\n");
    DFAsheet->shrink();
    DFAsheet->Demo(stdout);
    fprintf(fp, "============DFAgraph = new DFA(DFAsheet);=============\n");
    DFAgraph = new DFA(DFAsheet);
    DFAgraph->Demo(stdout);
    size_t i;
    fprintf(fp, "%s", regular[0]->name);
    for (i = 1; i < regular.count(); i++)
    {
        fprintf(fp, " | %s", regular[i]->name);
    }
    fprintf(fp, "\n");
}

void lexicalPanel::Cprint(FILE* fp, const char* name)
{
    const char** Atrribute__;
    const char** Name__;
    Name__ = GetName();
    Atrribute__ = GetAttribute();
    DFAgraph->Cprint(fp, name);
    DFAgraph->CprintAccept(fp, name, Atrribute__, Name__);

    Cgroup(fp, name);
    strfree(Atrribute__, regular.count());
    strfree(Name__, regular.count());
}
void lexicalPanel::CppPrint(FILE* fp, const char* name)
{
    size_t i;
    const char** Atrribute__;
    const char** Name__;
    Name__ = GetName();
    Atrribute__ = GetAttribute();
    fprintf(fp, "struct %s\n{\n", name);
    fprintf(fp, "\tenum regular\n\t{\n");
    //fprintf(fp, "\t\tnull = %zu,", 0);
    fprintf(fp, "\t\t_%s_ = %zu", regular[0]->name, (size_t)1);
    for (i = 1; i < regular.count(); i++)
    {
        fprintf(fp, ",\n\t\t_%s_ = %zu", regular[i]->name, i + 1);
    }
    fprintf(fp, "\n\t};\n");
    fprintf(fp, "\tenum group\n\t{\n");
    fprintf(fp, "\t\t_%s___ = %zu", attribute[0], (size_t)1);
    for (i = 1; i < attribute.count(); i++)
    {
        fprintf(fp, ",\n\t\t_%s___ = %zu", attribute[i], i + 1);
    }
    fprintf(fp, "\n\t};\n");
    fprintf(fp, "\tstatic int next(int state, const char c);\n");
    fprintf(fp, "\tstatic int action(int state);\n");
    fprintf(fp, "\tstatic int GroupGet(int state);\n");
    fprintf(fp, "};\n");


    DFAgraph->CppPrint(fp, name);
    DFAgraph->CppPrintAccept(fp, name, Atrribute__, Name__);
    CppGroup(fp, name);
    strfree(Atrribute__, regular.count());
    strfree(Name__, regular.count());
}


void lexicalPanel::SetGrammer(void)
{
    infor* II;

    II = new infor;
    II->SetAttribute("division");
    II->SetName("|");
    II->reg = new RegTree();
    II->reg->Reserved("|");
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("spaces");
    II->reg = new RegTree();
    II->reg->spaces();
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("enters");
    II->reg = new RegTree();
    II->reg->LineFeeds();
    regular.append(II);

    II = new infor;
    II->SetAttribute("arrow");
    II->SetName("->");
    II->reg = new RegTree();
    II->reg->Reserved("->");
    regular.append(II);

    II = new infor;
    II->SetAttribute("ID");
    II->SetName("Identifiers");
    II->reg = new RegTree();
    II->reg->Identifier();
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName(";");
    II->reg = new RegTree();
    II->reg->Reserved(";");
    regular.append(II);



}
void lexicalPanel::SetReg(void)
{
    infor* II;

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("left");
    II->reg = new RegTree();
    II->reg->Reserved("(");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("right");
    II->reg = new RegTree();
    II->reg->Reserved(")");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("begin");
    II->reg = new RegTree();
    II->reg->Reserved("[");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("end");
    II->reg = new RegTree();
    II->reg->Reserved("]");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("range");
    II->reg = new RegTree();
    II->reg->Reserved("-");
    regular.append(II);

    II = new infor;
    II->SetAttribute("superscript");
    II->SetName("star");
    II->reg = new RegTree();
    II->reg->Reserved("*");
    regular.append(II);

    II = new infor;
    II->SetAttribute("superscript");
    II->SetName("plus");
    II->reg = new RegTree();
    II->reg->Reserved("+");
    regular.append(II);

    II = new infor;
    II->SetAttribute("superscript");
    II->SetName("ZeroOrOne");
    II->reg = new RegTree();
    II->reg->Reserved("?");
    regular.append(II);

    II = new infor;
    II->SetAttribute("char");
    II->SetName("idchar");
    II->priority = 1;
    II->reg = new RegTree();
    II->reg->IdentifierInner();
    regular.append(II);

    II = new infor;
    II->SetAttribute("char");
    II->SetName("CommonChar");
    II->reg = new RegTree();
    II->reg->ConstChar();
    regular.append(II);

    II = new infor;
    II->SetAttribute("Or");
    II->SetName("Or");
    II->reg = new RegTree();
    II->reg->Reserved("|");
    regular.append(II);
}
void lexicalPanel::SetRegS(void)
{
    infor* II;

    II = new infor;
    II->SetAttribute("Id");
    II->SetName("identifier");
    II->reg = new RegTree();
    II->reg->Identifier();
    regular.append(II);

    II = new infor;
    II->SetAttribute("number");
    II->SetName("integar");
    II->reg = new RegTree();
    II->reg->build("\'+\'?[0-9]+");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetName("lexical");
    II->SetAttribute("reserved_word");
    II->reg = new RegTree();
    II->reg->build("lexical");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetName("grammatical");
    II->SetAttribute("reserved_word");
    II->reg = new RegTree();
    II->reg->build("grammatical");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetName("formula");
    II->SetAttribute("reserved_word");
    II->reg = new RegTree();
    II->reg->build("formula");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetName("priority");
    II->SetAttribute("reserved_word");
    II->reg = new RegTree();
    II->reg->build("priority");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetName("void");
    II->SetAttribute("reserved_word");
    II->reg = new RegTree();
    II->reg->build("void");
    II->priority = 1;
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("spaces");
    II->reg = new RegTree();
    II->reg->spaces();
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("enters");
    II->reg = new RegTree();
    II->reg->LineFeeds();
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("semicolon");
    II->reg = new RegTree();
    II->reg->Reserved(";");
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("colon");
    II->reg = new RegTree();
    II->reg->Reserved(":");
    regular.append(II);

    II = new infor;
    II->SetAttribute("division");
    II->SetName("dot");
    II->reg = new RegTree();
    II->reg->Reserved(".");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("braceL");
    II->reg = new RegTree();
    II->reg->Reserved("{");
    regular.append(II);

    II = new infor;
    II->SetAttribute("braket");
    II->SetName("braceR");
    II->reg = new RegTree();
    II->reg->Reserved("}");
    regular.append(II);

    II = new infor;
    II->SetAttribute("annotation");
    II->SetName("anntationS");
    II->reg = new RegTree();
    II->reg->build("\'/\'\'/\'([\'\\0\'-\'\\11\']|[\'\\13\'-\'\\177\'])*\'\\n\'");
    regular.append(II);

    II = new infor;
    II->SetAttribute("annotation");
    II->SetName("anntationM");
    II->reg = new RegTree();
    II->reg->build("\'/\'\'*\'([\'\\0\'-\'\\177\'])*\'*\'+\'/\'");/**///
    regular.append(II);

    SetReg();
}
void lexicalPanel::SetRegFinal(void)
{
    infor* II;
    //identifier: identifier
    {
        II = new infor;
        II->SetAttribute("identifier");
        II->SetName("identifier");
        II->reg = new RegTree();
        II->priority = 1;
        II->reg->Identifier();
        regular.append(II);
    }
    //const: integar, CommonChar, idChar
    {
        II = new infor;
        II->SetAttribute("const");
        II->SetName("integar");
        II->reg = new RegTree();
        II->reg->build("\'+\'[0-9]+");//group (\'+\'|\'-\')?[0-9]+
        II->priority = 3;
        regular.append(II);

        II = new infor;
        II->SetAttribute("const");
        II->SetName("CommonChar");
        II->reg = new RegTree();
        II->reg->ConstChar();
        regular.append(II);

        II = new infor;
        II->SetAttribute("const");
        II->SetName("idChar");
        II->priority = 2;
        II->reg = new RegTree();
        II->reg->IdentifierInner();
        regular.append(II);


    }
    //reserved: lexical, grammar, void, all
    {
        II = new infor;
        II->SetName("lexical");
        II->SetAttribute("reserved");
        II->reg = new RegTree();
        II->reg->build("lexical");
        II->priority = 4;
        regular.append(II);

        II = new infor;
        II->SetName("grammar");
        II->SetAttribute("reserved");
        II->reg = new RegTree();
        II->reg->build("grammar");
        II->priority = 4;
        regular.append(II);

        II = new infor;
        II->SetName("void");
        II->SetAttribute("reserved");
        II->reg = new RegTree();
        II->reg->build("void");
        II->priority = 4;
        regular.append(II);

        II = new infor;
        II->SetName("all");
        II->SetAttribute("reserved");
        II->reg = new RegTree();
        II->reg->build("all");
        II->priority = 4;
        regular.append(II);
    }
    //format: spaces, enters, tab
    {
        II = new infor;
        II->SetAttribute("format");
        II->SetName("spaces");
        II->reg = new RegTree();
        II->reg->spaces();
        regular.append(II);

        II = new infor;
        II->SetAttribute("format");
        II->SetName("enters");
        II->reg = new RegTree();
        II->reg->LineFeeds();
        regular.append(II);

        II = new infor;
        II->SetAttribute("format");
        II->SetName("tab");
        II->reg = new RegTree();
        II->reg->build("\'\\t\'");
        regular.append(II);
    }
    //division: semicolon, colon, dot
    {
        II = new infor;
        II->SetAttribute("division");
        II->SetName("semicolon");
        II->reg = new RegTree();
        II->reg->Reserved(";");
        regular.append(II);

        II = new infor;
        II->SetAttribute("division");
        II->SetName("colon");
        II->reg = new RegTree();
        II->reg->Reserved(":");
        regular.append(II);

        II = new infor;
        II->SetAttribute("division");
        II->SetName("dot");
        II->reg = new RegTree();
        II->reg->Reserved(".");
        regular.append(II);
    }
    //braket: braceL, braceR, left, right, squareL, squareR, angleL, angleR;
    {
        II = new infor;
        II->SetAttribute("braket");
        II->SetName("braceL");
        II->reg = new RegTree();
        II->reg->Reserved("{");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("braceR");
        II->reg = new RegTree();
        II->reg->Reserved("}");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("left");
        II->reg = new RegTree();
        II->reg->Reserved("(");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("right");
        II->reg = new RegTree();
        II->reg->Reserved(")");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("squareL");
        II->reg = new RegTree();
        II->reg->Reserved("[");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("squareR");
        II->reg = new RegTree();
        II->reg->Reserved("]");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("angleL");
        II->reg = new RegTree();
        II->reg->Reserved("<");
        regular.append(II);

        II = new infor;
        II->SetAttribute("braket");
        II->SetName("angleR");
        II->reg = new RegTree();
        II->reg->Reserved(">");
        regular.append(II);
    }
    //anntation: anntationS, anntationM
    {
        II = new infor;
        II->SetAttribute("annotation");
        II->SetName("anntationS");
        II->reg = new RegTree();
        II->reg->build("\'/\'\'/\'([\'\\0\'-\'\\11\']|[\'\\13\'-\'\\177\'])*\'\\n\'");
        regular.append(II);

        II = new infor;
        II->SetAttribute("annotation");
        II->SetName("anntationM");
        II->reg = new RegTree();
        II->reg->build("\'/\'\'*\'([\'\\0\'-\'\\177\'])*\'*\'+\'/\'");/**///
        regular.append(II);
    }
    //RegSymbol: range, star, plus, question, or;
    {
        II = new infor;
        II->SetAttribute("RegSymbol");
        II->SetName("range");
        II->reg = new RegTree();
        II->reg->Reserved("-");
        II->priority = 5;
        regular.append(II);

        II = new infor;
        II->SetAttribute("RegSymbol");
        II->SetName("star");
        II->reg = new RegTree();
        II->reg->Reserved("*");
        regular.append(II);

        II = new infor;
        II->SetAttribute("RegSymbol");
        II->SetName("plus");
        II->reg = new RegTree();
        II->reg->Reserved("+");
        II->priority = 5;
        regular.append(II);

        II = new infor;
        II->SetAttribute("RegSymbol");
        II->SetName("question");
        II->reg = new RegTree();
        II->reg->Reserved("?");
        regular.append(II);

        II = new infor;
        II->SetAttribute("RegSymbol");
        II->SetName("or");
        II->reg = new RegTree();
        II->reg->Reserved("|");
        regular.append(II);
    }
}
void lexicalPanel::append(lexicalPanel::infor* II)
{
    regular.append(II);
}
void lexicalPanel::Cgroup(FILE* fp, const char* name)const
{
    fprintf(fp, "int GroupGet");
    if (name != NULL) fprintf(fp, "_%s", name);
    CppGroupCore(fp, name);
    return;
}
void lexicalPanel::CppGroup(FILE* fp, const char* name)const
{
    if (name != NULL) fprintf(fp, "int %s::GroupGet", name);
    else fprintf(fp, "int null::GroupGet");
    CppGroupCore(fp, name);
    return;
}
void lexicalPanel::CppGroupCore(FILE* fp, const char* name)const
{
    size_t i, No;
    fprintf(fp, "(int accept)\n{\n");
    fprintf(fp, "\tswitch (accept)\n\t{\n");
    //for (i = 0; i < dfa.StateAmountGet(); i++)
    for (No = 0; No < regular.count(); No++)
    {
        //No = (size_t)dfa.GraphStateGet(i);
        //if (No == 0) continue;
        //fprintf(fp, "\tcase %zu:\n", i);
        //fprintf(fp, "\t\tgroup = %zu;\n", regular[No - 1]->group);
        //fprintf(fp, "\t\treturn %zu;", No);
        fprintf(fp, "\tcase %zu:\n", No + 1);
        //fprintf(fp, "\t\tgroup = %zu;\n", regular[No - 1]->group);
        fprintf(fp, "\t\treturn %zu;", regular[No]->group);
        fprintf(fp, "//");
        fprintf(fp, "%s: ", regular[No]->attribute);
        fprintf(fp, "%s", regular[No]->name);
        fprintf(fp, "\n");
    }
    fprintf(fp, "\t}\n");
    fprintf(fp, "\treturn 0;\n}\n");
}
void lexicalPanel::Demo(FILE* fp) const
{
    size_t i;
    fprintf(fp, "count: %zu\n", regular.count());
    for (i = 0; i < regular.count(); i++)
    {
        fprintf(fp, "No[%zu]: \n", i);
        regular[i]->Demo(fp);
    }
}
void lexicalPanel::infor::Demo(FILE* fp)
{
    fprintf(fp, "\tpriority: %zu\n", priority);
    fprintf(fp, "\tname: %s\n", name);
    fprintf(fp, "\tattribute: %s(%zu)\n\tregular expression: ", attribute, group);
    reg->Demo(stdout);
    fprintf(fp, "\n");
}

void lexicalPanel::SetAll(void)
{
    size_t i, j;
    for (i = 0; i < regular.count(); i++)
    {
        for (j = 0; j < attribute.count(); j++)
            if (compare(regular[i]->attribute, attribute[j])) break;
        if (j == attribute.count())
            attribute.append(Copy(regular[i]->attribute));
        regular[i]->group = j + 1;
    }
}
static bool compare(const char* str1, const char* str2)
{
    size_t i;
    for (i = 0; (str1[i] != '\0') && (str1[i] == str2[i]); i++);
    return str1[i] == str2[i];
}
static size_t strlength(const char* str)
{
    size_t i;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}
static void strfree(const char** strs, size_t length)
{
    size_t i;
    for (i = 0; i < length; i++)
    {
        free((void*)strs[i]);
    }
    free(strs);
}
static void inverse(list<size_t>& out, const list<size_t>& in)
{
    size_t i, length;
    length = in.count();
    out.refresh(length);
    for (i = 0; i < length; i++)
        out[in[i]] = i;
}
static int PostfixSwitch_small(char c)
{
    switch (c)
    {
        /*case 'a':
            return 7;
        case 'b':
            return 8;
        case 'f':
            return 12;
        case 'n':
            return 10;
        case 'r':
            return 13;
        case 't':
            return 9;
        case 'v':
            return 11;*/
    case '\\':
        return 92;
    case '\'':
        return 39;
    case '\"':
        return 34;
    case '\?':
        return 63;
    case '\0':
        return 0;
    default:
        return -1;
    }
}
/*

void sNFA::build(const RegTree* Reg)
{
    buffer<size_t> output;
    list<size_t> s;
    list<sNFA*> nfa;
    build(Reg, output, s, nfa);
}
void sNFA::build(const RegTree* Reg, buffer<size_t> &output, list<size_t> &s, list<sNFA*> &nfa)
{
    size_t i, length, site, j;
    RegTree::NodeType T;
    sNFA* now, *highest, *L, *R;
    bool input[CharSize + 1];
    refresh();
    output.clear();
    s.refresh();
    nfa.refresh();
    Reg->tree.postorderTraversal(output, s);
    length = output.count();
    R = NULL;
    L = NULL;
    highest = NULL;
    now = NULL;
    //for (i = 0; i < length; i++)
    //	std::cout << "output[" << i << "] = site = " << output[i] << std::endl;
    for (i = 0; i < length; i++)
    {
        site = output[i];
        //std::cout <<"output[" << i << "] = site = " << site << std::endl;
        //std::cout << "nfa.count = " << nfa.count() << ", type: ";
        //Demo(stdout);
        T = Reg->tree[site].content.type;
        //RegTree::Demo(stdout, T);
        if (i + 1 == length) now = this;
        else now = new sNFA();
        switch (T)
        {
        case hyperlex::RegTree::Concatenation:
        case hyperlex::RegTree::Alternation:
            nfa.pop(R);
            nfa.pop(L);
            break;
        case hyperlex::RegTree::ZeroOrMore:
        case hyperlex::RegTree::OneOrMore:
        case hyperlex::RegTree::ZeroOrOne:
            nfa.pop(highest);
            //std::cout << "highest = " << std::endl;
            //highest->Demo(stdout);
            break;
        case hyperlex::RegTree::Range:
            break;
        }
        switch (T)
        {
        case hyperlex::RegTree::Concatenation:
            now->serial(L, R);
            break;
        case hyperlex::RegTree::Alternation:
            now->parallel(L, R);
            break;
        case hyperlex::RegTree::ZeroOrMore:
            now->any(highest);
            break;
        case hyperlex::RegTree::OneOrMore:
            now->plus(highest);
            break;
        case hyperlex::RegTree::ZeroOrOne:
            now->ZeroOrOne(highest);
            break;
        case hyperlex::RegTree::Range:
            for (j = 0; j < CharSize; j++)
                input[j] = (j <= (size_t)Reg->tree[site].content.upper && j >= (size_t)Reg->tree[site].content.lower);
            now->build(input);
            break;
        default:
            break;
        }
        switch (T)
        {
        case hyperlex::RegTree::Concatenation:
        case hyperlex::RegTree::Alternation:
            delete L;
            delete R;
            break;
        case hyperlex::RegTree::ZeroOrMore:
        case hyperlex::RegTree::OneOrMore:
        case hyperlex::RegTree::ZeroOrOne:
            delete highest;
            break;
        case hyperlex::RegTree::Range:
        default:
            break;
        }
        //std::cout << "now = " << std::endl;
        //now->Demo(stdout);
        nfa.append(now);
        //std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  << std::endl;
    }
    //Reg->tree.postorderTraversal(output, s);
}


NFA::NFA(const lexicalPanel& lP)
{
    vec<sNFA*> all;
    size_t count, i;

    buffer<size_t> output;
    list<size_t> s;
    list<sNFA*> nfa;

    count = lP.regular.count();
    all.Malloc(count);
    for (i = 0; i < count; i++)
    {
        all[i] = new sNFA();
        all[i]->build(lP.regular[i]->reg, output, s, nfa);
    }
    build(all.vector(), count);
    for (i = 0; i < count; i++)
        delete all[i];
    for (i = 0; i < count; i++) priority[i + 1] = lP.regular[i]->priority + 1;
    priority[0] = 0;
    //stack.reshape(StateAmount);
    //stack.refresh();
}
*/

//struct Retree
//{
//	int* GOTO;
//	int* ACTION;
//	int* RulesToSymbol;
//	int* RulesLength;
//	const size_t StateCount = 22;
//	const size_t NonTerminalCount = 5;
//	const size_t TerminalCount = 5;
//	const size_t RulesCount = 9;

//};

/*
struct postorder
{
    int state;
    size_t here;
    info* back;
    info* leftback;
    info* rightback;
};
void postorderall(void)
{
    list<postorder> s;
    size_t top;
    s.append();
    s[0].state = 0;
    while (s.count()!=0)
    {

        switch (s.top().state)
        {
        case 0:
            leftback = new info();

            break;
        case 1:

            break;
        }
    }
}
*/
/*void sheetDFA::acceptSet(const matlist<bool>& Dstates, const NFA& nfa)
{
    matlist<bool> __AcceptSheet(nfa.accepted + 1);
    list<size_t> __accpetedCount;
    size_t i, j, to;
    bool* __AcceptList;
    int* SheetTemp;
    char ele;
    //std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
    AcceptCount = nfa.accepted;
    accept.refresh(accept.column(), Dstates.row());
    __AcceptSheet.refresh(__AcceptSheet.column(), Dstates.row());
    //std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
    for (i = 0; i < Dstates.row(); i++)
    {
        __AcceptList = __AcceptSheet.append();
        for (j = 0; j < CharSize; j++) accept[i][j] = 0;
        __accpetedCount.append(nfa.GetAccepted(Dstates[i], __AcceptList));
        std::cout << "__accpetedCount][]: " << __accpetedCount[i] << std::endl;
        Demo(stdout, Dstates[i], Dstates.column());
    }
    //std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
    for (i = 0; i < Dstates.row(); i++)
    {
        if (__accpetedCount[i] == 0) continue;
        SheetTemp = sheet[i];
        for (ele = 0; (size_t)ele < CharSize; ele++)
        {
            to = SheetTemp[(size_t)ele];
            if (__accpetedCount[to] == 0) accept[i][(size_t)ele] = nfa.FirstAccepted(__AcceptSheet[i]);
        }
    }
    //for (i = 0; i < count; i++)
    //{
    //	for (j = 0; j < CharSize; j++)
    //		printf("%2d", action(i, j));
    //	printf("\n");
    //}
}*/
/*
bool grammerS::FirstOr(long long int symbol, size_t to)
{
    size_t i;
    bool change;
    change = false;
    if (symbol < 0)//symbol is terminal
    {
        if (symbol != epsilon)
        {
            change = !first[to][-symbol - 1];
            first[to][-symbol - 1] = true;
        }
    }
    else//symbol is non-terminal
    {
        for (i = 0; i < TerminalCount; i++)
        {
            change = change || (first[symbol][i] && !first[to][i]);
            first[to][i] = first[to][i] || first[symbol][i];
        }
        i = TerminalCount + 1;
        change = change || (first[symbol][i] && !first[to][i]);
        first[to][i] = first[to][i] || first[symbol][i];
    }
    return change;
}
*/


/*
void RegTree::grow_t(const RegTree* regL, const RegTree* regR, NodeType T, bool key)
{
    size_t site;
    tree.clear();
    site = tree.NewNodeOffset();
    tree.SetHead(site);
    tree.append_t(regL->tree, regR->tree, site, key);
    tree[site].content.type = T;
}
*/







