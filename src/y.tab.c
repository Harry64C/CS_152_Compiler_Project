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
    #include <stdlib.h>

    extern int yylex();
    extern int yyparse();
    extern FILE* yyin;

    void yyerror(const char* s);

#line 77 "y.tab.c" /* yacc.c:339  */

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
    NUMBER = 290,
    IDENTIFIER = 291,
    AND = 292,
    OR = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 167 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   116

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
static const yytype_uint8 yyrline[] =
{
       0,    16,    16,    17,    19,    20,    22,    24,    25,    27,
      28,    30,    31,    33,    34,    35,    36,    37,    39,    40,
      43,    46,    48,    49,    51,    52,    54,    57,    58,    60,
      61,    62,    64,    65,    66,    67,    70,    72,    73,    74,
      76,    77,    80,    83,    84,    87,    88,    91,    92,    94,
      95,    98,    99,   102,   103,   104,   107,   108,   109,   110,
     111,   112,   115,   116,   117,   120,   121,   124
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
  "CONTINUE", "READ", "WRITE", "RETURN", "SEMICOLON", "COMMA", "NUMBER",
  "IDENTIFIER", "AND", "OR", "$accept", "prog_start", "functions",
  "function", "arguments", "argument", "statements", "statement",
  "declaration", "assignment", "equations", "equationsp", "addop", "term",
  "termp", "mulop", "factor", "function_call", "params", "param",
  "if_start", "if_check", "if_checkp", "boolop", "fin", "compare", "finp",
  "compop", "branch_check", "else_check", "until_loop", YY_NULLPTR
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

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      18,    -7,    54,   -76,    18,    40,   -76,   -76,    58,    26,
      44,    30,   -76,    48,    58,     0,   -76,    31,    49,    50,
      -2,    52,    39,   -76,   -76,   -76,   -76,   -76,    67,     3,
       3,     4,     5,   -76,     0,     4,   -76,     6,    55,   -76,
      68,    -3,    66,    69,   -76,     4,    55,   -76,    43,    22,
     -76,   -76,   -76,    70,    42,   -76,   -76,     7,    65,    32,
      74,   -76,   -76,   -76,     6,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,     7,    75,    71,   -76,   -76,   -76,     4,   -76,
     -76,   -76,   -76,     4,   -76,     5,    72,    -3,    66,     0,
      -3,    66,     0,   -76,    43,    22,   -76,   -76,   -76,    77,
     -76,   -76,    78,   -76,   -76,    27,   -76,    79,    80,   -76,
     -76,     3,     3,    83,    84,    88,    89,     0,     0,    82,
      90,    73,    73,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     3,     4,     0,     1,     5,     9,     0,
       0,     7,    10,     0,     9,    11,     8,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,    18,     0,
       0,     0,    37,     6,    11,     0,    53,     0,    54,    55,
       0,    45,    51,     0,    33,     0,    34,    20,    23,    28,
      35,    41,    40,     0,    38,    12,    19,     0,     0,     0,
       0,    47,    48,    43,     0,    56,    57,    58,    59,    60,
      61,    49,     0,     0,     0,    24,    25,    21,     0,    29,
      30,    31,    26,     0,    36,    37,     0,    45,    51,    11,
      45,    51,    11,    32,    23,    28,    39,    44,    50,     0,
      46,    52,     0,    22,    27,    62,    67,     0,     0,    42,
      64,     0,     0,     0,     0,     0,     0,    11,    11,     0,
       0,    65,    65,    66,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   104,   -76,    96,   -76,   -33,   -76,   -76,   -76,
     -22,    17,   -76,    34,    19,   -76,    33,   -15,    28,   -76,
     -76,   -25,   -75,   -76,   -26,   -74,   -35,   -76,   -76,   -64,
     -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    21,    22,    23,    24,
      47,    77,    78,    48,    82,    83,    49,    39,    53,    54,
      26,    40,    63,    64,    41,    71,    42,    72,   109,   110,
      27
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    55,    59,    17,    31,    43,    36,    44,    51,    36,
      36,    58,    97,    56,    98,   100,    50,   101,    32,    25,
      50,     1,    86,    74,    18,    37,    45,    19,    57,     5,
      50,    79,    80,    81,    61,    62,    20,    91,    90,    38,
      46,    52,    38,    38,    65,    66,    67,    68,    69,    70,
      75,    76,   107,   108,     6,    88,    99,   123,   124,   102,
       8,     9,    12,    50,    14,    13,    15,    28,    50,    29,
      30,    33,    34,    35,    25,    32,    85,    25,    65,    66,
      67,    68,    69,    70,   119,   120,   113,   114,    87,    60,
      73,    84,    89,    92,    93,    88,   105,   106,   107,   111,
     112,   121,    25,    25,   115,   116,   117,   118,     7,   122,
      16,   103,    94,    96,   104,     0,    95
};

