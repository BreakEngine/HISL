
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

void yyerror(char* e);
#include <iostream>
#include <string>
#include <sstream>
#include "NodeFunctions.h"
using namespace Break::HISL;
NodeList* nodes = new NodeList();
int ix =0;
extern int yylex();
extern int yylineno;


/* Line 189 of yacc.c  */
#line 87 "parser.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     TYPE = 259,
     RETURN = 260,
     FLOAT = 261,
     INT = 262,
     BOOLCONST = 263,
     STRING = 264,
     OPEN_BRACE = 265,
     CLOSE_BRACE = 266,
     OPEN_CBRACE = 267,
     CLOSE_CBRACE = 268,
     SEMICOLON = 269,
     NONE = 270,
     EQL = 271,
     COMMA = 272,
     IF = 273,
     ELSE = 274,
     PLUS = 275,
     MINUS = 276,
     MULTIPLY = 277,
     DEVIDE = 278,
     NOT = 279,
     INC = 280,
     DEC = 281,
     PLUS_EQL = 282,
     MINUS_EQL = 283,
     MULTIPLY_EQL = 284,
     DEVIDE_EQL = 285,
     WHILE = 286,
     FOR = 287,
     GREATER = 288,
     LESS = 289,
     EQL_Q = 290,
     NEQL_Q = 291,
     GREATER_EQUAL = 292,
     LESS_EQUAL = 293,
     AND = 294,
     OR = 295,
     AND_Q = 296,
     OR_Q = 297,
     OPEN_SQBRACE = 298,
     CLOSE_SQBRACE = 299,
     STRUCT = 300,
     IOBUFFER = 301,
     COLON = 302,
     VERTEX = 303,
     PIXEL = 304,
     ROUTINE = 305,
     PROGRAM = 306,
     DOT = 307,
     ARROW = 308,
     GLSL = 309,
     HLSL = 310
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 15 "yacc.y"

  int token;
  float real;
  std::string *string;
  Break::HISL::Node *node;
  Break::HISL::NInteger *numInteger;
  Break::HISL::NFloat *numFloat;
  Break::HISL::NIdentifier *ident;
  Break::HISL::NType *ntype;
  Break::HISL::NFunctionCall *func_call;
  Break::HISL::NBinaryOperator *binary_op;
  Break::HISL::NAssignment *assignment;
  Break::HISL::NExpression *expr;
  Break::HISL::NStatement *stmt;
  Break::HISL::NBlock *block;
  Break::HISL::NVariableDeclaration *var_dcl;
  Break::HISL::NFunctionDeclaration *func_dcl;
  Break::HISL::NReturnStatement *ret_stmt;
  Break::HISL::ExpressionList *expr_list;
  Break::HISL::VariableList *var_list;
  Break::HISL::NIfStatement *if_stmt;
  Break::HISL::NMVariableDeclaration *multi_var_dcl;
  Break::HISL::NWhileStatement *while_stmt;
  Break::HISL::NForStatement *for_stmt;
  Break::HISL::NConstantExpression *const_expr;
  Break::HISL::NUnaryOperator *unary_expr;
  Break::HISL::NArrayDeclaration *arr_dcl;
  Break::HISL::NArrayCall *arr_call;
  Break::HISL::NStruct *strct;
  Break::HISL::NIOBuffer *iobfr;
  Break::HISL::NSVariableDeclaration *svar_dcl;
  Break::HISL::NStage *stage;
  Break::HISL::NRoutine *routine;
  Break::HISL::NProgram *gpu_program;
  Break::HISL::NString *my_string;
  Break::HISL::NNative *native;



