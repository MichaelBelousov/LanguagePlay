
#ifndef FLUSTER_COMPILER_TYPE_TABLES
#define FLUSTER_COMPILER_TYPE_TABLES

#include <memory>
#include <map>
#include "utils.h"
#include "type.h"


namespace Fluster {

class Type;



using PropertyTable = Dict<Identifier, Value>;

using FunctionTable = Dict<Identifier, Function>;

// XXX: don't inherit from std::map
class ConversionToTable : private FunctionTable {
    const TypePtr from_type, to_type;
public:
    ConversionTable(const TypePtr in_from_type, const TypePtr in_to_type)
      : from_type(in_from_type)
      , to_type(in_to_type)
    {}
    void defineConversion(const FunctionPtr in_func) {
        if (in_func.result_type != to_type
            // TODO: make equality comparator
            && in_func.params[0] == from_type
            && in_func.params.length == 1)
            throw "bad conversion";
        emplace_back(std::forward<ArgTypes>(args)...)
    }
};




}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE_TABLES
