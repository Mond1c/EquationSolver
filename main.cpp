#include "Parser/parser.h"
#include <iostream>
using namespace EquationSolver;

int main(int argc, char* argv[]) {
    auto equation = Parser::parse("sqrt(x) -2 = 0");
    auto ans = equation->findX();
    for (int i = 0; i < ans.size(); ++i) std::cout << ans[i] << " ";
    std::cout << std::endl;
    return 0;
}
