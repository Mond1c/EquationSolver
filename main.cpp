#include "Parser/parser.h"
#include <iostream>
using namespace EquationSolver;

int main(int argc, char* argv[]) {
    auto equation = Parser::parse("x -4 = 0");
    std::cout << equation->findX()[0] << std::endl;
    return 0;
}
