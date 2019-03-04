#ifndef FLUSTER_COMPILER_AST_RETURN
#define FLUSTER_COMPILER_AST_RETURN

#include <utility>
#include <vector>
#include "ast/base.h"

namespace fluster { namespace ast {



struct ReturnStatement : public Statement
                       , public PtrType<ReturnStatement> {
    const Expr::Ptr return_expr;
};

struct ParamDef : public NamedDef
                , public PtrType<ParamDef> {
    const Expr::Ptr type;
    const Expr::Ptr default_;
};


struct FunctionDef : public NamedDef
                   , public PtrType<FunctionDef> {
//// Fields
    const std::vector<const ParamDef::Ptr> parameters;
    const Expr::Ptr return_type;
    const std::vector<const Statement::Ptr> body;
};



}; };

#endif //FLUSTER_COMPILER_AST_RETURN
