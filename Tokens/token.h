#pragma once

#include <memory>
#define abstract 

namespace EquationSolver {
namespace Token {

    abstract class IConst {
    public:
        IConst() = default;
        virtual ~IConst() = default;
    public:
        virtual double calculate() const = 0;
        void setToken(std::unique_ptr<IConst> token);
    protected:
        std::unique_ptr<IConst> token_;
    };

    abstract class IVar {
    public:
        IVar() = default;
        virtual ~IVar() = default;
    public:
        virtual double getFactor() const = 0;
        void setToken(std::unique_ptr<IConst> token);
    protected:
        std::unique_ptr<IConst> token_;
    };

    namespace Const {
        class Number : public IConst {
        public:
            Number(double number) : number_(number) {}
            ~Number() override = default;
        public:
            double calculate() const override;
        private:
            double number_;
        };
    }

    namespace Var {
        class Linear : public IVar {
        public:
            Linear() = default;
            ~Linear() override = default;
        public:
            double getFactor() const override;
        };
    }
}
}
