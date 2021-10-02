#include "equation.h"
#include <iostream>
#include <cmath>
using namespace EquationSolver;

void IEquation::addConst(std::unique_ptr<Token::IConst> token) {
    consts_.push_back(std::move(token));
}

void IEquation::addVar(std::unique_ptr<Token::IVar> token) {
    vars_.push_back(std::move(token));
}

std::vector<double> Equation::Linear::findX() const {
    double consts_sum = 0;
    double vars_sum = 0;
    for (const auto& token : consts_) {
        consts_sum += token->calculate();
    }
    for (const auto& token : vars_) {
        vars_sum += token->getFactor();
    }
    return {consts_sum / vars_sum};
}

std::vector<double> Equation::Quadratic::findX() const {
    double a = 0, b = 0, c = 0;
    for (const auto& token : vars_) {
        if (token->getType() == Token::Var::Type::QUADRATIC) {
            a += token->getFactor();
        } else {
            b += token->getFactor();
        }
    }

    for (const auto& token : consts_) {
        c += token->calculate();
    }

    double d = b * b - 4 * a * c;
    if (d < 0) {
        std::cout << "D < 0" << std::endl;
        return {};
    }
    if (d == 0) {
        return {(-b) / (2 * a)};
    }
    d = std::sqrt(d);
    return {(-b + d) / (2 * a), (-b - d) / (2 * a) };
}

std::vector<double> Equation::Irrational::findX() const {
    double consts_sum = 0;
    double vars_sum = 0;
    for (const auto& token : consts_) {
        consts_sum += token->calculate();
    }
    for (const auto& token : vars_) {
        vars_sum += token->getFactor();
    }

    return {(consts_sum * consts_sum) / vars_sum};
}
