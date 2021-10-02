#pragma once

#include <memory>
#define abstract 

namespace EquationSolver {
namespace Token {
    namespace Var {
        enum Type {
            LINEAR,
            QUADRATIC
        };
    }

    abstract class IConst {
    public:
        IConst() = default;
        virtual ~IConst() = default;
    public:
        virtual double calculate() const = 0;
        void setToken(std::unique_ptr<IConst> token);
        virtual void changeSign() = 0;
    protected:
        std::unique_ptr<IConst> token_;
    };

    abstract class IVar {
    public:
        IVar() = default;
        virtual ~IVar() = default;
    public:
        double getFactor() const;
        virtual Var::Type getType() const = 0;
        void setToken(std::unique_ptr<IConst> token);
        void changeSign();
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
            void changeSign() override;
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
            Type getType() const override;
        };

        class Quadratic : public IVar {
        public:
            Quadratic() = default;
            ~Quadratic() override = default;
        public:
            Type getType() const override;
        };
    }
}
}
