%{
#include <stdio.h>
%}

DIGIT [0-9]
LETTER [a-zA-Z]
INVALIDI {0-9a-zA-z}

%%
%{
int lineNumber = 1;
%}


" "    {}
\t     {}
\n     {lineNumber++;}
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
"(" { printf( "L_PAREN \n"); }
")" { printf( "R_PAREN \n"); }

"check" { printf( "IF \n" ); }
"then" { printf( "ELSE \n" ); }
"or" { printf( "ELSE_IF \n" ); }
"until" { printf( "WHILE \n" ); }
"stop" { printf( "BREAK \n" ); }
"go" { printf( "CONTINUE \n" ); }
"inp" { printf( "READ \n" ); }
"outp" { printf( "WRITE \n" ); }
"return" {printf("RETURN \n");}
";" { printf( "SEMICOLON \n" ); }
"," { printf( "COMMA \n");}
"#".* {printf("Comment on line %d\n", lineNumber);}
{DIGIT}+ { printf( "NUMBER: %s\n", yytext); }
{LETTER}+ { printf( "WORD: %s\n", yytext); }
[0-9]+[a-zA-Z][0-9a-zA-Z]* {printf("**Error. Invalid identifier '%s' on line '%d'\n", yytext, lineNumber);}
. { printf("**Error. Unidentified token '%s' on line '%d'\n", yytext, lineNumber);}

%%
int main(int argc, char** argv)
{
    int i = 0;
    argv++;
    argc--;
    if(argc > 0){
        yyin = fopen( argv[0], "r");
    }else{
        //printf("%d \n", i++);
        yyin = stdin;
    }
    yylex();
    
    //printf("End of program");
}

