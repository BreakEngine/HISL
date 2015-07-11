#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>

namespace Break{
  namespace HISL{

    class NExpression;
    class NStatement;
    class NVariableDeclaration;
    typedef std::vector<NStatement*> StatementList;
    typedef std::vector<NExpression*> ExpressionList;
    typedef std::vector<NVariableDeclaration*> VariableList;

    class Node{
    public:
      enum Type{
        UNDEFINED, INTEGER, FLOAT, IDENTIFIER, TYPE,
        FUNCTION_CALL, BINARY_OPERATOR, ASSIGNMENT,
        BLOCK, EXPRESSION_STATEMENT, VARIABLE_DECLARATION,
        FUNCTION_DECLARATION, RETURN, IF_STATEMENT, ELSE_STATEMENT
      };
      Node* parent;
      std::vector<Node*> children;
      Type type;
      virtual ~Node(){
        for(int i=0;i<children.size();i++){
          if(children[i])
            delete children[i];
        }
      }
      virtual void generateCode(std::ostream& code){
        return;
      }
    };

    class NExpression: public Node{
    public:

    };

    class NStatement: public Node{

    };

    class NInteger: public NExpression{
    public:
      int value;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NInteger||"<<std::endl;
        code<<value<<std::endl;
      }
    };

    class NFloat: public NExpression{
    public:
      float value;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NFloat||"<<std::endl;
        code<<value<<std::endl;
      }
    };

    class NIdentifier: public NExpression{
    public:
      std::string value;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NIdentifier||"<<std::endl;
        code<<value<<std::endl;
      }
    };

    class NType: public NExpression{
    public:
      std::string value;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NType||"<<std::endl;
        code<<value<<std::endl;
      }
    };

    class NFunctionCall: public NExpression{
    public:
      NIdentifier& id;
      ExpressionList& args;

      NFunctionCall(NIdentifier& _id, ExpressionList& _args):id(_id), args(_args){

      }
      virtual ~NFunctionCall(){
        for(int i=0;i<args.size();i++)
          if(args[i])
            delete args[i];
      }
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NFunctionCall||"<<std::endl;
        id.generateCode(code);
        for(int i=0;i<args.size();i++)
          args[i]->generateCode(code);
      }
    };

    class NBinaryOperator: public NExpression{
    public:
      int op;
      NExpression& lhs;
      NExpression& rhs;

      NBinaryOperator(NExpression& _lhs, int _op, NExpression& _rhs)
      :lhs(_lhs), op(_op), rhs(_rhs){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate NBinaryOperator||"<<std::endl;
        lhs.generateCode(code);
        code<<op;
        rhs.generateCode(code);
      }
    };

    class NAssignment: public NExpression{
    public:
      NIdentifier& lhs;
      NExpression& rhs;

      NAssignment(NIdentifier& _lhs, NExpression& _rhs)
      :lhs(_lhs), rhs(_rhs){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate NAssignment||"<<std::endl;
        lhs.generateCode(code);
        code<<" = ";
        rhs.generateCode(code);
      }
    };

    class NBlock:public NExpression{
    public:
      StatementList statements;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NBlock||"<<std::endl;
        for(int i=0;i<statements.size();i++)
          statements[i]->generateCode(code);
      }
    };

    class NExpressionStatement: public NStatement{
    public:
      NExpression& expression;

      NExpressionStatement(NExpression& _exp):expression(_exp){}
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NExpressionStatement||"<<std::endl;
        expression.generateCode(code);
      }
    };

    class NVariableDeclaration: public NStatement{
    public:
      NType& VarType;
      NIdentifier& id;
      NExpression *assignmentExpr;

      NVariableDeclaration(NType& _type, NIdentifier& _id)
      :VarType(_type), id(_id){}

      NVariableDeclaration(NType& _type, NIdentifier& _id, NExpression* _assign)
      :VarType(_type), id(_id), assignmentExpr(_assign){}

      virtual ~NVariableDeclaration(){
        if(assignmentExpr)
          delete assignmentExpr;
      }

      virtual void generateCode(std::ostream& code){
        code<<"||Generate NVariableDeclaration||"<<std::endl;
        VarType.generateCode(code);
        id.generateCode(code);
        if(assignmentExpr)
          assignmentExpr->generateCode(code);
      }
    };

    class NReturnStatement: public NStatement{
    public:
      NExpression* expr;

      NReturnStatement(NExpression* _expr):expr(_expr){}
      virtual ~NReturnStatement(){
        if(expr)
          delete expr;
      }
      virtual void generateCode(std::ostream& code){
        code<<"||Generate NReturnStatement||"<<std::endl;
        code<<"return "<<std::endl;
        if(expr)
          expr->generateCode(code);
      }
    };

    class NFunctionDeclaration: public NStatement{
    public:
      NType& FuncType;
      NIdentifier& id;
      VariableList& args;
      NBlock& block;

      NFunctionDeclaration(NType& _type, NIdentifier& _id,
      VariableList& _args, NBlock& _block):FuncType(_type),
      id(_id), args(_args), block(_block){}

      virtual ~NFunctionDeclaration(){
        for(int i=0;i<args.size();i++)
          if(args[i])
            delete args[i];
      }

      virtual void generateCode(std::ostream& code){
        code<<"||Generate NFunctionDeclaration||"<<std::endl;
        FuncType.generateCode(code);
        id.generateCode(code);
        for(int i=0;i<args.size();i++)
          if(args[i])
            args[i]->generateCode(code);
        block.generateCode(code);
      }
    };

    class NElseStatement: public NStatement{
    public:
      NBlock& block;

      NElseStatement(NBlock& _block):block(_block){}
      virtual void generateCode(std::ostream& code){
        code<<"||Generate Else Statement||"<<std::endl;
        code<<"else ";
        block.generateCode(code);
      }
    };

    class NIfStatement: public NStatement{
    public:
      NExpression& expr;
      NBlock& block;
      NElseStatement* else_stmt;

      NIfStatement(NExpression& _expr, NBlock& _block)
      :expr(_expr), block(_block){}

      NIfStatement(NExpression& _expr, NBlock& _block,NElseStatement* _else)
      :expr(_expr), block(_block), else_stmt(_else){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate If Statement||"<<std::endl;
        code<<"if (";
        expr.generateCode(code);
        code<<")";
        block.generateCode(code);
        if(else_stmt)
          else_stmt->generateCode(code);
      }
    };

    }
}

#endif /* end of include guard: NODE_H */
