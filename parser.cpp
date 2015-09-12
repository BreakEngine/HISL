
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
using HISL::driver;
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
     STRING = 263,
     PROGRAM = 264,
     SEMICOLON = 265,
     ROUTINE = 266,
     STRUCT = 267,
     VERTEX = 268,
     PIXEL = 269,
     IOBUFFER = 270,
     UNIFORM = 271,
     OPEN_BRACE = 272,
     CLOSE_BRACE = 273,
     COMMA = 274,
     COLON = 275,
     OPEN_PAREN = 276,
     CLOSE_PAREN = 277,
     EQL = 278,
     DOT = 279,
     ARROW = 280,
     OPEN_BRACKET = 281,
     CLOSE_BRACKET = 282,
     PLUS_EQL = 283,
     MINUS_EQL = 284,
     MUL_EQL = 285,
     DEV_EQL = 286,
     MOD_EQL = 287,
     PLUS = 288,
     MINUS = 289,
     MUL = 290,
     DEV = 291,
     MOD = 292,
     LEQL = 293,
     GEQL = 294,
     QEQL = 295,
     NOT_EQL = 296,
     AND = 297,
     OR = 298,
     NOT = 299,
     INC = 300,
     DEC = 301,
     STD = 302,
     RETURN = 303,
     IF = 304,
     ELSE = 305,
     WHILE = 306,
     FOR = 307,
     GLSL = 308,
     HLSL = 309,
     SMALLER = 310,
     GREATER = 311,
     SHIFT_LEFT = 312,
     SHIFT_RIGHT = 313,
     AND_OP = 314,
     OR_OP = 315,
     XOR = 316,
     XOR_OP = 317
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 14 "parser.ypp"

  int inum;
  std::string* value;
  HISL::PTNode* pt_node;
  HISL::PTInt* pt_integer;
  HISL::PTFloat* pt_float;
  std::string* pt_string;
  HISL::PTVariableList* pt_variable_list;
  std::vector<HISL::PTVariableDeclaration>* pt_variable_declaration_list;
  HISL::PTVariableDeclaration* pt_variable_declaration;
  std::vector<HISL::PTSemanticVariable>* pt_semantic_variable_list;
  HISL::PTBlock* pt_block;
  HISL::PTStatement* pt_statement;
  HISL::PTArg* pt_argument;
  std::vector<HISL::PTArg>* pt_argument_list;
  HISL::PTFunctionDeclaration* pt_function_declaration;
  HISL::PTFunctionDefinition* pt_function_definition;
  HISL::PTProgram* pt_program;
  HISL::PTStruct* pt_struct;
  HISL::PTUniform* pt_uniform;
  HISL::PTArrayDeclaration* pt_array_declaration;
  HISL::PTIOBuffer* pt_iobuffer;
  HISL::PTStage* pt_stage;
  HISL::PTExpressionStmt* pt_expression_statment;
  HISL::PTAssignment* pt_assignment;
  HISL::PTExpression* pt_expression;
  HISL::PTLValue* pt_lvalue;
  HISL::PTUnaryExpression* pt_unary_expression;
  std::vector<HISL::PTStatement*>* pt_statement_list;
  HISL::PTArrayCall* ptr_array_call;
  HISL::PTFunctionCall* ptr_function_call;
  std::vector<HISL::PTExpression*>* pt_expression_list;
  std::vector<HISL::PTConfig*>* pt_config_list;
  HISL::PTRoutine* pt_routine;
  HISL::PTSemanticVariable* pt_semantic_variable;
  HISL::PTTypeConstructor* pt_type_constructor;
  HISL::PTPreQualifier* pt_pre_qualifier;
  HISL::PTPostQualifier* pt_post_qualifier;
  HISL::PTDeclarator* pt_declarator;
  HISL::PTInitDeclarator* pt_init_declarator;
  std::vector<HISL::PTInitDeclarator*>* pt_init_declarator_list;
  HISL::PTRAccessChain* pt_access_chain;
  HISL::PTRFunctionCall* pt_function_call;
  HISL::PTRArrayCall* pt_array_call;
  HISL::PTRVariableCall* pt_variable_call;