/* Line 214 of yacc.c  */
#line 218 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 230 "parser.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  79
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   674

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    17,    20,
      22,    24,    27,    30,    33,    36,    39,    42,    47,    52,
      54,    58,    62,    66,    70,    74,    78,    81,    86,    88,
      94,   104,   109,   111,   113,   121,   129,   137,   145,   151,
     157,   165,   173,   179,   185,   187,   190,   193,   197,   201,
     204,   211,   215,   218,   220,   222,   224,   227,   230,   232,
     235,   238,   240,   242,   244,   248,   250,   252,   254,   258,
     261,   264,   267,   269,   274,   279,   282,   286,   288,   290,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     312,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   350,   351,
     353,   357,   358,   360,   364,   365,   367,   371,   374,   379,
     381,   385
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    74,    -1,    78,    -1,    77,    -1,    87,
      -1,    97,    14,    -1,    98,    14,    -1,    68,    14,    -1,
      67,    -1,    70,    -1,    76,    14,    -1,    64,    14,    -1,
      62,    14,    -1,    63,    14,    -1,    61,    14,    -1,    59,
      14,    -1,    54,    12,    60,    13,    -1,    55,    12,    60,
      13,    -1,     9,    -1,    51,    88,    79,    -1,    48,    88,
      79,    -1,    49,    88,    79,    -1,    50,    88,    79,    -1,
      46,    88,    65,    -1,    12,    75,    13,    -1,    12,    13,
      -1,    90,    88,    47,    88,    -1,    71,    -1,    90,    88,
      43,    82,    44,    -1,    90,    88,    43,    82,    44,    16,
      12,    95,    13,    -1,    88,    43,    83,    44,    -1,    73,
      -1,    72,    -1,    18,    10,    83,    11,    79,    19,    79,
      -1,    18,    10,    83,    11,    79,    19,    58,    -1,    18,
      10,    83,    11,    58,    19,    58,    -1,    18,    10,    83,
      11,    58,    19,    79,    -1,    18,    10,    83,    11,    58,
      -1,    18,    10,    83,    11,    79,    -1,    32,    10,    58,
      58,    83,    11,    79,    -1,    32,    10,    58,    58,    83,
      11,    58,    -1,    31,    10,    83,    11,    79,    -1,    31,
      10,    83,    11,    58,    -1,    58,    -1,    74,    58,    -1,
      66,    14,    -1,    75,    66,    14,    -1,    45,    88,    79,
      -1,    83,    14,    -1,    90,    88,    10,    96,    11,    79,
      -1,    12,    74,    13,    -1,    12,    13,    -1,    81,    -1,
      82,    -1,     6,    -1,    21,     6,    -1,    20,     6,    -1,
       7,    -1,    21,     7,    -1,    20,     7,    -1,    93,    -1,
      86,    -1,    89,    -1,    83,    91,    83,    -1,    84,    -1,
      80,    -1,    85,    -1,    10,    83,    11,    -1,    92,    83,
      -1,    83,    25,    -1,    83,    26,    -1,     8,    -1,    88,
      10,    94,    11,    -1,    90,    10,    94,    11,    -1,     5,
      14,    -1,     5,    83,    14,    -1,     3,    -1,     3,    -1,
      69,    -1,     4,    -1,     3,    -1,    20,    -1,    21,    -1,
      22,    -1,    23,    -1,    35,    -1,    36,    -1,    33,    -1,
      34,    -1,    37,    -1,    38,    -1,    27,    -1,    28,    -1,
      29,    -1,    30,    -1,    39,    -1,    40,    -1,    41,    -1,
      42,    -1,    52,    -1,    53,    -1,    25,    -1,    26,    -1,
      22,    -1,    39,    -1,    24,    -1,    89,    16,    83,    -1,
      -1,    83,    -1,    94,    17,    83,    -1,    -1,    83,    -1,
      95,    17,    83,    -1,    -1,    97,    -1,    96,    17,    97,
      -1,    90,    88,    -1,    90,    88,    16,    83,    -1,    97,
      -1,    98,    17,    88,    -1,    98,    17,    88,    16,    83,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   120,   121,   124,
     127,   130,   131,   136,   139,   142,   143,   146,   149,   152,
     153,   155,   158,   159,   162,   163,   164,   165,   166,   167,
     170,   171,   174,   175,   178,   179,   182,   183,   186,   189,
     192,   198,   199,   202,   203,   206,   207,   208,   211,   212,
     213,   216,   217,   218,   219,   220,   221,   222,   223,   226,
     227,   228,   231,   234,   235,   237,   238,   241,   244,   245,
     247,   248,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   270,   273,   274,   275,   276,   277,   280,   282,   283,
     284,   287,   288,   289,   292,   293,   294,   296,   297,   300,
     301,   302
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "TYPE", "RETURN", "FLOAT", "INT",
  "BOOLCONST", "STRING", "OPEN_BRACE", "CLOSE_BRACE", "OPEN_CBRACE",
  "CLOSE_CBRACE", "SEMICOLON", "NONE", "EQL", "COMMA", "IF", "ELSE",
  "PLUS", "MINUS", "MULTIPLY", "DEVIDE", "NOT", "INC", "DEC", "PLUS_EQL",
  "MINUS_EQL", "MULTIPLY_EQL", "DEVIDE_EQL", "WHILE", "FOR", "GREATER",
  "LESS", "EQL_Q", "NEQL_Q", "GREATER_EQUAL", "LESS_EQUAL", "AND", "OR",
  "AND_Q", "OR_Q", "OPEN_SQBRACE", "CLOSE_SQBRACE", "STRUCT", "IOBUFFER",
  "COLON", "VERTEX", "PIXEL", "ROUTINE", "PROGRAM", "DOT", "ARROW", "GLSL",
  "HLSL", "$accept", "program", "stmt", "native", "my_string",
  "gpu_program", "stage", "routine", "iobuffer", "ioblock",
  "semantic_var_dcl", "selection_stmt", "arr_dcl", "arr_call", "loop_stmt",
  "if_stmt", "for_stmt", "while_stmt", "stmts", "iostmts", "strct",
  "expr_stmt", "func_dcl", "block", "numeric", "numFloat", "numInteger",
  "expr", "unary_expr", "const_expr", "func_call", "jump_stmt", "ident",
  "ident_all", "type", "binary_op", "unary_op", "assignment", "call_args",
  "init_list", "func_dcl_args", "var_dcl", "multi_var_dcl", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    59,    59,    60,
      61,    62,    62,    63,    64,    65,    65,    66,    67,    68,
      68,    69,    70,    70,    71,    71,    71,    71,    71,    71,
      72,    72,    73,    73,    74,    74,    75,    75,    76,    77,
      78,    79,    79,    80,    80,    81,    81,    81,    82,    82,
      82,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    85,    86,    86,    87,    87,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    92,    92,    93,    94,    94,
      94,    95,    95,    95,    96,    96,    96,    97,    97,    98,
      98,    98
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     1,
       1,     2,     2,     2,     2,     2,     2,     4,     4,     1,
       3,     3,     3,     3,     3,     3,     2,     4,     1,     5,
       9,     4,     1,     1,     7,     7,     7,     7,     5,     5,
       7,     7,     5,     5,     1,     2,     2,     3,     3,     2,
       6,     3,     2,     1,     1,     1,     2,     2,     1,     2,
       2,     1,     1,     1,     3,     1,     1,     1,     3,     2,
       2,     2,     1,     4,     4,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       3,     0,     1,     3,     0,     1,     3,     2,     4,     1,
       3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    78,    80,     0,    55,    58,    72,     0,     0,     0,
       0,   104,   106,   102,   103,     0,     0,   105,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
       0,     0,     0,     9,     0,    79,    10,    28,    33,    32,
       2,     0,     4,     3,    66,    53,    54,     0,    65,    67,
      62,     5,     0,    63,     0,     0,    61,   119,     0,    75,
       0,     0,     0,     0,    57,    60,    56,    59,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     1,
      16,    15,    13,    14,    12,     8,    45,    11,    49,    82,
      83,    84,    85,    70,    71,    92,    93,    94,    95,    88,
      89,    86,    87,    90,    91,    96,    97,    98,    99,   100,
     101,     0,   108,     0,     0,   108,   117,    69,     6,     7,
       0,    76,    68,     0,     0,     0,     0,    48,     0,    24,
      21,    22,    23,    20,    19,     0,     0,    64,   109,     0,
       0,   107,     0,   114,     0,     0,   120,     0,     0,     0,
      52,     0,    81,    26,     0,     0,     0,    17,    18,    73,
       0,    31,    74,     0,     0,   115,   118,     0,     0,     0,
       0,    38,    39,    43,    42,     0,    51,    46,    25,     0,
       0,   110,   117,     0,     0,    29,   121,     0,     0,     0,
      47,     0,    50,   116,     0,    36,    37,    35,    34,    41,
      40,    27,   111,   112,     0,    30,     0,   113
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,   135,    29,    30,    31,    32,   129,
     154,    33,    34,    35,    36,    37,    38,    39,    40,   155,
      41,    42,    43,   127,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    61,   111,    55,    56,   139,   204,
     164,    57,    58
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -142
static const yytype_int16 yypact[] =
{
     347,     2,  -142,    47,  -142,  -142,  -142,   158,    12,    25,
      41,  -142,  -142,  -142,  -142,    20,    32,  -142,    56,    56,
      56,    56,    56,    56,    52,    64,    77,  -142,    65,    66,
      67,    70,    73,  -142,    74,  -142,  -142,  -142,  -142,  -142,
     347,    75,  -142,  -142,  -142,  -142,  -142,   519,  -142,  -142,
    -142,  -142,    -7,    62,    16,   158,  -142,    76,    49,  -142,
     553,    82,   383,   158,  -142,  -142,  -142,  -142,   158,   347,
    -142,    81,    83,    81,    81,    81,    81,    85,    85,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
    -142,   158,   158,   158,   158,   158,    13,   621,  -142,  -142,
      56,  -142,  -142,   417,   451,   347,   188,  -142,    21,  -142,
    -142,  -142,  -142,  -142,  -142,    72,    84,   621,   621,    22,
     587,   621,    27,    71,   158,     0,    80,   241,   241,   158,
    -142,   294,  -142,  -142,    86,    24,    56,  -142,  -142,  -142,
     158,  -142,  -142,    56,    29,  -142,   621,    91,    92,    57,
     158,    87,    88,  -142,  -142,   485,  -142,  -142,  -142,    89,
      55,   621,   100,    81,    71,   103,   621,   241,   241,   241,
    -142,    56,  -142,  -142,    93,  -142,  -142,  -142,  -142,  -142,
    -142,  -142,   158,   621,    45,  -142,   158,   621
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,   -34,  -142,    26,  -142,  -142,  -142,  -142,  -142,
     -35,  -142,  -142,  -142,  -142,  -142,  -142,  -142,    -1,  -142,
    -142,  -142,  -142,   -65,  -142,  -142,   -24,    -3,  -142,  -142,
    -142,  -142,    -5,  -142,     1,  -142,  -142,  -142,    15,  -142,
    -142,  -141,  -142
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
      60,    54,   165,   112,    62,   -81,    86,     5,   130,   131,
     132,   133,   -77,    71,    72,    73,    74,    75,    76,    70,
     167,   168,    63,   143,   152,     2,   115,   152,     2,   144,
      68,    64,    65,   159,   153,   125,   113,   178,   162,   160,
     183,    54,    69,   193,   160,   -77,   184,    66,    67,   116,
       1,     2,   117,     4,     5,     6,   145,     7,   205,    70,
     123,    59,   206,   119,    77,   124,   120,     9,    10,    11,
      54,    12,    13,    14,   152,     2,    78,    79,   114,    80,
      81,    82,   172,   174,    83,   157,    17,    84,    85,    87,
     118,   149,   115,   126,   134,   128,   170,   158,    65,    67,
     177,   185,   191,   190,   136,   202,   187,   188,   137,   138,
     140,   141,   138,   171,   173,   146,   144,    86,   192,   194,
     179,   169,   196,   198,   200,   151,    54,    54,     0,   156,
     142,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   166,     0,     0,   163,     0,   175,     0,    54,    54,
       0,   180,    54,   195,   197,   199,   156,   181,   182,     0,
       0,     1,     2,     0,     4,     5,     6,   186,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,     0,    12,    13,    14,   163,   201,     0,    54,    54,
      54,     1,     2,     3,     4,     5,     6,    17,     7,   203,
       0,   150,     0,   207,     0,     0,     8,     0,     9,    10,
      11,     0,    12,    13,    14,     0,     0,     0,     0,    15,
      16,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    19,     0,    20,    21,    22,    23,
       0,     0,    24,    25,     1,     2,     3,     4,     5,     6,
       0,     7,     0,   126,     0,     0,     0,     0,     0,     8,
       0,     9,    10,    11,     0,    12,    13,    14,     0,     0,
       0,     0,    15,    16,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,    20,
      21,    22,    23,     0,     0,    24,    25,     1,     2,     3,
       4,     5,     6,     0,     7,     0,     0,   176,     0,     0,
       0,     0,     8,     0,     9,    10,    11,     0,    12,    13,
      14,     0,     0,     0,     0,    15,    16,     0,     0,     0,
       0,     0,     0,    17,     0,     0,     0,     0,     0,    18,
      19,     0,    20,    21,    22,    23,     0,     0,    24,    25,
       1,     2,     3,     4,     5,     6,     0,     7,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     9,    10,    11,
       0,    12,    13,    14,     0,     0,     0,     0,    15,    16,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,     0,    18,    19,   122,    20,    21,    22,    23,     0,
       0,    24,    25,    89,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,   147,     0,
       0,     0,     0,     0,     0,   109,   110,    89,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,   148,     0,     0,     0,     0,     0,     0,   109,
     110,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,   189,     0,     0,     0,
       0,     0,     0,   109,   110,    89,    90,    91,    92,     0,
      93,    94,    95,    96,    97,    98,     0,     0,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,     0,     0,
       0,     0,     0,    88,     0,     0,     0,   109,   110,    89,
      90,    91,    92,     0,    93,    94,    95,    96,    97,    98,
       0,     0,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,     0,   121,     0,     0,
       0,   109,   110,    89,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,     0,     0,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,    89,    90,    91,
      92,     0,    93,    94,    95,    96,    97,    98,     0,     0,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,   161,     0,     0,     0,     0,     0,     0,     0,   109,
     110,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,     0,     0,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110
};

