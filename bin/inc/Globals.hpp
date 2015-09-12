#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "location.hh"

#define BUILD_LIB

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)|| defined(_WIN64) || defined(WIN64)
	#ifdef BUILD_LIB
		#define LIB_CLASS __declspec(dllexport)
	#else
		#define LIB_CLASS 
	#endif
#else
	#define LIB_CLASS
#endif

namespace HISL{

	struct compilerConfig{
		bool fromFile;
		std::string fileName;
		std::string code;
		std::string language;
		bool outputToFile;
		std::string outputFile;
		bool debugMode;
	};

	class PTNode;
	class Driver;

	extern Driver* driver;
	
	void assert(bool val,std::string msg,location* loc);

	void assert(bool val,std::string msg);

	void removeNode(std::vector<PTNode*>* list, PTNode* node);

	std::string read(std::string path);

	void write(std::string path,std::string data);

	static const unsigned int version_major=1, version_minor=1;
}