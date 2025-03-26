lexical:{
	void:
	{
		num: [0-9];
        letter: [a-z]|[A-Z];
        sign: ('-'|'+')?;
	}
	id: id(+1): (<letter> | _)(<letter> | _ | <num>)*;
	number: 
    {
		integer(+3): <sign><num>+;
		realC(+1):  <integer>'.'<num>+((e|E)<integer>)?;
	}
	reserved(+5):
	{
		funct;
		manifold;
		function;
		manif;

		def;
		input;
		output;
		para;

		real;
		sint;
		uint;

		return;
		for;
		if;
		else;					
	};
	function1(+5):
	{
		sin;
		cos;
		exp;
		ln;
		log;
		sqrt;
	}
	function2(+5):
	{
		pow;
	}
	format:
	{
		spaces: ' '+;
		enters: '\n'+;
		tab: '\t';
	}
	division:
	{
		semicolon:';';
		colon:':';
		dot: '.';
		comma: ',';
	}
	braket:
	{
		braceL:'{';
		braceR:'}';
		left:'(';
		right: ')';
		squareL: '[';
		squareR: ']';		
		angleL: '<';
		angleR: '>';
	}
	anntation:
	{
		anntationS: '/''/'(['\0'-'\11']|['\13'-'\177'])*'\n';
		anntationM: '/''*'(['\0'-'\177'])*'*'+'/';
	}
	operatmd:
	{     
		multi: '*';       
		div: '/';   
	}
	operatas:
	{
		sub: '-';
		add: '+';
	}
	value: value: '=';		
};

grammar: FUNCTION:
{
	FUNCTION: <FUNCTWORD> left PARA right braceL MANIFBODY braceR;
	PARA: <MANIFPARAS>;
	<MANIFPARAS>:
	{
		single: MANIFPARA;
		multi: <MANIFPARAS> comma MANIFPARA;
	}
	MANIFPARA:
	{
		input: input id;
		para: para id;
		paras: para id squareL integer squareR;
	}
    <FUNCTWORD>: 
    {
        function: function;
        funct: funct;
    }
	MANIFBODY: DELARATIONS EXPRESSIONS RETURN;
	DELARATIONS: DELARATION*;
	DELARATION:
	{
		single: def id semicolon;
		multi: def id squareL integer squareR semicolon;
	}
	RETURN: return EXP_RIGHT semicolon;
	EXPRESSIONS: EXPRESSION*;
	EXPRESSION: ID value EXP_RIGHT semicolon;
	EXP_RIGHT:
	{
		<implicit>: EXP_MUL;
		add: EXP_RIGHT [operatas] EXP_MUL;
	}
	EXP_MUL:
	{
		<implicit>: EXP_MINUS;
		multi: EXP_MUL [operatmd] EXP_MINUS;
	}
	EXP_MINUS:
	{
		<implicit>: UNIT;
		plus: [operatas] UNIT;
	}
	UNIT:
	{
		id: ID;
		call: CALL;
		const: [number];
		complex: left EXP_RIGHT right;
	}
	ID:
	{
		array: id squareL integer squareR;
		single: id;
	}
	CALL:
	{
		call_1: [function1] left EXP_RIGHT right; 
		call_2: [function2] left EXP_RIGHT comma EXP_RIGHT right; 
	}
}
