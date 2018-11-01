
#ifndef FLUSTER_COMPILER_TYPE_H
#define FLUSTER_COMPILER_TYPE_H

/*
 * this doesn't know what it's doing yet
 * */

//#include <llvm/ir>
#include <memory>
#include <utility>
#include <tuple>
#include <map>
#include "value.h"

namespace Fluster {

struct Type;

//void compile(const AST&);

struct Property
{
    using std::string;
    string name;
    Type& type;
    Property(const string& in_name, const Type& in_type)
        : name(in_name), type(in_type) {}
};

struct Type  //: Public Parametric
{
public:  //types
    using std::vector; using std::map;
    using std::tuple;
    using Ptr = std::shared_ptr<Type>;
    using Properties = vector<Properties>

private: //class variables
    static int next_id = 0;
    static const Type MetaType;

public:  //members
    const int id;
    vector<Type::Ptr> convertible_from;
    Properties props;
    Properties class_props;

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

#endif //FLUSTER_COMPILER_TYPE_H
