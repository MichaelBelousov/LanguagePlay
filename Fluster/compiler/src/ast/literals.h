#ifndef FLUSTER_COMPILER_AST_LITERALS
#define FLUSTER_COMPILER_AST_LITERALS

#include <vector>
#include <string>
#include "ast/base.h"
#include "ast/function.h"
#include "ast/util.h"

namespace fluster { namespace ast {



struct Literal : public Expr {};

struct IntegerLiteral : public Literal {
    //underlying = PrimitiveValue<Integer>
};

struct StringLiteral : public Literal {
    //underlying = PrimitiveValue<String>
};

struct FloatLiteral : public Literal {
    //underlying = PrimitiveValue<float>
};

struct ArrayLiteral : public Literal {
    std::vector<Expr::Ptr> elements;
    // ensure array has same type
};

struct StructLiteralMemberDef : public Statement,
                                public PtrType<StructLiteralMemberDef> {};
struct StructLiteralFieldDef : public StructLiteralMemberDef
                             , public VariableDef {};
struct StructLiteralFunctionDef : public StructLiteralMemberDef
                                , public FunctionDef {};
struct StructLiteralMethodDef : public StructLiteralMemberDef
                              , public MethodDef {};

struct StructLiteral : public Literal {
    std::vector<StructLiteralMemberDef::Ptr> members;
};



}; };

#endif //FLUSTER_COMPILER_AST_LITERALS
