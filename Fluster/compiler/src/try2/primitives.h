#ifndef FLUSTER_COMPILER_PRIMITIVES
#define FLUSTER_COMPILER_PRIMITIVES

#include <cstdint>
#include "type.h"

namespace Fluster {



/* Primitive types */

//metatype primitive
extern const TypePtr TheType;

//integer primitive types
extern const TypePtr int8;
extern const TypePtr int16;
extern const TypePtr int32;
extern const TypePtr int64;
extern const TypePtr& int_;// = int32;
//unsigned integer primitive types
extern const TypePtr uint8;
extern const TypePtr uint16;
extern const TypePtr uint32;
extern const TypePtr uint64;
extern const TypePtr& uint;// = uint32;

//floating point primitive types
extern const TypePtr float32;
extern const TypePtr float64;
extern const TypePtr& float_;// = float32;

//raw types
extern const TypePtr bit;
extern const TypePtr byte;
extern const TypePtr word;


//TODO: std::enable_if<std::is_scalar<CppAnalogType>>::value>
template<typename CppAnalogType>
class PrimitiveValue final : public BaseValue {
    CppAnalogType payload;
    const TypePtr typeof() const noexcept final;
};

#define DEF_PRIMITIVE(ctype, real) \
    const TypePtr \
        PrimitiveValue<(ctype)>:: \
    typeof() const noexcept final \
{ \
    return (real); \
}

DEF_PRIMITIVE(std::int8_t,int8)
DEF_PRIMITIVE(std::int16_t,int16)
DEF_PRIMITIVE(std::int32_t,int32)
DEF_PRIMITIVE(std::int64_t,int64)

DEF_PRIMITIVE(std::uint8_t,uint8)
DEF_PRIMITIVE(std::uint16_t,uint16)
DEF_PRIMITIVE(std::uint32_t,uint32)
DEF_PRIMITIVE(std::uint64_t,uint64)



};

#endif //FLUSTER_COMPILER_PRIMITIVES
