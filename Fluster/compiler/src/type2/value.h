#ifndef FLUSTER_COMPILER_VALUE
#define FLUSTER_COMPILER_VALUE

#include <map>
#include <memory>
#include <string>
class Type;

namespace Fluster {



class Value {
    //// Public Interface
public:
    virtual const Type& typeof() const = 0;
};

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




};

#endif //FLUSTER_COMPILER_VALUE
