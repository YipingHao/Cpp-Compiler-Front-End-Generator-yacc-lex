lexical:{
	void:
	{
		num: [0-9];
        letter: [a-z]|[A-Z];
	}
	identifier: identifier(+1): ([a-z]|[A-Z]|_)<idC>+;
	number: 
    {
        integer(+3): <sign><num>+;
        real(+1):  <integer>'.'<num>+((e|E)<integer>)?;
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
		range: '-';
		star: '*';        //zero or more
		plus: '+';        //one or more
		question: '?';    //zero or one, not wildcard
		or: '|';
	}		
};