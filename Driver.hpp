#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include "location.hh"
#include "Globals.hpp"
#include "Env.hpp"

namespace HISL{

	enum class PType : int{
		NONE = -1, INT = 1, FLOAT = 2, TYPE = 3, ID = 4, DECLARATION = 5,
		VARIABLE_DECLARATION = 6, STRUCT = 7, SEMANTIC_VARIABLE = 8, IOBUFFER = 9,
		BLOCK = 10, VERTEX = 11, ARGUMENT = 12, FUNCTION_DECLARATION = 13,
		FUNCTION_DEFINITION = 14, PROGRAM = 15, BINARY_EXP = 16, UNARY_EXP = 17,
		EXPR_STMT = 18, ARRAY_CALL = 19, VAR_CALL = 20, ACCESS_CHAIN = 21,
		ASSIGNMENT = 22, FUNCTION_CALL = 23, UNIFORM = 24, ARRAY_DECLARATION = 25,
		CONFIG_STATEMENT = 26, ROUTINE = 27, PIXEL = 28, TYPE_CONSTRUCTOR = 29
	};
	class PTVariableList;
	class PTId;
	class PTType;
	class PTVariableDeclaration;
	class PTSemanticVariable;
	class PTBlock;
	class PTStatement;
	class PTArg;
	class PTFunctionDeclaration;
	class PTFunctionDefinition;
	class PTForwardDeclaration;
	class PTProgram;
	class PTStruct;
	class PTIOBuffer;
	class PTStage;
	class PTExpressionStmt;
	class PTAssignment;
	class PTExpression;
	class PTLValue;
	class PTBinaryExpression;
	class PTUnaryExpression;
	class PTExpressionStmt;
	class PTVarCall;
	class PTArrayCall;
	class PTAccessChain;
	class PTInt;
	class PTFloat;
	class PTAssignment;
	class PTFunctionCall;
	class PTUniform;
	class PTArrayDeclaration;
	class PTConfig;
	class PTRoutine;
	class PTTypeConstructor;

	class Dictionary;
	class PTNode{
	public:
		PTNode* m_parent;
		std::vector<PTNode*> m_children;
		PType m_type;

		Env* m_env;

		virtual ~PTNode(){
			for(auto node : m_children)
				if(node)
					delete node;
		}

		virtual void printTree(std::ostream& out){
			out<<"generic node {};"<<std::endl;
			out<<std::endl;
			for(auto child : m_children){
				child->printTree(out);
				out<<std::endl;
			}
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){

		}

		virtual void semanticAnalysis(Dictionary* dic){

		}

		virtual void handleMultiplication(){

		}
		virtual PTType* inferType(){
			return NULL;
		}

		virtual void generateCode(std::ostream& predef, std::ostream& code, compilerConfig* config){
			
		}

		virtual std::string getNodeName(){
			return "";
		}

		PTNode* finddfs(std::string name, PType t){
			//gaurd return for wierd values
			int tint = (int)m_type;
			if((tint <-1 && tint >29)||tint == 0)
				return NULL;

			for(int i=0;i<m_children.size();i++)
			{
				if(m_children[i]->m_type == t && m_children[i]->getNodeName() == name){
					return m_children[i];
				}else{
					auto dfs_ret = m_children[i]->find(name,t);
					if(dfs_ret != NULL)
						return dfs_ret;
				}
			}
			return NULL;
		}

		PTNode* find(std::string name, PType t){
			for(int i=0;i<m_children.size();i++)
			{
				if(m_children[i]->m_type == t && m_children[i]->getNodeName() == name){
					return m_children[i];
				}
			}
			return NULL;
		}
	};
	class Driver{
	public:
		Driver();
		~Driver();

		int parse(compilerConfig* config);
		int parseFile(std::string& path);

		void reset();

		void printTree();

		void correctTree();

		void semanticAnalysis();

		void handleMultiplication();

		std::string generateCode(compilerConfig* config);

		PTInt* createInteger(std::string& val);
		PTFloat* createFloat(std::string& val);
		PTType* createType(std::string val);
		PTId* createId(std::string val);
		PTForwardDeclaration* createDeclaration(PTNode* type, PTNode* id);
		PTVariableDeclaration* createVarDcl(PTNode* type, PTNode* idList);
		PTStruct* createStruct(PTNode* id,std::vector<PTStatement*>& data);
		PTUniform* createUniform(PTNode* id, std::vector<PTStatement*>& data);
		PTSemanticVariable* createSemanticVar(PTNode* type, PTNode* id, PTNode* sem);
		PTIOBuffer* createBuffer(PTNode* id,std::vector<PTSemanticVariable>& data);
		PTBlock* createBlock();
		PTStage* createVertex(PTNode* id, PTNode* block);
		PTStage* createPixel(PTNode* id, PTNode* block);
		PTArg* createArg(PTNode* type, PTNode* id);
		PTFunctionDeclaration* createFuncDcl(PTNode* ret, PTNode* id, std::vector<PTArg>& args);
		PTFunctionDefinition* createFuncDef(PTFunctionDeclaration* sign,PTBlock* block);
		PTProgram* createProgram(PTId* id, PTBlock* block);
		PTBinaryExpression* createBinaryExp(PTExpression* lhs, std::string* op, PTExpression* rhs);
		PTUnaryExpression* createUnaryExp(std::string* op, PTExpression* uhs, bool after=false);
		PTExpressionStmt* createExpressionStmt(PTExpression* expr);
		PTVarCall* createVarCall(std::string* id,std::string op="");
		PTArrayCall* createArrayCall(PTId* id,PTExpression* index,std::string op="");
		PTArrayDeclaration* createArrayDcl(PTNode* type,std::string id,PTInt* size);
		PTAccessChain* createAccessChain(PTLValue* chain);
		PTAssignment* createAssignment(PTLValue* lhs, std::string op, PTExpression* rhs);
		PTFunctionCall* createFunctionCall(PTAccessChain* id, std::vector<PTExpression*>* args);
		PTConfig* createConfigStatement(PTId* builtin, PTExpression* obj);
		PTRoutine* createRoutine(PTId* id,std::vector<PTConfig*>* data);
		PTTypeConstructor* createTypeConstructor(PTType* type,std::vector<PTExpression*>* args);

		int m_test;
		location* m_location;
		PTNode* m_PTroot,*m_std;
		Dictionary* m_dictionary;
	};
}