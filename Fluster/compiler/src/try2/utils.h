#ifndef FLUSTER_COMPILER_UTILS
#define FLUSTER_COMPILER_UTILS

#include <map>
#include <unordered_map>
#include <string>

namespace Fluster {



template<typename ...Args>
using Dict = std::unordered_map<...Args>;

using Identifier = std::string;



};

#endif //FLUSTER_COMPILER_UTILS
