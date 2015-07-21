
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 147 "parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


