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

    enum Type { Integer, Array };

    struct Symbol {
        std::string name;
        Type type;
    };

    struct Function {
        std::string name;
        std::vector<Symbol> declarations;
    };

std::string create_temp() {
    static int num = 0;
    std::string value = "_temp" + num;
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
    

#line 174 "y.tab.c" /* yacc.c:339  */

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
    DOT = 292,
    NUMBER = 293,
    IDENTIFIER = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 109 "bison.y" /* yacc.c:355  */

  char *op_val;
  struct CodeNode *node;

#line 259 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   151,   151,   159,   168,   174,   188,   195,   202,   210,
     214,   223,   228,   234,   242,   250,   251,   252,   253,   258,
     259,   266,   270,   275,   285,   296,   306,   324,   330,   345,
     357,   364,   373,   382,   384,   385,   386,   387,   388,   389,
     390,   391,   394,   404,   413,   416,   417,   418,   419,   420,
     423,   431,   432,   433,   434,   435,   442,   445,   446,   447,
     450,   460,   463,   467,   468,   471,   472,   475
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
  "DOT", "NUMBER", "IDENTIFIER", "$accept", "prog_start", "functions",
  "function", "function_ident", "arguments", "argument", "statements",
  "statement", "nonsemicolonstatement", "declaration", "assignment",
  "arraycall", "equations", "equationsp", "addop", "term", "termp",
  "mulop", "factor", "function_call", "params", "param", "if_start",
  "branch_check", "else_check", "until_loop", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -53

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-53)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,     9,    17,   -53,     4,    -9,   -53,   -53,   -53,    12,
      21,    -5,    16,    18,   -53,    42,    21,    15,   -53,    24,
      29,    31,    49,   -53,   -53,    50,    28,    35,    52,    39,
      15,   -53,   -53,    67,   -53,   -53,   -53,    71,    65,    28,
      28,    28,   -53,    28,   -53,     5,   -53,   -53,    68,     0,
     -53,    23,   -18,   -18,   -53,    15,   -53,    28,    26,    28,
      53,    73,    74,    69,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,    28,   -53,   -53,   -53,   -53,   -53,   -53,
      28,    76,   -53,   -53,   -53,    77,    63,    78,   -53,   -53,
      80,   -53,    79,    86,    88,   -53,   -53,    68,     0,    87,
     -53,   -18,   -53,    89,   -53,    15,    15,   -53,   -53,   -53,
     -53,   -53,    93,    94,    33,   -53,    96,    95,   -53,   -53,
      15,    28,    97,    98,   -53,    99,    15,   101,    82,   -53
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
       0,     0,    51,     0,    53,    52,    55,    20,    33,    44,
      54,     0,    59,    59,     5,    11,    13,     0,     0,     0,
       0,     0,     0,     0,    34,    35,    36,    37,    38,    39,
      40,    41,    31,     0,    45,    46,    47,    48,    49,    42,
       0,     0,    27,    61,    60,     0,    57,     0,    12,    28,
       0,    24,     0,     0,     0,    18,    50,    33,    44,     0,
      56,    59,    30,     0,    25,    11,    11,    32,    43,    29,
      58,    26,     0,     0,    65,    67,     0,     0,    62,    64,
      11,     0,     0,     0,    66,     0,    11,     0,    65,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   114,   -53,   -53,   105,   -53,   -27,   -53,   -53,
     -53,   -53,   -17,   -35,    25,   -53,    51,    27,   -53,   -47,
     -15,   -52,   -53,   -53,   -53,    -2,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     9,    12,    13,    28,    29,    30,
      31,    32,    46,    47,    72,    73,    48,    79,    80,    49,
      50,    85,    86,    35,   118,   119,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    87,    34,    56,    60,    61,    62,     1,    63,    74,
      75,    76,    92,    33,     5,    34,    82,     6,    19,    20,
      83,    84,    89,    91,    11,    52,    42,    53,    88,    42,
       8,    42,    10,    98,    14,    77,    78,    15,    33,    21,
      34,    51,    22,    23,    24,    43,    25,    26,    43,   110,
      43,    39,    16,    81,    27,    52,    90,    53,   116,   117,
      17,    44,    45,    37,    44,    45,    44,    45,    38,    40,
      41,    54,    55,    57,    93,    64,    65,    58,   112,   113,
      66,    67,    68,    69,    70,    71,   123,    59,    33,    33,
      34,    34,    96,   122,    94,    95,    99,   101,   100,   127,
     103,   102,   104,    33,   105,    34,   106,   116,   109,    33,
     111,    34,   114,   115,   120,   121,   124,   126,     7,   125,
     128,    18,   107,     0,    97,   108,   129
};

