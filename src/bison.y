%{
    #include <stdio>
%}
%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISON MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA NUMBER IDENTIFIER
%start prog_start

%%
prog_start: %empty {printf("prog_start->epsilon\n");}
          | functions {printf("prog_start->epsilon\n");}
          ;
functions: %empty {printf("functions->epsilon\n");}
         | function functions {printf("functions-> function functions\n");}
         ;
function: INTEGER IDENT BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {printf("function->INTEGER IDENT BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");} 
        ;
arguments: argument {printf("arguments->arugment\n");}
         | argument COMMA arguments {printf("arguments ->argument arguments\n");}
         ;
argument: %empty {printf("argument->epsilon\n");}
        | INTEGER IDENT {printf("argument-> INTEGER IDENT\n");}
        ;
statements: %empty {printf("statements->epsilon\n");}
          | statement SEMICOLON statements {printf("statements->statement SEMICOLON statements\n");}
          ;
statement: declaration {printf("statement->declaration\n");}
         | assignment {printf("statement->assignement\n");}
         | function_call {printf("statement->function_call\n");}
         ;
declaration: INTEGER IDENT {printf("declaration-> INTEGER IDENT\n");}
           | INTEGER IDENT ASSIGN equations {printf("declaration ->INTEGER IDENT ASSIGN equations\n");}
           ;
assignemnt: IDENT ASSIGN equations {printf("IDENT ASSIGN equations\n");}
          ;

equations: equations addop term {printf("equations->equations addop term\n");}
         | term {printf("equations->term\n");}
         ;
addop: ADD {printf("addop ->ADD\n");}
     | SUBTRACT {printf("addop->SUBTRACT\n");}
     ;
term: term mulop factor {printf("term->term mulop factor\n");}
    | factor {printf("term ->factor\n");}
    ;
mulop: MULTIPLY {printf("mulop->MULTIPLY\n");}
     | DIVISION {printf("mulop->DIVISION\n");}
     | MOD {printf("mulop->MOD\n");}
     ;
factor: LPR equations RPR {printf("factor->LPR equations RPR");}
      | INTEGER {printf("factor ->INT\n");}
      | IDENT {printf("factor->IDENT\n");}
      | function_call {printf("factor->function_call\n");}
      ;


function_call: IDENT BEGIN_PARAM params END_PARAM {printf("function_call->IDENT BEGIN_PARAM params END_PARAM\n");}
             ;
params: %empty {printf("params->epsilon\n");}
      | param {printf("params->param\n");}
      | param COMMA params {printf("params-> param COMMA params\n");}
      ;
param: IDENT {printf("param->IDENT\n");}
     | INTEGER {printf("param->INTEGER\n");}
     ;
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