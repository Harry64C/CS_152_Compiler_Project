/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 175 "bison.y" /* yacc.c:1909  */

  char *op_val;
  struct CodeNode *node;

#line 98 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
