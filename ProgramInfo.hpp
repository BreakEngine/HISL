#pragma once
#include <string>
#include <vector>

namespace HISL{
	
	
	enum class Stage{VERTEX,PIXEL};
	
	
	struct LIB_CLASS InputElementInfo{
		std::string m_type;
		std::string m_name;
		std::string m_semantic;	
	};
	
	struct LIB_CLASS UniformElementInfo{
		std::string m_type;
		std::string m_name;
		unsigned int m_offset;
		unsigned int m_size;	
	};
	
	struct LIB_CLASS SamplerInfo{
		std::string m_name;
		unsigned int m_slot;
	};
	
	struct LIB_CLASS TextureInfo{
		std::string m_name;
		unsigned int m_slot;
		SamplerInfo m_sampler;	
	};
	
	struct LIB_CLASS UniformInfo{
		std::string m_name;
		unsigned int m_slot,m_size;
		std::vector<UniformElementInfo> m_elements;
	};
	
	struct LIB_CLASS InputLayoutInfo{
		std::vector<InputElementInfo> m_elements;
		std::string m_name;
	};
	
	struct LIB_CLASS ShaderInfo{
		std::string m_name;
		InputLayoutInfo* m_inputLayout;
		Stage m_type;
		std::vector<UniformInfo> m_uniforms;
		std::vector<TextureInfo> m_textures;
		std::vector<SamplerInfo> m_samplers;	
	};
	struct LIB_CLASS RoutineInfo{
		ShaderInfo m_vertex;
		ShaderInfo m_pixel;
		std::string m_name;
	};
	struct LIB_CLASS ProgramInfo{
		RoutineInfo m_routine;
		std::string m_name;	
	};
}