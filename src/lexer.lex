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


" "    {col_num +=1;}
"   "  {col_num +=4;}
\t     {}
\n     {lineNumber++;col_num = 1;}
"inum" { printf( "INTEGER\n"); col_num+=4;}
"arr" { printf( "ARRAY \n"); col_num+=3;}
"func" { printf("FUNCTION\n");col_num+=4;}
"~" { printf( "ASSIGN \n" ); col_num+=1;}
"plus" { printf ( "ADD \n" ); col_num+=4;}
"minus" { printf( "SUBTRACT \n"); col_num+=5;}
"mult" { printf( "MULTIPLY \n" );col_num+=4; }
"divi" { printf( "DIVISION \n" ); col_num+=4;}
"mod" { printf( "MOD \n" );col_num+=3; }

"eq" { printf( "EQ \n" ); col_num+=2;}
"gte" { printf( "GTE \n" );col_num+=3; }
"lte" { printf( "LTE \n" ); col_num+=3;}
"dne" { printf( "NEQ \n" ); col_num+=3;}
"gt" { printf( "GT \n" );col_num+=2; }
"lt" { printf( "LT \n" );col_num+=2; }

"[" { printf( "BEGIN_BODY \n" ); col_num++;}
"]" { printf( "END_BODY \n" ); col_num+=1;}
"{" { printf( "BEGIN_PARAM \n" );col_num+=1; }
"}" { printf( "END_PARAM \n" ); col_num+=1;}
"(" { printf( "L_PAREN \n"); col_num+=1;}
")" { printf( "R_PAREN \n"); col_num+=1;}

"check" { printf( "IF \n" ); col_num+=5;}
"then" { printf( "ELSE \n" ); col_num+=4;}
"or" { printf( "ELSE_IF \n" ); col_num+=2;}
"until" { printf( "WHILE \n" ); col_num+=5;}
"stop" { printf( "BREAK \n" ); col_num+=4;}
"go" { printf( "CONTINUE \n" );col_num+=2; }
"inp" { printf( "READ \n" ); col_num+=3;}
"outp" { printf( "WRITE \n" ); col_num+=4;}
"return" {printf("RETURN \n");col_num+=6;}
";" { printf( "SEMICOLON \n" ); col_num++;}
"," { printf( "COMMA \n");col_num++;}
"#".* {}
{DIGIT}+ { printf( "NUMBER: %s\n", yytext); col_num += yyleng;}
{LETTER}+ { printf( "WORD: %s\n", yytext); col_num+= yyleng;}
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

