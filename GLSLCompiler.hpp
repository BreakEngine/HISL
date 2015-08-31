#pragma once
#include "PTree.hpp"
#include "Compiler.hpp"
#include "Globals.hpp"
namespace HISL{
	class GLSLCompiler: public Compiler{
	public:
		void compileVS(PTNode* vs, std::ostream& predef, std::ostream& code) override
		{
			auto cvs = (PTStage*)vs;
			assert(cvs!=NULL,"can't cast PTNode object to vertex shader object");

			predef<<"/*"<<std::endl;
			predef<<" * Generated using HISL - higher intermidate shading language"<<std::endl;
			predef<<" * version: "<<version_major<<"."<<version_minor<<std::endl;
			predef<<" */"<<std::endl;

			auto main_func = (PTFunctionDefinition*)vs->finddfs("main",PType::FUNCTION_DEFINITION);

			assert(main_func!= NULL,"undefined main entry function to vertex shader stage named '"+cvs->id.val+"'");

			if(main_func->signature.returnType.val!="void"){
				//do nothing
			}else{
				//compileOutBlock
			}

			for(int i=0;i<main_func->signature.args.size();i++){
				auto inputBufferType = main_func->signature.args[i].type.val;
				auto bufferObj = (PTIOBuffer*)main_func->m_env->find(inputBufferType);
				bufferObj->isLayout = true;
				if(bufferObj!= NULL){
					if(main_func->signature.args[i].id != NULL)
						compileInputBuffer(bufferObj,predef,code,main_func->signature.args[i].id->val);
					else
						compileInputBuffer(bufferObj,predef,code,"");
				}else{
					if(main_func->signature.args[i].id != NULL)
						assert(false,"unidentified iobuffer object passed as parameter to main function '"+main_func->signature.args[i].id->val+"'\n note: main function input must be iobuffers only");
					else
						assert(false,"unidentified iobuffer object passed as parameter to main function\n note: main function input must be iobuffers only");
				}
			}
			
			
			compileBlock(&cvs->block,predef,code);
		}
		
		void compilePS(PTNode* ps, std::ostream& predef, std::ostream& code)override{
			auto cps = (PTStage*)ps;
			assert(cps!=NULL,"can't cast PTNode object to pixel shader");
			predef<<"/*"<<std::endl;
			predef<<" * Generated using HISL - higher intermidate shading language"<<std::endl;
			predef<<" * version: "<<version_major<<"."<<version_minor<<std::endl;
			predef<<" */"<<std::endl;
			
			auto main_func = (PTFunctionDefinition*)ps->finddfs("main",PType::FUNCTION_DEFINITION);
			
			assert(main_func != NULL,"undefined main entry function to pixel shader");
			
			assert(main_func->signature.returnType.val == "void","pixel shader main function can't have a return type");
			
			for(int i=0;i<main_func->signature.args.size();i++){
				auto inputBufferType = main_func->signature.args[i].type.val;
				auto bufferObj = (PTIOBuffer*)main_func->m_env->find(inputBufferType);
				if(bufferObj!=NULL){
					if(main_func->signature.args[i].id!=NULL)
						compilePSInputBuffer(bufferObj,predef,code,main_func->signature.args[i].id->val);
				}else{
					if(main_func->signature.args[i].id !=NULL){
						if(main_func->signature.args[i].id != NULL)
						assert(false,"unidentified iobuffer object passed as parameter to main function '"+main_func->signature.args[i].id->val+"'\n note: main function input must be iobuffers only");
					else
						assert(false,"unidentified iobuffer object passed as parameter to main function\n note: main function input must be iobuffers only");
					}
				}
			}
			
			compileBlock(&cps->block,predef,code);
		}

		void compileStatement(PTUniform* obj,std::ostream& predef,std::ostream& code)override{
			code<<"uniform "<<obj->id.val<<std::endl;
			code<<"{\n";
			for(int i=0;i<obj->data.size();i++){
				branchStatement(obj->data[i],predef,code);
			}
			code<<"};\n";
		}
		
		void compileStatement(PTForwardDeclaration* stmt,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getGLSLEq(stmt->type.val);
			if(eqv.size()>0){
				code<<eqv<<" ";
			}else{
				code<<stmt->type.val<<" ";
			}
			
			code<<stmt->id.val<<";\n";
		}

