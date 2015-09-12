#pragma once
#include <map>
#include <string>
#include <vector>
namespace HISL{
	
	struct IType{
		bool isMatrix;
		virtual std::string getReturnType()=0;
		virtual std::string getName()=0;
		virtual bool isFunction()=0;
		virtual IType* getMember(std::string)=0;
		virtual unsigned int getSize()=0;
	};
	
	struct TypeInfo:IType{
		std::string return_type;
		std::vector<IType*> member_objects;
		std::string name;
		unsigned int size;
		
		TypeInfo(std::string ret_type,std::string obj_name):return_type(ret_type), name(obj_name){isMatrix = false;}
		
		TypeInfo(){isMatrix = false;}
		virtual std::string getReturnType(){return return_type;}
		
		virtual std::string getName()override{
			return name;
		}
		virtual bool isFunction()override{
			return false;
		}
		
		virtual IType* getMember(std::string name)override{
			for(auto member : member_objects){
				if(member->getName() == name)
					return member;
			}
			return NULL;
		}
		virtual unsigned int getSize(){
			return size;
		}
	};
	
	struct FunctionInfo : TypeInfo{
		std::vector<IType*> args;
		
		virtual bool isFunction()override{
			return true;
		}	
	};
	
	class Dictionary{
	public:
		std::map<std::string, void*> m_types;
		static std::map<std::string, std::string> glsl_table,hlsl_table;
		
		static std::map<std::string,IType*> std_lang;

		static const std::string g_vs, g_ps;

		static void populateGLSLTable(){
			glsl_table["int"] = "int";
			glsl_table["float"] = "float";
			glsl_table["vec2"] = "vec2";
			glsl_table["vec3"] = "vec3";
			glsl_table["vec4"] = "vec4";
			glsl_table["mat2"] = "mat2";
			glsl_table["mat3"] = "mat3";
			glsl_table["mat4"] = "mat4";
			glsl_table["texture2D"] = "sampler2D";
			glsl_table["g_position"] = "gl_Position";
			glsl_table["g_color"] = "gl_FragColor";
		}
		
		static void populateHLSLTable(){
			hlsl_table["int"] = "int";
			hlsl_table["float"] = "float";
			hlsl_table["vec2"] = "float2";
			hlsl_table["vec3"] = "float3";
			hlsl_table["vec4"] = "float4";
			hlsl_table["mat2"] = "float2x2";
			hlsl_table["mat3"] = "float3x3";
			hlsl_table["mat4"] = "float4x4";
			hlsl_table["texture2D"] = "Texture2D";
		}
		
		static bool isMatrix(std::string type){
			std::size_t pos = type.find("mat");
			return pos != std::string::npos;
		}

		static std::string getGLSLEq(std::string type){
			if(glsl_table.size()==0)			
				populateGLSLTable();

			return glsl_table[type];
		}
		
		static std::string getHLSLEq(std::string type){
			if(hlsl_table.size()==0)			
				populateHLSLTable();

			return hlsl_table[type];
		}
		
		static void registerHLSL(std::string key,std::string val){
			hlsl_table[key] = val;
		}
		
