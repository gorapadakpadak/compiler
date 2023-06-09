/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

        #include "ast.h"
        #include <stdio.h>
        #include <stdlib.h>
        STACK *stack;
        int yylex(void);
        int yyerror(char* s);
        int inLoop=0;
        int inSwitch=0;
        int inFunction=0;
        int rError=0;
        int bError=0;
        int isReturn=0;
        int isBreak=0;

#line 86 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 248 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   207

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

#define YYUNDEFTOK  2
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    48,    53,    55,    56,    64,    73,    81,
      91,   100,   105,   108,   112,   117,   119,   126,   133,   141,
     145,   152,   155,   159,   164,   166,   172,   176,   185,   189,
     190,   192,   193,   201,   209,   217,   218,   219,   226,   234,
     242,   250,   258,   264,   272,   281,   289,   298,   304,   312,
     325,   338,   354,   359,   363,   364,   366,   372,   378,   384,
     390,   396,   403,   409,   413,   419,   421,   427,   429,   435,
     441,   447,   453,   459,   465,   467,   473,   479,   481,   487,
     493,   499,   501,   502,   503,   504,   505,   510,   516,   523,
     526,   530,   533,   538,   546,   554,   562,   572,   582,   589,
     594,   598,   603
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TINTEGER", "TREAL", "TIDENTIFIER",
  "TINT", "TFLOAT", "TCHAR", "STRING", "TBREAK", "TCASE", "TDEFAULT",
  "TDO", "TFOR", "TRETURN", "TWHILE", "TIF", "TELSE", "TSWITCH", "TVOID",
  "PLUSEQUAL", "MINUSEQUAL", "TIMESEQUAL", "DIVEQUAL", "MODEQUAL",
  "LOGICALOR", "LOGICALAND", "LESS", "GREAT", "LESSEQUAL", "GREATEREQUAL",
  "EQUALEQUAL", "NOTEQUAL", "PLUSPLUS", "MINUSMINUS", "PLUS", "MINUS",
  "TIMES", "DIV", "MOD", "EQUAL", "LEFT_PAREN", "RIGHT_PAREN", "SEMICOLON",
  "LEFT_BRACE", "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "COLON",
  "COMMA", "TERROR", "TCOMMENT", "$accept", "Program", "DecList", "Dec",
  "FuncDec", "Params", "ParamList", "Param", "CpndStmt", "LDecList",
  "VarDec", "VarType", "IDs", "Value", "StmtList", "Stmt", "MatchedStmt",
  "OpenStmt", "SwitchStmt", "CaseList", "DefaultCase", "ReturnStmt",
  "BreakStmt", "ExprStmt", "Expr", "AssignExpr", "Variable", "SimpleExpr",
  "AndExpr", "RelExpr", "AddExpr", "Term", "Factor", "NumberLiteral",
  "IncDec", "WhileMatchedStmt", "WhileOpenStmt", "DoWhileStmt",
  "ForMatchedStmt", "ForOpenStmt", "FuncCall", "Arguments", "ArgumentList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

