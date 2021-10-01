#include "token_parser.h"
using namespace EquationSolver;
using namespace Token;

std::unique_ptr<IConst> Const::Parser::parse(const std::string& str) {
    return std::move(parseNumber(str));
}

std::unique_ptr<Const::Number> Const::Parser::parseNumber(std::string str) {
    if (str.empty()) str = "1";
    else if (str == "-") str = "-1";
    return std::move(std::make_unique<Const::Number>(std::stod(str)));
}

std::unique_ptr<IVar> Var::Parser::parse(const std::string& str) {
    return std::move(parseLinear(str, str.find('x')));
}

template<typename Iterator>
std::unique_ptr<Var::Linear> Var::Parser::parseLinear(const std::string& str, Iterator iterator) {
    auto ptr = std::make_unique<Var::Linear>();
    ptr->setToken(Const::Parser::parse(str.substr(0, iterator)));
    return std::move(ptr);
};
