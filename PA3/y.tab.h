/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    TINTEGER = 258,
    TREAL = 259,
    TIDENTIFIER = 260,
    TINT = 261,
    TFLOAT = 262,
    TCHAR = 263,
    STRING = 264,
    TBREAK = 265,
    TCASE = 266,
    TDEFAULT = 267,
    TDO = 268,
    TFOR = 269,
    TRETURN = 270,
    TWHILE = 271,
    TIF = 272,
    TELSE = 273,
    TSWITCH = 274,
    TVOID = 275,
    PLUSEQUAL = 276,
    MINUSEQUAL = 277,
    TIMESEQUAL = 278,
    DIVEQUAL = 279,
    MODEQUAL = 280,
    LOGICALOR = 281,
    LOGICALAND = 282,
    LESS = 283,
    GREAT = 284,
    LESSEQUAL = 285,
    GREATEREQUAL = 286,
    EQUALEQUAL = 287,
    NOTEQUAL = 288,
    PLUSPLUS = 289,
    MINUSMINUS = 290,
    PLUS = 291,
    MINUS = 292,
    TIMES = 293,
    DIV = 294,
    MOD = 295,
    EQUAL = 296,
    LEFT_PAREN = 297,
    RIGHT_PAREN = 298,
    SEMICOLON = 299,
    LEFT_BRACE = 300,
    RIGHT_BRACE = 301,
    LEFT_BRACKET = 302,
    RIGHT_BRACKET = 303,
    COLON = 304,
    COMMA = 305,
    TERROR = 306,
    TCOMMENT = 307
  };
#endif
/* Tokens.  */
#define TINTEGER 258
#define TREAL 259
#define TIDENTIFIER 260
#define TINT 261
#define TFLOAT 262
#define TCHAR 263
#define STRING 264
#define TBREAK 265
#define TCASE 266
#define TDEFAULT 267
#define TDO 268
#define TFOR 269
#define TRETURN 270
#define TWHILE 271
#define TIF 272
#define TELSE 273
#define TSWITCH 274
#define TVOID 275
#define PLUSEQUAL 276
#define MINUSEQUAL 277
#define TIMESEQUAL 278
#define DIVEQUAL 279
#define MODEQUAL 280
#define LOGICALOR 281
#define LOGICALAND 282
#define LESS 283
#define GREAT 284
#define LESSEQUAL 285
#define GREATEREQUAL 286
#define EQUALEQUAL 287
#define NOTEQUAL 288
#define PLUSPLUS 289
#define MINUSMINUS 290
#define PLUS 291
#define MINUS 292
#define TIMES 293
#define DIV 294
#define MOD 295
#define EQUAL 296
#define LEFT_PAREN 297
#define RIGHT_PAREN 298
#define SEMICOLON 299
#define LEFT_BRACE 300
#define RIGHT_BRACE 301
#define LEFT_BRACKET 302
#define RIGHT_BRACKET 303
#define COLON 304
#define COMMA 305
#define TERROR 306
#define TCOMMENT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

        int iVal;
        float rVal;
        char* sVal;

#line 167 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