#define YYPACT_NINF (-156)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,  -156,  -156,    -1,     6,     5,  -156,  -156,  -156,     9,
      43,  -156,  -156,   -24,   -31,  -156,    10,    10,    35,  -156,
      90,  -156,    57,    -2,  -156,    90,    60,    65,    73,  -156,
      -4,    14,  -156,    27,  -156,  -156,  -156,  -156,  -156,  -156,
    -156,    14,  -156,    90,    77,  -156,  -156,   -18,    85,   121,
      88,    42,    91,    97,    99,  -156,  -156,   112,   112,  -156,
    -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,  -156,    98,
    -156,   146,   106,   116,   144,    38,    69,  -156,  -156,   139,
    -156,  -156,  -156,  -156,  -156,  -156,   112,   112,  -156,   129,
     112,  -156,   104,   112,   112,   112,    54,  -156,   107,  -156,
     112,   112,   112,   112,   112,   112,  -156,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   112,   112,
     105,  -156,  -156,   108,   103,   109,   117,   118,  -156,   135,
     136,   140,  -156,  -156,  -156,  -156,  -156,  -156,  -156,   116,
     144,    38,    38,    38,    38,    38,    38,    69,    69,  -156,
    -156,  -156,  -156,   112,  -156,   112,   112,   121,   121,   115,
    -156,   141,   120,  -156,  -156,  -156,   143,   171,   142,   112,
     121,   182,    86,  -156,   151,  -156,  -156,   147,   192,   148,
     152,   121,  -156,   150,  -156,  -156,  -156,  -156,   121,  -156,
     121,   121
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    21,    22,     0,     0,     2,     4,     6,     5,     0,
       0,     1,     3,    26,     0,    24,    13,    13,     0,    20,
       0,    12,     0,    11,    15,     0,     0,     0,    26,    23,
       0,     0,    16,     0,    25,    10,    19,     9,    14,     8,
       7,    28,    18,     0,     0,    89,    90,    63,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,    53,
      17,    36,    27,    29,    30,    38,    35,    37,    31,     0,
      54,    84,    55,    65,    67,    74,    77,    81,    85,     0,
      33,    41,    34,    32,    40,    83,   100,     0,    51,     0,
       0,    50,     0,     0,     0,     0,    84,    86,     0,    52,
       0,     0,     0,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      63,    88,   102,     0,    99,     0,     0,     0,    49,     0,
       0,     0,    82,    57,    58,    59,    60,    61,    56,    64,
      66,    68,    70,    69,    71,    72,    73,    75,    76,    78,
      79,    80,    98,     0,    62,     0,     0,     0,     0,     0,
     101,     0,     0,    93,    94,    42,    29,     0,     0,     0,
       0,     0,    48,    95,     0,    39,    43,     0,     0,     0,
       0,     0,    28,     0,    28,    44,    96,    97,    46,    28,
      47,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -156,  -156,  -156,   195,  -156,   184,  -156,   172,     1,  -156,
     161,    32,  -156,    58,   -83,   -48,  -148,  -155,  -156,  -156,
    -156,  -156,  -156,  -156,   -51,  -156,   -52,  -156,   100,    96,
      79,    12,   -49,  -156,   -68,  -156,  -156,  -156,  -156,  -156,
    -156,  -156,  -156
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    22,    23,    24,    61,    41,
       8,    25,    14,    15,    44,    62,    63,    64,    65,   172,
     180,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   123,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      92,    89,   164,   106,    10,    96,    11,    98,    97,   163,
     166,     1,     2,    19,    13,   176,     1,     2,    17,    20,
       1,     2,   175,    18,    86,     3,   187,   121,   106,    87,
      21,    37,     9,   186,    40,   122,   125,     9,    27,   127,
      35,    36,   129,   130,   131,    45,    46,    47,    31,   133,
     134,   135,   136,   137,   138,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,   149,   150,
     151,    39,    36,    43,   115,   116,    55,    56,    29,    57,
      45,    46,    47,    32,    58,    16,    91,    48,    55,    56,
      49,    50,    51,    52,    53,    28,    54,   178,   179,   188,
      30,   190,   160,    33,   161,   162,   191,   117,   118,   119,
     165,    55,    56,    34,    57,    45,    46,    47,   174,    58,
      18,    59,    36,    60,    45,    46,    47,   147,   148,    88,
      90,    48,   107,    93,    49,    50,    51,    52,    53,    94,
      54,    95,    99,   108,   120,   126,    55,    56,   128,    57,
     132,   152,    87,   153,    58,    55,    56,   154,    57,   155,
     167,   170,   156,    58,   169,    59,    36,   100,   101,   102,
     103,   104,   109,   110,   111,   112,   113,   114,   157,   158,
      55,    56,   171,   159,   168,   177,   173,   105,   141,   142,
     143,   144,   145,   146,   181,   183,   182,   184,   185,   189,
      12,    26,    42,    38,   140,     0,     0,   139
};

