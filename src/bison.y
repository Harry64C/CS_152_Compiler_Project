%{
    #include <stdio.h>
    #include <string>
    #include <vector>
    #include <string.h>
    #include <stdlib.h>
    #include <sstream>


    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;
    extern int lineNumber;
    extern int col_num;
    char *identToken;
    int numberToken;
    extern char* yytext;
    #define YYERROR_VERBOSE 1
    void yyerror(const char* s);
    bool ifFunc = false;
    bool ifArray = false;
    std::string varName; 
    bool ifArr = false;
    bool leZero = false;
    int loop = 0;
    int ifcount = 0;
    enum Type { Integer, Array };
    std::ostringstream ll;

    struct Symbol {
        std::string name;
        Type type;
    };

    struct Function {
        std::string name;
        std::vector<Symbol> declarations;
    };
static int count;
std::string create_temp() {
    std::ostringstream ss;
    static int num = 0;
    ss << num;
    std::string value = "_temp" + ss.str();
    num += 1;
    return value;
} 



std::string decl_temp_code(std::string &temp) {
    return std::string(". ") + temp + std::string("\n");
}

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
    std::vector <std::string> reservedWords;
    bool inReserve(std::string &value){
        reservedWords.push_back(std::string("check"));
        reservedWords.push_back(std::string("plus"));
        reservedWords.push_back(std::string("minus"));
        reservedWords.push_back(std::string("mult"));
        reservedWords.push_back(std::string("divi"));
        reservedWords.push_back(std::string("mod")); 
        reservedWords.push_back(std::string("AND"));
        reservedWords.push_back(std::string("OR"));
        reservedWords.push_back(std::string("then"));
        reservedWords.push_back(std::string("or"));
        reservedWords.push_back(std::string("until"));
        reservedWords.push_back(std::string("stop"));
        reservedWords.push_back(std::string("go"));
        reservedWords.push_back(std::string("inp"));
        reservedWords.push_back(std::string("outp"));
        reservedWords.push_back(std::string("eq"));
        reservedWords.push_back(std::string("gte"));
        reservedWords.push_back(std::string("lte"));
        reservedWords.push_back(std::string("dne"));
        reservedWords.push_back(std::string("gt"));
        reservedWords.push_back(std::string("lt"));
        reservedWords.push_back(std::string("funct"));
        reservedWords.push_back(std::string("arr"));
        reservedWords.push_back(std::string("inum"));
        for(int i = 0; i < reservedWords.size(); i++){
            if(value == reservedWords[i]){
                return true;
            }
        }
        return false;
    }
    bool f_function(std::string &value){
        for(int i = 0; i < symbol_table.size(); i++){
            if(symbol_table[i].name == value){
                return true;
            }
        }
        return false;
    }
    bool isArray(std::string &name){
        Function *f = get_function();
        for(int i = 0; i < f->declarations.size(); i++){
            Symbol *s = &f->declarations[i];
            if(s->name == name && s->type == Array){
                return true;
            }
            else if(s->name == name){
                return false;
            }
        }
        return false;
    }
    // find a particular variable using the symbol table.
    // grab the most recent function, and linear search to
    // find the symbol you are looking for.
    // you may want to extend "find" to handle different types of "Integer" vs "Array"
    bool find(std::string &value) {
        Function *f = get_function();
        for(int i=0; i < f->declarations.size(); i++) {
            Symbol *s = &f->declarations[i];
            if (s->name == value) {
            return true;
            }
        }
        return false;
    }

    // when you see a function declaration inside the grammar, add
    // the function name to the symbol table
    void add_function_to_symbol_table(std::string &value) {
    Function f; 
    f.name = value; 
    symbol_table.push_back(f);
    }

    // when you see a symbol declaration inside the grammar, add
    // the symbol name as well as some type information to the symbol table
    void add_variable_to_symbol_table(std::string &value, Type t) {
    Symbol s;
    s.name = value;
    s.type = t;
    Function *f = get_function();
    f->declarations.push_back(s);
    }

    // a function to print out the symbol table to the screen
    // largely for debugging purposes.
    void print_symbol_table(void) {
    printf("symbol table:\n");
    printf("--------------------\n");
    for(int i=0; i<symbol_table.size(); i++) {
        printf("function: %s\n", symbol_table[i].name.c_str());
        for(int j=0; j<symbol_table[i].declarations.size(); j++) {
        printf("  locals: %s\n", symbol_table[i].declarations[j].name.c_str());
        }
    }
    printf("--------------------\n");
    }

    struct CodeNode {
        std::string code; // generated code as a string.
        std::string name;
    };
    
%}

