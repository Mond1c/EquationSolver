#pragma once
#include "../Tokens/token.h"
#include "../Equation/equation.h"
#include "token_parser.h"
#include <memory>
#include <string>

namespace EquationSolver {
    class Parser {
    public:
        static std::unique_ptr<IEquation> parse(const std::string& str);
    private:
        static std::unique_ptr<Equation::Linear> parseLinear(const std::vector<std::string>& expression);
        static std::unique_ptr<Equation::Quadratic> parseQuadratic(const std::vector<std::string>& expression);
        static std::vector<std::string> split(const std::string& str, char separator);
    };
}
