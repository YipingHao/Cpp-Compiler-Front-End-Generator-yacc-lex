#include<cstring>
#include<time.h>
using namespace std;
#include "AutoHeader.h"
#include<stdlib.h>
int test_entrance(const char* output_path);
int static entrance(int argc, char* argv[]);
int main(int argc, char* argv[])
{
	int info;
	int amount_of_cores;
	const char* output_path;
	output_path = argv[1];
	info = 0;
	info = test_entrance(output_path);
	return info;
}
int static entrance(int argc, char* argv[])
{

}







