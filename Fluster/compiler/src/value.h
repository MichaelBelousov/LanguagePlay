
#ifndef FLUSTER_COMPILER_VALUE_H
#define FLUSTER_COMPILER_VALUE_H

/*
 * this doesn't know what it's doing yet
 * */

//#include <llvm/ir>
#include <memory>
#include <utility>
#include <tuple>
#include <map>

namespace Fluster {


struct Value
{
    Type& type;
    Type& typeof() const;
};

template<typename T>
struct Defaulted
{
    template<typename... Args>
    Defaulted(const T& in_default, Args... args)
        : value(new T(in_default)) {}
    const T const* value;
    const get() { return value == null}
};

#endif //FLUSTER_COMPILER_VALUE_H
