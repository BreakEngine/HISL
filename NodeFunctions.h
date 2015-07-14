#ifndef NODE_FUCNTIONS_H
#define NODE_FUCNTIONS_H
#include "Node.h"
namespace Break{
  namespace HISL{

    int toInt(std::string str){
      return std::stoi(str);
    }

    float toFloat(std::string str){
      return std::stof(str);
    }
    Node* createNode(Node::Type _type){
      Node* res = new Node();
      res->type = _type;
      res->parent = NULL;
      return res;
    }

    NInteger* createNInteger(int _value){
      NInteger* res = new NInteger();
      res->type = Node::INTEGER;
      res->parent = NULL;
      res->value = _value;
      return res;
    }

    NFloat* createNFloat(float _value){
      NFloat* res = new NFloat();
      res->type = Node::FLOAT;
      res->parent = NULL;
      res->value = _value;
      return res;
    }

    NIdentifier* createNIdentifier(std::string str){
      NIdentifier* res = new NIdentifier();
      res->type = Node::IDENTIFIER;
      res->parent = NULL;
      res->value = str;
      return res;
    }

    NType* createNType(std::string str){
      NType* res = new NType();
      res->type = Node::TYPE;
      res->parent = NULL;
      res->value = str;
      return res;
    }

    NFunctionCall* createNFunctionCall(NIdentifier& id, ExpressionList& args){
      NFunctionCall* res = new NFunctionCall(id,args);
      res->type = Node::FUNCTION_CALL;
      res->parent = NULL;
      return res;
    }

    NBinaryOperator* createNBinaryOperator(NExpression& lhs, std::string op, NExpression& rhs){
      NBinaryOperator* res = new NBinaryOperator(lhs,op,rhs);
      res->type = Node::BINARY_OPERATOR;
      res->parent = NULL;
      return res;
    }

    NAssignment* createNAssignment(NIdentifier& lhs, NExpression& rhs){
      NAssignment* res = new NAssignment(lhs,rhs);
      res->type = Node::ASSIGNMENT;
      res->parent = NULL;
      return res;
    }

    NBlock* createNBlock(StatementList& stmts){
      NBlock* res = new NBlock();
      res->type = Node::BLOCK;
      res->parent = NULL;
      res->statements = stmts;
      return res;
    }

    NExpressionStatement* createNExpressionStatement(NExpression& expr){
      NExpressionStatement* res = new NExpressionStatement(expr);
      res->type = Node::EXPRESSION_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NVariableDeclaration* createNVariableDeclaration(NType& type, NIdentifier& id){
      NVariableDeclaration* res = new NVariableDeclaration(type,id,NULL);
      res->type = Node::VARIABLE_DECLARATION;
      res->parent = NULL;
      return res;
    }

    NVariableDeclaration* createNVariableDeclaration(NType& type, NIdentifier& id, NExpression* expr){
      NVariableDeclaration* res = new NVariableDeclaration(type,id,expr);
      res->type = Node::VARIABLE_DECLARATION;
      res->parent = NULL;
      return res;
    }

    NFunctionDeclaration* createNFunctionDeclaration(NType& type, NIdentifier& id,
    VariableList& args, NBlock& block){
      NFunctionDeclaration* res = new NFunctionDeclaration(type,id,args,block);
      res->type = Node::FUNCTION_DECLARATION;
      res->parent = NULL;
      return res;
    }

    NReturnStatement* createNReturnStatement(NExpression* expr){
      NReturnStatement* res = new NReturnStatement(expr);
      res->type = Node::RETURN;
      res->parent = NULL;
      return res;
    }

    NIfStatement* createNIfStatement(NExpression& expr, NBlock& block, NElseStatement* else_stmt){
      NIfStatement* res = new NIfStatement(expr,block,else_stmt);
      res->type = Node::IF_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NIfStatement* createNIfStatement(NExpression& expr, NStatement& stmt, NElseStatement* else_stmt){
      NBlock* block = new NBlock();
      block->statements.push_back(&stmt);

      NIfStatement* res = new NIfStatement(expr,*block,else_stmt);
      res->type = Node::IF_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NElseStatement* createNElseStatement(NBlock& block){
      NElseStatement* res = new NElseStatement(block);
      res->type = Node::ELSE_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NMVariableDeclaration* createNMVariableDeclaration(VariableList& vars){
      NMVariableDeclaration* res = new NMVariableDeclaration(vars);
      res->type = Node::MULTI_VARIABLE_DECLARATION;
      res->parent = NULL;
      return res;
    }

    NElseStatement* createNElseStatement(NStatement& stmt){
      NBlock* block = new NBlock();
      block->statements.push_back(&stmt);

      NElseStatement* res = new NElseStatement(*block);
      res->type = Node::ELSE_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NWhileStatement* createNWhileStatement(NExpression& expr,NBlock& block){
      NWhileStatement* res = new NWhileStatement(expr,block);
      res->type = Node::WHILE_STATEMENT;
      res->parent = NULL;
      return res;
    }

    NWhileStatement* createNWhileStatement(NExpression& expr,NStatement& stmt){
      NBlock* block = new NBlock();
      block->statements.push_back(&stmt);

      NWhileStatement* res = new NWhileStatement(expr,*block);
      res->type = Node::WHILE_STATEMENT;
      res->parent = NULL;
      return res;
    }

    void deleteNode(Node* node){
      /*if(node != NULL){
        for(int i=0;i<node->children.size();i++)
            deleteNode(node->children[i]);
          delete node;
      }*/
      delete node;
    }

    void addChild(Node* _parent, Node* child){
      child->parent = _parent;
      _parent->children.push_back(child);
    }

  }
}
#endif
