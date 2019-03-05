#ifndef FLUSTER_COMPILER_AST_EXCEPTION_FLOW
#define FLUSTER_COMPILER_AST_EXCEPTION_FLOW

#include <vector>
#include "ast/base.h"

namespace fluster { namespace ast {



struct ParamDef : public NamedDef
                , PtrType<ParamDef> {
    const Expr::Ptr type;
    const Expr::Ptr default_;
};


struct FunctionDef : public NamedDef
                   , public PtrType<FunctionDef> {
//// Fields
    const std::vector<ParamDef::Ptr> params;
    const Expr::Ptr type;
    const std::vector<Statement::Ptr> body;
};



}; };

#endif //FLUSTER_COMPILER_AST_FUNCTION
