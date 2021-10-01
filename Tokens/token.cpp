#include "token.h"
using namespace EquationSolver;
using namespace Token;

void IConst::setToken(std::unique_ptr<IConst> token) {
    token_ = std::move(token);
}

void IVar::setToken(std::unique_ptr<IConst> token) {
    token_ = std::move(token);
}

double Const::Number::calculate() const {
    return number_;
}

double Var::Linear::getFactor() const {
    return token_->calculate();
}
