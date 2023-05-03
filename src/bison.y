%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern int lineNumber;
    extern int col_num;
    extern char* yytext;
    #define YYERROR_VERBOSE 1

    void yyerror(const char* s);
%}

%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA NUMBER IDENTIFIER AND OR DOT
%start prog_start

%%
prog_start: functions {printf("prog_start -> functions\n");}
          ;
functions: function functions {printf("functions -> function functions\n");}
         | %empty {printf("functions -> epsilon\n");}
         ;
function: INTEGER FUNCTION IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {printf("function -> INTEGER FUNCTION IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");} 
        ;
arguments: argument {printf("arguments -> arugment\n");}
         | argument COMMA arguments {printf("arguments -> argument arguments\n");}
         ;
argument: %empty {printf("argument -> epsilon\n");}
        | INTEGER IDENTIFIER {printf("argument -> INTEGER IDENTIFIER\n");}
        ;
statements: %empty {printf("statements -> epsilon\n");}
          | statement SEMICOLON statements {printf("statements -> statement SEMICOLON statements\n");}
          | nonsemicolonstatement statements{printf("statements -> nonsemicolonstatement statements\n");}
          | error SEMICOLON {}
          ;
statement: declaration {printf("statement -> declaration\n");}
         | assignment {printf("statement -> assignment\n");}
         | function_call  {printf("statement -> function_call\n");}
         | BREAK  {printf("statement -> BREAK\n");}
         | WRITE BEGIN_PARAM equations END_PARAM {printf("statement -> WRITE BEGIN_PARAM equations END_PARAM\n");}
         | CONTINUE {printf("statement -> CONTINUE\n");}
         | RETURN equations {printf("statement -> RETURN equations \n");}
         ;
nonsemicolonstatement: if_start {printf("nonsemicolonstatement -> if_start\n");}
         | until_loop {printf("nonsemicolonstatement -> until_loop\n");}
         ;
         
declaration: INTEGER IDENTIFIER {printf("declaration-> INTEGER IDENTIFIER\n");}
           | INTEGER IDENTIFIER ASSIGN equations {printf("declaration ->INTEGER IDENTIFIER ASSIGN equations\n");}
           | ARRAY IDENTIFIER BEGIN_PARAM factor END_PARAM {printf("declaration -> ARRAY arraycall\n");}
           | INTEGER IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {printf("declaration-> INTEGER IDENTIFIER ASSIGN READ BEGIN_PARAM ENDPARAM \n");}
           ;

assignment: IDENTIFIER ASSIGN equations {printf("IDENTIFIER ASSIGN equations\n");}
          | function_call ASSIGN equations {printf("arraycall ASSIGN equations\n");}
          | IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {printf("assignment-> IDENTIFIER ASSIGN READ BEGIN_PARAM ENDPARAM \n");}
          
equations: term equationsp {printf("equations -> term equationsp\n");}
         ;
equationsp: addop term equationsp {printf("equationsp -> addop term equationsp\n");}
	    | %empty {printf("equationsp -> epsilon\n");}
	    ;
addop: ADD {printf("addop -> ADD\n");}
     | SUBTRACT {printf("addop -> SUBTRACT\n");}
     | EQ {printf("compop -> EQ\n");}
     | GTE {printf("compop -> GTE\n");}
     | LTE {printf("compop -> LTE\n");}
     | NEQ {printf("compop -> NEQ\n");}
     | GT {printf("compop -> GT\n");}
     | LT {printf("compop -> LT\n");}
     ;
term: factor termp {printf("term -> factor termp\n");}
    ;

termp: mulop factor termp {printf("termp -> mulop factor termp\n");}
     | %empty {printf("termp -> epsilon\n");}
     ;
mulop: MULTIPLY {printf("mulop -> MULTIPLY\n");}
     | DIVISION {printf("mulop -> DIVISION\n");}
     | MOD {printf("mulop -> MOD\n");}
     | AND {printf("mulop -> AND\n");}
     | OR {printf("mulop -> OR\n");}
     ;
     
factor: L_PAREN equations R_PAREN {printf("factor->L_PAREN equations R_PAREN");}
      | INTEGER {printf("factor ->INTEGER\n");}
      | IDENTIFIER {printf("factor->IDENTIFIER\n");}
      | NUMBER {printf("factor->NUMBER\n");}
      | function_call {printf("factor->function_call\n");}
      ;


function_call: IDENTIFIER BEGIN_PARAM params END_PARAM {printf("function_call -> IDENTIFIER BEGIN_PARAM params END_PARAM\n");}
             ;

params: param {printf("params->param\n");}
      | param COMMA params {printf("params-> param COMMA params\n");}
      | %empty {printf("params->epsilon\n");}
      ;

param: IDENTIFIER {printf("param->IDENTIFIER\n");}
     | NUMBER {printf("param->NUMBER\n");}


if_start: IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY branch_check {printf("if_start -> IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY branch_check\n");}
        ;


branch_check: ELSE_IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY else_check {printf("branch_check -> ELSE_IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
            | else_check {printf("branch_check -> else_check\n");}
            ;

else_check: %empty {printf("else_check -> epsilon\n");}
          | ELSE BEGIN_BODY statements END_BODY {printf("else_check -> ELSE BEGIN_BODY statements END_BODY\n");}
          ;

until_loop: WHILE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY {printf("until_loop -> WHILE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY\n");}
          ;

%%
void main(int argc, char** argv) {
    if(argc >= 2){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL)
            yyin = stdin;
    }else{
        yyin = stdin;
    }
    yyparse();
}

void yyerror(const char* s) {
    extern char* yytext;

    printf("Parse Error: %s, on line %d\n", s, lineNumber);
    exit(1);
}
