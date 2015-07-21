%{
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
}

%token <string> ID TYPE RETURN FLOAT INT BOOLCONST STRING
%token <token>  OPEN_BRACE CLOSE_BRACE OPEN_CBRACE CLOSE_CBRACE SEMICOLON NONE
%token <token>  EQL COMMA IF ELSE PLUS MINUS MULTIPLY DEVIDE NOT INC DEC PLUS_EQL
%token <token>  MINUS_EQL MULTIPLY_EQL DEVIDE_EQL WHILE FOR GREATER LESS
%token <token>  EQL_Q NEQL_Q GREATER_EQUAL LESS_EQUAL AND OR AND_Q OR_Q
%token <token>  OPEN_SQBRACE CLOSE_SQBRACE STRUCT IOBUFFER COLON VERTEX PIXEL ROUTINE
%token <token>  PROGRAM DOT ARROW GLSL HLSL

//%type <token> func_dcl block;
%type<node> program
%type <numFloat> numFloat
%type <numInteger> numInteger
%type <ident> ident ident_all
%type <ntype> type
%type <func_call> func_call
%type <string> binary_op unary_op
%type <assignment> assignment
%type <expr> expr
%type <stmt> stmt expr_stmt
%type <block> block stmts ioblock iostmts
%type <func_dcl> func_dcl
%type <var_dcl> var_dcl
%type <ret_stmt> jump_stmt
%type <var_list> func_dcl_args
%type <expr_list> call_args init_list
%type <stmt> if_stmt selection_stmt loop_stmt
%type <var_list> multi_var_dcl
%type <while_stmt> while_stmt
%type <for_stmt> for_stmt
%type <const_expr> const_expr
%type <unary_expr> unary_expr
%type <arr_dcl> arr_dcl
%type <arr_call> arr_call
%type <strct> strct
%type <iobfr> iobuffer
%type <svar_dcl> semantic_var_dcl
%type <stage> stage
%type <routine> routine
%type <gpu_program> gpu_program
%type <my_string> my_string
%type <native> native

%start program

%%

program : stmts { std::cout<<"program"<<std::endl;
    //dive.clear();
  }
        ;

stmt : func_dcl { $$ = $1; }
     | expr_stmt { }
     | jump_stmt { $$ = $1; }
     | var_dcl SEMICOLON{$$ = $1;}
     | multi_var_dcl SEMICOLON {$$ = createNMVariableDeclaration(*$1);}
     | arr_dcl SEMICOLON {$$=$1;}
     | selection_stmt {$$ = $1;}
     | loop_stmt {$$ = $1;}
     | strct SEMICOLON {$$ = $1;}
     | iobuffer SEMICOLON {$$ = $1;}
     | stage SEMICOLON {$$=$1;}
     | routine SEMICOLON {$$=$1;}
     | gpu_program SEMICOLON {$$=$1;}
     | native SEMICOLON {$$ = $1;}
     ;

native : GLSL OPEN_CBRACE my_string CLOSE_CBRACE {$$ = createNNative(Node::GLSL,*$3); nodes->push_back($$);}
       | HLSL OPEN_CBRACE my_string CLOSE_CBRACE {$$ = createNNative(Node::HLSL,*$3); nodes->push_back($$);}
       ;
       
my_string : STRING {$$ = createNString(*$1);}
          ;

gpu_program : PROGRAM ident block {$$ = createNProgram(*$2,*$3); nodes->push_back($$);}
            ;

stage : VERTEX ident block {$$ = createNVertex(*$2,*$3); nodes->push_back($$);}
      | PIXEL ident block {$$ = createNPixel(*$2,*$3); nodes->push_back($$);}
      //| GEOMTERY
      //| TESSLATION Shader
      ;

routine : ROUTINE ident block {$$ = createNRoutine(*$2,*$3); nodes->push_back($$);}
        ;

iobuffer : IOBUFFER ident ioblock {$$ = createNIOBuffer(*$2,*$3); nodes->push_back($$);}
         ;