%union {
  char *op_val;
  struct CodeNode *node;
}
%start prog_start
%token INTEGER ARRAY FUNCTION ASSIGN ADD SUBTRACT MULTIPLY DIVISION MOD EQ GTE LTE NEQ GT LT BEGIN_BODY END_BODY BEGIN_PARAM END_PARAM 
%token L_PAREN R_PAREN IF ELSE ELSE_IF WHILE BREAK CONTINUE READ WRITE RETURN SEMICOLON COMMA AND OR 
%token <op_val> NUMBER 
%token <op_val> IDENTIFIER
//%type  <op_val> symbol 
%type  <op_val> function_ident
%type  <node>   functions
%type  <node>   function
//%type  <node>   declarations
%type  <node>   declaration
%type  <node>   statements
%type  <node>   statement

%type  <node>   argument
%type  <node>   arguments
%type  <node>   nonsemicolonstatement
%type  <node>   equations

%type  <node>   assignment
%type  <node>   function_call
%type  <node>   arraycall
%type  <node>   addop
%type  <node>   term

%type  <node>   mulop
%type  <node>   factor
%type  <node>   param
%type  <node>   params

%type  <node>   if_start
%type  <node>   branch_check
%type  <node>   else_check
%type  <node>   until_loop


%%

prog_start: functions { // this happens last
    CodeNode* node = $1; // $1 means the leftmost of the rhs of the grammar
    std::string code = node->code;
    std::string error;
    std::string mains = std::string("main");
    if(!f_function(mains)){
        error = std::string("No main Function");
        yyerror(error.c_str());
    }
    //printf("generated code:\n");
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
            std::string func_name = $3;
            CodeNode* argumen = $5;
            CodeNode* body = $8;
            add_function_to_symbol_table(func_name);
            std::string code = std::string("func ") + func_name + std::string("\n");
            code += argumen->code;
            code += body->code;
            code +=std::string("endfunc\n");
            CodeNode *node = new CodeNode;
            node->code = code;
            $$ = node;
    };
        
function_ident: IDENTIFIER {
    // add the function to the symbol table.
    std::string func_name = $1;
    std::string error;
    if(inReserve(func_name)){
        error = std::string(" name cannot be a reserved word");
        yyerror(error.c_str());
    }
    add_function_to_symbol_table(func_name);
    $$ = $1;
};

arguments: argument { 
        CodeNode* arg = $1;
        std::string code = arg->code;
        CodeNode *node = new CodeNode;
        node->code = code;
        $$ = node;
}
         | argument COMMA arguments { CodeNode*  arg = $1;
         CodeNode* args = $3;
         std::string code = arg->code + args->code;
         CodeNode *node = new CodeNode;
         node->code = code;
         $$ = node;
};

argument: %empty {
    CodeNode *node = new CodeNode;
    count = 0;
    $$ = node;
}
        | INTEGER IDENTIFIER {std::string value = $2; 
        Type t = Integer;
        std::string error;
        if(inReserve(value)){
            error = std::string("variable cannot be defined by a reservedWord");
        }
        if(find(value)|| f_function(value)){
            error = std::string("variable already defined");
            yyerror(error.c_str());
        }
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        std::ostringstream s;
        s << count;
        //printf("count is %d", count);
        code += std::string("= ") + value + std::string(", ") + std::string("$") + s.str() + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        count++;
        $$ = node;
};

statements: %empty {
    CodeNode* node = new CodeNode;
    count = 0;
    $$ = node;
}
        | statement SEMICOLON statements {
    CodeNode* node = new CodeNode;
    node->code = $1->code + $3->code;
    $$ = node;
}
        | nonsemicolonstatement statements {
    CodeNode* node = new CodeNode;
    node->code = $1->code + $2->code;
    $$ = node;
};
        

statement: declaration {
    CodeNode* decl = $1; 
    std::string code = decl->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    $$ = node;
}
         | assignment {$$ = $1;}
         | function_call  {$$ = $1;}
         | BREAK  {CodeNode* node = new CodeNode;
            ll << loop;
          node->code = std::string(":= endloop") + ll.str() + std::string("\n");
          $$ = node;
         }
         | WRITE BEGIN_PARAM equations END_PARAM {
            CodeNode* node = new CodeNode; 
            node->code = $3->code;
            node->code += std::string(".> ") + $3->name + std::string("\n");             
            $$ = node; 
}
         | CONTINUE {CodeNode* node = new CodeNode;
         ll << loop;
         node->code = std::string(":= beginloop") + ll.str() + std::string("\n");
         $$ = node;
         }
         | RETURN equations {
            CodeNode* node = new CodeNode; 
            CodeNode* eq = $2;
            node->code = eq->code; 
            node->code += std::string("ret ") + eq->name + std::string("\n"); 
            $$ = node; 
         };

