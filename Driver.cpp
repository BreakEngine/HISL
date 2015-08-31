#include "Driver.hpp"
#include "PTree.hpp"
#include "Dictionary.hpp"
#include "parser.hpp"
#include <sstream>
using namespace HISL;


extern int yyparse();
extern void switchBuffer(const char* bfr);
extern void terminateBuffer();

Driver::Driver():m_location(new location)
{
	m_test = -12;
	m_PTroot = new PTNode();
	m_PTroot->m_parent = NULL;
	m_PTroot->m_type = PType::NONE;
	m_std = new PTNode();
	m_std->m_parent = NULL;
	m_std->m_type = PType::NONE;
	m_dictionary = new Dictionary();
}

Driver::~Driver(){
	if(m_location)
		delete m_location;
	if(m_PTroot)
		delete m_PTroot;
}

void Driver::reset(){
	if(m_location)
		delete m_location;
	m_location = new location();
}

int Driver::parse(compilerConfig* config){
	if(config->fromFile){
		std::string compilestr = read(config->fileName);
		switchBuffer(compilestr.c_str());
		yyparse();
		terminateBuffer();
	}else{
		yyparse();
	}
	return 0;
}

int Driver::parseFile(std::string& path){
	std::ifstream s(path.c_str(), std::ifstream::in);

	s.close();
	return 0;
}

void Driver::printTree(){
	std::stringstream out;
	m_PTroot->printTree(out);
	std::cerr<<out.str()<<std::endl;
}

void Driver::correctTree(){
	std::vector<PTNode*> nodes;
	for(int i=0;i<m_PTroot->m_children.size();i++){
		nodes.push_back(m_PTroot->m_children[i]);
	}
	m_PTroot->m_children.clear();
	while(nodes.size()>0){
		nodes[0]->correctTree(&nodes,m_PTroot);
	}
}

void Driver::semanticAnalysis(){
	for(int i=0;i<m_PTroot->m_children.size();i++)
		m_PTroot->m_children[i]->semanticAnalysis(m_dictionary);
}

void Driver::handleMultiplication(){
	for(int i=0;i<m_PTroot->m_children.size();i++)
		m_PTroot->m_children[i]->handleMultiplication();
}

std::string Driver::generateCode(compilerConfig* config){
	std::string code_str;
	std::stringstream predef,code;
	auto program = m_PTroot->find("main", PType::PROGRAM);
	assert(program != NULL,"can't find entry program 'main'");
	program->generateCode(predef,code,config);
	code_str += predef.str();
	code_str += code.str();
	return code_str;
}

PTInt* Driver::createInteger(std::string& val){
	PTInt* res = new PTInt();
	res->m_parent = NULL;
	res->m_type = PType::INT;
	res->val = std::stoi(val);
	res->m_env = new Env();
	return res;
}

PTFloat* Driver::createFloat(std::string& val){
	PTFloat* res = new PTFloat();
	res->m_parent = NULL;
	res->m_type = PType::FLOAT;
	res->val = std::stof(val);
	res->m_env = new Env();
	return res;	
}

PTType* Driver::createType(std::string val){
	PTType* res= new PTType();
	res->m_parent = NULL;
	res->m_type = PType::TYPE;
	res->val = val;
	res->m_env = new Env();
	return res;
}
PTId* Driver::createId(std::string val){
	auto res = new PTId();
	res->m_parent = NULL;
	res->m_type = PType::ID;
	res->val = val;
	res->m_env = new Env();
	return res;
}

PTForwardDeclaration* Driver::createDeclaration(PTNode* type, PTNode* id){
	auto res= new PTForwardDeclaration();
	res->m_parent = NULL;
	res->m_type = PType::DECLARATION;

	auto ctype = (PTType*)type;
	assert(ctype != NULL, "invalid type",m_location);
	auto cid = (PTId*)id;
	assert(cid != NULL, "invalid identifier",m_location);


	res->type = *ctype;
	res->id = *cid;
	res->m_env = new Env();
	return res;
}

