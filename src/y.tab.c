/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

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
    

#line 240 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER = 258,
    ARRAY = 259,
    FUNCTION = 260,
    ASSIGN = 261,
    ADD = 262,
    SUBTRACT = 263,
    MULTIPLY = 264,
    DIVISION = 265,
    MOD = 266,
    EQ = 267,
    GTE = 268,
    LTE = 269,
    NEQ = 270,
    GT = 271,
    LT = 272,
    BEGIN_BODY = 273,
    END_BODY = 274,
    BEGIN_PARAM = 275,
    END_PARAM = 276,
    L_PAREN = 277,
    R_PAREN = 278,
    IF = 279,
    ELSE = 280,
    ELSE_IF = 281,
    WHILE = 282,
    BREAK = 283,
    CONTINUE = 284,
    READ = 285,
    WRITE = 286,
    RETURN = 287,
    SEMICOLON = 288,
    COMMA = 289,
    AND = 290,
    OR = 291,
    NUMBER = 292,
    IDENTIFIER = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 175 "bison.y" /* yacc.c:355  */

  char *op_val;
  struct CodeNode *node;

#line 324 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 341 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   163

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   217,   217,   230,   238,   244,   258,   270,   277,   285,
     290,   312,   317,   322,   329,   336,   337,   338,   343,   349,
     354,   362,   365,   369,   386,   416,   438,   463,   493,   501,
     520,   544,   553,   560,   561,   562,   563,   564,   565,   566,
     567,   570,   578,   586,   587,   588,   589,   590,   593,   600,
     602,   616,   620,   626,   638,   655,   661,   667,   670,   682,
     690,   712,   734,   738,   747,   758
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ARRAY", "FUNCTION", "ASSIGN",
  "ADD", "SUBTRACT", "MULTIPLY", "DIVISION", "MOD", "EQ", "GTE", "LTE",
  "NEQ", "GT", "LT", "BEGIN_BODY", "END_BODY", "BEGIN_PARAM", "END_PARAM",
  "L_PAREN", "R_PAREN", "IF", "ELSE", "ELSE_IF", "WHILE", "BREAK",
  "CONTINUE", "READ", "WRITE", "RETURN", "SEMICOLON", "COMMA", "AND", "OR",
  "NUMBER", "IDENTIFIER", "$accept", "prog_start", "functions", "function",
  "function_ident", "arguments", "argument", "statements", "statement",
  "nonsemicolonstatement", "declaration", "assignment", "arraycall",
  "equations", "addop", "term", "mulop", "factor", "function_call",
  "params", "param", "if_start", "branch_check", "else_check",
  "until_loop", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     7,    16,   -35,     0,    -4,   -35,   -35,   -35,    17,
      49,    20,    33,    28,   -35,    37,    49,    15,   -35,    29,
      36,    46,    55,   -35,   -35,    60,    23,     5,    57,    48,
      15,   -35,   -35,    76,   -35,   -35,   -35,    79,    69,    23,
      23,    23,   -35,    23,   -35,   -12,   -35,   140,    21,   -35,
     -35,    -2,   -16,    23,   -35,    15,   -35,    23,    11,    23,
      96,   107,   118,    56,   -35,   -35,   -35,   -35,   -35,   -35,
     -35,   -35,    23,   -35,   -35,   -35,   -35,   -35,    23,    72,
     140,   -35,   -35,    73,    59,    74,   -35,   140,    75,   140,
      77,    80,    84,   -35,   -35,    21,   -35,    85,   -35,   -16,
     -35,    95,   -35,    15,    15,   -35,   -35,   -35,    99,   108,
      25,   -35,   111,   120,   -35,   -35,    15,    23,   119,   129,
     -35,   131,    15,   132,   133,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,     1,     3,     6,     0,
       9,     0,     0,     7,    10,     0,     9,    11,     8,     0,
       0,     0,     0,    17,    19,     0,     0,     0,     0,     0,
      11,    14,    15,     0,    16,    21,    22,    23,     0,     0,
       0,     0,    49,     0,    51,    50,    53,    20,    32,    42,
      52,     0,    57,     0,     5,    11,    13,     0,     0,     0,
       0,     0,     0,     0,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    43,    44,    45,    46,    47,     0,     0,
      27,    59,    58,     0,    55,     0,    12,    28,     0,    24,
       0,     0,     0,    18,    48,    31,    41,     0,    54,    57,
      30,     0,    25,    11,    11,    29,    56,    26,     0,     0,
      63,    65,     0,     0,    60,    62,    11,     0,     0,     0,
      64,     0,    11,     0,    63,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   155,   -35,   -35,   144,   -35,   -26,   -35,   -35,
     -35,   -35,   -17,   -34,   -35,    89,   -35,     6,   -15,    63,
     -35,   -35,   -35,    39,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    12,    13,    28,    29,    30,
      31,    32,    46,    47,    72,    48,    78,    49,    50,    83,
      84,    35,   114,   115,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    42,    34,     1,    56,    60,    61,    62,    52,    63,
      53,    51,     5,    33,    42,    34,     6,    80,    19,    20,
      43,    81,    82,    87,    89,    52,    42,    53,    79,    86,
      73,    74,    75,    43,     8,    44,    45,    10,    33,    21,
      34,    88,    22,    23,    24,    43,    25,    26,    44,    45,
     112,   113,    11,    27,    15,    17,    76,    77,    14,    85,
      44,    45,    16,    64,    65,    90,    39,    37,    66,    67,
      68,    69,    70,    71,    38,    40,    54,   108,   109,    94,
      41,    55,    57,   119,    96,    58,    33,    33,    34,    34,
     118,    59,    97,    99,    98,   101,   123,   100,   103,    33,
     102,    34,   104,    64,    65,    33,   105,    34,    66,    67,
      68,    69,    70,    71,    64,    65,   107,    91,   110,    66,
      67,    68,    69,    70,    71,    64,    65,   111,    92,   116,
      66,    67,    68,    69,    70,    71,    64,    65,   120,    93,
     117,    66,    67,    68,    69,    70,    71,    64,    65,   122,
     121,   124,    66,    67,    68,    69,    70,    71,   112,     7,
      18,    95,   106,   125
};

static const yytype_uint8 yycheck[] =
{
      17,     3,    17,     3,    30,    39,    40,    41,    20,    43,
      22,     6,     5,    30,     3,    30,     0,    51,     3,     4,
      22,    37,    38,    57,    58,    20,     3,    22,    30,    55,
       9,    10,    11,    22,    38,    37,    38,    20,    55,    24,
      55,    30,    27,    28,    29,    22,    31,    32,    37,    38,
      25,    26,     3,    38,    21,    18,    35,    36,    38,    53,
      37,    38,    34,     7,     8,    59,    20,    38,    12,    13,
      14,    15,    16,    17,    38,    20,    19,   103,   104,    23,
      20,    33,     6,   117,    78,     6,   103,   104,   103,   104,
     116,    22,    20,    34,    21,    20,   122,    23,    18,   116,
      23,   116,    18,     7,     8,   122,    21,   122,    12,    13,
      14,    15,    16,    17,     7,     8,    21,    21,    19,    12,
      13,    14,    15,    16,    17,     7,     8,    19,    21,    18,
      12,    13,    14,    15,    16,    17,     7,     8,    19,    21,
      20,    12,    13,    14,    15,    16,    17,     7,     8,    18,
      21,    19,    12,    13,    14,    15,    16,    17,    25,     4,
      16,    72,    99,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    40,    41,    42,     5,     0,    41,    38,    43,
      20,     3,    44,    45,    38,    21,    34,    18,    44,     3,
       4,    24,    27,    28,    29,    31,    32,    38,    46,    47,
      48,    49,    50,    51,    57,    60,    63,    38,    38,    20,
      20,    20,     3,    22,    37,    38,    51,    52,    54,    56,
      57,     6,    20,    22,    19,    33,    46,     6,     6,    22,
      52,    52,    52,    52,     7,     8,    12,    13,    14,    15,
      16,    17,    53,     9,    10,    11,    35,    36,    55,    30,
      52,    37,    38,    58,    59,    56,    46,    52,    30,    52,
      56,    21,    21,    21,    23,    54,    56,    20,    21,    34,
      23,    20,    23,    18,    18,    21,    58,    21,    46,    46,
      19,    19,    25,    26,    61,    62,    18,    20,    46,    52,
      19,    21,    18,    46,    19,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    43,    44,    44,    45,
      45,    46,    46,    46,    47,    47,    47,    47,    47,    47,
      47,    48,    48,    49,    49,    49,    49,    50,    50,    50,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    56,    56,    57,    58,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     9,     1,     1,     3,     0,
       2,     0,     3,     2,     1,     1,     1,     1,     4,     1,
       2,     1,     1,     2,     4,     5,     6,     3,     3,     5,
       4,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     4,     1,     3,     0,     1,     1,
       8,     8,     1,     0,     4,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 217 "bison.y" /* yacc.c:1646  */
    { // this happens last
    CodeNode* node = (yyvsp[0].node); // $1 means the leftmost of the rhs of the grammar
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
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 230 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* func = (yyvsp[-1].node);
    CodeNode* funcs = (yyvsp[0].node);
    std::string code = func->code + funcs->code;
    CodeNode* node = new CodeNode;
    node->code = code;
    (yyval.node) = node;
    }
#line 1536 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 238 "bison.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            (yyval.node) = node;
    }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 244 "bison.y" /* yacc.c:1646  */
    {
            std::string func_name = (yyvsp[-6].op_val);
            CodeNode* argumen = (yyvsp[-4].node);
            CodeNode* body = (yyvsp[-1].node);
            add_function_to_symbol_table(func_name);
            std::string code = std::string("func ") + func_name + std::string("\n");
            code += argumen->code;
            code += body->code;
            code +=std::string("endfunc\n");
            CodeNode *node = new CodeNode;
            node->code = code;
            (yyval.node) = node;
    }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 258 "bison.y" /* yacc.c:1646  */
    {
    // add the function to the symbol table.
    std::string func_name = (yyvsp[0].op_val);
    std::string error;
    if(inReserve(func_name)){
        error = std::string(" name cannot be a reserved word");
        yyerror(error.c_str());
    }
    add_function_to_symbol_table(func_name);
    (yyval.op_val) = (yyvsp[0].op_val);
}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 270 "bison.y" /* yacc.c:1646  */
    { 
        CodeNode* arg = (yyvsp[0].node);
        std::string code = arg->code;
        CodeNode *node = new CodeNode;
        node->code = code;
        (yyval.node) = node;
}
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 277 "bison.y" /* yacc.c:1646  */
    { CodeNode*  arg = (yyvsp[-2].node);
         CodeNode* args = (yyvsp[0].node);
         std::string code = arg->code + args->code;
         CodeNode *node = new CodeNode;
         node->code = code;
         (yyval.node) = node;
}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 285 "bison.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    count = 0;
    (yyval.node) = node;
}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 290 "bison.y" /* yacc.c:1646  */
    {std::string value = (yyvsp[0].op_val); 
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
        (yyval.node) = node;
}
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 312 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* node = new CodeNode;
    count = 0;
    (yyval.node) = node;
}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 317 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code;
    (yyval.node) = node;
}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 322 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-1].node)->code + (yyvsp[0].node)->code;
    (yyval.node) = node;
}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 329 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* decl = (yyvsp[0].node); 
    std::string code = decl->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 336 "bison.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 337 "bison.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 338 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode;
            ll << loop;
          node->code = std::string(":= endloop") + ll.str() + std::string("\n");
          (yyval.node) = node;
         }
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 343 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode; 
            node->code = (yyvsp[-1].node)->code;
            node->code += std::string(".> ") + (yyvsp[-1].node)->name + std::string("\n");             
            (yyval.node) = node; 
}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 349 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode;
         ll << loop;
         node->code = std::string(":= beginloop") + ll.str() + std::string("\n");
         (yyval.node) = node;
         }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 354 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode; 
            CodeNode* eq = (yyvsp[0].node);
            node->code = eq->code; 
            node->code += std::string("ret ") + eq->name + std::string("\n"); 
            (yyval.node) = node; 
         }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 362 "bison.y" /* yacc.c:1646  */
    {
    (yyval.node) = (yyvsp[0].node);
}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 365 "bison.y" /* yacc.c:1646  */
    {
            (yyval.node) = (yyvsp[0].node);
}
#line 1752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 369 "bison.y" /* yacc.c:1646  */
    {
        std::string value = (yyvsp[0].op_val); 
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
        (yyval.node) = node;
}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 386 "bison.y" /* yacc.c:1646  */
    {
        std::string value = (yyvsp[-2].op_val); 
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
        CodeNode* eq = (yyvsp[0].node);

        if(ifArray){
            node->code = std::string("=[] ") + value + std::string(", ") + eq->code + std::string("\n");
            ifArray = false;
        }
        else {
            node->code += eq->code;
            node->code += std::string("= ") + value + std::string(", ") + eq->name + std::string("\n");
        }
        (yyval.node) = node;
}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 416 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-3].op_val);
        CodeNode* n = (yyvsp[-1].node); 
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
        std::string code = std::string(".[] ") + name + std::string(", ") + (yyvsp[-1].node)->name  + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        (yyval.node) =node;
}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 438 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-4].op_val);
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
        (yyval.node) = node;
}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 463 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-2].op_val);
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
        CodeNode* eq = (yyvsp[0].node);
        node->code = eq->code;
        if(ifFunc){
            node->code += name + std::string("\n");
            ifFunc = false;
        }
        else if(ifArray){
            node->code = eq->code;
            node->code += std::string("= ") + name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
            ifArray = false;
        }
        else{
            node->code += std::string("= ")+ name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
        }
        (yyval.node) = node;
}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 493 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            CodeNode* eq = (yyvsp[0].node);
            node->code = eq->code;
            node->code += std::string("[]= ") + (yyvsp[-2].node)->code + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
            (yyval.node) = node;
}
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 501 "bison.y" /* yacc.c:1646  */
    {
            std::string name = (yyvsp[-4].op_val);
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
            (yyval.node) = node;
}
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 520 "bison.y" /* yacc.c:1646  */
    {
    std::string name = (yyvsp[-3].op_val);
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

    CodeNode* fac = (yyvsp[-1].node);
    node->code = fac->code;
    node->code += name + std::string(", ") + fac->name;
    (yyval.node) = node;
}
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 544 "bison.y" /* yacc.c:1646  */
    {
    std::string temp = create_temp();
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code + decl_temp_code(temp);
    node->code += (yyvsp[-1].node)->code + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
    node->name = temp;

    (yyval.node) = node;
}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 553 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        node->code = (yyvsp[0].node)->code;
        node->name = (yyvsp[0].node)->name;
        (yyval.node) = node;
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 560 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("+ "); (yyval.node) = node;}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 561 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("- "); (yyval.node) = node;}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 562 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("== "); (yyval.node) = node;}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 563 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string(">= "); (yyval.node) = node;}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 564 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("<= "); (yyval.node) = node;}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 565 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("!= "); (yyval.node) = node;}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 566 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("> "); (yyval.node) = node;}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 567 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("< "); (yyval.node) = node;}
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 570 "bison.y" /* yacc.c:1646  */
    {
    std::string temp = create_temp();
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code +  decl_temp_code(temp);
    node->code += (yyvsp[-1].node)->code + temp + std::string(", ") + (yyvsp[-2].node)->name + std::string(", ") + (yyvsp[0].node)->name + std::string("\n");
    node->name = temp;
    (yyval.node) = node;
}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 578 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[0].node)->code;
    node->name = (yyvsp[0].node)->name;
    (yyval.node) = node;
}
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 586 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("* "); (yyval.node) = node;}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 587 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("/ "); (yyval.node) = node;}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 588 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("% "); (yyval.node) = node;}
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 589 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("&& "); (yyval.node) = node;}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 590 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("|| "); (yyval.node) = node;}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 593 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* eq = (yyvsp[-1].node);
    CodeNode *node = new CodeNode;
    node->code = eq->code;
    node->name = (yyvsp[-1].node)->name;
    (yyval.node) = node;
}
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 600 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 602 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode; 
        node->name = (yyvsp[0].op_val); 
        std::string error;
        if (!find(node->name)) {
            error = std::string("UNKNOWN VARIABLE\n");
            yyerror(error.c_str());
        }
        if(isArray(node->name)){
            error = std::string("variable is an array and is missing array index");
            yyerror(error.c_str());
        }
        (yyval.node) = node;
}
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 616 "bison.y" /* yacc.c:1646  */
    {//CodeNode* node = new CodeNode; node->name = $1; if(atoi($1) < 0){leZero = true;} else{leZero = false;} $$ = node;
        std::string temp = create_temp(); CodeNode* node = new CodeNode; if(atoi((yyvsp[0].op_val)) < 0){ leZero = true; int ssd = -atoi((yyvsp[0].op_val));std::ostringstream ss;
        ss << ssd; node->code = decl_temp_code(temp) + std::string("- ") + temp + std::string(", 0, ") + ss.str() + std::string("\n"); node->name = temp;} else{ leZero = false; node->name = (yyvsp[0].op_val);} (yyval.node) = node;
      }
