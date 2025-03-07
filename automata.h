#ifndef __automata_adfhaiofh_fh823hasguj45482934__
#define __automata_adfhaiofh_fh823hasguj45482934__
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
//namespace hyperlex 1: template
//namespace hyperlex 2: DFA class declaring without members
/*
	class NFA;
	class sNFA;
	class sheetDFA;
	class DFA;
	class LR0;
	class LR1;
	class Gsheet;
*/
//namespace hyperlex 3: DFA class declaring 
//namespace hyperlex 4: grammer analysis declaring
/*
class grammerS;
template <class Cg> class LRNFA;
class LR0;
class LR1;
class Gsheet;
*/
//namespace hyperlex 5: template
namespace hyperlex
{
	template <class T> class vector
	{
	protected:
		size_t Count;
		size_t Capacity;
		T* content;
	public:
		vector();
		~vector();
		void clear(void);
		void copy(const vector<T>& source);
		void append(const vector<T>& source);
		size_t capacity(void) const;
		size_t count(void) const;
		void recapacity(size_t NewSize);
		void recount(size_t NewCount);
		void append(const T& element);
		size_t SearchAppend(const T& element);
		size_t pop(T& element);
		size_t top(T& element);
		void pop(void);
		size_t append(void);
		void swap(vector<T>& other);
		const T* ptr(void) const;
		T* ptr(void);
		const T* ptr(size_t offset)const;
		T* ptr(size_t offset);
		const T& operator[](size_t target) const;
		T& operator[](size_t target);
		void value(const T& element);
		const T& top(void) const;
		T& top(void);
		//friend bool operator<(size_t i, const vector<T>& right);
	};
	template <class T> class array
	{
	protected:
		size_t Length;
		T* content;
	public:
		array();
		~array();
		size_t length(void) const;
		T* ptr(void);
		T* ptr(size_t offset);
		const T* ptr(size_t offset) const;
		T& operator[](size_t target);
		T& operator[](const size_t target) const;
		void value(const T& element);
		void Malloc(size_t NewSize);
		void Realloc(size_t NewSize);
		void Free(void);
	};
	template <class T> class tree
	{
	public:
		tree();
		~tree();
		void clear(void);
		void build(vector<tree<T>*>& input);
		void build(vector<tree<T>*>& input, size_t offset);
		void PostOrderTraversal(vector<tree<T>*>& output);
		T& root(void);
		const T& root(void) const;
		size_t ChildCount(void) const;
		tree<T>* child(size_t No) const;
		struct Iterator
		{
			tree<T>* target;
			int state;
		};
		class PostIterator
		{
		public:
			PostIterator() {}
			~PostIterator() {}
			void initial(tree<T>* root);
			int& state(void);
			tree<T>*& target(void);
			void next(void);
			bool still(void);
		protected:
			vector<Iterator> stack;
			
		};
	private:
		array<tree<T>*> childs;
		T content;
		tree<T>* parent;
		size_t No;
	};
	template <class T> class BiTree
	{
	public:
		BiTree();
		~BiTree();
		void clear(void);
		void build(BiTree<T>* left, BiTree<T>* right);
		void PreOrderTraversal(vector<BiTree<T>*>& output);
		void PreOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack);
		void InOrderTraversal(vector<BiTree<T>*>& output);
		void InOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack);
		void PostOrderTraversal(vector<BiTree<T>*>& output);
		void PostOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack);

		T& content(void);
		const T& content(void) const;
		BiTree<T>*& left(void);
		BiTree<T>*& right(void);
		void*& label(void);
		BiTree<T>* copy(void);
		struct Iterator
		{
			BiTree<T>* target;
			int state;
		};
		class iterator
		{
		public:
			iterator() {}
			~iterator() {}
			void initial(BiTree<T>* root);
			int& state(void);
			BiTree<T>*& target(void);
			void next(void);
			bool still(void);
		protected:
			vector<Iterator> stack;

		};
	private:
		BiTree<T>* Left;
		BiTree<T>* Right;
		void* tempLabel;
		T Content;
	};
	template <class T> class buffer
	{
	protected:
		size_t Rear;
		size_t Capacity;
		size_t Head;
		T* content;
	public:
		buffer();
		~buffer();
		void clear(void);
		void append(const buffer<T>& other);
		size_t append(const T& element);
		size_t expand(void);
		void expand(const size_t L);
		bool dequeue(T& out);
		bool backspace(T& in);
		bool backspace(buffer<T>& in);
		T* ptr(void);
		size_t count(void) const;
		size_t rear(void) const;
		size_t capacity(void) const;
		size_t head(void) const;
		T& operator[](size_t target) const;
	};
	class BufferChar : public buffer<char>
	{
	public:
		BufferChar();
		~BufferChar();
		void operator<<(FILE* fp);
		char* ptr(void);
		char* CopyVector(void) const;
		size_t CopyVector(vector<char>& storage, size_t& length) const;
		void operator=(const char* input);
		long int DequeueInt(void);

	private:

	};
}
namespace hyperlex
{
	template <class T> class list
	{
	private:
		size_t Count;
		size_t Size;
		T* content;
	public:
		list();
		~list();
		void refresh(void);
		void refresh(size_t NewCount);
		void reshape(size_t NewSize);
		void renew(size_t NewSize);
		void append(const T& element);
		size_t SearchAppend(const T& element);
		size_t pop(T& element);
		void pop(void);
		size_t append(void);
		size_t size(void) const;
		size_t count(void) const;
		void swap(list<T>& other);
		const T* vector(void)const;
		T* vector(void);
		const T* vector(size_t offset)const;
		T* vector(size_t offset);
		const T& operator[](size_t target) const;
		T& operator[](size_t target);
		void value(const T& element);
		const T& top(void) const;
		T& top(void);
	};
	template <class T> class matlist
	{
		/*
		matlist(size_t column);
		column can not be 0.
		*/
	public:
		matlist(size_t column);
		matlist();
		~matlist();
		void refresh(void);
		void refresh(size_t column, size_t length);
		void refresh(size_t row, size_t column, size_t length);
		//void reshape(size_t NewSize);
		void append(const T* element);
		size_t SearchAdd(const T* element);
		//size_t pop(T* element);
		T* append(void);
		size_t column(void) const;
		size_t row(void) const;
		size_t length(void) const;
		void swap(matlist<T>& other);
		const T* operator[](size_t target) const;
		T* operator[](size_t target);
		void value(const T element);
	private:
		size_t Row;
		size_t Column;
		size_t Length;
		T* content;
	};
	template <class T> class vec
	{
	private:
		size_t Size;
		T* content;
	public:
		vec();
		~vec();
		size_t size(void) const;
		T* vector(void);
		T& operator[](size_t target);
		T& operator[](const size_t target) const;
		void Malloc(size_t NewSize);
		void Realloc(size_t NewSize);
		void Free(void);
	};



	template <class Cg, class Ca> class Dgraph
	{
	public:
		struct vortex
		{
			size_t first;
			size_t rear;
			Cg content;
		};
		struct arc
		{
			size_t from;
			size_t to;
			size_t next;
			Ca content;
		};
		list<vortex> vertice;
		buffer<arc> arcs;
		Dgraph();
		~Dgraph();
		Cg& operator[](size_t target);
		void refresh(void);
		void refresh(size_t newlength);
		size_t FirstArc(size_t) const;
		size_t NextArc(size_t) const;
		size_t ArcTo(size_t) const;
		size_t ArcCount(size_t) const;
		size_t append(size_t from, size_t to, const Ca & C);
		void append(const Dgraph<Cg, Ca>& right, size_t VerticeOffset);
		void Demo(FILE* fp) const;
	};
	template <class T> class bitree
	{
		bitree<T>* left;
		bitree<T>* right;
		T content;
	public:
		bitree();
		~bitree();
		const bitree<T>*& L(void) const;
		const bitree<T>*& R(void) const;
		bitree<T>*& L(void);
		bitree<T>*& R(void);
		const T&C(void) const;
		T& C(void);
		void postorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
		void postorderTraversal(buffer<size_t>& output) const;
		void inorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
		void inorderTraversal(buffer<size_t>& output) const;
		bool IfLeaf(size_t site)const;
	};
	template <class T> class Bitree
	{
	public:
		struct node
		{
			size_t left;
			size_t right;
			T content;
		};
		Bitree();
		~Bitree();
		void move(Bitree<T>& source);
		void clear(void);
		void SetHead(size_t head);
		size_t NewNodeOffset(void);
		node* NewNode(void);
		node* Node(size_t site)const;
		node* LeftChild(const node* now)const;
		node* RightChild(const node* now)const;
		const node& operator[](size_t target) const;
		node& operator[](size_t target);
		void postorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
		void postorderTraversal(buffer<size_t>& output) const;
		void inorderTraversal(buffer<size_t>& output, list<size_t>& s) const;
		void inorderTraversal(buffer<size_t>& output) const;
		bool IfLeaf(size_t site)const;
		void Demo(FILE* fp)const;


		void removal(size_t site);
		void removal(size_t site, buffer<size_t>& output, list<size_t>& s);
		void append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, size_t & NewSite);
		
		void append(const Bitree<T>& left, size_t parent);
		void append(const Bitree<T>& left, const Bitree<T>& right, size_t parent);

		//size_t append_t(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, bool key);
		//void append_t(const Bitree<T>& left, const Bitree<T>& right, size_t parent, bool key);
		size_t Head;
	private:
		
		size_t Size;
		size_t Count;
		size_t FirstEmpty;
		node* Nodes;
	};
	




	template <class T> class StaticTree
	{
	public:
		struct node
		{
			size_t offset;
			size_t degree;
			T content;
		};
		StaticTree();
		~StaticTree();
		void clear(void);
		void build(tree<T>* input);
	private:
		size_t Head;
		list<node> Nodes;
		list<size_t> next;
	};
	template <class T> class Tree
	{
	public:
		struct node
		{
			vec<node*> childs;
			T content;
			node() {}
			~node() {}
			void build(list<Tree>& input);
		};
		Tree();
		~Tree();
		void move(Tree<T>& source);
		void clear(void);
		void build(list<Tree>&input);
		void PostOrderTraversal(list<node*>& output) const;
		T& head(void);
		const T& head(void) const;
	private:
		node* Head;
		void RuinSelf(void);
	};
	
}
namespace hyperlex
{
	class NFA;
	class sNFA;
	class sheetDFA;
	class DFA;
	class lexicalPanel;
	class grammerS;
	class LR0;
	class LR1;
	class Gsheet;
}
// input analysis and lexical analysis.
namespace hyperlex
{
	class Morpheme
	{
		/**
		* Structure storing lexical analysis results
		* @struct result
		* @member accept   the lexical unit is identified as
		* @member category Lexical category identifier
		* @member length   Length of matched lexical unit
		* @member begin    Starting position in input stream
		*/
	public:
		struct result
		{
			int accept;
			int category;
			size_t length;
			size_t begin;
		};
		Morpheme();
		~Morpheme();
		char* Copy(size_t site) const;
		void append(const BufferChar& input, int accept, int category);
		void AppendEnd(int TerminalCount);
		void UnitMove(size_t from, size_t to);
		void CountReset(size_t count);
		void Demo(FILE* fp) const;
		size_t GetCount(void) const;
		const char* GetWord(size_t site) const;
		const result& operator[](const size_t target) const;

		char GetChar(size_t site) const;

