%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;

    void yyerror(const char* s);
%}

%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA NUMBER IDENTIFIER AND OR
%start prog_start

%%
prog_start: functions {printf("prog_start->functions\n");}
          | %empty {printf("prog_start->epsilon\n");}
          ;
functions: %empty {printf("functions->epsilon\n");}
         | function functions {printf("functions-> function functions\n");}
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
statement: declaration SEMICOLON {printf("statement->declaration SEMICOLON\n");}
         | assignment SEMICOLON {printf("statement->assignment SEMICOLON\n");}
         | function_call SEMICOLON {printf("statement->function_call SEMICOLON\n");}
         | if_start {printf("statement->if_start\n");}
         | until_loop {printf("statement->until_loop\n");}
         | BREAK SEMICOLON {printf("statement-> BREAK SEMICOLON\n");}
         | WRITE BEGIN_PARAM equations END_PARAM SEMICOLON {printf("statement-> WRITE BEGIN_PARAM equations END_PARAM SEMICOLON");}
         | READ BEGIN_PARAM END_PARAM SEMICOLON {printf("statement-> READ BEGIN_PARAM ENDPARAM SEMICOLON\n");}
         | CONTINUE SEMICOLON {printf("statement-> CONTINUE SEMICOLON\n");}
         | RETURN equations SEMICOLON {printf("statement-> RETURN equations SEMICOLON\n");}
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
     ;
term: factor termp {printf("term->factor termp\n");}
    ;

termp: mulop factor termp {printf("termp->mulop factor termp\n");}
     | %empty {printf("termp ->epsilon\n");}
     ;
mulop: MULTIPLY {printf("mulop->MULTIPLY\n");}
     | DIVISION {printf("mulop->DIVISION\n");}
     | MOD {printf("mulop->MOD\n");}
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

if_start: IF BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY branch_check {printf("if_start->IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY branch_check\n");}
        ;

if_check: fin if_checkp {printf("if_check->fin if_checkp\n");}
        | L_PAREN fin R_PAREN if_checkp {printf("if_check-> L_PAREN fin R_PAREN if_checkp\n");}
        ;

if_checkp: %empty {printf("if_checkp->epsilon\n");}
         | boolop fin if_checkp {printf("if_checkp->boolep fin if_checkp\n");}
         ;

boolop: AND {printf("boolop->AND\n");}
      | OR {printf("boolop->OR\n");}

fin: finp compare {printf("fin->finp compare\n");}
   | L_PAREN finp R_PAREN compare {printf("fin->L_PAREN finp R_PAREN compare\n");}
   ;

compare: %empty {printf("empty->epsilon\n");}
       | compop finp compare {printf("compare->compop finp compare\n");}
       ;

finp: INTEGER {printf("finp->INTEGER\n");}
    | IDENTIFIER {printf("finp->IDENTIFIER\n");}
    | function_call {printf("finp->function_call\n");}
    ;

compop: EQ {printf("compop->EQ\n");}
      | GTE {printf("compop->GTE\n");}
      | LTE {printf("compop->LTE\n");}
      | NEQ {printf("compop->NEQ\n");}
      | GT {printf("compop->GT\n");}
      | LT {printf("compop->LT\n");}
      ;

branch_check: %empty {printf("branch_check->epsilon\n");}
            | ELSE_IF BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY else_check {printf("branch_check->ELSE_IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
            | else_check {printf("branch_check->else_check\n");}
            ;

else_check: %empty {printf("else_check->epsilon\n");}
          | ELSE BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY else_check {printf("else_check->ELSE BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
          ;

until_loop: WHILE BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY {printf("until_loop->WHILE BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY\n");}
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
    fprintf(stderr, "Parse error: %s.[insert error message here]\n", s);
    exit(1);
}