static const yytype_int16 yycheck[] =
{
      51,    49,   157,    71,     5,    57,     0,    58,    57,   157,
     158,     6,     7,    44,     5,   170,     6,     7,    42,    50,
       6,     7,   170,    47,    42,    20,   181,    79,    96,    47,
      20,    30,     0,   181,    33,    86,    87,     5,     3,    90,
      44,    45,    93,    94,    95,     3,     4,     5,    50,   100,
     101,   102,   103,   104,   105,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   117,   118,
     119,    44,    45,    41,    36,    37,    34,    35,    20,    37,
       3,     4,     5,    25,    42,    42,    44,    10,    34,    35,
      13,    14,    15,    16,    17,     5,    19,    11,    12,   182,
      43,   184,   153,    43,   155,   156,   189,    38,    39,    40,
     158,    34,    35,    48,    37,     3,     4,     5,   169,    42,
      47,    44,    45,    46,     3,     4,     5,   115,   116,    44,
      42,    10,    26,    42,    13,    14,    15,    16,    17,    42,
      19,    42,    44,    27,     5,    16,    34,    35,    44,    37,
      43,    43,    47,    50,    42,    34,    35,    48,    37,    42,
      45,    18,    44,    42,    44,    44,    45,    21,    22,    23,
      24,    25,    28,    29,    30,    31,    32,    33,    43,    43,
      34,    35,    11,    43,    43,     3,    44,    41,   109,   110,
     111,   112,   113,   114,    43,     3,    49,    49,    46,    49,
       5,    17,    41,    31,   108,    -1,    -1,   107
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,     7,    20,    54,    55,    56,    57,    63,    64,
       5,     0,    56,     5,    65,    66,    42,    42,    47,    44,
      50,    20,    58,    59,    60,    64,    58,     3,     5,    66,
      43,    50,    66,    43,    48,    44,    45,    61,    60,    44,
      61,    62,    63,    64,    67,     3,     4,     5,    10,    13,
      14,    15,    16,    17,    19,    34,    35,    37,    42,    44,
      46,    61,    68,    69,    70,    71,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    42,    47,    44,    68,
      42,    44,    77,    42,    42,    42,    79,    85,    77,    44,
      21,    22,    23,    24,    25,    41,    87,    26,    27,    28,
      29,    30,    31,    32,    33,    36,    37,    38,    39,    40,
       5,    79,    77,    94,    95,    77,    16,    77,    44,    77,
      77,    77,    43,    77,    77,    77,    77,    77,    77,    81,
      82,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      85,    85,    43,    50,    48,    42,    44,    43,    43,    43,
      77,    77,    77,    69,    70,    68,    69,    45,    43,    44,
      18,    11,    72,    44,    77,    69,    70,     3,    11,    12,
      73,    43,    49,     3,    49,    46,    69,    70,    67,    49,
      67,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      70,    70,    70,    70,    71,    72,    72,    73,    73,    74,
      74,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80,    81,    81,    82,    82,
      82,    82,    82,    82,    82,    83,    83,    83,    84,    84,
      84,    84,    85,    85,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    89,    90,    91,    92,    93,    94,
      94,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     6,     6,     6,
       6,     1,     1,     0,     3,     1,     2,     4,     2,     0,
       3,     1,     1,     3,     1,     4,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     7,
       1,     1,     5,     7,     8,     5,     4,     3,     0,     3,
       2,     2,     2,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     4,     1,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     3,     1,     1,     1,     2,     2,     2,     1,
       1,     1,     1,     5,     5,     7,     9,     9,     4,     1,
       0,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 43 "parser.y"
                {
        ASTNode* DecList=pop(stack);
        ASTNode* programNode = makeASTNode(_PROG);
        push(stack,setChild(programNode, DecList));
}
#line 1573 "y.tab.c"
    break;

  case 3:
#line 48 "parser.y"
                        {
        ASTNode* Dec=pop(stack);
        ASTNode* DecList=pop(stack);
        push(stack,setLastSibling(DecList,Dec));
}
#line 1583 "y.tab.c"
    break;

  case 6:
#line 56 "parser.y"
         {
        inFunction=1;
        if (isReturn==1) {
                if(inFunction==0)
                        rError=1;
        }
}
#line 1595 "y.tab.c"
    break;

  case 7:
#line 64 "parser.y"
                                                                      {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNodeID((yyvsp[-4].sVal));
        ASTNode* CpndStmt = pop(stack);
        ASTNode* Params = pop(stack);
        ASTNode* Type = pop(stack);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type,setSibling(ID,setSibling(Params, CpndStmt)))));
}
#line 1609 "y.tab.c"
    break;

  case 8:
#line 73 "parser.y"
                                                                    {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* Params = pop(stack);
        ASTNode* ID=makeASTNodeID((yyvsp[-4].sVal));
        ASTNode* Type = pop(stack);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type, setSibling(ID, Params))));
}
#line 1622 "y.tab.c"
    break;

  case 9:
#line 81 "parser.y"
                                                               {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNodeID((yyvsp[-4].sVal));
        ASTNode* CpndStmt = pop(stack);
        ASTNode* Params = pop(stack);
        ASTNode* Type = makeASTNodeTYPE(TYPE_VOID);
        inFunction=1;
	push(stack,setChild(FuncDec,setSibling(Type, setSibling(ID, setSibling(Params, CpndStmt)))));

}
#line 1637 "y.tab.c"
    break;

  case 10:
#line 91 "parser.y"
                                                                    {
        ASTNode* FuncDec=makeASTNode(_FUNCDEC);
        ASTNode* ID=makeASTNode(_ID);
        ASTNode* Params = pop(stack);
        ASTNode* Type = makeASTNodeTYPE(TYPE_VOID);
        inFunction=1;
	push(stack,setChild(FuncDec, setSibling(Type,setSibling(ID, Params) )));
	}
#line 1650 "y.tab.c"
    break;

  case 11:
#line 100 "parser.y"
                        {
        ASTNode* Params=makeASTNode(_PARAMS);
        ASTNode* ParamList=pop(stack);
        push(stack,setChild(Params, ParamList));
	}
#line 1660 "y.tab.c"
    break;

  case 12:
#line 105 "parser.y"
         {
	push(stack,makeASTNode(_PARAMS));
	}
#line 1668 "y.tab.c"
    break;

  case 13:
#line 108 "parser.y"
        {
	push(stack,makeASTNode(_PARAMS));
	}
#line 1676 "y.tab.c"
    break;

  case 14:
#line 112 "parser.y"
                                    {
        ASTNode* newParam=pop(stack);
        ASTNode* ParamList=pop(stack);
        push(stack,setLastSibling(ParamList,newParam));
}
#line 1686 "y.tab.c"
    break;

  case 16:
#line 119 "parser.y"
                        {
        ASTNode* Param=makeASTNode(_PARAM);
        ASTNode* Value=pop(stack);
        ASTNode* Type=pop(stack);
        push(stack,setChild(Param,setSibling(Type,Value)));
}
#line 1697 "y.tab.c"
    break;

  case 17:
#line 126 "parser.y"
                                                          {
        ASTNode* CpndStmt=makeASTNode(_CPNDSTMT);
        ASTNode* StmtList=pop(stack);
	ASTNode* LDecList=pop(stack);
        push(stack, setChild(CpndStmt,setSibling(LDecList,StmtList)));
}
#line 1708 "y.tab.c"
    break;

  case 18:
#line 133 "parser.y"
                                 {
        ASTNode* VarDec=pop(stack);
        ASTNode* LDecList=pop(stack);
        if(getChild(LDecList)==NULL){
		push(stack,setChild(LDecList,VarDec));
	}
	else{push(stack,setLastSibling(LDecList,VarDec));}
}
#line 1721 "y.tab.c"
    break;

  case 19:
#line 141 "parser.y"
         {
        push(stack,makeASTNode(_LDECLIST));
}
#line 1729 "y.tab.c"
    break;

  case 20:
#line 145 "parser.y"
                                {
        ASTNode* VarDec=makeASTNode(_VARDEC);
        ASTNode* IDs=pop(stack);
        ASTNode* Type=pop(stack);
        push(stack,setChild(VarDec,setSibling(Type,IDs)));
}
#line 1740 "y.tab.c"
    break;

  case 21:
#line 152 "parser.y"
                  {
       push(stack,makeASTNodeTYPE(TYPE_INT));
}
#line 1748 "y.tab.c"
    break;

  case 22:
#line 155 "parser.y"
          {
	push(stack,makeASTNodeTYPE(TYPE_FLOAT));
}
#line 1756 "y.tab.c"
    break;

  case 23:
#line 159 "parser.y"
                     {
        ASTNode* Value=pop(stack);
        ASTNode* IDs=pop(stack);
        push(stack,setLastSibling(IDs,Value));
}
#line 1766 "y.tab.c"
    break;

  case 25:
