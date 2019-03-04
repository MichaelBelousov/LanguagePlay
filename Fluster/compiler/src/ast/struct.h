#ifndef FLUSTER_COMPILER_AST_STRUCT
#define FLUSTER_COMPILER_AST_STRUCT

#include <memory>
#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct StructDef : public Def {
//// Types
    using Ptr = std::shared_ptr<StructDef>;
//// Fields
    const std::vector<const TypeDef::Ptr> inheritances;
    const std::vector<const TypeDef::Ptr> embeddings;
    const std::vector<const FieldDef::Ptr> fields;
    const std::vector<const MethodDef::Ptr> methods;
    const std::vector<const FunctionDef::Ptr> functions;
    const std::vector<const ConversionDef::Ptr> conversions;
    const std::vector<const OperationDef::Ptr> operations;
//// Private Fields
    const fluster::data::Struct::Ptr underlying;
};



}; };

#endif //FLUSTER_COMPILER_AST_STRUCT
