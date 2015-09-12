#pragma once
#include "PTree.hpp"
#include "Compiler.hpp"
#include "Globals.hpp"
namespace HISL{
	extern Driver* driver;
	class GLSLCompiler: public Compiler{
	public:
		static std::string main_input, main_output;
		static bool inside_main;
		static std::string stage_type; 
		static int uniform_slot,sampler_slot;
		void compileVS(PTNode* vs, std::ostream& predef, std::ostream& code) override
		{
			uniform_slot = 0;
			sampler_slot = 0;
			stage_type = "VS";
			
			auto cvs = (PTStage*)vs;
			assert(cvs!=NULL,"can't cast PTNode object to vertex shader object");

			predef<<"/*"<<std::endl;
			predef<<" * Generated using HISL - higher intermidate shading language"<<std::endl;
			predef<<" * version: "<<version_major<<"."<<version_minor<<std::endl;
			predef<<" */"<<std::endl;

			auto main_func = (PTFunctionDefinition*)vs->finddfs("main",PType::FUNCTION_DEFINITION);

			assert(main_func!= NULL,"undefined main entry function to vertex shader stage named '"+cvs->id.val+"'");

			for(int i=0;i<main_func->signature.args.size();i++){
				if(i>=1)
					break;
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
			
			if(main_func->signature.returnType.val=="void"){
				//do nothing
			}else{
				auto vs_out = main_func->m_env->find(main_func->signature.returnType.val);
				compileOutputBuffer((PTIOBuffer*)vs_out,predef,code);
			}
			compileBlock(&cvs->block,predef,code);
			Driver::m_program_info.m_routine.m_vertex.m_type = Stage::VERTEX;
		}
		
		void compilePS(PTNode* ps, std::ostream& predef, std::ostream& code)override{
			uniform_slot = 0;
			sampler_slot = 0;
			stage_type = "PS";
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
			Driver::m_program_info.m_routine.m_vertex.m_type = Stage::PIXEL;
		}

		void compileStatement(PTUniform* obj,std::ostream& predef,std::ostream& code)override{
			UniformInfo uni;
			uni.m_name = obj->id.val;
			uni.m_slot = uniform_slot;
			uniform_slot++;
			uni.m_size = 0;
			
			code<<"uniform "<<obj->id.val<<std::endl;
			code<<"{\n";
			int alignAssistant = 16,tem=0;
			for(int i=0;i<obj->data.size();i++){
				if(obj->data[i]->m_type == PType::VARIABLE_DECLARATION){
					auto vars = (PTVariableDeclaration*)obj->data[i];
					for(int i=0;i<vars->variables->dcl_list.size();i++){
						UniformElementInfo uei;
						uei.m_type = vars->variables->type.val;
						
						uei.m_name = vars->variables->dcl_list[i]->declarator.id.val;
						uei.m_offset = uni.m_size;
						uei.m_size = Dictionary::std_getType(uei.m_type)->getSize();
						
						int ss=uei.m_size;
						if(ss<=tem){
							uni.m_size+=ss;
							tem-=ss;
						}else{
							uni.m_size+=tem;
							uei.m_offset+=tem;
							tem=0;
							while(ss>0){
								ss-=alignAssistant;
								if(ss>=0){
									uni.m_size+=alignAssistant;
								}else{
									int em = ss*-1;
									uni.m_size += alignAssistant-em;
									tem=em;
								}
							}
						}
						uni.m_elements.push_back(uei);
					}
				} 
				branchStatement(obj->data[i],predef,code);
			}
			uni.m_size+=tem;
			code<<"};\n";
			
			if(stage_type == "VS"){
				Driver::m_program_info.m_routine.m_vertex.m_uniforms.push_back(uni);
			}else if(stage_type == "PS"){
				Driver::m_program_info.m_routine.m_pixel.m_uniforms.push_back(uni);
			}
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
			InputLayoutInfo* io = new InputLayoutInfo();
			io->m_name = buffer->id.val;
			
			main_input = buffer->id.val;
			for(int i=0;i<buffer->data.size();i++){
				InputElementInfo ieo;
				ieo.m_type = buffer->data[i].type.val;
				ieo.m_name = buffer->data[i].id.val;
				ieo.m_semantic = buffer->data[i].semantic.val;
				io->m_elements.push_back(ieo);
				predef<<"layout(location = "<<i+1<<") in "<<Dictionary::getGLSLEq(buffer->data[i].type.val)<<" "<<"g_usr_in"<<"_"<<buffer->data[i].id.val<<";"<<std::endl;
			}
			Driver::m_program_info.m_routine.m_vertex.m_inputLayout = io;
		}
		
		void compileOutputBuffer(PTIOBuffer* buffer,std::ostream& predef, std::ostream& code){
			main_output = buffer->id.val;
			for(int i=0;i<buffer->data.size();i++){
				predef<<"out "<<Dictionary::getGLSLEq(buffer->data[i].type.val)<<" "<<"g_usr_out_"<<buffer->data[i].id.val<<";\n";
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
			main_output = buffer->id.val;
			for(int i=0;i<buffer->data.size();i++){
				predef<<"in "<<Dictionary::getGLSLEq(buffer->data[i].type.val)<<" g_usr_out_"<<buffer->data[i].id.val<<";\n";
			}
			/*
			predef<<"in "<<buffer->id.val<<std::endl;
			predef<<"{\n";
			for(int i=0;i<buffer->data.size();i++){
				branchStatement(&buffer->data[i],code,predef);
			}
			predef<<"} "<<instanceName<<";\n";
			*/
		}

		void compileMainFunc(PTFunctionDefinition* main,std::ostream& predef,std::ostream& code,PType stageType) override{
			code<<"void main()"<<std::endl;
			code<<"{"<<std::endl;
			inside_main = true;
				compileBlock(&main->block,predef,code);
			inside_main = false;
			code<<"}"<<std::endl;
		}

		void compileBlock(PTBlock* block,std::ostream& predef, std::ostream& code) override
		{
			for(int i=0;i<block->instructions.size();i++){
				PTStatement* stmt = block->instructions[i];
				if(inside_main){
					if(stmt->m_type == PType::RETURN){
						code<<"return;\n";
					}else if(stmt->m_type == PType::VARIABLE_DECLARATION){
						auto decl_type = stmt->inferType();
						auto decl_obj = block->m_env->find(decl_type->val);
						if(decl_obj){
							if(decl_obj->m_type != PType::IOBUFFER)
								branchStatement(stmt,predef,code);
						}else{
							branchStatement(stmt,predef,code);
						}
					}else{
						branchStatement(stmt,predef,code);
					}
				}else{
					branchStatement(stmt,predef,code);
				}
			}
		}

		void branchExpression(PTExpression* exp, std::ostream& predef, std::ostream& code)override{
			switch(exp->m_type){
				case PType::ACCESS_CHAIN :
					compileExpression((PTRAccessChain*)exp,predef,code);
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
		void compileExpression(PTRAccessChain* exp,std::ostream& predef, std::ostream& code){
			/*
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
			*/
			
			PTLValue* it = exp->lval;
			PTNode* obj;
			PTType* obj_type;
			while(it!=NULL){
				obj = NULL;
				obj_type = NULL;
				if(it->m_type == PType::VAR_CALL){
					obj = exp->m_env->find(it->getName());
					
					if(obj != NULL)
						obj_type = obj->inferType();
						
					obj = NULL;
					if(obj_type != NULL)
						obj = exp->m_env->find(obj_type->val);
						
					
					if(obj && obj->m_type == PType::IOBUFFER){
						auto bfr = (PTIOBuffer*)obj;
						if(bfr->id.val == main_input){
							code<<"g_usr_in_";
						}else if(bfr->id.val == main_output){
							code<<"g_usr_out_";
						}
						//code<<it->op<<it->getName();
						it = it->next;
						if(it)
							code<<it->getName();
					}else if(obj_type && obj_type->val == "texture2D" && it->next && it->next->getName()=="sample"){
						code<<"texture("<<it->getName()<<", ";
						auto sample_func = (PTRFunctionCall*) it->next;
						branchExpression(sample_func->args[0],predef,code);
						code<<")";
						it = it->next;
					}else{
						code<<it->op<<it->getName();
					}
				}else if(it->m_type == PType::ARRAY_CALL){
					PTRArrayCall* arr = (PTRArrayCall*) it;
					
					code<<it->op<<it->getName()<<"[";
					if(arr->index)
						branchExpression(arr->index,predef,code);
					code<<"]";
				}else if(it->m_type == PType::FUNCTION_CALL){
					PTRFunctionCall* func = (PTRFunctionCall*)it;
					
					code<<it->op<<it->getName()<<"(";
					for(int i=0;i<func->args.size();i++){
						if(i!=0)
							code<<", ";
						branchExpression(func->args[i],predef,code);
					}
					code<<")";
				}
				if(it)
					it = it->next;
				else
					break;
			}
		}

		using Compiler::compileStatement;
		void compileStatement(PTNative* stmt,std::ostream& predef, std::ostream& code)override{
			if(stmt->m_type != PType::GLSL)
				return;
			
			code<<stmt->content;
		}
		void compileStatement(PTReturn* stmt,std::ostream& predef, std::ostream& code)override{
			code<<"return ";
			if(stmt->obj)
				branchExpression(stmt->obj,predef,code);
			code<<";\n";
		}
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
			bool isTex = false;
			if(var->type.val == "texture2D"){
				isTex = true;
				code<<"uniform ";
				std::string eqv = Dictionary::getGLSLEq(var->type.val);
				if(eqv.size()>0)
					code<<eqv<<" ";
				else
					code<<var->type.val<<" ";
			}else{
				std::string eqv = Dictionary::getGLSLEq(var->type.val);
				if(eqv.size()>0)
					code<<eqv<<" ";
				else
					code<<var->type.val<<" ";
			}
				
			if(var->variables){
				for(int i=0;i<var->variables->dcl_list.size();i++){
					if(isTex)
					{
						SamplerInfo soso;
						soso.m_name = var->variables->dcl_list[i]->declarator.id.val;
						soso.m_slot = sampler_slot;
						TextureInfo toto;
						toto.m_name = soso.m_name;
						toto.m_slot = sampler_slot;
						toto.m_sampler = soso;
						if(stage_type == "VS"){
							Driver::m_program_info.m_routine.m_vertex.m_textures.push_back(toto);
							Driver::m_program_info.m_routine.m_vertex.m_samplers.push_back(soso);
						}else if(stage_type=="PS"){
							Driver::m_program_info.m_routine.m_pixel.m_textures.push_back(toto);
							Driver::m_program_info.m_routine.m_pixel.m_samplers.push_back(soso);
						}
						sampler_slot++;
					}
					if(i!=0)
						code<<", ";
					if(var->variables->dcl_list[i]->declarator.pre)
						code<<var->variables->dcl_list[i]->declarator.pre->val;
						
					code<<var->variables->dcl_list[i]->declarator.id.val;
					
					if(var->variables->dcl_list[i]->declarator.post){
						if(var->variables->dcl_list[i]->declarator.post->isArray)
							code<<"["<<var->variables->dcl_list[i]->declarator.post->size<<"]";
					}
					
					
					if(var->variables->dcl_list[i]->initializer_list.size()==1){
						code<<" = ";
						branchExpression(var->variables->dcl_list[i]->initializer_list[0],predef,code);
					}else if(var->variables->dcl_list[i]->initializer_list.size()>1){
						code<<" = ";
						code<<"{";
						for(int j = 0;j<var->variables->dcl_list[i]->initializer_list.size();j++){
							if(j!=0)
								code<<", ";
							branchExpression(var->variables->dcl_list[i]->initializer_list[j],predef,code);
						}
						code<<"}";
					}
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
	std::string GLSLCompiler::main_input = "";
	std::string GLSLCompiler::main_output = "";
	bool GLSLCompiler::inside_main = false;
	std::string GLSLCompiler::stage_type = "";
	int GLSLCompiler::sampler_slot = 0;
	int GLSLCompiler::uniform_slot = 0;
}