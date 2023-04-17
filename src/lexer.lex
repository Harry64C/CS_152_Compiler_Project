%{
#include <stdio.h>
int col_num = 1;
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
\n     {lineNumber++;col_num = 1;}
"inum" { printf( "INTEGER\n"); col_num++;}
"arr" { printf( "ARRAY \n"); col_num++;}
"func" { printf("FUNCTION\n");col_num++;}
"~" { printf( "ASSIGN \n" ); col_num++;}
"plus" { printf ( "ADD \n" ); col_num++;}
"minus" { printf( "SUBTRACT \n"); col_num++;}
"mult" { printf( "MULTIPLY \n" );col_num++; }
"divi" { printf( "DIVISION \n" ); col_num++;}
"mod" { printf( "MOD \n" );col_num++; }

"eq" { printf( "EQ \n" ); col_num++;}
"gte" { printf( "GTE \n" );col_num++; }
"lte" { printf( "LTE \n" ); col_num++;}
"dne" { printf( "NEQ \n" ); col_num++;}
"gt" { printf( "GT \n" );col_num++; }
"lt" { printf( "LT \n" );col_num++; }

"[" { printf( "BEGIN_BODY \n" ); col_num++;}
"]" { printf( "END_BODY \n" ); col_num++;}
"{" { printf( "BEGIN_PARAM \n" );col_num++; }
"}" { printf( "END_PARAM \n" ); col_num++;}
"(" { printf( "L_PAREN \n"); col_num++;}
")" { printf( "R_PAREN \n"); col_num++;}

"check" { printf( "IF \n" ); col_num++;}
"then" { printf( "ELSE \n" ); col_num++;}
"or" { printf( "ELSE_IF \n" ); col_num++;}
"until" { printf( "WHILE \n" ); col_num++;}
"stop" { printf( "BREAK \n" ); col_num++;}
"go" { printf( "CONTINUE \n" );col_num++; }
"inp" { printf( "READ \n" ); col_num++;}
"outp" { printf( "WRITE \n" ); col_num++;}
"return" {printf("RETURN \n");col_num++;}
";" { printf( "SEMICOLON \n" ); col_num++;}
"," { printf( "COMMA \n");col_num++;}
"#".* {printf("Comment on line %d\n", lineNumber);}
{DIGIT}+ { printf( "NUMBER: %s\n", yytext); col_num += 1;}
{LETTER}+ { printf( "WORD: %s\n", yytext); col_num+= 1;}
[0-9]+[a-zA-Z][0-9a-zA-Z]* {printf("**Error. Invalid identifier '%s' on line '%d' column '%d'\n", yytext, lineNumber, col_num);}
. { printf("**Error. Unidentified token '%s' on line '%d' column '%d'\n", yytext, lineNumber, col_num);}

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

