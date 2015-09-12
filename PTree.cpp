#include "PTree.hpp"
#include "GLSLCompiler.hpp"
#include "HLSLCompiler.hpp"
#include "ProgramInfo.hpp"
using namespace HISL;

extern Driver* driver;
PTType* PTInt::inferType(){
	auto t = new PTType();
	t->m_type = PType::TYPE;
	t->val = "int";
	return t;
}

PTType* PTFloat::inferType(){
	auto t = new PTType();
	t->m_type = PType::TYPE;
	t->val = "float";
	return t;
}

void PTProgram::generateCode(std::ostream& predef, std::ostream& code, compilerConfig* config){
		Compiler* cc;
		auto main_routine = (PTRoutine*)(this->finddfs(id.val,PType::ROUTINE));
		std::string vsStage = main_routine->evaluate(Dictionary::g_vs);
		std::string psStage = main_routine->evaluate(Dictionary::g_ps);
		
		auto vs = this->finddfs(vsStage,PType::VERTEX);
		auto ps = this->finddfs(psStage,PType::PIXEL);
		
		std::stringstream ps_predef,ps_code;

		assert(vs != NULL,"undefined vertex shader stage '"+vsStage+"'");
		assert(ps != NULL,"undefined pixel shader stage '"+psStage+"'");
		
		//filling program info
		driver->m_program_info.m_name = id.val;
		driver->m_program_info.m_routine.m_name = id.val;
		driver->m_program_info.m_routine.m_vertex.m_name = vsStage;
		driver->m_program_info.m_routine.m_pixel.m_name = psStage;
		
		if(config->language == "glsl"){
			cc = new GLSLCompiler();
			for(int i=0;i<block.instructions.size();i++){
				if(block.instructions[i]->m_type == PType::STRUCT ||
					block.instructions[i]->m_type == PType::DECLARATION){
					cc->branchStatement(block.instructions[i],predef,code);	
				}
			}
			cc->compileVS(vs,predef,code);
			cc->compilePS(ps,ps_predef,ps_code);
		}else if(config->language == "hlsl"){
			cc = new HLSLCompiler();
			for(int i=0;i<block.instructions.size();i++){
				if(block.instructions[i]->m_type == PType::STRUCT ||
					block.instructions[i]->m_type == PType::DECLARATION){
					cc->branchStatement(block.instructions[i],predef,code);	
				}
			}
			cc->compileVS(vs,predef,code);
			cc->compilePS(ps,ps_predef,ps_code);
		}
		//vs->generateCode(predef,code);
		//ps->generateCode(predef,code);
		std::stringstream vs_predef;
		vs_predef << predef.rdbuf();
		std::stringstream vs_code;
		vs_code << code.rdbuf();
		Driver::m_compiled_vs = vs_predef.str()+vs_code.str();
		Driver::m_compiled_ps = ps_predef.str()+ps_code.str();
		if(!config->outputToFile || config->debugMode){
			
			//std::cout<<"/****************************** VERTEX SHADER ******************************/"<<std::endl;
			//std::cout<<Driver::m_compiled_vs<<std::endl;
			//std::cout<<"/****************************** PIXEL SHADER ******************************/"<<std::endl;
			//std::cout<<Driver::m_compiled_ps<<std::endl;
			
		}
		return;
}

