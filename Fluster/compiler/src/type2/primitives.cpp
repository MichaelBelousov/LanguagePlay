#include "primitives.h"
#include "type.h"

namespace Fluster {



/* Primitive types */

static const Type TheType(new _Type);

//integer primitive types
static const Type int8(new _Type);
static const Type int16(new _Type);
static const Type int32(new _Type);
static const Type int64(new _Type);
static const Type& int_ = int32;
//unsigned integer primitive types
static const Type uint8(new _Type);
static const Type uint16(new _Type);
static const Type uint32(new _Type);
static const Type uint64(new _Type);
static const Type& uint = uint32;

//floating point primitive types
static const Type float32(new _Type);
static const Type float64(new _Type);
static const Type& float_ = float32;

//raw types
static const Type bit(new _Type);
static const Type byte(new _Type);
static const Type word(new _Type);



};
