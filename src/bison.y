%{
    #include <stdio.h>
    #include <string>
    #include <vector>
    #include <string.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern int lineNumber;
    extern int col_num;
    extern char* yytext;
    #define YYERROR_VERBOSE 1
    void yyerror(const char* s);

    struct CodeNode {
        std::string code;
        std::string name;
    };

    enum Type { Integer, Array };

    struct Symbol {
        std::string name;
        Type type;
    };

    struct Function {
        std::string name;
        std::vector<Symbol> declarations;
    };

    std::vector <Function> symbol_table;
    // remember that Bison is a bottom up parser: that it parses leaf nodes first before parsing the parent nodes. So control flow begins at the leaf grammar nodes and propagates up to the parents.
    Function *get_function() {
        int last = symbol_table.size()-1;
        if (last < 0) {
            printf("***Error. Attempt to call get_function with an empty symbol table\n");
            printf("Create a 'Function' object using 'add_function_to_symbol_table' before\n");
            printf("calling 'find' or 'add_variable_to_symbol_table'");
            exit(1);
        }
        return &symbol_table[last];
    }
    
%}

%union {
  char *op_val;
}
%start prog_start
%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM 
%token L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA AND OR DOT NUMBER IDENTIFIER
%type <node> function
%type <node> statement
%type <node> statements

%%

prog_start: functions { // this happens last
    CodeNode* node = $1; // $1 means the leftmost of the rhs of the grammar
    string code = node->code;
    printf("generated code:\n);
    printf("%s\n", code.c_str());
}
          
functions: function functions {
    printf("functions -> function functions\n");
    
    }
         | %empty {
            
            printf("functions -> epsilon\n");
    };
         

function: INTEGER FUNCTION function_ident BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {
            printf("function -> INTEGER FUNCTION function_ident BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");
            string func_name = $2;
    };
        
function_ident: IDENTIFIER {
  // add the function to the symbol table.
  std::string func_name = $1;
  add_function_to_symbol_table(func_name);
  $$ = $1;
  printf("function_ident -> IDENTIFIER\n");
}
arguments: argument {printf("arguments -> arugment\n");}
         | argument COMMA arguments {printf("arguments -> argument arguments\n");}
         ;
argument: %empty {printf("argument -> epsilon\n");}
        | INTEGER IDENTIFIER {printf("argument -> INTEGER IDENTIFIER\n");}
        ;

statements: %empty {
    printf("statements -> epsilon\n");
    CodeNode* node = new CodeNode;
    $$ = node;
}
        | statement SEMICOLON statements {
    printf("statements -> statement SEMICOLON statements\n");
    CodeNode* node = new CodeNode;
    node->code = $1->code + $3->code;
    $$ = node;
}
        | nonsemicolonstatement statements {
    printf("statements -> nonsemicolonstatement statements\n");
    CodeNode* node = new CodeNode;
    node->code = $1->code + $2->code;
    $$ = node;
};
        

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
          // we will want assign to look like a := 
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
int main(int argc, char** argv) {
    if(argc >= 2){
        yyin = fopen(argv[1], "r");
        if(yyin == NULL)
            yyin = stdin;
    }else{
        yyin = stdin;
    }
    return yyparse();
}

void yyerror(const char* s) {
    extern char* yytext;

    printf("Parse Error: %s, on line %d\n", s, lineNumber);
    exit(1);
}

bool has_main() {
    bool TF = false;
    for(int i = 0; i < symbol_table.size(); i++) {
        Function *f = &symbol_table[i];
        if (f->name == "main")
            TF = true;
    }
    return TF;
}

std::string create_temp() {
    static int num = 0;
    std::string value = "_temp" + std::to_string(num);
    num += 1;
    return value;
}

std::string decl_temp_code(std::string &temp) {
    return std::string(". ") + temp + std::string("\n");
}