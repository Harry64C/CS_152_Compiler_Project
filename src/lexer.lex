%option noyywrap
%{
   #include<string.h>
    #include <stdio.h>
    #include "y.tab.h" 
    #define YY_DECL int yylex()
    int currLine = 1, currPos = 1;
   
    extern char *identToken;
    extern int numberToken;
    int lineNumber = 1;
    int col_num = 1;
%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
" "    {col_num +=1;}
"   "  {col_num +=4;}
\t     {col_num+=4;}
\n     {lineNumber++;col_num = 1;}
"."    { return DOT; col_num +=1; }
"inum" { return INTEGER; col_num+=4;}
"arr" { return ARRAY; col_num+=3;}
"funct" { return FUNCTION; col_num+=5;}
"~" { return ASSIGN; col_num+=1;}
"plus" { return ADD; col_num+=4;}
"minus" { return SUBTRACT; col_num+=5;}
"mult" { return MULTIPLY; col_num+=4; }
"divi" { return DIVISION; col_num+=4;}
"mod" { return MOD; col_num+=3; }

"eq" { return EQ; col_num+=2;}
"gte" { return GTE; col_num+=3; }
"lte" { return LTE; col_num+=3;}
"dne" { return NEQ; col_num+=3;}
"gt" { return GT; col_num+=2; }
"lt" { return LT; col_num+=2; }
"AND" { return AND; col_num+=3;}
"OR" { return OR; col_num+=2; }

"[" { return BEGIN_BODY; col_num++;}
"]" { return END_BODY; col_num+=1;}
"{" { return BEGIN_PARAM; col_num+=1; }
"}" { return END_PARAM; col_num+=1;}
"(" { return L_PAREN ; col_num+=1;}
")" { return R_PAREN ; col_num+=1;}

"check" { return IF ; col_num+=5;}
"then" { return ELSE ; col_num+=4;}
"or" { return ELSE_IF ; col_num+=2;}
"until" { return WHILE ; col_num+=5;}
"stop" { return BREAK ; col_num+=4;}
"go" { return CONTINUE ;col_num+=2; }
"inp" { return READ ; col_num+=3;}
"outp" { return WRITE ; col_num+=4;}
"return" {return RETURN ; col_num+=6;}
";" { return SEMICOLON ; col_num++;}
"," { return COMMA ; col_num++;}
"#".* {}

{DIGIT}+ { 
   col_num += yyleng;
   char * token = new char[yyleng];
   strcpy(token, yytext);
   yylval.op_val = token;
   numberToken = atoi(yytext); 
   return NUMBER; 
}
{LETTER}+ { currPos += yyleng;
   char * token = new char[yyleng];
   strcpy(token, yytext);
   yylval.op_val = token;
   col_num+= yyleng;
   identToken = yytext; 
   return IDENTIFIER; 
}
({LETTER})|({LETTER}({LETTER}|{DIGIT}|"_")*({LETTER}|{DIGIT})) {
   currPos += yyleng;
   char* token = new char[yyleng];
   strcpy(token, yytext);
   yylval.op_val = token;
   col_num+=yyleng;
   identToken = yytext; 
   return IDENTIFIER;
}
[_][_0-9a-zA-Z]* {printf("**Error. IDENTIFIER: '%s' on line '%d' column '%d'. Identifiers cannot start with '_' \n", yytext, lineNumber, col_num); col_num += yyleng;}
[a-zA-Z]+[_0-9a-zA-Z]*[_] {printf("**Error. IDENTIFIER: '%s' on line '%d' column '%d'. Identifiers cannot end in '_' \n", yytext, lineNumber, col_num);col_num += yyleng;}
[0-9]+[a-zA-Z][0-9a-zA-Z]* {printf("**Error. IDENTIFIER: '%s' on line '%d' column '%d'. Identifiers cannot start with a number\n", yytext, lineNumber, col_num);col_num += yyleng;}
. { printf("**Error. Unidentified token '%s' on line '%d' column '%d'\n", yytext, lineNumber, col_num);col_num += yyleng;}

%%


