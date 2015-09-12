#include "Globals.hpp"
#ifndef BUILD_LIB
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "Driver.hpp"
#include "HISLCompiler.hpp"



void print_program_info();

HISL::compilerConfig* parseArgs(int argc, std::vector<std::string> argv){
	HISL::compilerConfig* config = new HISL::compilerConfig();
	config->debugMode = false;
	int i=1;
	while(i<argc){
		if(argv[i] == "-o"){
			config->outputToFile = true;
			HISL::assert(i+1<argc,"you didn't provide output file name after -o\nHint: -o filename");
			config->outputFile = argv[++i];
		}else if(argv[i] == "-in"){
			config->fromFile = true;
			HISL::assert(i+1<argc,"you didn't provide input file name after -in\nHint: -in filename");
			config->fileName = argv[++i];
		}else if(argv[i] == "-lang"){
			HISL::assert(i+1<argc,"you didn't provide language to compile to -lang\nHint: -lang glsl || -lang hlsl");
			config->language = argv[++i];
			HISL::assert(config->language == "glsl" || config->language == "hlsl","you choosed undefined language '"+config->language+"' to compile to\nHint: -lang glsl || -lang hlsl");
		}else if(argv[i] == "-d"){
			config->debugMode = true;
		}else if(argv[i] == "-v"){
			cout<<HISL::Driver::get_version()<<endl;
			exit(0);
		}
		i++;
	}
	return config;
}

int main(int argc, char** argv)
{

	auto config = parseArgs(argc,std::vector<std::string>(argv,argv+argc));
	HISL::driver = new HISL::Driver();
	HISL::driver->parse(config);
	HISL::driver->correctTree();
		if(config->debugMode){
			//std::cout<<"/****************************** Parse Tree ******************************/"<<std::endl;
			//HISL::driver->printTree();
		}
	HISL::driver->semanticAnalysis();
	HISL::driver->typeGuard();
	HISL::driver->handleMultiplication();
        std::string code = HISL::driver->generateCode(config);
		
		if(config->debugMode)
			print_program_info();
		
	if(config->language == "glsl"){
		cout<<"#version 330\n";
		cout<<HISL::Driver::m_compiled_vs<<endl;
		cout<<"#version 330\n";
		cout<<HISL::Driver::m_compiled_ps<<endl;
	}else
	{
		cout<<HISL::Driver::m_compiled_vs<<endl;
		cout<<HISL::Driver::m_compiled_ps<<endl;
	}
	//system("pause");
		
    return 0;
}

//int main()
//{
//	HISL::HISLC compiler;
//	cout<<compiler.fetch(HISL::C_PARAMETER::VERSION)<<endl;
//
//	compiler.config(HISL::C_PARAMETER::LANGUAGE,HISL::HISLC::GLSL);
//	compiler.config(HISL::C_PARAMETER::CODE,HISL::read("test/example01.hisl"));
//	
//	HISL::C_STATE res = compiler.compile();
//	if(res != HISL::C_STATE::OK)
//	{
//		cout<<compiler.fetch(HISL::C_PARAMETER::WARNING_LOG)<<endl;
//		cout<<compiler.fetch(HISL::C_PARAMETER::ERROR_LOG)<<endl;
//	}
//	cout<<compiler.fetch(HISL::C_PARAMETER::VERTEX_SHADER)<<endl;
//	cout<<compiler.fetch(HISL::C_PARAMETER::PIXEL_SHADER)<<endl;
//	HISL::ProgramInfo pinfo = compiler.getProgramInfo();
//
//	
//	compiler.config(HISL::C_PARAMETER::LANGUAGE,HISL::HISLC::HLSL);
//	compiler.config(HISL::C_PARAMETER::CODE,HISL::read("test/example02.hisl"));
//
//	res = compiler.compile();
//	if(res != HISL::C_STATE::OK)
//	{
//		cout<<compiler.fetch(HISL::C_PARAMETER::WARNING_LOG)<<endl;
//		cout<<compiler.fetch(HISL::C_PARAMETER::ERROR_LOG)<<endl;
//	}
//	cout<<compiler.fetch(HISL::C_PARAMETER::VERTEX_SHADER)<<endl;
//	cout<<compiler.fetch(HISL::C_PARAMETER::PIXEL_SHADER)<<endl;
//	
//
//	system("pause");
//	return 0;
//}

void print_program_info(){
	std::cout<<"/****************************** Program Info ******************************/"<<std::endl;
	cout<<"Program name: "<<HISL::Driver::m_program_info.m_name<<endl;
	cout<<"Routine name: "<<HISL::Driver::m_program_info.m_routine.m_name<<endl;
	cout<<"Vertex Shader name: "<<HISL::Driver::m_program_info.m_routine.m_vertex.m_name<<endl;
	if(HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout)
	{
		cout<<"Input Layout name: "<<HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout->m_name<<endl;
		for(auto element :HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout->m_elements){
			cout<<element.m_type<<" "<<element.m_name<<" "<<element.m_semantic<<endl;
		}
	}
	
	for(auto uniform:HISL::Driver::m_program_info.m_routine.m_vertex.m_uniforms){
		cout<<"Uniform name: "<<uniform.m_name<<endl;
		cout<<"Uniform slot: "<<uniform.m_slot<<endl;
		cout<<"Uniform size: "<<uniform.m_size<<endl;
		for(auto element:uniform.m_elements){
			cout<<"Uniform Element name: "<<element.m_name<<endl;
			cout<<"Uniform Element type: "<<element.m_type<<endl;
			cout<<"Uniform Element offset: "<<element.m_offset<<endl;
			cout<<"Uniform Element size: "<<element.m_size<<endl;
		}
	}
	
	for(auto texture : HISL::Driver::m_program_info.m_routine.m_vertex.m_textures){
		cout<<"Texture name: "<<texture.m_name<<endl;
		cout<<"Texture slot: "<<texture.m_slot<<endl;
	}
	
	for(auto sampler:HISL::Driver::m_program_info.m_routine.m_vertex.m_samplers){
		cout<<"Sampler name: "<<sampler.m_name<<endl;
		cout<<"Sampler slot: "<<sampler.m_slot<<endl;
	}
	cout<<"Pixel Shader name: "<<HISL::Driver::m_program_info.m_routine.m_pixel.m_name<<endl;
	
	for(auto uniform:HISL::Driver::m_program_info.m_routine.m_pixel.m_uniforms){
		cout<<"Uniform name: "<<uniform.m_name<<endl;
		cout<<"Uniform slot: "<<uniform.m_slot<<endl;
		cout<<"Uniform size: "<<uniform.m_size<<endl;
		for(auto element:uniform.m_elements){
			cout<<"Uniform Element name: "<<element.m_name<<endl;
			cout<<"Uniform Element type: "<<element.m_type<<endl;
			cout<<"Uniform Element offset: "<<element.m_offset<<endl;
			cout<<"Uniform Element size: "<<element.m_size<<endl;
		}
	}
	
	for(auto texture:HISL::Driver::m_program_info.m_routine.m_pixel.m_textures){
		cout<<"Texture name: "<<texture.m_name<<endl;
		cout<<"Texture slot: "<<texture.m_slot<<endl;
	}
	
	for(auto sampler:HISL::Driver::m_program_info.m_routine.m_pixel.m_samplers){
		cout<<"Sampler name: "<<sampler.m_name<<endl;
		cout<<"Sampler slot: "<<sampler.m_slot<<endl;
	}
}
#endif