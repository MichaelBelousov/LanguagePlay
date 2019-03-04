#ifndef FLUSTER_COMPILER_AST_LITERALS
#define FLUSTER_COMPILER_AST_LITERALS

#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct StringLiteral {
    std::string value;
};

struct FloatLiteral {
    std::string value;
};



}; };

#endif //FLUSTER_COMPILER_AST_LITERALS
