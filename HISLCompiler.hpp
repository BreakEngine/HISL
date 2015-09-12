#pragma once
#include "Globals.hpp"
#include <string>
#include <sstream>

namespace HISL
{
	struct ProgramInfo;

	enum class C_PARAMETER
	{
		VERSION = 0, DEBUG = 1, CODE = 2, INPUT_FILE = 3,
		LANGUAGE = 4, VERTEX_SHADER = 5, PIXEL_SHADER = 6,
		ERROR_LOG = 7, WARNING_LOG = 8, GLSL330 = 9, HLSL40 = 10
	};

	enum class C_STATE : int { OK = 0, OK_WARNING = 1, FAILED = -1};

	class LIB_CLASS HISLC
	{
	private:
		compilerConfig* m_config;
		std::string m_code;

	public:
		static std::stringstream m_error;
		static std::stringstream m_warning;
		static unsigned int m_error_count;
		static unsigned int m_warning_count;

		static void error(std::string err);
		static void warning(std::string warn);
		//glsl lang parameter
		static const std::string GLSL;
		//hlsl lang parameter
		static const std::string HLSL;
		//default constructor
		HISLC();

		//configs HISL compiler
		void config(C_PARAMETER option, std::string val="");
		void config(C_PARAMETER option, C_PARAMETER param);

		//gets compiler output
		std::string fetch(C_PARAMETER option);

		ProgramInfo getProgramInfo();

		C_STATE compile();
	};
}