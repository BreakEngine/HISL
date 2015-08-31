#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "location.hh"

namespace HISL{

	struct compilerConfig{
		bool fromFile;
		std::string fileName;
		std::string language;
		bool outputToFile;
		std::string outputFile;
	};

	class PTNode;
	void assert(bool val,std::string msg,location* loc);

	void assert(bool val,std::string msg);

	void removeNode(std::vector<PTNode*>* list, PTNode* node);

	std::string read(std::string path);

	void write(std::string path,std::string data);

	static const unsigned int version_major=0, version_minor=1;
}