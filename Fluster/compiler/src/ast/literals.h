#ifndef FLUSTER_COMPILER_AST_LITERALS
#define FLUSTER_COMPILER_AST_LITERALS

#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct Literal : public Expr {};

struct StringLiteral : public Literal {
    std::string value;
};

struct FloatLiteral : public Literal {
    float value;
};



}; };

#endif //FLUSTER_COMPILER_AST_LITERALS
