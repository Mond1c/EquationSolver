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
            static std::unique_ptr<Const::Number> parseNumber(std::string str);
            static std::unique_ptr<Const::Power> parsePower(const std::string& str);
            static std::unique_ptr<Const::Irrational> parseIrrational(const std::string& str);
        };
    }

    namespace Var {
        class Parser {
        public:
            static std::unique_ptr<IVar> parse(const std::string& str);
        private:
            template<typename Iterator>
            static std::unique_ptr<Var::Linear> parseLinear(const std::string& str, Iterator iterator);
            
            template<typename Iterator>
            static std::unique_ptr<Var::Quadratic> parseQuadratic(const std::string& str, Iterator iterator);
            
            template<typename Iterator>
            static std::unique_ptr<Var::Irrational> parseIrrational(const std::string& str, Iterator iterator);
        };
    }
}
}