#line 166 "parser.y"
                                                       {
        ASTNode* Array=makeASTNode(_ARRAY);
        ASTNode* ID=makeASTNodeID((yyvsp[-3].sVal));
        ASTNode* INTEGER=makeASTNodeINT((yyvsp[-1].iVal));
        push(stack,setChild(Array,setSibling(ID,INTEGER)));
}
#line 1777 "y.tab.c"
    break;

  case 26:
#line 172 "parser.y"
                 {
        push(stack,makeASTNodeID((yyvsp[0].sVal)));
	}
#line 1785 "y.tab.c"
    break;

  case 27:
#line 176 "parser.y"
                         {
        ASTNode* Stmt=pop(stack);
        ASTNode* StmtList=pop(stack);
	if(getChild(StmtList)==NULL){
		push(stack,setChild(StmtList,Stmt));
	}else{
        	push(stack,setLastSibling(StmtList,Stmt));
	}
}
#line 1799 "y.tab.c"
    break;

  case 28:
#line 185 "parser.y"
         {
        push(stack,makeASTNode(_STMTLIST));
	}
#line 1807 "y.tab.c"
    break;

  case 32:
#line 193 "parser.y"
                        { 
        inLoop=1;
         if(isBreak==1){
                if (!inLoop) {
                        bError=1;
                }
        }
}
#line 1820 "y.tab.c"
    break;

  case 33:
#line 201 "parser.y"
                        {
        inLoop=1;
         if(isBreak==1){
                if (!inLoop) {
                        bError=1;
                }
        }
}
#line 1833 "y.tab.c"
    break;

  case 34:
#line 209 "parser.y"
                {
        inLoop=1;
        if(isBreak==1){
                if (!inLoop) {
                        bError=1;
                }
        }
}
#line 1846 "y.tab.c"
    break;

  case 37:
#line 219 "parser.y"
                {
        if(isBreak==1){
                if (!inSwitch&&!inLoop) {
                        bError=1;
                }
        }
}
#line 1858 "y.tab.c"
    break;

  case 38:
#line 226 "parser.y"
                {
         if(isBreak==1){
                if (!inSwitch) {
                        bError=1;
                }
        }
        inSwitch=1;
}
#line 1871 "y.tab.c"
    break;

  case 39:
#line 234 "parser.y"
                                                                        {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* Stmt2=pop(stack);
        ASTNode* Stmt1=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,setSibling(Stmt1,Stmt2))));
}
#line 1883 "y.tab.c"
    break;

  case 40:
#line 242 "parser.y"
                       {
        if(isBreak==1){
                if (!inLoop) {
                        bError=1;
                }
        }
        inLoop=1;
}
#line 1896 "y.tab.c"
    break;

  case 41:
#line 250 "parser.y"
                {
         if(isBreak==1){
                if (!inLoop) {
                        bError=1;
                }
        }
        inLoop=1;
}
#line 1909 "y.tab.c"
    break;

  case 42:
#line 258 "parser.y"
                                        {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,Stmt)));
}
#line 1920 "y.tab.c"
    break;

  case 43:
#line 264 "parser.y"
                                                                 {
        ASTNode* IfStmt=makeASTNode(_IFSTMT);
        ASTNode* OStmt=pop(stack);
        ASTNode* MStmt=pop(stack);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(IfStmt,setSibling(Expr,setSibling(MStmt,OStmt))));
}
#line 1932 "y.tab.c"
    break;

  case 44:
#line 272 "parser.y"
                                                                                             {
        ASTNode* SwitchStmt=makeASTNode(_SWSTMT);
        ASTNode* Default=pop(stack);
        ASTNode* Case=pop(stack);
        ASTNode* Expr=pop(stack);
        inSwitch=1;
	push(stack,setChild(SwitchStmt,setSibling(Expr,setLastSibling(Case,Default))));
}
#line 1945 "y.tab.c"
    break;

  case 45:
#line 281 "parser.y"
                                                     {
        ASTNode* StmtList=pop(stack);
        ASTNode* CaseList=pop(stack);
        ASTNode* Case=makeASTNode(_CASE);
        ASTNode* Integer=makeASTNodeINT((yyvsp[-2].iVal));
	inSwitch=1;
       	push(stack,setLastSibling(CaseList,setChild(Case,setSibling(Integer,StmtList))));
}
#line 1958 "y.tab.c"
    break;

  case 46:
