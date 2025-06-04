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
	enters: enters: '\n'+;
	format:
	{
		spaces: ' '+;
		tab: '\t';
	}
	division:
	{
		semicolon:';';
		colon:':';
		dot: '.';
	}
};