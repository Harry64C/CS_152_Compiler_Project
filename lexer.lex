%{
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
"inum" { printf( "INTEGER" ); }
"arr{{DIGIT}*}" { printf( "ARRAY" ); }
"~" { printf( "ASSIGN" ); }
"plus" { printf ( "ADD" ); }
"minus" { printf( "SUBTRACT" ); }
"mult" { printf( "MULTIPLY" ); }
"divi" { printf( "DIVISION" ); }
"mod" { printf( "MOD" ); }

"eq" { printf( "EQ" ); }
"gte" { printf( "GTE" ); }
"lte" { printf( "LTE" ); }
"dne" { printf( "NEQ" ); }
"gt" { printf( "GT" ); }
"lt" { printf( "LT" ); }

"[" { printf( "BEGIN_BODY" ); }
"]" { printf( "END_BODY" ); }
"{" { printf( "BEGIN_PARAM" ); }
"}" { printf( "END_PARAM" ); }

"check" { printf( "IF" ); }
"then" { printf( "ELSE" ); }
"or" { printf( "ELSE_IF" ); }
"until" { printf( "WHILE" ); }
"stop" { printf( "BREAK" ); }
"go" { printf( "CONTINUE" ); }
"inp" { printf( "READ" ); }
"outp" { printf( "WRITE" ); }

";" { printf( "SEMICOLON" ); }
"#" { printf( "COMMENT" ); }
{DIGIT}+ { printf( "NUMBER: %s\n", yytext); }
{LETTER}+ { printf( "WORD: %s\n", yytext); }

%%
int main(void){
  printf("CTRL+D to quit\n");
  yylex();
}