#line 289 "parser.y"
                                     {
        ASTNode* Case=makeASTNode(_CASE);
        ASTNode* Integer=makeASTNodeINT((yyvsp[-2].iVal));
        ASTNode* StmtList=pop(stack);
	inSwitch=1;

        push(stack,setChild(Case,setSibling(Integer,StmtList)));
}
#line 1971 "y.tab.c"
    break;

  case 47:
#line 298 "parser.y"
                                     {
        ASTNode* Default=makeASTNode(_DEFAULT);
        ASTNode* StmtList=pop(stack);
        push(stack,setChild(Default,StmtList));
	inSwitch=1;
}
#line 1982 "y.tab.c"
    break;

  case 48:
#line 304 "parser.y"
         {
        push(stack,makeASTNode(_DEFAULT));
	inSwitch=1;
}
#line 1991 "y.tab.c"
    break;

  case 49:
#line 312 "parser.y"
                                        {
        ASTNode* RTStmt=makeASTNode(_RTSTMT);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(RTStmt,Expr));
        isReturn=1;
        if(rError){
                yyerror("[return] error occured!!");
                isReturn=0;
                inFunction=0;
        }
        
	
}
#line 2009 "y.tab.c"
    break;

  case 50:
#line 325 "parser.y"
                        {
        push(stack,makeASTNode(_RTSTMT));
        isReturn=1;
        if(rError){
                yyerror("[return] error occured!!");
                isReturn=0;
                inFunction=0;
        }
        

	
}
#line 2026 "y.tab.c"
    break;

  case 51:
#line 338 "parser.y"
                                 {
	push(stack,makeASTNode(_BRKSTMT));
	isBreak=1;
        if(bError){
                yyerror("[break] error occured!!");
                isBreak=0;
                inSwitch=0;
                inLoop=0;

        }

}
#line 2043 "y.tab.c"
    break;

  case 52:
#line 354 "parser.y"
                        {
        ASTNode* ExprStmt=makeASTNode(_EXPRSTMT);
        ASTNode* Expr=pop(stack);
        push(stack,setChild(ExprStmt,Expr));
}
#line 2053 "y.tab.c"
    break;

  case 53:
#line 359 "parser.y"
                {
        push(stack,makeASTNode(_EXPRSTMT));
}
#line 2061 "y.tab.c"
    break;

  case 56:
#line 366 "parser.y"
                                     {
        ASTNode* Assign=makeASTNodeOP(ASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(Assign,setSibling(Variable,Expr)));
}
#line 2072 "y.tab.c"
    break;

  case 57:
#line 372 "parser.y"
                                {
        ASTNode* AddAssign=makeASTNodeOP(ADDASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(AddAssign,setSibling(Variable,Expr)));
}
#line 2083 "y.tab.c"
    break;

  case 58:
#line 378 "parser.y"
                                 {
        ASTNode* SubAssign=makeASTNodeOP(SUBASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(SubAssign,setSibling(Variable,Expr)));
}
#line 2094 "y.tab.c"
    break;

  case 59:
#line 384 "parser.y"
                               {
        ASTNode* MultAssign=makeASTNodeOP(MULTASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(MultAssign,setSibling(Variable,Expr)));
}
#line 2105 "y.tab.c"
    break;

  case 60:
#line 390 "parser.y"
                             {
        ASTNode* DivAssign=makeASTNodeOP(DIVASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(DivAssign,setSibling(Variable,Expr)));
}
#line 2116 "y.tab.c"
    break;

  case 61:
#line 396 "parser.y"
                             {
        ASTNode* ModAssign=makeASTNodeOP(MODASSIGN_);
        ASTNode* Expr=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(ModAssign,setSibling(Variable,Expr)));
}
#line 2127 "y.tab.c"
    break;

  case 62:
#line 403 "parser.y"
                                                       {
        ASTNode* Array=makeASTNode(_ARRAY);
        ASTNode* ID=makeASTNodeID((yyvsp[-3].sVal));
        ASTNode* Expr=pop(stack);
        push(stack,setChild(Array,setSibling(ID,Expr)));
}
#line 2138 "y.tab.c"
    break;

  case 63:
#line 409 "parser.y"
                 {
        push(stack,makeASTNodeID((yyvsp[0].sVal)));
}
#line 2146 "y.tab.c"
    break;

  case 64:
