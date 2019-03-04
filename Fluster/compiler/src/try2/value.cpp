#include "primitives.h"
#include "type.h"
#include "value.h"
//#include <types>

class Type;

namespace fluster {



virtual const Type& PrimitiveValue<int8_t >::typeof() const { return int8;  }
virtual const Type& PrimitiveValue<int16_t>::typeof() const { return int16; }
virtual const Type& PrimitiveValue<int32_t>::typeof() const { return int32; }
virtual const Type& PrimitiveValue<int64_t>::typeof() const { return int64; }



};
