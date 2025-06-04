#include<cstring>
#include<time.h>
using namespace std;
#include "AutoHeader.h"
#include<stdlib.h>
int test_entrance(const char* output_path);
int static entrance(int argc, char* argv[]);
static bool compare(const char* str1, const char* str2);
int main(int argc, char* argv[])
{
	int info;
	const char* output_path;
	output_path = argv[1];
	info = 0;
	//info = test_entrance(output_path);
    info = entrance(argc, argv);
	return info;
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
int static entrance(int argc, char* argv[])
{
    hyperlex::dictionary para;
    FILE* fp;
    std::string file;
    CFile CF;
    int error;
    hyperlex::BufferChar input;
    hyperlex::BufferChar temp;
    int info;

    file = "./parameter/para.txt";
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
    error = para.build(input.ptr());
    std::cout << "error: " << error << std::endl;
    para.print(stdout);

    const char* item;
    item = para.search("test old", "item");
    std::cout << "item: " << item << std::endl;
    if (compare(item, "test old"))
    {
        info = test_entrance(argv[1]);
    }
    else if (compare(item, "simple LR"))
    {
        info = test_entrance(argv[1]);
    }
    else
    {
        info = test_entrance(argv[1]);
    }
    }
    return info;
}







static bool compare(const char* str1, const char* str2)
{
    size_t i;
    for (i = 0; (str1[i] != '\0') && (str1[i] == str2[i]); i++);
    return str1[i] == str2[i];
}

#include<errno.h>
#include <string.h>
void static ExitWarning(int error, FILE* fp);
CFile::CFile()
{
}
CFile::~CFile()
{
}
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

void static ExitWarning(int error, FILE* fp)
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















