
/*
 * this doesn't know what it's doing yet
 * */

//#include <llvm/ir>
#include <memory>
#include <utility>
#include <tuple>
#include <map>

namespace Fluster {


//void compile(const AST&);

struct Type  //: Public Parametric
{
    using std::vector; using std::map;
    using std::tuple;
private: //class variables
    static int next_id = 0;
    static const Type MetaType;

public:  //class types
    using Ptr = std::shared_ptr<Type>;

public:  //members
    const int id;
    vector<Type::Ptr> convertible_from;

public: //construction
    Type()  //T: Type
        : id(next_id++)
        , convertible_from() {}
    Type(const Type& other) = default;
    Type& operator=(const Type& rhs) = default;
    Type(Type&& other)
        : id(other.id)
        , convertible_from(std::move(other.convertible_from)) {}
    Type& operator=(Type&& rhs) {
        this->convertible_from = std::move(rhs.convertible_from);
        return *this;
    }

public:  //Operators
    friend bool operator==(const Type& lhs, const Type& rhs);
    friend bool operator!=(const Type& lhs, const Type& rhs);
    friend Type operator&(const Type& lhs, const Type& rhs);
    friend Type operator|(const Type& lhs, const Type& rhs);
    friend Type operator~(const Type& rhs);
    static Type is(const Type& lhs, const Type& rhs);
    static Type is(const Type& rhs);
    static Type has(const Type& lhs, const Type& rhs);

private:
    //TODO: move type map to separate object for oop sanity
    using FromType = Type;
    using ToType = Type;
    using ConversionPair = tuple<FromType, ToType>;
    using Conversion = const Value&(*)(const Value&);
    //TODO: rename Conversion pair to imply assymetry
    static map<ConversionPair, Conversion> setupPrimitiveTypes();
    const static map<ConversionPair, Conversion> conversion_graph;

public:  //Methods
    Type cloneof();
    void defineConversion(Type& u, Type& v, Conversion convert_func) {
        conversion_graph.add(tuple(u, v), convert_func);
    }
    convert(const Value& value, const Type& to) {
    }
};

Type::MetaType = Type();

namespace builtin
{
    namespace types {
        Type int32;
    };
};
