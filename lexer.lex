%{
//c code here
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
inum { printf( "INT %s\n", yytext ); }
~ { printf( "ASSIGN %s\n", yytext ); }
plus { printf( "ADD %s\n", yytext ); }
minus { printf( "SUBTRACT %s\n", yytext ); }
mult { printf( "MULTIPLY %s\n", yytext ); }
divi { printf( "DIVISION %s\n", yytext ); }
mod { printf( "MOD %s\n", yytext ); }
eq { printf( "EQ %s\n", yytext ); }
dne { printf( "NEQ %s\n", yytext); }
gt { printf( "GT %s\n", yytext); }
lt { printf( "LT %s\n", yytext); }
gte { printf( "GTE %s\n", yytext}; }

(DIGIT)+ { printf( "NUMBER: %s\n", yytext); }
(LETTER)+ { printf( "WORD: %s\n", yytext); }
%%
int main(void){
  printf("CTRL+D to quit\n");
  yylex();
}
