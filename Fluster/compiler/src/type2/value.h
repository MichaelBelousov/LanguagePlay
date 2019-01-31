#ifndef FLUSTER_COMPILER_TYPE_VALUE
#define FLUSTER_COMPILER_TYPE_VALUE

#include <map>
#include <memory>
#include <string>

namespace Fluster {



class Type;
class Value;

using TypePtr = std::shared_ptr<Type>;
using ValuePtr = std::shared_ptr<Value>;

class Value {
    //// Public Interface
public:
    virtual const Type& typeof() const = 0;
};

template<typename ...Args>
using Dict = unordered_map<...Args>;

class Identifier {
    using std::string;
    //// Construction
    const string text;
public:
    Identifier(const string& in)
      : text(in)
    {
        if (regex_pattern(R"([a-zA-Z_][a-zA-Z0-9_]*)").matches(text))
    }
};


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


//types
extern static const Type TheType;
extern static const Type int_;
extern static const Type int8;
extern static const Type int16;
extern static const Type int32;
extern static const Type int64;
extern static const Type uint;
extern static const Type uint8;
extern static const Type uint16;
extern static const Type uint32;
extern static const Type uint64;



};

#endif //FLUSTER_COMPILER_TYPE_VALUE
