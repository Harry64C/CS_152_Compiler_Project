%{
//c code here
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
(DIGIT)+ { printf( "NUMBER: %s\n", yytext); }
(LETTER)+ { printf( "WORD: %s\n", yytext); }

"inum" { print( "INTEGER" ); }
"arr{"(DIGIT)*"}" { print( "ARRAY" ); }
"~" { print( "ASSIGN" ); }
"plus" { print ( "ADD" ); }
"minus" { print( "SUBTRACT" ); }
"mult" { print( "MULTIPLY" ); }
"divi" { print( "DIVISION" ); }
"mod" { print( "MOD" ); }

"eq" { print( "EQ" ); }
"gte" { print( "GTE" ); }
"lte" { print( "LTE" ); }
"dne" { print( "NEQ" ); }
"gt" { print( "GT" ); }
"lt" { print( "LT" ); }

"[" { print( "BEGIN_BODY" ); }
"]" { print( "END_BODY" ); }
"{" { print( "BEGIN_PARAM" ); }
"}" { print( "END_PARAM" ); }

"check" { print( "IF" ); }
"then" { print( "ELSE" ); }
"or" { print( "ELSE_IF" ); }
"until" { print( "WHILE" ); }
"stop" { print( "BREAK" ); }
"go" { print( "CONTINUE" ); }
"inp" { print( "READ" ); }
"outp" { print( "WRITE" ); }

";" { print( "SEMICOLON" ); }
"#" { print( "COMMENT" ); }
%%
int main(void){
  printf("CTRL+D to quit\n");
  yylex();
}
