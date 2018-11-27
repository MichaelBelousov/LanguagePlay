

#ifndef FLUSTER_COMPILER_TYPE_RESOLUTION_H
#define FLUSTER_COMPILER_TYPE_RESOLUTION_H

/*
 * this doesn't know what it's doing yet
 * */

/// forward decl
class Resolution;

/// includes
#include <utility>
#include <algorithm>
#include <tuple>
#include "type.h"
#include "value.h"
#include "property.h"

/*
 * What I lack while writing here, is a formal introduction or
 * even following of mathematical type theory, which would
 * indubitably be helpful
 */

namespace Fluster {


using Args = vector<Value>;

struct Resolve 
{
    using std::tuple;
    static HLCode overloadedProcedure(Callable f, Args args)
    {
    }
    //FIXME: doesn't belong here
    //TODO: make a more generic overload resolver for arguables
    //FIXME: this is actually first level code generation for an
    //overloaded callable, not the resolutioin
    static HLCode generateProcedure(Procedure p, Args args)
    {
        //XXX:
        //not actually resolving possible types of the Callable f...
        /* 
        for ambiguous code, 
        - require direct casts? 
        - choose the largest possible overload (e.g. int64 if int32)
            - would require type ordering
            - is this really a good enough feature?
        */
        // in general, fluster code should use explicit conversions
        // for lossy conversions, and implicit for perfect conversions
        // but integrals numbers are (by convention of C) an exception
        //XXX:
        //HLCODE is currently a schedule of transactions,
        //e.g. assignments, function calls, etc, all with an
        //output (possibly void) and several inputs defined
        //as previous outputs
        HLCode result;
        for (auto& [arg,prm] : tuple(args, Callable.parameters))
        {
            if (arg.type != prm.type) 
            {
                try 
                    result.emplace_back(
                            ArgConversion(searchDirectConversion(type)),
                            arg, prm);
                catch (CantConvertDirectly)
                    throw UnresolvableArguments("Can't convert directly");
            }
        }

        // in theory, go through an iterator of conversions 
        // (which we have in result) and setup the necessary
        // transaction input/output links,
        // leaving remaining slots for the non-converted variables
        result.append(LinkConversions(f, result));

        for (const auto& c : Result)
        {
            ResultAsArg
        }
    }
private:
    static DirectConversion findDirectConversion(Type type)
    {
        //oooh, maybe call python-style try-except `problems'?
        //problems and panics? for control flow?
        if (BAD)
            throw CantConvertDirectly();
    }
};



}; //namespace Fluster

#endif //FLUSTER_COMPILER_TYPE_RESOLUTION_H
