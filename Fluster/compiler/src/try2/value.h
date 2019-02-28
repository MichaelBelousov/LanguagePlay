#ifndef FLUSTER_COMPILER_VALUE
#define FLUSTER_COMPILER_VALUE

namespace Fluster {

struct Type;
using TypePtr = std::shared_ptr<Type>;



class BaseValue {
    //// Public Interface
public:
    virtual const TypePtr typeof() const noexcept = 0;
};



// XXX: final???
class RuntimeValue : public BaseValue {
    //// Public Interface
public:
    const TypePtr typeof() const noexcept final;
    //// Private Members
private:
    TypePtr type;
    //alignment
    //LLVM value
};



};

#endif //FLUSTER_COMPILER_VALUE
