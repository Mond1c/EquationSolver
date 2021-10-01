#include "equation.h"
using namespace EquationSolver;

void IEquation::addConst(std::unique_ptr<Token::IConst> token) {
    consts_.push_back(std::move(token));
}

void IEquation::addVar(std::unique_ptr<Token::IVar> token) {
    vars_.push_back(std::move(token));
}

std::vector<double> Equation::Linear::findX() const {
    return {};
}

std::vector<double> Equation::Quadratic::findX() const {
    return {};
}
