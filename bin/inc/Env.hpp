#pragma once
#include <map>
#include <string>

namespace HISL{
	class PTNode;
	class Env{
		std::map<std::string,PTNode*> table;
		std::map<std::string,PTNode*> functions;
		std::map<std::string,PTNode*> routines;
	public:
		Env* prev;

		Env(){
			prev=NULL;
		}

		void put(std::string s, PTNode* n){
			table[s]=n;
		}

		void putFunction(std::string s, PTNode* func){
			functions[s] = func;
		}

		void putRoutine(std::string s, PTNode* routine){
			routines[s] = routine;
		}

		PTNode* findRoutine(std::string s){
			for(Env* e = this;e!=NULL;e = e->prev){
				auto found = e->routines.find(s);
				if(found != e->routines.end())
					return found->second;
			}
			return NULL;
		}

		PTNode* findFunction(std::string s){
			for(Env* e = this;e!=NULL;e = e->prev){
				auto found = e->functions.find(s);
				if(found != e->functions.end())
					return found->second;
			}
			return NULL;
		}

		PTNode* find(std::string s){
			/*
			for(Env* e = this;e!=NULL;e = e->prev){
				auto found = e->table.find(s);
				if(found != e->table.end())
					return found->second;
			}*/
			auto found = table.find(s);
			if(found != table.end()){
				return found->second;
			}else if(prev != NULL){
				return prev->find(s);
			}
			return NULL;
		}
	};
}