		template<typename T> int Build(const char* reg);
		template<typename T> int Build(FILE* fp);
	private:
		size_t count;
		//list<size_t> begin;
		//list<size_t> length;
		vector<result> lex;
		vector<char> storage;
		template<typename T> bool RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate);
	};
	class GrammarTree
	{
	public:
		GrammarTree();
		~GrammarTree();
		struct TreeInfor
		{
			bool rules;
			size_t site;
			size_t label;
			void* infor;
			// rules:false, this is a leaf node, and its a node corresponding to
			// a lexical terminal symbol then site is a location of the lexical unit 
			// in the lexical sheet
			// rules: true, this may be not a leaf node, 
			// site is the corresponding production rules
		};
		//template<typename T> int build(const char* reg);
		void Demo(FILE* fp, const Morpheme& input, const char* const* RulesName) const;
		void clear(void);
		template<typename T> int build(const Morpheme& input);

		tree<TreeInfor>* GT;
	private:
	};
	class RegularExp
	{
	public:
		RegularExp();
		~RegularExp();
		enum NodeType
		{
			Concatenation = 0,
			Alternation = 1,
			ZeroOrMore = 2,
			OneOrMore = 3,
			ZeroOrOne = 4,
			Range = 5,
		};
		struct item
		{
			int lower;
			int upper;
			NodeType type;
			void Demo(FILE* fp);
			void copy(const item& source);
		};

		void Demo(FILE* fp) const;
		static void Demo(FILE* fp, NodeType T);
		static void Demo(FILE* fp, int L, int U);
		void clear(void);

		int set(const char* input);

		void copy(RegularExp& source);
		void set(int L, int U);
		void set(int leaf);
		void set(BiTree<item>* reg);
		void set(BiTree<item>* reg, NodeType T);
		void set(BiTree<item>* regL, BiTree<item>* regR, NodeType T);
		void set(RegularExp* reg);
		void set(RegularExp* reg, NodeType T);
		void set(RegularExp* regL, RegularExp* regR, NodeType T);
		void set(RegularExp* regL, RegularExp* regR);
		void set(const Morpheme& eme, hyperlex::tree<GrammarTree::TreeInfor>* Tree);
		friend class sNFA;
	private:
		BiTree<item>* tree;
		void set(void);
		int fastBuild(Morpheme& eme);
		int standardBuild(Morpheme& eme);
	};
	class InputPanel
	{
	public:
		typedef const vector<const char*> cvccp;
		InputPanel();
		~InputPanel();
		int build(FILE* fp);
		int build(const char* input);
		void demo(FILE* fp) const;
		void ErrorDemo(FILE* fp) const;
		void printL(FILE* fp, const char* nameL)const;
		int printG(FILE* output, FILE* infor, const char* nameG)const;

		struct RegContent
		{
			const char* name;
			long int priority;
			long int accept;
			size_t group; 
			//When two distinct regular expressions match simultaneously, 
			//the regular expression with the higher priority number is accepted.
			RegularExp* reg;
			RegContent();
			~RegContent();
			void SetName(const char* input);
		};
		struct RegGroup
		{
			const char* name;
			int priority;
			vector<RegContent*> regs;
			size_t prefix;
			RegGroup();
			~RegGroup();
			void SetName(const char* input);
		};
		struct Rules
		{
			const char* name;
			vector<long int> formula;
			Rules();
			~Rules();
			void SetName(const char* input);
			void demo(FILE* fp, cvccp& N, cvccp& T);
		};
		struct Group
		{
			size_t group;
			const char* name;
			vector<Rules*> rules;
			size_t count;
			size_t offset;
			Group();
			~Group();
			void SetName(const char* input);

		};
		enum errorType
		{
			NoError = 0,
			ConflictRegGroupName = 1,
			repeatRegName = 2,
			missingId = 3,
			repeatGGroupName = 4,
			repeatGName = 5,
			ErrorNonTernimal,
			WorngRuleBody 
		};
		friend class NFA;
		friend class grammerS;
	private:
		typedef hyperlex::tree<GrammarTree::TreeInfor> GLTree;
		typedef hyperlex::tree<GrammarTree::TreeInfor>::PostIterator GTIter;
		bool GrammarEnclosed;
		vector<RegGroup*> RegG;
		vector<RegContent*> regular;
		vector<Group*> GrammarG;

		vector<const char*> Terminal;
		vector<const char*> NontTerminal;
		char* RootName;

		vector<Rules*> rules;

		errorType errorCode;
		size_t errorInfor1;
		size_t errorInfor2;
		const char* errorInfor3;
		bool errorInfor4;
		/*
		demo of input file analysis;
		*/
		void demoL(FILE* fp) const;
		void demoG(FILE* fp) const;

		/*
		* input analysis;
		*/
		int buildGanalysis(const Morpheme& eme);
		int buildAll(const Morpheme& eme, GrammarTree& Tree);
		void buildLpost(void);

		int buildL(const Morpheme& eme, GLTree* Tree);
		void addVoidGroup(void);
		int RegGroupName(size_t& siteReturn, const Morpheme& eme, GLTree* Tree);
		int RegName(size_t& siteReturn, size_t group, const Morpheme& eme, GLTree* Tree);
		bool RegSearch(size_t& group, size_t& site, const char* name);
		int RegBuild(size_t siteReturn, size_t group, const Morpheme& eme, GLTree* Tree);
		void NeglectNullToken(Morpheme& eme) const;

		int buildG(const Morpheme& eme, GLTree* Tree);
		int buildRules(const Morpheme& eme, GLTree* Tree);
		void addAllGroup(void);
		void addAllGroup02(void);
		int GrammarGroup(size_t& GroupSite, const Morpheme& eme, GLTree* Tree);
		int RulesAppend(size_t GroupSite, GLTree* Name, const Morpheme& eme, GLTree* Tree);
		void addTerminal(void);
		long int SymbolAdd(const char* symbol);
		int NonTerminalSort(void);
	};
}

// lexical analysis

namespace hyperlex
{
	class ShrinkList
	{
	public:
		friend class sheetDFA;
		friend class DFA;
		ShrinkList(size_t AcceptCount, size_t size);
		~ShrinkList();
		void Insert(size_t site, size_t state);
		size_t DeleteNext(size_t now);
		size_t NewState(size_t Now);
		size_t Head(size_t site)const;
		size_t Count(void)const;
		void Demo(FILE* fp)const;
	private:
		vec<size_t> group;
		vec<size_t> next;
		size_t Statecount;
		list<size_t> head;
		list<size_t> rear;
	};
	class RegTree
	{
	public:
		friend class sNFA;
		enum NodeType
		{
			Concatenation = 0,
			Alternation = 1,
			ZeroOrMore = 2,
			OneOrMore = 3,
			ZeroOrOne = 4,
			Range = 5,
		};
		struct info
		{
			char upper;
			char lower;
			NodeType type;
			void Demo(FILE* fp)const;
		};

		static int next_Reg(int state, const char c);
		static int action_Reg(int state);
		static int GroupGet_Reg(int accept);
	private:
		Bitree<info> tree;
		struct traverse
		{
			int state;
			size_t site;
		};
	public:
		RegTree();
		~RegTree();
		void build(const char* reg);
		void build(BufferChar& input);
		bool RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate);


		void grow(const RegTree* reg, NodeType T);
		void grow(const RegTree* regL, const RegTree* regR, NodeType T);
		//void grow_t(const RegTree* regL, const RegTree* regR, NodeType T, bool key);
		void grow(char L, char U);
		void grow(char C);
		void value(const RegTree* regL);

		void Reserved(const char* res);
		void Int(void);
		void Identifier(void);
		void IdentifierHead(void);
		void IdentifierInner(void);
		void ConstChar(void);
		void CommonChar(void);
		void EscapeAll(void);
		void EscapeChar(void);
		void HexaChar(void);
		void OctaChar(void);
		void spaces(void);
		void LineFeeds(void);

