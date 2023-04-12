%{
//c code here
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
"inum" { print( "INT" ); }
"~" { print( "ASSIGN" ); }
"plus" { print ( "ADD" ); }
"minus" { print( "SUBTRACT" ); }
"mult" { print( "MULTIPLY" ); }
(DIGIT)+ { printf( "NUMBER: %s\n", yytext); }
(LETTER)+ { printf( "WORD: %s\n", yytext); }
%%
int main(void){
  printf("CTRL+D to quit\n");
  yylex();
}