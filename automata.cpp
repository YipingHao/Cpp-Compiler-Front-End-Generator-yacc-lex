#include"automata.h"
using namespace hyperlex;
#define SizeMax ((size_t)0xffffffffffffffff)
#define CharSize ((size_t)(1 << (sizeof(char) * 8 - 1)))


#include<stdlib.h>
//typedef size_t uint;
//typedef long long int sint;
#include<iostream>
#include <bitset>

static bool compare(const char* str1, const char* str2);
static void inverse(list<size_t>& out, const list<size_t>& in);

BufferChar::BufferChar()
{
}
BufferChar::~BufferChar()
{
}
void BufferChar::operator<<(FILE* fp)
{
	while (feof(fp) == 0)
		append((const char)getc(fp));	
}
char* BufferChar::vector(void)
{
	append('\0');
	return content + Head;
}

RegTree::RegTree()
{
}
RegTree::~RegTree()
{
}
void RegTree::build(const char* reg)
{
	tree.clear();
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
	RegTree* left, * right, *middle;
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
	RegTree* left, * right, * middle, *temp;
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
	range1.grow(' ', '!');//32, 33
	range2.grow('#', '&');//35, 38
	range3.grow('(', '.');//40, 46
	range4.grow('0', '[');//48, 91
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
	//buffer<size_t> output;
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
					if ((int)L < 32) fprintf(fp, "[\\%d-", (int)L);
					else fprintf(fp, "[%c-", L);
					if ((int)U < 32) fprintf(fp, "\\%d]", (int)U);
					else fprintf(fp, "%c]", U);
				}
				else
				{
					if ((int)L < 32) fprintf(fp, "[\\%d]", (int)L);
					else fputc(L, fp);
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
	case hyperlex::RegTree::Concatenation:
		fprintf(fp, "Concatenation\n");
		break;
	case hyperlex::RegTree::Alternation:
		fprintf(fp, "Alternation\n");
		break;
	case hyperlex::RegTree::ZeroOrMore:
		fprintf(fp, "ZeroOrMore\n");
		break;
	case hyperlex::RegTree::OneOrMore:
		fprintf(fp, "OneOrMore\n");
		break;
	case hyperlex::RegTree::ZeroOrOne:
		fprintf(fp, "ZeroOrOne\n");
		break;
	case hyperlex::RegTree::Range:
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
		if ((int)L < 32) fprintf(fp, "[\\%d-", (int)L);
		else fprintf(fp, "[%c-", L);
		if ((int)U < 32) fprintf(fp, "\\%d]", (int)U);
		else fprintf(fp, "%c]", U);
	}
	else
	{
		if ((int)L < 32) fprintf(fp, "[\\%d]", (int)L);
		else fputc(L, fp);
	}
}

void RegTree::info::Demo(FILE* fp)
{
	RegTree::Demo(fp, lower, upper);
	RegTree::Demo(fp, type);
}

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

}
lexicalPanel::~lexicalPanel()
{
	size_t i;
	for (i = 0; i < regular.count(); i++)
		delete regular[i];
}
lexicalPanel::infor::infor()
{
	priority = 0;
	reg = NULL;
	name = NULL;
	attribute = NULL;
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
	II->SetAttribute("char");
	II->SetName("reserved");
	II->reg = new RegTree();
	II->reg->IdentifierInner();
	regular.append(II);

	II = new infor;
	II->SetAttribute("char");
	II->SetName("CommonChar");
	II->reg = new RegTree();
	II->reg->ConstChar();
	regular.append(II);

	
}
void lexicalPanel::SetRegS(void)
{
	infor* II;

	SetReg();

	II = new infor;
	II->SetAttribute("Id");
	II->SetName("identifier");
	II->reg = new RegTree();
	II->reg->Identifier();
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
}
void lexicalPanel::append(lexicalPanel::infor* II)
{
	regular.append(II);
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
	fprintf(fp, "\tattribute: %s\n\tregular expression: ", attribute);
	reg->Demo(stdout);
	fprintf(fp, "\n");
}