#line 413 "parser.y"
                                                {
        ASTNode* Or=makeASTNodeOP(OR_);
        ASTNode* AndExpr=pop(stack);
        ASTNode* SimpleExpr=pop(stack);
        push(stack,setChild(Or,setSibling(SimpleExpr,AndExpr)));
}
#line 2157 "y.tab.c"
    break;

  case 66:
#line 421 "parser.y"
                                       {
        ASTNode* And=makeASTNodeOP(AND_);
        ASTNode* RelExpr=pop(stack);
        ASTNode* AndExpr=pop(stack);
        push(stack,setChild(And,setSibling(AndExpr,RelExpr)));
}
#line 2168 "y.tab.c"
    break;

  case 68:
#line 429 "parser.y"
                                  {
        ASTNode* LT=makeASTNodeOP(LT_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(LT,setSibling(RelExpr,AddExpr)));
}
#line 2179 "y.tab.c"
    break;

  case 69:
#line 435 "parser.y"
                              {
        ASTNode* LE=makeASTNodeOP(LE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(LE,setSibling(RelExpr,AddExpr)));
}
#line 2190 "y.tab.c"
    break;

  case 70:
#line 441 "parser.y"
                           {
        ASTNode* GT=makeASTNodeOP(GT_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(GT,setSibling(RelExpr,AddExpr)));
}
#line 2201 "y.tab.c"
    break;

  case 71:
#line 447 "parser.y"
                                        {
        ASTNode* GE=makeASTNodeOP(GE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(GE,setSibling(RelExpr,AddExpr)));
}
#line 2212 "y.tab.c"
    break;

  case 72:
#line 453 "parser.y"
                               {
        ASTNode* EQ=makeASTNodeOP(EQ_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(EQ,setSibling(RelExpr,AddExpr)));
}
#line 2223 "y.tab.c"
    break;

  case 73:
#line 459 "parser.y"
                             {
        ASTNode* NE=makeASTNodeOP(NE_);
        ASTNode* AddExpr=pop(stack);
        ASTNode* RelExpr=pop(stack);
        push(stack,setChild(NE,setSibling(RelExpr,AddExpr)));
}
#line 2234 "y.tab.c"
    break;

  case 75:
#line 467 "parser.y"
                                  {
        ASTNode* Plus=makeASTNodeOP(PLUS_);
        ASTNode* Term=pop(stack);
        ASTNode* AddExpr=pop(stack);
        push(stack,setChild(Plus,setSibling(AddExpr,Term)));
}
#line 2245 "y.tab.c"
    break;

  case 76:
#line 473 "parser.y"
                           {
        ASTNode* Minus=makeASTNodeOP(MINUS_);
        ASTNode* Term=pop(stack);
        ASTNode* AddExpr=pop(stack);
        push(stack,setChild(Minus,setSibling(AddExpr,Term)));
}
#line 2256 "y.tab.c"
    break;

  case 78:
#line 481 "parser.y"
                           {
        ASTNode* MULT=makeASTNodeOP(MULT_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(MULT,setSibling(Term,Factor)));
}
#line 2267 "y.tab.c"
    break;

  case 79:
#line 487 "parser.y"
                         {
        ASTNode* Div=makeASTNodeOP(DIV_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(Div,setSibling(Term,Factor)));
}
#line 2278 "y.tab.c"
    break;

  case 80:
#line 493 "parser.y"
                         {
        ASTNode* Mod=makeASTNodeOP(MOD_);
        ASTNode* Factor=pop(stack);
        ASTNode* Term=pop(stack);
        push(stack,setChild(Mod,setSibling(Term,Factor)));
}
#line 2289 "y.tab.c"
    break;

  case 86:
#line 505 "parser.y"
                {
        ASTNode* Minus=makeASTNodeOP(MINUS_);
        ASTNode* Factor=pop(stack);
        push(stack,setChild(Minus,Factor));
}
#line 2299 "y.tab.c"
    break;

  case 87:
#line 510 "parser.y"
                        {
        ASTNode* IncDecExp=makeASTNode(_INCDECEXP);
        ASTNode* IncDec=pop(stack);
        ASTNode* Variable=pop(stack);
        push(stack,setChild(IncDecExp,setSibling(Variable,IncDec)));
}
#line 2310 "y.tab.c"
    break;

  case 88:
