#ifndef FLUSTER_COMPILER_AST_BASE
#define FLUSTER_COMPILER_AST_BASE

#include <memory>
#include <array>
#include <string>
#include <vector>

namespace fluster { namespace ast {



// TODO: compiler is all about verbosity, this
// setting is for the future when the compiler
// can have a skim milk mode
/*
enum class Verbosity {
    none,
    standard
};
template<Verbosity verbosity = none>
struct _blah {};
struct _blah<standard> { member; };
*/

using Name = std::string;

enum class ExprType {
};

struct Def {
    using Ptr = std::shared_ptr<Def>;
    Def::Ptr next;
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