static const yytype_int16 yycheck[] =
{
       3,     0,   143,    10,     7,     3,    40,     7,    73,    74,
      75,    76,    10,    18,    19,    20,    21,    22,    23,     3,
      20,    21,    10,    10,     3,     4,    10,     3,     4,    16,
      10,     6,     7,    11,    13,    69,    43,    13,    11,    17,
      11,    40,    10,   184,    17,    43,    17,     6,     7,    54,
       3,     4,    55,     6,     7,     8,    43,    10,    13,     3,
      63,    14,    17,    14,    12,    68,    17,    20,    21,    22,
      69,    24,    25,    26,     3,     4,    12,     0,    16,    14,
      14,    14,   147,   148,    14,    13,    39,    14,    14,    14,
      14,   125,    10,    12,     9,    12,    16,    13,     7,     7,
      14,    44,    47,    14,    78,    12,    19,    19,   111,   112,
     113,   114,   115,   147,   148,   120,    16,   151,   183,    16,
     155,   145,   187,   188,   189,   126,   125,   126,    -1,   128,
     115,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,   143,    -1,   149,    -1,   147,   148,
      -1,   156,   151,   187,   188,   189,   155,   160,   163,    -1,
      -1,     3,     4,    -1,     6,     7,     8,   170,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    -1,    24,    25,    26,   184,   191,    -1,   187,   188,
     189,     3,     4,     5,     6,     7,     8,    39,    10,   202,
      -1,    13,    -1,   206,    -1,    -1,    18,    -1,    20,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      -1,    -1,    54,    55,     3,     4,     5,     6,     7,     8,
      -1,    10,    -1,    12,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    21,    22,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    51,    -1,    -1,    54,    55,     3,     4,     5,
       6,     7,     8,    -1,    10,    -1,    -1,    13,    -1,    -1,
      -1,    -1,    18,    -1,    20,    21,    22,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    48,    49,    50,    51,    -1,    -1,    54,    55,
       3,     4,     5,     6,     7,     8,    -1,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    21,    22,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    11,    48,    49,    50,    51,    -1,
      -1,    54,    55,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53,    20,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    14,    -1,    -1,    -1,    52,    53,    20,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    52,    53,    20,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    52,    53,    20,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    10,    18,    20,
      21,    22,    24,    25,    26,    31,    32,    39,    45,    46,
      48,    49,    50,    51,    54,    55,    57,    58,    59,    61,
      62,    63,    64,    67,    68,    69,    70,    71,    72,    73,
      74,    76,    77,    78,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    92,    93,    97,    98,    14,
      83,    90,    83,    10,     6,     7,     6,     7,    10,    10,
       3,    88,    88,    88,    88,    88,    88,    12,    12,     0,
      14,    14,    14,    14,    14,    14,    58,    14,    14,    20,
      21,    22,    23,    25,    26,    27,    28,    29,    30,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    52,
      53,    91,    10,    43,    16,    10,    88,    83,    14,    14,
      17,    14,    11,    83,    83,    58,    12,    79,    12,    65,
      79,    79,    79,    79,     9,    60,    60,    83,    83,    94,
      83,    83,    94,    10,    16,    43,    88,    11,    11,    58,
      13,    74,     3,    13,    66,    75,    90,    13,    13,    11,
      17,    44,    11,    90,    96,    97,    83,    20,    21,    82,
      16,    58,    79,    58,    79,    83,    13,    14,    13,    66,
      88,    83,    88,    11,    17,    44,    83,    19,    19,    11,
      14,    47,    79,    97,    16,    58,    79,    58,    79,    58,
      79,    88,    12,    83,    95,    13,    17,    83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 99 "yacc.y"
    { std::cout<<"program"<<std::endl;
    //dive.clear();
  ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 104 "yacc.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].func_dcl); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 105 "yacc.y"
    { ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 106 "yacc.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].ret_stmt); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 107 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].var_dcl);;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 108 "yacc.y"
    {(yyval.stmt) = createNMVariableDeclaration(*(yyvsp[(1) - (2)].var_list));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 109 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (2)].arr_dcl);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 110 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 111 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (1)].stmt);;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 112 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].strct);;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].iobfr);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 114 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (2)].stage);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 115 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (2)].routine);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 116 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (2)].gpu_program);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 117 "yacc.y"
    {(yyval.stmt) = (yyvsp[(1) - (2)].native);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    {(yyval.native) = createNNative(Node::GLSL,*(yyvsp[(3) - (4)].my_string)); nodes->push_back((yyval.native));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 121 "yacc.y"
    {(yyval.native) = createNNative(Node::HLSL,*(yyvsp[(3) - (4)].my_string)); nodes->push_back((yyval.native));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 124 "yacc.y"
    {(yyval.my_string) = createNString(*(yyvsp[(1) - (1)].string));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 127 "yacc.y"
    {(yyval.gpu_program) = createNProgram(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.gpu_program));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 130 "yacc.y"
    {(yyval.stage) = createNVertex(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.stage));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 131 "yacc.y"
    {(yyval.stage) = createNPixel(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.stage));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 136 "yacc.y"
    {(yyval.routine) = createNRoutine(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.routine));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    {(yyval.iobfr) = createNIOBuffer(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.iobfr));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 142 "yacc.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 143 "yacc.y"
    { (yyval.block) = new NBlock(); (yyval.block)->type = Node::BLOCK; ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 146 "yacc.y"
    {(yyval.svar_dcl) = createNSVariableDeclaration(*(yyvsp[(1) - (4)].ntype),*(yyvsp[(2) - (4)].ident), *(yyvsp[(4) - (4)].ident));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 149 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].stmt);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    {(yyval.arr_dcl) = createNArrayDeclaration(*(yyvsp[(1) - (5)].ntype),*(yyvsp[(2) - (5)].ident),(yyvsp[(4) - (5)].numInteger)->value);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 153 "yacc.y"
    {(yyval.arr_dcl) = createNArrayDeclaration(*(yyvsp[(1) - (9)].ntype),*(yyvsp[(2) - (9)].ident),(yyvsp[(4) - (9)].numInteger)->value,(yyvsp[(8) - (9)].expr_list));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 155 "yacc.y"
    {(yyval.arr_call)= createNArrayCall(*(yyvsp[(1) - (4)].ident),*(yyvsp[(3) - (4)].expr));;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 158 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].while_stmt);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 159 "yacc.y"
    {(yyval.stmt)=(yyvsp[(1) - (1)].for_stmt);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 162 "yacc.y"
    {(yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (7)].expr),*(yyvsp[(5) - (7)].block), createNElseStatement(*(yyvsp[(7) - (7)].block))); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 163 "yacc.y"
    {(yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (7)].expr),*(yyvsp[(5) - (7)].block), createNElseStatement(*(yyvsp[(7) - (7)].stmt))); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 164 "yacc.y"
    {(yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (7)].expr),*(yyvsp[(5) - (7)].stmt), createNElseStatement(*(yyvsp[(7) - (7)].stmt))); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 165 "yacc.y"
    {(yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (7)].expr),*(yyvsp[(5) - (7)].stmt), createNElseStatement(*(yyvsp[(7) - (7)].block))); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 166 "yacc.y"
    { (yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (5)].expr),*(yyvsp[(5) - (5)].stmt),NULL); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 167 "yacc.y"
    { (yyval.stmt) = createNIfStatement(*(yyvsp[(3) - (5)].expr),*(yyvsp[(5) - (5)].block),NULL); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 170 "yacc.y"
    {(yyval.for_stmt) = createNForStatement(*(yyvsp[(3) - (7)].stmt),*(yyvsp[(4) - (7)].stmt),*(yyvsp[(5) - (7)].expr),*(yyvsp[(7) - (7)].block));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 171 "yacc.y"
    {(yyval.for_stmt) = createNForStatement(*(yyvsp[(3) - (7)].stmt),*(yyvsp[(4) - (7)].stmt),*(yyvsp[(5) - (7)].expr),*(yyvsp[(7) - (7)].stmt));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 174 "yacc.y"
    {(yyval.while_stmt) = createNWhileStatement(*(yyvsp[(3) - (5)].expr),*(yyvsp[(5) - (5)].block));;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 175 "yacc.y"
    {(yyval.while_stmt) = createNWhileStatement(*(yyvsp[(3) - (5)].expr),*(yyvsp[(5) - (5)].stmt));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 178 "yacc.y"
    { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[(1) - (1)].stmt));;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 179 "yacc.y"
    { (yyvsp[(1) - (2)].block)->statements.push_back((yyvsp[(2) - (2)].stmt)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 182 "yacc.y"
    {(yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[(1) - (2)].svar_dcl));;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 183 "yacc.y"
    {(yyvsp[(1) - (3)].block)->statements.push_back((yyvsp[(2) - (3)].svar_dcl));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 186 "yacc.y"
    {(yyval.strct) = createNStruct(*(yyvsp[(2) - (3)].ident),*(yyvsp[(3) - (3)].block)); nodes->push_back((yyval.strct));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 189 "yacc.y"
    {(yyval.stmt) = createNExpressionStatement(*(yyvsp[(1) - (2)].expr));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 192 "yacc.y"
    {
  (yyval.func_dcl) = createNFunctionDeclaration(*(yyvsp[(1) - (6)].ntype),*(yyvsp[(2) - (6)].ident),*(yyvsp[(4) - (6)].var_list),*(yyvsp[(6) - (6)].block));
  nodes->push_back((yyval.func_dcl));
         ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 198 "yacc.y"
    { (yyval.block) = (yyvsp[(2) - (3)].block);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 199 "yacc.y"
    { (yyval.block) = new NBlock(); (yyval.block)->type = Node::BLOCK; ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 202 "yacc.y"
    { std::cout<<"numFloat"<<std::endl; ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 203 "yacc.y"
    { std::cout<<"numInteger"<<std::endl; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 206 "yacc.y"
    { (yyval.numFloat) = createNFloat(toFloat(*(yyvsp[(1) - (1)].string)));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 207 "yacc.y"
    {(yyval.numFloat) = createNFloat(-1*toFloat(*(yyvsp[(2) - (2)].string)));;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 208 "yacc.y"
    {(yyval.numFloat) = createNFloat(toFloat(*(yyvsp[(2) - (2)].string)));;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 211 "yacc.y"
    { (yyval.numInteger) = createNInteger(toInt(*(yyvsp[(1) - (1)].string)));;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 212 "yacc.y"
    {(yyval.numInteger) = createNInteger(-1*toInt(*(yyvsp[(2) - (2)].string)));;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 213 "yacc.y"
    {(yyval.numInteger) = createNInteger(toInt(*(yyvsp[(2) - (2)].string)));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 216 "yacc.y"
    {;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 217 "yacc.y"
    { std::cout<<"Function Call"<<std::endl; ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 218 "yacc.y"
    { std::cout<<"Just ID"<<std::endl; ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 219 "yacc.y"
    {(yyval.expr) = createNBinaryOperator(*(yyvsp[(1) - (3)].expr),*(yyvsp[(2) - (3)].string),*(yyvsp[(3) - (3)].expr));;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 220 "yacc.y"
    {(yyval.expr) = (yyvsp[(1) - (1)].unary_expr);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 221 "yacc.y"
    {;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 222 "yacc.y"
    {(yyval.expr)=(yyvsp[(1) - (1)].const_expr);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 223 "yacc.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr);;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 226 "yacc.y"
    {(yyval.unary_expr) = createNUnaryOperator(*(yyvsp[(1) - (2)].string),*(yyvsp[(2) - (2)].expr),false);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 227 "yacc.y"
    {(yyval.unary_expr) = createNUnaryOperator("++",*(yyvsp[(1) - (2)].expr),true);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 228 "yacc.y"
    {(yyval.unary_expr) = createNUnaryOperator("--",*(yyvsp[(1) - (2)].expr),true);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 231 "yacc.y"
    {(yyval.const_expr) = createNConstantExpression(*(yyvsp[(1) - (1)].string));;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 234 "yacc.y"
    { (yyval.func_call) = createNFunctionCall(*(yyvsp[(1) - (4)].ident),*(yyvsp[(3) - (4)].expr_list));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 235 "yacc.y"
    { (yyval.func_call) = createNFunctionCall(*(yyvsp[(1) - (4)].ntype),*(yyvsp[(3) - (4)].expr_list));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 237 "yacc.y"
    { (yyval.ret_stmt) = createNReturnStatement(NULL); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 238 "yacc.y"
    { (yyval.ret_stmt) = createNReturnStatement((yyvsp[(2) - (3)].expr)); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 241 "yacc.y"
    { (yyval.ident) = createNIdentifier(*(yyvsp[(1) - (1)].string));;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 244 "yacc.y"
    { (yyval.ident) = createNIdentifier(*(yyvsp[(1) - (1)].string));;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    {;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 247 "yacc.y"
    { (yyval.ntype) = createNType(*(yyvsp[(1) - (1)].string));;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 248 "yacc.y"
    {(yyval.ntype) = createNType(*(yyvsp[(1) - (1)].string));;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 251 "yacc.y"
    {(yyval.string) = new std::string("+");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 252 "yacc.y"
    {(yyval.string) = new std::string("-");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 253 "yacc.y"
    {(yyval.string) = new std::string("*");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 254 "yacc.y"
    {(yyval.string) = new std::string("/");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    {(yyval.string) = new std::string("==");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 256 "yacc.y"
    {(yyval.string) = new std::string("!=");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 257 "yacc.y"
    {(yyval.string) = new std::string(">");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 258 "yacc.y"
    {(yyval.string) = new std::string("<");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 259 "yacc.y"
    {(yyval.string) = new std::string(">=");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 260 "yacc.y"
    {(yyval.string) = new std::string("<=");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 261 "yacc.y"
    {(yyval.string) = new std::string("+=");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 262 "yacc.y"
    {(yyval.string) = new std::string("-=");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 263 "yacc.y"
    {(yyval.string) = new std::string("*=");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 264 "yacc.y"
    {(yyval.string) = new std::string("/=");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 265 "yacc.y"
    {(yyval.string) = new std::string("&");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 266 "yacc.y"
    {(yyval.string) = new std::string("|");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 267 "yacc.y"
    {(yyval.string) = new std::string("&&");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 268 "yacc.y"
    {(yyval.string) = new std::string("||");;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 269 "yacc.y"
    {(yyval.string) = new std::string(".");;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 270 "yacc.y"
    {(yyval.string) = new std::string("->");;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 273 "yacc.y"
    {(yyval.string) = new std::string("++");;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 274 "yacc.y"
    {(yyval.string) = new std::string("--");;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 275 "yacc.y"
    {(yyval.string) = new std::string("*");;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 276 "yacc.y"
    {(yyval.string) = new std::string("&");;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 277 "yacc.y"
    {(yyval.string) = new std::string("!");;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 280 "yacc.y"
    {(yyval.assignment) = createNAssignment(*(yyvsp[(1) - (3)].ident),*(yyvsp[(3) - (3)].expr));;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 282 "yacc.y"
    {(yyval.expr_list) = new ExpressionList();;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 283 "yacc.y"
    {(yyval.expr_list) = new ExpressionList(); (yyval.expr_list)->push_back((yyvsp[(1) - (1)].expr));;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 284 "yacc.y"
    {(yyvsp[(1) - (3)].expr_list)->push_back((yyvsp[(3) - (3)].expr));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 287 "yacc.y"
    {(yyval.expr_list) = new ExpressionList();;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 288 "yacc.y"
    {(yyval.expr_list) = new ExpressionList(); (yyval.expr_list)->push_back((yyvsp[(1) - (1)].expr));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 289 "yacc.y"
    {(yyvsp[(1) - (3)].expr_list)->push_back((yyvsp[(3) - (3)].expr));;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 292 "yacc.y"
    {(yyval.var_list) = new VariableList();;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 293 "yacc.y"
    {(yyval.var_list) = new VariableList(); (yyval.var_list)->push_back((yyvsp[(1) - (1)].var_dcl)); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 294 "yacc.y"
    {(yyvsp[(1) - (3)].var_list)->push_back((yyvsp[(3) - (3)].var_dcl));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 296 "yacc.y"
    {(yyval.var_dcl) = createNVariableDeclaration(*(yyvsp[(1) - (2)].ntype),*(yyvsp[(2) - (2)].ident));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 297 "yacc.y"
    {(yyval.var_dcl) = createNVariableDeclaration(*(yyvsp[(1) - (4)].ntype),*(yyvsp[(2) - (4)].ident),(yyvsp[(4) - (4)].expr));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 300 "yacc.y"
    {(yyval.var_list) = new VariableList(); (yyval.var_list)->push_back((yyvsp[(1) - (1)].var_dcl));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 301 "yacc.y"
    {(yyval.var_list)->push_back(createNVariableDeclaration((*(yyval.var_list))[0]->VarType, *(yyvsp[(3) - (3)].ident)));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 302 "yacc.y"
    {(yyval.var_list)->push_back(createNVariableDeclaration((*(yyval.var_list))[0]->VarType, *(yyvsp[(3) - (5)].ident),(yyvsp[(5) - (5)].expr)));;}
    break;



/* Line 1455 of yacc.c  */
#line 2566 "parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 304 "yacc.y"


void yyerror(char* e){
  std::cout<<e<<"line: "<<yylineno<<std::endl;
}

int main(){
  //int wait=0;
  //std::cin>>wait;
  auto res = yyparse();
  Node* root = new Node();
  root->type = Node::UNDEFINED;
  if(nodes){
    std::cout<<"List is ok"<<std::endl;
    std::cout<<"List has #"<<nodes->size()<<" elements"<<std::endl;

    while(nodes->size()>0){
      (*nodes)[0]->correctParseTree(nodes,root);
    }
  }

  std::cout<<"Program is ok"<<std::endl;
  std::cout<<"Program has #"<<root->children.size()<<" children"<<std::endl;
  std::stringstream ss;
  for(int i=0;i<root->children.size();i++){
    root->children[i]->generateCode(ss);
  }
  std::cout<<ss.str()<<std::endl;



  //removeNode(nodes,moka);


  //deleteNode(root);
  delete root;
  delete nodes;
  return 0;
}

