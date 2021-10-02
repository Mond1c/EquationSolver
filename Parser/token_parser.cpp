#include "token_parser.h"
#include <iostream>
using namespace EquationSolver;
using namespace Token;

std::unique_ptr<IConst> Const::Parser::parse(const std::string& str) {
    if (str.find("sqrt") != std::string::npos) return std::move(parseIrrational(str));
    if (str.find('^') != std::string::npos) return std::move(parsePower(str));
    return std::move(parseNumber(str));
}

std::unique_ptr<Const::Number> Const::Parser::parseNumber(std::string str) {
    if (str.empty()) str = "1";
    else if (str == "-") str = "-1";
    return std::move(std::make_unique<Const::Number>(std::stod(str)));
}

std::unique_ptr<Const::Power> Const::Parser::parsePower(const std::string& str) {
    auto it = str.find('^');
    return std::move(std::make_unique<Const::Power>(parse(str.substr(0, it)), std::stod(str.substr(it + 1, str.size()))));
}

std::unique_ptr<Const::Irrational> Const::Parser::parseIrrational(const std::string& str) {
    auto it = str.find(')');
    return std::move(std::make_unique<Const::Irrational>(parse(str.substr(it + 1, str.size()))));
}

std::unique_ptr<IVar> Var::Parser::parse(const std::string& str) {
    if (str.find("sqrt") != std::string::npos) return std::move(parseIrrational(str, str.find('x')));
    if (str.find('^') != std::string::npos) return std::move(parseQuadratic(str, str.find('x')));
    return std::move(parseLinear(str, str.find('x')));
}

template<typename Iterator>
std::unique_ptr<Var::Linear> Var::Parser::parseLinear(const std::string& str, Iterator iterator) {
    auto ptr = std::make_unique<Var::Linear>();
    ptr->setToken(Const::Parser::parse(str.substr(0, iterator)));
    return std::move(ptr);
};

template<typename Iterator>
std::unique_ptr<Var::Quadratic> Var::Parser::parseQuadratic(const std::string& str, Iterator iterator) {
    auto ptr = std::make_unique<Var::Quadratic>();
    ptr->setToken(Const::Parser::parse(str.substr(0, iterator)));
    return std::move(ptr);
}

template<typename Iterator>
std::unique_ptr<Var::Irrational> Var::Parser::parseIrrational(const std::string& str, Iterator iterator) {
    auto ptr = std::make_unique<Var::Irrational>();
    if (iterator - str.find('(') <= 1) ptr->setToken(Const::Parser::parse(""));
    else ptr->setToken(Const::Parser::parse(str.substr(str.find('(') + 1, iterator)));
    return std::move(ptr);
}
