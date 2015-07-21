#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <algorithm>

namespace Break{
  namespace HISL{

    class NExpression;
    class NStatement;
    class NVariableDeclaration;
    class Node;
    typedef std::vector<Node*> NodeList;
    typedef std::vector<NStatement*> StatementList;
    typedef std::vector<NExpression*> ExpressionList;
    typedef std::vector<NVariableDeclaration*> VariableList;

    extern void removeNode(NodeList* list,Node* node);

    class Node{
    public:
      enum Type{
        UNDEFINED, INTEGER, FLOAT, IDENTIFIER, TYPE,
        FUNCTION_CALL, BINARY_OPERATOR, ASSIGNMENT,
        BLOCK, EXPRESSION_STATEMENT, VARIABLE_DECLARATION,
        FUNCTION_DECLARATION, RETURN, IF_STATEMENT, ELSE_STATEMENT,
        MULTI_VARIABLE_DECLARATION, WHILE_STATEMENT, FOR_STATEMENT, CONST_EXPRESSION,
        UNARY_OPERATOR, ARRAY_DECLARATION, ARRAY_CALL, STRUCT, IOBUFFER,SEMANTIC_VARIABLE,
        VERTEX, TYPE_CONSTRUCTOR, PIXEL, ROUTINE, PROGRAM, STRING, GLSL, HLSL
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
      virtual void correctParseTree(NodeList* list,Node* Nparent){

      }
    };

    class NExpression: public Node{
    public:

    };

    class NStatement: public Node{
    public:
    };

    class NConstantExpression: public NExpression{
    public:
      std::string value;

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Constant Expression||"<<std::endl;
        code<<value<<std::endl;
      }
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

    class NString: public NStatement{
    public:
      std::string value;
      virtual void generateCode(std::ostream& code){
        code<<"||Generate STRING||"<<std::endl;
        code<<value<<std::endl;
      }
    };

    class NArrayDeclaration: public NStatement{
    public:
      NType& VarType;
      NIdentifier& id;
      unsigned int size;

      ExpressionList* init_list;

      NArrayDeclaration(NType& _type, NIdentifier& _id, unsigned int _size)
      :VarType(_type), id(_id), size(_size), init_list(NULL){}

      NArrayDeclaration(NType& _type, NIdentifier& _id, unsigned int _size, ExpressionList* il)
      :VarType(_type), id(_id), size(_size), init_list(il){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Array Declaration||"<<std::endl;
        VarType.generateCode(code);
        id.generateCode(code);
        code<<"["<<size<<"]";

        if(init_list){
          code<<" = {";
          for(int i=0;i<init_list->size();i++){
            (*init_list)[i]->generateCode(code);
            if(i!=init_list->size()-1)
              code<<",";
          }
          code<<"};";
        }

      }
    };


    class NArrayCall: public NIdentifier{
    public:
      NIdentifier& id;
      NExpression& ix;
      NArrayCall(NIdentifier& _id,NExpression& _ix):id(_id), ix(_ix){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Array Call||"<<std::endl;
        id.generateCode(code);
        code<<"[";
        ix.generateCode(code);
        code<<"]";
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
      std::string op;
      NExpression& lhs;
      NExpression& rhs;

      NBinaryOperator(NExpression& _lhs, std::string _op, NExpression& _rhs)
      :lhs(_lhs), op(_op), rhs(_rhs){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate NBinaryOperator||"<<std::endl;
        lhs.generateCode(code);
        code<<op;
        rhs.generateCode(code);
      }
    };

    class NUnaryOperator: public NExpression{
    public:
      std::string op;
      NExpression& uhs;
      bool after;

      NUnaryOperator(std::string _op, NExpression& _uhs, bool _after)
      :op(_op),uhs(_uhs),after(_after){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Unary Operator||"<<std::endl;
        if(after){
          uhs.generateCode(code);
          code<<op;
        }else{
          code<<op;
          uhs.generateCode(code);
        }
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
        code<<"{";
        for(int i=0;i<statements.size();i++)
          statements[i]->generateCode(code);
        code<<"}";
      }

