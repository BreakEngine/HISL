#include <iostream>
#include "scanner.h"
using namespace std;


const std::string Break::HISL::Token::TypeText[] = { "",
  "None",        "DataType",    "Identifier",    "Open Brace",
  "Close Brace", "Open CBrace", "Close CBrace",  "Integer",
  "Semicolon",   "Float"
};
/*
*
*/
extern int yylex();
extern int yylineno;
extern char* yytext;

int main(){
  Token name;
  //yylex will return a valid token
  //when end of file will return 0
  name = yylex();

  while(name){
    //output the token
    cout<<"Token: "<<Break::HISL::Token::TypeText[name.type]<<" | Text: "<<name.str<<endl;
    name = yylex();
  }
  return 0;
}