		static void swap(const RegTree* &regL, const RegTree* &regR);
		void Demo(FILE* fp) const;
		static void Demo(FILE* fp, NodeType T);
		static void Demo(FILE* fp, char L, char U);
	private:
		void value(size_t site, char LU);
		void value(size_t site, char L, char U);
		void link(size_t site, size_t L, size_t R, NodeType T);
		void link(size_t site, size_t L, NodeType T);
	};



	class lexicalPanel
	{
	public:
		class infor
		{
		public:
			size_t priority;
			//When two distinct regular expressions match simultaneously, 
			//the regular expression with the higher priority number is accepted.
			RegTree* reg;
			const char* name;
			const char* attribute;
			size_t group;
			infor();
			~infor();
			void Demo(FILE* fp);
			void SetName(const char* input);
			void SetAttribute(const char* input);
		};
		friend class NFA;
		lexicalPanel();
		~lexicalPanel();
		
		void build(void);
		void BuildDemo(FILE*fp);

		void Cprint(FILE*fp, const char* name);
		void CppPrint(FILE* fp, const char* name);

		void SetGrammer(void);
		void SetReg(void);
		void SetRegS(void);
		void SetRegFinal(void);
		void append(infor* II);

		void Demo(FILE*fp) const; 

		const char** GetName(void)const;
		const char** GetAttribute(void)const;
		//void append(const char* Name, const char* Attri, RegTree* Reg, size_t Priority);
		//void expand(void);
	private:
		list<infor*> regular;
		void SetAll(void);
		//size_t AttributeCount;
		list<const char*> attribute;
		//size_t count;
		//size_t capacity;
		//RegTree** reg;
		//const char**name;
		//const char**attribute;
		//size_t* priority;

		NFA* nfa;
		sheetDFA* DFAsheet;
		DFA* DFAgraph;
		void Cgroup(FILE* fp, const char* name)const;
		void CppGroup(FILE* fp, const char* name)const;
		void CppGroupCore(FILE* fp, const char* name)const;
	};
	class DirectedGraph
	{
	public:
		DirectedGraph();
		~DirectedGraph();
		struct vortex
		{
			size_t first;
			size_t rear;
			//size_t site;
		};
		struct arc
		{
			size_t from;
			size_t to;
			size_t next;
			size_t site;
		};
		void refresh(void);
		void refresh(size_t newlength);
		size_t append(size_t from, size_t to, size_t site);
		void append(DirectedGraph & right, size_t VerticeOffset, size_t ArcsOffset, size_t siteOffset);
		list<vortex> vertice;
		buffer<arc> arcs;
	private:
	};
	struct Convert
	{
		char upper;
		char lower;
		bool epsilon;
		bool in(const char ele);
	};
	struct convert
	{
		int upper;
		int lower;
		//size_t to;
		bool in(const char ele);
		bool in(int ele);
	};
	class sNFA
	{
	public:
		friend class NFA;
		sNFA();
		~sNFA();
		//typedef buffer<Convert> converts;
		void refresh(void);
		void build(const RegularExp* Reg);
		void build(const RegTree* Reg);
		void build(const RegTree *Reg, buffer<size_t> &output, list<size_t>& s, list<sNFA*> &nfa);
		void Demo(FILE* fp) const;
	protected:
		void build(void);
		void build(const bool input[128]);
		void parallel(const sNFA& left, const sNFA& right);
		void serial(const sNFA& left, const sNFA& right);
		void any(const sNFA& right);
		void plus(const sNFA& right);
		void ZeroOrOne(const sNFA& right);

		void parallel(const sNFA* left, const sNFA* right);
		void serial(const sNFA* left, const sNFA* right);
		void any(const sNFA* right);
		void plus(const sNFA* right);
		void ZeroOrOne(const sNFA* right);
	private:
		Dgraph<int, Convert> graph;
		// content of vertice of graph is meanless
		// state = 0 is the begin
		size_t StateAmount;
		//DirectedGraph graph;
		size_t accepted;
		//converts CC;
	};
	class NFA
	{
	public:
		friend class sheetDFA;
		NFA(const sNFA& single);
		NFA(const sNFA* const* multiple, size_t count);
		NFA(const lexicalPanel&lP);
		NFA(const InputPanel& lP);
		~NFA();
		void initial(bool* state, list<size_t>& stack) const;
		void closure(bool* state, list<size_t> &stack) const;
		size_t move(const bool* from, bool* to, const char ele, list<size_t>& stack) const;
		size_t GetAccepted(const bool* state, bool* accept) const;
		size_t FirstAccepted(const bool* accept) const;
		void Demo(FILE* fp) const;
	private:
		// content of vertice of graph is label of accpet
		// state = 0 is the begin
		// No i accepted state has graph.vertice[??].content = i
		Dgraph<int, Convert> graph;
		size_t StateAmount;
		size_t accepted;
		list<size_t> priority;
	private:
		void build(const sNFA* const* multiple, size_t count);
		//vec<bool> state;
	};
	class sheetDFA
	{
	public:
		friend class DFA;
		sheetDFA(const NFA & nfa);
		~sheetDFA();
		void shrink(void);
		int next(int state, const char c)const;
		int action(int state)const;
		
		void Demo(FILE*fp)const ;
		static void Demo(FILE* fp, const bool *state, size_t n);
	private:
		size_t count;
		size_t AcceptCount;
		matlist<int> sheet;
		list<int> accept;
		//matlist<int> accept;
		void acceptSet(const matlist<bool>& Dstates, const NFA& nfa);
		void shrink(const ShrinkList* SL);
	};
	enum NodeType
	{
		Concatenation = 0,
		Alternation = 1,
		ZeroOrMore = 2,
		OneOrMore = 3,
		AnyOne = 4,
	};
	class DFA
	{
	public:
		DFA(const sheetDFA* dfa);
		~DFA();
		int next(int state, const char c)const;
		int action(int state)const;
		void Demo(FILE* fp)const;
		void Cprint(FILE* fp, const char* name)const;
		void CppPrint(FILE* fp, const char* name)const;
		void CprintAccept(FILE* fp, const char* name, const char** const category, const char** const accept)const;
		void CppPrintAccept(FILE* fp, const char* name, const char** const category, const char** const accept)const;

		static void Cprint(FILE* fp, convert& CC);
		static void Demo(FILE* fp, int L, int U);
		static void Demo(FILE* fp, convert &CC);

		size_t StateAmountGet(void) const;
		int GraphStateGet(const size_t site) const;
	private:
		Dgraph<int, convert> graph;
		size_t StateAmount;
		size_t AcceptCount;
		void CprintCore(FILE* fp, const char* name)const;
		void CprintAcceptCore(FILE* fp, const char* name, const char** const category, const char** const accept)const;
	};
}
namespace hyperlex
{
	template<typename T> int Morpheme::Build(FILE* fp)
	{
		BufferChar input;
		BufferChar result;
		BufferChar intermediate;
		int accept;
		char now;
		input << fp;
		while (RunBuild<T>(accept, result, input, intermediate))
		{
			if (accept != 0) append(result, accept, T::GroupGet(accept));
			else
			{
				input.dequeue(now);
				result.append(now);
				append(result, 0, T::GroupGet(0));
			}
		}
		AppendEnd(0);
		return 0;
	}
	template<typename T> int Morpheme::Build(const char* reg)
	{
		BufferChar input;
		BufferChar result;
		BufferChar intermediate;
		int accept;
		char now;
		input = reg;
		while (RunBuild<T>(accept, result, input, intermediate))
		{
			if (accept != 0) append(result, accept, T::GroupGet(accept));
			else
			{
				input.dequeue(now);
				result.append(now);
				append(result, 0, T::GroupGet(0));
			}
		}
		AppendEnd(0);
		return 0;
	}
	template<typename T> bool Morpheme::RunBuild(int& accept, BufferChar& result, BufferChar& input, BufferChar& intermediate)
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
		intermediate.clear();
		state = 0;
		acc = 0;
		action = 0;
		accept = 0;
		result.clear();
		while (input.dequeue(now))
		{
			/*state switch*/
			/*change here to get a different automata*/
			state = T::next(state, now);
			acc = T::action(state);
			/*change here to get a different automata*/
			accept = acc != 0 ? acc : accept;
			switch (action)
			{
			case 0://initial
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
			case 1://run and waiting for accept
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
					intermediate.clear();
					action = 2;
				}
				else intermediate.append(now);//continue 
				break;
			case 2://accept
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
	template<typename T> int GrammarTree::build(const Morpheme& input)
	{
		vector<int> stack;
		vector<tree<TreeInfor>*> TempTree;
		tree<TreeInfor>* TreeNow;
		bool DoNext;
		size_t length, head, i, begin_, inputCount_;
		int symbol, top, temp, information;
		int GoFull, GoD, GoI, error;
		typename T::type type;
		stack.append(0);
		head = 0;
		inputCount_ = input.GetCount();
		DoNext = true;
		do
		{
			if (head >= inputCount_)
			{
				error = -1;
				break;
			}
			top = stack.top();
			temp = T::ACTION[top][input[head].accept];
			information = temp / 4;
			type = (typename T::type)(temp % 4);
			printf( "T = %5d, top = %5d, information = %5d, type = %5d, ", input[head].accept, top, information, (int)type);
			printf("head = %5zu, lex = %s, \n", head, input.GetWord(head));
			switch (type)
			{
			case T::accept:
				error = 0;
				DoNext = false;
				clear();
				TempTree.pop(GT);
				break;
			case T::error:
				error = temp;
				DoNext = false;
				break;
			case T::push:
				
				//printf("<%8zu, %4d: %4d , %s>\n", head, input[head].category, input[head].accept, input.GetWord(head));
				stack.append(information);
				TreeNow = new tree<TreeInfor>;
				TreeNow->root().rules = false;
				TreeNow->root().site = head;
				TreeNow->root().infor = NULL;
				TempTree.append(TreeNow);		
				head += 1;
				
				break;
			case T::reduce:
				symbol = T::RulesToSymbol[information];
				length = T::RulesLength[information];
				begin_ = TempTree.count() - length;

				TreeNow = new tree<TreeInfor>;
				TreeNow->root().rules = true;
				TreeNow->root().site = information;
				TreeNow->root().infor = NULL;
				TreeNow->build(TempTree, begin_);
				
				for (i = 0; i < length; i++)
				{
					stack.pop();
					TempTree[begin_ + i] = NULL;
				}
				TempTree.recount(begin_);
				GoFull = T::GOTO[stack.top()][symbol];
				GoD = GoFull / 4;
				GoI = GoFull % 4;
				stack.append(GoD);
				TempTree.append(TreeNow);
				break;
			}

		} while (DoNext);

		for (i = 0; i < TempTree.count(); i++)
		{
			//printf("<%8zu>\n", i);
			if (TempTree[i] != NULL)
			{
				//printf("####\n");
				TempTree[i]->clear();
				delete TempTree[i];
			}
		}
		return error;
	}
}
// grammer analysis
namespace hyperlex
{
	class grammerS
	{
	public:
		friend class LR0;
		friend class LR1;
		friend class Gsheet;
		grammerS();
		~grammerS();
		int build(const InputPanel& input);
		int build(FILE* fp);
		int build(BufferChar& input);
		void Demo(FILE* fp) const;
		void Cprint(FILE* fp) const;
		void Demo(FILE* fp, size_t rule) const;
		void Demo(FILE* fp, size_t rule, size_t dot) const;
		const char* SymbolGet(long long int index) const;
		const long long int* vector(size_t No)const;
		void SetExample(void);
		struct production
		{
			size_t symbol;
			size_t length;
			size_t begin;
		};
		enum ErrorCode
		{
			done = 0,
			undone = 1,
			unexpectedTernimal = 2,
			missingdivision = 3,
			missingRulesOrWrongSymbol = 4,
		};
	private:
		ErrorCode ERROR;
		size_t count;// count of non-terminal
		size_t TerminalCount;
		//[0,count-1] non-terminal
		//[count,TerminalCount + count -1]; terminal
		//TerminalCount + count: epsilon
		//TerminalCount + count + 1: END-EOF
		long long int epsilon;
		long long int end;
		list<size_t> degeneracy;//has length of count.
		//degeneracy[i]: rules' count of non-terminal[i]
		list<size_t> prefix;//has length of count
		//prefix[i]: rules' begining index of non-terminal[i]
		list<const char*> name;//has length of count
		list<const char*> ternimal;
		list<production> rules;//has length of count of all rules
		list<long long int> all;//Production Rules

		matlist<bool> first;//matrix of count * (TerminalCount + 2)
		matlist<bool> follow;//matrix of count * (TerminalCount + 2)
	private:
		void append(const char* input);
		void Tappend(const char* input);
		size_t SearchAppend(const char* input);
		long long int SearchTerminal(const char* input);
		int nextTest(int state, const char c);
		int actionTest(int state);
		bool RunBuild(int&accept, BufferChar& result, BufferChar& input, BufferChar& intermediate);
	private:
		
		void FirstBiuld(void);
		bool IfaRuleEpsilon(size_t site) const;
		bool IfEpsilon(long long int site) const;
		bool FirstOr(long long int symbol, bool* to) const;
		bool Or(const bool* from, bool* to) const;
		bool FollowOr(const bool* from, size_t to);
		bool AddFirstBeta(bool* result, size_t L, const long long int* in) const;
		void FirstBeta(bool* result, size_t L, const long long int*in) const;
		void FollowBiuld(void);
	};
	template <class Cg> class LRNFA
	{
	public:
		struct vortex
		{
			size_t first;
			size_t rear;
			Cg content;
		};
		struct arc
		{
			size_t from;
			size_t to;
			size_t next;
			bool epsilon;
			long long int symbol;
			//bool in(long long int ele);
		};
		list<vortex> vertice;
		buffer<arc> arcs;
		LRNFA();
		~LRNFA();
		Cg& operator[](size_t target);
		const Cg& operator[](size_t target) const;
		void refresh(void);
		void refresh(size_t newlength);
		size_t VortexAppend(const Cg& element);
		size_t FirstArc(size_t) const;
		size_t NextArc(size_t) const;
		size_t ArcTo(size_t) const;
		size_t ArcCount(size_t) const;
		size_t append(size_t from, size_t to, bool Epsilon, long long int Symbol);
		void Demo(FILE* fp) const;

		void initial(bool* state, list<size_t>& stack) const;
		void closure(bool* state, list<size_t>& stack) const;
		size_t move(const bool* from, bool* to, long long int ele, list<size_t>& stack) const;
		void build(matlist<int>& sheet, matlist<bool> &Dstates, size_t NonTcount, size_t Tcount) const;
	};
	class LR0
	{
	public:
		friend class Gsheet;
		LR0(const grammerS *G);
		~LR0();
		void Demo(FILE*fp, const grammerS* G);
		struct item
		{
			size_t rules;
			size_t dot;
		};
	private:
		LRNFA<item> graph;

