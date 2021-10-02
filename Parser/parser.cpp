#include "parser.h"
using namespace EquationSolver;


std::unique_ptr<IEquation> Parser::parse(const std::string& str) {
    std::vector<std::string> expression = split(str, ' ');
    if (str.find("sqrt") != std::string::npos) return parseIrrational(expression);
    if (str.find("^2") != std::string::npos) return parseQuadratic(expression);
    return parseLinear(expression);
}

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
            auto tmp = Token::Var::Parser::parse(str);
            if (!left) tmp->changeSign();
            ans->addVar(std::move(tmp));
        } else {
            auto tmp = Token::Const::Parser::parse(str);
            if (left) tmp->changeSign();
            ans->addConst(std::move(tmp));
        }
    }
    return std::move(ans);
}

std::unique_ptr<Equation::Quadratic> Parser::parseQuadratic(const std::vector<std::string>& expression) {
    bool left = true;
    std::unique_ptr<Equation::Quadratic> ans = std::make_unique<Equation::Quadratic>();
    for (const std::string& str : expression) {
        if (str == "=") {
            left = false;
            continue;
        }
        auto it = str.find('x');
        if (it != std::string::npos) {
            auto tmp = Token::Var::Parser::parse(str);
            if (!left) tmp->changeSign();
            ans->addVar(std::move(tmp));
        } else {
            auto tmp = Token::Const::Parser::parse(str);
            if (!left) tmp->changeSign();
            ans->addConst(std::move(tmp));
        }
    }
    return std::move(ans);
}

std::unique_ptr<Equation::Irrational> Parser::parseIrrational(const std::vector<std::string>& expression) {
    bool left = true;
    std::unique_ptr<Equation::Irrational> ans = std::make_unique<Equation::Irrational>();
    for (const std::string& str : expression) {
        if (str == "=") {
            left = false;
            continue;
        }
        auto it = str.find('x');
        if (it != std::string::npos) {
            auto tmp = Token::Var::Parser::parse(str);
            if (!left) tmp->changeSign();
            ans->addVar(std::move(tmp));
        } else {
            auto tmp = Token::Const::Parser::parse(str);
            if (left) tmp->changeSign();
            ans->addConst(std::move(tmp));
        }
    }
    return std::move(ans);
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
