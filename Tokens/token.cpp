#include "token.h"
#include <cmath>
using namespace EquationSolver;
using namespace Token;

void IConst::setToken(std::unique_ptr<IConst> token) {
    token_ = std::move(token);
}

double IVar::getFactor() const {
    return token_->calculate();
}

void IVar::setToken(std::unique_ptr<IConst> token) {
    token_ = std::move(token);
}

void IVar::changeSign() {
    token_->changeSign();
}

double Const::Number::calculate() const {
    return number_;
}

void Const::Number::changeSign() {
    number_ *= -1;
}


double Const::Power::calculate() const {
    return factor_ * std::pow(token_->calculate(), power_);
}

void Const::Power::changeSign() {
    factor_ *= -1;
}

double Const::Irrational::calculate() const {
    return factor_ * std::sqrt(token_->calculate());
}

void Const::Irrational::changeSign() {
    factor_ *= -1;
}

Var::Type Var::Linear::getType() const {
    return Var::Type::LINEAR;
}

Var::Type Var::Quadratic::getType() const {
    return Var::Type::QUADRATIC;
}

Var::Type Var::Irrational::getType() const {
    return Var::Type::IRRATIONAL;
}