static const yytype_int8 yycheck[] =
{
      15,    34,    37,     3,     6,    30,     3,     3,     3,     3,
       3,    37,    87,    35,    88,    90,    31,    91,    20,    34,
      35,     3,    57,    45,    24,    22,    22,    27,    22,    36,
      45,     9,    10,    11,    37,    38,    36,    72,    64,    36,
      36,    36,    36,    36,    12,    13,    14,    15,    16,    17,
       7,     8,    25,    26,     0,    23,    89,   121,   122,    92,
      20,     3,    36,    78,    34,    21,    18,    36,    83,    20,
      20,    19,    33,     6,    89,    20,    34,    92,    12,    13,
      14,    15,    16,    17,   117,   118,   111,   112,    23,    21,
      21,    21,    18,    18,    23,    23,    19,    19,    25,    20,
      20,    19,   117,   118,    21,    21,    18,    18,     4,    19,
      14,    94,    78,    85,    95,    -1,    83
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    40,    41,    42,    36,     0,    41,    20,     3,
      43,    44,    36,    21,    34,    18,    43,     3,    24,    27,
      36,    45,    46,    47,    48,    56,    59,    69,    36,    20,
      20,     6,    20,    19,    33,     6,     3,    22,    36,    56,
      60,    63,    65,    60,     3,    22,    36,    49,    52,    55,
      56,     3,    36,    57,    58,    45,    49,    22,    63,    65,
      21,    37,    38,    61,    62,    12,    13,    14,    15,    16,
      17,    64,    66,    21,    49,     7,     8,    50,    51,     9,
      10,    11,    53,    54,    21,    34,    65,    23,    23,    18,
      63,    65,    18,    23,    52,    55,    57,    61,    64,    45,
      61,    64,    45,    50,    53,    19,    19,    25,    26,    67,
      68,    20,    20,    60,    60,    21,    21,    18,    18,    45,
      45,    19,    19,    68,    68
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    42,    43,    43,    44,
      44,    45,    45,    46,    46,    46,    46,    46,    47,    47,
      48,    49,    50,    50,    51,    51,    52,    53,    53,    54,
      54,    54,    55,    55,    55,    55,    56,    57,    57,    57,
      58,    58,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     0,     2,     8,     1,     3,     0,
       2,     0,     3,     1,     1,     1,     1,     1,     2,     4,
       3,     2,     3,     0,     1,     1,     2,     3,     0,     1,
       1,     1,     3,     1,     1,     1,     4,     0,     1,     3,
       1,     1,     8,     2,     4,     0,     3,     1,     1,     2,
       4,     0,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     8,     1,     0,     8,     7
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
#line 16 "bison.y" /* yacc.c:1646  */
    {printf("prog_start->epsilon\n");}
#line 1330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 17 "bison.y" /* yacc.c:1646  */
    {printf("prog_start->functions\n");}
#line 1336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 19 "bison.y" /* yacc.c:1646  */
    {printf("functions->epsilon\n");}
#line 1342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 20 "bison.y" /* yacc.c:1646  */
    {printf("functions-> function functions\n");}
#line 1348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 22 "bison.y" /* yacc.c:1646  */
    {printf("function->INTEGER IDENTIFIER BEGIN_PARAM arguments END_PARAM BEGIN_BODY statements END_BODY\n");}
#line 1354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 24 "bison.y" /* yacc.c:1646  */
    {printf("arguments->arugment\n");}
#line 1360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 25 "bison.y" /* yacc.c:1646  */
    {printf("arguments ->argument arguments\n");}
#line 1366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 27 "bison.y" /* yacc.c:1646  */
    {printf("argument->epsilon\n");}
#line 1372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 28 "bison.y" /* yacc.c:1646  */
    {printf("argument-> INTEGER IDENTIFIER\n");}
#line 1378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 30 "bison.y" /* yacc.c:1646  */
    {printf("statements->epsilon\n");}
#line 1384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 31 "bison.y" /* yacc.c:1646  */
    {printf("statements->statement SEMICOLON statements\n");}
#line 1390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 33 "bison.y" /* yacc.c:1646  */
    {printf("statement->declaration\n");}
#line 1396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 34 "bison.y" /* yacc.c:1646  */
    {printf("statement->assignment\n");}
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 35 "bison.y" /* yacc.c:1646  */
    {printf("statement->function_call\n");}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 36 "bison.y" /* yacc.c:1646  */
    {printf("statement->if_start\n");}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 37 "bison.y" /* yacc.c:1646  */
    {printf("statement->until_loop\n");}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 39 "bison.y" /* yacc.c:1646  */
    {printf("declaration-> INTEGER IDENTIFIER\n");}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 40 "bison.y" /* yacc.c:1646  */
    {printf("declaration ->INTEGER IDENTIFIER ASSIGN equations\n");}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 43 "bison.y" /* yacc.c:1646  */
    {printf("IDENTIFIER ASSIGN equations\n");}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 46 "bison.y" /* yacc.c:1646  */
    {printf("equations->term equationsp\n");}
#line 1444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 48 "bison.y" /* yacc.c:1646  */
    {printf("equationsp->addop term equationsp\n");}
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 49 "bison.y" /* yacc.c:1646  */
    {printf("equationsp->epsilon\n");}
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 51 "bison.y" /* yacc.c:1646  */
    {printf("addop -> ADD\n");}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 52 "bison.y" /* yacc.c:1646  */
    {printf("addop->SUBTRACT\n");}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 54 "bison.y" /* yacc.c:1646  */
    {printf("term->factor termp\n");}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 57 "bison.y" /* yacc.c:1646  */
    {printf("termp->mulop factor termp\n");}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 58 "bison.y" /* yacc.c:1646  */
    {printf("termp ->epsilon\n");}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 60 "bison.y" /* yacc.c:1646  */
    {printf("mulop->MULTIPLY\n");}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 61 "bison.y" /* yacc.c:1646  */
    {printf("mulop->DIVISION\n");}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 62 "bison.y" /* yacc.c:1646  */
    {printf("mulop->MOD\n");}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 64 "bison.y" /* yacc.c:1646  */
    {printf("factor->L_PAREN equations R_PAREN");}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 65 "bison.y" /* yacc.c:1646  */
    {printf("factor ->INT\n");}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 66 "bison.y" /* yacc.c:1646  */
    {printf("factor->IDENTIFIER\n");}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 67 "bison.y" /* yacc.c:1646  */
    {printf("factor->function_call\n");}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 70 "bison.y" /* yacc.c:1646  */
    {printf("function_call->IDENTIFIER BEGIN_PARAM params END_PARAM\n");}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 72 "bison.y" /* yacc.c:1646  */
    {printf("params->epsilon\n");}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 73 "bison.y" /* yacc.c:1646  */
    {printf("params->param\n");}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 74 "bison.y" /* yacc.c:1646  */
    {printf("params-> param COMMA params\n");}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 76 "bison.y" /* yacc.c:1646  */
    {printf("param->IDENTIFIER\n");}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 77 "bison.y" /* yacc.c:1646  */
    {printf("param->INTEGER\n");}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 80 "bison.y" /* yacc.c:1646  */
    {printf("if_start->IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY branch_check\n");}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 83 "bison.y" /* yacc.c:1646  */
    {printf("if_check->fin if_checkp\n");}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 84 "bison.y" /* yacc.c:1646  */
    {printf("if_check-> L_PAREN fin R_PAREN if_checkp\n");}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 87 "bison.y" /* yacc.c:1646  */
    {printf("if_checkp->epsilon\n");}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 88 "bison.y" /* yacc.c:1646  */
    {printf("if_checkp->boolep fin if_checkp\n");}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 91 "bison.y" /* yacc.c:1646  */
    {printf("boolop->AND\n");}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 92 "bison.y" /* yacc.c:1646  */
    {printf("boolop->OR\n");}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 94 "bison.y" /* yacc.c:1646  */
    {printf("fin->finp compare\n");}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 95 "bison.y" /* yacc.c:1646  */
    {printf("fin->L_PAREN finp R_PAREN compare\n");}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 98 "bison.y" /* yacc.c:1646  */
    {printf("empty->epsilon\n");}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 99 "bison.y" /* yacc.c:1646  */
    {printf("compare->compop finp compare\n");}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 102 "bison.y" /* yacc.c:1646  */
    {printf("finp->INTEGER\n");}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 103 "bison.y" /* yacc.c:1646  */
    {printf("finp->IDENTIFIER\n");}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 104 "bison.y" /* yacc.c:1646  */
    {printf("finp->function_call\n");}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 107 "bison.y" /* yacc.c:1646  */
    {printf("compop->EQ\n");}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 108 "bison.y" /* yacc.c:1646  */
    {printf("compop->GTE\n");}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 109 "bison.y" /* yacc.c:1646  */
    {printf("compop->LTE\n");}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 110 "bison.y" /* yacc.c:1646  */
    {printf("compop->NEQ\n");}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 111 "bison.y" /* yacc.c:1646  */
    {printf("compop->GT\n");}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 112 "bison.y" /* yacc.c:1646  */
    {printf("compop->LT\n");}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 115 "bison.y" /* yacc.c:1646  */
    {printf("branch_check->epsilon\n");}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 116 "bison.y" /* yacc.c:1646  */
    {printf("branch_check->ELSE_IF BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 117 "bison.y" /* yacc.c:1646  */
    {printf("branch_check->else_check\n");}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 120 "bison.y" /* yacc.c:1646  */
    {printf("else_check->epsilon\n");}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 121 "bison.y" /* yacc.c:1646  */
    {printf("else_check->ELSE BEGIN_BODY if_check END_PARAM BEGIN_BODY statements END_BODY else_check\n");}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 124 "bison.y" /* yacc.c:1646  */
    {printf("until_loop->WHILE BEGIN_PARAM if_check END_PARAM BEGIN_BODY statements END_BODY\n");}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1724 "y.tab.c" /* yacc.c:1646  */
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
#line 127 "bison.y" /* yacc.c:1906  */

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