#line 2136 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 620 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode; node->code = (yyvsp[0].node)->code;
        node->name = (yyvsp[0].node)->name;
        (yyval.node) = node;
      }
#line 2146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 626 "bison.y" /* yacc.c:1646  */
    {
        std::string temp = create_temp();
        
        ifArray = true;
        CodeNode* node = new CodeNode;
        node->code = decl_temp_code(temp);
        node->code += std::string("=[] ") +temp +std::string(" , ") + (yyvsp[0].node)->code + std::string("\n");
        node->name = temp;
        (yyval.node) = node;

      }
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 638 "bison.y" /* yacc.c:1646  */
    {
    std::string name = (yyvsp[-3].op_val);
    std::string error;
    if (!f_function(name)) {
        error = std::string("Undefined function");
        yyerror(error.c_str());
    }

    ifFunc = true;
    CodeNode* node = new CodeNode;
    node->name = (yyvsp[-3].op_val);
    node->code = (yyvsp[-1].node)->code;
    node->code += std::string("call ") + name + std::string(", ") + varName;
    (yyval.node) = node;

}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 655 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            node->code = (yyvsp[0].node)->code + std::string("\n");
            (yyval.node) = node;
        
        }
#line 2194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 661 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            node->code = (yyvsp[-2].node)->code + std::string("\n") + (yyvsp[0].node)->code;
            (yyval.node) = node;

        }
