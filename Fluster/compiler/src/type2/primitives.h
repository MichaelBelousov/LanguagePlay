#ifndef FLUSTER_COMPILER_PRIMITIVES
#define FLUSTER_COMPILER_PRIMITIVES

#include <ctypes>

class Type;

namespace Fluster {



/* Primitive types */

//metatype primitive
extern static const Type TheType;

//integer primitive types
extern static const Type int8;
extern static const Type int16;
extern static const Type int32;
extern static const Type int64;
extern static const Type& int_ = int32;
//unsigned integer primitive types
extern static const Type uint8;
extern static const Type uint16;
extern static const Type uint32;
extern static const Type uint64;
extern static const Type& uint = uint32;

//floating point primitive types
extern static const Type float32;
extern static const Type float64;
extern static const Type& float_ = float32;

//raw types
extern static const Type bit;
extern static const Type byte;
extern static const Type word;


//TODO: std::enable_if<std::is_scalar<CppAnalogType>>::value>
template<typename CppAnalogType>
final class PrimitiveValue : public Value {
    CppAnalogType payload;
    virtual const Type& typeof() const override;
};

virtual const Type& PrimitiveValue<int8_t>::typeof() const {
    return int8;
}
virtual const Type& PrimitiveValue<int16_t>::typeof() const {
    return int16;
}


};

#endif //FLUSTER_COMPILER_PRIMITIVES
