#ifndef FLUSTER_COMPILER_VALUE
#define FLUSTER_COMPILER_VALUE

class Type;

namespace Fluster {



class BaseValue {
    //// Public Interface
public:
    virtual const TypePtr typeof() const noexcept = 0;
};



final class RuntimeValue : public BaseValue {
    //// Public Interface
public:
    const TypePtr typeof() const override;
    //// Private Members
private:
    TypePtr type;
    //alignment
    //LLVM value
};



};

#endif //FLUSTER_COMPILER_VALUE
