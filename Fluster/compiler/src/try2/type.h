#ifndef FLUSTER_COMPILER_TYPE
#define FLUSTER_COMPILER_TYPE

#include <memory>
#include <map>
#include "value.h"
#include "utils.h"
#include "type_aux.h"

namespace fluster {

class Type;




using TypePtr = std::shared_ptr<Type>;

class Type : public BaseValue {

    //// Public Types
public:
    friend ConversionToTable;
    friend FunctionTable;
    enum class Kind : uint8_t {
        meta,
        class_,
        struct_,
        primitive  //scalar
        //nil
    };
    // TODO: can you nest namespaces in a class?
    struct Builder final {
        static TypePtr Class();
        static TypePtr Struct();
        static TypePtr Custom(Kind in_kind);
    };

    //// Public Interface
public:
    virtual TypePtr cloneof() const noexcept;
    const TypePtr typeof() const noexcept override;
    const bool is(TypePtr other) const noexcept;
    const bool has(TypePtr other) const noexcept;


    //// Construction
public:
    Type();

    //// Private Fields
private:
    Kind kind;
    PropertyTable props;
    ConversionToTable conv_tbl;
    FunctionTable meth_tbl;
    FunctionTable func_tbl;

    //// Operators
public:
    friend bool operator==(const Type& lhs, const Type& rhs) noexcept;

};






}; //namespace fluster

#endif //FLUSTER_COMPILER_TYPE
