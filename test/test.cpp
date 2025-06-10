#include<cstring>
#include<time.h>
#include "AutoHeader.h"
#include<stdlib.h>

typedef hyperlex::tree<hyperlex::GrammarTree::TreeInfor> GTNode;
typedef hyperlex::tree<hyperlex::GrammarTree::TreeInfor>::PostIterator GTiterator;

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
    case 2:
    {
        error = Test002(para);
        break;
    }
    case 3:
    {
        error = Test003(para);
        break;
    }
    case 4:
    {
        error = Test004(para);
        break;
    }
    case 5:
    {
        error = Test005(para);
        break;
    }
    case 6:
    {
        error = Test006(para);
        break;
    }
    case 7:
    {
        error = Test007(para);
        break;
    }
    case 8:
    {
        error = Test008(para);
        break;
    }
    case 9:
    {
        error = Test009(para);
        break;
    }
    case 10:
    {
        error = Test010(para);
        break;
    }
    case 11:
    {
        error = Test011(para);
        break;
    }
    case 12:
    {
        error = Test012(para);
        break;
    }
    case 13:
    {
        error = Test013(para);
        break;
    }
    case 14:
    {
        error = Test014(para);
        break;
    }
    case 15:
    {
        error = Test015(para);
        break;
    }
    case 16:
    {
        error = Test016(para);
        break;
    }
    case 17:
    {
        error = Test017(para);
        break;
    }
    case 18:
    {
        error = Test018(para);
        break;
    }
    case 19:
    {
        error = Test019(para);
        break;
    }
    case 20:
    {
        error = Test020(para);
        break;
    }
    case 21:
    {
        error = Test021(para);
        break;
    }
    case 22:
    {
        error = Test022(para);
        break;
    }
    case 23:
    {
        error = Test023(para);
        break;
    }
    case 24:
    {
        error = Test024(para);
        break;
    }
    case 25:
    {
        error = Test025(para);
        break;
    }
    case 26:
    {
        error = Test026(para);
        break;
    }
    case 27:
    {
        error = Test027(para);
        break;
    }
    case 28:
    {
        error = Test028(para);
        break;
    }
    case 29:
    {
        error = Test029(para);
        break;
    }
    case 30:
    {
        error = Test030(para);
        break;
    }
    case 31:
    {
        error = Test031(para);
        break;
    }
    case 32:
    {
        error = Test032(para);
        break;
    }
    case 33:
    {
        error = Test033(para);
        break;
    }
    case 34:
    {
        error = Test034(para);
        break;
    }
    case 35:
    {
        error = Test035(para);
        break;
    }
    case 36:
    {
        error = Test036(para);
        break;
    }
    case 37:
    {
        error = Test037(para);
        break;
    }
    case 38:
    {
        error = Test038(para);
        break;
    }
    case 39:
    {
        error = Test039(para);
        break;
    }
    case 40:
    {
        error = Test040(para);
        break;
    }
    case 41:
    {
        error = Test041(para);
        break;
    }
    case 42:
    {
        error = Test042(para);
        break;
    }
    case 43:
    {
        error = Test043(para);
        break;
    }
    case 44:
    {
        error = Test044(para);
        break;
    }
    case 45:
    {
        error = Test045(para);
        break;
    }
    case 46:
    {
        error = Test046(para);
        break;
    }
    case 47:
    {
        error = Test047(para);
        break;
    }
    case 48:
    {
        error = Test048(para);
        break;
    }
    case 49:
    {
        error = Test049(para);
        break;
    }
    case 50:
    {
        error = Test050(para);
        break;
    }
    case 51:
    {
        error = Test051(para);
        break;
    }
    case 52:
    {
        error = Test052(para);
        break;
    }
    case 53:
    {
        error = Test053(para);
        break;
    }
    case 54:
    {
        error = Test054(para);
        break;
    }
    case 55:
    {
        error = Test055(para);
        break;
    }
    case 56:
    {
        error = Test056(para);
        break;
    }
    case 57:
    {
        error = Test057(para);
        break;
    }
    case 58:
    {
        error = Test058(para);
        break;
    }
    case 59:
    {
        error = Test059(para);
        break;
    }
    case 60:
    {
        error = Test060(para);
        break;
    }
    case 61:
    {
        error = Test061(para);
        break;
    }
    case 62:
    {
        error = Test062(para);
        break;
    }
    case 63:
    {
        error = Test063(para);
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

struct Preparser
{
	enum type
	{
		accept = 0,
		error = 1,
		push = 2,
		reduce = 3
	};
	enum rules
	{
		all_all_ = 0,
		TEXT_meow_ = 1,
		//<DEF*>_first_ = 2,
		//<DEF*>_multi_ = 3,
		DEF_anntation_ = 4,
		DEF_anything_ = 5,
		DEF_include_ = 6,
		//[anntation]_anntationS_ = 7,
		//[anntation]_anntationM_ = 8,
		INCLUDE_include_ = 9,
		INCLUDE_include2_ = 10,
		ANY_identifier_ = 11,
		ANY_const_ = 12,
		ANY_RegSymbol_ = 13,
		ANY_braket_ = 14,
		ANY_division_ = 15,
		ANY_format_ = 16,
		//[identifier]_identifier_ = 17,
		//[const]_integer_ = 18,
		//[const]_CommonChar_ = 19,
		//[const]_idChar_ = 20,
		//[RegSymbol]_range_ = 21,
		//[RegSymbol]_star_ = 22,
		//[RegSymbol]_plus_ = 23,
		//[RegSymbol]_question_ = 24,
		//[RegSymbol]_or_ = 25,
		//[braket]_braceL_ = 26,
		//[braket]_braceR_ = 27,
		//[braket]_left_ = 28,
		//[braket]_right_ = 29,
		//[braket]_squareL_ = 30,
		//[braket]_squareR_ = 31,
		//[braket]_angleL_ = 32,
		//[braket]_angleR_ = 33,
		//[division]_semicolon_ = 34,
		//[division]_colon_ = 35,
		//[division]_dot_ = 36,
		//[format]_spaces_ = 37,
		//[format]_enters_ = 38,
		//[format]_tab_ = 39
	};
	enum nonterminal
	{
		_all_ = 0,
		_TEXT_ = 1,
		//_<DEF*>_ = 2,
		_DEF_ = 3,
		//_[anntation]_ = 4,
		_INCLUDE_ = 5,
		_ANY_ = 6,
		//_[identifier]_ = 7,
		//_[const]_ = 8,
		//_[RegSymbol]_ = 9,
		//_[braket]_ = 10,
		//_[division]_ = 11,
		//_[format]_ = 12
	};
	static const size_t StateCount;
	static const size_t NonTerminalCount;
	static const size_t TerminalCount;
	static const size_t RulesCount;
	static const int GOTO[42][13];
	static const int ACTION[42][28];
	static const int RulesToSymbol[40];
	static const int RulesLength[40];
	static const char* const RulesName[40];
	static const int Implicit[40];
};

int static pretreatment(hyperlex::Morpheme& input, hyperlex::Morpheme& output)
{
	int error = output.Build<PreTreat>(input);
	if (error != 0)
	{
		return error;
	}

	hyperlex::vector<const char*> path;
	bool include;
	do
	{
        include = false;
        size_t begin = 0;
        size_t count = 0;
        const char* name = NULL;
		hyperlex::GrammarTree Tree;
        error = Tree.build<Preparser>(output);
        GTiterator iterator;
        iterator.initial(Tree.GT);
        while (iterator.still())
        {
            GTNode* GT = iterator.target();
            if (iterator.state() == 0)
            {
                size_t infor = GT->root().site;
                if (GT->root().rules)
                {
                    if (infor == (int)Preparser::INCLUDE_include_ )
                    {
                        size_t site = GT->child(1)->root().site;
                        include = true;
                        begin = GT->child(0)->root().site;
                        count = 2;
                        name = output.GetString(site);
                        break;
                    }
                    else if(infor == (int)INCLUDE_include2_)
                    {
                        size_t site = GT->child(2)->root().site;
                        include = true;
                        begin = GT->child(0)->root().site;
                        count = 3;
                        name = output.GetString(site);
                        break;
                    }
                }
            }
            iterator.next();
        }
        if (include)
        {

        }
	} while (include);

	return error;
}

int static Test001(const hyperlex::dictionary& para)
{
	int error = 0;
	
	return error;
}
struct test003
{
	static int infor;
	test003()
	{
		std::cout << "test003()" << std::endl;
		std::cout << "infor: " << infor << std::endl;
		infor += 1;
	}
	~test003()
	{
		std::cout << "~test003()" << std::endl;
		std::cout << "infor: " << infor << std::endl;
	}
};
int test003::infor = 0;
int static Test002(const hyperlex::dictionary& para)
{
    int error = 0;
	for (size_t i = 0; i < 16; i++)
	{
		test003 temp;
	}
    return error;
}
int static Test003(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test004(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test005(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test006(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test007(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test008(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test009(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test010(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test011(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test012(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test013(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test014(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test015(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test016(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test017(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test018(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test019(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test020(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test021(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test022(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test023(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test024(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test025(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test026(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test027(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test028(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test029(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test030(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test031(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test032(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test033(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test034(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test035(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test036(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test037(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test038(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test039(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test040(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test041(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test042(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test043(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test044(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test045(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test046(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test047(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test048(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test049(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test050(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test051(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test052(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test053(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test054(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test055(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test056(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test057(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test058(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test059(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test060(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test061(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test062(const hyperlex::dictionary& para)
{
    int error = 0;
    return error;
}
int static Test063(const hyperlex::dictionary& para)
{
    int error = 0;
    for (size_t i = 0; i < 64; i++)
    {
        printf("int static Test");
        if (i < 10) printf("00%zu", i);
        else if (i < 100) printf("0%zu", i);
		else printf("%zu", i);
        printf("(const hyperlex::dictionary& para)");
        if (error == 0)
        {
            printf("\n{\n");
            printf("\tint error = 0;\n");
            printf("\treturn error;\n");
            printf("}\n");
        }
        else
        {
            printf(";");
        }
    }

    for (size_t i = 2; i < 64; i++)
    {
        printf("\t\tcase ");
        printf("%zu:\n\t\t{\n\t\t\terror = Test", i);
        if (i < 10) printf("00%zu", i);
        else if (i < 100) printf("0%zu", i);
        else printf("%zu", i);
        printf("(para);\n");
        printf("\t\t\tbreak;\n");
        printf("\t\t}\n");
    }
    return error;
}




