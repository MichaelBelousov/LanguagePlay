#ifndef FLUSTER_COMPILER_FUNCTION
#define FLUSTER_COMPILER_FUNCTION

#include "value.h"

namespace Fluster {



using Address = std::size_t;

struct Addressable {
    Address address;
    Addressable(Address in_addr)
        : address(in_addr) 
    {}
};

struct Executable {};

//TODO: a feature, need to be able to make constructors automatically
//add parent functions
// i.e. function
//NOTE: are executables always addressable?
class Function : public BaseValue
               , public Executable
               , public Addressable 
{
    //// Construction
public:
    Function (Address in_addr)
        : BaseValue()
        , Executable()
        , Addressable(in_addr)
    {}
    //// Public Fields
public:
    TypePtr result_type;
};



};

#endif //FLUSTER_COMPILER_FUNCTION
