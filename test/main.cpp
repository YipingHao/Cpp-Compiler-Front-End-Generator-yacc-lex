﻿#include<cstring>
#include<time.h>
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
int static simpleLR(hyperlex::dictionary& para);
int static simpleLR_v02(hyperlex::dictionary& para);
int testNew(hyperlex::dictionary& para);
int static entrance(int argc, char* argv[])
{
    hyperlex::dictionary para;
    FILE* fp;
    std::string file, outputDir;
    CFile CF;
    int error;
    hyperlex::BufferChar input;
    hyperlex::BufferChar temp;
    int info;

    if (argc > 1) file = argv[1];
    else file = "./parameter/parameter.txt";
    if (argc > 2) outputDir = argv[2];
    else outputDir = "./output/";
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fp = CF.OpenRead(file.c_str());
    std::cout << "InputFileName: " << file << std::endl;
    std::cout << "OutputFilePath: " << outputDir << std::endl;
    input << fp;
    temp.append(input);
    std::cout << "/*" << std::endl;
    std::cout << temp.ptr() << std::endl;
    std::cout << "*/" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    fclose(fp);
    error = para.build(input.ptr());
    std::cout << "error: " << error << std::endl;
    

    hyperlex::FilePath Opath;
    hyperlex::FilePath O_1, O_2, O_3;
    Opath.build(outputDir.c_str());

    O_1.build(para.search("L.txt", "OutputFileName"));
    O_2.build(para.search("G.txt", "OutputFileName2"));
    O_3.build(para.search("G2.txt", "OutputFileName3"));

    hyperlex::FilePath F_1, F_2, F_3;

    F_1.copy(Opath);
    F_2.copy(Opath);
    F_3.copy(Opath);

    F_1.RearOnlyAppend(O_1);
    F_2.RearOnlyAppend(O_2);
    F_3.RearOnlyAppend(O_3);


    para.assign("OutputFileName", F_1.path());
    para.assign("OutputFileName2", F_2.path());
    para.assign("OutputFileName3", F_3.path());
  
    para.print(stdout);

    const char* item;
    item = para.search("test old", "item");
    std::cout << "item: " << item << std::endl;
    if (compare(item, "test old"))
    {
        info = test_entrance(outputDir.c_str());
    }
    else if (compare(item, "simple LR"))
    {
        info = simpleLR(para);
    }
    else if (compare(item, "simple LR v02"))
    {
        info = simpleLR_v02(para);
    }
    else if (compare(item, "test"))
    {
        info = testNew(para);
    }
    else
    {
        info = test_entrance(argv[1]);
    }
    return info;
}



int simpleLR(hyperlex::dictionary& para)
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
    error = IP.build(input.ptr());
    std::cout << "error: " << error << std::endl;
    IP.demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    FILE* fpL, * fpG, * fpG2;
    if (para.search(false, "PrintToFile"))
    {
        fpL = CF.OpenWritePlus(para.search("./output/L.txt", "OutputFileName"));
        fpG = CF.OpenWritePlus(para.search("./output/G.txt", "OutputFileName2"));
        fpG2 = CF.OpenWritePlus(para.search("./output/G2.txt", "OutputFileName3"));
    }
    else
    {
        fpL = stdout;
        fpG = stdout;
        fpG2 = stdout;
    }
    error = IP.printL(fpL, OutputLabel.c_str());
    std::cout << "error: " << error << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    error = IP.printG(fpG, fpG2, OutputLabel2.c_str());
    std::cout << "error: " << error << std::endl;
    if (para.search(false, "PrintToFile"))
    {
        fclose(fpL);
        fclose(fpG);
        fclose(fpG2);
    }
    return error;
}
int static simpleLR_v02(hyperlex::dictionary& para)
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
    error = IP.build_v02(file.c_str());
    std::cout << "error-IP.build_v02(file.c_str()): " << error << std::endl;
    IP.demo(stdout);
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;

    FILE* fpL, * fpG, * fpG2;
    if (para.search(false, "PrintToFile"))
    {
        fpL = CF.OpenWritePlus(para.search("./output/L.txt", "OutputFileName"));
        fpG = CF.OpenWritePlus(para.search("./output/G.txt", "OutputFileName2"));
        fpG2 = CF.OpenWritePlus(para.search("./output/G2.txt", "OutputFileName3"));
    }
    else
    {
        fpL = stdout;
        fpG = stdout;
        fpG2 = stdout;
    }
    error = IP.printL(fpL, OutputLabel.c_str());
    std::cout << "error-IP.printL(fpL, OutputLabel.c_str()): " << error << std::endl;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    error = IP.printG(fpG, fpG2, OutputLabel2.c_str());
    std::cout << "error-IP.printG(fpG, fpG2, OutputLabel2.c_str()): " << error << std::endl;
    if (para.search(false, "PrintToFile"))
    {
        fclose(fpL);
        fclose(fpG);
        fclose(fpG2);
    }
    return error;
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