#line 516 "parser.y"
                        {
        ASTNode* IncDecExp=makeASTNode(_INCDECEXP);
        ASTNode* Variable=pop(stack);
        ASTNode* IncDec=pop(stack);
        push(stack,setChild(IncDecExp,setSibling(IncDec,Variable)));
}
#line 2321 "y.tab.c"
    break;

  case 89:
#line 523 "parser.y"
                       {
        push(stack,makeASTNodeINT((yyvsp[0].iVal)));
}
#line 2329 "y.tab.c"
    break;

  case 90:
#line 526 "parser.y"
        {
        push(stack,makeASTNodeREAL((yyvsp[0].rVal)));
}
#line 2337 "y.tab.c"
    break;

  case 91:
#line 530 "parser.y"
                     {
        push(stack,makeASTNodeOP(INC_));
}
#line 2345 "y.tab.c"
    break;

  case 92:
#line 533 "parser.y"
               {
        push(stack,makeASTNodeOP(DEC_));
}
#line 2353 "y.tab.c"
    break;

  case 93:
#line 538 "parser.y"
                                                                        {
        ASTNode* WhileStmt=makeASTNode(_WHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(WhileStmt,setSibling(Expr,Stmt)));
}
#line 2365 "y.tab.c"
    break;

  case 94:
#line 546 "parser.y"
                                                                {
        ASTNode* WhileStmt=makeASTNode(_WHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(WhileStmt,setSibling(Expr,Stmt)));
}
#line 2377 "y.tab.c"
    break;

  case 95:
#line 554 "parser.y"
                                                                      {
        ASTNode* DoWhileStmt=makeASTNode(_DOWHLSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr=pop(stack);
	inLoop=1;
        push(stack,setChild(DoWhileStmt,setSibling(Expr,Stmt)));
}
#line 2389 "y.tab.c"
    break;

  case 96:
#line 562 "parser.y"
                                                                                                    {
        ASTNode* ForStmt=makeASTNode(_FORSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr3=pop(stack);
        ASTNode* Expr2=pop(stack);
        ASTNode* Expr1=pop(stack);
	inLoop=1;
        push(stack,setChild(ForStmt,setSibling(Expr1,setSibling(Expr2,setSibling(Expr3,Stmt)))));
}
#line 2403 "y.tab.c"
    break;

  case 97:
#line 572 "parser.y"
                                                                                              {
        ASTNode* ForStmt=makeASTNode(_FORSTMT);
        ASTNode* Stmt=pop(stack);
        ASTNode* Expr3=pop(stack);
        ASTNode* Expr2=pop(stack);
        ASTNode* Expr1=pop(stack);
        inLoop=1;
        push(stack,setChild(ForStmt,setSibling(Expr1,setSibling(Expr2,setSibling(Expr3,Stmt)))));
}
#line 2417 "y.tab.c"
    break;

  case 98:
#line 582 "parser.y"
                                                                {
        ASTNode* FuncCall=makeASTNode(_FUNCCALL);
        ASTNode* ID=makeASTNodeID((yyvsp[-3].sVal));
        ASTNode* Args=pop(stack);
        push(stack,setChild(FuncCall,setSibling(ID,Args)));
}
#line 2428 "y.tab.c"
    break;

  case 99:
#line 589 "parser.y"
                                 {
        ASTNode* Args=makeASTNode(_ARGS);
        ASTNode* Arg=pop(stack);
        push(stack,setChild(Args,Arg));
}
#line 2438 "y.tab.c"
    break;

  case 100:
#line 594 "parser.y"
         {
        push(stack,makeASTNode(_ARGS));
}
#line 2446 "y.tab.c"
    break;

  case 101:
#line 598 "parser.y"
                                           {
        ASTNode* Arg=pop(stack);
        ASTNode* ArgList=pop(stack);
        push(stack,setLastSibling(ArgList,Arg));
}
#line 2456 "y.tab.c"
    break;


#line 2460 "y.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 605 "parser.y"

int main(int argc, char* argv[]){
        extern FILE *yyin;
        stack = initStack();
        yyin = fopen(argv[1], "r"); yyparse();
        fclose(yyin); printAST(pop(stack)); delStack(stack);
        return 0;
}

int yyerror(char *s){
        printf("Parse error : %s\n", s);
        return 0;
}