#line 2205 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 667 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 2211 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 670 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        std::string name = (yyvsp[0].op_val);
        node->name = name;
        node->code = std::string("param ") + name;
        std::string error;
        if (!find(node->name)) {
            error = std::string("UNKNOWN VARIABLE\n");
            yyerror(error.c_str());
        }
        (yyval.node) = node;
}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 682 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        std::string num = (yyvsp[0].op_val);
        node->code = std::string("param ") + num;
        (yyval.node) = node;
}
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 690 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << ifcount;

        node->code += (yyvsp[-5].node)->code;
        node->code += std::string("?:= if_true") + ll.str() + std::string(", ") + (yyvsp[-5].node)->name + std::string("\n");
        node->code += (yyvsp[0].node)->name;

        //If body code
        node->code += std::string(": if_true") + ll.str() + std::string("\n");
        node->code += (yyvsp[-2].node)->code;
        node->code += std::string(":= endif") + ll.str() + std::string("\n");

        node->code += (yyvsp[0].node)->code;
        //End of conditional branches
        node->code += std::string(": endif") + ll.str() + std::string("\n");
        ifcount++;
        (yyval.node) = node;
}
#line 2264 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 712 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << ifcount;
        
        node->name = std::string(":= elseif_start") + ll.str() + std::string("\n");
        node->code = std::string(": elseif_start") + ll.str() + std::string("\n");
        node->code += (yyvsp[-5].node)->code;
        node->code += std::string("?:= elseif_true") + ll.str() + std::string(", ") + (yyvsp[-5].node)->name + std::string("\n");
        node->code += (yyvsp[0].node)->name;

        //If body code
        node->code += std::string(": elseif_true") + ll.str() + std::string("\n");
        node->code += (yyvsp[-2].node)->code;
        node->code += std::string(":= end_elseif") + ll.str() + std::string("\n");

        node->code += (yyvsp[0].node)->code;
        //End of conditional branches
        node->code += std::string(": end_elseif") + ll.str() + std::string("\n");
        ifcount++;
        (yyval.node) = node;
}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 734 "bison.y" /* yacc.c:1646  */
    {
                (yyval.node) = (yyvsp[0].node);
}
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 738 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode;
            std::ostringstream ll;
            ll.str("");
            ll << ifcount;
            node->name = std::string(":= endif") + ll.str() + std::string("\n");
            //ifcount++;
            (yyval.node) = node;
          }
#line 2313 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 747 "bison.y" /* yacc.c:1646  */
    {
            std::ostringstream ll;
            ll.str("");
            ll << ifcount;
            CodeNode* node = new CodeNode;
            node->name = std::string(":= else") + ll.str() + std::string("\n");
            node->code += std::string(": else") + ll.str() + std::string("\n");
            node->code += (yyvsp[-1].node)->code;
            (yyval.node) = node;
          }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 758 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode;
        std::ostringstream ll;
        ll << loop;
        node->code = std::string(": beginloop") +  ll.str() + std::string("\n");
        node->code += (yyvsp[-4].node)->code;
        node->code += std::string("?:= bodyloop") + ll.str() + std::string(", ") + (yyvsp[-4].node)->name + std::string("\n");
        node->code += std::string(":= endloop") + ll.str() + std::string("\n");
        node->code += std::string(": bodyloop") + ll.str() + std::string("\n");
        node->code += (yyvsp[-1].node)->code + std::string(":= beginloop") + ll.str() + std::string("\n");
        node->code += std::string(": endloop") + ll.str() + std::string("\n");
        loop++;
        (yyval.node) = node;
}
#line 2347 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2351 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 774 "bison.y" /* yacc.c:1906  */

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
