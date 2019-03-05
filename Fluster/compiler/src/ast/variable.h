#ifndef FLUSTER_COMPILER_AST_VARIABLE
#define FLUSTER_COMPILER_AST_VARIABLE

#include <utility>
#include <vector>
#include "ast/base.h"

namespace fluster { namespace ast {



struct VariableDef : public NamedDef
                   , public PtrType<ParamDef> {
    const Expr::Ptr type;
    const Expr::Ptr default_;
};



}; };

#endif //FLUSTER_COMPILER_AST_VARIABLE
