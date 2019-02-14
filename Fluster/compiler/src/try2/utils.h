#ifndef FLUSTER_COMPILER_UTILS
#define FLUSTER_COMPILER_UTILS

#include <map>
#include <string>

namespace Fluster {



template<typename ...Args>
using Dict = unordered_map<...Args>;

using Identifier = std::string;



};

#endif //FLUSTER_COMPILER_UTILS
