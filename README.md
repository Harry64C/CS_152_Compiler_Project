# CS 152 Compiler Project


Our language is one that is similar to c++ but is easier for writers to learn. 

The language is called A++ but the file extension name is app. 

Rules: 
1. In-line comments must start with # and multiline comments must begin with /# and end with #/
2. Variable names cannot start with a number or contain special characters. 
3. Brackets are used instead of curly braces in c++. Additionally, curly braces are used instead of parenthesis. 

|	Language Features |	Code example |
|	----------------- | ------------ |
|	Scalar Integer Var	|	inum x; inum y; inum avg;	|
|	1-D Int Array	|	inum arr{3}; inum a{20}	|
|	Assignment Statement	|	inum x ~ 1; inum x ~ y;	|
|	Arithmetic Add	|	x plus 1	|
|	Arithmetic Subtract	|	x minus 1	|
|	Arithmetic Multiply	|	x mult 1	|
|	Arithmetic Divide	|	x divi 1	|
|	Arithmetic Modulus	|	x mod 1	|
|	Relation “<”	|	x lt 1	|
|	Relation ">"	|	x gt 1	|
|	Relation "=="	|	x eq 1	|
|	Relation "!="	|	x dne 1	|
|	Relation "<="	|	x lte 1	|
|	Relation ">="	|	x gte 1	|
|	while	|	until{x gte 1}[]	|
|	continue	|	go;	|
|	break	|	stop;	|
|	if	|	check {"condition"}[...]	|
|	else if	|	or {"condition"}[...]	|
|	else	|	then[...] |
|	cin	|	inum input = system.inp{}	|
|	cout	|	outp{output}	|
|	Comments	|	#	|
|	Return functions	|	inum foo{ } [...]	|
|	Void functions	|	noreturn foo{ } [...]	|

Token Table: 


| SYMBOL            |     TOKEN    |
|	----------------- | ------------ |
| inum | INTEGER |
| arr{} | ARRAY |
| ~ | ASSIGN |
| plus | ADD |
| minus | SUBTRACT |
| mult | MULTIPLY |
| divi | DIVISION |
| mod | MOD |
| eq | EQ |
| gte | GTE |
| lte | LTE |
| dne | NEQ |
| gt | GT |
| lt | LT |
| [ | BEGIN_BODY |
| ] | END_BODY |
| { | BEGIN_PARAM |
| } | END_PARAM |
| check | IF |
| then | ELSE |
| or | ELSE_IF |
| until | WHILE |
| stop | BREAK |
| go | CONTINUE |
| inp | READ | 
| outp | WRITE |
| ; | SEMICOLON |
| # | COMMENT |
