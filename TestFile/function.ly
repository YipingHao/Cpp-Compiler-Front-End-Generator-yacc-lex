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
	operation:
	{
		sub: '-';
		add: '+';     
		multi: '*';       
		div: '/';   
	}
	value: value: '=';		
};

grammar: FUNCTION:
{
	FUNCTION: FUNCTWORD left MANIFPARAS right braceL MANIFBODY braceR;
	MANIFPARAS:
	{
		single: MANIFPARA;
		multi: MANIFPARAS comma MANIFPARA;
	}
	MANIFPARA:
	{
		input: input id;
		para: para id;
		paras: para id squareL integer squareR;
	}
    FUNCTWORD: 
    {
        function: function;
        funct: funct;
    }
	MANIFBODY:
	{
		direct: EXPRESSIONS RETURN;
		indirect: DELARATIONS EXPRESSIONS RETURN;
	}
	DELARATIONS:
	{
		single: DELARATION;
		multi: DELARATIONS DELARATION;
	}
	DELARATION:
	{
		single: def id semicolon;
		multi: def id squareL integer squareR semicolon;
	}
	RETURN: return EXP_RIGHT semicolon;
	EXPRESSIONS:
	{
		single: EXPRESSION;
		multi: EXPRESSIONS EXPRESSION; 
	}
	EXPRESSION: ID value EXP_RIGHT semicolon;
	EXP_RIGHT:
	{
		single: EXP_MUL;
		add: EXP_RIGHT add EXP_MUL;
		sub: EXP_RIGHT sub EXP_MUL;
	}
	EXP_MUL:
	{
		single: EXP_MINUS;
		multi: EXP_MUL multi EXP_MINUS;
		div: EXP_MUL div EXP_MINUS;
	}
	EXP_MINUS:
	{
		single: UNIT;
		plus: add UNIT;
		minus: sub UNIT;
	}
	UNIT:
	{
		id: ID;
		call: CALL;
		const: CONST;
		complex: left EXP_RIGHT right;
	}
	CONST:
	{
		integer: integer;
		real: realC;
	}
	ID:
	{
		array:  id squareL integer squareR;
		single: id;
	}
	CALL:
	{
		call_1: FUNCT_NAME left EXP_RIGHT right; 
		call_2: FUNCT_NAME left EXP_RIGHT comma EXP_RIGHT right; 
	}
	FUNCT_NAME:
	{
		id: id;
		sin: sin;
		cos: cos;
		exp: exp;
		ln: ln;
		log: log;
		sqrt: sqrt;
		pow: pow;
	}
	
}