PTVariableDeclaration* Driver::createVarDcl(PTNode* type, PTNode* idList){
	auto res = new PTVariableDeclaration();

	res->m_parent = NULL;
	res->m_type = PType::VARIABLE_DECLARATION;

	auto ctype = (PTType*)type;
	assert(ctype != NULL, "invalid type",m_location);
	auto cidlst = (PTVariableList*)idList;
	assert(cidlst != NULL, "invalid identifiers", m_location);
	cidlst->m_env = new Env();
	cidlst->type = *ctype;
	res->type = *ctype;
	res->variables = *cidlst;

	res->m_env = new Env();
	return res;
}
PTUniform* Driver::createUniform(PTNode* id, std::vector<PTStatement*>& data){
	auto res = new PTUniform(data);
	res->m_parent = NULL;
	res->m_type = PType::UNIFORM;
	auto cid = (PTId*)id;
	assert(cid!=NULL,"invalid identifier",m_location);

	res->id = *cid;
	res->m_env = new Env();
	return res;
}
PTStruct* Driver::createStruct(PTNode* id,std::vector<PTStatement*>& data){
	auto res = new PTStruct(data);

	res->m_parent = NULL;
	res->m_type = PType::STRUCT;

	auto cid = (PTId*)id;
	assert(cid!=NULL,"invalid identifier", m_location);

	res->id = *cid;
	res->m_env = new Env();

	return res;
}

PTSemanticVariable* Driver::createSemanticVar(PTNode* type, PTNode* id, PTNode* sem){
	auto res = new PTSemanticVariable();

	res->m_parent = NULL;
	res->m_type = PType::SEMANTIC_VARIABLE;

	auto ctype = (PTType*)type;
	assert(ctype != NULL,"invalid type",m_location);
	auto cid = (PTId*) id;
	assert(cid != NULL,"invalid identifier",m_location);
	auto csem = (PTId*) sem;
	assert(csem != NULL,"invalid semantic",m_location);

	res->type = *ctype;
	res->id = *cid;
	res->semantic = *csem;
	res->m_env = new Env();

	return res;
}

PTIOBuffer* Driver::createBuffer(PTNode* id,std::vector<PTSemanticVariable>& data){
	auto res = new PTIOBuffer(data);

	res->m_parent = NULL;
	res->m_type = PType::IOBUFFER;

	auto cid = (PTId*)id;
	assert(cid!=NULL,"invalid identifier", m_location);

	res->id = *cid;
	res->m_env = new Env();

	return res;
}

PTBlock* Driver::createBlock(){
	auto res = new PTBlock();

	res->m_parent = NULL;
	res->m_type = PType::BLOCK;

	res->m_env = new Env();

	return res;
}

PTStage* Driver::createVertex(PTNode* id, PTNode* block){
	auto res = new PTStage();

	res->m_parent = NULL;
	res->m_type = PType::VERTEX;

	auto cid = (PTId*)id;
	assert(cid != NULL,"invalid identifier",m_location);
	auto cblock = (PTBlock*)block;
	assert(cblock != NULL,"invalid block",m_location);

	res->id = *cid;
	res->block = *cblock;
	res->m_env = new Env();

	return res;
}

PTStage* Driver::createPixel(PTNode* id, PTNode* block){
	auto res = new PTStage();

	res->m_parent = NULL;
	res->m_type = PType::PIXEL;

	auto cid = (PTId*)id;
	assert(cid != NULL,"invalid identifier",m_location);
	auto cblock = (PTBlock*)block;
	assert(cblock != NULL,"invalid block",m_location);

	res->id = *cid;
	res->block = *cblock;
	res->m_env = new Env();

	return res;
}

PTArg* Driver::createArg(PTNode* type, PTNode* id){
	auto res = new PTArg();

	res->m_parent = NULL;
	res->m_type = PType::ARGUMENT;

	auto ctype = (PTType*) type;
	assert(ctype != NULL, "invalid type", m_location);
	res->type = *ctype;

	if(id!=NULL){
		auto cid = (PTId*)id;
		assert(cid != NULL, "invalid identifier", m_location);
		res->id = cid;
	}
	res->m_env = new Env();

	return res;
}

PTFunctionDeclaration* Driver::createFuncDcl(PTNode* ret, PTNode* id, std::vector<PTArg>& args){
	auto res = new PTFunctionDeclaration(args);

	res->m_parent = NULL;
	res->m_type = PType::FUNCTION_DECLARATION;

	auto ctype = (PTType*)ret;
	assert(ctype != NULL,"invalid type",m_location);

	auto cid = (PTId*)id;
	assert(cid != NULL,"invalid identifier", m_location);

	res->returnType = *ctype;
	res->id = *cid;
	res->m_env = new Env();

	return res;
}

