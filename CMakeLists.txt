cmake_minimum_required(VERSION 3.2)
project(HISL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES main.cpp Dictionary.cpp Driver.cpp Globals.cpp HISLCompiler.cpp lex.yy.c parser.cpp PTree.cpp scanner.cpp)
#add_executable(HISLC ${SOURCE_FILES})
add_library(HISL SHARED ${SOURCE_FILES})