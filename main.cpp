#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Driver.hpp"
#include "Globals.hpp"


HISL::Driver* driver;

HISL::compilerConfig* parseArgs(int argc, std::vector<std::string> argv){
	HISL::compilerConfig* config = new HISL::compilerConfig();
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
		}
		i++;
	}
	return config;
}

int main(int argc, char** argv)
{

		auto config = parseArgs(argc,std::vector<std::string>(argv,argv+argc));
        driver = new HISL::Driver();
        driver->parse(config);
        driver->correctTree();
        driver->printTree();
        driver->semanticAnalysis();
        driver->handleMultiplication();
        std::string code = driver->generateCode(config);

        std::cout<<"code: "<<std::endl<<code<<std::endl;
        return 0;
}