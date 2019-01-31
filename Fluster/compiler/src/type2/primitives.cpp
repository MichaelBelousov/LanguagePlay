#include "primitives.h"
#include "type.h"

namespace Fluster {



/* Primitive types */

static const Type TheType;

//integer primitive types
static const Type int8;
static const Type int16;
static const Type int32;
static const Type int64;
static const Type& int_ = int32;
//unsigned integer primitive types
static const Type uint8;
static const Type uint16;
static const Type uint32;
static const Type uint64;
static const Type& uint = uint32;

//floating point primitive types
static const Type float32;
static const Type float64;
static const Type& float_ = float32;

//raw types
static const Type bit;
static const Type byte;
static const Type word;



};