		void compileInputBuffer(PTIOBuffer* buffer,std::ostream& predef, std::ostream& code,std::string objName) override
		{
			for(int i=0;i<buffer->data.size();i++){
				predef<<"layout(location = "<<i+1<<") in "<<Dictionary::getGLSLEq(buffer->data[i].type.val)<<" "<<objName<<"_"<<buffer->data[i].id.val<<";"<<std::endl;
			}
		}
		
		void compileStatement(PTSemanticVariable* stmt,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getGLSLEq(stmt->type.val);
			if(eqv.size()>0){
				code<<eqv<<" ";
			}else{
				code<<stmt->type.val<<" ";
			}
			
			code<<stmt->id.val<<";\n";
		}
		
		void compilePSInputBuffer(PTIOBuffer* buffer, std::ostream& predef, std::ostream& code,std::string instanceName)override{
			predef<<"in "<<buffer->id.val<<std::endl;
			predef<<"{\n";
			for(int i=0;i<buffer->data.size();i++){
				branchStatement(&buffer->data[i],code,predef);
			}
			predef<<"} "<<instanceName<<";\n";
		}

		void compileMainFunc(PTFunctionDefinition* main,std::ostream& predef,std::ostream& code,PType stageType) override{
			code<<"void main()"<<std::endl;
			code<<"{"<<std::endl;
				compileBlock(&main->block,predef,code);
			code<<"}"<<std::endl;
		}

		void compileBlock(PTBlock* block,std::ostream& predef, std::ostream& code) override
		{
			for(int i=0;i<block->instructions.size();i++){
				PTStatement* stmt = block->instructions[i];
				branchStatement(stmt,predef,code);
			}
		}

		void branchExpression(PTExpression* exp, std::ostream& predef, std::ostream& code){
			switch(exp->m_type){
				case PType::ACCESS_CHAIN :
					compileExpression((PTAccessChain*)exp,predef,code);
				break;
				case PType::INT:
					compileExpression((PTInt*)exp,predef,code);
				break;
				case PType::FLOAT:
					compileExpression((PTFloat*)exp,predef,code);
				break;
				case PType::ARGUMENT:
					compileExpression((PTArg*)exp,predef,code);
				break;
				case PType::ASSIGNMENT:
					compileExpression((PTAssignment*)exp,predef,code);
				break;
				case PType::UNARY_EXP:
					compileExpression((PTUnaryExpression*)exp,predef,code);
				break;
				case PType::FUNCTION_CALL:
					compileExpression((PTFunctionCall*)exp,predef,code);
				break;
				case PType::BINARY_EXP:
					compileExpression((PTBinaryExpression*)exp,predef,code);
				break;
				case PType::TYPE_CONSTRUCTOR:
					compileExpression((PTTypeConstructor*)exp,predef,code);
				break;
				default:
					compileExpression(exp,predef,code);
				break;
			}
		}

		using Compiler::compileExpression;
		
		void compileExpression(PTBinaryExpression* exp,std::ostream& predef, std::ostream& code){
			branchExpression(&exp->lhs,predef,code);
			code<<" "<<exp->op<<" ";
			branchExpression(&exp->rhs,predef,code);
		}
		
		void compileExpression(PTFunctionCall* exp,std::ostream& predef, std::ostream& code){
			
			PTLValue* lval = exp->chain.id;
			
			while(lval!=NULL){
				if(lval->m_type == PType::VAR_CALL){
					code<<lval->op<<lval->getName();
				}else if(lval->m_type == PType::ARRAY_CALL){
					code<<lval->op<<lval->getName()<<"[]";
				}
				lval = lval->next;
			}
			
			code<<"(";
			for(int i=0;i<exp->args.size();i++){
				if(i!=0)
					code<<", ";
					
				branchExpression(exp->args[i],predef,code);
			}
			code<<")";
			//code<<"function()";
		}
		
		void compileExpression(PTUnaryExpression* exp,std::ostream& predef, std::ostream& code){
			if(exp->after){
				branchExpression(&exp->uhs,predef,code);
				code<<exp->op;
			}else{
				code<<exp->op;
				branchExpression(&exp->uhs,predef,code);
			}
		}
		
		void compileExpression(PTTypeConstructor* exp,std::ostream& predef, std::ostream& code){
			std::string eqv = Dictionary::getGLSLEq(exp->type.val);
			if(eqv.size()>0){
				code<<eqv<<" ";
			}else{
				code<<exp->type.val<<" ";
			}
			
			code<<"(";
			for(int i=0;i<exp->args.size();i++){
				if(i!=0)
					code<<", ";
					
				branchExpression(exp->args[i],predef,code);
			}
			code<<")";
		}
		
