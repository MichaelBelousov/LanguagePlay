#ifndef FLUSTER_COMPILER_AST_BASE
#define FLUSTER_COMPILER_AST_BASE

#include <memory>
#include <array>
#include <string>
#include <vector>

namespace Fluster { namespace ast {



enum class ExprType {
};

struct Declaration {
    using Ptr = std::shared_ptr<Declaration>;
    DeclarationPtr next;
    //ScopePtr _outer;
}

struct Expr {
    using Ptr = std::shared_ptr<Expr>;
};

template<int N>
struct NaryExpr : public Expr {};

struct Operator : public Expr {};

template<int N>
struct NaryOperator : public Operator {
    std::array<Expr::Ptr, N> operands;
};

using UnaryOperator = NaryOperator<1>;

struct BinaryOperator : public NaryOperator<2> {
    Expr::Ptr leftOperand() { return operands[0]; }
    Expr::Ptr rightOperand() { return operands[1]; }
};

struct TernaryOperator : public NaryOperator<3> {
    Expr::Ptr firstOperand() { return operands[0]; }
    Expr::Ptr secondOperand() { return operands[1]; }
    Expr::Ptr thirdOperand() { return operands[2]; }
};

struct InvokeOperation : public Operator {
    std::vector<Expr::Ptr> arguments;
    Expr::Ptr invokee;
};

struct Name {
};



}; };

#endif //FLUSTER_COMPILER_AST_BASE