ioblock : OPEN_CBRACE iostmts CLOSE_CBRACE { $$ = $2;}
        | OPEN_CBRACE CLOSE_CBRACE { $$ = new NBlock(); $$->type = Node::BLOCK; }
        ;

semantic_var_dcl : type ident COLON ident {$$ = createNSVariableDeclaration(*$1,*$2, *$4);}
                 ;

selection_stmt : if_stmt {$$=$1;}
               ;

arr_dcl : type ident OPEN_SQBRACE numInteger CLOSE_SQBRACE {$$ = createNArrayDeclaration(*$1,*$2,$4->value);}
        | type ident OPEN_SQBRACE numInteger CLOSE_SQBRACE EQL OPEN_CBRACE init_list CLOSE_CBRACE {$$ = createNArrayDeclaration(*$1,*$2,$4->value,$8);}
        ;
arr_call : ident OPEN_SQBRACE expr CLOSE_SQBRACE {$$= createNArrayCall(*$1,*$3);}
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

iostmts : semantic_var_dcl SEMICOLON {$$ = new NBlock(); $$->statements.push_back($<svar_dcl>1);}
        | iostmts semantic_var_dcl SEMICOLON {$1->statements.push_back($<svar_dcl>2);}
        ;

strct : STRUCT ident block {$$ = createNStruct(*$2,*$3); nodes->push_back($$);}
      ;

expr_stmt : expr SEMICOLON {$$ = createNExpressionStatement(*$1);}
          ;

func_dcl : type ident OPEN_BRACE func_dcl_args CLOSE_BRACE block {
  $$ = createNFunctionDeclaration(*$1,*$2,*$4,*$6);
  nodes->push_back($$);
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
     | ident_all { std::cout<<"Just ID"<<std::endl; }
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
          | type OPEN_BRACE call_args CLOSE_BRACE { $$ = createNFunctionCall(*$1,*$3);}
          ;
jump_stmt : RETURN SEMICOLON { $$ = createNReturnStatement(NULL); }
          | RETURN expr SEMICOLON { $$ = createNReturnStatement($2); }
          ;

ident : ID { $$ = createNIdentifier(*$1);}
      ;

ident_all : ID { $$ = createNIdentifier(*$1);}
          | arr_call {}
          ;
type : TYPE { $$ = createNType(*$1);}
     | ID {$$ = createNType(*$1);}
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
          | DOT {$$ = new std::string(".");}
          | ARROW {$$ = new std::string("->");}
          ;

unary_op : INC {$$ = new std::string("++");}
         | DEC {$$ = new std::string("--");}
         | MULTIPLY {$$ = new std::string("*");}
         | AND {$$ = new std::string("&");}
         | NOT {$$ = new std::string("!");}
         ;

assignment : ident_all EQL expr {$$ = createNAssignment(*$1,*$3);}
           ;
call_args: /*blank*/ {$$ = new ExpressionList();}
         | expr {$$ = new ExpressionList(); $$->push_back($1);}
         | call_args COMMA expr {$1->push_back($3);}
         ;

init_list: /*blank*/ {$$ = new ExpressionList();}
         | expr {$$ = new ExpressionList(); $$->push_back($1);}
         | init_list COMMA expr {$1->push_back($3);}
         ;

func_dcl_args : /*blank*/ {$$ = new VariableList();}
              | var_dcl {$$ = new VariableList(); $$->push_back($<var_dcl>1); }
              | func_dcl_args COMMA var_dcl {$1->push_back($<var_dcl>3);}
              ;
var_dcl : type ident {$$ = createNVariableDeclaration(*$1,*$2);}
        | type ident EQL expr{$$ = createNVariableDeclaration(*$1,*$2,$4);}
        ;

multi_var_dcl : var_dcl {$$ = new VariableList(); $$->push_back($1);}
              | multi_var_dcl COMMA ident {$$->push_back(createNVariableDeclaration((*$$)[0]->VarType, *$3));}
              | multi_var_dcl COMMA ident EQL expr {$$->push_back(createNVariableDeclaration((*$$)[0]->VarType, *$3,$5));}
              ;
%%

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
