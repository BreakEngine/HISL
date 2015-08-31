#include "PTree.hpp"
#include "GLSLCompiler.hpp"
#include "HLSLCompiler.hpp"
using namespace HISL;

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
		
		std::cout<<ps_predef.str()<<ps_code.str()<<std::endl;
		return;
}