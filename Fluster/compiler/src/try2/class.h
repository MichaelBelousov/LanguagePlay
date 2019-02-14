
#ifndef FLUSTER_COMPILER_CLASS
#define FLUSTER_COMPILER_CLASS

#include "type.h"

namespace Fluster {



class Constructible {
    virtual void defaultConstruct() = 0;
};

class Class : public Constructible, public CompositeType {
    void construct() override;
};

class Struct : public Constructible, public CompositeType {
    void construct() override;
};


};

#endif //FLUSTER_COMPILER_CLASS