		void compileExpression(PTAssignment* exp,std::ostream& predef, std::ostream& code){
			branchExpression(&exp->lhs,predef,code);
			code<<" "<<exp->op<<" ";
			branchExpression(&exp->rhs,predef,code);
		}
		
		void compileExpression(PTArg* exp,std::ostream& predef, std::ostream& code){
			std::string eqv = Dictionary::getGLSLEq(exp->type.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<exp->type.val<<" ";

			if(exp->id != NULL){
				code<<exp->id->val;
			}
		}
		void compileExpression(PTAccessChain* exp,std::ostream& predef, std::ostream& code){
			PTLValue* curr = exp->id;
			Env* env = exp->m_env;
			
			auto res = env->find(curr->getName());
			auto rtype = res->inferType();
			
			while(curr!=NULL){
				if(rtype!=NULL){
					auto obj = env->find(rtype->val);
					auto ioObj = (PTIOBuffer*)obj;
					if(obj!=NULL&&obj->m_type == PType::IOBUFFER&&ioObj->isLayout){
						code<<curr->getName()<<"_";
						if(curr->next!=NULL){
							code<<curr->next->getName();
							curr = curr->next;
							rtype = NULL;
						}
					}else{
						if(curr->m_type == PType::VAR_CALL){
							code<<curr->op<<curr->getName();
						}else if(curr->m_type == PType::ARRAY_CALL){
							auto arr = (PTArrayCall*)curr;
							code<<curr->op<<curr->getName()<<"[";
							//std::cout<<(int)arr->index.m_type<<std::endl;
							branchExpression(&(arr->index),predef,code);
							code<<"]";
						}
					}
				}else{
					if(curr->m_type == PType::VAR_CALL){
						code<<curr->op<<curr->getName();
					}else if(curr->m_type == PType::ARRAY_CALL){
						auto arr = (PTArrayCall*)curr;
						code<<curr->op<<curr->getName()<<"[";
						//std::cout<<(int)arr->index.m_type<<std::endl;
						branchExpression(&(arr->index),predef,code);
						code<<"]";
					}
				}
				curr = curr->next;
			}
		}

		using Compiler::compileStatement;
		void compileStatement(PTConfig* config,std::ostream& predef, std::ostream& code) override{
			code<<Dictionary::getGLSLEq(config->builtin.val)<<" = ";
			branchExpression(config->id,predef,code);
			code<<";"<<std::endl;
		}

		void compileStatement(PTExpressionStmt* stmt,std::ostream& predef,std::ostream& code)override{
			branchExpression(&(stmt->expr),predef,code);
			code<<";\n";
		}
		void compileStatement(PTFunctionDefinition* func,std::ostream& predef,std::ostream& code) override{
			std::string eqv = Dictionary::getGLSLEq(func->signature.returnType.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<func->signature.returnType.val<<" ";

			code<<func->signature.id.val<<"(";
			for(int i=0;i<func->signature.args.size();i++){
				if(i!=0)
					code<<", ";
				branchExpression(&func->signature.args[i],predef,code);
			}
			code<<")";

			code<<"{\n";
			compileBlock(&func->block,predef,code);
			code<<"}\n";
		}

		void compileStatement(PTVariableDeclaration* var,std::ostream& predef, std::ostream& code) override{
			std::string eqv = Dictionary::getGLSLEq(var->type.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<var->type.val<<" ";
			for(int i=0;i<var->variables.ids.size();i++){
				if(i>0)
					code<<", ";
				code<<var->variables.ids[i]->val;
				if(var->variables.values[i]!=NULL){
					code<<" = ";
					branchExpression(var->variables.values[i],predef,code);
				}
			}
			code<<";"<<std::endl;
		}

		void compileStatement(PTArrayDeclaration* arr,std::ostream& predef, std::ostream& code) override{
			std::string eqv = Dictionary::getGLSLEq(arr->type.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<arr->type.val<<" ";

			code<<arr->id.val<<"["<<arr->size<<"]"<<";"<<std::endl;
		}

		void compileStatement(PTFunctionDeclaration* func,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getGLSLEq(func->returnType.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<func->returnType.val<<" ";

			code<<func->id.val<<"(";
			for(int i=0;i<func->args.size();i++){
				if(i!=0)
					code<<", ";
				branchExpression(&(func->args[i]),predef,code);
			}
			code<<");\n";
		}
	};
}