#include "type.h"
#include "primitives.h"

namespace fluster {



//// Public Interface 

//return a clone
TypePtr Type::cloneof() const {
    return Type(*this);
}

//return the type of types, TheType
const TypePtr Type::typeof() const override {
    return TheType;
}

//// Operators

bool operator==(const TypePtr& lhs, const TypePtr& rhs) {
    return lhs.kind == rhs.kind
        && lhs.props == rhs.props;
}



}; //namespace fluster
