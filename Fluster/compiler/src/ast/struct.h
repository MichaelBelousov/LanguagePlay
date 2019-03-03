#ifndef FLUSTER_COMPILER_AST_STRUCT
#define FLUSTER_COMPILER_AST_STRUCT

#include <memory>
#include <vector>
#include <string>
#include "ast/base.h"

namespace fluster { namespace ast {



struct Struct : public Type {
//// Types
    using Ptr = std::shared_ptr<Struct>;
//// Fields
    const std::vector<const TypeDecl::Ptr> inheritances;
    const std::vector<const TypeDecl::Ptr> embeddings;
    const std::vector<const FieldDecl::Ptr> fields;
    const std::vector<const MethodDecl::Ptr> methods;
    const std::vector<const FunctionDecl::Ptr> functions;
    const std::vector<const ConversionToDecl::Ptr> conversions;
    const std::vector<const OperationDecl::Ptr> operations;

    const fluster::data::Struct::Ptr underlying;
};



}; };

#endif //FLUSTER_COMPILER_AST_STRUCT
