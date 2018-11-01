
#ifndef FLUSTER_COMPILER_TYPE_H
#define FLUSTER_COMPILER_TYPE_H

/*
 * this doesn't know what it's doing yet
 * */

#include <memory>
#include <utility>
#include <tuple>
#include <map>
#include "value.h"
#include <algorithm>

namespace Fluster {



struct Type;

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
    using std::vector; using std::map;
    using std::tuple; using std::set;
public:  //types
    using Properties = set<Properties>;
    using Ptr = std::shared_ptr<Type>;
    using WeakPtr = std::weak_ptr<Type>;

private: //class variables
    static int next_id = 0;
    static const Type MetaType;

public:  //members
    //TODO: switch to property hash + a "factor" for clones
    const int factor;
    const int id;
    vector<Type::Ptr> convertible_from;
    vector<Type::WeakPtr> convertible_to;
    const Properties inst_props;
    const Properties type_props;

public: //construction
    static getNextAvailableId() {return next_id++;};
    Type()  //T: Type
        : id(getNextAvailableId(), 
        , convertible_from() 
        , convertible_to() 
        , inst_props() 
        , type_props() {}
    Type(Type&& other)
        : id(other.id)
        , convertible_from(std::move(other.convertible_from))
        , convertible_to(std::move(other.convertible_to))
        , inst_props(std::move(other.inst_props)) 
        , type_props(std::move(other.type_props)) {}
    Type(const Type& other) = default;
    Type& operator=(const Type& rhs) = default;
    Type& operator=(Type&& rhs) {
        this->convertible_from  = std::move(rhs.convertible_from);
        this->convertible_to    = std::move(rhs.convertible_to);
        this->inst_props        = std::move(rhs.inst_props);
        this->type_props        = std::move(rhs.type_props);
        return *this;
    }
private:
    //TODO: move to util
    template<typename Set>
    static Set intersection(Set a, Set b) {
        Set result;
        std::set_intersection(a.begin(), a.end(), 
                              b.begin(), b.end(),
                              std::back_inserter(result));
        return result;
    }
    template<typename Conversions, typename Props>
    Type(Conversions in_convertible_from, Conversions in_convertible_to
         Props&& in_inst_props, Props&& in_type_props)
        : id(getNextAvailableId())
        , convertible_from(std::forward(in_convertible_from))
        , convertible_to(std::forward(in_convertible_to))
        , inst_props(std::forward(in_inst_props)) 
        , type_props(std::forward(in_type_props)) {}

public:  //Operators
    friend bool operator==(const Type& lhs, const Type& rhs);
    friend bool operator!=(const Type& lhs, const Type& rhs);
    friend Type operator&(const Type& lhs, const Type& rhs);
    friend Type operator|(const Type& lhs, const Type& rhs);
    friend Type operator~(const Type& rhs);
    static Type is(const Type& lhs, const Type& rhs);
    static Type is(const Type& rhs);
    static Type has(const Type& lhs, const Type& rhs);

public:  //Methods
    Type cloneof();
    void defineConversion(Type& u, Type& v);

    ConversionPath 
    getConversionPath(const Value& value, 
                      const Type& to);
};

struct Array 
{
    Type& type;
    int size;
};

namespace builtin
{
    namespace types {
        extern const Type int_;
        extern const Type int8;
        extern const Type uint8;
        extern const Type int16;
        extern const Type uint16;
        extern const Type int32;
        extern const Type uint32;
        extern const Type int64;
        extern const Type uint64;

        extern const Type float_;
        extern const Type float32;
        extern const Type float64;

        extern const Type bool_;
        extern const Type byte_;
        extern const Type bit_;
    };
};



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE_H