DirectedGraph::DirectedGraph()
{
}
DirectedGraph::~DirectedGraph()
{
}
void DirectedGraph::refresh(void)
{
	vertice.refresh();
	arcs.refresh();
}
void DirectedGraph::refresh(size_t newlength)
{
	size_t i;
	vertice.refresh(newlength);
	arcs.refresh();
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
	begin = arcs.site();
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

bool Convert::in(const char ele)
{
	return lower <= ele && ele <= upper && !epsilon;
}
bool convert::in(const char ele)
{
	return lower <= (int)ele && (int)ele <= upper;
}
bool convert::in(int ele)
{
	return lower <= ele && ele <= upper;
}

sNFA::sNFA()
{
	StateAmount = 0;
	accepted = 0;
}
sNFA::~sNFA()
{
}
void sNFA::Demo(FILE* fp) const
{
	size_t i, first, count;
	//size_t To;
	char U, L;
	fprintf(fp, "\nStateAmount = %zu.\n", StateAmount);
	fprintf(fp, "accepted state = %zu.\n", accepted);
	fprintf(fp, "Amount od Arcs = %zu.\n", graph.arcs.count());
	fprintf(fp, "=========================================================\n");
	for (i = 0; i < StateAmount; i++)
	{
		fprintf(fp, "State[%zu], Arc count: %zu\n", i, graph.ArcCount(i));
		count = 0;
		first = graph.vertice[i].first;
		while (first != SizeMax)
		{
			fprintf(fp, "\tNo[%zu], to: %zu, ", count, graph.ArcTo(first));
			if(graph.arcs[first].content.epsilon)
				fprintf(fp, "a default epsilon conversion.\n");
			else
			{
				U = graph.arcs[first].content.upper;
				L = graph.arcs[first].content.lower;
				fprintf(fp, "label: ");
				if (U != L)
				{
					if ((int)L < 32) fprintf(fp, "[\\%d-", (int)L);
					else fprintf(fp, "[%c-", L);
					if ((int)U < 32) fprintf(fp, "\\%d]", (int)U);
					else fprintf(fp, "%c]", U);
				}
				else
				{
					if ((int)L < 32) fprintf(fp, "[\\%d]", (int)L);
					else fputc(L, fp);
				}
				fprintf(fp, "\n");
			}
			count += 1;
			first = graph.arcs[first].next;
		}
	}
	fprintf(fp, "=========================================================\n");
}
void sNFA::refresh(void)
{
	StateAmount = 0;
	graph.refresh();
	accepted = 0;
	//CC.refresh();
}
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
	bool input[128];
	refresh();
	output.refresh();
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
void sNFA::build(void)
{
	//size_t site;
	Convert CC;
	refresh();
	StateAmount = 2;
	graph.refresh(StateAmount);
	//FirstConvert.Malloc(StateAmount);
	//accepted.Malloc(StateAmount);
	//accepted[0] = 0;
	//accepted[1] = 1;
	accepted = 1;
	//FirstConvert[0] = SizeMax;
	//FirstConvert[1] = SizeMax;
	//site = CC.expand();
	//CC[site].from = 0;
	//CC[site].to = 1;
	//CC[site].next = SizeMax;
	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
}
void sNFA::build(const bool input[128])
{
	size_t i;
	Convert CC;
	char state = 0;
	refresh();
	StateAmount = 2;
	graph.refresh(StateAmount);
	//FirstConvert.Malloc(StateAmount);
	//accepted.Malloc(StateAmount);
	//accepted[0] = 0;
	//accepted[1] = 1;
	accepted = 1;
	//FirstConvert[0] = SizeMax;
	//FirstConvert[1] = SizeMax;
	//site = CC.expand();
	//CC[site].from = 0;
	//CC[site].to = 1;
	//CC[site].next = SizeMax;
	for (i = 0; i < 128; i++)
	{
		switch (state)
		{
		case 0:
			if (input[i])
			{
				//site = CC.expand();
				//CC[site].from = 0;
				//CC[site].to = 1;
				//CC[site].next = SizeMax;
				CC.epsilon = false;
				CC.lower = (char)i;
				//graph.append(0, 1, site);
				state = 1;
			}
			break;
		case 1:
			if (!input[i])
			{
				CC.upper = (char)(i - 1);
				graph.append(0, 1, CC);
				//std::cout << "L: " << CC.lower << "U: " << CC.upper << std::endl;
				state = 0;
			}
			break;
		}
	}
	if (state == 1)
	{
		CC.upper = (char)(i - 1);
		graph.append(0, 1, CC);
		state = 0;
	}
	//std::cout << std::endl << "build(const bool input[128])" << std::endl;
	//Demo(stdout);
}
void sNFA::parallel(const sNFA& left, const sNFA& right)
{
	size_t leftOffset, rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + left.StateAmount + right.StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	leftOffset = 1;
	rightOffset = 1 + left.StateAmount;

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, leftOffset, CC);
	graph.append(0, rightOffset, CC);

	graph.append(left.graph, leftOffset);
	graph.append(right.graph, rightOffset);

	graph.append(leftOffset + left.accepted, accepted, CC);
	graph.append(rightOffset + right.accepted, accepted, CC);
}
void sNFA::serial(const sNFA& left, const  sNFA& right)
{
	size_t leftOffset, rightOffset;
	Convert CC;
	refresh();
	leftOffset = 0;
	rightOffset = left.StateAmount;
	StateAmount = left.StateAmount + right.StateAmount;
	graph.refresh(StateAmount);
	accepted = rightOffset + right.accepted;

	graph.append(left.graph, leftOffset);
	graph.append(right.graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(left.accepted, rightOffset, CC);
	graph.append(rightOffset, left.accepted, CC);
}
void sNFA::any(const sNFA& right)
{
	size_t rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + right.StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = 1;
	graph.append(right.graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
	graph.append(0, accepted, CC);
	graph.append(rightOffset + right.accepted, 1, CC);
	graph.append(rightOffset + right.accepted, accepted, CC);
}
void sNFA::plus(const sNFA& right)
{
	size_t rightOffset, middle;
	Convert CC;
	refresh();
	StateAmount = 2 + 2 * right.StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = right.StateAmount + 1;
	middle = right.StateAmount;
	graph.append(right.graph, 0);
	graph.append(right.graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(right.accepted, middle, CC);
	graph.append(middle, right.accepted, CC);
	//==================================
	graph.append(middle, rightOffset, CC);
	graph.append(middle, accepted, CC);
	graph.append(rightOffset + right.accepted, rightOffset, CC);
	graph.append(rightOffset + right.accepted, accepted, CC);
}
void sNFA::ZeroOrOne(const sNFA& right)
{
	size_t rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + right.StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = 1;
	graph.append(right.graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
	graph.append(0, accepted, CC);
	//graph.append(rightOffset + right.accepted, 1, CC);
	graph.append(rightOffset + right.accepted, accepted, CC);
}

void sNFA::parallel(const sNFA* left, const sNFA* right)
{
	size_t leftOffset, rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + left->StateAmount + right->StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	leftOffset = 1;
	rightOffset = 1 + left->StateAmount;

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
	graph.append(0, rightOffset, CC);

	graph.append(left->graph, leftOffset);
	graph.append(right->graph, rightOffset);

	graph.append(leftOffset + left->accepted, accepted, CC);
	graph.append(rightOffset + right->accepted, accepted, CC);

	//std::cout << std::endl << "parallel(const sNFA* left, const sNFA* right)" << std::endl;
	//Demo(stdout);
}
void sNFA::serial(const sNFA* left, const  sNFA* right)
{
	size_t leftOffset, rightOffset;
	Convert CC;
	refresh();
	leftOffset = 0;
	rightOffset = left->StateAmount;
	StateAmount = left->StateAmount + right->StateAmount;
	graph.refresh(StateAmount);
	accepted = rightOffset + right->accepted;

	graph.append(left->graph, leftOffset);
	graph.append(right->graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(left->accepted, rightOffset, CC);
	graph.append(rightOffset, left->accepted, CC);

	//std::cout << std::endl << "void sNFA::serial(const sNFA* left, const  sNFA* right)" << std::endl;
	//Demo(stdout);
	//std::cout << std::endl << "left" << std::endl;
	//left->Demo(stdout);
	//std::cout << std::endl << "right" << std::endl;
	//right->Demo(stdout);
}
void sNFA::any(const sNFA* right)
{
	size_t rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + right->StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = 1;
	graph.append(right->graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
	graph.append(0, accepted, CC);
	graph.append(rightOffset + right->accepted, 1, CC);
	graph.append(rightOffset + right->accepted, accepted, CC);
}
void sNFA::plus(const sNFA* right)
{
	size_t rightOffset, middle;
	Convert CC;
	refresh();
	StateAmount = 2 + 2 * right->StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = right->StateAmount + 1;
	middle = right->StateAmount;
	graph.append(right->graph, 0);
	graph.append(right->graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(right->accepted, middle, CC);
	graph.append(middle, right->accepted, CC);
	//==================================
	graph.append(middle, rightOffset, CC);
	graph.append(middle, accepted, CC);
	graph.append(rightOffset + right->accepted, rightOffset, CC);
	graph.append(rightOffset + right->accepted, accepted, CC);

	//std::cout << std::endl << "void sNFA::plus(const sNFA* right)" << std::endl;
	//right->Demo(stdout);
	//std::cout << std::endl << "void sNFA::plus(const sNFA* right)" << std::endl;
	//Demo(stdout);
}
void sNFA::ZeroOrOne(const sNFA* right)
{
	size_t rightOffset;
	Convert CC;
	refresh();
	StateAmount = 2 + right->StateAmount;
	graph.refresh(StateAmount);
	accepted = StateAmount - 1;

	rightOffset = 1;
	graph.append(right->graph, rightOffset);

	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	graph.append(0, 1, CC);
	graph.append(0, accepted, CC);
	//graph.append(rightOffset + right.accepted, 1, CC);
	graph.append(rightOffset + right->accepted, accepted, CC);
	//std::cout << std::endl << "ZeroOrOne(const sNFA* right)" << std::endl;
	//Demo(stdout);
}

NFA::NFA(const sNFA& single)
{
	size_t i;
	graph.refresh();
	StateAmount = single.StateAmount;
	graph.refresh(StateAmount);
	graph.append(single.graph, 0);
	for (i = 0; i < StateAmount; i++) graph.vertice[i].content = 0;
	graph.vertice[single.accepted].content = 1;
	accepted = 1;

	//stack.reshape(StateAmount);
	//stack.refresh();
}
NFA::NFA(const sNFA*const* multiple, size_t count)
{
	build(multiple, count);
	//stack.reshape(StateAmount);
	//stack.refresh();
}
void NFA::build(const sNFA* const* multiple, size_t count)
{
	size_t i, prefix;
	Convert CC;
	graph.refresh();
	StateAmount = 1;
	accepted = count;
	for (i = 0; i < count; i++) StateAmount += multiple[i]->StateAmount;
	graph.refresh(StateAmount);
	prefix = 1;
	for (i = 0; i < count; i++)
	{
		graph.append(multiple[i]->graph, prefix);
		prefix += multiple[i]->StateAmount;
	}
	for (i = 0; i < StateAmount; i++) graph.vertice[i].content = 0;
	prefix = 1;
	CC.epsilon = true;
	CC.lower = 'a' + (char)1;
	CC.upper = 'a';
	for (i = 0; i < count; i++)
	{
		graph.vertice[prefix + multiple[i]->accepted].content = i + 1;
		graph.append(0, prefix, CC);
		prefix += multiple[i]->StateAmount;
	}

	//stack.reshape(StateAmount);
	//stack.refresh();
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
	//stack.reshape(StateAmount);
	//stack.refresh();
}
NFA::~NFA()
{

}

void NFA::initial(bool* state, list<size_t>& stack) const
{
	size_t i;
	state[0] = true;
	for (i = 1; i < StateAmount; i++) state[i] = false;
	closure(state, stack);
}
void NFA::closure(bool* state, list<size_t>& stack) const
{
	size_t delta;
	size_t Scount;
	size_t i;
	size_t now, arc, temp;
	Scount = 0;
	delta = 0;
	stack.refresh();
	for (i = 0; i < StateAmount; i++)
		if (state[i])
		{
			Scount += 1;
			stack.append(i);
		}
	while (stack.pop(now) != 0)
	{
		arc = graph.vertice[now].first;
		while (arc != SizeMax)
		{
			if (graph.arcs[arc].content.epsilon == true)
			{
				temp = graph.arcs[arc].to;
				if (!state[temp])
				{
					state[temp] = true;
					stack.append(temp);
					delta += 1;
				}
			}
			arc = graph.arcs[arc].next;
		}
	}
}
size_t NFA::move(const bool* from, bool* to, const char ele, list<size_t>& stack)  const
{
	size_t i; 
	size_t Scount;
	size_t now, arc;
	
	/*
	size_t count__ = 0;
	bool flag;
	flag = false;
	for (i = 0; i < StateAmount; i++) count__ += from[i] ? 1 : 0;
	if (count__ == 39 && ele == '\'') flag = true;
	if (count__ == 10 && ele == '\\' && from[150]) flag = true;
	*/

	Scount = 0;
	for (i = 0; i < StateAmount; i++) to[i] = false;
	for (i = 0; i < StateAmount; i++)
		if (from[i])
		{
			//if (flag)
			//{
			//	std::cout << "from[" << i << "]:" << std::endl;
			//}
			arc = graph.vertice[i].first;
			while (arc != SizeMax)
			{
				if (graph.arcs[arc].content.in(ele))
				{
					now = graph.arcs[arc].to;
					Scount += (to[now] ? 0 : 1);
					to[now] = true;
					//if (flag) std::cout << "to: " << now << std::endl;
				}
				arc = graph.arcs[arc].next;
			}
		}
	//sheetDFA::Demo(stdout, to, StateAmount);
	closure(to, stack);
	//sheetDFA::Demo(stdout, to, StateAmount);
	return Scount;
}
size_t NFA::GetAccepted(const bool* state, bool* accept) const
{
	size_t __accpetedCount, i;
	for (i = 0; i < accepted + 1; i++) accept[i] = false;
	for (i = 0; i < StateAmount; i++)
		if (state[i]) accept[graph.vertice[i].content] = true;
	__accpetedCount = 0;
	for (i = 1; i < accepted + 1; i++)
		if (accept[i]) __accpetedCount += 1;
	return __accpetedCount;
}
size_t NFA::FirstAccepted(const bool* accept) const
{
	size_t i;
	for (i = 1; i < accepted + 1; i++)
		if (accept[i]) return i;
	return 0;
}
void NFA::Demo(FILE* fp) const
{
	size_t i, first, count;
	//size_t To;
	char U, L;
	fprintf(fp, "\nStateAmount = %zu.\n", StateAmount);
	fprintf(fp, "accepted state amount= %zu.\n", accepted);
	fprintf(fp, "Amount od Arcs = %zu.\n", graph.arcs.count());
	fprintf(fp, "=========================================================\n");
	for (i = 0; i < StateAmount; i++)
	{
		fprintf(fp, "State[%zu], Arc count: %zu, ", i, graph.ArcCount(i));
		fprintf(fp, "accepted label: [%d]\n", graph.vertice[i].content);
		count = 0;
		first = graph.vertice[i].first;
		while (first != SizeMax)
		{
			fprintf(fp, "\tNo[%zu], to: %zu, ", count, graph.ArcTo(first));
			if (graph.arcs[first].content.epsilon)
				fprintf(fp, "a default epsilon conversion.\n");
			else
			{
				U = graph.arcs[first].content.upper;
				L = graph.arcs[first].content.lower;
				fprintf(fp, "label: ");
				RegTree::Demo(fp, L, U);
				fprintf(fp, "\n");
			}
			count += 1;
			first = graph.arcs[first].next;
		}
	}
	fprintf(fp, "=========================================================\n");
}

sheetDFA::sheetDFA(const NFA& nfa) : sheet(CharSize)
{
	list<size_t> stack;
	list<size_t> auxiliary;
	matlist<bool> Dstates(nfa.StateAmount);
	size_t now, old;
	bool* state;
	vec<bool> to;
	int ele;
	size_t Scount;
	size_t NewSite_;


	to.Malloc(nfa.StateAmount);
	auxiliary.reshape(nfa.StateAmount);
	auxiliary.refresh();
	state = Dstates.append();
	
	nfa.initial(state, auxiliary);
	//return;
	stack.append(0);
	sheet.append();
	//return;
	while (stack.pop(now) != 0)
	{
		//std::cout << "****************state number = " << now << ";" << std::endl;
		//Demo(stdout, Dstates[now], nfa.StateAmount);
		for (ele = 0; (size_t)ele < CharSize; ele++)
		{
			
			//std::cout << "ele[" << (size_t)ele << "] = " << (char)ele << ";" << std::endl;
			state = Dstates[now];
			Scount = nfa.move(state, to.vector(), (char)ele, auxiliary);
			//if (state[7])
			//{
				//std::cout << "Scount: " << Scount << ", No: " << ele << ", ele: " << (char)ele << std::endl;
				//Demo(stdout, state, nfa.StateAmount);
				//Demo(stdout, to.vector(), nfa.StateAmount);
				//']','Z', '[';
			//}
			//std::cout << "Scount: " << Scount << ");" << std::endl;
			if (Scount == 0) sheet[now][(size_t)ele] = 0;
			else
			{
				//std::cout << "Scount: " << Scount << ", No: " << ele << ", ele: " << (char)ele << std::endl;
				//bool tempKK;
				//tempKK = state[7];
				//if (state[7]) std::cout << "All is well 1 " << std::endl;
				old = Dstates.row();
				//if (state[7]) std::cout << "All is well 2 " << std::endl;
				NewSite_ = Dstates.SearchAdd(to.vector());
				//if (state[7]) std::cout << "All is well 2.5 " << std::endl;
				//else std::cout << "All is wrong 2.5 " << std::endl;
				sheet[now][(size_t)ele] = NewSite_;
				//sheet[now][(size_t)ele] = Dstates.SearchAdd(to.vector());
				//if (tempKK) std::cout << "All is well 3: " << NewSite_ << std::endl;
				if (old != Dstates.row())
				{
					//std::cout << "Scount: " << Scount << ", No: " << ele << ", ele: " << (char)ele << std::endl;
					//std::cout << "To *****new***** state: " << old << " : ";
					//Demo(stdout, to.vector(), nfa.StateAmount);
					sheet.append();
					stack.append(old);
				}
				//else
				//{
					//std::cout << "To old state: " << old << std::endl;
				//}
				//if (state[7]) std::cout << "All is well 4" << std::endl;
				//if (old != Dstates.row()) Demo(stdout, Dstates[old], nfa.StateAmount);
			}
			//if (true)
			//{
			//	std::cout << "=========Scount: " << Scount << ", No: " << ele << ", ele: " << (char)ele << std::endl;
				//Demo(stdout, state, nfa.StateAmount);
			//}
			//std::cout << "Scount: " << Scount << ");" << std::endl;
		}
		//std::cout << "now: (" << now << ");" << std::endl;
	}
	//std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
	//Demo(stdout, Dstates[old], nfa.StateAmount);
	count = Dstates.row();
	acceptSet(Dstates, nfa);
}
sheetDFA::~sheetDFA()
{

}
void sheetDFA::acceptSet(const matlist<bool>& Dstates, const NFA& nfa)
{
	matlist<bool> __AcceptSheet(nfa.accepted + 1);
	list<size_t> __accpetedCount;
	size_t i;
	//size_t to, j;
	bool* __AcceptList;
	//int* SheetTemp;
	//char ele;
	//std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
	AcceptCount = nfa.accepted;
	accept.refresh(Dstates.row());
	__AcceptSheet.refresh(__AcceptSheet.column(), Dstates.row());
	//std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
	for (i = 0; i < Dstates.row(); i++)
	{
		__AcceptList = __AcceptSheet.append();
		//for (j = 0; j < CharSize; j++) accept[i][j] = 0;
		__accpetedCount.append(nfa.GetAccepted(Dstates[i], __AcceptList));
		accept[i] = nfa.FirstAccepted(__AcceptList);
		//std::cout << "__accpetedCount[]: " << __accpetedCount[i] << std::endl;
		//std::cout << "accept[i]: " << accept[i] << std::endl;
		//Demo(stdout, Dstates[i], Dstates.column());
	}
	//std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
	//for (i = 0; i < Dstates.row(); i++)
	//{
	//	if (__accpetedCount[i] == 0) continue;
	//	SheetTemp = sheet[i];
	//	for (ele = 0; (size_t)ele < CharSize; ele++)
	//	{
	//		to = SheetTemp[(size_t)ele];
	//		if (__accpetedCount[to] == 0) accept[i][(size_t)ele] = nfa.FirstAccepted(__AcceptSheet[i]);
	//	}
	//}
}
int sheetDFA::next(int state, const char c)const
{
	return sheet[(size_t)state][(size_t)c];
}
int sheetDFA::action(int state)const
{
	return accept[(size_t)state];
}
void sheetDFA::Demo(FILE* fp)const
{
	size_t i, j, arc;
	char U, L;
	int state, to, acc;
	U = '?';
	L = '?';
	to = 0;
	fprintf(fp, "=========================================================\n");
	fprintf(fp, "\nStateAmount = %zu.\n", count);
	fprintf(fp, "accepted state amount= %zu.\n", AcceptCount);
	//fprintf(fp, "Amount od Arcs = %llu.\n", graph.arcs.count());
	fprintf(fp, "=========================================================\n");
	for (i = 0; i < count; i++)
	{
		acc = action(i);
		fprintf(fp, "State[%zu]: acc = %d\n", i, acc);
		state = 0;
		arc = 0;
		for (j = 0; j < CharSize; j++)
		{
			switch (state)
			{
			case 0:
				if (sheet[i][j] != 0)
				{
					L = j;
					to = sheet[i][j];
					state = 1;
				}
				break;
			case 1:
				if (to != sheet[i][j])
				{
					U = j - 1;
					fprintf(fp, "\t Arc[%zu]: ", arc);
					arc += 1;
					RegTree::Demo(fp, L, U);
					
					fprintf(fp, ", to: %d.\n", to);
					if (sheet[i][j] != 0)
					{
						L = j;
						to = sheet[i][j];
					}
					else state = 0;
				}
				break;
			}
		}
		if (state == 1)
		{
			U = (char)(CharSize - 1);
			fprintf(fp, "\t Arc[%zu]: ", arc);
			RegTree::Demo(fp, L, U);
			acc = action((int)i);
			fprintf(fp, ", to: %d, acc = %d.\n", to, acc);
			fprintf(fp, ", to: %d.\n", to);
		}
	}
}
void sheetDFA::Demo(FILE* fp, const bool* state, size_t n)
{
	size_t i, count;
	for (i = 0, count = 0; i < n; i++)
		count += state[i] ? 1 : 0;
	fprintf(fp, "count: %6zu | ", count);
	for (i = 0, count = 0; i < n; i++)
		if(state[i]) fprintf(fp, "%zu ", i);
	fprintf(fp, "\n");
}
void sheetDFA::shrink(void)
{
	ShrinkList* SL;
	//list<int> state_record;
	size_t i, j, toRecord, now, state, NewS, nextS;
	size_t toNow;
	bool change;
	SL = new ShrinkList(AcceptCount + 1, sheet.row());
	for (i = 0; i < sheet.row(); i++)
		SL->Insert(i, accept[i]);
	//SL->Demo(stdout);
	do
	{
		change = false;
		for (state = 0; state < SL->Statecount; state++)
		{
			for (j = 0; j < CharSize; j++)
			{
				now = SL->Head(state);
				toRecord = SL->group[sheet[now][j]];
				NewS = SizeMax;
				//printf("state: %zu, char:%c", state, (char)j);
				nextS = SL->next[now];
				//printf(", now: %zu, nextS:%zu\n", now, nextS);
				while (nextS != SizeMax)
				{
					toNow = SL->group[sheet[nextS][j]];
					change = change || (toNow != toRecord);
					if (toNow != toRecord)
					{
						//printf("\t\tstate: %zu, char:%c, ", state, (char)j);
						//printf("now: %zu, nextS:%zu, ", now, nextS);
						//printf("toNow: %zu, toRecord:%zu", toNow, toRecord);
						NewS = SL->NewState(NewS);
						SL->DeleteNext(now);
						SL->Insert(nextS, NewS);
						//nextS = SL->next[now];
						//printf(", nextS:%zu\n", nextS);
					}
					else now = nextS;
					nextS = SL->next[now];
					//printf("\tnow: %zu, nextS:%zu\n", now, nextS);
				}
				if (change) break;
			}
			if (change) break;
		}
	} while (change);
	shrink(SL);
	delete SL;
}
void sheetDFA::shrink(const ShrinkList* SL)
{
	//SL->Demo(stdout);
	matlist<int> Newsheet(sheet.column());
	list<int> Newaccept;
	size_t Newcount;
	size_t i, j;
	Newcount = SL->Statecount;
	Newsheet.refresh(sheet.column(), Newcount);
	Newaccept.refresh(Newcount);
	for (i = 0; i < Newcount; i++)
		Newaccept[i] = accept[SL->head[i]];
	for (i = 0; i < Newcount; i++)
	{
		Newsheet.append();
		for (j = 0; j < CharSize; j++)
		{
			Newsheet[i][j] = SL->group[sheet[SL->head[i]][j]];
		}
	}
	sheet.swap(Newsheet);
	accept.swap(Newaccept);
	count = Newcount;
}

DFA::DFA(const sheetDFA* dfa)
{
	//size_t i, j, arc;
	size_t i, j;
	convert CC;
	//char U, L;
	int state, to;
	//int acc;
	//printf("????\n");
	CC.lower = 'c';
	CC.upper = 'c';
	to = 0;
	graph.refresh();
	StateAmount = dfa->sheet.row();
	AcceptCount = dfa->AcceptCount;
	graph.refresh(StateAmount);
	//printf("StateAmount = %llu\n", StateAmount);
	for (i = 0; i < StateAmount; i++)
		graph.vertice[i].content = dfa->accept[i];
	//printf("????\n");
	for (i = 0; i < dfa->count; i++)
	{ 
		state = 0;
		//arc = 0;
		//printf("%llu==\n", i);
		for (j = 0; j < CharSize; j++)
		{
			switch (state)
			{
			case 0:
				if (dfa->sheet[i][j] != 0)
				{
					CC.lower = j;
					to = dfa->sheet[i][j];
					state = 1;
				}
				break;
			case 1:
				if (to != dfa->sheet[i][j])
				{
					CC.upper = j - 1;
					//printf("%llu==%d\n", i, to);
					//graph.Demo(stdout);
					//printf("%llu==%d\n", i, to);
					
					graph.append(i, to, CC);
					//printf("%llu==%d\n", i, to);
					if (dfa->sheet[i][j] != 0)
					{
						CC.lower = j;
						to = dfa->sheet[i][j];
					}
					else state = 0;
				}
				break;
			}
		}
		if (state == 1)
		{
			CC.upper = CharSize - 1;
			graph.append(i, to, CC);
		}
	}
}
DFA::~DFA()
{
}
int DFA::next(int state, const char c)const
{
	size_t from;
	//from = graph.vertice[(size_t)state].first;
	from = graph.FirstArc((size_t)state);
	while (from != SizeMax)
	{
		if (graph.arcs[from].content.in(c))
			return graph.arcs[from].to;
		from = graph.NextArc(from);
	}
	return 0;
}
int DFA::action(int state)const
{
	return graph.vertice[(size_t)state].content;
}
void DFA::Demo(FILE* fp)const
{
	size_t i, arc, No;
	fprintf(fp, "=========================================================\n");
	fprintf(fp, "\nStateAmount = %llu.\n", (long long unsigned int)StateAmount);
	fprintf(fp, "accepted state amount= %llu.\n", (long long unsigned int)AcceptCount);
	//fprintf(fp, "Amount od Arcs = %llu.\n", graph.arcs.count());
	fprintf(fp, "=========================================================\n");
	for (i = 0; i < StateAmount; i++)
	{
		fprintf(fp, "State[%llu]: acc = %d\n", (long long unsigned int)i, (int)graph.vertice[i].content);
		arc = graph.FirstArc((size_t)i);
		No = 0;
		while (arc != SizeMax)
		{
			fprintf(fp, "\t Arc[%llu]: ", (long long unsigned int)No);
			Demo(fp, graph.arcs[arc].content);
			fprintf(fp, ", to: %llu \n", (long long unsigned int)graph.arcs[arc].to);
			arc = graph.NextArc(arc);
			No += 1;
		}
	}
}
void DFA::Demo(FILE* fp, int L, int U)
{
	if (U != L)
	{
		if (L < 32) fprintf(fp, "[\\%d-", L);
		else fprintf(fp, "[%c-", (char)L);
		if (U < 32) fprintf(fp, "\\%d]", U);
		else fprintf(fp, "%c]", (char)U);
	}
	else
	{
		if (L < 32) fprintf(fp, "[\\%d]", L);
		else fputc(L, fp);
	}
}
void DFA::Demo(FILE* fp, convert& CC)
{
	Demo(fp, CC.lower, CC.upper);
}
void DFA::Cprint(FILE* fp, const char* name) const
{
	size_t i, arc, No;
	fprintf(fp, "int next");
	if (name != NULL) fprintf(fp, "_%s", name);
	fprintf(fp, "(int state, const char c)\n{\n");
	fprintf(fp, "\tswitch (state)\n\t{\n");
	for (i = 0; i < StateAmount; i++)
	{
		fprintf(fp, "\tcase %d:\n", (int)i);
		arc = graph.FirstArc((size_t)i);
		No = 0;
		while (arc != SizeMax)
		{
			if (No == 0)
				fprintf(fp, "\t\tif(");
			else
				fprintf(fp, "\t\telse if(");
			Cprint(fp, graph.arcs[arc].content);
			//Demo(fp, graph.arcs[arc].content);
			fprintf(fp, ") return %llu;\n", (long long unsigned int)graph.arcs[arc].to);
			arc = graph.NextArc(arc);
			No += 1;
		}
		if (No == 0)
			fprintf(fp, "\t\treturn 0;\n");
		else
			fprintf(fp, "\t\telse return 0;\n");
	}
	fprintf(fp, "\t}\n");
	fprintf(fp, "\treturn 0;\n}\n");

	fprintf(fp, "int action");
	if (name != NULL) fprintf(fp, "_%s", name);
	fprintf(fp, "(int state)\n{\n");
	fprintf(fp, "\tswitch (state)\n\t{\n");
	for (i = 0; i < StateAmount; i++)
	{
		No = graph.vertice[i].content;
		if (No == 0) continue;
		fprintf(fp, "\tcase %d:\n", (int)i);
		fprintf(fp, "\t\treturn %llu;\n", (long long unsigned int)No);
	}
	fprintf(fp, "\t}\n");
	fprintf(fp, "\treturn 0;\n}\n");
}
void DFA::Cprint(FILE* fp, convert& CC)
{
	int L; 
	int U;
	L = CC.lower;
	U = CC.upper;
	if (U != L)
	{
		if (L < 32) fprintf(fp, "(char)%d <= c && ", L);
		else fprintf(fp, "\'%c\' <= c && ", (char)L);
		if (U < 32) fprintf(fp, "c <= (char)%d", U);
		else fprintf(fp, "c <= \'%c\'", (char)U);
	}
	else
	{
		if (L < 32) fprintf(fp, "c == (char)%d", L);
		else fprintf(fp, "c == \'%c\'", (char)L);
	}

}

ShrinkList::ShrinkList(size_t AcceptCount, size_t size)
{
	size_t i;
	//size_t j, toRecord, now;
	group.Malloc(size);
	next.Malloc(size);
	Statecount = AcceptCount;
	head.refresh(Statecount);
	rear.refresh(Statecount);
	for (i = 0; i < Statecount; i++)
	{
		head[i] = SizeMax;
		rear[i] = SizeMax;
	}
	for (i = 0; i < size; i++) next[i] = SizeMax;

}
ShrinkList::~ShrinkList()
{
}
void ShrinkList::Insert(size_t site, size_t state)
{
	group[site] = state;
	next[site] = SizeMax;
	if (head[state] == SizeMax) head[state] = site;
	else next[rear[state]] = site;
	rear[state] = site;
}
size_t ShrinkList::NewState(size_t Now)
{
	if (Now != SizeMax) return Now;
	head.append(SizeMax);
	rear.append(SizeMax);
	Statecount += 1;
	return Statecount - 1;
}
size_t ShrinkList::DeleteNext(size_t now)
{
	size_t deleted, Sstate;
	deleted = next[now];
	Sstate = group[deleted];
	next[now] = next[deleted];
	if (deleted == rear[Sstate])  rear[Sstate] = now;
	return deleted;
}
size_t ShrinkList::Head(size_t state)const
{
	return head[state];
}
size_t ShrinkList::Count(void)const
{
	return Statecount;
}
void ShrinkList::Demo(FILE* fp)const
{
	size_t i;
	fprintf(fp, "Statecount = %llu\n", (long long int)Statecount);
	for (i = 0; i < group.size(); i++)
	{
		fprintf(fp, "\tgroup[%llu] = %llu, ", (long long int)i, (long long int)(group[i]));
		fprintf(fp, "next[%llu] = %llu\n", (long long int)i, (long long int)(next[i]));
	}
	fprintf(fp, "\n");
	for (i = 0; i < Statecount; i++)
	{
		fprintf(fp, "\thead[%llu] = %llu, ", (long long int)i, (long long int)(head[i]));
		fprintf(fp, "rear[%llu] = %llu\n", (long long int)i, (long long int)(rear[i]));
	}
}

grammerS::grammerS()
{
	ERROR = undone;
	count = 0;
	TerminalCount = 0;
	
	epsilon = 0;
	end = 0;
}
grammerS::~grammerS()
{
	size_t i;
	for (i = 0; i < name.count(); i++)
	{
		free((void*)name[i]);
	}
	for (i = 0; i < ternimal.count(); i++)
	{
		free((void*)ternimal[i]);
	}
}
int grammerS::build(FILE* fp)
{
	BufferChar input;
	input << fp;
	return build(input);
}
int grammerS::nextTest(int state, const char c)
{
	switch (state)
	{
	case 0:
		if (c == (char)10) return 3;
		else if (c == (char)13) return 8;
		else if (c == ' ') return 2;
		else if (c == '-') return 7;
		else if (c == ';') return 6;
		else if ('A' <= c && c <= 'Z') return 5;
		else if (c == '_') return 5;
		else if ('a' <= c && c <= 'z') return 5;
		else if (c == '|') return 1;
		else return 0;
	case 1:
		return 0;
	case 2:
		if (c == ' ') return 2;
		else return 0;
	case 3:
		if (c == (char)10) return 3;
		else if (c == (char)13) return 8;
		else return 0;
	case 4:
		return 0;
	case 5:
		if ('0' <= c && c <= '9') return 5;
		else if ('A' <= c && c <= 'Z') return 5;
		else if (c == '_') return 5;
		else if ('a' <= c && c <= 'z') return 5;
		else return 0;
	case 6:
		return 0;
	case 7:
		if (c == '>') return 4;
		else return 0;
	case 8:
		if (c == (char)10) return 3;
		else return 0;
	}
	return 0;
}
int grammerS::actionTest(int state)
{
	switch (state)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
	case 4:
		return 4;
	case 5:
		return 5;
	case 6:
		return 6;
	}
	return 0;
	//1 : |
	//2 : space
	//3 : enter
	//4 : ->
	//5: id
	//6: ;
}
bool grammerS::RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar &intermediate)
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
	intermediate.refresh();
	state = 0;
	acc = 0;
	action = 0;
	accept = 0;
	result.refresh();
	while (input.dequeue(now))
	{
		/*state switch*/
		state = nextTest(state, now);
		acc = actionTest(state);
		accept = acc != 0 ? acc : accept;
		switch (action)
		{
		case 0:
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
		case 1:
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
				intermediate.refresh();
				action = 2;
			}
			else intermediate.append(now);//continue 
			break;
		case 2:
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
int grammerS::build(BufferChar& input)
{
	BufferChar result;
	BufferChar intermediate;
	list<size_t> site, InvSite;
	int accept;
	int state;
	long long int temp;
	const char* Result;
	production PP;
	size_t from, i, j;
	size_t Count_;//degeneracy
	list<const char*> nameTemp;
	PP.symbol = 0;
	state = 0;
	from = 0;
	Count_ = 0;
	//accept == 4: ->
	//accept == 5: id
	while (RunBuild(accept, result, input, intermediate))
	{
		if (accept == 0)
		{
			char aa;
			input.dequeue(aa);
			continue;
		}
		Result = result.vector();
		//fprintf(stdout, "<%s, %d>\n", Result, accept);
		//fprintf(stdout, "%s", result.vector());
		//continue;
		switch (state)
		{
		case 0:
			if (compare(Result, "terminal")) state = 1;
			break;
		case 1:
			if (accept == 5)
			{
				if (compare(Result, "epsilon") || compare(Result, "END-EOF"))
				{
					ERROR = unexpectedTernimal;
					return (int)unexpectedTernimal;
				}
				state = 2;
				Tappend(Result);
			}
			break;
		case 2:
			if (accept == 6)
			{
				state = 3;
				TerminalCount = ternimal.count();
				epsilon = TerminalCount;
				epsilon = -epsilon - 1;
				end = epsilon - 1;
				Tappend("epsilon");
				Tappend("END-EOF");
				count = 0;
			}
			else if (accept == 1) state = 1;
			else if (accept == 5)
			{
				ERROR = missingdivision;
				return (int)missingdivision;
			}
			break;
		case 3:
			if (accept == 5) 
			{
				Count_ = 0;
				count += 1;
				site.append(SearchAppend(Result));
				prefix.append(from);
				state = 4;
			}
			break;
		case 4:
			if (accept == 4) state = 5;
			else if (accept == 5)
			{
				ERROR = missingdivision;
				return (int)missingdivision;
			}
			break;
		case 5:
			if (accept == 5)
			{
				Count_ += 1;
				state = 6;
				PP.length = 1;
				PP.begin = all.count();
				temp = SearchTerminal(Result);
				//fprintf(stdout, "temp: %lld, Result: %s\n", temp, Result);
				if (temp == 0) temp = SearchAppend(Result);
				all.append(temp);
			}
			break;
		case 6:
			if (accept == 5)
			{
				PP.length += 1;
				temp = SearchTerminal(Result);
				//fprintf(stdout, "temp: %lld, Result: %s\n", temp, Result);
				if (temp == 0) temp = SearchAppend(Result);
				all.append(temp);
			}
			else if (accept == 1)
			{
				rules.append(PP);
				state = 5;
			}
			else if (accept == 6)
			{
				rules.append(PP);
				from += Count_;
				degeneracy.append(Count_);
				state = 3;
			}
			break;
		}
	}
	if (count != name.count())
	{
		ERROR = missingRulesOrWrongSymbol;
		return (int)missingRulesOrWrongSymbol;
	}
	//count = name.count();
	inverse(InvSite, site);
	//for (from = 0; from < site.count(); from++)
	//{
	//	fprintf(stdout, "No[%zu]: site: %zu, inv: %zu, name: %s\n", from, site[from], InvSite[from], name[from]);
	//}
	nameTemp.refresh(count);
	for (i = 0; i < count; i++)
		nameTemp[i] = name[site[i]];
	for (i = 0; i < count; i++) name[i] = nameTemp[i];
	for (i = 0; i < all.count(); i++)
	{
		if (all[i] >= 0) all[i] = (long long int)InvSite[all[i]];
	}
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < degeneracy[i]; j++)
		{
			rules[prefix[i] + j].symbol = i;
		}
	}
	//return 0;
	FirstBiuld();
	//return 0;
	FollowBiuld();
	ERROR = done;
	return (int)done;
}
void grammerS::SetExample(void)
{
	size_t i;
	count = 3; // 非终结符数量
	TerminalCount = 5; // 终结符数量

	// 设置非终结符的名称
	append("E");
	append("T");
	append("F");
	
	// 设置终结符的名称


	Tappend("+");//-1
	Tappend("*");//-2
	Tappend("(");//-3
	Tappend(")");//-4
	Tappend("id");//-5

	Tappend("epsilon");//-6
	Tappend("END-EOF");//-7
	// 设置每个非终结符的 degeneracy

	epsilon = TerminalCount;
	epsilon = -epsilon - 1;
	end = epsilon - 1;

	degeneracy.append(2); 
	degeneracy.append(2);
	degeneracy.append(2);

	size_t pp;
	pp = 0;
	for (i = 0; i < degeneracy.count(); i++)
	{
		prefix.append(pp);
		pp += degeneracy[i];
	}

	// 设置产生式规则
	production PP;
	PP.begin = 0;
	all.append(0);
	all.append(-1);
	all.append(1);
	PP.length = 3;
	rules.append(PP);

}
void grammerS::Demo(FILE* fp) const
{
	size_t i, j, k;
	//size_t site;
	long long int index;
	//long long int  *R;
	production PP;
	fprintf(fp, "error code: %d\n", (int)ERROR);
	fprintf(fp, "count: %zu\n", count);
	fprintf(fp, "TerminalCount: %zu\n", TerminalCount);
	for (i = 0; i < TerminalCount; i++)
	{
		fprintf(fp, "\tNo[%zu] terminal symbol: %s\n", i, ternimal[i]);
	}
	for (i = 0; i < count; i++)
	{
		fprintf(fp, "%s: prefix: %zu, degeneracy: %zu\n", name[i], prefix[i], degeneracy[i]);
		for (j = 0; j < degeneracy[i]; j++)
		{
			PP = rules[prefix[i] + j];
			fprintf(fp, "\tNo[%zu] production rules: %s->", j, name[PP.symbol]);
			//PP = rules[prefix[i] + j];
			for (k = 0; k < PP.length; k++)
			{
				index = all[PP.begin + k]; 
				if (index >= 0)
					fprintf(fp, "%s ", name[index]);
				else
					fprintf(fp, "%s ", ternimal[-index - 1]);
			}
			fprintf(fp, "\n");
		}
	}
	//return;
	for (i = 0; i < count; i++)
	{
		fprintf(fp, "No[%zu] non-terminal symbol: %s.\n\tFIRST: ", i, name[i]);
		for (j = 0; j < TerminalCount + 2; j++)
			if(first[i][j]) 
				fprintf(fp, "%s  ", ternimal[j]);
		fprintf(fp, "\n\t FOLLOW: ");
		for (j = 0; j < TerminalCount + 2; j++)
			if (follow[i][j])
				fprintf(fp, "%s  ", ternimal[j]);
		fprintf(fp, "\n");
	}
}
void grammerS::Demo(FILE* fp, size_t rule, size_t dot) const
{
	production PP;
	size_t i;
	long long int index;
	PP = rules[rule];
	fprintf(fp, "%s->",name[PP.symbol]);
	if ((PP.length == 1) && all[PP.begin] == epsilon)
	{
		fprintf(fp, "@");
	}
	else
	{
		for (i = 0; i < PP.length; i++)
		{
			if (i == dot)
				fprintf(fp, "@ ");
			index = all[PP.begin + i];
			if (index >= 0)
				fprintf(fp, "%s ", name[index]);
			else
				fprintf(fp, "%s ", ternimal[-index - 1]);
		}
		if (dot == PP.length)
			fprintf(fp, "@");
	}
}
const char* grammerS::SymbolGet(long long int index) const
{
	if (index >= 0) return name[index];
	else return ternimal[-index - 1];
}
const long long int* grammerS::vector(size_t No)const
{
	return all.vector(rules[No].begin);
}
size_t grammerS::SearchAppend(const char* input)
{
	size_t i;
	for (i = 0; i < name.count(); i++)
		if (compare(input, name[i])) return i;
	append(input);
	return i;
}
long long int grammerS::SearchTerminal(const char* input)
{
	long long int i, length;
	length = ternimal.count();
	for (i = 0; i < length; i++)
		if (compare(input, ternimal[i])) return -i - 1;
	return 0;
}
void grammerS::append(const char* input)
{
	char* nnnn;
	size_t length, i;
	for (length = 0; input[length] != '\0'; length++);
	length += 1;
	nnnn = (char*)malloc(sizeof(char) * length);
	for (i = 0; i < length; i++) nnnn[i] = input[i];
	name.append(nnnn);
}
void grammerS::Tappend(const char* input)
{
	char* nnnn;
	size_t length, i;
	for (length = 0; input[length] != '\0'; length++);
	length += 1;
	nnnn = (char*)malloc(sizeof(char) * length);
	for (i = 0; i < length; i++) nnnn[i] = input[i];
	ternimal.append(nnnn);
}

void grammerS::FirstBiuld(void)
{
	size_t i, j, k;
	//size_t l;
	production PP;
	//long long int temp; 
	long long int * vect;
	bool change;
	first.refresh(count, TerminalCount + 2, count);
	first.value(false);
	//fprintf(stdout, "first.row(): %zu, first.column(): %zu,  first.length(): %zu.\n", first.row(), first.column(), first.length());
	//for (i = 0; i < count; i++)
	//{
	//	for (j = 0; j < degeneracy[i]; j++)
	//	{
	//		k = prefix[i] + j;
	//		PP = rules[k];
	//		temp = all[PP.begin];
			//fprintf(stdout, "i: %zu, j: %zu, k: %zu, temp: %lld, first[i]: %zu\n", i, j, k, temp, (size_t)first[i]);
	//		if (temp < (long long int)0) first[i][(size_t)(-temp - 1)] = true;
	//	}
	//}
	//return;
	do
	{
		change = false;
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < degeneracy[i]; j++)
			{
				k = prefix[i] + j;
				PP = rules[k];
				vect = all.vector(PP.begin);
				change = change || AddFirstBeta(first[i], PP.length, vect);
				//change = change || FirstOr(vect[0], i);
				//change = change || Or(vect[0], first[i]);
				//for (l = 1; l < PP.length; l++)
				//{
				//	if (IfEpsilon(vect[l - 1]))
						//change = change || FirstOr(vect[l], i);
				//		change = change || Or(vect[l], first[i]);
				//	else break;
				//}
				//if (l == PP.length && IfEpsilon(vect[l - 1]))
				//{
				//	change = change || !first[i][TerminalCount];
				//	first[i][TerminalCount] = true;
				//}
			}
		}
	} while (change);

}
bool grammerS::IfaRuleEpsilon(size_t site) const
{
	return all[rules[site].begin] == epsilon;
}
bool grammerS::IfEpsilon(long long int site) const
{
	if (site > 0) return first[site][TerminalCount];
	else return (site == epsilon);
}
bool grammerS::FirstOr(long long int symbol, bool* to) const
{
	//size_t i;
	bool change;
	change = false;
	if (symbol < 0)//symbol is terminal
	{
		if (symbol != epsilon)
		{
			change = !to[-symbol - 1];
			to[-symbol - 1] = true;
		}
	}
	else//symbol is non-terminal
		change = Or(first[symbol], to);
	return change;
}
bool grammerS::Or(const bool* from, bool* to) const
{
	size_t i;
	bool change;
	change = false;
	for (i = 0; i < TerminalCount; i++)
	{
		change = change || (from[i] && !to[i]);
		to[i] = to[i] || from[i];
	}
	i = TerminalCount + 1;
	change = change || (from[i] && !to[i]);
	to[i] = to[i] || from[i];
	return change;
}
bool grammerS::FollowOr(const bool* from, size_t to)
{
	size_t i;
	bool change;
	change = false;
	for (i = 0; i < TerminalCount + 2; i++)
	{
		change = change || (from[i] && !follow[to][i]);
		follow[to][i] = follow[to][i] || from[i];
	}
	return change;
}
bool grammerS::AddFirstBeta(bool* result, size_t L, const long long int* in) const
{
	size_t i;
	bool change;
	change = FirstOr(in[0], result);
	for (i = 1; i < L; i++)
	{
		if (IfEpsilon(in[i - 1]))
			change = change || FirstOr(in[i], result);
		else break;
	}
	if (i == L && IfEpsilon(in[i - 1]))
	{
		change = change || !result[TerminalCount];
		result[TerminalCount] = true;
	}
	return change;
}
void grammerS::FirstBeta(bool* result, size_t L, const long long int* in) const
{
	size_t i;
	//bool change;
	for (i = 0; i < TerminalCount + 2; i++) result[i] = false;
	AddFirstBeta(result, L, in);
}
void grammerS::FollowBiuld(void)
{
	size_t i, j, k, l;
	production PP;
	list<bool> FB;
	//long long int temp;
	long long int* vect;
	bool change;

	follow.refresh(count, TerminalCount + 2, count);
	FB.refresh(TerminalCount + 2);
	follow.value(false);
	follow[0][TerminalCount + 1] = true;
	//return;
	do
	{
		change = false;
		for (i = 0; i < count; i++)
		{
			for (j = 0; j < degeneracy[i]; j++)
			{
				k = prefix[i] + j;
				PP = rules[k];
				vect = all.vector(PP.begin);
				if (vect[PP.length - 1] >= 0)
					change = change || FollowOr(follow[i], vect[PP.length - 1]);
				for (l = 0; l < PP.length - 1; l++)
				{
					if (vect[l] < (long long int)0) continue;
					FirstBeta(FB.vector(), PP.length - 1 - l, vect + l + 1);
					if (FB[TerminalCount] == true)
					{
						change = change || FollowOr(follow[i], vect[l]);
					}
					change = change || Or(FB.vector(), follow[vect[l]]);
				}
			}
		}
	} while (change);
}

LR0::LR0(const grammerS* G)
{
	list<size_t> RulesPrefix;
	list<size_t> RulesCount;
	size_t prefix_, count__, length__;
	size_t i, j;
	const long long int* vect;
	//size_t k, l, NonT;
	size_t k, l;
	prefix_ = 0;
	
	for (i = 0; i < G->rules.count(); i++)
	{
		length__ = G->rules[i].length;
		vect = G->vector(i);
		if (length__ == 1 && vect[0] == G->epsilon)
			count__ = 1;
		else count__ = length__ + 1;
		RulesPrefix.append(prefix_);
		prefix_ += count__;
		RulesCount.append(count__);
	}
	graph.refresh(prefix_);
	for (i = 0; i < G->rules.count(); i++)
	{
		prefix_ = RulesPrefix[i];
		count__ = RulesCount[i];
		vect = G->vector(i);
		for (j = 0; j + 1 < count__; j++)
		{
			graph[prefix_ + j].dot = j;
			graph[prefix_ + j].rules = i;
			graph.append(prefix_ + j, prefix_ + j + 1, false, vect[j]);
			if (vect[j] < (long long int)0) continue;
			//NonT = vect[j];
			for (k = 0; k < G->degeneracy[vect[j]]; k++)
			{
				l = G->prefix[vect[j]] + k;
				graph.append(prefix_ + j, RulesPrefix[l], true, G->epsilon);
				if(RulesCount[l]==1) 
					graph.append(prefix_ + j, prefix_ + j + 1, true, G->epsilon);
			}
		}
		graph[prefix_ + count__ - 1].dot = j;
		graph[prefix_ + count__ - 1].rules = i;
	}


	graph.build(sheet, Dstates, G->count, G->TerminalCount);
	TerminalCount = G->TerminalCount;
	NonTerminalCount = G->count;
}
//void LR0::build(const grammerS* G)
//{
	//item aa;
	//aa.dot = 1;
	//aa.rules = 2;
	//graph.vertice.SearchAppend(aa);
//s}
LR0::~LR0()
{
}
void LR0::Demo(FILE* fp, const grammerS* G)
{
	size_t i, j, now, count;
	item Item;
	long long int index;
	fprintf(fp, "Items count: vertice.count() = %zu\n", graph.vertice.count());
	fprintf(fp, "arcs.count() = %zu\n", graph.arcs.count());
	for (i = 0; i < graph.vertice.count(); i++)
	{
		Item = graph[i];
		fprintf(fp, "No[%5zu] item, rule: %5zu, dot: %5zu, arc count: %zu:", i, Item.rules, Item.dot, graph.ArcCount(i));
		G->Demo(fp, Item.rules, Item.dot);
		fprintf(fp, "\n");
		now = graph.vertice[i].first;
		while (now != SizeMax)
		{
			if (graph.arcs[now].epsilon)
			{
				fprintf(fp, "\t symbol: epsilon, to: %5zu: ", graph.arcs[now].to);
			}
			else
			{
				fprintf(fp, "\t symbol: %s, to: %5zu: ", G->SymbolGet(graph.arcs[now].symbol), graph.arcs[now].to);
			}
			Item = graph[graph.arcs[now].to];
			G->Demo(fp, Item.rules, Item.dot);
			fprintf(fp, "\n");
			now = graph.NextArc(now);
		}
	}

	
	fprintf(fp, "Closure count: %zu, sheet row: %zu\n", Dstates.row(), sheet.row());
	for (i = 0; i < Dstates.row(); i++)
	{
		count = 0;
		for (j = 0; j < Dstates.column(); j++)
			count += Dstates[i][j] ? 1 : 0;
		fprintf(fp, "No[%5zu] closure, items count: %zu, ", i, count);
		count = 0;
		for (j = 0; j < sheet.column(); j++)
			count += sheet[i][j] !=  -1 ? 1 : 0;
		fprintf(fp, "convert count: %zu\n", count);
		count = 0;
		for (j = 0; j < Dstates.column(); j++)
			if (Dstates[i][j])
			{
				fprintf(fp, "\tNo[%5zu] item = %5zu ", count, j);
				Item = graph[j];
				G->Demo(fp, Item.rules, Item.dot);
				fprintf(fp, "\n");
				count += 1;
			}
		count = 0;
		for (j = 0; j < sheet.column(); j++)
			if (sheet[i][j] != -1)
			{
				index =  j < G->count ? j : -(long long int)(j + 1 - G->count);
				fprintf(fp, "\t\tNo[%5zu] index = %5lld, symbol: %s, to: %d", count, index, G->SymbolGet(index), sheet[i][j]);
				fprintf(fp, "\n");
				count += 1;
			}
	}
}

LR1::LR1(const grammerS* G)
{
	list<size_t> stack;
	size_t now, RulesLength_, NewV, i, j;
	item I, To, Default;
	const long long int* List_;
	long long int Symbol__;
	bool IfAppend;

	size_t firstRules, countRules;
	list<bool> symbolT;
	list<long long int> beta__;

	I.dot = 0;
	I.rules = 0;
	I.symbol = G->end;
	now = 0;
	graph.VortexAppend(I);
	stack.append(now);

	symbolT.refresh(G->TerminalCount + 2);

	while (stack.pop(now) != 0)
	{
		Demo(stdout, now, G);
		I = graph[now];
		RulesLength_ = G->rules[I.rules].length;
		List_ = G->vector(I.rules);
		if (I.dot == RulesLength_) continue;
		if ((List_[0] == G->epsilon) && (RulesLength_ == 1)) continue;
		To.dot = I.dot + 1;
		To.rules = I.rules;
		To.symbol = I.symbol;
		NewV = SearchAppend(To, IfAppend);
		if (IfAppend) stack.append(NewV);
		Symbol__ = List_[I.dot];
		graph.append(now, NewV, false, Symbol__);
		//compute FIRST(beta symbol)
		beta__.refresh();
		for (i = I.dot + 1; i < RulesLength_; i++)
			beta__.append(List_[i]);
		beta__.append(I.symbol);
		G->FirstBeta(symbolT.vector(), beta__.count(), beta__.vector());
		//add closure
		if (Symbol__ >= 0)
		{
			firstRules = G->prefix[Symbol__];
			countRules = G->degeneracy[Symbol__];
			for (i = firstRules; i < firstRules + countRules; i++)
			{
				Default.dot = 0;
				Default.rules = i;
				for (j = 0; j < symbolT.count(); j++)
				{
					if (symbolT[j])
					{
						Default.symbol = -(long long int)(j + 1);
						NewV = SearchAppend(Default, IfAppend);
						if (IfAppend) stack.append(NewV);
						graph.append(now, NewV, true, G->epsilon);
					}
				}
				if (G->IfaRuleEpsilon(i))
				{
					NewV = SearchAppend(To, IfAppend);
					graph.append(now, NewV, true, G->epsilon);
				}
			}
		}
		
	}

	graph.build(sheet, Dstates, G->count, G->TerminalCount);

	TerminalCount = G->TerminalCount;
	NonTerminalCount = G->count;
}
LR1::~LR1()
{

}
void LR1::Demo(FILE* fp, size_t site, const grammerS* G)
{
	item Item;
	Item = graph[site];
	fprintf(fp, "item = %5zu, rule: %5zu, dot: %5zu, ", site, Item.rules, Item.dot);
	fprintf(fp, "symbol: %5lld, arc count: %zu:[", Item.symbol, graph.ArcCount(site));
	G->Demo(fp, Item.rules, Item.dot);
	fprintf(fp, ", %s]\n", G->SymbolGet(Item.symbol));
}
void LR1::Demo(FILE* fp, const grammerS* G)
{
	//size_t i, j, RR, now, count;
	size_t i, j, now, count;
	//item Item;
	long long int index;
	fprintf(fp, "Items count: vertice.count() = %zu\n", graph.vertice.count());
	fprintf(fp, "arcs.count() = %zu\n", graph.arcs.count());
	for (i = 0; i < graph.vertice.count(); i++)
	{
		Demo(fp, i, G);
		now = graph.vertice[i].first;
		while (now != SizeMax)
		{
			if (graph.arcs[now].epsilon)
			{
				fprintf(fp, "\t symbol: epsilon, to: %5zu: ", graph.arcs[now].to);
			}
			else
			{
				fprintf(fp, "\t symbol: %s, to: %5zu: ", G->SymbolGet(graph.arcs[now].symbol), graph.arcs[now].to);
			}
			//Item = graph[graph.arcs[now].to];
			Demo(fp, graph.arcs[now].to, G);
			//G->Demo(fp, Item.rules, Item.dot);
			//fprintf(fp, "\n");
			now = graph.NextArc(now);
		}
		fprintf(fp, "\n");
	}

	fprintf(fp, "Closure count: %zu, sheet row: %zu\n", Dstates.row(), sheet.row());
	for (i = 0; i < Dstates.row(); i++)
	{
		count = 0;
		for (j = 0; j < Dstates.column(); j++)
			count += Dstates[i][j] ? 1 : 0;
		fprintf(fp, "No[%5zu] closure, items count: %zu, ", i, count);
		count = 0;
		for (j = 0; j < sheet.column(); j++)
			count += sheet[i][j] != -1 ? 1 : 0;
		fprintf(fp, "convert count: %zu\n", count);
		count = 0;
		for (j = 0; j < Dstates.column(); j++)
			if (Dstates[i][j])
			{
				fprintf(fp, "\tNo[%5zu] item = %5zu ", count, j);
				Demo(fp, j, G);
				//Item = graph[j];
				//G->Demo(fp, Item.rules, Item.dot);
				//fprintf(fp, "\n");
				count += 1;
			}
		count = 0;
		for (j = 0; j < sheet.column(); j++)
			if (sheet[i][j] != -1)
			{
				index = j < G->count ? j : -(long long int)(j + 1 - G->count);
				fprintf(fp, "\t\tNo[%5zu] index = %5lld, symbol: %s, to: %d", count, index, G->SymbolGet(index), sheet[i][j]);
				fprintf(fp, "\n");
				count += 1;
			}
	}

}
bool LR1::item::operator==(const LR1::item R) const
{
	return (rules == R.rules) && (dot == R.dot) && (symbol == R.symbol);
};
size_t LR1::SearchAppend(const LR1::item & I, bool & IfAppend)
{
	size_t i, length;
	item temp;
	//bool middle;
	length = graph.vertice.count();
	IfAppend = false;
	for (i = 0; i < length; i++)
	{
		temp = graph.vertice[i].content;
		if (temp == I) return i;
	}
	IfAppend = true;
	graph.VortexAppend(I);
	return length;
}

Gsheet::Gsheet()
{
	StateCount = 0;
	TerminalCount = 0;
	NonTerminalCount = 0;
	ACTION = NULL;
	GOTO = NULL;

	RulesLength = NULL;
	RulesToSmbol = NULL;

	ET = uninitialized;
}
Gsheet::~Gsheet()
{
	StateCount = 0;
	TerminalCount = 0;
	NonTerminalCount = 0;
	free(ACTION);
	free(GOTO);

	free(RulesLength);
	free(RulesToSmbol);
}
void Gsheet::build(const LR0* lr, const grammerS* G)
{
	size_t i, j, k, column; 
	LR0::item II; 
	grammerS::production PP;
	const matlist<bool>& Dstates = lr->Dstates;
	//const matlist<int>& sheet = lr->sheet;
	const bool* followLine;
	int ErrorTemp;
	bool temp;
	//const LRNFA<LR0::item>& graph = lr->graph;
	//push setting
	//ET = Conflict;
	ErrorTemp = build(lr->sheet, lr->Dstates, G);
	if (ErrorTemp != 0) return;
	//reduce setting
	column = Dstates.column();
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < column; j++)
		{
			if (Dstates[i][j] == true)
			{
				II = lr->graph[j];
				PP = G->rules[II.rules];
				if (II.dot == PP.length)
				{
					if (II.rules == 0 && II.dot == 1)
					{//Sp->S@
						temp = actionAdd(i, TerminalCount, accept, 0);
						if (!temp) return;
					}
					else
					{
						followLine = G->follow[PP.symbol];
						for (k = 0; k < TerminalCount; k++)
						{
							if (followLine[k])
							{
								temp = actionAdd(i, k, reduce, II.rules);
								if (!temp) return;
							}
						}
						if (followLine[TerminalCount + 1])
						{
							temp = actionAdd(i, TerminalCount, reduce, II.rules);
							if (!temp) return;
						}
					}
				}
			}
		}
	ET = NoError;

	build();
	return;
}
void Gsheet::build(const LR1* lr, const grammerS* G)
{
	size_t i, j, column;
	LR1::item II;
	grammerS::production PP;
	const matlist<bool>& Dstates = lr->Dstates;
	//const matlist<int>& sheet = lr->sheet;
	//const bool* followLine;
	int ErrorTemp;
	bool temp;
	//const LRNFA<LR1::item>& graph = lr->graph;
	//push setting
	//ET = Conflict;
	ErrorTemp = build(lr->sheet, lr->Dstates, G);
	if (ErrorTemp != 0) return;
	column = Dstates.column();
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < column; j++)
		{
			if (Dstates[i][j] == true)
			{
				II = lr->graph[j];
				PP = G->rules[II.rules];
				if (II.dot == PP.length)
				{
					if (II.symbol == G->end)
					{
						if (II.rules == 0 && II.dot == 1)
						{
							temp = actionAdd(i, TerminalCount, accept, II.rules);
						}
						else
						{
							temp = actionAdd(i, TerminalCount, reduce, II.rules);
						}
					}
					else 
					{
						temp = actionAdd(i, (size_t)(-II.symbol - 1), reduce, II.rules);
					}
					if (!temp) return;
				}
			}
		}

	build();

	ET = NoError;
}
int Gsheet::build(const matlist<int>& sheet, const matlist<bool>& Dstates, const grammerS* G)
{
	size_t i, j;
	bool temp;
	TerminalCount = G->TerminalCount;
	NonTerminalCount = G->count;
	
	RulesCount = G->rules.count();
	RulesToSmbol = (int*)malloc(sizeof(int) * RulesCount);
	RulesLength = (int*)malloc(sizeof(int) * RulesCount);
	for (i = 0; i < RulesCount; i++)
	{
		RulesToSmbol[i] = G->rules[i].symbol;
		RulesLength[i] = G->rules[i].length;
	}
		
	
	StateCount = Dstates.row();

	ACTION = (infor*)malloc(sizeof(infor) * StateCount * (TerminalCount + 1));
	GOTO = (infor*)malloc(sizeof(infor) * StateCount * NonTerminalCount);

	for (i = 0; i < StateCount; i++)
		for (j = 0; j < NonTerminalCount; j++)
		{
			GOTO[i * NonTerminalCount + j].action = error;
			GOTO[i * NonTerminalCount + j].state = -1;
		}
	for (i = 0; i < StateCount * (TerminalCount + 1); i++)
	{
		ACTION[i].action = error;
		ACTION[i].state = -1;
	}
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < NonTerminalCount; j++)
		{
			if (sheet[i][j] != -1)
			{
				temp = gotoAdd(i, j, push, sheet[i][j]);
				if (!temp) return 1;
			}
		}
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < TerminalCount; j++)
		{
			if (sheet[i][j + NonTerminalCount] != -1)
			{
				temp = actionAdd(i, j, push, sheet[i][j + NonTerminalCount]);
				if (!temp) return 2;
			}
		}
	return 0;
}
void Gsheet::build(void)
{
	size_t i, j;
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < NonTerminalCount; j++)
		{
			if(GOTO[i * NonTerminalCount + j].action == error)
				GOTO[i * NonTerminalCount + j].state += 1;
		}
	for (i = 0; i < StateCount * (TerminalCount + 1); i++)
	{
		if(ACTION[i].action == error)
			ACTION[i].state += 1;
	}
}
bool Gsheet::gotoAdd(size_t i, size_t j, Gsheet::type Action, int State)
{
	bool temp;
	size_t ld;
	ld = NonTerminalCount;
	temp = (GOTO[i * ld + j].action == error);
	temp = temp && (GOTO[i * ld + j].state == -1);
	if (temp)
	{
		GOTO[i * ld + j].action = Action;
		GOTO[i * ld + j].state = State;
	}
	else
	{
		EI.i = i;
		EI.j = j;
		EI.ActionOld = GOTO[i * ld + j].action;
		EI.StateOld = GOTO[i * ld + j].state;
		EI.ActionNew = Action;
		EI.StateNew = State;
		ET = ConflictGOTO;
	}
	return temp;
}
bool Gsheet::actionAdd(size_t i, size_t j, Gsheet::type Action, int State)
{
	bool temp;
	size_t ld;
	ld = (TerminalCount + 1);
	temp = ACTION[i * ld + j].action == error;
	temp = temp && ACTION[i * ld + j].state == -1;
	if (temp)
	{
		ACTION[i * ld + j].action = Action;
		ACTION[i * ld + j].state = State;
	}
	else
	{
		EI.i = i;
		EI.j = j;
		EI.ActionOld = ACTION[i * ld + j].action;
		EI.StateOld = ACTION[i * ld + j].state;
		EI.ActionNew = Action;
		EI.StateNew = State;
		ET = ConflictACTION;
	}
	return temp;
}
bool Gsheet::gotoCheck(size_t i, size_t j)
{
	return (GOTO[i * NonTerminalCount + j].action == error) && (GOTO[i * NonTerminalCount + j].state == -1);
}
bool Gsheet::actionCheck(size_t i, size_t j)
{
	bool temp;
	temp = ACTION[i * (TerminalCount + 1) + j].action == error;
	temp = temp && ACTION[i * (TerminalCount + 1) + j].state == -1;
	return temp;
}
void Gsheet::Demo(FILE* fp, const LR0* lr, const grammerS* G)const
{
	Demo01(fp);
	if (ET == ConflictACTION || ET == ConflictGOTO)
	{
		Demo02(fp);
		return;
	}
	if (ET == NoError)
		Demo03(fp);
}
void Gsheet::Demo(FILE* fp, const LR1* lr, const grammerS* G)const
{
	Demo01(fp);
	if (ET == ConflictACTION || ET == ConflictGOTO)
	{
		Demo02(fp);
		return;
	}
	if (ET == NoError)
		Demo03(fp);
}
void Gsheet::Demo(FILE* fp)const
{
	Demo01(fp);
	if (ET == ConflictACTION || ET == ConflictGOTO)
	{
		Demo02(fp);
		return;
	}
	if (ET == NoError)
		Demo03(fp);
}
void Gsheet::Demo01(FILE* fp)const
{
	fprintf(fp, "TerminalCount: %zu, NonTerminalCount: %zu\n", TerminalCount, NonTerminalCount);
	if (ET == uninitialized)
	{
		fprintf(fp, "Error type: uninitialized\n");
	}
}
void Gsheet::Demo02(FILE* fp)const
{
	if (ET == ConflictACTION) fprintf(fp, "Error type: ACTION Conflict\n");
	if (ET == ConflictGOTO) fprintf(fp, "Error type: GOTO Conflict\n");
	fprintf(fp, "Error site: (%zu, %zu).\n", EI.i, EI.j);
	fprintf(fp, "Former item: (%s, %d).\n", TypeToChar(EI.ActionOld), EI.StateOld);
	fprintf(fp, "New item: (%s, %d).\n", TypeToChar(EI.ActionNew), EI.StateNew);
}
void Gsheet::Demo03(FILE* fp)const
{
	size_t i, j;
	infor InF;
	fprintf(fp, "ACTION: \n");
	for (i = 0; i < StateCount; i++)
	{
		fprintf(fp, "[%4zu]: ", i);
		for (j = 0; j < TerminalCount + 1; j++)
		{
			InF = ACTION[i * (TerminalCount + 1) + j];
			fprintf(fp, "(%6s, %3d) ", TypeToChar(InF.action), InF.state);
		}
		fprintf(fp, "\n");
	}
	fprintf(fp, "GOTO: \n");
	for (i = 0; i < StateCount; i++)
	{
		fprintf(fp, "[%4zu]: ", i);
		for (j = 0; j < NonTerminalCount; j++)
		{
			InF = GOTO[i * NonTerminalCount + j];
			fprintf(fp, "(%6s, %3d) ", TypeToChar(InF.action), InF.state);
		}
		fprintf(fp, "\n");
	}
	for (i = 0; i < RulesCount; i++)
	{
		fprintf(fp, "rules[%4zu]: %d\n", i, RulesToSmbol[i]);
	}
}
const char* Gsheet::TypeToChar(Gsheet::type TT)
{
	switch (TT)
	{
	case hyperlex::Gsheet::accept:
		return "accept";
	case hyperlex::Gsheet::error:
		return "error";
	case hyperlex::Gsheet::push:
		return "push";
	case hyperlex::Gsheet::reduce:
		return "reduce";
	default:
		return "error";
	}
}

