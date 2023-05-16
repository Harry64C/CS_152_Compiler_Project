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
    printf("generated code:\n");
    printf("%s\n", code.c_str());
}
          
functions: function functions {
    CodeNode* func = $1;
    CodeNode* funcs = $2;
    std::string code = func->code + funcs->code;
    CodeNode* node = new CodeNode;
    node->code = code;
    $$ = node;
    }
         | %empty {
            CodeNode *node = new CodeNode;
            $$ = node;
    };
         

function: INTEGER FUNCTION function_ident BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY {
            printf("function -> INTEGER FUNCTION function_ident BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");
            std::string func_name = $3;
            std::string param = $5;
            std::string body = $8;
            std::string code = std::string("func ") + func_name + std::string("\n");
            code += param->code;
            code += body->code;
            code +=std::string("endfunc\n");
            CodeNode *node = new CodeNode;
            node->code = code;
            $$ = node;
    };
        
function_ident: IDENTIFIER {
  // add the function to the symbol table.
  std::string func_name = $1;
  add_function_to_symbol_table(func_name);
  $$ = $1;
  printf("function_ident -> IDENTIFIER\n");
};
arguments: argument { CodeNode* arg = $1;
        std::string code = arg->code;
        CodeNode *node = new CodeNode;
        node->code = code;
        $$ = node;}
         | argument COMMA arguments { CodeNode*  arg = $1;
         CodeNode* args = $3;
         std::string code = arg->code + args->code;
         CodeNode *node = new CodeNode;
         node->code = code;
         $$ = node;
         }
         ;
argument: %empty {CodeNode *node = new CodeNode;
   $$ = node;}
        | INTEGER IDENTIFIER {std::string value = $2; 
        Type t = Integer;
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        $$ = node;
        }
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
        

statement: declaration {CodeNode* decl = $1; std::string code = decl->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
         | assignment {CodeNode* node = new CodeNode; node->code = $1->code; $$ = node;}
         | function_call  {CodeNode* fcall = $1; std::string code = fcall->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
         | BREAK  {}
         | WRITE BEGIN_PARAM equations END_PARAM {printf("statement -> WRITE BEGIN_PARAM equations END_PARAM\n");}
         | CONTINUE {printf("statement -> CONTINUE\n");}
         | RETURN equations {printf("statement -> RETURN equations \n");}
         ;
nonsemicolonstatement: if_start {printf("nonsemicolonstatement -> if_start\n");}
         | until_loop {printf("nonsemicolonstatement -> until_loop\n");}
         ;
         
declaration: INTEGER IDENTIFIER {std::string value = $2; 
        Type t = Integer;
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        $$ = node;}
           | INTEGER IDENTIFIER ASSIGN equations {printf("declaration ->INTEGER IDENTIFIER ASSIGN equations\n");}
           | ARRAY IDENTIFIER L_PAREN factor R_PAREN {std::string name = $2;
           CodeNode* n = $4;
           std::string code = std::string(".[] ") + name + std::string(", ") + n->code;
           CodeNode* node = new CodeNode;
           node->code = code;
           $$ =node;
           }
           | INTEGER IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {printf("declaration-> INTEGER IDENTIFIER ASSIGN READ BEGIN_PARAM ENDPARAM \n");}
           ;

assignment: IDENTIFIER ASSIGN equations {std::string name = $1;
                                        CodeNode* rhs = $3;
                                        std::string code = std::string("= ") + name + std::string(", ") + rhs;
                                        }
          | arraycall ASSIGN equations {printf("arraycall ASSIGN equations\n");}
          | IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {printf("assignment-> IDENTIFIER ASSIGN READ BEGIN_PARAM ENDPARAM \n");}
          // we will want assign to look like a := 
arraycall: IDENTIFIER L_PAREN param R_PAREN {}
         ;
equations: term equationsp {CodeNode* t = $1; CodeNode* eqp = $2; std::string code = t->code + eqp->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
         ;
equationsp: addop term equationsp {CodeNode* op = $1 CodeNode* t = $2; CodeNode * eqp = $3; std::string code = op->code + term->code + eqp->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
	    | %empty {CodeNode* node = new CodeNode; $$ = $1;}
	    ;
addop: ADD {CodeNode* node = new CodeNode; node->code = std::string("+ "); $$ = node;}
     | SUBTRACT {CodeNode* node = new CodeNode; node->code = std::string("- "); $$ = node;}
     | EQ {CodeNode* node = new CodeNode; node->code = std::string("+ "); $$ = node;}
     | GTE {CodeNode* node = new CodeNode; node->code = std::string(">= "); $$ = node;}
     | LTE {CodeNode* node = new CodeNode; node->code = std::string("<= "); $$ = node;}
     | NEQ {CodeNode* node = new CodeNode; node->code = std::string("!= "); $$ = node;}
     | GT {CodeNode* node = new CodeNode; node->code = std::string("> "); $$ = node;}
     | LT {CodeNode* node = new CodeNode; node->code = std::string("< "); $$ = node;}
     ;
term: factor termp {CodeNode* fact = $1; CodeNode* tp = $2; std::code = fact->code + tp->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
    ;

termp: mulop factor termp {CodeNode* op = $1; CodeNode fct = $2; CodeNode* tp = $3; std::string code = op->code + fct->code + tp->code; CodeNode* node = new CodeNode; node->code = code; $$ = node;}
     | %empty {CodeNode* node = new CodeNode; $$ = $1;}
     ;
mulop: MULTIPLY {CodeNode* node = new CodeNode; node->code = std::string("* "); $$ = node;}
     | DIVISION {CodeNode* node = new CodeNode; node->code = std::string("/ "); $$ = node;}
     | MOD {CodeNode* node = new CodeNode; node->code = std::string("% "); $$ = node;}
     | AND {CodeNode* node = new CodeNode; node->code = std::string("&& "); $$ = node;}
     | OR {CodeNode* node = new CodeNode; node->code = std::string("|| "); $$ = node;}
     ;
     
factor: L_PAREN equations R_PAREN {}
      | INTEGER {CodeNode* node = new CodeNode; node -> code = $1; $$ = node;}
      | IDENTIFIER {CodeNode* node = new CodeNode; node->code = $1; $$ = node;}
      | NUMBER {CodeNode* node = new CodeNode; node->code = $1; $$ = node;}
      | function_call {CodeNode* node = new CodeNode; node->code = $1->code; $$ = node;}
      ;


function_call: IDENTIFIER BEGIN_PARAM params END_PARAM {}
             ;

params: param {printf("params->param\n");}
      | param COMMA params {printf("params-> param COMMA params\n");}
      | %empty {printf("params->epsilon\n");}
      ;

param: IDENTIFIER {}
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