		size_t TerminalCount;
		size_t NonTerminalCount;
		matlist<int> sheet;
		matlist<bool> Dstates;
		//void build(const grammerS* G);
		
	};
	class LR1
	{
	public:
		friend class Gsheet;
		LR1(const grammerS* G);
		~LR1();
		void Demo(FILE* fp, const grammerS* G);
		void Demo(FILE* fp, size_t site, const grammerS* G);
		struct item
		{
			size_t rules;
			size_t dot;
			long long int symbol;
			bool operator==(const item R) const;
		};
	private:
		LRNFA<item> graph;

		size_t TerminalCount;
		size_t NonTerminalCount;
		matlist<int> sheet;
		matlist<bool> Dstates;
		size_t SearchAppend(const item& I, bool& IfAppend);
		//void build(const grammerS* G);
	};
	class Gsheet
	{
	public:
		Gsheet();
		~Gsheet();
		enum type
		{
			accept = 0,
			error = 1,
			push = 2,
			reduce = 3,
		};
		struct infor
		{
			type action;
			int state;
		};
		enum ErrorType
		{
			NoError = 0,
			uninitialized = 1,
			ConflictACTION = 2,
			ConflictGOTO = 3,
		};
		struct ErrorInfor
		{
			size_t i;
			size_t j;
			type ActionOld;
			int StateOld;
			type ActionNew;
			int StateNew;
		};
		void build(const LR0* lr, const grammerS* G);
		void build(const LR1* lr, const grammerS* G);
		int build(const matlist<int>& sheet, const matlist<bool>& Dstates, const grammerS* G);
		void build(void);//after
		void Demo(FILE* fp) const;
		void Demo(FILE* fp, const LR0* lr, const grammerS* G)const;
		void Demo(FILE* fp, const LR1* lr, const grammerS* G)const;

		infor Goto(size_t state, size_t symbol) const;
		infor Action(size_t state, size_t symbol) const;
		int GetSymbol(size_t rules) const;
		void Cprint(const char* name, FILE* fp)const;
		void CppPrint(const char* name, FILE* fp)const;
		void CppStructPrint(const char* name, FILE* fp, const grammerS * grammer)const;
		// now site 0 is END-EOF, site 1-N Are N terminal symbol
		static const char* TypeToChar(type TT);
		const ErrorType ErrorTypeGet(void);
		const ErrorInfor ErrorInforGet(void);
	private:
		size_t StateCount;
		size_t TerminalCount;
		size_t NonTerminalCount;
		size_t RulesCount;

		infor* ACTION;
		infor* GOTO;
		int* RulesToSmbol;
		int* RulesLength;

		ErrorType ET;
		ErrorInfor EI;

		bool gotoAdd(size_t i, size_t j, type Action, int State);
		bool actionAdd(size_t i, size_t j, type Action, int State);
		bool gotoCheck(size_t i, size_t j);
		bool actionCheck(size_t i, size_t j);
		void Demo01(FILE* fp)const;
		void Demo02(FILE* fp)const;
		void Demo03(FILE* fp)const;
	};
}
#define SizeMax ((size_t)0xffffffffffffffff)
#define CharSize ((size_t)(1 << (sizeof(char) * 8 - 1)))


#include<stdlib.h>
namespace hyperlex
{
	template <class T> vector<T>::vector()
	{
		Count = 0;
		Capacity = 0;
		content = NULL;
	}
	template <class T> vector<T>::~vector()
	{
		Count = 0;
		Capacity = 0;
		free(content);
		content = NULL;
	}
	template <class T> void vector<T>::copy(const vector<T>& source)
	{
		size_t i;
		Count = source.Count;
		Capacity = Count;
		content = (T*)realloc(content, Capacity * sizeof(T));
		for (i = 0; i < Count; i++)
			content[i] = source.content[i];
	}
	template <class T> void vector<T>::append(const vector<T>& source)
	{
		size_t i, NewCount;
		NewCount = Count + source.Count;
		if (NewCount > Capacity)
		{
			content = (T*)realloc(content, NewCount * sizeof(T));
			Capacity = NewCount;
		}
		for (i = 0; i < source.Count; i++)
			content[i + Count] = source.content[i];
		Count = NewCount;
	}
	template <class T> void vector<T>::append(const T& element)
	{
		size_t should;
		should = append();
		content[should] = element;
	}

	template <class T> size_t vector<T>::SearchAppend(const T& element)
	{
		size_t i, j;
		const T* temp;
		for (i = 0; i < Count; i++)
		{
			if (content[i] == element) return i;
		}
		append(element);
		return Count - 1;
	}
	template <class T> void vector<T>::clear(void)
	{
		Count = 0;
	}
	template <class T> void vector<T>::recount(size_t NewCount)
	{
		if (NewCount > Capacity)
		{
			//std::cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< std::endl;
			//std::cout << "NewCount: " << NewCount << "Capacity: " << Capacity << std::endl;
			//std::cout << "old content: " << content << std::endl;
			content = (T*)realloc(content, NewCount * sizeof(T));
			//std::cout << "new content: " << content << std::endl;
			Capacity = NewCount;
		}
		Count = NewCount;
	}
	template <class T> void vector<T>::recapacity(size_t NewSize)
	{
		if (NewSize <= Count) Count = NewSize;
		content = (T*)realloc(content, NewSize * sizeof(T));
		Capacity = NewSize;
	}
	template <class T> size_t vector<T>::pop(T& element)
	{
		if (Count != 0)
		{
			Count -= 1;
			element = content[Count];
			return Count + 1;
		}
		return Count;
	}
	template <class T> size_t vector<T>::top(T& element)
	{
		if (Count != 0)
		{
			element = content[Count - 1];
		}
		return Count;
	}
	template <class T> void vector<T>::pop(void)
	{
		if (Count != 0) Count -= 1;
	}
	template <class T> size_t vector<T>::append(void)
	{
		size_t should, new_size;
		if (Count >= Capacity)
		{
			new_size = (Capacity + Capacity / 4 + 8);
			content = (T*)realloc(content, new_size * sizeof(T));
			Capacity = new_size;
		}
		should = Count;
		Count += 1;
		return should;
	}
	template <class T> size_t vector<T>::count(void) const
	{
		return Count;
	}
	template <class T> size_t vector<T>::capacity(void) const
	{
		return Capacity;
	}
	template <class T> void vector<T>::swap(vector<T>& other)
	{
		T* middle;
		middle = other.content;
		other.content = content;
		content = middle;

		size_t MM;

		MM = other.Count;
		other.Count = Count;
		Count = MM;

		MM = other.Capacity;
		other.Capacity = Capacity;
		Capacity = MM;
	}
	template <class T> const T* vector<T>::ptr(void) const
	{
		return content;
	}
	template <class T> T* vector<T>::ptr(void)
	{
		return content;
	}
	template <class T> const T* vector<T>::ptr(size_t offset)const
	{
		return content + offset;
	}
	template <class T> T* vector<T>::ptr(size_t offset)
	{
		return content + offset;
	}
	template <class T> const T& vector<T>::operator[](size_t target) const
	{
		return content[target];
	}
	template <class T> T& vector<T>::operator[](size_t target)
	{
		return content[target];
	}
	template <class T> void vector<T>::value(const T& element)
	{
		size_t i;
		for (i = 0; i < Count; i++)
			content[i] = element;
	}
	template <class T> const T& vector<T>::top(void) const
	{
		size_t target;
		target = Count != 0 ? Count - 1 : 0;
		return content[target];
	}
	template <class T> T& vector<T>::top(void)
	{
		size_t target;
		target = Count != 0 ? Count - 1 : 0;
		return content[target];
	}
	//template <class T> bool operator<(size_t i, const vector<T>& right)
	//{
	//	return i < right.Count;
	//}


	template <class T> array<T>::array()
	{
		Length = 0;
		content = NULL;
	}
	template <class T> array<T>::~array()
	{
		Length = 0;
		free(content);
		content = NULL;
	}
	template <class T> size_t array<T>::length(void) const
	{
		return Length;
	}
	template <class T> T* array<T>::ptr(void)
	{
		return content;
	}
	template <class T> T* array<T>::ptr(size_t offset)
	{
		return content + offset;
	}
	template <class T> const T* array<T>::ptr(size_t offset) const
	{
		return content + offset;
	}
	template <class T> T& array<T>::operator[](size_t target)
	{
		return content[target];
	}
	template <class T> T& array<T>::operator[](const size_t target) const
	{
		return content[target];
	}
	template <class T> void array<T>::Malloc(size_t NewSize)
	{
		Length = NewSize;
		content = (T*)malloc(NewSize * sizeof(T));
	}
	template <class T> void array<T>::Realloc(size_t NewSize)
	{
		content = (T*)realloc(content, NewSize * sizeof(T));
		Length = NewSize;
	}
	template <class T> void array<T>::Free(void)
	{
		Length = 0;
		free(content);
		content = NULL;
	}
	template <class T> void array<T>::value(const T& element)
	{
		size_t i;
		for (i = 0; i < Length; i++)
			content[i] = element;
	}

	template <class T> tree<T>::tree()
	{
		parent = NULL;
		No = 0;
	}
	template <class T> tree<T>::~tree()
	{
	}
	template <class T> void tree<T>::clear(void)
	{
		vector<tree<T>*> deleted;
		size_t i;
		PostOrderTraversal(deleted);
		for (i = 1; i < deleted.count(); i++)
			delete deleted[i - 1];
		childs.Free();
	}
	template <class T> void tree<T>::PostOrderTraversal(vector<tree<T>*>& output)
	{
		vector<bool> StackState;
		vector<tree<T>*> StackSite;
		tree<T>* here;
		bool label;
		size_t i;
		for (i = childs.length(); i != 0; i--)
		{
			StackSite.append(childs[i - 1]);
			StackState.append(false);
		}
		while (StackState.pop(label) != 0)
		{
			StackSite.pop(here);
			if (here == NULL) continue;
			if (label) output.append(here);
			else
			{
				StackSite.append(here);
				StackState.append(true);

				for (i = here->childs.length(); i != 0; i--)
				{
					StackSite.append(here->childs[i - 1]);
					StackState.append(false);
				}
			}
		}
		output.append((tree<T>*)this);
	}
	template <class T> void tree<T>::build(vector<tree<T>*>& input)
	{
		size_t i;
		childs.Realloc(input.count());
		for (i = 0; i < input.count(); i++)
		{
			childs[i] = input[i];
			childs[i]->parent = this;
			childs[i]->No = i;
		}
	}
	template <class T> void tree<T>::build(vector<tree<T>*>& input, size_t offset)
	{
		size_t i;
		if (input.count() <= offset)
		{
			childs.Realloc(0);
			return;
		}
		childs.Realloc(input.count() - offset);
		for (i = 0; i < input.count() - offset; i++)
		{
			childs[i] = input[i + offset];
			childs[i]->parent = this;
			childs[i]->No = i;
		}
	}
	template <class T> T& tree<T>::root(void)
	{
		return content;
	}
	template <class T> const T& tree<T>::root(void) const
	{
		return content;
	}

