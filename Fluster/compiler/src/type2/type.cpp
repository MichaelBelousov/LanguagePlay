#include "type.h"
#include "primitives.h"

namespace Fluster {



//// Public Interface 

//return a clone
virtual Type _Type::cloneof() const {
    return Type(*this);
}

//return the type of types, TheType
virtual const Type _Type::typeof() const override {
    return TheType;
}

//// Operators

/*
bool _Type::operator==(const _Type& other) const {
    return properties == properties;
}
*/



};
