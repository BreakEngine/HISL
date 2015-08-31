#pragma once
#include <map>
#include <string>
namespace HISL{
	class Dictionary{
	public:
		std::map<std::string, void*> m_types;
		static std::map<std::string, std::string> glsl_table,hlsl_table;

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
			hlsl_table["texture2D"] = "texture2D";
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