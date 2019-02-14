#include "primitives.h"
#include "type.h"

namespace Fluster {



/* Primitive types */

static const TypePtr TheType(new Type);

//integer primitive types
static const TypePtr int8(new Type);
static const TypePtr int16(new Type);
static const TypePtr int32(new Type);
static const TypePtr int64(new Type);
static const TypePtr& int_ = int32;
//unsigned integer primitive types
static const TypePtr uint8(new Type);
static const TypePtr uint16(new Type);
static const TypePtr uint32(new Type);
static const TypePtr uint64(new Type);
static const TypePtr& uint = uint32;

//floating point primitive types
static const TypePtr float32(new Type);
static const TypePtr float64(new Type);
static const TypePtr& float_ = float32;

//raw types
static const TypePtr bit(new Type);
static const TypePtr byte(new Type);
static const TypePtr word(new Type);



};
