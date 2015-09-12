%{
	#include <iostream>
	#include "Driver.hpp"
	#include "parser.hpp"
	extern HISL::Driver* driver;
	YY_BUFFER_STATE buffer_state;
	#define STEP() driver->m_location->step()

	#define COL(Col) driver->m_location->columns(Col)
	#define LINE(Line) driver->m_location->lines(Line)
	#define SAVE_TOKEN yylval.value = new std::string (yytext,yyleng)
	
	std::string* consumeString();
	void comment();
	void yyerror(std::string e);
%}
%option noyywrap
%option nounistd
%option never-interactive

D [0-9]
L [a-zA-z_]

%%
%{
	//STEP();
%}

[\n\r]+ {LINE(yyleng);}
[ \t]+  {STEP();}

(["])					{yylval.value = consumeString(); return STRING;}
"//".*					{}
"/*"					{comment();}
"GLSL"					{return GLSL;}
"HLSL"					{return HLSL;}
"int"					{SAVE_TOKEN; return TYPE;}
"float"					{SAVE_TOKEN; return TYPE;}
"bool"					{SAVE_TOKEN; return TYPE;}
"vec2"					{SAVE_TOKEN; return TYPE;}
"vec3"					{SAVE_TOKEN; return TYPE;}
"vec4"					{SAVE_TOKEN; return TYPE;}
"mat2"					{SAVE_TOKEN; return TYPE;}
"mat3"					{SAVE_TOKEN; return TYPE;}
"mat4"					{SAVE_TOKEN; return TYPE;}
"texture2D"				{SAVE_TOKEN; return TYPE;}
"if"					{return IF;}
"else"					{return ELSE;}
"struct"				{return STRUCT;}
"routine"				{return ROUTINE;}
"vertex"				{return VERTEX;}
"pixel"					{return PIXEL;}
"program"				{return PROGRAM;}
"iobuffer"				{return IOBUFFER;}
"uniform"				{return UNIFORM;}
"while"					{return WHILE;}
"for"					{return FOR;}
"return"				{return RETURN;}
"->"					{return ARROW;}
"++"					{return INC;}
"--"					{return DEC;}
"+="					{return PLUS_EQL;}
"-="					{return MINUS_EQL;}
"*="					{return MUL_EQL;}
"/="					{return DEV_EQL;}
"%="					{return MOD_EQL;}
"+"						{return PLUS;}
"-"						{return MINUS;}
"*"						{return MUL;}
"/"						{return DEV;}
"%"						{return MOD;}
"<="					{return LEQL;}
">="					{return GEQL;}
"=="					{return QEQL;}
"!="					{return NOT_EQL;}
"&&"					{return AND;}
"||"					{return OR;}
"!"						{return NOT;}
"="						{return EQL;}
"("						{return OPEN_PAREN;}
")"						{return CLOSE_PAREN;}
"{"						{return OPEN_BRACE;}
"}"						{return CLOSE_BRACE;}
"["						{return OPEN_BRACKET;}
"]"						{return CLOSE_BRACKET;}
";"						{return SEMICOLON;}
","					    {return COMMA;}
"."						{return DOT;}
":"						{return COLON;}
"g_"{L}+				{SAVE_TOKEN; return BUILTIN_VAR;}
{D}+ 					{SAVE_TOKEN; return INTEGER;}
{D}+"."{D}+				{SAVE_TOKEN; return FLOAT; }
[a-zA-Z][a-zA-Z0-9_]*	{SAVE_TOKEN; return ID;}
. 						{yyterminate();}
%%

std::string* consumeString(){
	std::string *str = new std::string();
	
	int x;
	while((x = yyinput()) != 0){
		if(x=='"')
			return str;
		if(x == 0)
			break;
			
		str->push_back((char)x);
	}
	yyerror("string object didn't close properly");
	return NULL;
} 
void comment(){
	int c;
	
	while((c = yyinput()) != 0){
		if(c == '*'){
			while((c=yyinput()) == '*');
			
			if(c=='/')
				return;
			
			if(c==0)
				break;
		}
	}
	yyerror("unterminated comment");
}

void switchBuffer(const char* bfr){
	int len = strlen(bfr);
	char* tmp = new char[len+2];
	strcpy(tmp,bfr);
	tmp[len+1]= 0;
	buffer_state = yy_scan_string(tmp);
	yy_switch_to_buffer(buffer_state);
}

void terminateBuffer(){
	yy_delete_buffer(buffer_state);
}