      virtual void correctParseTree(NodeList* list,Node* Nparent){
        for(int i=0;i<statements.size();i++)
          statements[i]->correctParseTree(list,Nparent);
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

    class NSVariableDeclaration: public NStatement{
    public:
      NType& VarType;
      NIdentifier& id;
      NIdentifier& semantic;

      NSVariableDeclaration(NType& _type,NIdentifier& _id, NIdentifier& _semantic)
      :VarType(_type), id(_id), semantic(_semantic){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Semantic Variable||"<<std::endl;
        VarType.generateCode(code);
        id.generateCode(code);
        code<<" : ";
        semantic.generateCode(code);
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

    class NMVariableDeclaration:public NStatement{
    public:
      VariableList& variables;

      NMVariableDeclaration(VariableList& _var):variables(_var){}

      virtual ~NMVariableDeclaration(){
        for(int i=0;i<variables.size();i++)
          if(variables[i])
            delete variables[i];
      }

      NType* getType(){
        return &variables[0]->VarType;
      }

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Multi Variable Declaration||";
        for(int i=0;i<variables.size();i++){
          if(variables[i])
          {
            variables[i]->generateCode(code);
            code<<";";
          }
        }
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

      virtual void correctParseTree(NodeList* list,Node* Nparent){
        if(parent!= NULL)
          {
            removeNode(&parent->children,this);
          }
        Nparent->children.push_back(this);
        parent = Nparent;
        removeNode(list,this);
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

    class NWhileStatement: public NStatement{
    public:
      NExpression& expr;
      NBlock& block;

      NWhileStatement(NExpression& _expr, NBlock& _block)
      :expr(_expr), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate While Statement||"<<std::endl;
        code<<"while (";
        expr.generateCode(code);
        code<<")";
        block.generateCode(code);
      }
    };

    class NForStatement: public NStatement{
    public:
      NStatement& start;
      NStatement& condition;
      NExpression& increment;
      NBlock& block;

      NForStatement(NStatement& _start, NStatement& _cond, NExpression& _inc,NBlock& _blk)
      :start(_start), condition(_cond), increment(_inc), block(_blk){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate For Statement"<<std::endl;
        code<<"for (";
        start.generateCode(code);
        code<<";";
        condition.generateCode(code);
        code<<";";
        increment.generateCode(code);
        code<<")";
        block.generateCode(code);
      }
    };


    class NStruct: public NStatement{
    public:
      NIdentifier& id;
      NBlock& block;

      NStruct(NIdentifier& _id, NBlock& _block): id(_id), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate Struct Node||"<<std::endl;
        code<<"struct ";
        id.generateCode(code);
        block.generateCode(code);
        code<<";";
      }

      virtual void correctParseTree(NodeList* list,Node* Nparent){
        if(parent!= NULL)
          {
            removeNode(&parent->children,this);
          }
        Nparent->children.push_back(this);
        parent = Nparent;
        block.correctParseTree(list,this);
        removeNode(list,this);
      }
    };

    class NStage: public NStatement{
    public:
      NIdentifier& id;
      NBlock& block;

      NStage(NIdentifier& _id, NBlock& _block): id(_id), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate STAGE||"<<std::endl;
        if(type == Node::VERTEX)
          code<<"vertex";
        else if(type == Node::PIXEL)
          code<<"pixel";

        id.generateCode(code);
        block.generateCode(code);
      }

      virtual void correctParseTree(NodeList* list, Node* Nparent){
        if(parent!=NULL){
          removeNode(&parent->children,this);
        }
        Nparent->children.push_back(this);
        parent = Nparent;
        block.correctParseTree(list,this);
        removeNode(list,this);
      }
    };

    class NRoutine: public NStatement{
    public:
      NIdentifier& id;
      NBlock& block;

      NRoutine(NIdentifier& _id, NBlock& _block): id(_id), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate ROUTINE||"<<std::endl;
        code<<"routine";

        id.generateCode(code);
        block.generateCode(code);
      }

      virtual void correctParseTree(NodeList* list, Node* Nparent){
        if(parent!=NULL){
          removeNode(&parent->children,this);
        }
        Nparent->children.push_back(this);
        parent = Nparent;
        block.correctParseTree(list,this);
        removeNode(list,this);
      }
    };

    class NNative: public NStatement{
    public:
      NString& block;

      NNative(NString& _block):block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Native Block||"<<std::endl;
        block.generateCode(code);
      }

      virtual void correctParseTree(NodeList* list, Node* Nparent){
        if(parent!=NULL){
          removeNode(&parent->children,this);
        }
        Nparent->children.push_back(this);
        parent = Nparent;
        removeNode(list,this);
      }
    };
    class NProgram: public NStatement{
    public:
      NIdentifier& id;
      NBlock& block;

      NProgram(NIdentifier& _id, NBlock& _block): id(_id), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate PROGRAM||"<<std::endl;
        code<<"program";

        id.generateCode(code);
        block.generateCode(code);
      }

      virtual void correctParseTree(NodeList* list, Node* Nparent){
        if(parent!=NULL){
          removeNode(&parent->children,this);
        }
        Nparent->children.push_back(this);
        parent = Nparent;
        block.correctParseTree(list,this);
        removeNode(list,this);
      }
    };

    class NIOBuffer: public NStatement{
    public:
      NIdentifier& id;
      NBlock& block;

      NIOBuffer(NIdentifier& _id, NBlock& _block): id(_id), block(_block){}

      virtual void generateCode(std::ostream& code){
        code<<"||Generate IOBuffer||"<<std::endl;

        code<<"iobuffer";
        id.generateCode(code);
        block.generateCode(code);
      }
      virtual void correctParseTree(NodeList* list, Node* Nparent){
        if(parent!=NULL){
          removeNode(&parent->children,this);
        }
        Nparent->children.push_back(this);
        parent = Nparent;
        removeNode(list,this);
      }
    };

    }
}

#endif /* end of include guard: NODE_H */