	template <class T> size_t tree<T>::ChildCount(void) const
	{
		return childs.length();
	}
	template <class T> tree<T>* tree<T>::child(size_t No) const
	{
		return childs[No];
	}
	template <class T> int& tree<T>::PostIterator::state(void)
	{
		return stack.top().state;
	}
	template <class T> tree<T>*& tree<T>::PostIterator::target(void)
	{
		return stack.top().target;
	}
	template <class T> void tree<T>::PostIterator::initial(tree<T>* root)
	{
		Iterator now;
		stack.clear();
		if (root != NULL)
		{
			now.state = 0;
			now.target = root;
			stack.append(now);
		}
	}
	template <class T> void tree<T>::PostIterator::next(void)
	{
		size_t i; 
		Iterator now, parent;
		tree<T>* here;
		if (stack.pop(parent) != 0)
		{
			if (parent.state == 0)
			{
				parent.state = 1;
				stack.append(parent);
				here = parent.target;
				now.state = 0;
				for (i = here->childs.length(); i != 0; i--)
				{
					now.target = here->childs[i - 1];
					stack.append(now);
				}
			}
		}
		
	}
	template <class T> bool tree<T>::PostIterator::still(void)
	{
		return stack.count() != 0;
	}


	template <class T> BiTree<T>::BiTree()
	{
		Left = NULL;
		Right = NULL;
		tempLabel = NULL;
	}
	template <class T> BiTree<T>::~BiTree()
	{
		Left = NULL;
		Right = NULL;
	}
	template <class T> int& BiTree<T>::iterator::state(void)
	{
		return stack.top().state;
	}
	template <class T> BiTree<T>*& BiTree<T>::iterator::target(void)
	{
		return stack.top().target;
	}
	template <class T> void BiTree<T>::iterator::initial(BiTree<T>* root)
	{
		Iterator now;
		stack.clear();
		if (root != NULL)
		{
			now.state = 0;
			now.target = root;
			stack.append(now);
		}
	}
	template <class T> void BiTree<T>::iterator::next(void)
	{
		size_t i;
		Iterator now, parent;
		now.state = 0;
		if (stack.pop(parent) != 0)
		{
			if (parent.state == 0)
			{
				parent.state = 2;
				stack.append(parent);
				if (parent.target->Right != NULL)
				{
					now.target = parent.target->Right;
					stack.append(now);
				}
				parent.state = 1;
				stack.append(parent);
				if (parent.target->Left != NULL)
				{
					now.target = parent.target->Left;
					stack.append(now);
				}
			}
		}

	}
	template <class T> bool BiTree<T>::iterator::still(void)
	{
		return stack.count() != 0;
	}

	template <class T> void BiTree<T>::clear(void)
	{
		vector<BiTree<T>*> output;
		size_t i;
		PostOrderTraversal(output);
		for (i = 1; i < output.count(); i++) delete output[i - 1];
		Left = NULL;
		Right = NULL;
	}
	template <class T> BiTree<T>* BiTree<T>::copy(void)
	{
		vector<BiTree<T>*> output;
		size_t i;
		BiTree<T>* now, *temp;
		PostOrderTraversal(output);
		for (i = 0; i < output.count(); i++)
		{
			now = output[i];
			temp = new BiTree<T>;
			temp->Content.copy(now->Content);
			if (now->Left != NULL)
			{
				temp->Left = (BiTree<T>*)now->Left->tempLabel;
				now->Left->tempLabel = NULL;
			}
			if (now->Right != NULL)
			{
				temp->Right = (BiTree<T>*)now->Right->tempLabel;
				now->Right->tempLabel = NULL;
			}
			now->tempLabel = (void*)temp;
		}
		now = (BiTree<T>*)tempLabel;
		tempLabel = NULL;
		return now;
	}
	template <class T> void BiTree<T>::build(BiTree<T>* left_, BiTree<T>* right_)
	{
		Left = left_;
		Right = right_;
	}
	template <class T> T& BiTree<T>::content(void)
	{
		return Content;
	}
	template <class T> const T& BiTree<T>::content(void) const
	{
		return Content;
	}
	template <class T> BiTree<T>*& BiTree<T>::left(void)
	{
		return Left;
	}
	template <class T> BiTree<T>*& BiTree<T>::right(void)
	{
		return Right;
	}
	template <class T> void*& BiTree<T>::label(void)
	{
		return tempLabel;
	}
	template <class T> void BiTree<T>::PreOrderTraversal(vector<BiTree<T>*>& output)
	{
		vector<BiTree<T>*> stack;
		PreOrderTraversal(output, stack);
	}
	template <class T> void BiTree<T>::PreOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack)
	{
		BiTree<T>* now;
		stack.clear();
		stack.append(this);
		while (stack.pop(now) != 0)
		{
			if (now != NULL)
			{
				output.append(now);
				stack.append(now->Right);
				stack.append(now->Left);
			}
		}
	}
	template <class T> void BiTree<T>::InOrderTraversal(vector<BiTree<T>*>& output)
	{
		vector<BiTree<T>*> stack;
		InOrderTraversal(output, stack);
	}
	template <class T> void BiTree<T>::InOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack)
	{
		BiTree<T>* now;
		stack.clear();
		now = this;
		while (now != NULL || stack.count() != 0)
		{
			while (now != NULL)
			{
				stack.append(now);
				now = now->Left;
			}
			stack.pop(now);
			output.append(now);
			now = now->Right;
		}
	}
	template <class T> void BiTree<T>::PostOrderTraversal(vector<BiTree<T>*>& output)
	{
		vector<BiTree<T>*> stack;
		PostOrderTraversal(output, stack);
	}
	template <class T> void BiTree<T>::PostOrderTraversal(vector<BiTree<T>*>& output, vector<BiTree<T>*>& stack)
	{
		BiTree<T>* now;
		BiTree<T>* LeftMost, * LastOutput;
		stack.clear();
		now = this;
		LastOutput = NULL;
		while (now != NULL || stack.count() != 0)
		{
			while (now != NULL)
			{
				stack.append(now);
				now = now->Left;
			}
			LeftMost = stack.top();
			if (LeftMost->Right == NULL || LeftMost->Right == LastOutput)
			{
				output.append(LeftMost);
				LastOutput = LeftMost;
				stack.pop();
			}
			else
				now = LeftMost->Right;
		}
	}

	template <class T> buffer<T>::buffer()
	{
		Rear = 0;
		Capacity = 0;
		Head = 0;
		content = NULL;
	}
	template <class T> buffer<T>::~buffer()
	{
		Rear = 0;
		Capacity = 0;
		Head = 0;
		free(content);
		content = NULL;
	}
	template <class T> void buffer<T>::append(const buffer<T>& other)
	{
		size_t L, i;
		L = other.count();
		if (Rear + L > Capacity)
		{
			content = (T*)realloc(content, (Capacity + L + 4) * sizeof(T));
			Capacity = Capacity + L + 4;
		}
		for (i = 0; i < L; i++) content[i + Rear] = other.content[i + other.Head];
		Rear += L;
		return;
	}
	template <class T> size_t buffer<T>::append(const T& element)
	{
		size_t should;
		should = expand();
		content[should] = element;
		return should;
	}
	template <class T> void buffer<T>::clear(void)
	{
		Head = 0;
		Rear = 0;
	}
	template <class T> size_t buffer<T>::expand(void)
	{
		size_t should, new_size;
		if (Rear >= Capacity)
		{
			new_size = (Capacity + Capacity / 4 + 8);
			content = (T*)realloc(content, new_size * sizeof(T));
			Capacity = new_size;
		}
		should = Rear;
		Rear += 1;
		return should;
	}
	template <class T> void buffer<T>::expand(size_t L)
	{
		if (Rear + L > Capacity)
		{
			content = (T*)realloc(content, (Capacity + L + 4) * sizeof(T));
			Capacity = Capacity + L + 4;
		}
		return;
	}
	template <class T> bool buffer<T>::dequeue(T& out)
	{
		if (Head < Rear)
		{
			out = content[Head];
			Head += 1;
			return true;
		}
		return false;
	}
	template <class T> bool buffer<T>::backspace(T& in)
	{
		if (Head != 0)
		{
			Head -= 1;
			content[Head] = in;
			return true;
		}
		return false;
	}
	template <class T> bool buffer<T>::backspace(buffer<T>& in)
	{
		size_t i, LL;
		LL = in.Rear - in.Head;
		if (LL <= Head)
		{
			Head -= LL;
			for (i = 0; i < LL; i++)
			{
				content[Head + i] = in[in.Head + i];
			}
			in.clear();
			return true;
		}
		return false;
	}
	template <class T> T* buffer<T>::ptr(void)
	{
		//append('\0');
		return content + Head;
	}
	template <class T> size_t buffer<T>::count(void) const
	{
		return (size_t)(Rear - Head);
	}
	template <class T> size_t buffer<T>::rear(void) const
	{
		return Rear;
	}
	template <class T> size_t buffer<T>::capacity(void) const
	{
		return Capacity;
	}
	template <class T> size_t buffer<T>::head(void) const
	{
		return Head;
	}
	template <class T> T& buffer<T>::operator[](size_t target) const
	{
		return content[target];
	}
}
namespace hyperlex
{
	template <class T> list<T>::list()
	{
		Count = 0;
		Size = 0;
		content = NULL;
	}
	template <class T> list<T>::~list()
	{
		Count = 0;
		Size = 0;
		free(content);
		content = NULL;
	}
	template <class T> void list<T>::append(const T& element)
	{
		size_t should;
		should = append();
		content[should] = element;
	}
	template <class T> size_t list<T>::SearchAppend(const T& element)
	{
		size_t i, j;
		const T* temp;
		for (i = 0; i < Count; i++)
		{
			if (content[i] == element) return i;
		}
		append(element);
		return Count - 1;
	}
	template <class T> void list<T>::refresh(void)
	{
		Count = 0;
	}
	template <class T> void list<T>::refresh(size_t NewCount)
	{
		content = (T*)realloc(content, NewCount * sizeof(T));
		Size = NewCount;
		Count = NewCount;
	}
	template <class T> void list<T>::renew(size_t NewCount)
	{
		if (NewCount > Size)
		{
			//std::cout <<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<< std::endl;
			//std::cout << "NewCount: " << NewCount << "Size: " << Size << std::endl;
			//std::cout << "old content: " << content << std::endl;
			content = (T*)realloc(content, NewCount * sizeof(T));
			//std::cout << "new content: " << content << std::endl;
			Size = NewCount;
		}
		Count = NewCount;
	}
	template <class T> void list<T>::reshape(size_t NewSize)
	{
		if (NewSize <= Count) Count = NewSize;
		content = (T*)realloc(content, NewSize * sizeof(T));
		Size = NewSize;
	}
	template <class T> size_t list<T>::pop(T& element)
	{
		if (Count != 0)
		{
			Count -= 1;
			element = content[Count];
			return Count + 1;
		}
		return Count;
	}
	template <class T> void list<T>::pop(void)
	{
		if (Count != 0) Count -= 1;
	}
	template <class T> size_t list<T>::append(void)
	{
		size_t should, new_size;
		if (Count >= Size)
		{
			new_size = (Size + Size / 4 + 8);
			content = (T*)realloc(content, new_size * sizeof(T));
			Size = new_size;
		}
		should = Count;
		Count += 1;
		return should;
	}
	template <class T> size_t list<T>::count(void) const
	{
		return Count;
	}
	template <class T> size_t list<T>::size(void) const
	{
		return Size;
	}
	template <class T> void list<T>::swap(list<T>& other)
	{
		T* middle;
		middle = other.content;
		other.content = content;
		content = middle;

		size_t MM;

		MM = other.Count;
		other.Count = Count;
		Count = MM;

		MM = other.Size;
		other.Size = Size;
		Size = MM;
	}
	template <class T> const T* list<T>::vector(void)const
	{
		return content;
	}
	template <class T> T* list<T>::vector(void)
	{
		return content;
	}
	template <class T> const T* list<T>::vector(size_t offset)const
	{
		return content + offset;
	}
	template <class T> T* list<T>::vector(size_t offset)
	{
		return content + offset;
	}
	template <class T> const T& list<T>::operator[](size_t target) const
	{
		return content[target];
	}
	template <class T> T& list<T>::operator[](size_t target)
	{
		return content[target];
	}
	template <class T> void list<T>::value(const T& element)
	{
		size_t i;
		for (i = 0; i < Count; i++)
			content[i] = element;
	}
	template <class T> const T& list<T>::top(void) const
	{
		size_t target;
		target = Count != 0 ? Count - 1 : 0;
		return content[target];
	}
	template <class T> T& list<T>::top(void)
	{
		size_t target;
		target = Count != 0 ? Count - 1 : 0;
		return content[target];
	}


