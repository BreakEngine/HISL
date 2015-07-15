%{
void yyerror(char* e);
#include <iostream>
#include <string>
#include <sstream>
#include "NodeFunctions.h"
using namespace Break::HISL;
Node* root = createNode(Node::UNDEFINED);
Node* current = root;
NType* multi_var_init_type;
extern int yylex();
%}


%union{
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
}

%token <string> ID TYPE RETURN FLOAT INT BOOLCONST
%token <token>  OPEN_BRACE CLOSE_BRACE OPEN_CBRACE CLOSE_CBRACE SEMICOLON NONE
%token <token>  EQL COMMA IF ELSE PLUS MINUS MULTIPLY DEVIDE NOT INC DEC PLUS_EQL
%token <token>  MINUS_EQL MULTIPLY_EQL DEVIDE_EQL DOT WHILE FOR GREATER LESS
%token <token>  EQL_Q NEQL_Q GREATER_EQUAL LESS_EQUAL AND OR AND_Q OR_Q

//%type <token> func_dcl block;
%type<node> program
%type <numFloat> numFloat
%type <numInteger> numInteger
%type <ident> ident
%type <ntype> type
%type <func_call> func_call
%type <string> binary_op unary_op
%type <assignment> assignment
%type <expr> expr
%type <stmt> stmt expr_stmt
%type <block> block stmts
%type <func_dcl> func_dcl
%type <var_dcl> var_dcl
%type <ret_stmt> jump_stmt
%type <var_list> func_dcl_args
%type <expr_list> call_args
%type <stmt> if_stmt selection_stmt loop_stmt
%type <var_list> multi_var_dcl
%type <while_stmt> while_stmt
%type <for_stmt> for_stmt
%type <const_expr> const_expr
%type <unary_expr> unary_expr

%start program

%%

program : stmts { std::cout<<"program"<<std::endl; }
        ;

stmt : func_dcl { $$ = $1; }
     | expr_stmt { }
     | jump_stmt { $$ = $1; }
     | var_dcl SEMICOLON{$$ = $1;}
     | multi_var_dcl SEMICOLON {$$ = createNMVariableDeclaration(*$1);}
     | selection_stmt {$$ = $1;}
     | loop_stmt {$$ = $1;}
     ;

selection_stmt : if_stmt {$$=$1;}
               ;

loop_stmt : while_stmt {$$=$1;}
          | for_stmt {$$=$1;}
          ;

if_stmt : IF OPEN_BRACE expr CLOSE_BRACE block ELSE block {$$ = createNIfStatement(*$3,*$5, createNElseStatement(*$7)); }
        | IF OPEN_BRACE expr CLOSE_BRACE block ELSE stmt {$$ = createNIfStatement(*$3,*$5, createNElseStatement(*$7)); }
        | IF OPEN_BRACE expr CLOSE_BRACE stmt ELSE stmt {$$ = createNIfStatement(*$3,*$5, createNElseStatement(*$7)); }
        | IF OPEN_BRACE expr CLOSE_BRACE stmt ELSE block {$$ = createNIfStatement(*$3,*$5, createNElseStatement(*$7)); }
        | IF OPEN_BRACE expr CLOSE_BRACE stmt  { $$ = createNIfStatement(*$3,*$5,NULL); }
        | IF OPEN_BRACE expr CLOSE_BRACE block { $$ = createNIfStatement(*$3,*$5,NULL); }
        ;

for_stmt : FOR OPEN_BRACE stmt stmt expr CLOSE_BRACE block {$$ = createNForStatement(*$3,*$4,*$5,*$7);}
         | FOR OPEN_BRACE stmt stmt expr CLOSE_BRACE stmt {$$ = createNForStatement(*$3,*$4,*$5,*$7);}
         ;

while_stmt : WHILE OPEN_BRACE expr CLOSE_BRACE block {$$ = createNWhileStatement(*$3,*$5);}
           | WHILE OPEN_BRACE expr CLOSE_BRACE stmt  {$$ = createNWhileStatement(*$3,*$5);}
           ;

stmts : stmt { $$ = new NBlock(); $$->statements.push_back($<stmt>1);}
      | stmts stmt { $1->statements.push_back($<stmt>2); }
      ;

expr_stmt : expr SEMICOLON {$$ = createNExpressionStatement(*$1);}
          ;

func_dcl : type ident OPEN_BRACE func_dcl_args CLOSE_BRACE block {
  $$ = createNFunctionDeclaration(*$1,*$2,*$4,*$6);
  addChild(current,$$);
  //current = $$;
         }
         ;

block : OPEN_CBRACE stmts CLOSE_CBRACE { $$ = $2;}
      | OPEN_CBRACE CLOSE_CBRACE { $$ = new NBlock(); $$->type = Node::BLOCK; }
      ;

numeric : numFloat { std::cout<<"numFloat"<<std::endl; }
        | numInteger { std::cout<<"numInteger"<<std::endl; }
        ;

