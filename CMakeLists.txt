cmake_minimum_required(VERSION 3.17)
project(EquationSolver)
set(CMAKE_CXX_STANDARD 20)

include_directories(.)
add_executable(EquationSover main.cpp
        Tokens/token.h Tokens/token.cpp
        Equation/equation.h Equation/equation.cpp
        Parser/parser.h Parser/parser.cpp
        Parser/token_parser.h Parser/token_parser.cpp)