nonsemicolonstatement: if_start {
    $$ = $1;
}
         | until_loop {
            $$ = $1;
};
         
declaration: INTEGER IDENTIFIER {
        std::string value = $2; 
        Type t = Integer;
        std::string error;
        if(inReserve(value)){
            error = std::string("variable cannot be defined by a reservedWord");
        }
        if(find(value)|| f_function(value)){
            error = std::string("variable already defined");
            yyerror(error.c_str());
        }
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        $$ = node;
}
           | INTEGER IDENTIFIER ASSIGN equations {
        std::string value = $2; 
        Type t = Integer;
        std::string error;
        if(inReserve(value)){
            error = std::string("variable cannot be defined by a reservedWord");
        }
        if(find(value)|| f_function(value)){
            error = std::string("variable already defined");
            yyerror(error.c_str());
        }
        add_variable_to_symbol_table(value, t);

        CodeNode* node = new CodeNode;
        //CodeNode* eq = $4;
        //node->code = eq->code;

        node->code = std::string(". ") + value + std::string("\n");
        CodeNode* eq = $4;

        if(ifArray){
            node->code = std::string("=[] ") + value + std::string(", ") + eq->code + std::string("\n");
            ifArray = false;
        }
        else {
            node->code += eq->code;
            node->code += std::string("= ") + value + std::string(", ") + eq->name + std::string("\n");
        }
        $$ = node;
}
           | ARRAY IDENTIFIER L_PAREN factor R_PAREN {
        std::string name = $2;
        CodeNode* n = $4; 
        Type t = Array;
        std::string error;
        if(inReserve(name)){
            error = std::string("variable cannot be defined by a reservedWord");
        }
        if(find(name)|| f_function(name)){
            error = std::string("variable already defined");
            yyerror(error.c_str());
        }
        else if (leZero == true){
            error = std::string("Invalid size less than or equal to 0");
            yyerror(error.c_str());
        }
        add_variable_to_symbol_table(name, t);
        std::string code = std::string(".[] ") + name + std::string(", ") + $4->name  + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        $$ =node;
}
            | INTEGER IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {
        std::string name = $2;
        std::string error;
        //if (!find(name, Integer, error)) {
        //    yyerror(error.c_str());
        //}
        

        Type t = Integer;
        if(inReserve(name)){
            error = std::string("variable cannot be defined by a reservedWord");
        }
        if(find(name)|| f_function(name)){
            error = std::string("variable already defined");
            yyerror(error.c_str());
        }
        add_variable_to_symbol_table(name, t);
        std::string code = std::string(". ") + name + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;

        node->code += std::string(".< ") + name + std::string("\n");
        $$ = node;
};

assignment: IDENTIFIER ASSIGN equations {
        std::string name = $1;
         std::string error;
         
        if (!find(name)) {
            error = std::string("UNKNOWN VARIABLE");
            yyerror(error.c_str());
        }
        if(isArray(name)){
            error = std::string("variable is an array and is missing array index");
            yyerror(error.c_str());
        }
        CodeNode* node = new CodeNode;
        CodeNode* eq = $3;
        node->code = eq->code;
        if(ifFunc){
            node->code += name + std::string("\n");
            ifFunc = false;
        }
        else if(ifArray){
            node->code = eq->code;
            node->code += std::string("= ") + name + std::string(", ") + $3->name + std::string("\n");
            ifArray = false;
        }
        else{
            node->code += std::string("= ")+ name + std::string(", ") + $3->name + std::string("\n");
        }
        $$ = node;
}
          
          | arraycall ASSIGN equations {
            CodeNode* node = new CodeNode;
            CodeNode* eq = $3;
            node->code = eq->code;
            node->code += std::string("[]= ") + $1->code + std::string(", ") + $3->name + std::string("\n");
            $$ = node;
}

          | IDENTIFIER ASSIGN READ BEGIN_PARAM END_PARAM {
            std::string name = $1;
            std::string error;
            //if (!find(name, Integer, error)) {
            //    yyerror(error.c_str());
            //}
            if (!find(name)) {
            error = std::string("UNKNOWN VARIABLE");
            yyerror(error.c_str());
            }
            if(isArray(name)){
                error = std::string("variable is an array and is missing array index");
                yyerror(error.c_str());
            }
            CodeNode* node = new CodeNode;
            node->code = std::string(".< ") + name + std::string("\n");
            $$ = node;
}

