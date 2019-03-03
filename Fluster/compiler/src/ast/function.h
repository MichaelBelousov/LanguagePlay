#ifndef FLUSTER_COMPILER_AST_FUNCTION
#define FLUSTER_COMPILER_AST_FUNCTION

#include <memory>
#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct FunctionDef : public Type {
//// Types
    using Ptr = std::shared_ptr<Struct>;
//// Fields
    const std::vector<> params;
};



}; };

#endif //FLUSTER_COMPILER_AST_FUNCTION