PTFunctionDefinition* Driver::createFuncDef(PTFunctionDeclaration* sign,PTBlock* block){

	auto res = new PTFunctionDefinition(*sign,*block);

	res->m_parent = NULL;
	res->m_type = PType::FUNCTION_DEFINITION;

	res->m_env = new Env();

	return res;
}

PTProgram* Driver::createProgram(PTId* id, PTBlock* block){
	auto res = new PTProgram(*id,*block);

	res->m_parent = NULL;
	res->m_type = PType::PROGRAM;

	res->m_env = new Env();

	return res;
}

PTBinaryExpression* Driver::createBinaryExp(PTExpression* lhs, std::string* op, PTExpression* rhs){
	auto res = new PTBinaryExpression(*lhs,*op,*rhs);

	res->m_parent = NULL;
	res->m_type = PType::BINARY_EXP;

	res->m_env = new Env();

	return res;
}

PTUnaryExpression* Driver::createUnaryExp(std::string* op, PTExpression* uhs, bool after){
	auto res = new PTUnaryExpression(*op,*uhs,after);

	res->m_parent = NULL;
	res->m_type = PType::UNARY_EXP;
	res->m_env = new Env();
	return res;
}

PTExpressionStmt* Driver::createExpressionStmt(PTExpression* expr){
	auto res = new PTExpressionStmt(*expr);

	res->m_parent = NULL;
	res->m_type = PType::EXPR_STMT;
	res->m_env = new Env();
	return res;
}

PTVarCall* Driver::createVarCall(std::string* id,std::string op){
	auto res= new PTVarCall();

	res->m_parent = NULL;
	res->m_type = PType::VAR_CALL;

	res->id = *createId(*id);
	res->op = op;
	res->m_env = new Env();

	return res;
}

PTArrayDeclaration* Driver::createArrayDcl(PTNode* type,std::string id,PTInt* size){
	auto res = new PTArrayDeclaration();

	res->m_parent = NULL;
	res->m_type = PType::ARRAY_DECLARATION;

	res->id = *createId(id);
	PTType* cType = (PTType*)type;
	assert(cType!=NULL,"invalid type of array '"+id+"'");
	res->type = *cType;
	res->size = size->val;

	res->m_env = new Env();

	return res;
}

PTArrayCall* Driver::createArrayCall(PTId* id,PTExpression* index,std::string op){
	auto res= new PTArrayCall(*id,*index,op);

	res->m_parent = NULL;
	res->m_type = PType::ARRAY_CALL;
	res->m_env = new Env();

	return res;
}

PTAccessChain* Driver::createAccessChain(PTLValue* chain){
	auto res = new PTAccessChain(chain);

	res->m_parent = NULL;
	res->m_type = PType::ACCESS_CHAIN;
	res->m_env = new Env();

	return res;
}

PTAssignment* Driver::createAssignment(PTLValue* lhs, std::string op, PTExpression* rhs){
	auto res = new PTAssignment(*lhs,op,*rhs);

	res->m_parent = NULL;
	res->m_type = PType::ASSIGNMENT;
	res->m_env = new Env();

	return res;
}
PTFunctionCall* Driver::createFunctionCall(PTAccessChain* id, std::vector<PTExpression*>* args){
	auto res= new PTFunctionCall(*id,*args);

	res->m_parent = NULL;
	res->m_type = PType::FUNCTION_CALL;
	res->m_env = new Env();
	return res;
}

PTTypeConstructor* Driver::createTypeConstructor(PTType* type,std::vector<PTExpression*>* args){
	auto res = new PTTypeConstructor(*args);

	res->m_parent= NULL;
	res->m_type = PType::TYPE_CONSTRUCTOR;
	res->m_env = new Env();

	res->type = *type;

	return res;
}

PTConfig* Driver::createConfigStatement(PTId* builtin, PTExpression* obj){
	auto res = new PTConfig();

	res->m_parent = NULL;
	res->m_type = PType::CONFIG_STATEMENT;
	res->m_env = new Env();

	res->builtin = *builtin;
	res->id = obj;

	return res;
}

PTRoutine* Driver::createRoutine(PTId* id,std::vector<PTConfig*> *data){
	auto res = new PTRoutine(*data);

	res->id = *id;

	res->m_parent = NULL;
	res->m_type = PType::ROUTINE;
	res->m_env = new Env();

	return res;
}