arraycall: IDENTIFIER L_PAREN factor R_PAREN {
    std::string name = $1;
    CodeNode* node = new CodeNode;
    std::string error;
         
    if (!find(name)) {
        error = std::string("UNKNOWN VARIABLE");
        yyerror(error.c_str());
    }
    if(!isArray(name)){
        error = std::string("Variable is not an array");
        yyerror(error.c_str());
    }
    if(leZero == true){
        error = std::string("Invalid access to array element less than zero");
        yyerror(error.c_str()); 
    }

    CodeNode* fac = $3;
    node->code = fac->code;
    node->code += name + std::string(", ") + fac->name;
    $$ = node;
};

equations: equations addop term {
    std::string temp = create_temp();
    CodeNode* node = new CodeNode;
    node->code = $1->code + $3->code + decl_temp_code(temp);
    node->code += $2->code + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
    node->name = temp;

    $$ = node;
}
    | term {
        CodeNode* node = new CodeNode;
        node->code = $1->code;
        node->name = $1->name;
        $$ = node;
    };

addop: ADD {CodeNode* node = new CodeNode; node->code = std::string("+ "); $$ = node;}
     | SUBTRACT {CodeNode* node = new CodeNode; node->code = std::string("- "); $$ = node;}
     | EQ {CodeNode* node = new CodeNode; node->code = std::string("== "); $$ = node;}
     | GTE {CodeNode* node = new CodeNode; node->code = std::string(">= "); $$ = node;}
     | LTE {CodeNode* node = new CodeNode; node->code = std::string("<= "); $$ = node;}
     | NEQ {CodeNode* node = new CodeNode; node->code = std::string("!= "); $$ = node;}
     | GT {CodeNode* node = new CodeNode; node->code = std::string("> "); $$ = node;}
     | LT {CodeNode* node = new CodeNode; node->code = std::string("< "); $$ = node;}
     ;

term: term mulop factor{
    std::string temp = create_temp();
    CodeNode* node = new CodeNode;
    node->code = $1->code + $3->code +  decl_temp_code(temp);
    node->code += $2->code + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
    node->name = temp;
    $$ = node;
}
    | factor {
    CodeNode* node = new CodeNode;
    node->code = $1->code;
    node->name = $1->name;
    $$ = node;
};


mulop: MULTIPLY {CodeNode* node = new CodeNode; node->code = std::string("* "); $$ = node;}
     | DIVISION {CodeNode* node = new CodeNode; node->code = std::string("/ "); $$ = node;}
     | MOD {CodeNode* node = new CodeNode; node->code = std::string("% "); $$ = node;}
     | AND {CodeNode* node = new CodeNode; node->code = std::string("&& "); $$ = node;}
     | OR {CodeNode* node = new CodeNode; node->code = std::string("|| "); $$ = node;}
     ;
     
factor: L_PAREN equations R_PAREN {
    CodeNode* eq = $2;
    CodeNode *node = new CodeNode;
    node->code = eq->code;
    node->name = $2->name;
    $$ = node;
}
      | INTEGER {
        CodeNode* node = new CodeNode; $$ = node;}
      | IDENTIFIER {
        CodeNode* node = new CodeNode; 
        node->name = $1; 
        std::string error;
        if (!find(node->name)) {
            error = std::string("UNKNOWN VARIABLE\n");
            yyerror(error.c_str());
        }
        if(isArray(node->name)){
            error = std::string("variable is an array and is missing array index");
            yyerror(error.c_str());
        }
        $$ = node;
}
      | NUMBER {//CodeNode* node = new CodeNode; node->name = $1; if(atoi($1) < 0){leZero = true;} else{leZero = false;} $$ = node;
        std::string temp = create_temp(); CodeNode* node = new CodeNode; if(atoi($1) < 0){ leZero = true; int ssd = -atoi($1);std::ostringstream ss;
        ss << ssd; node->code = decl_temp_code(temp) + std::string("- ") + temp + std::string(", 0, ") + ss.str() + std::string("\n"); node->name = temp;} else{ leZero = false; node->name = $1;} $$ = node;
      }
      | function_call {
        CodeNode* node = new CodeNode; node->code = $1->code;
        node->name = $1->name;
        $$ = node;
      }

      | arraycall {
        std::string temp = create_temp();
        
        ifArray = true;
        CodeNode* node = new CodeNode;
        node->code = decl_temp_code(temp);
        node->code += std::string("=[] ") +temp +std::string(" , ") + $1->code + std::string("\n");
        node->name = temp;
        $$ = node;

      };

