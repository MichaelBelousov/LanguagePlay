
#include "type.h"

namespace Fluster {


//void compile(const AST&);

bool operator==(const Type& lhs, const Type& rhs)
{ return lhs.id == rhs.id; }
bool operator!=(const Type& lhs, const Type& rhs);
{ return !(lhs == rhs); }

Type operator&(const Type& lhs, const Type& rhs);

Type operator|(const Type& lhs, const Type& rhs);

Type operator~(const Type& rhs);


Type Type::is(const Type& lhs, const Type& rhs);
Type Type::is(const Type& rhs);
Type Type::has(const Type& lhs, const Type& rhs);

Type cloneof();
void Type::defineConversion(Type& u, Type& v, Conversion convert_func) {
    conversion_graph.add(tuple(u, v), convert_func);
}
//TODO: this is runtime, that shouldn't be done!

Type::MetaType = Type();

struct Array 
{
    Type& type;
    int size;
};

namespace builtin
{
    namespace types {
        Type int_;
        Type int8;
        Type uint8;
        Type int16;
        Type uint16;
        Type int32;
        Type uint32;
        Type int64;
        Type uint64;

        Type float_;
        Type float32;
        Type float64;

        Type bool_;
        Type byte_;
        Type bit_;
    };
};

