
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
#line 1 "parser.ypp"

#include <iostream>
#include <string>
#include <vector>
#include "PTree.hpp"
#include "Driver.hpp"
extern HISL::Driver* driver;
extern int yylex();
void yyerror(std::string e);
void report(std::string e);


/* Line 189 of yacc.c  */
#line 86 "parser.cpp"

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
     INTEGER = 258,
     ID = 259,
     TYPE = 260,
     BUILTIN_VAR = 261,
     FLOAT = 262,
     PROGRAM = 263,
     SEMICOLON = 264,
     ROUTINE = 265,
     STRUCT = 266,
     VERTEX = 267,
     PIXEL = 268,
     IOBUFFER = 269,
     UNIFORM = 270,
     OPEN_BRACE = 271,
     CLOSE_BRACE = 272,
     COMMA = 273,
     COLON = 274,
     OPEN_PAREN = 275,
     CLOSE_PAREN = 276,
     EQL = 277,
     DOT = 278,
     ARROW = 279,
     OPEN_BRACKET = 280,
     CLOSE_BRACKET = 281,
     PLUS_EQL = 282,
     MINUS_EQL = 283,
     MUL_EQL = 284,
     DEV_EQL = 285,
     MOD_EQL = 286,
     PLUS = 287,
     MINUS = 288,
     MUL = 289,
     DEV = 290,
     MOD = 291,
     LEQL = 292,
     GEQL = 293,
     QEQL = 294,
     NOT_EQL = 295,
     AND = 296,
     OR = 297,
     NOT = 298,
     INC = 299,
     DEC = 300,
     STD = 301
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "parser.ypp"

  int inum;
  std::string* value;
  HISL::PTNode* node;
  HISL::PTInt* integer;
  HISL::PTFloat* flt;
  std::string* str;
  HISL::PTVariableList* var_list;
  std::vector<HISL::PTVariableDeclaration>* strct_blck;
  HISL::PTVariableDeclaration* var_dcl;
  HISL::PTSemanticVariable* svar_dcl;
  std::vector<HISL::PTSemanticVariable>* bfr_blck;
  HISL::PTBlock* generic_blck;
  HISL::PTStatement* generic_stmt;
  HISL::PTArg* argument;
  std::vector<HISL::PTArg>* arg_lst;
  HISL::PTFunctionDeclaration* func_dcl;
  HISL::PTFunctionDefinition* func_def;
  HISL::PTProgram* prg;
  HISL::PTStruct* strct;
  HISL::PTUniform* unifrom;
  HISL::PTArrayDeclaration* array;
  HISL::PTIOBuffer* bfr;
  HISL::PTStage* stg;
  HISL::PTExpressionStmt* exprstmt;
  HISL::PTAssignment* ass;
  HISL::PTExpression* expr;
  HISL::PTLValue* lval;
  std::vector<HISL::PTLValue*>* lvalList;
  HISL::PTUnaryExpression* unaryExp;
  std::vector<HISL::PTStatement*>* bstmts;
  HISL::PTArrayCall* arr_call;
  HISL::PTFunctionCall* funcCall;
  std::vector<HISL::PTExpression*>* expr_list;
  std::vector<HISL::PTConfig*>* config_list;
  HISL::PTRoutine* routine;
  HISL::PTTypeConstructor* type_construct;



