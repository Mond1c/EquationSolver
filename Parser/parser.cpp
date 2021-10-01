#include "parser.h"
using namespace EquationSolver;

std::unique_ptr<Equation::Linear> Parser::parseLinear(const std::vector<std::string>& expression) {
    bool left = true;
    std::unique_ptr<Equation::Linear> ans = std::make_unique<Equation::Linear>();
    for (const std::string& str : expression) {
        if (str == "=") {
            left = false;
            continue;
        }
        auto it = str.find('x');
        if (it != std::string::npos) {
        } else {
        }
    }
}

std::vector<std::string> Parser::split(const std::string& str, char separator) {
    std::vector<std::string> value;
    std::string tmp;
    for (char ch : str) {
        if (ch == separator) {
            value.push_back(tmp);
            tmp.clear();
        } else {
            tmp += ch;
        }
    }
    if (!tmp.empty()) value.push_back(tmp);
    return value;
}
