#pragma once
#include "PTree.hpp"
#include "Compiler.hpp"
#include "Globals.hpp"
namespace HISL{
	class HLSLCompiler: public Compiler{
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

			}else{
			
			}

			for(int i=0;i<main_func->signature.args.size();i++){
				auto inputBufferType = main_func->signature.args[i].type.val;
				auto bufferObj = (PTIOBuffer*)main_func->m_env->find(inputBufferType);
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
			
			if(main_func->signature.returnType.val == "void"){
				prepareDefaultVSOutput(predef,code);
			}else{
				
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
		
		void compilePSInputBuffer(PTIOBuffer* buffer, std::ostream& predef, std::ostream& out,std::string instanceName)override{
			predef<<"struct "<<buffer->id.val<<std::endl;
			predef<<"{\n";
			for(int i=0;i<buffer->data.size();i++)
				branchStatement(&buffer->data[i],out,predef);
			predef<<"};\n";
		}
		
		void prepareDefaultVSOutput(std::ostream& predef,std::ostream& code){
			predef<<"struct g_vs_out"<<std::endl;
			predef<<"{\n";
			predef<<"float4 position : SV_POSITION;\n";
			predef<<"};\n";
			
			Dictionary::registerHLSL("g_position","g_vs_out_obj.position");
		}

		void compileStatement(PTUniform* obj,std::ostream& predef,std::ostream& code)override{
			code<<"cbuffer "<<obj->id.val<<std::endl;
			code<<"{\n";
			for(int i=0;i<obj->data.size();i++){
				branchStatement(obj->data[i],predef,code);
			}
			code<<"};\n";
		}
		
		void compileStatement(PTForwardDeclaration* stmt,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getHLSLEq(stmt->type.val);
			if(eqv.size()>0){
				code<<eqv<<" ";
			}else{
				code<<stmt->type.val<<" ";
			}
			
			code<<stmt->id.val<<";\n";
		}
		
		void compileStatement(PTSemanticVariable* stmt,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getHLSLEq(stmt->type.val);
			if(eqv.size()>0){
				code<<eqv<<" ";
			}else{
				code<<stmt->type.val<<" ";
			}
			
			code<<stmt->id.val<<" : "<<stmt->semantic.val<<";\n";
		}

		void compileInputBuffer(PTIOBuffer* buffer,std::ostream& predef, std::ostream& code,std::string objName) override
		{
			predef<<"struct "<<buffer->id.val<<std::endl;
			predef<<"{\n";
			for(int i=0;i<buffer->data.size();i++){
				branchStatement(&buffer->data[i],code,predef);
			}
			predef<<"};\n";
		}

		void compileMainFunc(PTFunctionDefinition* main,std::ostream& predef,std::ostream& code,PType stageType) override{
			if(main->signature.returnType.val == "void"&&stageType== PType::VERTEX){
				code<<"g_vs_out ";
			}else if(main->signature.returnType.val == "void"&&stageType== PType::PIXEL){
				code<<"float4 ";
			}else{
				code<<main->signature.returnType.val<<" ";
			}
			code<<"main(";
			for(int i=0;i<main->signature.args.size();i++){
				if(i!=0)
					code<<", ";
				branchExpression(&main->signature.args[i],predef,code);
			}
			code<<")";
			if(stageType == PType::PIXEL)
				code<<": SV_TARGET"<<std::endl;
			code<<"{"<<std::endl;
				if(main->signature.returnType.val == "void"&&stageType== PType::VERTEX){
					code<<"g_vs_out g_vs_out_obj;\n";
				}
				if(main->signature.returnType.val == "void"&&stageType== PType::PIXEL){
					code<<"float4 g_ps_color;\n";
					Dictionary::registerHLSL("g_color","g_ps_color");
				}
				compileBlock(&main->block,predef,code);
				if(stageType == PType::PIXEL)
					code<<"return g_ps_color;\n";
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
		
		void compileExpression(PTTypeConstructor* exp,std::ostream& predef, std::ostream& code){
			std::string eqv = Dictionary::getHLSLEq(exp->type.val);
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
		
		void compileExpression(PTBinaryExpression* exp,std::ostream& predef, std::ostream& code){
			PTType* ltype = exp->lhs.inferType();
			PTType* rtype = exp->rhs.inferType();
			static int scopes = 0;
			if(Dictionary::isMatrix(ltype->val) || Dictionary::isMatrix(rtype->val)){
				code<<"mul(";
				scopes++;
				branchExpression(&exp->lhs,predef,code);
				code<<", ";
				branchExpression(&exp->rhs,predef,code);
				for(int i=0;i<scopes;i++){
					code<<")";					
				}
				scopes = 0;
			}else{
				branchExpression(&exp->lhs,predef,code);
				code<<" "<<exp->op<<" ";
				branchExpression(&exp->rhs,predef,code);
			}
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
		
		void compileExpression(PTAssignment* exp,std::ostream& predef, std::ostream& code){
			branchExpression(&exp->lhs,predef,code);
			code<<" "<<exp->op<<" ";
			branchExpression(&exp->rhs,predef,code);
		}
		
		void compileExpression(PTArg* exp,std::ostream& predef, std::ostream& code){
			std::string eqv = Dictionary::getHLSLEq(exp->type.val);
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
			
			while(curr!=NULL){
				if(curr->m_type == PType::VAR_CALL){
					code<<curr->op<<curr->getName();
				}else if(curr->m_type == PType::ARRAY_CALL){
					auto arr = (PTArrayCall*)curr;
					code<<curr->op<<curr->getName()<<"[";
					//std::cout<<(int)arr->index.m_type<<std::endl;
					branchExpression(&(arr->index),predef,code);
					code<<"]";
				}
				curr = curr->next;
			}
		}

		using Compiler::compileStatement;
		void compileStatement(PTConfig* config,std::ostream& predef, std::ostream& code) override{
			code<<Dictionary::getHLSLEq(config->builtin.val)<<" = ";
			branchExpression(config->id,predef,code);
			code<<";"<<std::endl;
		}

		void compileStatement(PTExpressionStmt* stmt,std::ostream& predef,std::ostream& code)override{
			branchExpression(&(stmt->expr),predef,code);
			code<<";\n";
		}
		void compileStatement(PTFunctionDefinition* func,std::ostream& predef,std::ostream& code) override{
			std::string eqv = Dictionary::getHLSLEq(func->signature.returnType.val);
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
			std::string eqv = Dictionary::getHLSLEq(var->type.val);
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
			std::string eqv = Dictionary::getHLSLEq(arr->type.val);
			if(eqv.size()>0)
				code<<eqv<<" ";
			else
				code<<arr->type.val<<" ";

			code<<arr->id.val<<"["<<arr->size<<"]"<<";"<<std::endl;
		}

		void compileStatement(PTFunctionDeclaration* func,std::ostream& predef,std::ostream& code)override{
			std::string eqv = Dictionary::getHLSLEq(func->returnType.val);
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