static const yytype_int16 yycheck[] =
{
      17,    53,    17,    30,    39,    40,    41,     3,    43,     9,
      10,    11,    59,    30,     5,    30,    51,     0,     3,     4,
      38,    39,    57,    58,     3,    20,     3,    22,    55,     3,
      39,     3,    20,    80,    39,    35,    36,    21,    55,    24,
      55,     6,    27,    28,    29,    22,    31,    32,    22,   101,
      22,    20,    34,    30,    39,    20,    30,    22,    25,    26,
      18,    38,    39,    39,    38,    39,    38,    39,    39,    20,
      20,    19,    33,     6,    21,     7,     8,     6,   105,   106,
      12,    13,    14,    15,    16,    17,   121,    22,   105,   106,
     105,   106,    23,   120,    21,    21,    20,    34,    21,   126,
      20,    23,    23,   120,    18,   120,    18,    25,    21,   126,
      21,   126,    19,    19,    18,    20,    19,    18,     4,    21,
      19,    16,    97,    -1,    73,    98,   128
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    41,    42,    43,     5,     0,    42,    39,    44,
      20,     3,    45,    46,    39,    21,    34,    18,    45,     3,
       4,    24,    27,    28,    29,    31,    32,    39,    47,    48,
      49,    50,    51,    52,    60,    63,    66,    39,    39,    20,
      20,    20,     3,    22,    38,    39,    52,    53,    56,    59,
      60,     6,    20,    22,    19,    33,    47,     6,     6,    22,
      53,    53,    53,    53,     7,     8,    12,    13,    14,    15,
      16,    17,    54,    55,     9,    10,    11,    35,    36,    57,
      58,    30,    53,    38,    39,    61,    62,    61,    47,    53,
      30,    53,    59,    21,    21,    21,    23,    56,    59,    20,
      21,    34,    23,    20,    23,    18,    18,    54,    57,    21,
      61,    21,    47,    47,    19,    19,    25,    26,    64,    65,
      18,    20,    47,    53,    19,    21,    18,    47,    19,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    45,    45,    46,
      46,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    50,    50,    51,    51,    51,
      52,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    56,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    61,
      62,    62,    63,    64,    64,    65,    65,    66
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     9,     1,     1,     3,     0,
       2,     0,     3,     2,     1,     1,     1,     1,     4,     1,
       2,     1,     1,     2,     4,     5,     6,     3,     3,     5,
       4,     2,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     0,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     4,     1,     3,     0,
       1,     1,     8,     8,     1,     0,     4,     7
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
#line 151 "bison.y" /* yacc.c:1646  */
    { // this happens last
    printf("prog_start -> functions\n");
    CodeNode* node = (yyvsp[0].node); // $1 means the leftmost of the rhs of the grammar
    std::string code = node->code;
    printf("\ngenerated code:\n");
    printf("%s\n", code.c_str());
}
#line 1445 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 159 "bison.y" /* yacc.c:1646  */
    {
    printf("prog_start -> function functions\n");
    CodeNode* func = (yyvsp[-1].node);
    CodeNode* funcs = (yyvsp[0].node);
    std::string code = func->code + funcs->code;
    CodeNode* node = new CodeNode;
    node->code = code;
    (yyval.node) = node;
    }
#line 1459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 168 "bison.y" /* yacc.c:1646  */
    {
            CodeNode *node = new CodeNode;
            (yyval.node) = node;
    }
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 174 "bison.y" /* yacc.c:1646  */
    {
            printf("function -> INTEGER FUNCTION function_ident BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");
            std::string func_name = (yyvsp[-6].op_val);
            CodeNode* param = (yyvsp[-4].node);
            CodeNode* body = (yyvsp[-1].node);
            std::string code = std::string("func ") + func_name + std::string("\n");
            code += param->code;
            code += body->code;
            code +=std::string("endfunc\n");
            CodeNode *node = new CodeNode;
            node->code = code;
            (yyval.node) = node;
    }
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 188 "bison.y" /* yacc.c:1646  */
    {
    // add the function to the symbol table.
    std::string func_name = (yyvsp[0].op_val);
    add_function_to_symbol_table(func_name);
    (yyval.op_val) = (yyvsp[0].op_val);
}
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 195 "bison.y" /* yacc.c:1646  */
    { 
        CodeNode* arg = (yyvsp[0].node);
        std::string code = arg->code;
        CodeNode *node = new CodeNode;
        node->code = code;
        (yyval.node) = node;
}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 202 "bison.y" /* yacc.c:1646  */
    { CodeNode*  arg = (yyvsp[-2].node);
         CodeNode* args = (yyvsp[0].node);
         std::string code = arg->code + args->code;
         CodeNode *node = new CodeNode;
         node->code = code;
         (yyval.node) = node;
}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 210 "bison.y" /* yacc.c:1646  */
    {
    CodeNode *node = new CodeNode;
    (yyval.node) = node;
}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "bison.y" /* yacc.c:1646  */
    {std::string value = (yyvsp[0].op_val); 
        Type t = Integer;
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        (yyval.node) = node;
}
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 223 "bison.y" /* yacc.c:1646  */
    {
    printf("statements -> epsilon\n");
    CodeNode* node = new CodeNode;
    (yyval.node) = node;
}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 228 "bison.y" /* yacc.c:1646  */
    {
    printf("statements -> statement SEMICOLON statements\n");
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-2].node)->code + (yyvsp[0].node)->code;
    (yyval.node) = node;
}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 234 "bison.y" /* yacc.c:1646  */
    {
    printf("statements -> nonsemicolonstatement statements\n");
    CodeNode* node = new CodeNode;
    node->code = (yyvsp[-1].node)->code + (yyvsp[0].node)->code;
    (yyval.node) = node;
}
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 242 "bison.y" /* yacc.c:1646  */
    {
    printf("statement -> declaration\n");
    CodeNode* decl = (yyvsp[0].node); 
    std::string code = decl->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 250 "bison.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 251 "bison.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 252 "bison.y" /* yacc.c:1646  */
    {}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 253 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode; 
            node->code = std::string(". > ") + (yyvsp[-1].node)->code + std::string("\n"); 
            (yyval.node) = node; 
}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 258 "bison.y" /* yacc.c:1646  */
    {printf("statement -> CONTINUE\n");}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 259 "bison.y" /* yacc.c:1646  */
    {
            CodeNode* node = new CodeNode; 
            node->code = std::string("ret ") + (yyvsp[0].node)->code + std::string("\n"); 
            (yyval.node) = node; 
}
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 266 "bison.y" /* yacc.c:1646  */
    {
    printf("nonsemicolonstatement -> if_start\n");
    (yyval.node) = (yyvsp[0].node);
}
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 270 "bison.y" /* yacc.c:1646  */
    {
            printf("nonsemicolonstatement -> until_loop\n");
            (yyval.node) = (yyvsp[0].node);
}
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 275 "bison.y" /* yacc.c:1646  */
    {
        printf("declaration -> INTEGER IDENTIFIER\n");
        std::string value = (yyvsp[0].op_val); 
        Type t = Integer;
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        (yyval.node) = node;
}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 285 "bison.y" /* yacc.c:1646  */
    {
        printf("declaration -> INTEGER IDENTIFIER ASSIGN equations\n");
        std::string value = (yyvsp[-2].op_val); 
        Type t = Integer;
        add_variable_to_symbol_table(value, t);
        std::string code = std::string(". ") + value + std::string("\n");
        code += std::string("= ") + value + (yyvsp[0].node)->code;
        CodeNode* node = new CodeNode;
        node->code = code;
        (yyval.node) = node;
}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 296 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-3].op_val);
        CodeNode* n = (yyvsp[-1].node); 
        Type t = Integer;
        add_variable_to_symbol_table(name, t);
        std::string code = std::string(".[] ") + name + std::string(", ") + n->code  + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;
        (yyval.node) =node;
}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 306 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-4].op_val);
        //std::string error;
        //if (!find(name, Integer, error)) {
        //    yyerror(error.c_str());
        //}

        Type t = Integer;
        add_variable_to_symbol_table(name, t);
        std::string code = std::string(". ") + name + std::string("\n");
        CodeNode* node = new CodeNode;
        node->code = code;

        node->code += std::string(".< ") + name + std::string("\n");
        (yyval.node) = node;
}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 324 "bison.y" /* yacc.c:1646  */
    {
        std::string name = (yyvsp[-2].op_val);
        CodeNode* node = new CodeNode;
        node->code = std::string("= ") + name + std::string(", ") + (yyvsp[0].node)->code + std::string("\n");
        (yyval.node) = node;
}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 330 "bison.y" /* yacc.c:1646  */
    {
            
            printf("arraycall ASSIGN equations\n");
            CodeNode* node = new CodeNode;
            node->code = std::string("[]= ") + (yyvsp[-2].node)->code + std::string(", ") + (yyvsp[0].node)->code + std::string("\n");
            
            /*
            std::string temp = create_temp();
            CodeNode *node = new CodeNode;
            node->code = $3->code + decl_temp_code(temp);
            node->code += std::string("[]= ") + temp + std::string(", ") + std::string("\n");
            node->name = temp;
            */
            (yyval.node) = node;
}
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 345 "bison.y" /* yacc.c:1646  */
    {
            std::string name = (yyvsp[-4].op_val);
            //std::string error;
            //if (!find(name, Integer, error)) {
            //    yyerror(error.c_str());
            //}

            CodeNode* node = new CodeNode;
            node->code = std::string(".< ") + name + std::string("\n");
            (yyval.node) = node;
}
#line 1764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 357 "bison.y" /* yacc.c:1646  */
    {
    std::string name = (yyvsp[-3].op_val);
    CodeNode* node = new CodeNode;
    node->code = name + std::string(", ") + (yyvsp[-1].node)->code;
    (yyval.node) = node;
}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 364 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* t = (yyvsp[-1].node); 
    CodeNode* eqp = (yyvsp[0].node); 
    std::string code = t->code + eqp->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 373 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* op = (yyvsp[-2].node);
    CodeNode* t = (yyvsp[-1].node); 
    CodeNode* eqp = (yyvsp[0].node); 
    std::string code = op->code + t->code + eqp->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 382 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 384 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("+ "); (yyval.node) = node;}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 385 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("- "); (yyval.node) = node;}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 386 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("+ "); (yyval.node) = node;}
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 387 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string(">= "); (yyval.node) = node;}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 388 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("<= "); (yyval.node) = node;}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 389 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("!= "); (yyval.node) = node;}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 390 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("> "); (yyval.node) = node;}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 391 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("< "); (yyval.node) = node;}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 394 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* fact = (yyvsp[-1].node); 
    CodeNode* tp = (yyvsp[0].node); 
    std::string code = fact->code + tp->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 404 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* op = (yyvsp[-2].node); 
    CodeNode* fct = (yyvsp[-1].node); 
    CodeNode* tp = (yyvsp[0].node); 
    std::string code = op->code + fct->code + tp->code; 
    CodeNode* node = new CodeNode; 
    node->code = code; 
    (yyval.node) = node;
}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 413 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 416 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("* "); (yyval.node) = node;}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 417 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("/ "); (yyval.node) = node;}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 418 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("% "); (yyval.node) = node;}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 419 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("&& "); (yyval.node) = node;}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 420 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = std::string("|| "); (yyval.node) = node;}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 423 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* eq = (yyvsp[-1].node);
    std::string code = std::string("(") + eq->code + std::string(")");

    CodeNode *node = new CodeNode;
    node->code = code;
    (yyval.node) = node;
}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 431 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 432 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = (yyvsp[0].op_val); (yyval.node) = node;}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 433 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = (yyvsp[0].op_val); (yyval.node) = node;}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 434 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = (yyvsp[0].node)->code; (yyval.node) = node;}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 435 "bison.y" /* yacc.c:1646  */
    {
        CodeNode* node = new CodeNode; node->code = (yyvsp[0].node)->code; 
        (yyval.node) = node;  
      }
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 442 "bison.y" /* yacc.c:1646  */
    {}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 445 "bison.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 446 "bison.y" /* yacc.c:1646  */
    {printf("params-> param COMMA params\n");}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 447 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 1989 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 450 "bison.y" /* yacc.c:1646  */
    {
    CodeNode* node = new CodeNode;
    node->code = "";
    node->name = (yyvsp[0].op_val);
    std::string error;
    //if (!find(node->name, Integer, error)) {
    //    yyerror(error.c_str());
    //}
    (yyval.node) = node;
}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 460 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; node->code = (yyvsp[0].op_val); (yyval.node) = node;}
#line 2010 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 463 "bison.y" /* yacc.c:1646  */
    {printf("if_start -> IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY branch_check\n");}
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 467 "bison.y" /* yacc.c:1646  */
    {printf("branch_check -> ELSE_IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 468 "bison.y" /* yacc.c:1646  */
    {printf("branch_check -> else_check\n");}
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 471 "bison.y" /* yacc.c:1646  */
    {CodeNode* node = new CodeNode; (yyval.node) = node;}
#line 2034 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 472 "bison.y" /* yacc.c:1646  */
    {printf("else_check -> ELSE BEGIN_BODY statements END_BODY\n");}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 475 "bison.y" /* yacc.c:1646  */
    {printf("until_loop -> WHILE BEGIN_PARAM equations END_PARAM BEGIN_BODY statements END_BODY\n");}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2050 "y.tab.c" /* yacc.c:1646  */
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
#line 479 "bison.y" /* yacc.c:1906  */

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
