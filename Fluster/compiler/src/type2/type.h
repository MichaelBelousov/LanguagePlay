#ifndef FLUSTER_COMPILER_TYPE
#define FLUSTER_COMPILER_TYPE

#include <memory>
#include <map>
#include "value.h"
#include "utils.h"
#include "identifier.h"

class Type;

namespace Fluster {



class _Type : public Value {

//// Public Interface
public:
    virtual Type cloneof() const;
    virtual const Type typeof() const override;
 
//// Construction
public:
    
//// Private Fields
private:
    Dict<Identifier, Value> properties;

//// Operators
    //bool operator==(const _Type& other) const;

};

using Type = std::shared_ptr<_Type>;



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE
