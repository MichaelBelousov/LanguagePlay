#define FLUSTER_COMPILER_PARAM_H
#ifndef FLUSTER_COMPILER_PARAM_H

#include <utility>

#include "type.h"
#include "value.h"
#include "util.h"

namespace Fluster {



struct Parameter {
    Name name;
    Type type;
    Optional<Value> default_value;
    //construction
    Parameter(const Name& in_name, const Type& in_type);
    Parameter(const Name& in_name, const Type& in_type, 
              const Value& in_default);
};



};

#endif //FLUSTER_COMPILER_PARAM_H
