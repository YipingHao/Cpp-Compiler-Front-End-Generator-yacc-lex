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



int static Test000(const hyperlex::dictionary& para)
{

}








