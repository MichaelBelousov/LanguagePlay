
#ifndef FLUSTER_COMPILER_TYPE_TABLES
#define FLUSTER_COMPILER_TYPE_TABLES

#include <memory>
#include <map>
#include "utils.h"
#include "type.h"
#include "function.h"


namespace fluster {

class Type;
using TypePtr = std::shared_ptr<Type>;



using Identifier = std::string;

using PropertyTable = Dict<Identifier, BaseValue>;

using FunctionTable = Dict<Identifier, Function>;

// XXX: don't inherit from std::map
class ConversionToTable : private FunctionTable {

    //// Private Members
    const TypePtr from_type, to_type;
public:

    ConversionToTable(const TypePtr in_from_type, 
                      const TypePtr in_to_type)
      : from_type(in_from_type)
      , to_type(in_to_type)
    {}

    template<typename TFunction>
    void defineConversion(const TFunction in_func) {
        if (in_func.result_type != to_type
            // TODO: make equality comparator
            && in_func.params[0] == from_type
            && in_func.params.length == 1)
            throw "bad conversion";
        emplace_back(std::forward<TFunction>(in_func));
    }
};




}; //namespace fluster

#endif //FLUSTER_COMPILER_TYPE_TABLES
