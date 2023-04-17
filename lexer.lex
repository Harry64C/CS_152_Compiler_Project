%{
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]
 

%%
" "    {}
\t     {}   
"inum" { printf( "INTEGER\n"); }
"arr" { printf( "ARRAY \n"); }
"func" { printf("FUNCTION\n");}
"~" { printf( "ASSIGN \n" ); }
"plus" { printf ( "ADD \n" ); }
"minus" { printf( "SUBTRACT \n"); }
"mult" { printf( "MULTIPLY \n" ); }
"divi" { printf( "DIVISION \n" ); }
"mod" { printf( "MOD \n" ); }

"eq" { printf( "EQ \n" ); }
"gte" { printf( "GTE \n" ); }
"lte" { printf( "LTE \n" ); }
"dne" { printf( "NEQ \n" ); }
"gt" { printf( "GT \n" ); }
"lt" { printf( "LT \n" ); }

"[" { printf( "BEGIN_BODY \n" ); }
"]" { printf( "END_BODY \n" ); }
"{" { printf( "BEGIN_PARAM \n" ); }
"}" { printf( "END_PARAM \n" ); }

"check" { printf( "IF \n" ); }
"then" { printf( "ELSE \n" ); }
"or" { printf( "ELSE_IF \n" ); }
"until" { printf( "WHILE \n" ); }
"stop" { printf( "BREAK \n" ); }
"go" { printf( "CONTINUE \n" ); }
"inp" { printf( "READ \n" ); }
"outp" { printf( "WRITE \n" ); }

";" { printf( "SEMICOLON \n" ); }
"#" { printf( "COMMENT \n" ); }
{DIGIT}+ { printf( "NUMBER: %s\n", yytext); }
{LETTER}+ { printf( "WORD: %s\n", yytext); }
. { printf("**Error. Unidentified token '%s' \n", yytext);}

%%
int main(arc, argv) int arc; char** argv;
{
    argv++;
    argc--;
    if(argc > 0){
        yyin = fopen( argv[0], "r");
    }else{
        yyin = stdin;
    }
    yylex();
}

