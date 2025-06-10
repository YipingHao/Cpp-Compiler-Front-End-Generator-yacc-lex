#include<cstring>
#include<time.h>
#include "AutoHeader.h"
#include<stdlib.h>
int static Test000(const hyperlex::dictionary& para);
int static Test001(const hyperlex::dictionary& para);
int static Test002(const hyperlex::dictionary& para);
int static Test003(const hyperlex::dictionary& para);
int static Test004(const hyperlex::dictionary& para);
int static Test005(const hyperlex::dictionary& para);
int static Test006(const hyperlex::dictionary& para);
int static Test007(const hyperlex::dictionary& para);
int static Test008(const hyperlex::dictionary& para);
int static Test009(const hyperlex::dictionary& para);
int static Test010(const hyperlex::dictionary& para);
int static Test011(const hyperlex::dictionary& para);
int static Test012(const hyperlex::dictionary& para);
int static Test013(const hyperlex::dictionary& para);
int static Test014(const hyperlex::dictionary& para);
int static Test015(const hyperlex::dictionary& para);
int static Test016(const hyperlex::dictionary& para);
int static Test017(const hyperlex::dictionary& para);
int static Test018(const hyperlex::dictionary& para);
int static Test019(const hyperlex::dictionary& para);
int static Test020(const hyperlex::dictionary& para);
int static Test021(const hyperlex::dictionary& para);
int static Test022(const hyperlex::dictionary& para);
int static Test023(const hyperlex::dictionary& para);
int static Test024(const hyperlex::dictionary& para);
int static Test025(const hyperlex::dictionary& para);
int static Test026(const hyperlex::dictionary& para);
int static Test027(const hyperlex::dictionary& para);
int static Test028(const hyperlex::dictionary& para);
int static Test029(const hyperlex::dictionary& para);
int static Test030(const hyperlex::dictionary& para);
int static Test031(const hyperlex::dictionary& para);
int static Test032(const hyperlex::dictionary& para);
int static Test033(const hyperlex::dictionary& para);
int static Test034(const hyperlex::dictionary& para);
int static Test035(const hyperlex::dictionary& para);
int static Test036(const hyperlex::dictionary& para);
int static Test037(const hyperlex::dictionary& para);
int static Test038(const hyperlex::dictionary& para);
int static Test039(const hyperlex::dictionary& para);
int static Test040(const hyperlex::dictionary& para);
int static Test041(const hyperlex::dictionary& para);
int static Test042(const hyperlex::dictionary& para);
int static Test043(const hyperlex::dictionary& para);
int static Test044(const hyperlex::dictionary& para);
int static Test045(const hyperlex::dictionary& para);
int static Test046(const hyperlex::dictionary& para);
int static Test047(const hyperlex::dictionary& para);
int static Test048(const hyperlex::dictionary& para);
int static Test049(const hyperlex::dictionary& para);
int static Test050(const hyperlex::dictionary& para);
int static Test051(const hyperlex::dictionary& para);
int static Test052(const hyperlex::dictionary& para);
int static Test053(const hyperlex::dictionary& para);
int static Test054(const hyperlex::dictionary& para);
int static Test055(const hyperlex::dictionary& para);
int static Test056(const hyperlex::dictionary& para);
int static Test057(const hyperlex::dictionary& para);
int static Test058(const hyperlex::dictionary& para);
int static Test059(const hyperlex::dictionary& para);
int static Test060(const hyperlex::dictionary& para);
int static Test061(const hyperlex::dictionary& para);
int static Test062(const hyperlex::dictionary& para);
int static Test063(const hyperlex::dictionary& para);
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
	case 1:
	{
		error = Test001(para);
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

	std::cout << "derived == here : " << (derived == here) << std::endl;

	here.insert(0, 286, derived);
	std::cout << "derived == here : " << (derived == here) << std::endl;

	hyperlex::Morpheme newOne;
	//newOne.Demo(stdout);
	newOne.insert(4, 286, derived);
	//newOne.Demo(stdout);
	std::cout << "newOne == derived : " << (newOne == derived) << std::endl;

    return error;
}


int static Test001(const hyperlex::dictionary& para)
{
	int error = 0;
	for (size_t i = 0; i < 64; i++)
	{
		printf("int static Test");
		if (i< 10) printf("00%zu", i);
		else if (i < 100) printf("0%zu", i);
		printf("(const hyperlex::dictionary& para);\n");
		if (error == 0)
		{
			printf("{\n");
			printf("\tint error = 0;\n");
			printf("\treturn error;\n");
			printf("}\n");
		}
	}
	return error;
}





