#include "HISLCompiler.hpp"
#include "Driver.hpp"
using namespace std;
using namespace HISL;

const string HISLC::GLSL = "glsl";
const string HISLC::HLSL = "hlsl";

stringstream HISLC::m_error;
stringstream HISLC::m_warning;
unsigned int HISLC::m_error_count = 0;
unsigned int HISLC::m_warning_count = 0;

void HISLC::error(std::string err)
{
	m_error_count++;
	m_error<<"ERROR #"<<m_error_count<<": "<<err<<std::endl;
}

void HISLC::warning(std::string warn)
{
	m_warning_count++;
	m_warning<<"WARNING #"<<m_warning_count<<": "<<warn<<std::endl;
}

HISLC::HISLC()
{
	m_config = new compilerConfig();
	m_config->outputToFile = false;
	m_config->fromFile = false;
	m_config->debugMode = false;
}

void HISLC::config(C_PARAMETER option, std::string val)
{
	switch (option)
	{
	case C_PARAMETER::VERSION:
		warning("cannot set parameter VERSION with value '"+val+"'");
	break;
	case C_PARAMETER::DEBUG:
		if(val.size()==0)
			m_config->debugMode = true;
		else
			warning("cannot set parameter DEBUG with value '"+val+"'");
		break;
	case C_PARAMETER::CODE:
		m_config->code = val;
		break;
	case C_PARAMETER::INPUT_FILE:
		warning("unimplemented functionality");
		break;
	case C_PARAMETER::LANGUAGE:
		if(val != "glsl" && val != "hlsl")
			error("cannot set parameter LANGUAGE with value '"+val+"' please use HISLC::GLSL or HISLC::HLSL.");
		else
			m_config->language = val;
		break;
	case C_PARAMETER::VERTEX_SHADER:
		warning("cannot set parameter VERTEX_SHADER with value '"+val+"'");
		break;
	case C_PARAMETER::PIXEL_SHADER:
		warning("cannot set parameter PIXEL_SHADER with value '"+val+"'");
		break;
	case C_PARAMETER::ERROR_LOG:
		warning("cannot set parameter ERROR_LOG with value '"+val+"'");
		break;
	case C_PARAMETER::WARNING_LOG:
		warning("cannot set parameter WARNING_LOG with value '"+val+"'");
		break;
	default:
		warning("unidentified compiler parameter");
		break;
	}
}

void HISLC::config(C_PARAMETER option, C_PARAMETER param)
{
	switch (option)
	{
	case C_PARAMETER::VERSION:
		warning("cannot set parameter VERSION");
	break;
	case C_PARAMETER::DEBUG:
		warning("cannot set parameter DEBUG");
		break;
	case C_PARAMETER::CODE:
		warning("cannot set parameter CODE");
		break;
	case C_PARAMETER::INPUT_FILE:
		warning("unimplemented functionality");
		break;
	case C_PARAMETER::LANGUAGE:
		if(param == C_PARAMETER::GLSL330)
			m_config->language = "glsl";
		else if(param == C_PARAMETER::HLSL40)
			m_config->language = "hlsl";
		else
			error("unidentified language parameter");
		break;
	case C_PARAMETER::VERTEX_SHADER:
		warning("cannot set parameter VERTEX_SHADER");
		break;
	case C_PARAMETER::PIXEL_SHADER:
		warning("cannot set parameter PIXEL_SHADER");
		break;
	case C_PARAMETER::ERROR_LOG:
		warning("cannot set parameter ERROR_LOG");
		break;
	case C_PARAMETER::WARNING_LOG:
		warning("cannot set parameter WARNING_LOG");
		break;
	default:
		warning("unidentified compiler parameter");
		break;
	}
}

std::string HISLC::fetch(C_PARAMETER option)
{
	switch (option)
	{
	case C_PARAMETER::VERSION:
		return Driver::get_version();
	break;
	case C_PARAMETER::DEBUG:
		warning("cannot set parameter DEBUG with value using fetch function");
		break;
	case C_PARAMETER::CODE:
		warning("cannot set parameter CODE with value using fetch function");
		break;
	case C_PARAMETER::INPUT_FILE:
		warning("cannot set parameter INPUT_FILE with value using fetch function");
		break;
	case C_PARAMETER::LANGUAGE:
		return m_config->language;
		break;
	case C_PARAMETER::VERTEX_SHADER:
		if(m_config->language == "glsl"){
			return "#version 330\n"+Driver::m_compiled_vs;
		}else
		{
			return Driver::m_compiled_vs;
		}
		break;
	case C_PARAMETER::PIXEL_SHADER:
		if(m_config->language == "glsl"){
			return "#version 330\n"+Driver::m_compiled_ps;
		}else
		{
			return Driver::m_compiled_ps;
		}
		break;
	case C_PARAMETER::ERROR_LOG:
		return m_error.str();
		break;
	case C_PARAMETER::WARNING_LOG:
		return m_warning.str();
		break;
	default:
		warning("unidentified compiler parameter");
		break;
	}
}

ProgramInfo HISLC::getProgramInfo()
{
	return Driver::m_program_info;
}

C_STATE HISLC::compile()
{
	Driver::m_program_info = ProgramInfo();
	C_STATE res = C_STATE::OK;

	HISL::driver = new HISL::Driver();
	HISL::driver->parse(m_config);

	HISL::driver->correctTree();

	if(m_error_count>0) return C_STATE::FAILED;

	HISL::driver->semanticAnalysis();
	if(m_error_count>0) return C_STATE::FAILED;
	HISL::driver->typeGuard();
	if(m_error_count>0) return C_STATE::FAILED;
    HISL::driver->handleMultiplication();
	if(m_error_count>0) return C_STATE::FAILED;

	HISL::driver->generateCode(m_config);
	if(m_error_count>0) return C_STATE::FAILED;

	if(m_config->debugMode)
	{
		std::cout<<"/****************************** Parse Tree ******************************/"<<std::endl;
        HISL::driver->printTree();
	}
	if(m_config->debugMode)
		Driver::print_program_info();

	res = m_warning_count > 0  ? C_STATE::OK_WARNING : C_STATE::OK;
	res = m_error_count > 0  ? C_STATE::FAILED : C_STATE::OK;
	return res;
}