/* Line 214 of yacc.c  */
#line 233 "parser.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 245 "parser.cpp"

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
#define YYLAST   607

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNRULES -- Number of states.  */
#define YYNSTATES  262

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,    11,    18,    23,    29,    34,    40,
      45,    51,    56,    62,    68,    74,    79,    85,    88,    89,
      91,    95,    97,   100,   101,   103,   106,   109,   113,   116,
     118,   121,   124,   129,   135,   137,   139,   142,   145,   147,
     150,   154,   158,   161,   164,   167,   170,   173,   178,   183,
     186,   190,   192,   195,   197,   200,   205,   207,   209,   211,
     213,   216,   219,   223,   226,   228,   230,   232,   234,   238,
     240,   242,   246,   247,   249,   253,   256,   259,   262,   265,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     288,   290,   292,   294,   296,   298,   300,   302,   304,   306,
     310,   314,   318,   322,   326,   330,   332,   336,   338,   343,
     347,   352,   354,   357,   360,   365,   373,   379,   385,   392,
     400,   408,   417,   420,   422,   426,   428,   432,   434,   438,
     440,   443,   445,   449,   453,   455,   457,   459
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,     9,     4,    17,    18,    10,
      -1,     9,     4,    17,    83,    18,    10,    -1,    12,     4,
      17,    18,    -1,    12,     4,    17,    80,    18,    -1,    11,
       4,    17,    18,    -1,    11,     4,    17,    68,    18,    -1,
       6,    23,     4,    10,    -1,    68,     6,    23,     4,    10,
      -1,    15,     4,    17,    18,    -1,    15,     4,    17,    98,
      18,    -1,    13,     4,    17,    77,    18,    -1,    14,     4,
      17,    77,    18,    -1,     5,    21,    92,    22,    -1,   110,
       4,    21,    75,    22,    -1,    73,    86,    -1,    -1,    76,
      -1,    75,    19,    76,    -1,   110,    -1,   110,     4,    -1,
      -1,    78,    -1,    77,    78,    -1,    66,    10,    -1,    12,
       4,    10,    -1,    73,    10,    -1,    74,    -1,    79,    10,
      -1,   103,    10,    -1,    16,     4,    17,    18,    -1,    16,
       4,    17,    80,    18,    -1,    81,    -1,    82,    -1,    81,
      82,    -1,   103,    10,    -1,    84,    -1,    83,    84,    -1,
      12,     4,    10,    -1,    15,     4,    10,    -1,    69,    10,
      -1,    66,    10,    -1,    70,    10,    -1,    67,    10,    -1,
      71,    10,    -1,    53,    17,     8,    18,    -1,    54,    17,
       8,    18,    -1,    17,    18,    -1,    17,    87,    18,    -1,
      88,    -1,    87,    88,    -1,    90,    -1,   103,    10,    -1,
       6,    23,    91,    10,    -1,    89,    -1,    86,    -1,   101,
      -1,   102,    -1,    85,    10,    -1,    48,    10,    -1,    48,
      91,    10,    -1,    91,    10,    -1,    95,    -1,    96,    -1,
     111,    -1,   112,    -1,    91,    94,    91,    -1,    93,    -1,
      72,    -1,    21,    91,    22,    -1,    -1,    91,    -1,    92,
      19,    91,    -1,    44,    91,    -1,    45,    91,    -1,    46,
      91,    -1,    91,    45,    -1,    91,    46,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,
      39,    -1,    40,    -1,    41,    -1,    42,    -1,    43,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    96,    23,    91,    -1,
      96,    28,    91,    -1,    96,    29,    91,    -1,    96,    31,
      91,    -1,    96,    30,    91,    -1,    96,    32,    91,    -1,
      97,    -1,    96,    24,    97,    -1,     4,    -1,     4,    26,
      91,    27,    -1,     4,    21,    22,    -1,     4,    21,   108,
      22,    -1,    99,    -1,    98,    99,    -1,   100,    10,    -1,
     110,     4,    20,     4,    -1,    49,    21,    91,    22,    88,
      50,    88,    -1,    49,    21,    91,    22,    88,    -1,    51,
      21,    91,    22,    88,    -1,    52,    21,    90,    90,    22,
      88,    -1,    52,    21,    90,    90,    91,    22,    88,    -1,
      52,    21,   103,    10,    90,    22,    88,    -1,    52,    21,
     103,    10,    90,    91,    22,    88,    -1,   110,   104,    -1,
     106,    -1,   104,    19,   106,    -1,    91,    -1,    17,   108,
      18,    -1,   107,    -1,   107,    23,   105,    -1,     4,    -1,
       4,   109,    -1,    91,    -1,   108,    19,    91,    -1,    26,
     111,    27,    -1,     5,    -1,     4,    -1,     3,    -1,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   145,   146,   149,   150,   153,   154,   157,
     159,   162,   163,   166,   169,   172,   175,   178,   181,   182,
     183,   186,   187,   190,   191,   192,   195,   196,   197,   198,
     199,   200,   203,   204,   207,   210,   211,   213,   216,   217,
     220,   221,   222,   223,   224,   225,   226,   229,   230,   233,
     234,   237,   238,   241,   242,   243,   244,   245,   246,   247,
     248,   251,   252,   255,   258,   259,   260,   261,   262,   263,
     264,   265,   268,   269,   270,   273,   274,   275,   276,   277,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   301,
     302,   303,   304,   305,   306,   309,   310,   321,   322,   323,
     324,   328,   329,   332,   335,   338,   339,   342,   343,   344,
     345,   346,   349,   352,   353,   356,   357,   360,   361,   364,
     365,   368,   369,   372,   375,   376,   379,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER", "ID", "TYPE", "BUILTIN_VAR",
  "FLOAT", "STRING", "PROGRAM", "SEMICOLON", "ROUTINE", "STRUCT", "VERTEX",
  "PIXEL", "IOBUFFER", "UNIFORM", "OPEN_BRACE", "CLOSE_BRACE", "COMMA",
  "COLON", "OPEN_PAREN", "CLOSE_PAREN", "EQL", "DOT", "ARROW",
  "OPEN_BRACKET", "CLOSE_BRACKET", "PLUS_EQL", "MINUS_EQL", "MUL_EQL",
  "DEV_EQL", "MOD_EQL", "PLUS", "MINUS", "MUL", "DEV", "MOD", "LEQL",
  "GEQL", "QEQL", "NOT_EQL", "AND", "OR", "NOT", "INC", "DEC", "STD",
  "RETURN", "IF", "ELSE", "WHILE", "FOR", "GLSL", "HLSL", "SMALLER",
  "GREATER", "SHIFT_LEFT", "SHIFT_RIGHT", "AND_OP", "OR_OP", "XOR",
  "XOR_OP", "$accept", "start", "program", "struct_node", "routine_node",
  "config_block", "iobuffer", "vertex", "pixel", "type_constructor",
  "function_dcl", "function_def", "arg_list", "arg", "r_stage_block",
  "r_stage_stmts", "unifrom_block", "struct_block", "struct_stmts",
  "struct_stmt", "r_program_block", "r_program_stmts", "r_native_block",
  "r_block", "stmts", "r_stmt", "r_jump_statement", "expr_stmt",
  "expression", "args", "unary_expr", "r_binary_op", "assignment",
  "r_access_chain", "r_access_element", "r_buffer_block", "buffer_stmts",
  "semantic_variable", "r_selection_statement", "r_iteration_statement",
  "variable_declaration", "init_declarator_list", "initializer",
  "init_declarator", "declarator", "expression_list", "post_op",
  "variable_spec", "r_integer", "r_float", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    71,    72,    73,    74,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    81,    81,    82,    83,    83,
      84,    84,    84,    84,    84,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    92,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    99,   100,   101,   101,   102,   102,   102,
     102,   102,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   112
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     6,     4,     5,     4,     5,     4,
       5,     4,     5,     5,     5,     4,     5,     2,     0,     1,
       3,     1,     2,     0,     1,     2,     2,     3,     2,     1,
       2,     2,     4,     5,     1,     1,     2,     2,     1,     2,
       3,     3,     2,     2,     2,     2,     2,     4,     4,     2,
       3,     1,     2,     1,     2,     4,     1,     1,     1,     1,
       2,     2,     3,     2,     1,     1,     1,     1,     3,     1,
       1,     3,     0,     1,     3,     2,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     4,     3,
       4,     1,     2,     2,     4,     7,     5,     5,     6,     7,
       7,     8,     2,     1,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     3,    43,    45,    42,    44,
      46,     0,    39,     0,    40,     0,    23,    23,    41,     0,
       4,     0,     7,     0,   135,   134,     5,     0,    34,    35,
       0,     0,     0,     0,     0,     0,    29,     0,    24,     0,
       0,     0,     0,    11,     0,   111,     0,     0,     0,     0,
       8,     6,    36,    37,   129,   122,   123,   127,     0,     0,
      26,    28,     0,    17,    13,    25,    30,    31,   129,    14,
      12,   112,   113,     0,     0,     0,     0,   130,     0,     0,
      27,     0,   136,   107,   134,     0,   137,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
      57,     0,    51,    56,    53,     0,    69,    64,    65,   105,
      58,    59,     0,    66,    67,    18,     0,     9,     0,     0,
     124,   107,     0,     0,   125,   128,    32,     0,     0,     0,
      72,     0,     0,    75,    76,    77,    61,     0,     0,     0,
       0,     0,     0,    60,    50,    52,    63,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    78,    79,
      91,    92,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,    54,     0,    19,    21,
     114,    10,   133,   131,     0,    33,   109,     0,     0,    73,
       0,     0,    71,    62,     0,     0,     0,     0,     0,     0,
      68,    99,   106,   100,   101,   103,   102,   104,     0,    16,
      22,   126,     0,   110,   108,     0,    15,    55,     0,     0,
       0,     0,    47,    48,    20,   132,    74,   116,   117,     0,
       0,     0,     0,   118,     0,     0,     0,   115,   119,   120,
       0,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    54,    14,    43,    15,    16,    17,   118,
      55,    56,   197,   198,    57,    58,    59,    47,    48,    49,
      18,    19,   119,   120,   121,   122,   123,   124,   125,   210,
     126,   188,   127,   128,   129,    64,    65,    66,   130,   131,
     132,    75,   145,    76,    77,   204,    97,    51,   133,   134
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -157
static const yytype_int16 yypact[] =
{
      16,     6,    47,  -157,    41,  -157,   256,    45,    67,   116,
     122,   124,   126,   134,   143,   145,   157,   164,   284,  -157,
     159,    23,   169,   170,    62,  -157,  -157,  -157,  -157,  -157,
    -157,   167,  -157,    30,  -157,    12,    64,    64,  -157,    14,
    -157,   165,  -157,    32,  -157,  -157,  -157,   173,    98,  -157,
     197,   204,   205,   206,   201,    76,  -157,    19,  -157,   213,
     214,   221,   113,  -157,    52,  -157,   216,   234,   237,   219,
    -157,  -157,  -157,  -157,   222,   241,  -157,   236,    90,   255,
    -157,  -157,    60,  -157,  -157,  -157,  -157,  -157,    18,  -157,
    -157,  -157,  -157,   253,   265,   273,   275,  -157,   204,    38,
    -157,    70,  -157,     1,   258,   260,  -157,  -157,   330,   330,
     330,   330,   311,   261,   266,   269,   264,   283,  -157,   291,
    -157,   240,  -157,  -157,  -157,   123,  -157,  -157,   118,  -157,
    -157,  -157,   296,  -157,  -157,    98,   305,  -157,   307,   292,
    -157,    89,   258,   330,   545,  -157,  -157,   302,   168,   330,
     330,   330,   359,   545,   545,   545,  -157,   160,   330,   330,
     345,   317,   322,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,   330,   330,
     332,   330,   330,   330,   330,   330,  -157,    68,  -157,   334,
    -157,  -157,  -157,   545,   133,  -157,  -157,   100,   515,   545,
     108,   194,  -157,  -157,   389,   419,   330,   329,   325,   326,
     545,   545,  -157,   545,   545,   545,   545,   545,    98,  -157,
    -157,  -157,   330,  -157,  -157,   330,  -157,  -157,   259,   259,
     319,   330,  -157,  -157,  -157,   545,   545,   297,  -157,   259,
     449,   324,   259,  -157,   259,   259,   479,  -157,  -157,  -157,
     259,  -157
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,    83,  -157,  -157,  -157,  -157,  -157,  -157,
    -157,  -157,  -157,   114,   316,    59,  -157,   257,  -157,   306,
    -157,   341,  -157,   312,  -157,  -115,  -157,  -156,   -97,  -157,
    -157,  -157,  -157,  -157,   171,  -157,   298,  -157,  -157,  -157,
     -28,  -157,  -157,   262,  -157,   223,  -157,   -36,   276,  -157
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -136
static const yytype_int16 yytable[] =
{
      61,    61,   144,    67,   216,  -135,   165,    50,    60,    60,
       4,   152,   153,   154,   155,   157,    44,    45,    44,    45,
      50,    61,   148,    44,    45,     1,    61,   149,    67,    60,
      46,    52,    63,    34,    60,    53,    41,    84,    69,   135,
      35,   102,   141,   142,    96,   106,   203,     5,    42,    20,
      70,   203,   208,   209,   211,   143,    44,    45,     6,   108,
     240,   214,   215,   102,   103,   104,   105,   106,    44,    45,
      90,    21,    38,    50,    44,    45,    52,    82,   107,    39,
      53,   108,   109,   110,   111,   251,    81,   228,   146,    13,
     229,   220,   221,    82,   223,   224,   225,   226,   227,   199,
     100,    13,    44,    45,   109,   110,   111,    35,   112,   113,
     148,   114,   115,   116,   117,   149,    85,    44,    45,   232,
      22,    85,   233,   247,   248,    52,    23,   235,    24,    53,
     236,    89,   217,   166,   253,   245,    25,   257,   246,   258,
     259,   189,   190,   250,    26,   261,   191,   192,   193,   194,
     195,   231,   232,    27,   256,    28,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,    29,   178,   179,
     213,   102,   141,   142,    30,   106,    33,    40,   180,   181,
     182,   183,   184,   185,   186,   187,    36,    37,    68,   108,
     206,    71,   199,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   237,   178,   179,    73,    74,    78,
      79,    80,   109,   110,   111,   180,   181,   182,   183,   184,
     185,   186,   187,    86,    87,    88,    92,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,    93,   178,
     179,    94,    95,   102,   103,   104,   105,   106,    96,   180,
     181,   182,   183,   184,   185,   186,   187,    82,   164,    99,
      98,   108,   102,   103,   104,   105,   106,     7,     8,     9,
      10,    11,   101,   136,    12,   137,    82,   138,   102,   150,
     108,   161,   158,   151,   109,   110,   111,   159,   112,   113,
     160,   114,   115,   116,   117,     7,     8,     9,    10,    11,
     162,   163,    31,   109,   110,   111,   196,   112,   113,   200,
     114,   115,   116,   117,   102,   141,   142,   201,   106,   202,
     205,   156,   102,   141,   142,   218,   106,   102,   141,   142,
     219,   106,   108,   102,   141,   142,   141,   106,   230,   241,
     108,   249,   244,   242,   243,   108,   255,   252,   102,   103,
     104,   108,   106,    62,    72,   109,   110,   111,   147,    32,
     140,   222,    91,   109,   110,   111,   108,    83,   109,   110,
     111,   207,   139,     0,   109,   110,   111,     0,     0,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,   109,
     110,   111,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,     0,     0,     0,
       0,   238,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,     0,     0,     0,
       0,   239,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,     0,     0,     0,
       0,   254,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,     0,     0,     0,
       0,   260,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,     0,   178,   179,     0,     0,     0,     0,
       0,     0,     0,     0,   180,   181,   182,   183,   184,   185,
     186,   187,   234,     0,     0,     0,     0,     0,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,   187,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,     0,
     178,   179,     0,     0,     0,     0,     0,     0,     0,     0,
     180,   181,   182,   183,   184,   185,   186,   187
};

static const yytype_int16 yycheck[] =
{
      36,    37,    99,    39,   160,     4,   121,    35,    36,    37,
       4,   108,   109,   110,   111,   112,     4,     5,     4,     5,
      48,    57,    21,     4,     5,     9,    62,    26,    64,    57,
      18,    12,    18,    10,    62,    16,     6,    18,     6,    21,
      17,     3,     4,     5,    26,     7,   143,     0,    18,     4,
      18,   148,   149,   150,   151,    17,     4,     5,    17,    21,
     216,   158,   159,     3,     4,     5,     6,     7,     4,     5,
      18,     4,    10,   101,     4,     5,    12,    17,    18,    17,
      16,    21,    44,    45,    46,   241,    10,    19,    18,     6,
      22,   188,   189,    17,   191,   192,   193,   194,   195,   135,
      10,    18,     4,     5,    44,    45,    46,    17,    48,    49,
      21,    51,    52,    53,    54,    26,    57,     4,     5,    19,
       4,    62,    22,   238,   239,    12,     4,    19,     4,    16,
      22,    18,   160,    10,   249,   232,    10,   252,   235,   254,
     255,    23,    24,   240,    10,   260,    28,    29,    30,    31,
      32,    18,    19,    10,   251,    10,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    10,    45,    46,
      10,     3,     4,     5,    10,     7,    17,    10,    55,    56,
      57,    58,    59,    60,    61,    62,    17,    17,    23,    21,
      22,    18,   228,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    10,    45,    46,    10,     4,     4,
       4,    10,    44,    45,    46,    55,    56,    57,    58,    59,
      60,    61,    62,    10,    10,     4,    10,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,     4,    45,
      46,     4,    23,     3,     4,     5,     6,     7,    26,    55,
      56,    57,    58,    59,    60,    61,    62,    17,    18,    23,
      19,    21,     3,     4,     5,     6,     7,    11,    12,    13,
      14,    15,    17,    20,    18,    10,    17,     4,     3,    21,
      21,    17,    21,    23,    44,    45,    46,    21,    48,    49,
      21,    51,    52,    53,    54,    11,    12,    13,    14,    15,
      17,    10,    18,    44,    45,    46,    10,    48,    49,     4,
      51,    52,    53,    54,     3,     4,     5,    10,     7,    27,
      18,    10,     3,     4,     5,     8,     7,     3,     4,     5,
       8,     7,    21,     3,     4,     5,     4,     7,     4,    10,
      21,    22,   228,    18,    18,    21,    22,    50,     3,     4,
       5,    21,     7,    37,    48,    44,    45,    46,   101,    18,
      98,   190,    64,    44,    45,    46,    21,    55,    44,    45,
      46,   148,    96,    -1,    44,    45,    46,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    46,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,    60,
      61,    62,    27,    -1,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    56,    57,    58,    59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    64,    65,     4,     0,    17,    11,    12,    13,
      14,    15,    18,    66,    67,    69,    70,    71,    83,    84,
       4,     4,     4,     4,     4,    10,    10,    10,    10,    10,
      10,    18,    84,    17,    10,    17,    17,    17,    10,    17,
      10,     6,    18,    68,     4,     5,    18,    80,    81,    82,
     103,   110,    12,    16,    66,    73,    74,    77,    78,    79,
     103,   110,    77,    18,    98,    99,   100,   110,    23,     6,
      18,    18,    82,    10,     4,   104,   106,   107,     4,     4,
      10,    10,    17,    86,    18,    78,    10,    10,     4,    18,
      18,    99,    10,     4,     4,    23,    26,   109,    19,    23,
      10,    17,     3,     4,     5,     6,     7,    18,    21,    44,
      45,    46,    48,    49,    51,    52,    53,    54,    72,    85,
      86,    87,    88,    89,    90,    91,    93,    95,    96,    97,
     101,   102,   103,   111,   112,    21,    20,    10,     4,   111,
     106,     4,     5,    17,    91,   105,    18,    80,    21,    26,
      21,    23,    91,    91,    91,    91,    10,    91,    21,    21,
      21,    17,    17,    10,    18,    88,    10,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    45,    46,
      55,    56,    57,    58,    59,    60,    61,    62,    94,    23,
      24,    28,    29,    30,    31,    32,    10,    75,    76,   110,
       4,    10,    27,    91,   108,    18,    22,   108,    91,    91,
      92,    91,    22,    10,    91,    91,    90,   103,     8,     8,
      91,    91,    97,    91,    91,    91,    91,    91,    19,    22,
       4,    18,    19,    22,    27,    19,    22,    10,    22,    22,
      90,    10,    18,    18,    76,    91,    91,    88,    88,    22,
      91,    90,    50,    88,    22,    22,    91,    88,    88,    88,
      22,    88
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
#line 142 "parser.ypp"
    {(yyval.pt_node) = (yyvsp[(1) - (1)].pt_program);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 145 "parser.ypp"
    {(yyval.pt_program) = driver->createProgram((HISL::PTId*)driver->createId(*(yyvsp[(2) - (5)].value)),driver->createBlock()); driver->m_PTroot->m_children.push_back((yyval.pt_program));;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 146 "parser.ypp"
    {(yyval.pt_program) = driver->createProgram((HISL::PTId*)driver->createId(*(yyvsp[(2) - (6)].value)),(yyvsp[(4) - (6)].pt_block)); driver->m_PTroot->m_children.push_back((yyval.pt_program));;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 149 "parser.ypp"
    {(yyval.pt_struct) = driver->createStruct(driver->createId(*(yyvsp[(2) - (4)].value)),*new std::vector<HISL::PTStatement*>()); driver->m_PTroot->m_children.push_back((yyval.pt_struct));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 150 "parser.ypp"
    {(yyval.pt_struct) = driver->createStruct(driver->createId(*(yyvsp[(2) - (5)].value)),*(yyvsp[(4) - (5)].pt_statement_list)); driver->m_PTroot->m_children.push_back((yyval.pt_struct));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 153 "parser.ypp"
    { (yyval.pt_routine) = driver->createRoutine(driver->createId(*(yyvsp[(2) - (4)].value)),new std::vector<HISL::PTConfig*>());;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 154 "parser.ypp"
    { (yyval.pt_routine) = driver->createRoutine(driver->createId(*(yyvsp[(2) - (5)].value)),(yyvsp[(4) - (5)].pt_config_list));;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 157 "parser.ypp"
    {(yyval.pt_config_list) = new std::vector<HISL::PTConfig*>();
                 (yyval.pt_config_list)->push_back(driver->createConfigStatement(driver->createId(*(yyvsp[(1) - (4)].value)),driver->createId(*(yyvsp[(3) - (4)].value))));;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 159 "parser.ypp"
    {(yyvsp[(1) - (5)].pt_config_list)->push_back(driver->createConfigStatement(driver->createId(*(yyvsp[(2) - (5)].value)),driver->createId(*(yyvsp[(4) - (5)].value))));;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 162 "parser.ypp"
    {(yyval.pt_iobuffer) = driver->createBuffer(driver->createId(*(yyvsp[(2) - (4)].value)),*new std::vector<HISL::PTSemanticVariable>()); driver->m_PTroot->m_children.push_back((yyval.pt_iobuffer));;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 163 "parser.ypp"
    {(yyval.pt_iobuffer) = driver->createBuffer(driver->createId(*(yyvsp[(2) - (5)].value)),*(yyvsp[(4) - (5)].pt_semantic_variable_list)); driver->m_PTroot->m_children.push_back((yyval.pt_iobuffer));;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 166 "parser.ypp"
    {(yyval.pt_stage) = driver->createVertex(driver->createId(*(yyvsp[(2) - (5)].value)),(yyvsp[(4) - (5)].pt_block));driver->m_PTroot->m_children.push_back((yyval.pt_stage));;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 169 "parser.ypp"
    {(yyval.pt_stage) = driver->createPixel(driver->createId(*(yyvsp[(2) - (5)].value)),(yyvsp[(4) - (5)].pt_block));driver->m_PTroot->m_children.push_back((yyval.pt_stage));;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 172 "parser.ypp"
    { (yyval.pt_type_constructor) = driver->createTypeConstructor(driver->createType(*(yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].pt_expression_list));;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 175 "parser.ypp"
    {(yyval.pt_function_declaration) = driver->createFuncDcl((yyvsp[(1) - (5)].pt_node),driver->createId(*(yyvsp[(2) - (5)].value)),*(yyvsp[(4) - (5)].pt_argument_list)); driver->m_PTroot->m_children.push_back((yyval.pt_function_declaration));;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 178 "parser.ypp"
    {(yyval.pt_function_definition) = driver->createFuncDef((yyvsp[(1) - (2)].pt_function_declaration),(yyvsp[(2) - (2)].pt_block)); driver->m_PTroot->m_children.push_back((yyval.pt_function_definition));;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 181 "parser.ypp"
    {(yyval.pt_argument_list) = new std::vector<HISL::PTArg>();;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 182 "parser.ypp"
    {(yyval.pt_argument_list) = new std::vector<HISL::PTArg>(); (yyval.pt_argument_list)->push_back(*(yyvsp[(1) - (1)].pt_argument));;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 183 "parser.ypp"
    {(yyvsp[(1) - (3)].pt_argument_list)->push_back(*(yyvsp[(3) - (3)].pt_argument));;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 186 "parser.ypp"
    {(yyval.pt_argument) = driver->createArg((yyvsp[(1) - (1)].pt_node),NULL);;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 187 "parser.ypp"
    {(yyval.pt_argument) = driver->createArg((yyvsp[(1) - (2)].pt_node),driver->createId(*(yyvsp[(2) - (2)].value)));;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 190 "parser.ypp"
    {(yyval.pt_block) = driver->createBlock();;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 191 "parser.ypp"
    {(yyval.pt_block) = driver->createBlock(); (yyval.pt_block)->instructions.push_back((yyvsp[(1) - (1)].pt_statement));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 192 "parser.ypp"
    {(yyvsp[(1) - (2)].pt_block)->instructions.push_back((yyvsp[(2) - (2)].pt_statement));;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 195 "parser.ypp"
    {(yyval.pt_statement) = (HISL::PTStatement*)(yyvsp[(1) - (2)].pt_struct);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 196 "parser.ypp"
    {(yyval.pt_statement) = (HISL::PTStatement*)driver->createDeclaration(driver->createType("struct"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 197 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_function_declaration);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 198 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_function_definition);;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 199 "parser.ypp"
    { (yyval.pt_statement) = (yyvsp[(1) - (2)].pt_uniform);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 200 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_variable_declaration);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 203 "parser.ypp"
    {(yyval.pt_uniform) = driver->createUniform(driver->createId(*(yyvsp[(2) - (4)].value)),*new std::vector<HISL::PTStatement*>()); driver->m_PTroot->m_children.push_back((yyval.pt_uniform));;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 204 "parser.ypp"
    {(yyval.pt_uniform) = driver->createUniform(driver->createId(*(yyvsp[(2) - (5)].value)),*(yyvsp[(4) - (5)].pt_statement_list)); driver->m_PTroot->m_children.push_back((yyval.pt_uniform));;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 207 "parser.ypp"
    {(yyval.pt_statement_list) = (yyvsp[(1) - (1)].pt_statement_list);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 210 "parser.ypp"
    {(yyval.pt_statement_list) = new std::vector<HISL::PTStatement*>(); (yyval.pt_statement_list)->push_back((yyvsp[(1) - (1)].pt_statement));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 211 "parser.ypp"
    {(yyvsp[(1) - (2)].pt_statement_list)->push_back((yyvsp[(2) - (2)].pt_statement));;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 213 "parser.ypp"
    { (yyval.pt_statement) = (yyvsp[(1) - (2)].pt_variable_declaration); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 216 "parser.ypp"
    {(yyval.pt_block) = driver->createBlock(); (yyval.pt_block)->instructions.push_back((yyvsp[(1) - (1)].pt_statement));;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 217 "parser.ypp"
    {(yyvsp[(1) - (2)].pt_block)->instructions.push_back((yyvsp[(2) - (2)].pt_statement));;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 220 "parser.ypp"
    {(yyval.pt_statement) = driver->createDeclaration(driver->createType("struct"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 221 "parser.ypp"
    {(yyval.pt_statement) = driver->createDeclaration(driver->createType("iobuffer"),driver->createId(*(yyvsp[(2) - (3)].value)));;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 222 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_iobuffer);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 223 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_struct);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 224 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_stage);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 225 "parser.ypp"
    {(yyval.pt_statement)=(yyvsp[(1) - (2)].pt_routine);;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 226 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_stage);;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 229 "parser.ypp"
    {(yyval.pt_statement) = driver->createGLSL(*(yyvsp[(3) - (4)].value));;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 230 "parser.ypp"
    {(yyval.pt_statement) = driver->createHLSL(*(yyvsp[(3) - (4)].value));;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 233 "parser.ypp"
    {(yyval.pt_block) = driver->createBlock();;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 234 "parser.ypp"
    {(yyval.pt_block) = driver->createBlock(); (yyval.pt_block)->instructions = *(yyvsp[(2) - (3)].pt_statement_list);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 237 "parser.ypp"
    { (yyval.pt_statement_list) = new std::vector<HISL::PTStatement*>(); (yyval.pt_statement_list)->push_back((yyvsp[(1) - (1)].pt_statement));;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 238 "parser.ypp"
    {(yyvsp[(1) - (2)].pt_statement_list)->push_back((yyvsp[(2) - (2)].pt_statement));;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 241 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_expression_statment);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 242 "parser.ypp"
    { ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 243 "parser.ypp"
    {(yyval.pt_statement) = driver->createConfigStatement(driver->createId(*(yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].pt_expression));;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 244 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_statement);;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 245 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_block);;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 246 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_statement);;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 247 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (1)].pt_statement);;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 248 "parser.ypp"
    {(yyval.pt_statement) = (yyvsp[(1) - (2)].pt_statement);;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 251 "parser.ypp"
    {(yyval.pt_statement) = driver->createReturn(NULL);;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 252 "parser.ypp"
    {(yyval.pt_statement) = driver->createReturn((yyvsp[(2) - (3)].pt_expression));;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 255 "parser.ypp"
    {(yyval.pt_expression_statment) = driver->createExpressionStmt((yyvsp[(1) - (2)].pt_expression));;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 258 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_assignment);;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 259 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_access_chain);;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 260 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_integer);;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 261 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_float);;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 262 "parser.ypp"
    {(yyval.pt_expression) = driver->createBinaryExp((yyvsp[(1) - (3)].pt_expression),(yyvsp[(2) - (3)].pt_string),(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 263 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_unary_expression);;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 264 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(1) - (1)].pt_type_constructor);;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 265 "parser.ypp"
    {(yyval.pt_expression) = (yyvsp[(2) - (3)].pt_expression);;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 268 "parser.ypp"
    {(yyval.pt_expression_list) = new std::vector<HISL::PTExpression*>();;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 269 "parser.ypp"
    {(yyval.pt_expression_list) = new std::vector<HISL::PTExpression*>(); (yyval.pt_expression_list)->push_back((yyvsp[(1) - (1)].pt_expression));;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 270 "parser.ypp"
    {(yyvsp[(1) - (3)].pt_expression_list)->push_back((yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 273 "parser.ypp"
    {(yyval.pt_unary_expression) = driver->createUnaryExp(new std::string("!"),(yyvsp[(2) - (2)].pt_expression),false);;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 274 "parser.ypp"
    {(yyval.pt_unary_expression) = driver->createUnaryExp(new std::string("++"),(yyvsp[(2) - (2)].pt_expression),false);;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 275 "parser.ypp"
    {(yyval.pt_unary_expression) = driver->createUnaryExp(new std::string("--"),(yyvsp[(2) - (2)].pt_expression),false);;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 276 "parser.ypp"
    {(yyval.pt_unary_expression) = driver->createUnaryExp(new std::string("++"),(yyvsp[(1) - (2)].pt_expression),true);;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 277 "parser.ypp"
    {(yyval.pt_unary_expression) = driver->createUnaryExp(new std::string("--"),(yyvsp[(1) - (2)].pt_expression),true);;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 280 "parser.ypp"
    {(yyval.pt_string) = new std::string("+");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 281 "parser.ypp"
    {(yyval.pt_string) = new std::string("-");;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 282 "parser.ypp"
    {(yyval.pt_string) = new std::string("*");;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 283 "parser.ypp"
    {(yyval.pt_string) = new std::string("/");;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 284 "parser.ypp"
    {(yyval.pt_string) = new std::string("%");;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 285 "parser.ypp"
    {(yyval.pt_string) = new std::string("<=");;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 286 "parser.ypp"
    {(yyval.pt_string) = new std::string(">=");;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 287 "parser.ypp"
    {(yyval.pt_string) = new std::string("==");;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 288 "parser.ypp"
    {(yyval.pt_string) = new std::string("!=");;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 289 "parser.ypp"
    {(yyval.pt_string) = new std::string("&&");;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 290 "parser.ypp"
    {(yyval.pt_string) = new std::string("||");;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 291 "parser.ypp"
    {(yyval.pt_string) = new std::string("<");;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 292 "parser.ypp"
    {(yyval.pt_string) = new std::string(">");;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 293 "parser.ypp"
    {(yyval.pt_string) = new std::string("<<");;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 294 "parser.ypp"
    {(yyval.pt_string) = new std::string(">>");;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 295 "parser.ypp"
    {(yyval.pt_string) = new std::string("&");;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 296 "parser.ypp"
    {(yyval.pt_string) = new std::string("|");;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 297 "parser.ypp"
    {(yyval.pt_string) = new std::string("^^");;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 298 "parser.ypp"
    {(yyval.pt_string) = new std::string("^");;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 301 "parser.ypp"
    { (yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 302 "parser.ypp"
    {(yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"+=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 303 "parser.ypp"
    {(yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"-=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 304 "parser.ypp"
    {(yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"/=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 305 "parser.ypp"
    {(yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"*=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 306 "parser.ypp"
    {(yyval.pt_assignment) = driver->createAssignment((yyvsp[(1) - (3)].pt_access_chain),"%=",(yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 309 "parser.ypp"
    {(yyvsp[(1) - (1)].pt_lvalue)->op = ""; (yyval.pt_access_chain) = driver->createRAccessChain((yyvsp[(1) - (1)].pt_lvalue));;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 310 "parser.ypp"
    {(yyvsp[(3) - (3)].pt_lvalue)->op = ".";
                 auto it = (yyvsp[(1) - (3)].pt_access_chain)->lval;
                 while(it!=NULL){
                   if(it->next == NULL)
                    break;
                   it = it->next;
                 } 
                 it->next = (yyvsp[(3) - (3)].pt_lvalue);
                 ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 321 "parser.ypp"
    {(yyval.pt_lvalue) = driver->createRVarCall(*(yyvsp[(1) - (1)].value),"");;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 322 "parser.ypp"
    {(yyval.pt_lvalue) = driver->createRArrayCall(*(yyvsp[(1) - (4)].value),(yyvsp[(3) - (4)].pt_expression),"");;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 323 "parser.ypp"
    {(yyval.pt_lvalue) = driver->createRFunctionCall(*(yyvsp[(1) - (3)].value),new std::vector<HISL::PTExpression*>(),"");;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 324 "parser.ypp"
    {(yyval.pt_lvalue) = driver->createRFunctionCall(*(yyvsp[(1) - (4)].value),(yyvsp[(3) - (4)].pt_expression_list),"");;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 328 "parser.ypp"
    {(yyval.pt_semantic_variable_list) = new std::vector<HISL::PTSemanticVariable>(); (yyval.pt_semantic_variable_list)->push_back(*(yyvsp[(1) - (1)].pt_semantic_variable));;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 329 "parser.ypp"
    {(yyvsp[(1) - (2)].pt_semantic_variable_list)->push_back(*(yyvsp[(2) - (2)].pt_semantic_variable));;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 332 "parser.ypp"
    {(yyval.pt_semantic_variable) = (yyvsp[(1) - (2)].pt_semantic_variable);;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 335 "parser.ypp"
    {(yyval.pt_semantic_variable) = driver->createSemanticVar((yyvsp[(1) - (4)].pt_node),driver->createId(*(yyvsp[(2) - (4)].value)),driver->createId(*(yyvsp[(4) - (4)].value)));;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 338 "parser.ypp"
    {(yyval.pt_statement) = driver->createIf((yyvsp[(3) - (7)].pt_expression),(yyvsp[(5) - (7)].pt_statement),(yyvsp[(7) - (7)].pt_statement));;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 339 "parser.ypp"
    {(yyval.pt_statement) = driver->createIf((yyvsp[(3) - (5)].pt_expression),(yyvsp[(5) - (5)].pt_statement),NULL);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 342 "parser.ypp"
    {(yyval.pt_statement) = driver->createWhile((yyvsp[(3) - (5)].pt_expression),(yyvsp[(5) - (5)].pt_statement));;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 343 "parser.ypp"
    {(yyval.pt_statement) = driver->createFor((yyvsp[(3) - (6)].pt_expression_statment),(yyvsp[(4) - (6)].pt_expression_statment),NULL,(yyvsp[(6) - (6)].pt_statement));;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 344 "parser.ypp"
    {(yyval.pt_statement) = driver->createFor((yyvsp[(3) - (7)].pt_expression_statment),(yyvsp[(4) - (7)].pt_expression_statment),(yyvsp[(5) - (7)].pt_expression),(yyvsp[(7) - (7)].pt_statement));;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 345 "parser.ypp"
    {(yyval.pt_statement) = driver->createFor((yyvsp[(3) - (7)].pt_variable_declaration),(yyvsp[(5) - (7)].pt_expression_statment),NULL,(yyvsp[(7) - (7)].pt_statement));;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 346 "parser.ypp"
    {(yyval.pt_statement) = driver->createFor((yyvsp[(3) - (8)].pt_variable_declaration),(yyvsp[(5) - (8)].pt_expression_statment),(yyvsp[(6) - (8)].pt_expression),(yyvsp[(8) - (8)].pt_statement));;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 349 "parser.ypp"
    {(yyval.pt_variable_declaration) = driver->createVarDcl((yyvsp[(1) - (2)].pt_node),driver->createVariableList((yyvsp[(2) - (2)].pt_init_declarator_list)));;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 352 "parser.ypp"
    {(yyval.pt_init_declarator_list) = new std::vector<HISL::PTInitDeclarator*>(); (yyval.pt_init_declarator_list)->push_back((yyvsp[(1) - (1)].pt_init_declarator));;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 353 "parser.ypp"
    {(yyvsp[(1) - (3)].pt_init_declarator_list)->push_back((yyvsp[(3) - (3)].pt_init_declarator));;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 356 "parser.ypp"
    {(yyval.pt_expression_list) = new std::vector<HISL::PTExpression*>(); (yyval.pt_expression_list)->push_back((yyvsp[(1) - (1)].pt_expression));;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 357 "parser.ypp"
    {(yyval.pt_expression_list) = (yyvsp[(2) - (3)].pt_expression_list);;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 360 "parser.ypp"
    {(yyval.pt_init_declarator) = driver->createInitDeclarator((yyvsp[(1) - (1)].pt_declarator),new std::vector<HISL::PTExpression*>());;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 361 "parser.ypp"
    {(yyval.pt_init_declarator) = driver->createInitDeclarator((yyvsp[(1) - (3)].pt_declarator),(yyvsp[(3) - (3)].pt_expression_list));;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 364 "parser.ypp"
    {(yyval.pt_declarator) = driver->createDeclarator(NULL,*driver->createId(*(yyvsp[(1) - (1)].value)),NULL);;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 365 "parser.ypp"
    {(yyval.pt_declarator) = driver->createDeclarator(NULL,*driver->createId(*(yyvsp[(1) - (2)].value)),(yyvsp[(2) - (2)].pt_post_qualifier));;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 368 "parser.ypp"
    {(yyval.pt_expression_list) = new std::vector<HISL::PTExpression*>(); (yyval.pt_expression_list)->push_back((yyvsp[(1) - (1)].pt_expression));;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 369 "parser.ypp"
    {(yyvsp[(1) - (3)].pt_expression_list)->push_back((yyvsp[(3) - (3)].pt_expression));;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 372 "parser.ypp"
    {(yyval.pt_post_qualifier) = driver->createPostQualifier(true,(yyvsp[(2) - (3)].pt_integer)->val);;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 375 "parser.ypp"
    {(yyval.pt_node) = driver->createType(*(yyvsp[(1) - (1)].value));;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 376 "parser.ypp"
    {(yyval.pt_node) = driver->createType(*(yyvsp[(1) - (1)].value));;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 379 "parser.ypp"
    {(yyval.pt_integer) = driver->createInteger(*(yyvsp[(1) - (1)].value));;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 382 "parser.ypp"
    {(yyval.pt_float) = driver->createFloat(*(yyvsp[(1) - (1)].value));;}
    break;



/* Line 1455 of yacc.c  */
#line 2718 "parser.cpp"
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
#line 385 "parser.ypp"


void yyerror(std::string e){
  std::cerr<<e<<" at line: "<<*driver->m_location<<std::endl;
  exit(1);
}

void report(std::string e){
  std::cerr<<e<<std::endl;
}
