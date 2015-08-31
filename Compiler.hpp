#pragma once
#include <sstream>
#include <iostream>
#include "Driver.hpp"
namespace HISL{
	class Compiler{
	public:
		virtual void compileVS(PTNode* vs, std::ostream& predef, std::ostream& out)=0;
		virtual void compilePS(PTNode* ps, std::ostream& predef, std::ostream& out)=0;
		virtual void compileInputBuffer(PTIOBuffer* buffer, std::ostream& predef, std::ostream& out,std::string objName)=0;
		virtual void compilePSInputBuffer(PTIOBuffer* buffer, std::ostream& predef, std::ostream& out,std::string instanceName)=0;
		virtual void compileMainFunc(PTFunctionDefinition* main,std::ostream& predef,std::ostream& code,PType stageType)=0;
		virtual void compileBlock(PTBlock* block,std::ostream& predef, std::ostream& code)=0;
		virtual void compileStatement(PTStatement* config,std::ostream& predef, std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}
		
		virtual void compileStatement(PTForwardDeclaration* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;	
		}

		virtual void compileStatement(PTConfig* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;	
		}

		virtual void compileStatement(PTVariableDeclaration* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;	
		}

		virtual void compileStatement(PTArrayDeclaration* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;	
		}

		virtual void compileStatement(PTFunctionDeclaration* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}

		virtual void compileStatement(PTFunctionDefinition* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}
		
		virtual void compileStatement(PTSemanticVariable* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}

		virtual void compileStatement(PTExpressionStmt* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}
		
		virtual void compileStatement(PTUniform* stmt,std::ostream& predef,std::ostream& code){
			code<<"generic statement;"<<std::endl;
		}

		void compileExpression(PTExpression* exp, std::ostream& predef, std::ostream& code){
			code<<"generic expression";
		}

		void compileExpression(PTInt* exp, std::ostream& predef, std::ostream& code){
			code<<exp->val;
		}

		void compileExpression(PTFloat* exp, std::ostream& predef, std::ostream& code){
			code<<exp->val;
		}

		void branchStatement(PTStatement* stmt,std::ostream& predef, std::ostream& code){
			switch(stmt->m_type){
					case PType::CONFIG_STATEMENT:
						compileStatement((PTConfig*)stmt,predef,code);
						break;
					case PType::VARIABLE_DECLARATION:
						compileStatement((PTVariableDeclaration*)stmt,predef,code);
						break;
					case PType::STRUCT:
						compileStatement((PTStruct*)stmt,predef,code);
						break;
					case PType::FUNCTION_DEFINITION:
					{
						auto main_func = (PTFunctionDefinition*)stmt;
						if(main_func->getNodeName() == "main"){
							compileMainFunc(main_func,predef,code,main_func->m_parent->m_parent->m_type);
						}else{
							compileStatement((PTFunctionDefinition*)stmt,predef,code);
						}
						break;
					}
					case PType::ARRAY_DECLARATION:
						compileStatement((PTArrayDeclaration*)stmt,predef,code);
						break;
					case PType::FUNCTION_DECLARATION:
						compileStatement((PTFunctionDeclaration*)stmt,predef,code);
						break;
					case PType::EXPR_STMT:
						compileStatement((PTExpressionStmt*)stmt,predef,code);
						break;
					case PType::DECLARATION:
						compileStatement((PTForwardDeclaration*)stmt,predef,code);
						break;	
					case PType::UNIFORM:
						compileStatement((PTUniform*)stmt,predef,code);
						break;	
					case PType::SEMANTIC_VARIABLE:
						compileStatement((PTSemanticVariable*)stmt,predef,code);
						break;
					default:
						compileStatement(stmt,predef,code);
						break;
				}
		}

		void compileStatement(PTStruct* obj, std::ostream& predef,std::ostream& code){
			code<<"struct "<<obj->id.val<<std::endl;
			code<<"{\n";
			for(int i=0;i<obj->data.size();i++){
				branchStatement(obj->data[i],predef,code);
			}
			code<<"};\n";
		}
	};
}