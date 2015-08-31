#pragma once
#include "Driver.hpp"
#include "Globals.hpp"
#include "Dictionary.hpp"
namespace HISL{
	class PTExpression: public PTNode{
	public:
		virtual void printTree(std::ostream& out){
			out<<"generic expression {};"<<std::endl;
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
	};

	class PTStatement: public PTNode{
	public:
		virtual void printTree(std::ostream& out){
			out<<"generic statement {};"<<std::endl;
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
	};

	class PTConstant: public PTExpression{

	};

	class PTInt: public PTConstant{
	public:
		int val;

		virtual void printTree(std::ostream& out){
			out<<"int { val = "<<val<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
	};

	class PTFloat: public PTConstant{
	public:
		float val;
		virtual void printTree(std::ostream& out){
			out<<"float { val = "<<val<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
	};

	class PTType: public PTExpression{
	public:
		std::string val;

		virtual void printTree(std::ostream& out){
			out<<"type { val = "<<val<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
		virtual PTType* inferType(){
			auto res = new PTType();
			res->val = val;
			res->m_type = PType::TYPE;
			res->m_parent = m_parent;
			return res;
		}
	};

	class PTId: public PTExpression{
	public:
		std::string val;

		virtual void printTree(std::ostream& out){
			out<<"id { val = "<<val<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			
		}
	};

	class PTForwardDeclaration: public PTStatement{
	public:
		PTType type;
		PTId id;

