#include<cstring>
#include<time.h>
using namespace std;
#include "LexHeader.h"
#include<stdlib.h>
int test_entrance(const char* output_path);
static int cores_amount_from_input(const char* s);
int main(int argc, char* argv[])
{
	int info;
	//parameter_file pf;
	int amount_of_cores;
	const char* output_path;
	output_path = argv[1];
	amount_of_cores = cores_amount_from_input(argv[2]);
	info = 0;
	info = test_entrance(output_path);
	return info;
}







static int cores_amount_from_input(const char* s)
{
	buffer temp;
	int core;
	temp <= s;
	core = temp.dequeue_int();
	return core;
}
static int test_01(const char* output_path, parameter_file &pf);
static int test_02(const char* output_path, parameter_file& pf);
static int test_03(const char* output_path, parameter_file& pf);
static int test_04(const char* output_path, parameter_file& pf);
static int test_05(const char* output_path, parameter_file& pf);
static int test_06(const char* output_path, parameter_file& pf);
static int test_07(const char* output_path, parameter_file& pf);
static int test_08(const char* output_path, parameter_file& pf);
static int test_09(const char* output_path, parameter_file& pf);
static int test_10(const char* output_path, parameter_file& pf);
static int test_11(const char* output_path, parameter_file& pf);
static int test_12(const char* output_path, parameter_file& pf);
static int test_13(const char* output_path, parameter_file& pf);
static int test_14(const char* output_path, parameter_file& pf);
static int test_15(const char* output_path, parameter_file& pf);
static int test_16(const char* output_path, parameter_file& pf);
static int test_17(const char* output_path, parameter_file& pf);
static int test_18(const char* output_path, parameter_file& pf);
static int test_19(const char* output_path, parameter_file& pf);
int test_entrance(const char* output_path)
{
	int item;
	int info;
	parameter_file pf;
	pf.build("./parameter/test_item.txt");
	item = pf.first_int("item", 1);
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
		std::cout << "Test grammer LR0 from input file; " << std::endl;
		info = test_13(output_path, pf);
		break;
	case 14:
		std::cout << "Test template; " << std::endl;
		info = test_14(output_path, pf);
		break;
	case 15:
		std::cout << "Test grammer 2; " << std::endl;
		info = test_15(output_path, pf);
		break;
	case 16:
		std::cout << "Test grammer 2; " << std::endl;
		info = test_16(output_path, pf);
		break;
	case 17:
		std::cout << "Test grammer 2; " << std::endl;
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
static int test_01(const char* output_path, parameter_file& pf)
{
    printf("test_01\n");
}
static int test_02(const char* output_path, parameter_file& pf)
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
	long long int *list = NULL;
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
static int test_03(const char* output_path, parameter_file& pf)
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
		outer():a(1),b(2) {std::cout << "outer()" << std::endl; }
		~outer() { std::cout << "~outer()" << std::endl; }
		
	};
	outer test;
	char a[128];
	char *b;
	b = a;
	std::cout << "char a[128];: " << "sizeof(char[128]) = "<< sizeof(char[128]) << "sizeof(a) = " << sizeof(a) << std::endl;
	std::cout << "char *b; b = a;: " << "sizeof(b) = " << sizeof(b) << std::endl;
	std::cout << "#define CharSize ((size_t)1 << (sizeof(char) * 8 - 1)): " << ((size_t)(1 << (sizeof(char) * 8 - 1)))  << std::endl;
	//#define CharSize 
}
using namespace hyperlex;
static int test_04(const char* output_path, parameter_file& pf)
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
static int test_05(const char* output_path, parameter_file& pf)
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
}
static int test_06(const char* output_path, parameter_file& pf)
{
	RegTree RT, Id, res;
	//sNFA nfa, nfa2;
	NFA* ff;
	sNFA* nfa[2];
	sheetDFA *dfa;
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
static int test_07(const char* output_path, parameter_file& pf)
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
static int test_08(const char* output_path, parameter_file& pf)
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
static int test_09(const char* output_path, parameter_file& pf)
{
	size_t i;
	for (i = 10; i < 20; i++)
	{
		std::cout << "static int test_" << i<< "(const char* output_path, parameter_file& pf);" << std::endl;
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
		std::cout << "static int test_" << i << "(const char* output_path, parameter_file& pf)" << std::endl;
		std::cout << "{" << std::endl;
		std::cout << "\treturn 0;" << std::endl;
		std::cout << "}" << std::endl;
	}
}
static int test_10(const char* output_path, parameter_file& pf)
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
static int test_11(const char* output_path, parameter_file& pf)
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
static int test_12(const char* output_path, parameter_file& pf)
{
	BufferChar input;
	FILE* fp;
	CFile CF;
	grammerS G;
	LR0 *lr;
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
static int test_13(const char* output_path, parameter_file& pf)
{
	BufferChar input;
	FILE* fp;
	CFile CF;
	grammerS G;
	LR0* lr;
	LR1* lr1;
	string file;
	BufferChar temp;
	lr1 = NULL;
	file = pf.first_string("InputFileName", "./data/grammerT.txt");
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
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
	std::cout << "++++++++++++lr1 = new LR1(&G);+++++++++++++++" << std::endl;
	lr1 = new LR1(&G);
	lr1->Demo(stdout, &G);
	std::cout << "+++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
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
static int test_14(const char* output_path, parameter_file& pf)
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
static int test_15(const char* output_path, parameter_file& pf)
{
	return 0;
}
static int test_16(const char* output_path, parameter_file& pf)
{
	return 0;
}
static int test_17(const char* output_path, parameter_file& pf)
{
	return 0;
}
static int test_18(const char* output_path, parameter_file& pf)
{
	return 0;
}
static int test_19(const char* output_path, parameter_file& pf)
{
	return 0;
}






