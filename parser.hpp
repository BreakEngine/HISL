
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 139 "parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


