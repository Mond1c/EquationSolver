#pragma once
#include "../Tokens/token.h"
#include <memory>
#include <vector>

#define abstract 

namespace EquationSolver {
    abstract class IEquation {
    public:
        IEquation() = default;
        virtual ~IEquation() = default;
    public:
        void addConst(std::unique_ptr<Token::IConst> token);
        void addVar(std::unique_ptr<Token::IVar> token);
        virtual std::vector<double> findX() const = 0;
    protected:
        std::vector<std::unique_ptr<Token::IConst>> consts_;
        std::vector<std::unique_ptr<Token::IVar>> vars_;
    };

    namespace Equation {
        class Linear : public IEquation {
        public:
            Linear() = default;
            ~Linear() override = default;
        public:
            std::vector<double> findX() const override;
        };

        class Quadratic : public IEquation {
        public:
            Quadratic() = default;
            ~Quadratic() override = default;
        public:
            std::vector<double> findX() const override;
        };

        class Irrational : public IEquation {
        public:
            Irrational() = default;
            ~Irrational() override = default;
        public:
            std::vector<double> findX() const override;
        };
    }
}