	template <class T> matlist<T>::matlist()
	{
		Row = 0;
		Column = 1;
		Length = 0;
		//fprintf(stdout, "matlist(): row(): %zu, column(): %zu,  length(): %zu.\n", Row, Column, Length);
		content = NULL;
	}
	template <class T> matlist<T>::matlist(size_t column)
	{
		Row = 0;
		Column = column;
		Length = 0;
		content = NULL;
	}
	template <class T> matlist<T>::~matlist()
	{
		Row = 0;
		Column = 0;
		Length = 0;
		free(content);
		content = NULL;
	}
	template <class T> void matlist<T>::refresh(void)
	{
		Row = 0;
	}
	template <class T> void matlist<T>::refresh(size_t row, size_t column, size_t length)
	{
		Row = row;
		Column = column;
		Length = length;
		//free(content);
		//fprintf(stdout, "refresh: row(): %zu, column(): %zu,  length(): %zu.\n", row, column, length);
		content = (T*)realloc(content, column * length * sizeof(T));
		//if(content == NULL) fprintf(stdout, "refresh: content == NULL.\n");
		//else fprintf(stdout, "refresh: content == %zu.\n", (size_t)content);
	}
	template <class T> void matlist<T>::refresh(size_t column, size_t length)
	{
		Row = 0;
		Column = column;
		Length = length;
		//free(content);
		content = (T*)realloc(content, column * length * sizeof(T));
	}
	template <class T> void matlist<T>::append(const T* element)
	{
		size_t i;
		T* line;
		line = append();
		for (i = 0; i < Column; i++) line[i] = element[i];

	}
	//size_t pop(T* element);
	template <class T> T* matlist<T>::append(void)
	{
		size_t should, new_size;
		if (Row >= Length)
		{
			new_size = (Length + Length / 4 + 8);
			content = (T*)realloc(content, Column * new_size * sizeof(T));
			Length = new_size;
			//std::cout << "content: " << content << ", new_size: " << new_size << "Row: " << Row << std::endl;
		}
		should = Row;
		Row += 1;
		return content + should * Column;
	}

	template <class T> size_t matlist<T>::SearchAdd(const T* element)
	{
		size_t i, j;
		const T* temp;
		for (i = 0; i < Row; i++)
		{
			temp = content + i * Column;
			for (j = 0; j < Column; j++)
				if (temp[j] != element[j]) break;
			if (j == Column) return i;
		}
		append(element);
		return Row - 1;
	}
	template <class T> size_t matlist<T>::column(void) const
	{
		return Column;
	}
	template <class T> size_t matlist<T>::row(void) const
	{
		return Row;
	}
	template <class T> size_t matlist<T>::length(void) const
	{
		return Length;
	}
	template <class T> void matlist<T>::swap(matlist<T>& other)
	{
		T* middle;
		middle = other.content;
		other.content = content;
		content = middle;

		size_t MM;

		MM = other.Column;
		other.Column = Column;
		Column = MM;

		MM = other.Row;
		other.Row = Row;
		Row = MM;

		MM = other.Length;
		other.Length = Length;
		Length = MM;
	}
	template <class T> const T* matlist<T>::operator[](size_t target) const
	{

		return content + target * Column;
	}
	template <class T> T* matlist<T>::operator[](size_t target)
	{
		//fprintf(stdout, "template <class T> T* matlist<T>::operator[](size_t target)\n");
		//fprintf(stdout, "target: %zu, Column: %zu, content: %zu\n", target, Column, (size_t)content);
		return content + target * Column;
	}
	template <class T> void matlist<T>::value(const T element)
	{
		size_t i;
		for (i = 0; i < Row * Column; i++)
		{
			content[i] = element;
		}
	}

