#ifndef FLUSTER_COMPILER_AST_FUNCTION
#define FLUSTER_COMPILER_AST_FUNCTION

#include <utility>
#include <vector>
#include "ast/base.h"
#include "ast/variable.h"

namespace fluster { namespace ast {



struct ParamDef : public VariableDef, PtrType<ParamDef> {};


struct FunctionDef : public NamedDef
                   , public PtrType<FunctionDef> {
//// Fields
    const std::vector<ParamDef::Ptr> params;
    const Expr::Ptr return_type;
    const std::vector<Statement::Ptr> body;
};

struct FunctionDef : public NamedDef
                   , public PtrType<FunctionDef> {
//// Fields
    const std::vector<ParamDef::Ptr> params;
    const Expr::Ptr return_type;
    const std::vector<Statement::Ptr> body;
};


}; };

#endif //FLUSTER_COMPILER_AST_FUNCTION
