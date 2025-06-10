#include<cstring>
#include<time.h>
#include "AutoHeader.h"
#include<stdlib.h>
int static Test000(const hyperlex::dictionary& para);
int testNew(hyperlex::dictionary& para)
{
    int item = para.search(1L, "TestItem::item");
    int error = 0;
    std::cout << "item: " << item << std::endl;
    switch (item)
    {
    case 0:
    {
        error = Test000(para);
        break;
    }
    default:
    {
        error = Test000(para);
        break;
    }
        
    }
    return error;
}
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

struct PreTreat
{
	enum regular
	{
		_identifier_ = 1,
		_integer_ = 2,
		_CommonChar_ = 3,
		_idChar_ = 4,
		_string_ = 5,
		_include_ = 6,
		_spaces_ = 7,
		_enters_ = 8,
		_tab_ = 9,
		_semicolon_ = 10,
		_colon_ = 11,
		_dot_ = 12,
		_braceL_ = 13,
		_braceR_ = 14,
		_left_ = 15,
		_right_ = 16,
		_squareL_ = 17,
		_squareR_ = 18,
		_angleL_ = 19,
		_angleR_ = 20,
		_anntationS_ = 21,
		_anntationM_ = 22,
		_range_ = 23,
		_star_ = 24,
		_plus_ = 25,
		_question_ = 26,
		_or_ = 27
	};
	enum group
	{
		_identifier___ = 1,
		_const___ = 2,
		_string___ = 3,
		_include___ = 4,
		_format___ = 5,
		_division___ = 6,
		_braket___ = 7,
		_anntation___ = 8,
		_RegSymbol___ = 9
	};
	static int next(int state, const char c);
	static int action(int state);
	static int GroupGet(int state);
};
int static Test000(const hyperlex::dictionary& para)
{
	hyperlex::InputPanel IP;
	std::string file;
	FILE* fp;
	hyperlex::BufferChar input;
	hyperlex::BufferChar temp;
	CFile CF;
	std::string OutputLabel2, OutputLabel;
	OutputLabel = para.search("lexer", "OutputLabel");
	OutputLabel2 = para.search("parser", "OutputLabel2");
	int error = 0;
	file = para.search("./data/grammerT.txt", "InputFileName");
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

	hyperlex::Morpheme here;
	here.Build<PreTreat>(input.ptr());
	
	here.Demo(stdout);

	hyperlex::Morpheme derived;

	derived.Build<PreTreat>(here);

	derived.Demo(stdout);

	std::cout << "derived == here" << derived == here << std::endl;
    return error;
}








