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
        real(+1):  <integer>'.'<num>+((e|E)<integer>)?;
    }
	reserved(+5):
	{
		funct;
		manifold;
		function;
		manif;
		if;
		else;					
	};
	function1(+5):
	{
		sin;
		cos;
		exp;
		ln;
		pow;
		log;
		sqrt;
	}
	function2(+5):
	{
		sin;
		cos;
		exp;
		ln;
		pow;
		log;
		sqrt;
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
	RegSymbol:
	{
		minus: '-';
		multi: '*';        //zero or more
		plus: '+';        //one or more
		division: '?';    //zero or one, not wildcard
		or: '|';
	}		
};

grammar: MANIF:
{
	
	MANIF: MANIFWORD squareL integer squareR left MANIFPARAS right MANIFBODY;
	MANIFBODY:
	{

	}
	MANIFPARAS:
	{
		single: MANIFPARA;
		multi: MANIFPARAS comma MANIFPARA;
	}
    MANIFWORD: 
    {
        manifold: manifold;
        manif: manif;
    }
	
}