function_call: IDENTIFIER BEGIN_PARAM params END_PARAM  {
    std::string name = $1;
    std::string error;
    if (!f_function(name)) {
        error = std::string("Undefined function");
        yyerror(error.c_str());
    }

    ifFunc = true;
    CodeNode* node = new CodeNode;
    node->name = $1;
    node->code = $3->code;
    node->code += std::string("call ") + name + std::string(", ") + varName;
    $$ = node;

};

params: param {
            CodeNode* node = new CodeNode;
            node->code = $1->code + std::string("\n");
            $$ = node;
        
        }
      | param COMMA params {
            CodeNode* node = new CodeNode;
            node->code = $1->code + std::string("\n") + $3->code;
            $$ = node;

        }
      | %empty {CodeNode* node = new CodeNode; $$ = node;}
      ;

param: IDENTIFIER {
        CodeNode* node = new CodeNode;
        std::string name = $1;
        node->name = name;
        node->code = std::string("param ") + name;
        std::string error;
        if (!find(node->name)) {
            error = std::string("UNKNOWN VARIABLE\n");
            yyerror(error.c_str());
        }
        $$ = node;
}
     | NUMBER {
        CodeNode* node = new CodeNode;
        std::string num = $1;
        node->code = std::string("param ") + num;
        $$ = node;
};


if_start: IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY branch_check {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << ifcount;

        node->code += $3->code;
        node->code += std::string("?:= if_true") + ll.str() + std::string(", ") + $3->name + std::string("\n");
        node->code += $8->name;

        //If body code
        node->code += std::string(": if_true") + ll.str() + std::string("\n");
        node->code += $6->code;
        node->code += std::string(":= endif") + ll.str() + std::string("\n");

        node->code += $8->code;
        //End of conditional branches
        node->code += std::string(": endif") + ll.str() + std::string("\n");
        ifcount++;
        $$ = node;
};


branch_check: ELSE_IF BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY else_check {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << ifcount;
        
        node->name = std::string(":= elseif_start") + ll.str() + std::string("\n");
        node->code = std::string(": elseif_start") + ll.str() + std::string("\n");
        node->code += $3->code;
        node->code += std::string("?:= elseif_true") + ll.str() + std::string(", ") + $3->name + std::string("\n");
        node->code += $8->name;

        //If body code
        node->code += std::string(": elseif_true") + ll.str() + std::string("\n");
        node->code += $6->code;
        node->code += std::string(":= end_elseif") + ll.str() + std::string("\n");

        node->code += $8->code;
        //End of conditional branches
        node->code += std::string(": end_elseif") + ll.str() + std::string("\n");
        ifcount++;
        $$ = node;
}
            | else_check {
                $$ = $1;
};

else_check: %empty {
            CodeNode* node = new CodeNode;
            std::ostringstream ll;
            ll.str("");
            ll << ifcount;
            node->name = std::string(":= endif") + ll.str() + std::string("\n");
            //ifcount++;
            $$ = node;
          }
          | ELSE BEGIN_BODY statements END_BODY {
            std::ostringstream ll;
            ll.str("");
            ll << ifcount;
            CodeNode* node = new CodeNode;
            node->name = std::string(":= else") + ll.str() + std::string("\n");
            node->code += std::string(": else") + ll.str() + std::string("\n");
            node->code += $3->code;
            $$ = node;
          };

until_loop: WHILE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << loop;
        node->code = std::string(": beginloop") +  ll.str() + std::string("\n");
        node->code += $3->code;
        node->code += std::string("?:= bodyloop") + ll.str() + std::string(", ") + $3->name + std::string("\n");
        node->code += std::string(":= endloop") + ll.str() + std::string("\n");
        node->code += std::string(": bodyloop") + ll.str() + std::string("\n");
        node->code += $6->code + std::string(":= beginloop") + ll.str() + std::string("\n");
        node->code += std::string(": endloop") + ll.str() + std::string("\n");
        loop++;
        $$ = node;
};


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