%{
    #include <stdio>
%}

%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA NUMBER IDENTIFIER AND OR
%start prog_start

%%
prog_start: %empty {printf("prog_start->epsilon\n");}
          | functions {printf("prog_start->functions\n");}
          ;
functions: %empty {printf("functions->epsilon\n");}
         | function functions {printf("functions-> function functions\n");}
         ;
function: INTEGER IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {printf("function->INTEGER IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");} 
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
         | function_call {printf("statement->function_call\n");}
         ;
declaration: INTEGER IDENTIFIER {printf("declaration-> INTEGER IDENTIFIER\n");}
           | INTEGER IDENTIFIER ASSIGN equations {printf("declaration ->INTEGER IDENTIFIER ASSIGN equations\n");}
           ;

assignment: IDENTIFIER ASSIGN equations {printf("IDENTIFIER ASSIGN equations\n");}
          ;

equations: equations addop term {printf("equations->equations addop term\n");}
         | term {printf("equations->term\n");}
         ;
addop: ADD {printf("addop -> ADD\n");}
     | SUBTRACT {printf("addop->SUBTRACT\n");}
     ;
term: term mulop factor {printf("term->term mulop factor\n");}
    | factor {printf("term ->factor\n");}
    ;
mulop: MULTIPLY {printf("mulop->MULTIPLY\n");}
     | DIVISION {printf("mulop->DIVISION\n");}
     | MOD {printf("mulop->MOD\n");}
     ;
factor: L_PAREN equations R_PAREN {printf("factor->L_PAREN equations R_PAREN");}
      | INTEGER {printf("factor ->INT\n");}
      | IDENTIFIER {printf("factor->IDENTIFIER\n");}
      | function_call {printf("factor->function_call\n");}
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
    | IDENT {printf("finp->IDENT\n");}
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
    yyparse();
    

}