numFloat : FLOAT { $$ = createNFloat(toFloat(*$1));}
         | MINUS FLOAT {$$ = createNFloat(-1*toFloat(*$2));}
         | PLUS FLOAT {$$ = createNFloat(toFloat(*$2));}
         ;

numInteger : INT { $$ = createNInteger(toInt(*$1));}
           | MINUS INT {$$ = createNInteger(-1*toInt(*$2));}
           | PLUS INT {$$ = createNInteger(toInt(*$2));}
           ;

expr : assignment {}
     | func_call { std::cout<<"Function Call"<<std::endl; }
     | ident { std::cout<<"Just ID"<<std::endl; }
     | expr binary_op expr {$$ = createNBinaryOperator(*$1,*$2,*$3);}
     | unary_expr {$$ = $1;}
     | numeric {}
     | const_expr {$$=$1;}
     | OPEN_BRACE expr CLOSE_BRACE { $$ = $2;}
     ;

unary_expr : unary_op expr {$$ = createNUnaryOperator(*$1,*$2,false);}
           | expr INC {$$ = createNUnaryOperator("++",*$1,true);}
           | expr DEC {$$ = createNUnaryOperator("--",*$1,true);}
           ;

const_expr : BOOLCONST {$$ = createNConstantExpression(*$1);}
           ;

func_call : ident OPEN_BRACE call_args CLOSE_BRACE { $$ = createNFunctionCall(*$1,*$3);}
          ;
jump_stmt : RETURN SEMICOLON { $$ = createNReturnStatement(NULL); }
          | RETURN expr SEMICOLON { $$ = createNReturnStatement($2); }
          ;

ident : ID { $$ = createNIdentifier(*$1);}
      ;
type : TYPE { $$ = createNType(*$1);}
     ;

binary_op : PLUS {$$ = new std::string("+");}
          | MINUS {$$ = new std::string("-");}
          | MULTIPLY {$$ = new std::string("*");}
          | DEVIDE {$$ = new std::string("/");}
          | EQL_Q {$$ = new std::string("==");}
          | NEQL_Q {$$ = new std::string("!=");}
          | GREATER {$$ = new std::string(">");}
          | LESS {$$ = new std::string("<");}
          | GREATER_EQUAL {$$ = new std::string(">=");}
          | LESS_EQUAL {$$ = new std::string("<=");}
          | PLUS_EQL {$$ = new std::string("+=");}
          | MINUS_EQL {$$ = new std::string("-=");}
          | MULTIPLY_EQL {$$ = new std::string("*=");}
          | DEVIDE_EQL {$$ = new std::string("/=");}
          | AND {$$ = new std::string("&");}
          | OR {$$ = new std::string("|");}
          | AND_Q {$$ = new std::string("&&");}
          | OR_Q {$$ = new std::string("||");}
          ;

unary_op : INC {$$ = new std::string("++");}
         | DEC {$$ = new std::string("--");}
         | MULTIPLY {$$ = new std::string("*");}
         | AND {$$ = new std::string("&");}
         | NOT {$$ = new std::string("!");}
         ;

assignment : ident EQL expr {$$ = createNAssignment(*$1,*$3);}
           ;
call_args: /*blank*/ {$$ = new ExpressionList();}
         | expr {$$ = new ExpressionList(); $$->push_back($1);}
         | call_args COMMA expr {$1->push_back($3);}
         ;

func_dcl_args : /*blank*/ {$$ = new VariableList();}
              | var_dcl {$$ = new VariableList(); $$->push_back($<var_dcl>1); }
              | func_dcl_args COMMA var_dcl {$1->push_back($<var_dcl>3);}
              ;
var_dcl : type ident {$$ = createNVariableDeclaration(*$1,*$2);}
        | type ident EQL expr{$$ = createNVariableDeclaration(*$1,*$2,$4);}
        ;

multi_var_dcl : type ident {$$ = new VariableList(); $$->push_back(createNVariableDeclaration(*$1,*$2));}
              | type ident EQL expr {$$ = new VariableList(); $$->push_back(createNVariableDeclaration(*$1,*$2,$4));}
              | multi_var_dcl COMMA ident {$$->push_back(createNVariableDeclaration((*$$)[0]->VarType, *$3));}
              | multi_var_dcl COMMA ident EQL expr {$$->push_back(createNVariableDeclaration((*$$)[0]->VarType, *$3,$5));}
              ;
%%

void yyerror(char* e){
  std::cout<<e<<std::endl;
}

int main(){
  //int wait=0;
  //std::cin>>wait;
  auto res = yyparse();
  if(root){
    std::cout<<"Program is ok"<<std::endl;
    std::cout<<"Program has #"<<root->children.size()<<" children"<<std::endl;
    std::stringstream ss;
    for(int i=0;i<root->children.size();i++)
      root->children[i]->generateCode(ss);
    std::cout<<ss.str()<<std::endl;
  }
  //deleteNode(root);
  delete root;
  return 0;
}
