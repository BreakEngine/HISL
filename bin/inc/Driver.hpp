#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <vector>
#include "location.hh"
#include "Globals.hpp"
#include "Env.hpp"
#include "ProgramInfo.hpp"

namespace HISL{

	enum class PType : int{
		NONE = -1, INT = 1, FLOAT = 2, TYPE = 3, ID = 4, DECLARATION = 5,
		VARIABLE_DECLARATION = 6, STRUCT = 7, SEMANTIC_VARIABLE = 8, IOBUFFER = 9,
		BLOCK = 10, VERTEX = 11, ARGUMENT = 12, FUNCTION_DECLARATION = 13,
		FUNCTION_DEFINITION = 14, PROGRAM = 15, BINARY_EXP = 16, UNARY_EXP = 17,
		EXPR_STMT = 18, ARRAY_CALL = 19, VAR_CALL = 20, ACCESS_CHAIN = 21,
		ASSIGNMENT = 22, FUNCTION_CALL = 23, UNIFORM = 24, ARRAY_DECLARATION = 25,
		CONFIG_STATEMENT = 26, ROUTINE = 27, PIXEL = 28, TYPE_CONSTRUCTOR = 29,
		PRE_QUALIFIER = 30, POST_QUALIFIER = 31, DECLARATOR = 32, INIT_DECLARATOR = 33,
		VARIABLE_LIST = 34, RETURN = 35, IF = 36, FOR = 37, WHILE = 38, GLSL = 39, HLSL = 40
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
	class PTPreQualifier;
	class PTPostQualifier;
	class PTDeclarator;
	class PTInitDeclarator;
	class PTRVariableCall;
	class PTRFunctionCall;
	class PTRArrayCall;
	class PTRAccessChain;
	class PTReturn;
	class PTIf;
	class PTFor;
	class PTWhile;
	class PTNative;

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

		virtual void typeGuard(){
			
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

		static std::string m_compiled_vs,m_compiled_ps;
		static ProgramInfo m_program_info;

		static std::string get_version()
		{
			std::stringstream ret;
			ret<<"HISL ";
			ret<<HISL::version_major<<"."<<HISL::version_minor<< std::endl;
			ret<<"Written by Mostafa Saad Abdel-Hameed."<< std::endl;
			ret<<"Licensed under GNU GENERAL PUBLIC LICENSE - see LICENSE file"<< std::endl;
			return ret.str();
		}

		static void print_program_info()
		{
			std::cout<<"/****************************** Program Info ******************************/"<<std::endl;
			std::cout<<"Program name: "<<HISL::Driver::m_program_info.m_name<< std::endl;
			std::cout<<"Routine name: "<<HISL::Driver::m_program_info.m_routine.m_name<< std::endl;
			std::cout<<"Vertex Shader name: "<<HISL::Driver::m_program_info.m_routine.m_vertex.m_name<< std::endl;
			if(HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout)
			{
				std::cout<<"Input Layout name: "<<HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout->m_name<< std::endl;
				for(auto element :HISL::Driver::m_program_info.m_routine.m_vertex.m_inputLayout->m_elements){
					std::cout<<element.m_type<<" "<<element.m_name<<" "<<element.m_semantic<< std::endl;
				}
			}
	
			for(auto uniform:HISL::Driver::m_program_info.m_routine.m_vertex.m_uniforms){
				std::cout<<"Uniform name: "<<uniform.m_name<<std::endl;
				std::cout<<"Uniform slot: "<<uniform.m_slot<<std::endl;
				std::cout<<"Uniform size: "<<uniform.m_size<<std::endl;
				for(auto element:uniform.m_elements){
					std::cout<<"Uniform Element name: "<<element.m_name<<std::endl;
					std::cout<<"Uniform Element type: "<<element.m_type<<std::endl;
					std::cout<<"Uniform Element offset: "<<element.m_offset<<std::endl;
					std::cout<<"Uniform Element size: "<<element.m_size<<std::endl;
				}
			}
	
			for(auto texture : HISL::Driver::m_program_info.m_routine.m_vertex.m_textures){
				std::cout<<"Texture name: "<<texture.m_name<<std::endl;
				std::cout<<"Texture slot: "<<texture.m_slot<<std::endl;
			}
	
			for(auto sampler:HISL::Driver::m_program_info.m_routine.m_vertex.m_samplers){
				std::cout<<"Sampler name: "<<sampler.m_name<<std::endl;
				std::cout<<"Sampler slot: "<<sampler.m_slot<<std::endl;
			}
			std::cout<<"Pixel Shader name: "<<HISL::Driver::m_program_info.m_routine.m_pixel.m_name<<std::endl;
	
			for(auto uniform:HISL::Driver::m_program_info.m_routine.m_pixel.m_uniforms){
				std::cout<<"Uniform name: "<<uniform.m_name<<std::endl;
				std::cout<<"Uniform slot: "<<uniform.m_slot<<std::endl;
				std::cout<<"Uniform size: "<<uniform.m_size<<std::endl;
				for(auto element:uniform.m_elements){
					std::cout<<"Uniform Element name: "<<element.m_name<<std::endl;
					std::cout<<"Uniform Element type: "<<element.m_type<<std::endl;
					std::cout<<"Uniform Element offset: "<<element.m_offset<<std::endl;
					std::cout<<"Uniform Element size: "<<element.m_size<<std::endl;
				}
			}
	
			for(auto texture:HISL::Driver::m_program_info.m_routine.m_pixel.m_textures){
				std::cout<<"Texture name: "<<texture.m_name<<std::endl;
				std::cout<<"Texture slot: "<<texture.m_slot<<std::endl;
			}
	
			for(auto sampler:HISL::Driver::m_program_info.m_routine.m_pixel.m_samplers){
				std::cout<<"Sampler name: "<<sampler.m_name<<std::endl;
				std::cout<<"Sampler slot: "<<sampler.m_slot<<std::endl;
			}
		}
		
		Driver();
		~Driver();

		int parse(compilerConfig* config);
		int parseFile(std::string& path);

		void reset();

		void printTree();

		void correctTree();

		void semanticAnalysis();
		
		void typeGuard();

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
		PTPreQualifier* createPreQualifier(std::string val);
		PTPostQualifier* createPostQualifier(bool isArray,int ix);
		PTDeclarator* createDeclarator(PTPreQualifier* pre, PTId id, PTPostQualifier* post);
		PTInitDeclarator* createInitDeclarator(PTDeclarator* decl,std::vector<PTExpression*>* initlist);
		PTVariableList* createVariableList(std::vector<PTInitDeclarator*>* list);
		PTRVariableCall* createRVarCall(std::string id, std::string op);
		PTRArrayCall* createRArrayCall(std::string id,PTExpression* index,std::string op);
		PTRFunctionCall* createRFunctionCall(std::string id,std::vector<PTExpression*>* args, std::string op);
		PTRAccessChain* createRAccessChain(PTLValue* lval);
		PTReturn* createReturn(PTExpression* obj);
		PTIf* createIf(PTExpression* condition,PTStatement* if_stmt,PTStatement* else_stmt);
		PTFor* createFor(PTStatement* stmt_1,PTStatement* stmt_2, PTExpression* stmt_3, PTStatement* block);
		PTWhile* createWhile(PTExpression* condition, PTStatement* block);
		PTNative* createGLSL(std::string val);
		PTNative* createHLSL(std::string val);

		int m_test;
		location* m_location;
		PTNode* m_PTroot,*m_std;
		Dictionary* m_dictionary;
	};
}