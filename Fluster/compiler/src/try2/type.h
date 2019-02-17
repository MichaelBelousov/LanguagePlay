#ifndef FLUSTER_COMPILER_TYPE
#define FLUSTER_COMPILER_TYPE

#include <memory>
#include <map>
#include "value.h"
#include "utils.h"
#include "conversion.h"
#include "identifier.h"

namespace Fluster {

class Type;



using TypePtr = std::shared_ptr<Type>;

class Type : public BaseValue {

//// Public Types
public:
    enum class Kind;
    namespace Builder;
    friend ConversionTable; friend FunctionTable;

//// Public Interface
public:
    virtual TypePtr cloneof() const noexcept;
    const TypePtr typeof() const override;
    const bool is(TypePtr other) const noexcept;
    const bool has(TypePtr other) const noexcept;

 
//// Construction
public:
    Type();
    
//// Private Fields
private:
    Kind kind;
    PropertyTable props;
    ConversionTable conv_tbl;
    FunctionTable meth_tbl;
    FunctionTable func_tbl;

//// Operators
    friend bool operator==(const Type& lhs, const Type& rhs) noexcept;

};


enum class Type::Kind : /*public*/ uint8_t {
    meta,
    class_,
    struct_,
    primitive  //scalar
    //nil
};

namespace Type::Builder {
    static TypePtr Class();
    static TypePtr Struct();
    static TypePtr Custom(Properties properties, Type::Kind in_kind);
};



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE
