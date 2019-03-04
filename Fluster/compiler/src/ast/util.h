#ifndef FLUSTER_COMPILER_AST_BASE
#define FLUSTER_COMPILER_AST_BASE

#include <memory>

namespace fluster { namespace ast {



template<typename T>
struct PtrType {
    using Ptr = std::shared_ptr<T>;
    using UniqPtr = std::unique_ptr<T>;
};



}; };

#endif //FLUSTER_COMPILER_AST_BASE