		virtual void printTree(std::ostream& out){
			out<<"forward declaration {"<<std::endl;
			type.printTree(out);
			id.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			m_parent->m_env->put(id.val,this);
		}
		virtual PTType* inferType(){
			return type.inferType();
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTArrayDeclaration: public PTStatement
	{
	public:
		PTType type;
		PTId id;
		unsigned int size;


		PTArrayDeclaration(){

		}

		virtual void printTree(std::ostream& out){
			out<<"Array Declaration {"<<std::endl;
			type.printTree(out);
			id.printTree(out);
			out<<"["<<size<<"]";
			out<<"};\n";
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = m_parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
				auto res = m_env->find(id.val);
				assert(res == NULL,"redefinition of array '"+id.val+"'");
				m_env->prev->put(id.val,this);
		}

		virtual PTType* inferType(){
			return type.inferType();
		}

		virtual std::string getNodeName(){
			return id.val;
		}

	};
	class PTVariableList: public PTExpression{
	public:
		PTType type;
		std::vector<PTId*> ids;
		std::vector<PTExpression*> values;

		virtual void printTree(std::ostream& out){
			out<<"id list {"<<std::endl;
			for(int i=0;i<ids.size();i++){
				ids[i]->printTree(out);
				if(values[i]){
					out<<" = ";
					values[i]->printTree(out);
				}
			}
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        for(int i=0;i<values.size();i++){
	        	if(values[i]){
	        		values[i]->correctTree(list,parent);
	        	}
	        }
	        m_parent = parent;
	        m_env->prev = m_parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			for(int i=0;i<ids.size();i++){
				auto res = m_env->find(ids[i]->val);
				assert(res == NULL,"redefinition of variable '"+ids[i]->val+"'");
				m_env->prev->put(ids[i]->val,this);
			}
		}

		virtual void handleMultiplication(){
			for(int i=0;i<values.size();i++){
				if(values[i])
					values[i]->handleMultiplication();
			}
		}
		virtual PTType* inferType(){
			return type.inferType();
		}
	};

	class PTVariableDeclaration: public PTStatement{
	public:
		PTType type;
		PTVariableList variables;

		virtual void printTree(std::ostream& out){
			out<<"variable {"<<std::endl;
			type.printTree(out);
			variables.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        variables.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			if(!dic->typeExists(type.val)){
				PTNode* found = m_env->find(type.val);
				assert(found != NULL,"undefined type '"+type.val+"' of variable "+variables.ids[0]->val);
			}
			variables.semanticAnalysis(dic);
		}
		virtual void handleMultiplication(){
			variables.handleMultiplication();
		}
		virtual PTType* inferType(){
			return type.inferType();
		}
	};

	class PTSemanticVariable: public PTStatement{
	public:
		PTType type;
		PTId id;
		PTId semantic;

		virtual void printTree(std::ostream& out){
			out<<"semantic variable {"<<std::endl;
			type.printTree(out);
			id.printTree(out);
			semantic.printTree(out);
			out<<"};"<<std::endl;
		}	

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}	
		virtual void semanticAnalysis(Dictionary* dic){
			if(!dic->typeExists(type.val)){
				PTNode* found = m_env->find(type.val);
				assert(found != NULL,"undefined type '"+type.val+"' of variable "+id.val);
			}
			auto res = m_env->find(id.val);
			assert(res == NULL,"redefinition of variable '"+id.val+"'");
			m_env->prev->put(id.val,this);
		}
		virtual PTType* inferType(){
			return type.inferType();
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTIOBuffer: public PTStatement{
	public:
		PTId id;
		std::vector<PTSemanticVariable>& data;
		bool isLayout;

		PTIOBuffer(std::vector<PTSemanticVariable>& _data):data(_data){isLayout = false;}

		virtual void printTree(std::ostream& out){
			out<<"buffer {"<<std::endl;
			id.printTree(out);
			for(auto var : data)
				var.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        for(auto s:data)
	        	s.correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			auto node = m_env->find(id.val);
			assert(node == NULL || node->m_type == PType::DECLARATION, "redefinition of iobuffer '"+id.val+"'");
			m_env->prev->put(id.val,this);
			for(int i=0;i<data.size();i++)
	        	data[i].semanticAnalysis(dic);
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTUniform: public PTStatement{
	public:
		PTId id;
		std::vector<PTStatement*>& data;

		PTUniform(std::vector<PTStatement*>& _data):data(_data){}

		virtual void printTree(std::ostream& out){
			out<<"struct {"<<std::endl;
			id.printTree(out);
			for(auto var : data)
				var->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        for(int i=0;i<data.size();i++)
	        	data[i]->correctTree(list,parent);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}


		virtual void semanticAnalysis(Dictionary* dic){
			auto node = m_env->find(id.val);
			assert(node == NULL || node->m_type == PType::DECLARATION, "redefinition of uniform '"+id.val+"'");
			m_env->prev->put(id.val,this);
			for(int i=0;i<data.size();i++)
	        	data[i]->semanticAnalysis(dic);
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTStruct: public PTStatement{
	public:
		PTId id;
		std::vector<PTStatement*>& data;

		PTStruct(std::vector<PTStatement*>& _data):data(_data){}


		virtual void printTree(std::ostream& out){
			out<<"struct {"<<std::endl;
			id.printTree(out);
			for(auto var : data)
				var->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        for(int i=0;i<data.size();i++)
	        	data[i]->correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			auto node = m_env->find(id.val);
			assert(node == NULL || node->m_type == PType::DECLARATION, "redefinition of struct '"+id.val+"'");
			m_env->prev->put(id.val,this);
			for(int i=0;i<data.size();i++)
	        	data[i]->semanticAnalysis(dic);
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTBlock: public PTStatement{
	public:
		std::vector<PTStatement*> instructions;

		virtual void printTree(std::ostream& out){
			out<<"block {"<<std::endl;
			for(auto stmt : instructions)
				stmt->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        for(auto s:instructions)
	        	s->correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			for(int i=0;i<instructions.size();i++){
				instructions[i]->semanticAnalysis(dic);
			}
		}
		virtual void handleMultiplication(){
			for(int i=0;i<instructions.size();i++){
				instructions[i]->handleMultiplication();
			}
		}
	};

	class PTStage: public PTStatement{
	public:
		PTId id;
		PTBlock block;

		virtual void printTree(std::ostream& out){
			out<<"stage {"<<std::endl;
			id.printTree(out);
			block.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        block.correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			auto obj = m_env->find(id.val);
			assert(obj == NULL,"redefinition of stage '"+id.val+"'");
			m_env->prev->put(id.val,this);
			block.semanticAnalysis(dic);
		}
		virtual void handleMultiplication(){
			block.handleMultiplication();
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTArg: public PTExpression{
	public:
		PTType type;
		PTId* id;

		virtual void printTree(std::ostream& out){
			out<<"argument {"<<std::endl;
			type.printTree(out);
			if(id)
				id->printTree(out);
			out<<"};"<<std::endl;
		}
		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			if(!dic->typeExists(type.val)){
				PTNode* found = m_env->find(type.val);
				assert(found != NULL,"undefined type '"+type.val);
			}
			if(id)
				m_env->prev->put(id->val,this);
		}
		virtual PTType* inferType(){
			return type.inferType();
		}
	};

	class PTFunctionDeclaration: public PTStatement{
	public:
		PTType returnType;
		PTId id;
		std::vector<PTArg>& args;

		PTFunctionDeclaration(std::vector<PTArg>& _args):args(_args){}

		virtual void printTree(std::ostream& out){
			out<<"function declaration {"<<std::endl;
			returnType.printTree(out);
			id.printTree(out);
			for(auto arg : args)
				arg.printTree(out);
			out<<"};"<<std::endl;
		}
		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        for(int i=0;i<args.size();i++)
	        	if(parent->m_type != PType::FUNCTION_DEFINITION)
	        		args[i].correctTree(list,this);
	        	else
	        		args[i].correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			//block.semanticAnalysis(dic);
			auto res = m_env->prev->findFunction(id.val);
			if(res == NULL)
				m_env->prev->putFunction(id.val,this);
			else
				if(res->m_type != PType::FUNCTION_DEFINITION)
					m_env->prev->putFunction(id.val,this);

			for(int i=0;i<args.size();i++)
				args[i].semanticAnalysis(dic);
		}
		virtual PTType* inferType(){
			return returnType.inferType();
		}

		virtual std::string getNodeName(){
			return id.val;
		}
	};

	class PTFunctionDefinition: public PTStatement{
	public:
		PTFunctionDeclaration& signature;
		PTBlock& block;

		PTFunctionDefinition(PTFunctionDeclaration& _sign, PTBlock& _block):signature(_sign),block(_block){}

		virtual void printTree(std::ostream& out){
			out<<"function definition {"<<std::endl;
			signature.printTree(out);
			block.printTree(out);
			out<<"};"<<std::endl;
		}
		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        signature.correctTree(list,this);
	        block.correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			auto res = m_env->findFunction(signature.id.val);
			assert(res == NULL || res->m_type == PType::FUNCTION_DECLARATION,"redefinition of function '"+signature.id.val+"'");
			m_env->prev->putFunction(signature.id.val,this);

			signature.semanticAnalysis(dic);
			block.semanticAnalysis(dic);
		}
		virtual void handleMultiplication(){
			block.handleMultiplication();
		}
		virtual PTType* inferType(){
			return signature.inferType();
		}

		virtual std::string getNodeName(){
			return signature.getNodeName();
		}
	};
	class PTRoutine;
	class PTProgram: public PTStatement{
	public:
		PTId& id;
		PTBlock& block;

		PTProgram(PTId& _id, PTBlock& _block):id(_id),block(_block){}

		virtual void printTree(std::ostream& out){
			out<<"program {"<<std::endl;
			id.printTree(out);
			block.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        m_parent = parent;
	        block.correctTree(list,this);
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			block.semanticAnalysis(dic);
		}

		virtual void handleMultiplication(){
			block.handleMultiplication();
		}
		virtual std::string getNodeName(){
			return id.val;
		}


		void generateCode(std::ostream& predef, std::ostream& code, compilerConfig* config)override;

	};

	class PTExpressionStmt:public PTStatement{
	public:
		PTExpression& expr;

		PTExpressionStmt(PTExpression& _expr):expr(_expr){}

		virtual void printTree(std::ostream& out){
			expr.printTree(out);
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        expr.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			expr.semanticAnalysis(dic);
		}
		virtual void handleMultiplication(){
			expr.handleMultiplication();
		}
		virtual PTType* inferType(){
			return expr.inferType();
		}
	};

	class PTLValue: public PTExpression{
	public:
		PTLValue* next;
		std::string op;

		virtual std::string getName(){
			return "";
		}
	};

	class PTVarCall: public PTLValue{
	public:
		PTId id;

		virtual void printTree(std::ostream& out){
			out<<"Variable Call { {op = "<<op<<"}";
			id.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }
	        parent->m_children.push_back(this);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
				auto res = m_env->find(id.val);
				assert(res!=NULL,"undefined variable '"+id.val+"'");
				auto rtype = res->inferType();
				assert(rtype != NULL, "can't infer type of variable '"+id.val+"' for semantic analysis");

				auto curr = this->next;
				while(curr != NULL){
					auto objDef = m_env->find(rtype->val);
					if(!dic->isMemberOfType(rtype->val,curr->getName())){
						assert(objDef !=NULL,"undefined type '"+rtype->val+"' of variable '"+curr->getName()+"'");
						auto currNode = objDef->m_env->find(curr->getName());
						assert(currNode != NULL,"undefined member variable '"+curr->getName()+"' of object '"+id.val+"'");
						rtype = currNode->inferType();
					}
					curr = curr->next;
				}
		}
		virtual PTType* inferType(){
			Dictionary* new_dic = new Dictionary();
			PTType* res_type = NULL;
			auto res = m_env->find(id.val);
			auto rtype = res->inferType();
			res_type = rtype;
			auto curr = this->next;
			while(curr != NULL){
				auto objDef = m_env->find(rtype->val);
				if(new_dic->isMemberOfType(rtype->val,curr->getName())){
					res_type->m_type = PType::TYPE;
					res_type->val = "float";
					break;
				}
				auto currNode = objDef->m_env->find(curr->getName());
				rtype = currNode->inferType();
				res_type = rtype;
				curr = curr->next;
			}
			return res_type;
		}
		virtual std::string getName(){
			return id.val;
		}
	};

	class PTArrayCall: public PTLValue{
	public:
		PTId id;
		PTExpression& index;

		PTArrayCall(PTId& _id,PTExpression& _ix,std::string _op):id(_id),index(_ix){this->op = _op;}

		virtual void printTree(std::ostream& out){
			out<<"Array Call { {op = "<<this->op<<"}";
			id.printTree(out);
			index.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
			index.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
				//auto res = m_env->find(id.val);
				//assert(res!=NULL,"undefined array '"+id.val+"'");

			auto res = m_env->find(id.val);
			assert(res!=NULL,"undefined variable '"+id.val+"'");
			auto rtype = res->inferType();
			assert(rtype != NULL, "can't infer type of variable '"+id.val+"' for semantic analysis");

			auto curr = this->next;
			while(curr != NULL){
				auto objDef = m_env->find(rtype->val);
				if(!dic->isMemberOfType(rtype->val,curr->getName())){
					assert(objDef !=NULL,"undefined type '"+rtype->val+"' of variable '"+curr->getName()+"'");
					auto currNode = objDef->m_env->find(curr->getName());
					assert(currNode != NULL,"undefined member variable '"+curr->getName()+"' of object '"+id.val+"'");
					rtype = currNode->inferType();
				}
				curr = curr->next;
			}
		}

		virtual std::string getName(){
			return id.val;
		}
		virtual PTType* inferType(){
			auto res = m_env->find(id.val);
			assert(res!=NULL,"undefined array call '"+id.val+"'");
			return res->inferType();
		}
	};

	class PTAccessChain: public PTLValue{
	public:
		PTLValue* id;

		PTAccessChain(PTLValue* _id): id(_id){}

		virtual void printTree(std::ostream& out){
			out<<"Access Chain { ";
			auto curr = id;
			while(curr != NULL){
				curr->printTree(out);
				curr = curr->next;
			}
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        auto curr = id;
	        while(curr != NULL){
	        	curr->correctTree(list,parent);
	        	curr = curr->next;
	        }
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			//TODO
			id->semanticAnalysis(dic);
		}
		virtual PTType* inferType(){
			return id->inferType();
		}
	};

	class PTBinaryExpression: public PTExpression{
	public:
		PTExpression& lhs;
		std::string op;
		PTExpression& rhs;

		PTBinaryExpression(PTExpression& _lhs, std::string _op, PTExpression& _rhs):lhs(_lhs),op(_op),rhs(_rhs){}

		virtual void printTree(std::ostream& out){
			out<<"Binary Expression { ";
			lhs.printTree(out);
			out<<" "<<op<<" ";
			rhs.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        lhs.correctTree(list,parent);
	        rhs.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			lhs.semanticAnalysis(dic);
			rhs.semanticAnalysis(dic);
		}

		virtual void handleMultiplication(){
			if(op == "*"){
				PTType* rtype = rhs.inferType();
				PTType* ltype = lhs.inferType();
				assert(rtype != NULL,"can't infer type of rhs");
				assert(rtype != NULL,"can't infer type of lhs");
				std::cerr<<rtype->val<<std::endl;
				std::cerr<<ltype->val<<std::endl;
			}
		}
	};

	class PTUnaryExpression: public PTExpression{
	public:
		bool after;
		std::string op;
		PTExpression& uhs;

		PTUnaryExpression(std::string _op, PTExpression& _uhs, bool _after = false):op(_op),uhs(_uhs),after(_after){}

		virtual void printTree(std::ostream& out){
			out<<"Unary Expression { ";
			if(after)
			{
				uhs.printTree(out);
				out<<op;
			}else
			{
				out<<op;
				uhs.printTree(out);
			}
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        uhs.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			uhs.semanticAnalysis(dic);
		}
	};

	class PTAssignment: public PTExpression{
	public:
		std::string op;
		PTLValue& lhs;
		PTExpression& rhs;

		PTAssignment(PTLValue& _lhs,std::string _op,PTExpression& _rhs):lhs(_lhs),op(_op),rhs(_rhs){}

		virtual void printTree(std::ostream& out){
			out<<"Assignment Expression { ";
			lhs.printTree(out);
			out<<" "<<op<<" ";
			rhs.printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }
	        parent->m_children.push_back(this);
	        lhs.correctTree(list,parent);
	        rhs.correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			lhs.semanticAnalysis(dic);
			rhs.semanticAnalysis(dic);
		}
		virtual void handleMultiplication(){
			rhs.handleMultiplication();
		}

	};

	class PTFunctionCall: public PTExpression{
	public:
		PTAccessChain chain;
		std::vector<PTExpression*>& args;

		PTFunctionCall(PTAccessChain& _id, std::vector<PTExpression*>& _args):chain(_id),args(_args){}

		virtual void printTree(std::ostream& out){
			out<<"Function Call { ";
			chain.printTree(out);
			for(auto arg:args)
				arg->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
			chain.correctTree(list,parent);
			
			for(int i=0;i<args.size();i++)
				args[i]->correctTree(list,parent);
				
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			auto chain_node = chain.id;
			bool isTexture = false;
			while(chain_node != NULL){
				if(chain_node->next == NULL){
					if(!isTexture){
						auto objNode = m_env->findFunction(chain_node->getName());
						assert(objNode != NULL, "undefined function of name '"+chain_node->getName()+"'");
					}else{
						assert(chain_node->getName() == "sample","undefined member function of type texture '"+chain_node->getName()+"'");
					}
				}else{
					auto objNode = m_env->find(chain_node->getName());
					assert(objNode != NULL,"undefined object named '"+chain_node->getName()+"'");
					auto objType = objNode->inferType();
					assert(objType->val == "texture2D", "only textures has a member function but you access object of type '"+objType->val+"'");
					isTexture = true;
				}
				chain_node = chain_node->next;
			}
		}

		virtual PTType* inferType(){
			auto chain_node = chain.id;
			bool isTexture = false;
			while(chain_node != NULL){
				if(chain_node->next == NULL){
					if(!isTexture){
						auto objNode = m_env->findFunction(chain_node->getName());
						assert(objNode != NULL, "undefined function of name '"+chain_node->getName()+"'");
						return objNode->inferType();
					}else{
						auto ret = new PTType();
						ret->m_type = PType::TYPE;
						ret->val = "vec4";
						return ret;
					}
				}else{
					auto objNode = m_env->find(chain_node->getName());
					assert(objNode != NULL, "undefined object named '"+chain_node->getName()+"'");
					auto objType = objNode->inferType();
					assert(objType->val == "texture2D", "only textures has a member function but you access object of type '"+objType->val+"'");
					isTexture = true;
				}
				chain_node = chain_node->next;
			}
		}

	};

	class PTConfig: public PTStatement{
	public:
		PTId builtin;
		PTExpression* id;

		PTConfig(){

		}

		virtual void printTree(std::ostream& out){
			out<<"Config Statement { ";
			builtin.printTree(out);
			id->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }
	        parent->m_children.push_back(this);
	        id->correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			if(id->m_type == PType::ID){
				auto cid = (PTId*)id;
				auto res = m_env->find(cid->val);
				assert(res!=NULL, "undefined object named '"+cid->val+"' associated with '"+builtin.val+"'");
			}else
				id->semanticAnalysis(dic);
		}
	};

	class PTTypeConstructor: public PTExpression{
	public:
		PTType type;
		std::vector<PTExpression*>& args;

		PTTypeConstructor(std::vector<PTExpression*>& _args):args(_args){}


		virtual void printTree(std::ostream& out){
			out<<"Type Constructor { ";
			type.printTree(out);
			for(auto arg:args)
				arg->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }

	        parent->m_children.push_back(this);
	        for(int i=0;i<args.size();i++){
	        	args[i]->correctTree(list,parent);
	        }
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}

		virtual void semanticAnalysis(Dictionary* dic){
			for(int i=0;i<args.size();i++)
				args[i]->semanticAnalysis(dic);
		}

		virtual PTType* inferType(){
			return type.inferType();
		}
	};

	class PTRoutine: public PTStatement{
	public:
		std::vector<PTConfig*>& data;
		PTId id;

		PTRoutine(std::vector<PTConfig*>& _data):data(_data){}

		virtual void printTree(std::ostream& out){
			out<<"Routine { ";
			for(int i=0;i<data.size();i++)
				data[i]->printTree(out);
			out<<"};"<<std::endl;
		}

		virtual void correctTree(std::vector<PTNode*>* list, PTNode* parent){
			if(m_parent!= NULL)
	        {
	            removeNode(&m_parent->m_children,this);
	        }
	        parent->m_children.push_back(this);
	        for(int i=0;i<data.size();i++)
	        	data[i]->correctTree(list,parent);
	        m_parent = parent;
	        m_env->prev = parent->m_env;
	        removeNode(list,this);
		}
		virtual void semanticAnalysis(Dictionary* dic){
			auto obj = m_env->findRoutine(id.val);
			assert(obj == NULL,"redefinition of routine '"+id.val+"'");
			m_env->prev->putRoutine(id.val,this);
			for(int i=0;i<data.size();i++)
				data[i]->semanticAnalysis(dic);
		}

		virtual std::string getNodeName(){
			return id.val;
		}

		std::string evaluate(std::string varName){
			std::string res;
			for(int i=0;i<data.size();i++){
				if(data[i]->builtin.val == varName){
					res = ((PTId*)data[i]->id)->val;
				}	
			}
			return res;
		}
	};
}