PTType* PTLValue::inferType(){
	PTType* obj_type=NULL;
	PTNode* obj = NULL;
	PTLValue* it = chain->lval;
	
	while(it!=NULL){
		switch(it->m_type){
			case PType::VAR_CALL:
				if(obj_type==NULL){
					obj = chain->m_env->find(it->getName());
					assert(obj!=NULL,"undefined variable call named '"+it->getName()+"'");
					obj_type = obj->inferType();
				}else{
					if(!Dictionary::std_isBuiltIn(obj_type->val)){
						obj = chain->m_env->find(obj_type->val);
						assert(obj!=NULL,"undefined type named '"+obj_type->val+"'");
						obj = obj->m_env->find(it->getName());
						assert(obj!=NULL,"undefined variable call named '"+it->getName()+"'");
						obj_type = obj->inferType();
					}else{
						auto ans = Dictionary::std_isMember(obj_type->val,it->getName());
						assert(ans!=NULL,"undefined member variable '"+it->getName()+"' of object type '"+obj_type->val+"' ");
						obj_type = new PTType();
						obj_type->val = ans->getReturnType();
					}
				}
			break;
			case PType::FUNCTION_CALL:
				if(obj_type==NULL){
					obj = chain->m_env->findFunction(it->getName());
					assert(obj!=NULL,"undefined function call named '"+it->getName()+"'");
					obj_type = obj->inferType();
				}else{
					if(!Dictionary::std_isBuiltIn(obj_type->val)){
						obj = chain->m_env->find(obj_type->val);
						assert(obj!=NULL,"undefined type named '"+obj_type->val+"'");
						obj = obj->m_env->findFunction(it->getName());
						assert(obj!=NULL,"undefined function call named '"+it->getName()+"'");
						obj_type = obj->inferType();
					}else{
						auto ans = Dictionary::std_isMember(obj_type->val,it->getName());
						assert(ans!=NULL,"undefined member function "+it->getName()+" of object type '"+obj_type->val+"' ");
						obj_type = new PTType();
						obj_type->val = ans->getReturnType();
					}
				}
			break;
			case PType::ARRAY_CALL:
				if(obj_type==NULL){
					obj = chain->m_env->find(it->getName());
					assert(obj!=NULL,"undefined array call named '"+it->getName()+"'");
					obj_type = obj->inferType();
				}else{
					if(!Dictionary::std_isBuiltIn(obj_type->val)){
						obj = chain->m_env->find(obj_type->val);
						assert(obj!=NULL,"undefined type named '"+obj_type->val+"'");
						obj = obj->m_env->find(it->getName());
						assert(obj!=NULL,"undefined array call named '"+it->getName()+"'");
						obj_type = obj->inferType();
					}else{
						auto ans = Dictionary::std_isMember(obj_type->val,it->getName());
						assert(ans!=NULL,"undefined member array "+it->getName()+" of object type '"+obj_type->val+"' ");
						obj_type = new PTType();
						obj_type->val = ans->getReturnType();
					}
				}
			break;
			default:
			break;
		}
		if(it == this)
			break;
		it = it->next;
	}
	return obj_type;
}

PTBlock* getBlock(PTStatement* stmt){
	if(stmt->m_type != PType::BLOCK){
		PTBlock* block = new PTBlock();
		block->m_type = PType::BLOCK;
		block->m_parent = NULL;
		block->m_env = NULL;
		block->instructions.push_back(stmt);
		return block;
	}else{
		return (PTBlock*)stmt;
	}
}

bool PTFunctionDefinition::returnGuard(PTBlock* block, std::string type, std::string functionName){
	bool found = false;
	for(int i=0;i<block->instructions.size();i++){
		if(block->instructions[i]->m_type == PType::RETURN){
			found = true;
			auto ret= (PTReturn*)block->instructions[i];
			if(type == "void"){
				assert(ret->obj == NULL,"uncompatiable return type of function '"+functionName+"'");
			}else{
				assert(ret->obj != NULL,"uncompatiable return type of function '"+functionName+"'");
				PTType* objType = ret->obj->inferType();
				assert(objType!=NULL,"[semantic analysis] unexpected function return object type '"+functionName+"'");
				assert(objType->val == type,"uncompatiable return type of function '"+functionName+"'");
			}
		}else if(block->instructions[i]->m_type == PType::IF){
			PTIf* ifstmt = (PTIf*)block->instructions[i];
			auto ans = returnGuard(getBlock(ifstmt->if_stmt),type,functionName);
			found = ans == true ? ans : found;
			ans = returnGuard(getBlock(ifstmt->else_stmt),type,functionName);
			found = ans == true ? ans : found;
		}else if(block->instructions[i]->m_type == PType::FOR){
			PTFor* for_stmt = (PTFor*)block->instructions[i];
			auto ans = returnGuard(getBlock(for_stmt->block),type,functionName);
			found = ans == true ? ans : found;
		}else if(block->instructions[i]->m_type == PType::WHILE){
			PTWhile* while_stmt = (PTWhile*)block->instructions[i];
			auto ans = returnGuard(getBlock(while_stmt->block),type,functionName);
			found = ans == true ? ans : found;
		}
	}
	if(!found && type != "void"){
		assert(false,"no return statement to non-void function '"+functionName+"'");
	}
	return found;
}