Gsheet::infor Gsheet::Goto(size_t state, size_t symbol) const
{
	return GOTO[state * NonTerminalCount + symbol];
}
Gsheet::infor Gsheet::Action(size_t state, size_t symbol) const
{
	return ACTION[state * (TerminalCount + 1) + symbol];
}
int Gsheet::GetSymbol(size_t rules) const
{
	return RulesToSmbol[rules];
}
void Gsheet::Cprint(const char* name, FILE* fp)const
{
	size_t i, j;
	//size_t No;
	int infor;
	fprintf(fp, "int GOTO");
	if (name != NULL) fprintf(fp, "_%s", name);
	fprintf(fp, "(int* list)\n{\n");
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < NonTerminalCount; j++)
		{
			infor = 4 * GOTO[i * NonTerminalCount + j].state;
			infor += (int)GOTO[i * NonTerminalCount + j].action;
			fprintf(fp, "\tlist[%zu] = %d;\n", i * NonTerminalCount + j, infor);
		}
	fprintf(fp, "}\n");
	//====================================================
	fprintf(fp, "int ACTION");
	if (name != NULL) fprintf(fp, "_%s", name);
	fprintf(fp, "(int* list)\n{\n");
	for (i = 0; i < StateCount * (TerminalCount + 1); i++)
	{
		infor = 4 * ACTION[i].state;
		infor += (int)ACTION[i].action;
		fprintf(fp, "\tlist[%zu] = %d;\n", i, infor);
	}
	fprintf(fp, "}\n");
	//====================================================
	fprintf(fp, "int RulesToSymbol");
	if (name != NULL) fprintf(fp, "_%s", name);
	fprintf(fp, "(int* list)\n{\n");
	for (i = 0; i < RulesCount; i++)
	{
		fprintf(fp, "\tlist[%zu] = %d;\n", i, RulesToSmbol[i]);
	}
	fprintf(fp, "}\n");
}
void Gsheet::CppPrint(const char* name, FILE* fp)const
{
	size_t i, j;
	//size_t No;
	int infor;
	fprintf(fp, "void %s::build()\n{\n", name);

	fprintf(fp, "\tStateCount = %zu;\n", StateCount);
	fprintf(fp, "\tNonTerminalCount = %zu;\n", NonTerminalCount);
	fprintf(fp, "\tTerminalCount = %zu;\n", TerminalCount);

	fprintf(fp, "\tGOTO = (int*)malloc(sizeof(int) * StateCount * NonTerminalCount);\n");
	for (i = 0; i < StateCount; i++)
		for (j = 0; j < NonTerminalCount; j++)
		{
			infor = 4 * GOTO[i * NonTerminalCount + j].state;
			infor += (int)GOTO[i * NonTerminalCount + j].action;
			fprintf(fp, "\tGOTO[%zu] = %d;\n", i * NonTerminalCount + j, infor);
		}
	fprintf(fp, "//==============================\n");//
	//====================================================
	fprintf(fp, "\tACTION = (int*)malloc(sizeof(int) * StateCount * (TerminalCount + 1));\n");
	for (i = 0; i < StateCount * (TerminalCount + 1); i++)
	{
		infor = 4 * ACTION[i].state;
		infor += (int)ACTION[i].action;
		fprintf(fp, "\tACTION[%zu] = %d;\n", i, infor);
	}
	fprintf(fp, "//==============================\n");//
	//====================================================
	fprintf(fp, "\tRulesToSymbol = (int*)malloc(sizeof(int) * RulesCount);\n");
	fprintf(fp, "\tRulesLength = (int*)malloc(sizeof(int) * RulesCount);\n");
	for (i = 0; i < RulesCount; i++)
	{
		fprintf(fp, "\tRulesToSymbol[%zu] = %d;\n", i, RulesToSmbol[i]);
		fprintf(fp, "\tRulesLength[%zu] = %d;\n", i, RulesLength[i]);
	}
	fprintf(fp, "}\n");
}
static bool compare(const char* str1, const char* str2)
{
	size_t i;
	for (i = 0; (str1[i] != '\0') && (str1[i] == str2[i]); i++);
	return str1[i] == str2[i];
}
static void inverse(list<size_t>& out, const list<size_t>& in)
{
	size_t i, length;
	length = in.count();
	out.refresh(length);
	for (i = 0; i < length; i++)
		out[in[i]] = i;
}


