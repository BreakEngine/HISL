#ifndef SCANNER_H
#define SCANNER_H
#include <string>

namespace Break{
  namespace HISL{

    class Token{
    public:
      enum Type{
        NONE=1, DATATYPE, ID, OPEN_BRACE, CLOSE_BRACE, OPEN_CBRACE,
        CLOSE_CBRACE, INT, SEMICOLON, FLOAT
      };
      const static std::string TypeText[];

      //type of this token
      Type type;
      //string of this token
      std::string str;

      //default constructor
      Token():type(Type::NONE), str(""){

      }

      Token(Type _type, std::string _str):type(_type),str(_str){

      }

    };

  }
}



#endif /* end of include guard: SCANNER_H */
