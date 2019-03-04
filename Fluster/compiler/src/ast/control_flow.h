#ifndef FLUSTER_COMPILER_AST_CONTROL_FLOW
#define FLUSTER_COMPILER_AST_CONTROL_FLOW

#include <utility>
#include <vector>
#include "ast/base.h"

namespace fluster { namespace ast {



struct ConditionalBlock : public Statement
                        , public PtrType<ConditionalBlock> {
    const Expr::Ptr condition;
    const std::vector<const Statement::Ptr> body;
};

struct Conditional : public Expr {
    const std::vector<const ConditionalBlock::Ptr> branches;
    const std::vector<const Statement::Ptr> else_body;
};

struct While : public Expr {
    const Expr::Ptr condition;
    const std::vector<const Statement::Ptr> body;
};

struct For : public Expr {
    const Expr::Ptr iterable;
    const std::vector<const Name> index_variables;
    const std::vector<const Statement::Ptr> body;
};



}; };

#endif //FLUSTER_COMPILER_AST_CONTROL_FLOW
