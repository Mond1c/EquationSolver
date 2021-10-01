#pragma once
#include "../Tokens/token.h"
#include <memory>
#include <string>

namespace EquationSolver {
namespace Token {
    namespace Const {
        class Parser {
        public:
            static std::unique_ptr<IConst> parse(const std::string& str);
        private:
            static std::unique_ptr<Const::Number> parseNumber(const std::string& str);
        };
    }

    namespace Var {
        class Parser {
        public:
            static std::unique_ptr<IVar> parse(const std::string& str);
        private:
            template<typename Iterator>
            static std::unique_ptr<Var::Linear> parseLinear(const std::string& str, Iterator iterator);
        };
    }
}
}