	template <class T> vec<T>::vec()
	{
		Size = 0;
		content = NULL;
	}
	template <class T> vec<T>::~vec()
	{
		Size = 0;
		free(content);
		content = NULL;
	}
	template <class T> size_t vec<T>::size(void) const
	{
		return Size;
	}
	template <class T> T* vec<T>::vector(void)
	{
		return content;
	}
	template <class T> T& vec<T>::operator[](size_t target)
	{
		return content[target];
	}
	template <class T> T& vec<T>::operator[](const size_t target) const
	{
		return content[target];
	}
	template <class T> void vec<T>::Malloc(size_t NewSize)
	{
		Size = NewSize;
		content = (T*)malloc(NewSize * sizeof(T));
	}
	template <class T> void vec<T>::Realloc(size_t NewSize)
	{
		content = (T*)realloc(content, NewSize * sizeof(T));
		Size = NewSize;
	}
	template <class T> void vec<T>::Free(void)
	{
		Size = 0;
		free(content);
		content = NULL;
	}


}
namespace hyperlex
{
	template <class Cg, class Ca> Dgraph<Cg, Ca>::Dgraph()
	{

	}
	template <class Cg, class Ca> Dgraph<Cg, Ca>::~Dgraph()
	{

	}
	template <class Cg, class Ca> Cg& Dgraph<Cg, Ca>::operator[](size_t target)
	{
		return vertice.content[target].content;
	}
	template <class Cg, class Ca> void Dgraph<Cg, Ca>::refresh(void)
	{
		vertice.refresh();
		arcs.clear();
	}
	template <class Cg, class Ca> void Dgraph<Cg, Ca>::refresh(size_t newlength)
	{
		size_t i;
		vertice.refresh(newlength);
		arcs.clear();
		for (i = 0; i < vertice.count(); i++)
		{
			vertice[i].first = SizeMax;
			vertice[i].rear = SizeMax;
		}
	}
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::FirstArc(size_t site) const
	{
		return vertice[site].first;
	}
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::NextArc(size_t site) const
	{
		return arcs[site].next;
	}
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::ArcTo(size_t site) const
	{
		return arcs[site].to;
	}
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::ArcCount(size_t site) const
	{
		size_t count_, first_;
		count_ = 0;
		first_ = vertice[site].first;
		while (first_ != SizeMax)
		{
			first_ = arcs[first_].next;
			count_ += 1;
		}
		return count_;
	}
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::append(size_t from, size_t to, const Ca& C)
	{
		size_t should;
		should = arcs.expand();
		arcs[should].from = from;
		arcs[should].to = to;
		arcs[should].content = C;
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
	template <class Cg, class Ca> void Dgraph<Cg, Ca>::append(const Dgraph<Cg, Ca>& right, size_t VerticeOffset)
	{
		size_t ArcsOffset;
		size_t i, length, temp;
		ArcsOffset = arcs.rear();
		length = right.vertice.count();
		for (i = 0; i < length; i++)
		{
			temp = (right.vertice[i].first == SizeMax ? SizeMax : right.vertice[i].first + ArcsOffset);
			vertice[i + VerticeOffset].first = temp;
			temp = (right.vertice[i].rear == SizeMax ? SizeMax : right.vertice[i].rear + ArcsOffset);
			vertice[i + VerticeOffset].rear = temp;
		}
		//begin = arcs.site();
		arcs.append(right.arcs);
		//arcs.expand(right.arcs.count());
		length = right.arcs.count();
		for (i = ArcsOffset; i < length + ArcsOffset; i++)
		{
			arcs[i].from += VerticeOffset;
			arcs[i].to += VerticeOffset;
			temp = (arcs[i].next == SizeMax ? SizeMax : arcs[i].next + ArcsOffset);
			arcs[i].next = temp;
		}
	}
	template <class Cg, class Ca> void Dgraph<Cg, Ca>::Demo(FILE* fp)const 
	{
		fprintf(fp, "vertice.count() = %llu\n", (long long int)vertice.count());
		fprintf(fp, "arcs.count() = %llu\n", (long long int)arcs.count());
		//vertice.refresh();
		//arcs.refresh();
	}

	template <class Cg> LRNFA<Cg>::LRNFA()
	{

	}
	template <class Cg> LRNFA<Cg>::~LRNFA()
	{

	}
	template <class Cg> Cg& LRNFA<Cg>::operator[](size_t target)
	{
		return vertice[target].content;
	}
	template <class Cg> const Cg& LRNFA<Cg>::operator[](size_t target) const
	{
		return vertice[target].content;
	}
	template <class Cg> void LRNFA<Cg>::refresh(void)
	{
		vertice.refresh();
		arcs.refresh();
	}
	template <class Cg> void LRNFA<Cg>::refresh(size_t newlength)
	{
		size_t i;
		vertice.refresh(newlength);
		arcs.clear();
		for (i = 0; i < vertice.count(); i++)
		{
			vertice[i].first = SizeMax;
			vertice[i].rear = SizeMax;
		}
	}
	template <class Cg> size_t LRNFA<Cg>::VortexAppend(const Cg& element)
	{
		size_t length;
		vortex V;
		length = vertice.count();
		V.first = SizeMax;
		V.rear = SizeMax;
		V.content = element;
		vertice.append(V);
		return length;
	}
	template <class Cg> size_t LRNFA<Cg>::FirstArc(size_t site) const
	{
		return vertice[site].first;
	}
	template <class Cg> size_t LRNFA<Cg>::NextArc(size_t site) const
	{
		return arcs[site].next;
	}
	template <class Cg> size_t LRNFA<Cg>::ArcTo(size_t site) const
	{
		return arcs[site].to;
	}
	template <class Cg> size_t LRNFA<Cg>::ArcCount(size_t site) const
	{
		size_t count_, first_;
		count_ = 0;
		first_ = vertice[site].first;
		while (first_ != SizeMax)
		{
			first_ = arcs[first_].next;
			count_ += 1;
		}
		return count_;
	}
	template <class Cg> size_t LRNFA<Cg>::append(size_t from, size_t to, bool Epsilon, long long int Symbol)
	{
		size_t should;
		should = arcs.expand();
		arcs[should].from = from;
		arcs[should].to = to;
		arcs[should].epsilon = Epsilon;
		arcs[should].symbol = Symbol;
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
	template <class Cg> void LRNFA<Cg>::Demo(FILE* fp) const
	{
		fprintf(fp, "vertice.count() = %llu\n", (long long int)vertice.count());
		fprintf(fp, "arcs.count() = %llu\n", (long long int)arcs.count());
		//vertice.refresh();
		//arcs.refresh();
	}
	template <class Cg> void LRNFA<Cg>::initial(bool* state, list<size_t>& stack) const
	{
		size_t i;
		state[0] = true;
		for (i = 1; i < vertice.count(); i++) state[i] = false;
		closure(state, stack);
	}
	template <class Cg> void LRNFA<Cg>::closure(bool* state, list<size_t>& stack) const
	{
		size_t delta;
		size_t Scount;
		size_t i;
		size_t now, arc, temp;
		Scount = 0;
		delta = 0;
		stack.refresh();
		for (i = 0; i < vertice.count(); i++)
			if (state[i])
			{
				Scount += 1;
				stack.append(i);
			}
		while (stack.pop(now) != 0)
		{
			arc = vertice[now].first;
			while (arc != SizeMax)
			{
				if (arcs[arc].epsilon == true)
				{
					temp = arcs[arc].to;
					if (!state[temp])
					{
						state[temp] = true;
						stack.append(temp);
						delta += 1;
					}
				}
				arc = arcs[arc].next;
			}
		}
	}
	template <class Cg> size_t LRNFA<Cg>::move(const bool* from, bool* to, long long int ele, list<size_t>& stack) const
	{
		size_t i;
		size_t Scount;
		size_t now, arc;
		Scount = 0;
		for (i = 0; i < vertice.count(); i++) to[i] = false;
		for (i = 0; i < vertice.count(); i++)
			if (from[i])
			{
				arc = vertice[i].first;
				while (arc != SizeMax)
				{
					if (arcs[arc].symbol == ele && arcs[arc].epsilon == false)
					{
						now = arcs[arc].to;
						Scount += (to[now] ? 0 : 1);
						to[now] = true;
					}
					arc = arcs[arc].next;
				}
			}
		closure(to, stack);
		return Scount;
	}
	template <class Cg> void LRNFA<Cg>::build(matlist<int>& sheet, matlist<bool>& Dstates, size_t NonTcount, size_t Tcount) const
	{
		list<size_t> stack;
		list<size_t> auxiliary;
		//matlist<bool> Dstates(graph.vertice.count());
		size_t now, old;
		bool* state;
		vec<bool> to;
		long long int ele, symbol;
		size_t Scount, TotalSymbol;
		TotalSymbol = NonTcount + Tcount;
		sheet.refresh(0, TotalSymbol, 4);
		Dstates.refresh(0, vertice.count(), 4);
		to.Malloc(vertice.count());
		auxiliary.reshape(vertice.count());
		auxiliary.refresh();
		state = Dstates.append();

		initial(state, auxiliary);
		//return;
		stack.append(0);
		sheet.append();
		//return;
		while (stack.pop(now) != 0)
		{
			//Demo(stdout, state, nfa.StateAmount);
			for (ele = 0; (size_t)ele < TotalSymbol; ele++)
			{
				state = Dstates[now];
				symbol = ele < NonTcount ? ele : -(long long int)((ele + 1) - NonTcount);
				Scount = move(state, to.vector(), symbol, auxiliary);
				//std::cout << "Scount: " << Scount << ");" << std::endl;
				if (Scount == 0) sheet[now][(size_t)ele] = -1;
				else
				{
					//std::cout << "Scount: " << Scount << ", symbol = " << symbol << std::endl;
					old = Dstates.row();
					sheet[now][(size_t)ele] = (int)(Dstates.SearchAdd(to.vector()));
					if (old != Dstates.row())
					{
						sheet.append();
						stack.append(old);
					}
					//if (old != Dstates.row()) Demo(stdout, Dstates[old], nfa.StateAmount);
				}
				//std::cout << "Scount: " << Scount << ");" << std::endl;
			}
		}
		//std::cout << "Dstates.row(): " << Dstates.row() << std::endl;
		//Demo(stdout, Dstates[old], nfa.StateAmount);
		//count = Dstates.row();
		//acceptSet(Dstates, nfa);
	}
}
namespace hyperlex
{
	template <class T> bitree<T>::bitree()
	{
		left = NULL;
		right = NULL;
	}
	template <class T> bitree<T>::~bitree()
	{

	}
	template <class T> const bitree<T>*& bitree<T>::L(void) const
	{
		return left;
	}
	template <class T> const bitree<T>*& bitree<T>::R(void) const
	{
		return right;
	}
	template <class T> bitree<T>*& bitree<T>::L(void)
	{
		return left;
	}
	template <class T> bitree<T>*& bitree<T>::R(void)
	{
		return right;
	}
	template <class T> const T& bitree<T>::C(void) const
	{
		return content;
	}
	template <class T> T& bitree<T>::C(void)
	{
		return content;
	}
	template <class T> void bitree<T>::postorderTraversal(buffer<size_t>& output, list<size_t>& s) const
	{

	}
	template <class T> void bitree<T>::postorderTraversal(buffer<size_t>& output) const
	{
		list<size_t> s;
		postorderTraversal(output, s);
	}
	template <class T> void bitree<T>::inorderTraversal(buffer<size_t>& output, list<size_t>& s) const
	{
		bitree<T>* LeftMost;
		bitree<T>* now;
		now = this;
		while (now != NULL || s.count() != 0)
		{
			while (now != NULL)
			{
				s.append(now);
				now = now->left;
			}
			s.pop(LeftMost);
			output.append(LeftMost);
			now = LeftMost->right;
		}
	}
	template <class T> void bitree<T>::inorderTraversal(buffer<size_t>& output) const
	{
		list<size_t> s;
		inorderTraversal(output, s);
	}
	template <class T> bool bitree<T>::IfLeaf(size_t site)const
	{
		return left == NULL && right == NULL;
	}



	template <class T> Bitree<T>::Bitree()
	{
		Nodes = NULL;
		Count = 0;
		Size = 0;
		Head = SizeMax;
		FirstEmpty = SizeMax;
	}
	template <class T> Bitree<T>::~Bitree()
	{
		free(Nodes);
		Nodes = NULL;
		Count = 0;
		Size = 0;
		Head = SizeMax;
		FirstEmpty = SizeMax;
	}
	template <class T> void Bitree<T>::move(Bitree<T>& source)
	{
		Nodes = source.Nodes;
		Count = source.Count;
		Size = source.Size;
		Head = source.Head;
		FirstEmpty = source.FirstEmpty;
		
		source.Nodes = NULL;
		source.Count = 0;
		source.Size = 0;
		source.Head = SizeMax;
		source.FirstEmpty = SizeMax;
	}
	template <class T> void Bitree<T>::clear(void)
	{
		size_t i;
		if (Nodes == NULL)return;
		Head = SizeMax;
		Count = 0;
		FirstEmpty = 0;
		for (i = 0; i < Size; i++)
		{
			Nodes[i].right = SizeMax;
			Nodes[i].left = i + 1;
		}
		Nodes[Size - 1].left = SizeMax;
	}
	template <class T> void Bitree<T>::SetHead(size_t head)
	{
		Head = head;
	}
	template <class T> typename Bitree<T>::node* Bitree<T>::NewNode(void)
	{
		return Nodes + NewNodeOffset();
	}
	template <class T> size_t Bitree<T>::NewNodeOffset(void)
	{
		size_t result, NewSize__, i;
		if (FirstEmpty == SizeMax)
		{
			NewSize__ = (Size + Size / 4 + 8);
			Nodes = (node*)realloc(Nodes, NewSize__ * sizeof(node));
			for (i = Size; i < NewSize__; i++)
			{
				Nodes[i].right = SizeMax;
				Nodes[i].left = i + 1;
			}
			Nodes[NewSize__ - 1].left = SizeMax;
			FirstEmpty = Size;
			Size = NewSize__;
		}
		result = FirstEmpty;
		FirstEmpty = Nodes[FirstEmpty].left;
		Nodes[result].left = SizeMax;
		Count += 1;
		//if (result == 0) Head = 0;
		return result;
	}
	template <class T> typename Bitree<T>::node* Bitree<T>::Node(size_t site)const
	{
		return Nodes + site;
	}
	template <class T> typename Bitree<T>::node* Bitree<T>::LeftChild(const Bitree<T>::node* now)const
	{
		return Nodes + now->left;
	}
	template <class T> typename Bitree<T>::node* Bitree<T>::RightChild(const Bitree<T>::node* now)const
	{
		return Nodes + now->right;
	}
	template <class T> void Bitree<T>::postorderTraversal(buffer<size_t>& output) const
	{
		list<size_t> s;
		postorderTraversal(output, s);
	}
	template <class T> void Bitree<T>::postorderTraversal(buffer<size_t>& output, list<size_t>& s) const
	{
		size_t previous;
		size_t LeftMost;
		size_t now;
		now = Head;
		previous = SizeMax;
		while (now != SizeMax || s.count() != 0)
		{
			while (now != SizeMax)
			{
				s.append(now);
				now = (Nodes + now)->left;
			}
			LeftMost = s.top();
			if (Nodes[LeftMost].right == SizeMax || Nodes[LeftMost].right == previous)
			{
				output.append(LeftMost);
				previous = LeftMost;
				s.pop();
			}
			else
				now = Nodes[LeftMost].right;
		}
	}
	template <class T> const typename Bitree<T>::node& Bitree<T>::operator[](size_t target) const
	{
		return Nodes[target];
	}
	template <class T> typename Bitree<T>::node& Bitree<T>::operator[](size_t target)
	{
		return Nodes[target];
	}
	template <class T> void Bitree<T>::inorderTraversal(buffer<size_t>& output, list<size_t>& s) const
	{
		size_t LeftMost;
		size_t now;
		now = Head;
		LeftMost = Head;
		while (now != SizeMax || s.count() != 0)
		{
			while (now != SizeMax)
			{
				s.append(now);
				now = (Nodes + now)->left;
			}
			s.pop(LeftMost);
			output.append(LeftMost);
			now = Nodes[LeftMost].right;
		}
	}
	template <class T> void Bitree<T>::inorderTraversal(buffer<size_t>& output) const
	{
		list<size_t> s;
		inorderTraversal(output, s);
	}
	template <class T> bool Bitree<T>::IfLeaf(size_t site)const
	{
		return Nodes[site].left == SizeMax && Nodes[site].right == SizeMax;
	}
	template <class T> void Bitree<T>::Demo(FILE* fp)const
	{
		size_t i;
		fprintf(fp, "Head = %zu\n", Head);
		fprintf(fp, "Size = %zu\n", Size);
		fprintf(fp, "Count = %zu\n", Count);
		fprintf(fp, "FirstEmpty = %zu\n", FirstEmpty);
		if (Nodes == NULL)
		{
			fprintf(fp, "Nodes == NULL\n");
			return;
		}
		for (i = 0; i < Size; i++)
		{
			fprintf(fp, "Nodes[%zu].left = %22zu, ",i , Nodes[i].left); 
			fprintf(fp, "Nodes[%zu].right = %22zu  ", i, Nodes[i].right);
			Nodes[i].content.Demo(fp);
			//fprintf(fp, "\n");
		}
	}


	template <class T> void Bitree<T>::removal(size_t site)
	{
		buffer<size_t>& output;
		list<size_t>& s;
		removal(site, output, s);
	}
	template <class T> void Bitree<T>::removal(size_t site, buffer<size_t>& output, list<size_t>& s)
	{
		if (site == SizeMax) return;
		size_t now;
		s.refresh();
		output.clear();
		inorderTraversal(output, s);
		while (output.dequeue(now))
		{
			Count -= 1;
			(Nodes + now)->right = SizeMax;
			(Nodes + now)->left = FirstEmpty;
			FirstEmpty = now;
		}
	}
	template <class T> void Bitree<T>::append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, size_t& NewSite)
	{
		//size_t newHead;
		size_t now, new_node, temp;
		s.refresh();
		output.clear();
		new_node = SizeMax;
		source.postorderTraversal(output, s);
		s.refresh();
		s.renew(source.Size);
		while (output.dequeue(now))
		{
			new_node = NewNodeOffset();
			//std::cout << "new_node: " << new_node << std::endl;
			//std::cout << "now: " << now << std::endl;
			temp = source.Nodes[now].left;
			(Nodes + new_node)->left = (temp == SizeMax ? SizeMax : s[temp]);
			//std::cout << "source.Nodes[now].left: " << temp << std::endl;
			//std::cout << "(Nodes + new_node)->left: " << (Nodes + new_node)->left << std::endl;
			temp = source.Nodes[now].right;
			(Nodes + new_node)->right = (temp == SizeMax ? SizeMax : s[temp]);
			//std::cout << "source.Nodes[now].right: " << temp << std::endl;
			//std::cout << "(Nodes + new_node)->right: " << (Nodes + new_node)->right << std::endl;
			(Nodes + new_node)->content = source.Nodes[now].content;
			s[now] = new_node;
			//if (newHead == SizeMax) newHead = new_node;
			//newHead = new_node;
		}
		//std::cout << "newHead: " << new_node << std::endl;
		//std::cout << "newHead: " << newHead << std::endl;
		
		NewSite = new_node;
		//std::cout << "return NewSite: " << NewSite << "\n\n" << std::endl;
	}
	template <class T> void Bitree<T>::append(const Bitree<T>& L, size_t parent)
	{
		buffer<size_t> output;
		list<size_t> s;
		size_t NewSite;
		removal((Nodes + parent)->left, output, s);
		append(L, output, s, NewSite);
		(Nodes + parent)->left = NewSite;
	}
	template <class T> void Bitree<T>::append(const Bitree<T>& L, const Bitree<T>& R, size_t parent)
	{
		buffer<size_t> output;
		list<size_t> s;
		size_t NewSite;
		//size_t temp;
		//size_t as[15];
		removal((Nodes + parent)->left, output, s);
		removal((Nodes + parent)->right, output, s);
		//std::cout << "parent: " << parent << std::endl;
		//std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
		append(L, output, s, NewSite);
		(Nodes + parent)->left = NewSite;
		//std::cout << "parent: " << parent << std::endl;
		//temp = (Nodes + parent)->right;
		//std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
		//std::cout << "(Nodes + parent)->right: " << temp << std::endl;
		//(Nodes + parent)->right = 10007;
		//std::cout << "(Nodes + parent)->right: " << (Nodes + parent)->right << std::endl;
		//std::cout << "temp ptr: " << &temp << std::endl;
		//std::cout << "(Nodes + parent) ptr: " << (Nodes + parent) << std::endl;
		//std::cout << "(Nodes + parent)->left ptr: " << (size_t) & ((Nodes + parent)->left) << std::endl;
		//std::cout << "(Nodes + parent)->right ptr: " << &((Nodes + parent)->right) << std::endl;
		
		append(R, output, s, NewSite);
		(Nodes + parent)->right = NewSite;// the style that produced the bug.
		//temp = append(R, output, s);// the style that produced no bug.
		//Nodes[parent].right = temp;// the style that produced no bug. 

		//std::cout << "parent: " << parent << std::endl;
		//std::cout << "(Nodes + parent)->right: " << (Nodes + parent)->right << std::endl;
	}

	
	template <class T> StaticTree<T>::StaticTree()
	{

	}
	template <class T> StaticTree<T>::~StaticTree()
	{

	}
	template <class T> void StaticTree<T>::clear(void)
	{

	}
	template <class T> void StaticTree<T>::build(tree<T>* input)
	{

	}

	template <class T> Tree<T>::Tree()
	{
		Head = NULL;
	}
	template <class T> Tree<T>::~Tree()
	{
		RuinSelf();
	}
	template <class T> void Tree<T>::RuinSelf(void)
	{
		list<node*> deleted;
		size_t i;
		if (Head == NULL) return;
		PostOrderTraversal(deleted);
		for (i = 0; i < deleted.count(); i++)
			delete deleted[i];
		Head = NULL;
	}
	template <class T> void Tree<T>::move(Tree<T>& source)
	{
		Head = source.Head;
		source.Head = NULL;
	}
	template <class T> void Tree<T>::clear(void)
	{
		RuinSelf();
	}
	template <class T> void Tree<T>::PostOrderTraversal(list<node*>& output) const
	{
		/*struct infor
		{
			node* site;
			bool state;
		};
		list<infor> stack;
		infor now;
		node* here;
		size_t i;
		now.site = Head;
		now.state = false;
		stack.append(now);
		while (stack.pop(now) != 0)
		{
			here = now.site;
			if (here == NULL) continue;
			if (now.state) output.append(here);
			else
			{
				now.state = true;
				stack.append(now);
				now.state = false;
				for (i = 0; i < here->childs.size(); i++)
				{
					now.site = here->childs[i];
					stack.append(now);
				}
			}
		}
	*/
	}
	template <class T> void Tree<T>::build(list<Tree>& input)
	{
		size_t i;
		clear();
		Head = new node();
		Head->childs.Realloc(input.count());
		for (i = 0; i < input.count(); i++)
		{
			Head->childs[i] = input[i].Head;
			input[i].Head = NULL;
		}
	}
	template <class T> void Tree<T>::node::build(list<Tree>& input)
	{
		size_t i;
		node* now;
		Tree<T> temp;
		for (i = 0; i < childs.size(); i++)
		{
			temp.Head = childs[i];
			temp.clear();
		}
		childs.Realloc(input.count());
		for (i = 0; i < input.count(); i++)
		{
			childs[i] = input[i].Head;
			input[i].Head = NULL;
		}
	}
	template <class T> T& Tree<T>::head(void)
	{
		return Head->content;
	}
	template <class T> const T& Tree<T>::head(void) const
	{
		return Head->content;
	}
}
namespace hyperlex
{
	int PostfixSwitch(char c);
	bool IfHexa(char c);
	int SwitchHexa(char c);
	int SwitchOcta(char c);
	char dequeue(const char* list, size_t end, size_t& head);
	char CharGet(int& error, const char* list, size_t end, size_t& head);
}

#undef SizeMax 
#undef CharSize

#endif

/*
	template <class T> class stack
	{
	private:
		size_t Top;
		size_t Size;
		T* content;
	public:
		stack();
		~stack();
		void clear(void);
		void reshape(size_t NewSize);
		void push(const T& element);
		size_t pop(T& element);
		size_t size(void) const;
		size_t top(void) const;
		T& operator[](size_t target);
	};

		template <class T> stack<T>::stack(void)
	{
		Top = 0;
		Size = 0;
		content = NULL;
	}
	template <class T> stack<T>::~stack(void)
	{
		Top = 0;
		Size = 0;
		free(content);
		content = NULL;
	}
	template <class T> void stack<T>::clear(void)
	{
		Top = 0;
	}
	template <class T> void stack<T>::reshape(size_t NewSize)
	{
		content = (T*)realloc(content, NewSize * sizeof(T));
		Size = NewSize;
		Top = Top <= Size ? Top : Size;
	}
	template <class T> void stack<T>::push(const T& element)
	{
		content[Top] = element;
		Top += 1;
	}
	template <class T> size_t stack<T>::pop(T& element)
	{
		if (Top != 0)
		{
			Top -= 1;
			element = content[Top];
			return Top + 1;
		}
		return Top;
	}
	template <class T> size_t stack<T>::size(void) const
	{
		return Size;
	}
	template <class T> size_t stack<T>::top(void) const
	{
		return Top;
	}
	template <class T> T& stack<T>::operator[](size_t target)
	{
		return content[target];
	}

*/

/*
template <class T> size_t Bitree<T>::append_t(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s, bool key)
	{
		//size_t newHead;
		size_t now, new_node, temp;
		new_node = 0;
		//std::cout << "new_node site: " << &new_node << std::endl;
		//std::cout << "%rbx in stack: " << *(&new_node + 6) << std::endl;
		//std::cout << "%rbx in stack: " << *(&new_node + 5) << std::endl;
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		//std::cout << "new_node: " << new_node << std::endl;
		s.refresh();
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		output.refresh();
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		new_node = SizeMax;
		source.postorderTraversal(output, s);
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		s.refresh();
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		s.renew(source.Size);
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		while (output.dequeue(now))
		{
			new_node = NewNodeOffset();
			//std::cout << "new_node: " << new_node << std::endl;
			//std::cout << "now: " << now << std::endl;
			temp = source.Nodes[now].left;
			(Nodes + new_node)->left = (temp == SizeMax ? SizeMax : s[temp]);
			//std::cout << "source.Nodes[now].left: " << temp << std::endl;
			//std::cout << "(Nodes + new_node)->left: " << (Nodes + new_node)->left << std::endl;
			temp = source.Nodes[now].right;
			(Nodes + new_node)->right = (temp == SizeMax ? SizeMax : s[temp]);
			//std::cout << "source.Nodes[now].right: " << temp << std::endl;
			//std::cout << "(Nodes + new_node)->right: " << (Nodes + new_node)->right << std::endl;
			(Nodes + new_node)->content = source.Nodes[now].content;
			s[now] = new_node;
			//if (newHead == SizeMax) newHead = new_node;
			//newHead = new_node;
		}
		//std::cout << "newHead: " << newHead << std::endl;
		//std::cout << "return newHead: " << new_node << "\n\n" << std::endl;
		//std::cout << "%rbx in stack: " << *(&new_node + 4) << std::endl;
		return new_node;
	}
	template <class T> void Bitree<T>::append_t(const Bitree<T>& L, const Bitree<T>& R, size_t parent, bool key)
	{
		buffer<size_t> output;
		list<size_t> s;
		size_t temp;
		size_t as[15];
		//if(key) std::cout << "============key is on: ============" << std::endl;
		//else std::cout << "============key is off: ============" << std::endl;
		removal((Nodes + parent)->left, output, s);
		removal((Nodes + parent)->right, output, s);
		//std::cout << "parent: " << parent << std::endl;
		//std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
		(Nodes + parent)->left = append(L, output, s);
		//std::cout << "parent: " << parent << std::endl;
		temp = (Nodes + parent)->right;
		//std::cout << "(Nodes + parent)->left: " << (Nodes + parent)->left << std::endl;
		//std::cout << "(Nodes + parent)->right: " << temp << std::endl;
		(Nodes + parent)->right = 10007;
		//std::cout << "(Nodes + parent)->right: " << (Nodes + parent)->right << std::endl;
		//std::cout << "temp ptr: " << &temp << std::endl;
		//std::cout << "(Nodes + parent) ptr: " << (Nodes + parent) << std::endl;
		//std::cout << "(Nodes + parent)->left ptr: " << (size_t) &((Nodes + parent)->left) << std::endl;
		//std::cout << "(Nodes + parent)->right ptr: " << &((Nodes + parent)->right) << std::endl;
		//if(key) std::cout << "append(R, output, s);: " << append(R, output, s) << std::endl;
		//if (key)
		//{
			//temp = append(R, output, s);
			//Nodes[parent].right = temp;
		//}
		if (key) Nodes[parent].right = append_t(R, output, s, key);
		else Nodes[parent].right = append(R, output, s);


		//std::cout << "parent: " << parent << std::endl;
		//std::cout << "(Nodes + parent)->right(temp): " << temp << std::endl;
		//std::cout << "(Nodes + parent)->right: " << Nodes[parent].right << std::endl;
		if (key) exit(1);
	}
*/
