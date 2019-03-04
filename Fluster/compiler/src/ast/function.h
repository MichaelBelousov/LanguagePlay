#ifndef FLUSTER_COMPILER_AST_FUNCTION
#define FLUSTER_COMPILER_AST_FUNCTION

#include <memory>
#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct ParamDef : public Def {
}

struct FunctionDef : public Def {
//// Types
    using Ptr = std::shared_ptr<FunctionDef>;
//// Fields
    const Name name;
    const std::vector<ParamDef> params;
};



}; };

#endif //FLUSTER_COMPILER_AST_FUNCTION
