#ifndef FLUSTER_COMPILER_TYPE_PARAMETRIC_H
#define FLUSTER_COMPILER_TYPE_PARAMETRIC_H

#include <tuple>
#include <map>
#include "type.h"


namespace Fluster {


// Program Element
class Elem
{
};

// Program Element
class Arg
{
    ~Arg() = 0;
};

class TypeArg
{
    Type payload;
};

class ValueArg
{
    Value payload;
};



class Parameteric
{
    /// Members
    Parameters

    /// Construction
    Parametric();
};



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE_PARAMETRIC_H
