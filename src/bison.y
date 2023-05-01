%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern int lineNumber;
    extern int col_num;
    extern char* yytext;

    void yyerror(const char* s);
%}

%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA NUMBER IDENTIFIER AND OR
%start prog_start

%%
prog_start: functions {printf("prog_start->functions\n");}
          ;
functions: function functions {printf("functions-> function functions\n");}
         | %empty {printf("functions->epsilon\n");}
         ;
function: INTEGER FUNCTION IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {printf("function->INTEGER FUNCTION IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");} 
        ;
arguments: argument {printf("arguments->arugment\n");}
         | argument COMMA arguments {printf("arguments ->argument arguments\n");}
         ;
argument: %empty {printf("argument->epsilon\n");}
        | INTEGER IDENTIFIER {printf("argument-> INTEGER IDENTIFIER\n");}
        ;
statements: %empty {printf("statements->epsilon\n");}
          | statement SEMICOLON statements {printf("statements->statement SEMICOLON statements\n");}
          ;
statement: declaration {printf("statement->declaration\n");}
         | assignment {printf("statement->assignment\n");}
         | function_call  {printf("statement->function_call\n");}
         | if_start {printf("statement->if_start\n");}
         | until_loop {printf("statement->until_loop\n");}
         | BREAK  {printf("statement-> BREAK\n");}
         | WRITE BEGIN_PARAM equations END_PARAM {printf("statement-> WRITE BEGIN_PARAM equations END_PARAM\n");}
         | READ BEGIN_PARAM END_PARAM {printf("statement-> READ BEGIN_PARAM ENDPARAM \n");}
         | CONTINUE {printf("statement-> CONTINUE\n");}
         | RETURN equations {printf("statement-> RETURN equations \n");}
         ;
declaration: INTEGER IDENTIFIER {printf("declaration-> INTEGER IDENTIFIER\n");}
           | INTEGER IDENTIFIER ASSIGN equations {printf("declaration ->INTEGER IDENTIFIER ASSIGN equations\n");}
           | arraycall {printf("declaration -> arraycall\n");}
           ; 

assignment: IDENTIFIER ASSIGN equations {printf("IDENTIFIER ASSIGN equations\n");}
          | arraycall ASSIGN equations {printf("arraycall ASSIGN equations\n");}
          ;

equations: term equationsp {printf("equations->term equationsp\n");}
         ;
equationsp: addop term equationsp {printf("equationsp->addop term equationsp\n");}
	    | %empty {printf("equationsp->epsilon\n");}
	    ;
addop: ADD {printf("addop -> ADD\n");}
     | SUBTRACT {printf("addop->SUBTRACT\n");}
     | EQ {printf("compop->EQ\n");}
     | GTE {printf("compop->GTE\n");}
     | LTE {printf("compop->LTE\n");}
     | NEQ {printf("compop->NEQ\n");}
     | GT {printf("compop->GT\n");}
     | LT {printf("compop->LT\n");}
     ;
term: factor termp {printf("term->factor termp\n");}
    ;

termp: mulop factor termp {printf("termp->mulop factor termp\n");}
     | %empty {printf("termp ->epsilon\n");}
     ;
mulop: MULTIPLY {printf("mulop->MULTIPLY\n");}
     | DIVISION {printf("mulop->DIVISION\n");}
     | MOD {printf("mulop->MOD\n");}
     | AND {printf("mulop -> AND\n");}
     | OR {printf("mulop->OR\n");}
     ;
factor: L_PAREN equations R_PAREN {printf("factor->L_PAREN equations R_PAREN");}
      | INTEGER {printf("factor ->INT\n");}
      | IDENTIFIER {printf("factor->IDENTIFIER\n");}
      | NUMBER {printf("factor->NUMBER\n");}
      | arraycall {printf("factor->arraycall\n");}
      | function_call {printf("factor->function_call\n");}
      ;
arraycall: ARRAY L_PAREN INTEGER R_PAREN {printf("arraycall->ARRAY LPAREN INTEGER R_PAREN\n");}
         | ARRAY L_PAREN R_PAREN {printf("arraycall->ARRAY LPAREN R_PAREN\n");}
         ;

function_call: IDENTIFIER BEGIN_PARAM params END_PARAM {printf("function_call->IDENTIFIER BEGIN_PARAM params END_PARAM\n");}
             ;
params: %empty {printf("params->epsilon\n");}
      | param {printf("params->param\n");}
      | param COMMA params {printf("params-> param COMMA params\n");}
      ;
param: IDENTIFIER {printf("param->IDENTIFIER\n");}
     | INTEGER {printf("param->INTEGER\n");}
     ;

if_start: IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY branch_check {printf("if_start->IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY branch_check\n");}
        ;


branch_check: ELSE_IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY else_check {printf("branch_check->ELSE_IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
            | else_check {printf("branch_check->else_check\n");}
            ;

else_check: %empty {printf("else_check->epsilon\n");}
          | ELSE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY else_check {printf("else_check->ELSE BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
          ;

until_loop: WHILE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY {printf("until_loop->WHILE BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY\n");}
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
    printf("Parse error: %s on line %d column %d, error %s\n", yytext, lineNumber, col_num, s   );
    exit(1);
}