/* Line 214 of yacc.c  */
#line 209 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 221 "parser.cpp"

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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    12,    17,    23,    24,    29,    35,
      40,    47,    54,    59,    65,    68,    69,    71,    75,    77,
      80,    81,    83,    86,    88,    92,    95,    97,   100,   103,
     106,   110,   113,   117,   120,   123,   127,   131,   132,   134,
     137,   141,   145,   147,   149,   151,   154,   156,   159,   163,
     165,   168,   170,   173,   176,   181,   184,   186,   188,   190,
     192,   196,   198,   200,   202,   206,   211,   212,   214,   218,
     221,   224,   227,   230,   233,   236,   238,   240,   242,   244,
     246,   248,   250,   252,   254,   256,   258,   262,   266,   270,
     274,   278,   282,   284,   286,   288,   292,   296,   300,   304,
     309,   312,   316,   319,   323,   328,   331,   337,   339,   343,
     347,   353,   356,   358,   362,   364,   366,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,     8,     4,    16,    66,    17,
       9,    -1,    11,     4,    64,     9,    -1,    10,     4,    16,
      52,    17,    -1,    -1,     6,    22,     4,     9,    -1,    52,
       6,    22,     4,     9,    -1,    14,     4,    81,     9,    -1,
      12,     4,    16,    61,    17,     9,    -1,    13,     4,    16,
      61,    17,     9,    -1,     5,    20,    74,    21,    -1,    89,
       4,    20,    59,    21,    -1,    57,    68,    -1,    -1,    60,
      -1,    59,    18,    60,    -1,    89,    -1,    89,     4,    -1,
      -1,    62,    -1,    61,    62,    -1,    50,    -1,    11,     4,
       9,    -1,    57,     9,    -1,    58,    -1,    84,     9,    -1,
      63,     9,    -1,    85,     9,    -1,    15,     4,    64,    -1,
      16,    17,    -1,    16,    65,    17,    -1,    87,     9,    -1,
      85,     9,    -1,    65,    87,     9,    -1,    65,    85,     9,
      -1,    -1,    67,    -1,    66,    67,    -1,    11,     4,     9,
      -1,    14,     4,     9,    -1,    53,    -1,    50,    -1,    54,
      -1,    51,     9,    -1,    55,    -1,    16,    17,    -1,    16,
      69,    17,    -1,    70,    -1,    69,    70,    -1,    71,    -1,
      84,     9,    -1,    85,     9,    -1,     6,    22,    72,     9,
      -1,    72,     9,    -1,    77,    -1,    78,    -1,    90,    -1,
      91,    -1,    72,    76,    72,    -1,    75,    -1,    73,    -1,
      56,    -1,    20,    72,    21,    -1,    79,    20,    74,    21,
      -1,    -1,    72,    -1,    74,    18,    72,    -1,    43,    72,
      -1,    44,    72,    -1,    45,    72,    -1,    34,    72,    -1,
      72,    44,    -1,    72,    45,    -1,    32,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,    78,    22,
      72,    -1,    78,    27,    72,    -1,    78,    28,    72,    -1,
      78,    30,    72,    -1,    78,    29,    72,    -1,    78,    31,
      72,    -1,    79,    -1,     4,    -1,    80,    -1,    79,    23,
       4,    -1,    79,    24,     4,    -1,    79,    23,    80,    -1,
      79,    24,    80,    -1,     4,    25,    72,    26,    -1,    16,
      17,    -1,    16,    82,    17,    -1,    83,     9,    -1,    82,
      83,     9,    -1,    89,     4,    19,     4,    -1,    89,    86,
      -1,    89,     4,    25,    90,    26,    -1,     4,    -1,     4,
      22,    72,    -1,    86,    18,     4,    -1,    86,    18,     4,
      22,    72,    -1,    89,    88,    -1,     4,    -1,    88,    18,
       4,    -1,     5,    -1,     4,    -1,     3,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   132,   135,   138,   141,   142,   144,   147,
     150,   153,   156,   159,   162,   165,   166,   167,   170,   171,
     174,   175,   176,   179,   180,   181,   182,   183,   184,   185,
     188,   191,   192,   195,   197,   199,   200,   202,   203,   204,
     207,   208,   209,   210,   211,   212,   213,   216,   217,   220,
     221,   224,   225,   226,   227,   230,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   244,   247,   248,   249,   252,
     253,   254,   255,   256,   257,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   273,   274,   275,   276,
     277,   278,   281,   284,   285,   286,   295,   304,   314,   326,
     329,   330,   333,   334,   337,   340,   343,   345,   346,   347,
     348,   350,   353,   354,   357,   358,   361,   364
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "TYPE", "BUILTIN_VAR",
  "FLOAT", "PROGRAM", "SEMICOLON", "ROUTINE", "STRUCT", "VERTEX", "PIXEL",
  "IOBUFFER", "UNIFORM", "OPEN_BRACE", "CLOSE_BRACE", "COMMA", "COLON",
  "OPEN_PAREN", "CLOSE_PAREN", "EQL", "DOT", "ARROW", "OPEN_BRACKET",
  "CLOSE_BRACKET", "PLUS_EQL", "MINUS_EQL", "MUL_EQL", "DEV_EQL",
  "MOD_EQL", "PLUS", "MINUS", "MUL", "DEV", "MOD", "LEQL", "GEQL", "QEQL",
  "NOT_EQL", "AND", "OR", "NOT", "INC", "DEC", "STD", "$accept", "start",
  "program", "struct_node", "routine_node", "config_block", "iobuffer",
  "vertex", "pixel", "type_constructor", "function_dcl", "function_def",
  "arg_list", "arg", "stage_block", "stage_stmts", "unifrom_block",
  "struct_block", "struct_stmts", "program_block", "program_stmts",
  "block", "stmts", "stmt", "expr_stmt", "expression", "func_call", "args",
  "unary_expr", "binary_op", "assignment", "lvalue", "access_chain",
  "arr_access", "buffer_block", "buffer_stmts", "semantic_variable",
  "g_var_dcl", "g_arr_dcl", "g_id_list", "variable_dcl", "id_list",
  "variable_spec", "int_num", "float_num", 0
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
     295,   296,   297,   298,   299,   300,   301
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    50,    51,    52,    52,    52,    53,
      54,    55,    56,    57,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      67,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    71,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    77,    77,    77,    77,
      77,    77,    78,    79,    79,    79,    79,    79,    79,    80,
      81,    81,    82,    82,    83,    84,    85,    86,    86,    86,
      86,    87,    88,    88,    89,    89,    90,    91
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     6,     4,     5,     0,     4,     5,     4,
       6,     6,     4,     5,     2,     0,     1,     3,     1,     2,
       0,     1,     2,     1,     3,     2,     1,     2,     2,     2,
       3,     2,     3,     2,     2,     3,     3,     0,     1,     2,
       3,     3,     1,     1,     1,     2,     1,     2,     3,     1,
       2,     1,     2,     2,     4,     2,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     4,     0,     1,     3,     2,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     3,     3,     3,     3,     4,
       2,     3,     2,     3,     4,     2,     5,     1,     3,     3,
       5,     2,     1,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,    37,     0,     0,     0,
       0,     0,    43,     0,    42,    44,    46,     0,    38,     0,
       0,     0,     0,     0,    45,     0,    39,     6,    40,     0,
       0,    20,    20,    41,     0,     0,     3,     0,     0,   115,
     114,    31,     0,     0,     0,     0,     4,     0,     0,    23,
       0,    26,     0,    21,     0,     0,     0,     0,     0,   100,
       0,     0,     0,     9,     0,     0,     5,    32,     0,     0,
      34,    33,   112,   111,     0,     0,    25,     0,    14,     0,
      22,    28,    27,    29,   107,   105,     0,   101,     0,   102,
       0,     0,     0,    36,    35,     0,     0,    24,    30,   116,
      93,   114,     0,   117,    47,     0,     0,     0,     0,     0,
      63,     0,    49,    51,     0,    62,    61,    56,    57,    92,
      94,     0,     0,     0,    58,    59,    10,    15,     0,     0,
      11,   103,     0,     7,     0,     0,   113,     0,    66,     0,
      93,     0,     0,    72,    69,    70,    71,    48,    50,    55,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    73,    74,     0,     0,     0,     0,     0,     0,     0,
      66,     0,     0,    52,    53,   107,     0,    16,    18,   108,
     109,   104,     8,   106,     0,    67,     0,     0,    64,    60,
      86,    87,    88,    90,    89,    91,     0,    95,    97,    96,
      98,     0,    13,    19,     0,    99,     0,    12,    54,    65,
      17,   110,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    49,    13,    38,    14,    15,    16,   110,
      50,    51,   176,   177,    52,    53,    54,    30,    42,    17,
      18,    78,   111,   112,   113,   114,   115,   186,   116,   163,
     117,   118,   119,   120,    35,    60,    61,    55,    56,    85,
      44,    73,    57,   124,   125
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -100
static const yytype_int16 yypact[] =
{
       3,    23,    35,  -100,    64,  -100,   205,    33,    49,    68,
     106,   108,  -100,    97,  -100,  -100,  -100,   138,  -100,   100,
      34,   115,   137,    77,  -100,   105,  -100,   148,  -100,    37,
     161,    40,    40,  -100,    70,   162,  -100,   189,    -2,  -100,
    -100,  -100,    87,   175,   212,   224,  -100,   227,   228,  -100,
      79,  -100,    17,  -100,   225,   226,   229,   232,    98,  -100,
     197,   230,   233,  -100,   236,   211,  -100,  -100,   234,   235,
    -100,  -100,   216,   231,    80,   237,  -100,    13,  -100,   238,
    -100,  -100,  -100,  -100,   188,   239,   241,  -100,   242,  -100,
     223,   243,   244,  -100,  -100,   251,   252,  -100,  -100,  -100,
      -1,   240,   245,  -100,  -100,    74,    74,    74,    74,    74,
    -100,    56,  -100,  -100,    88,  -100,  -100,  -100,   176,   200,
    -100,   246,   249,   255,  -100,  -100,  -100,    21,    74,   257,
    -100,  -100,   258,  -100,   254,   219,  -100,    74,    74,    74,
     221,   240,   124,   155,   155,   155,   155,  -100,  -100,  -100,
    -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,    74,    74,    74,    74,    74,    74,    74,
      74,   260,   261,  -100,  -100,   187,   204,  -100,   262,   155,
     247,  -100,  -100,  -100,   141,   155,   208,   102,  -100,   155,
     155,   155,   155,   155,   155,   155,   209,   221,  -100,   221,
    -100,    21,  -100,  -100,    74,  -100,    74,  -100,  -100,  -100,
    -100,   155,   155
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -100,  -100,  -100,     6,  -100,  -100,  -100,  -100,  -100,  -100,
    -100,  -100,  -100,    67,   248,    -6,  -100,   195,  -100,  -100,
     256,  -100,  -100,   160,  -100,   -99,  -100,   104,  -100,  -100,
    -100,  -100,  -100,   -87,  -100,  -100,   215,   -75,   -28,  -100,
     250,  -100,   -29,   177,  -100
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -116
static const yytype_int16 yytable[] =
{
      45,    43,   121,  -115,    65,    62,   142,   143,   144,   145,
     146,     1,    12,    45,    68,    66,    99,   100,   101,   102,
     103,    39,    40,    12,   137,    39,    40,     4,    47,   179,
     104,    62,    48,   105,    79,     5,   121,    19,   184,   185,
     187,    39,    40,    28,    39,    40,    80,   106,   123,   122,
      29,    47,    80,    20,    41,    48,   107,   108,   109,    99,
     100,   101,   102,   103,   189,   190,   191,   192,   193,   194,
     195,   185,    21,   147,    39,    40,   105,    99,   140,   141,
       6,   103,   123,   122,   198,   200,    33,    59,    76,    97,
     106,    39,    40,    34,   105,    77,    29,   149,   178,   107,
     108,   109,    39,    40,    67,   211,    24,   212,   106,    47,
      22,   208,    23,    48,    36,    86,    27,   107,   108,   109,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    31,   161,   162,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   188,   161,   162,     7,     8,
       9,    10,    11,    32,    37,    25,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   205,   161,   162,
      46,    63,   178,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,    70,   161,   162,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   164,   161,
     162,    39,    40,   165,   166,   167,   168,   169,   127,   128,
     128,    64,    95,    95,    87,     7,     8,     9,    10,    11,
     170,    71,   201,   171,   172,   202,   206,   206,    72,   207,
     209,    74,    75,    92,    81,    82,    84,    90,    83,    89,
      91,    95,   132,    93,    94,   183,   137,   126,   134,    96,
     130,   131,   133,    29,    99,   173,   136,   129,   174,   175,
     138,   180,   181,   182,   197,   199,   203,   139,   210,   204,
      98,   148,   135,    26,   196,    88,     0,     0,     0,     0,
      58,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    69
};

static const yytype_int16 yycheck[] =
{
      29,    29,    77,     4,     6,    34,   105,   106,   107,   108,
     109,     8,     6,    42,    42,    17,     3,     4,     5,     6,
       7,     4,     5,    17,    25,     4,     5,     4,    11,   128,
      17,    60,    15,    20,    17,     0,   111,     4,   137,   138,
     139,     4,     5,     9,     4,     5,    52,    34,    77,    77,
      16,    11,    58,     4,    17,    15,    43,    44,    45,     3,
       4,     5,     6,     7,   163,   164,   165,   166,   167,   168,
     169,   170,     4,    17,     4,     5,    20,     3,     4,     5,
      16,     7,   111,   111,   171,   172,     9,    17,     9,     9,
      34,     4,     5,    16,    20,    16,    16,     9,   127,    43,
      44,    45,     4,     5,    17,   204,     9,   206,    34,    11,
       4,     9,     4,    15,     9,    17,    16,    43,    44,    45,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    16,    44,    45,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    21,    44,    45,    10,    11,
      12,    13,    14,    16,     6,    17,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    26,    44,    45,
       9,     9,   201,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,     9,    44,    45,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    22,    44,
      45,     4,     5,    27,    28,    29,    30,    31,    20,    22,
      22,    22,    25,    25,    17,    10,    11,    12,    13,    14,
      20,     9,    18,    23,    24,    21,    18,    18,     4,    21,
      21,     4,     4,    22,     9,     9,     4,     4,     9,     9,
       4,    25,    19,     9,     9,    26,    25,     9,     4,    18,
       9,     9,     9,    16,     3,     9,     4,    18,     9,     4,
      20,     4,     4,     9,     4,     4,     4,    22,   201,    22,
      75,   111,    95,    17,   170,    60,    -1,    -1,    -1,    -1,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    48,    49,     4,     0,    16,    10,    11,    12,
      13,    14,    50,    51,    53,    54,    55,    66,    67,     4,
       4,     4,     4,     4,     9,    17,    67,    16,     9,    16,
      64,    16,    16,     9,    16,    81,     9,     6,    52,     4,
       5,    17,    65,    85,    87,    89,     9,    11,    15,    50,
      57,    58,    61,    62,    63,    84,    85,    89,    61,    17,
      82,    83,    89,     9,    22,     6,    17,    17,    85,    87,
       9,     9,     4,    88,     4,     4,     9,    16,    68,    17,
      62,     9,     9,     9,     4,    86,    17,    17,    83,     9,
       4,     4,    22,     9,     9,    25,    18,     9,    64,     3,
       4,     5,     6,     7,    17,    20,    34,    43,    44,    45,
      56,    69,    70,    71,    72,    73,    75,    77,    78,    79,
      80,    84,    85,    89,    90,    91,     9,    20,    22,    18,
       9,     9,    19,     9,     4,    90,     4,    25,    20,    22,
       4,     5,    72,    72,    72,    72,    72,    17,    70,     9,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    44,    45,    76,    22,    27,    28,    29,    30,    31,
      20,    23,    24,     9,     9,     4,    59,    60,    89,    72,
       4,     4,     9,    26,    72,    72,    74,    72,    21,    72,
      72,    72,    72,    72,    72,    72,    74,     4,    80,     4,
      80,    18,    21,     4,    22,    26,    18,    21,     9,    21,
      60,    72,    72
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
#line 129 "parser.ypp"
    {(yyval.node) = (yyvsp[(1) - (1)].prg);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 132 "parser.ypp"
    {(yyval.prg) = driver->createProgram((HISL::PTId*)driver->createId(*(yyvsp[(2) - (6)].value)),(yyvsp[(4) - (6)].generic_blck)); driver->m_PTroot->m_children.push_back((yyval.prg));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 135 "parser.ypp"
    {(yyval.strct) = driver->createStruct(driver->createId(*(yyvsp[(2) - (4)].value)),*(yyvsp[(3) - (4)].bstmts)); driver->m_PTroot->m_children.push_back((yyval.strct));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 138 "parser.ypp"
    { (yyval.routine) = driver->createRoutine(driver->createId(*(yyvsp[(2) - (5)].value)),(yyvsp[(4) - (5)].config_list));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 141 "parser.ypp"
    {(yyval.config_list) = new std::vector<HISL::PTConfig*>();;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 142 "parser.ypp"
    {(yyval.config_list) = new std::vector<HISL::PTConfig*>();
                 (yyval.config_list)->push_back(driver->createConfigStatement(driver->createId(*(yyvsp[(1) - (4)].value)),driver->createId(*(yyvsp[(3) - (4)].value))));;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 144 "parser.ypp"
    {(yyvsp[(1) - (5)].config_list)->push_back(driver->createConfigStatement(driver->createId(*(yyvsp[(2) - (5)].value)),driver->createId(*(yyvsp[(4) - (5)].value))));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 147 "parser.ypp"
    {(yyval.bfr) = driver->createBuffer(driver->createId(*(yyvsp[(2) - (4)].value)),*(yyvsp[(3) - (4)].bfr_blck)); driver->m_PTroot->m_children.push_back((yyval.bfr));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 150 "parser.ypp"
    {(yyval.stg) = driver->createVertex(driver->createId(*(yyvsp[(2) - (6)].value)),(yyvsp[(4) - (6)].generic_blck));driver->m_PTroot->m_children.push_back((yyval.stg));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 153 "parser.ypp"
    {(yyval.stg) = driver->createPixel(driver->createId(*(yyvsp[(2) - (6)].value)),(yyvsp[(4) - (6)].generic_blck));driver->m_PTroot->m_children.push_back((yyval.stg));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 156 "parser.ypp"
    { (yyval.type_construct) = driver->createTypeConstructor(driver->createType(*(yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].expr_list));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 159 "parser.ypp"
    {(yyval.func_dcl) = driver->createFuncDcl((yyvsp[(1) - (5)].node),driver->createId(*(yyvsp[(2) - (5)].value)),*(yyvsp[(4) - (5)].arg_lst)); driver->m_PTroot->m_children.push_back((yyval.func_dcl));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 162 "parser.ypp"
    {(yyval.func_def) = driver->createFuncDef((yyvsp[(1) - (2)].func_dcl),(yyvsp[(2) - (2)].generic_blck)); driver->m_PTroot->m_children.push_back((yyval.func_def));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 165 "parser.ypp"
    {(yyval.arg_lst) = new std::vector<HISL::PTArg>();;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 166 "parser.ypp"
    {(yyval.arg_lst) = new std::vector<HISL::PTArg>(); (yyval.arg_lst)->push_back(*(yyvsp[(1) - (1)].argument));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 167 "parser.ypp"
    {(yyvsp[(1) - (3)].arg_lst)->push_back(*(yyvsp[(3) - (3)].argument));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 170 "parser.ypp"
    {(yyval.argument) = driver->createArg((yyvsp[(1) - (1)].node),NULL);;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 171 "parser.ypp"
    {(yyval.argument) = driver->createArg((yyvsp[(1) - (2)].node),driver->createId(*(yyvsp[(2) - (2)].value)));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 174 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock();;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 175 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock(); (yyval.generic_blck)->instructions.push_back((yyvsp[(1) - (1)].generic_stmt));;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 176 "parser.ypp"
    {(yyvsp[(1) - (2)].generic_blck)->instructions.push_back((yyvsp[(2) - (2)].generic_stmt));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 179 "parser.ypp"
    {(yyval.generic_stmt) = (HISL::PTStatement*)(yyvsp[(1) - (1)].strct);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 180 "parser.ypp"
    {(yyval.generic_stmt) = (HISL::PTStatement*)driver->createDeclaration(driver->createType("struct"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 181 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (2)].func_dcl);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 182 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].func_def);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 183 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (2)].var_dcl);;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 184 "parser.ypp"
    { (yyval.generic_stmt) = (yyvsp[(1) - (2)].unifrom);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 185 "parser.ypp"
    {(yyval.generic_stmt) =(yyvsp[(1) - (2)].array);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 188 "parser.ypp"
    {(yyval.unifrom) = driver->createUniform(driver->createId(*(yyvsp[(2) - (3)].value)),*(yyvsp[(3) - (3)].bstmts)); driver->m_PTroot->m_children.push_back((yyval.unifrom));;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 191 "parser.ypp"
    {(yyval.bstmts) = new std::vector<HISL::PTStatement*>();;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 192 "parser.ypp"
    {(yyval.bstmts) = (yyvsp[(2) - (3)].bstmts);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 195 "parser.ypp"
    {(yyval.bstmts) = new std::vector<HISL::PTStatement*>();
                                       (yyval.bstmts)->push_back(((yyvsp[(1) - (2)].var_dcl)));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 197 "parser.ypp"
    {(yyval.bstmts) = new std::vector<HISL::PTStatement*>();
                                       (yyval.bstmts)->push_back(((yyvsp[(1) - (2)].array)));;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 199 "parser.ypp"
    {(yyvsp[(1) - (3)].bstmts)->push_back(((yyvsp[(2) - (3)].var_dcl)));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 200 "parser.ypp"
    {(yyvsp[(1) - (3)].bstmts)->push_back((yyvsp[(2) - (3)].array));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 202 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock();;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 203 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock(); (yyval.generic_blck)->instructions.push_back((yyvsp[(1) - (1)].generic_stmt));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 204 "parser.ypp"
    {(yyvsp[(1) - (2)].generic_blck)->instructions.push_back((yyvsp[(2) - (2)].generic_stmt));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 207 "parser.ypp"
    {(yyval.generic_stmt) = driver->createDeclaration(driver->createType("struct"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 208 "parser.ypp"
    {(yyval.generic_stmt) = driver->createDeclaration(driver->createType("iobuffer"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 209 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].bfr);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 210 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].strct);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 211 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].stg);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 212 "parser.ypp"
    {(yyval.generic_stmt)=(yyvsp[(1) - (2)].routine);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 213 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].stg);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 216 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock();;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 217 "parser.ypp"
    {(yyval.generic_blck) = driver->createBlock(); (yyval.generic_blck)->instructions = *(yyvsp[(2) - (3)].bstmts);;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 220 "parser.ypp"
    { (yyval.bstmts) = new std::vector<HISL::PTStatement*>(); (yyval.bstmts)->push_back((yyvsp[(1) - (1)].generic_stmt));;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 221 "parser.ypp"
    {(yyvsp[(1) - (2)].bstmts)->push_back((yyvsp[(2) - (2)].generic_stmt));;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 224 "parser.ypp"
    {(yyval.generic_stmt) = (yyvsp[(1) - (1)].exprstmt);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 225 "parser.ypp"
    { ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 226 "parser.ypp"
    { ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 227 "parser.ypp"
    {(yyval.generic_stmt) = driver->createConfigStatement(driver->createId(*(yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].expr));;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 230 "parser.ypp"
    {(yyval.exprstmt) = driver->createExpressionStmt((yyvsp[(1) - (2)].expr));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 233 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].ass);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 234 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].lval);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 235 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].integer);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 236 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].flt);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 237 "parser.ypp"
    {(yyval.expr) = driver->createBinaryExp((yyvsp[(1) - (3)].expr),(yyvsp[(2) - (3)].str),(yyvsp[(3) - (3)].expr));;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 238 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].unaryExp);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 239 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].funcCall);;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 240 "parser.ypp"
    {(yyval.expr) = (yyvsp[(1) - (1)].type_construct);;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 241 "parser.ypp"
    {(yyval.expr) = (yyvsp[(2) - (3)].expr);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 244 "parser.ypp"
    {(yyval.funcCall) = driver->createFunctionCall(driver->createAccessChain((yyvsp[(1) - (4)].lval)),(yyvsp[(3) - (4)].expr_list));;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 247 "parser.ypp"
    {(yyval.expr_list) = new std::vector<HISL::PTExpression*>();;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 248 "parser.ypp"
    {(yyval.expr_list) = new std::vector<HISL::PTExpression*>(); (yyval.expr_list)->push_back((yyvsp[(1) - (1)].expr));;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 249 "parser.ypp"
    {(yyvsp[(1) - (3)].expr_list)->push_back((yyvsp[(3) - (3)].expr));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 252 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("!"),(yyvsp[(2) - (2)].expr),false);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 253 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("++"),(yyvsp[(2) - (2)].expr),false);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 254 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("--"),(yyvsp[(2) - (2)].expr),false);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 255 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("*"),(yyvsp[(2) - (2)].expr),false);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 256 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("++"),(yyvsp[(1) - (2)].expr),true);;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 257 "parser.ypp"
    {(yyval.unaryExp) = driver->createUnaryExp(new std::string("--"),(yyvsp[(1) - (2)].expr),true);;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 260 "parser.ypp"
    {(yyval.str) = new std::string("+");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 261 "parser.ypp"
    {(yyval.str) = new std::string("-");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 262 "parser.ypp"
    {(yyval.str) = new std::string("*");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 263 "parser.ypp"
    {(yyval.str) = new std::string("/");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 264 "parser.ypp"
    {(yyval.str) = new std::string("%");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 265 "parser.ypp"
    {(yyval.str) = new std::string("<=");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 266 "parser.ypp"
    {(yyval.str) = new std::string(">=");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 267 "parser.ypp"
    {(yyval.str) = new std::string("==");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 268 "parser.ypp"
    {(yyval.str) = new std::string("!=");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 269 "parser.ypp"
    {(yyval.str) = new std::string("&&");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 270 "parser.ypp"
    {(yyval.str) = new std::string("||");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 273 "parser.ypp"
    { (yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 274 "parser.ypp"
    {(yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"+=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 275 "parser.ypp"
    {(yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"-=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 276 "parser.ypp"
    {(yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"/=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 277 "parser.ypp"
    {(yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"*=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 278 "parser.ypp"
    {(yyval.ass) = driver->createAssignment((yyvsp[(1) - (3)].lval),"%=",(yyvsp[(3) - (3)].expr));;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 281 "parser.ypp"
    {(yyval.lval) = driver->createAccessChain((yyvsp[(1) - (1)].lval));;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 284 "parser.ypp"
    {(yyval.lval) = driver->createVarCall((yyvsp[(1) - (1)].value));;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 285 "parser.ypp"
    {(yyval.lval) = (yyvsp[(1) - (1)].arr_call);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 286 "parser.ypp"
    {
                  auto chainNode = (yyvsp[(1) - (3)].lval);
                  while(chainNode != NULL){
                    if(chainNode->next == NULL)
                      break;
                    chainNode = chainNode->next;
                  }
                  chainNode->next = driver->createVarCall((yyvsp[(3) - (3)].value),".");
                ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 295 "parser.ypp"
    {
                  auto chainNode = (yyvsp[(1) - (3)].lval);
                  while(chainNode != NULL){
                    if(chainNode->next == NULL)
                      break;
                    chainNode = chainNode->next;
                  }
                  chainNode->next = driver->createVarCall((yyvsp[(3) - (3)].value),"->");
                ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 304 "parser.ypp"
    {
                  auto chainNode = (yyvsp[(1) - (3)].lval);
                  while(chainNode != NULL){
                    if(chainNode->next == NULL)
                      break;
                    chainNode = chainNode->next;
                  }

                  (yyvsp[(3) - (3)].arr_call)->op = "."; chainNode->next = (yyvsp[(3) - (3)].arr_call);
                ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 314 "parser.ypp"
    {
                  auto chainNode = (yyvsp[(1) - (3)].lval);
                  while(chainNode != NULL){
                    if(chainNode->next == NULL)
                      break;
                    chainNode = chainNode->next;
                  }

                  (yyvsp[(3) - (3)].arr_call)->op = "->"; chainNode->next = (yyvsp[(3) - (3)].arr_call);
                ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 326 "parser.ypp"
    {(yyval.arr_call) = driver->createArrayCall(driver->createId(*(yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].expr));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 329 "parser.ypp"
    {(yyval.bfr_blck) = new std::vector<HISL::PTSemanticVariable>();;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 330 "parser.ypp"
    {(yyval.bfr_blck) = (yyvsp[(2) - (3)].bfr_blck);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 333 "parser.ypp"
    {(yyval.bfr_blck) = new std::vector<HISL::PTSemanticVariable>(); (yyval.bfr_blck)->push_back(*(yyvsp[(1) - (2)].svar_dcl));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 334 "parser.ypp"
    {(yyvsp[(1) - (3)].bfr_blck)->push_back(*(yyvsp[(2) - (3)].svar_dcl));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 337 "parser.ypp"
    {(yyval.svar_dcl) = driver->createSemanticVar((yyvsp[(1) - (4)].node),driver->createId(*(yyvsp[(2) - (4)].value)),driver->createId(*(yyvsp[(4) - (4)].value)));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 340 "parser.ypp"
    {(yyval.var_dcl) = driver->createVarDcl((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].var_list));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 343 "parser.ypp"
    {(yyval.array) = driver->createArrayDcl((yyvsp[(1) - (5)].node),*(yyvsp[(2) - (5)].value),(yyvsp[(4) - (5)].integer));;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 345 "parser.ypp"
    {(yyval.var_list) = new HISL::PTVariableList(); (yyval.var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(1) - (1)].value))); (yyval.var_list)->values.push_back(NULL);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 346 "parser.ypp"
    {(yyval.var_list) = new HISL::PTVariableList(); (yyval.var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(1) - (3)].value))); (yyval.var_list)->values.push_back((yyvsp[(3) - (3)].expr));;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 347 "parser.ypp"
    {(yyvsp[(1) - (3)].var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(3) - (3)].value))); (yyvsp[(1) - (3)].var_list)->values.push_back(NULL);;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 348 "parser.ypp"
    {(yyvsp[(1) - (5)].var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(3) - (5)].value))); (yyvsp[(1) - (5)].var_list)->values.push_back((yyvsp[(5) - (5)].expr));;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 350 "parser.ypp"
    {(yyval.var_dcl) = driver->createVarDcl((yyvsp[(1) - (2)].node),(yyvsp[(2) - (2)].var_list));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 353 "parser.ypp"
    {(yyval.var_list) = new HISL::PTVariableList(); (yyval.var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(1) - (1)].value))); (yyval.var_list)->values.push_back(NULL);;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 354 "parser.ypp"
    {(yyvsp[(1) - (3)].var_list)->ids.push_back((HISL::PTId*)driver->createId(*(yyvsp[(3) - (3)].value))); (yyvsp[(1) - (3)].var_list)->values.push_back(NULL);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 357 "parser.ypp"
    {(yyval.node) = driver->createType(*(yyvsp[(1) - (1)].value));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 358 "parser.ypp"
    {(yyval.node) = driver->createType(*(yyvsp[(1) - (1)].value));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 361 "parser.ypp"
    {(yyval.integer) = driver->createInteger(*(yyvsp[(1) - (1)].value));;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 364 "parser.ypp"
    {(yyval.flt) = driver->createFloat(*(yyvsp[(1) - (1)].value));;}
    break;



/* Line 1455 of yacc.c  */
#line 2479 "parser.cpp"
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
#line 367 "parser.ypp"


void yyerror(std::string e){
  std::cerr<<e<<" at line: "<<*driver->m_location<<std::endl;
  exit(1);
}

void report(std::string e){
  std::cerr<<e<<std::endl;
}
