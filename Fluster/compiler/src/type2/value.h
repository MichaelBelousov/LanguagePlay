#ifndef FLUSTER_COMPILER_VALUE
#define FLUSTER_COMPILER_VALUE

class Type;

namespace Fluster {



class Value {
    //// Public Interface
public:
    virtual const Type& typeof() const = 0;
};

//TODO: std::enable_if<std::is_primitive<CppAnalogType>>::value>
template<typename CppAnalogType>
final class PrimitiveValue : public Value {
    CppAnalogType payload;
    virtual const Type& typeof() const override;
};




};

#endif //FLUSTER_COMPILER_VALUE
