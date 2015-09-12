#include "Globals.hpp"
#include "PTree.hpp"
#include "HISLCompiler.hpp"
#include "Driver.hpp"
#include <sstream>
#include <fstream>
using namespace HISL;
using namespace std;

Driver* HISL::driver = new Driver();

void HISL::assert(bool val,std::string msg,location* loc){
		if(!val)
		{
			stringstream ret;
			ret<<msg<<" at location "<<loc->end<<std::endl;
			HISLC::error(ret.str());
			//exit(1);
		}
}

void HISL::assert(bool val,std::string msg){
		if(!val)
		{
			stringstream ret;
			ret<<msg<<std::endl;
			HISLC::error(ret.str());
			//exit(1);
		}
}

void HISL::removeNode(std::vector<PTNode*>* list, PTNode* node){
		if(list && node)
        	list->erase(std::remove_if(list->begin(),list->end(),
          	[node](const PTNode* liNode){
            	return node == liNode;
          	}),
        	list->end());
}

std::string HISL::read(std::string path){
	std::string res;
	ifstream file;
	file.open(path);
	assert(file.good(),"cannot open file named '"+path+"'");
	std::string line;
	while(getline(file,line)){
		res += line;
		res += "\n";
	}
	file.close();
	return res;
}

void HISL::write(std::string path,std::string data){
	ofstream file;
	file.open(path.c_str(),ios::out);
	file<<data;
	file.close();
}

