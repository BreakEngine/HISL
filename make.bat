  bison -d -o parser.cpp yacc.y
  flex -o tokens.cpp lex.l
  g++ -std=c++11 tokens.cpp parser.cpp -o hislc
  hislc<test\phase01.hisl
