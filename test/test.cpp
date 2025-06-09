#include<cstring>
#include<time.h>
using namespace std;
#include "AutoHeader.h"
#include<stdlib.h>

int testNew(hyperlex::dictionary& para)
{
    int item = para.search(1, "TestItem::item");
    int error = 0;
    std::cout << "item: " << item << std::endl;

    return error;
}