		static void populate_std(){
			TypeInfo* t_obj = new TypeInfo();
			t_obj->name = "int";
			t_obj->return_type = "int";
			t_obj->size = 4;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "float";
			t_obj->return_type = "float";
			t_obj->size = 4;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "vec2";
			t_obj->return_type = "vec2";
			t_obj->size = 8;
			t_obj->member_objects.push_back(new TypeInfo("float","x"));
			t_obj->member_objects.push_back(new TypeInfo("float","y"));
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "vec3";
			t_obj->return_type = "vec3";
			t_obj->size = 12;
			t_obj->member_objects.push_back(new TypeInfo("float","x"));
			t_obj->member_objects.push_back(new TypeInfo("float","y"));
			t_obj->member_objects.push_back(new TypeInfo("float","z"));
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "vec4";
			t_obj->return_type = "vec4";
			t_obj->size = 16;
			t_obj->member_objects.push_back(new TypeInfo("float","x"));
			t_obj->member_objects.push_back(new TypeInfo("float","y"));
			t_obj->member_objects.push_back(new TypeInfo("float","z"));
			t_obj->member_objects.push_back(new TypeInfo("float","w"));
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "mat2";
			t_obj->return_type = "mat2";
			t_obj->size = 16;
			t_obj->isMatrix = true;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "mat3";
			t_obj->return_type = "mat3";
			t_obj->size = 36;
			t_obj->isMatrix = true;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "mat4";
			t_obj->return_type = "mat4";
			t_obj->size = 64;
			t_obj->isMatrix = true;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "g_position";
			t_obj->return_type = "vec4";
			t_obj->isMatrix = false;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "g_color";
			t_obj->return_type = "vec4";
			t_obj->isMatrix = false;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "g_vs";
			t_obj->return_type = "vertex";
			t_obj->isMatrix = false;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "g_ps";
			t_obj->return_type = "pixel";
			t_obj->isMatrix = false;
			std_lang[t_obj->getName()] = t_obj;
			
			t_obj = new TypeInfo();
			t_obj->name = "texture2D";
			t_obj->return_type = "texture2D";
			t_obj->isMatrix = false;
			//functions
			FunctionInfo* f_sample = new FunctionInfo();
			f_sample->isMatrix = false;
			f_sample->name = "sample";
			f_sample->return_type = "vec4";
			f_sample->args.push_back(std_lang["vec2"]);
			
			t_obj->member_objects.push_back(f_sample);
			std_lang[t_obj->getName()] = t_obj;
		}
		
		static IType* std_isMember(std::string type, std::string member){
			if(std_lang.size()==0)
				populate_std();
				
			auto obj = std_lang.find(type);
			if(obj!=std_lang.end()){
				return obj->second->getMember(member); 
			}else{
				return NULL;
			}
		}
		
		static IType* std_getType(std::string type){
			if(std_lang.size()==0)
				populate_std();
			
			auto f = std_lang.find(type);
			if(f!=std_lang.end())
				return f->second;
			else
				return NULL;
		}		
		
		static std::string std_calcOperationResultType(std::string lhs,std::string rhs,std::string op){
			return "";
		}
		
		static bool std_isBuiltIn(std::string type){
			if(std_lang.size()==0)
				populate_std();
			
			auto f = std_lang.find(type);
			if(f!=std_lang.end())
				return true;
			else
				return false;
		}

		Dictionary(){
			m_types["int"] = NULL;
			m_types["float"] = NULL;
			m_types["vec2"] = NULL;
			m_types["vec3"] = NULL;
			m_types["vec4"] = NULL;
			m_types["mat2"] = NULL;
			m_types["mat3"] = NULL;
			m_types["mat4"] = NULL;
			m_types["program"] = NULL;
			m_types["struct"] = NULL;
			m_types["iobuffer"] = NULL;
			m_types["uniform"] = NULL;
			m_types["vertex"] = NULL;
			m_types["pixel"] = NULL;
			m_types["routine"] = NULL;
			m_types["texture2D"] = NULL;
		}

		bool typeExists(std::string key){
			return m_types.find(key) != m_types.end();
		}

		bool isMemberOfType(std::string key, std::string member){
			if(key == "vec2"){
				if(member == "x" || member == "y")
						return true;
					else
						return false;
			}else if(key == "vec3"){
				if(member == "x" || member == "y" || member == "z")
						return true;
					else
						return false;
			}else if(key == "vec4"){
				if(member == "x" || member == "y" || member == "z" || member == "w")
						return true;
					else
						return false;
			}
			return false;
		}

		bool isVec(std::string key){
			if(key == "vec2" || key == "vec3" || key == "vec4")
				return true;
			return false;
		}
	};
}