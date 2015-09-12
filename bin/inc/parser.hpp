
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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 163 "parser.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


