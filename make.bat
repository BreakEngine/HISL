bison -d parser.ypp -o parser.cpp
flex -o scanner.cpp scanner.l
g++ -std=c++11 -g Globals.cpp Driver.cpp main.cpp scanner.cpp parser.cpp Dictionary.cpp PTree.cpp -o hislc