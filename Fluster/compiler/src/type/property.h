

#ifndef FLUSTER_COMPILER_TYPE_PROPERTY_H
#define FLUSTER_COMPILER_TYPE_PROPERTY_H

#include <tuple>
#include <map>

namespace Fluster {



struct Type;

using Property = std::tuple<std::string, Type::Ptr>
using Properties = std::map<std::string, Type::Ptr>



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE_PROPERTY_H