//int LRrun(int * )
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















int hyperlex::PostfixSwitch(char c)
{
	switch (c)
	{
	case 'a':
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
		return 11;
	case '\\':
		return 92;
	case '\'':
		return 39;
	case '\"':
		return 34;
	case '?':
		return 63;
	case '\0':
		return 0;
	default:
		return -1;
	}
}
bool hyperlex::IfHexa(char c)
{
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}
int hyperlex::SwitchHexa(char c)
{
	int e;
	if (c >= '0' && c <= '9')
		c -= '0';
	else if (c >= 'a' && c <= 'f')
		c = c - 'a' + (char)10;
	else
		c = c - 'A' + (char)10;
	e = (int)c;
	return e;
}
int hyperlex::SwitchOcta(char c)
{
	return c - '0';
}
char hyperlex::dequeue(const char* list, size_t end, size_t& head)
{
	char c;
	if (head < end)
	{
		c = list[head];
		head++;
	}
	else c = EOF;
	return c;
}
char hyperlex::CharGet(int& error, const char* list, size_t end, size_t& head)
{
	char c, result;
	int temp;
	//int state;
	char c1, c2;
	c = dequeue(list, end, head);
	error = 0;
	if (c != '\\') return c;
	//state = 0;
	c = dequeue(list, end, head);
	if (c == 'x' || c == 'X')
	{
		temp = -1;
		c1 = dequeue(list, end, head);
		if (IfHexa(c1))
		{
			temp = SwitchHexa(c1);
			c2 = dequeue(list, end, head);
			if (IfHexa(c2)) temp = 16 * temp + SwitchHexa(c2);
		}
		else
			error = -2;
	}
	else if('0' <= c && c <= '8')
	{
		temp = SwitchOcta(c);
		c1 = dequeue(list, end, head);
		if (IfHexa(c1))
		{
			temp = 8 * temp + SwitchOcta(c1);
			c2 = dequeue(list, end, head);
			if ('0' <= c && c <= '8') temp = 8 * temp + SwitchOcta(c2);
		}
	}
	else
	{
		temp = PostfixSwitch(c);
		if (temp == -1) error = -1;
	}
	result = temp;
	return result;
}




