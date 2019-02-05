#ifndef FLUSTER_COMPILER_VALUE
#define FLUSTER_COMPILER_VALUE

class Type;

namespace Fluster {



//TODO: rename to AbstractValue?
class /*Base*/Value {
    //// Public Interface
public:
    virtual const Type& typeof() const = 0;
};



final class VariableValue : public /*Base*/Value {
    //// Public Interface
public:
    virtual const Type& typeof() const override;
    //// Private Members
private:
    Type type;
    //alignment
    //LLVM value
};



};

#endif //FLUSTER_COMPILER_VALUE
