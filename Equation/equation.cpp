#include "equation.h"
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
    return {};
}
