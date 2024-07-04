#ifndef __automata_adfhaiofh_fh823hasguj45482934__
#define __automata_adfhaiofh_fh823hasguj45482934__
#include<stdio.h>
#include<iostream>

namespace hyperlex
{
	template <class T> class buffer
	{
	protected:
		size_t Site;
		size_t Size;
		size_t Head;
		T* content;
	public:
		buffer();
		~buffer();
		void refresh(void);
		void append(const buffer<T>& other);
		size_t append(const T & element);
		size_t expand(void);
		void expand(const size_t L);
		bool dequeue(T& out);
		bool backspace(T& in);
		bool backspace(buffer<T>& in);
		T* vector(void);
		size_t count(void) const;
		size_t site(void) const;
		size_t size(void) const;
		size_t head(void) const;
		T& operator[](size_t target) const;
	};
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
		size_t append(const Dgraph<Cg, Ca>& right, size_t VerticeOffset);
		void Demo(FILE* fp) const;
	};
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
		void removal(size_t site);
		void removal(size_t site, buffer<size_t>& output, list<size_t>& s);
		size_t append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s);
		void append(const Bitree<T>& left, size_t parent);
		void append(const Bitree<T>& left, const Bitree<T>& right, size_t parent);
	private:
		size_t Head;
		size_t Size;
		size_t Count;
		size_t FirstEmpty;
		node* Nodes;
	};
	class BufferChar : public buffer<char>
	{
	public:
		BufferChar();
		~BufferChar();
		void operator<<(FILE* fp);
		char* vector(void);
	private:
		
	};
}
namespace hyperlex
{
	class NFA;
	class sNFA;
	class sheetDFA;
	class DFA;
	class LR0;
	class LR1;
	class Gsheet;
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
		};
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
		void grow(const RegTree* reg, NodeType T);
		void grow(const RegTree* regL, const RegTree* regR, NodeType T);
		void grow(char L, char U);
		void Reserved(const char* res);
		void Int(void);
		void Identifier(void);
		void IdentifierHead(void);
		void IdentifierInner(void);
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
			RegTree* reg;
			const char* name;
			const char* attribute;
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
		void SetGrammer(void);
		void SetReg(void);
		void append(infor* II);
		void Demo(FILE*fp) const; 
		
	private:
		list<infor*> regular;
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
		size_t append(DirectedGraph & right, size_t VerticeOffset, size_t ArcsOffset, size_t siteOffset);
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
		static void Cprint(FILE* fp, convert& CC);
		static void Demo(FILE* fp, int L, int U);
		static void Demo(FILE* fp, convert &CC);
	private:
		Dgraph<int, convert> graph;
		size_t StateAmount;
		size_t AcceptCount;
	};
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
		int build(FILE* fp);
		int build(BufferChar& input);
		void Demo(FILE* fp) const;
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
		size_t count;
		size_t TerminalCount;
		//[0,count-1] non-terminal
		//[count,TerminalCount + count -1]; terminal
		//TerminalCount + count: epsilon
		//erminalCount + count + 1: END-EOF
		long long int epsilon;
		long long int end;
		list<size_t> degeneracy;
		list<size_t> prefix;
		list<const char*> name;
		list<const char*> ternimal;
		list<production> rules;
		list<long long int> all;

		matlist<bool> first;
		matlist<bool> follow;
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
		void build(const grammerS* G);
		
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
		void Demo(FILE* fp) const;
		void Demo(FILE* fp, const LR0* lr, const grammerS* G)const;
		void Demo(FILE* fp, const LR1* lr, const grammerS* G)const;
		int Goto(size_t state, size_t symbol);
		infor Action(size_t state, size_t symbol);
		static const char* TypeToChar(type TT);
	private:
		size_t StateCount;
		size_t TerminalCount;
		size_t NonTerminalCount;
		size_t RulesCount;

		infor* ACTION;
		infor* GOTO;
		int* RulesToSmbol;


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
	template <class T> buffer<T>::buffer()
	{
		Site = 0;
		Size = 0;
		Head = 0;
		content = NULL;
	}
	template <class T> buffer<T>::~buffer()
	{
		Site = 0;
		Size = 0;
		Head = 0;
		free(content);
		content = NULL;
	}
	template <class T> void buffer<T>::append(const buffer<T>& other)
	{
		size_t L, i;
		L = other.count();
		if (Site + L > Size)
		{
			content = (T*)realloc(content, (Size + L + 4) * sizeof(T));
			Size = Size + L + 4;
		}
		for (i = 0; i < L; i++) content[i + Site] = other.content[i + other.Head];
		Site += L;
		return;
	}
	template <class T> size_t buffer<T>::append(const T& element)
	{
		size_t should;
		should = expand();
		content[should] = element;
		return should;
	}
	template <class T> void buffer<T>::refresh(void)
	{
		Head = 0;
		Site = 0;
	}
	template <class T> size_t buffer<T>::expand(void)
	{
		size_t should, i, new_size;
		if (Site >= Size)
		{
			new_size = (Size + Size / 4 + 8);
			content = (T*)realloc(content, new_size * sizeof(T));
			Size = new_size;
		}
		should = Site;
		Site += 1;
		return should;
	}
	template <class T> void buffer<T>::expand(size_t L)
	{
		if (Site + L > Size)
		{
			content = (T*)realloc(content, (Size + L + 4) * sizeof(T));
			Size = Size + L + 4;
		}
		return;
	}
	template <class T> bool buffer<T>::dequeue(T& out)
	{
		if (Head < Site)
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
		LL = in.Site - in.Head;
		if (LL <= Head)
		{
			Head -= LL;
			for (i = 0; i < LL; i++)
			{
				content[Head + i] = in[in.Head + i];
			}
			in.refresh();
			return true;
		}
		return false;
	}
	template <class T> T* buffer<T>::vector(void)
	{
		//append('\0');
		return content + Head;
	}
	template <class T> size_t buffer<T>::count(void) const
	{
		return (size_t)(Site - Head);
	}
	template <class T> size_t buffer<T>::site(void) const
	{
		return Site;
	}
	template <class T> size_t buffer<T>::size(void) const
	{
		return Size;
	}
	template <class T> size_t buffer<T>::head(void) const
	{
		return Head;
	}
	template <class T> T& buffer<T>::operator[](size_t target) const
	{
		return content[target];
	}


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
		if (NewSize > Size)
		{
			content = (T*)realloc(content, NewCount * sizeof(T));
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
		size_t should, i, new_size;
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
		size_t should, i, new_size;
		if (Row >= Length)
		{
			new_size = (Length + Length / 4 + 8);
			content = (T*)realloc(content, Column * new_size * sizeof(T));
			Length = new_size;
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
		arcs.refresh();
	}
	template <class Cg, class Ca> void Dgraph<Cg, Ca>::refresh(size_t newlength)
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
	template <class Cg, class Ca> size_t Dgraph<Cg, Ca>::append(const Dgraph<Cg, Ca>& right, size_t VerticeOffset)
	{
		size_t ArcsOffset;
		size_t i, length, temp;
		ArcsOffset = arcs.site();
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
		arcs.refresh();
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
			state = Dstates[now];
			//Demo(stdout, state, nfa.StateAmount);
			for (ele = 0; (size_t)ele < TotalSymbol; ele++)
			{
				symbol = ele < NonTcount ? ele : -(long long int)((ele + 1) - NonTcount);
				Scount = move(state, to.vector(), symbol, auxiliary);
				//std::cout << "Scount: " << Scount << ");" << std::endl;
				if (Scount == 0) sheet[now][(size_t)ele] = -1;
				else
				{
					//std::cout << "Scount: " << Scount << ", symbol = " << symbol << std::endl;
					old = Dstates.row();
					sheet[now][(size_t)ele] = Dstates.SearchAdd(to.vector());
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
		size_t LeftMost;
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
			now = Nodes[LeftMost].right;
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
		output.refresh();
		inorderTraversal(output, s);
		while (output.dequeue(now))
		{
			Count -= 1;
			(Nodes + now)->right = SizeMax;
			(Nodes + now)->left = FirstEmpty;
			FirstEmpty = now;
		}
	}
	template <class T> size_t Bitree<T>::append(const Bitree<T>& source, buffer<size_t>& output, list<size_t>& s)
	{
		size_t newHead;
		size_t now, new_node, temp;
		s.refresh();
		output.refresh();
		newHead = SizeMax;
		postorderTraversal(output, s);
		s.refresh();
		s.renew(source.Size);
		while (output.dequeue(now))
		{
			new_node = NewNodeOffset();

			temp = source.Nodes[now].left;
			(Nodes + new_node)->left = (temp == SizeMax ? SizeMax : s[temp]);

			temp = source.Nodes[now].right;
			(Nodes + new_node)->right = (temp == SizeMax ? SizeMax : s[temp]);

			s[now] = new_node;
			if (newHead == SizeMax) newHead = new_node;
		}
		return newHead;
	}
	template <class T> void Bitree<T>::append(const Bitree<T>& L, size_t parent)
	{
		buffer<size_t>& output;
		list<size_t>& s;
		removal((Nodes + parent)->left, output, s);
		(Nodes + parent)->left = append(L, output, s);
	}
	template <class T> void Bitree<T>::append(const Bitree<T>& L, const Bitree<T>& R, size_t parent)
	{
		buffer<size_t>& output;
		list<size_t>& s;
		removal((Nodes + parent)->left, output, s);
		removal((Nodes + parent)->right, output, s);
		(Nodes + parent)->left = append(L, output, s);
		(Nodes + parent)->right = append(R, output, s);
	}
}

#undef SizeMax 
#undef CharSize

#endif
