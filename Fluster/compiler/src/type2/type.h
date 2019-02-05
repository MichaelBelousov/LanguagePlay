#ifndef FLUSTER_COMPILER_TYPE
#define FLUSTER_COMPILER_TYPE

#include <memory>
#include <map>
#include "value.h"
#include "utils.h"
#include "identifier.h"

namespace Fluster {

class Type;



using TypePtr = std::shared_ptr<Type>;
using Props = Dict<Identifier, Value>;

class Type : public Value {

//// Public Types
public:
    enum class Kind;
    namespace Builder;

//// Public Interface
public:
    virtual TypePtr cloneof() const;
    const TypePtr typeof() const override;
 
//// Construction
public:
    Type();
    
//// Private Fields
private:
    Kind kind;
    Props props;

//// Operators
    friend bool operator==(const Type& lhs, const Type& rhs);

};


enum class Type::Kind : int {
    meta,
    class_,
    struct_,
    primitive
};

namespace Type::Builder {
    static TypePtr Class();
    static TypePtr Struct();
    static TypePtr Special(Properties properties, Type::Kind in_kind);
};


}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE
