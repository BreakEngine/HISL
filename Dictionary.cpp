#include "Dictionary.hpp"
using namespace HISL;


const std::string Dictionary::g_vs = "g_vs";
const std::string Dictionary::g_ps = "g_ps";

std::map<std::string, std::string> Dictionary::glsl_table = std::map<std::string, std::string>();
std::map<std::string, std::string> Dictionary::hlsl_table = std::map<std::string, std::string>();