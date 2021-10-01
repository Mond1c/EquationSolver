#pragma once
#include "../Tokens/token.h"
#include "../Equation/equation.h"
#include <memory>
#include <string>

namespace EquationSolver {
    class Parser {
    public:
        std::unique_ptr<IEquation> parse(const std::string& str);
    private:
        std::unique_ptr<Equation::Linear> parseLinear(const std::vector<std::string>& expression);
        std::vector<std::string> split(const std::string& str, char separator);
    };
}
