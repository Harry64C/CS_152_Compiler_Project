%{
    #include <stdio>
%}
%token INT SEMICOLON IDENT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM

%%
prog_start: %empty {printf("prog_start->epsilon\n");}
          | functions {printf("prog_start->epsilon\n");}
          ;
functions: %empty {printf("functions->epsilon\n");}
         | function functions {printf("functions-> function functions\n");}
         ;
function: INT IDENT BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {printf("function->INT IDENT BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");} 
        ;
arguments: argument {printf("arguments->arugment\n");}
         | argument COMMA arguments {printf("arguments ->argument arguments\n");}
         ;
argument: %empty {printf("argument->epsilon\n");}
        | INT IDENT {printf("argument-> INT IDENT\n");}
        ;
statements: %empty {printf("statements->epsilon\n");}
          | statement SEMICOLON statements {printf("statements->statement SEMICOLON statements\n");}
          ;
statement: declaration
         | assignment
         | function_call
         ;
declaration: INT IDENT
           | INT IDENT ASSIGN equations
           ;
assignemnt: IDENT ASSIGN equations
          ;
equations: LPR equations RPR operator equations 
         | equation
         | LPR equations RPR
         | equations operator equations
         ;
equation: INT operator INT
        | INT operator IDENT
        | IDENT operator INT
        | IDENT operator IDENT
        | IDENT
        | INT
        | function_call
        ;
function_call: IDENT BEGIN_PARAM params END_PARAM
             ;
params: %empty
      | param
      | param COMMA params
      ;
param: IDENT
     | INT
     ;
%%
