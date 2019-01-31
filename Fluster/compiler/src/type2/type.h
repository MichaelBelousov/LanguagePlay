#ifndef FLUSTER_COMPILER_TYPE
#define FLUSTER_COMPILER_TYPE

#include "value.h"
#include "utils.h"

namespace Fluster {



class Type : public Value {
    //// Public Interface
public:
    virtual Type cloneof() const = 0;
    virtual const Type& typeof() const override {
        return TheType;
    }
    //// Private Fields
private:
    Dict<Identifier, Value> properties;
    //// Operators
public:
    virtual bool operator==(const Type& other) const {
        return other.properties = this->properties;
    }
};



};

#endif //FLUSTER_COMPILER_TYPE
