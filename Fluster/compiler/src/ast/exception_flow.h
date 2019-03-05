#ifndef FLUSTER_COMPILER_AST_EXCEPTION_FLOW
#define FLUSTER_COMPILER_AST_EXCEPTION_FLOW

#include <vector>
#include "ast/base.h"

namespace fluster { namespace ast {



struct CatchBlock : public Statement
                  , public PtrType<ConditionalBlock> {
    const Expr::Ptr exception_type;
    const std::vector<const Statement::Ptr> body;
};

struct TrialBlock : public Expr {
    const std::vector<const Statement::Ptr> body;
    const std::vector<const CatchBlock::Ptr> catches;
    const std::vector<const Statement::Ptr> else_body;
};



}; };

#endif //FLUSTER_COMPILER_AST_EXCEPTION_FLOW
