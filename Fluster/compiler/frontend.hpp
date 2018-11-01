
/*
 * this doesn't know what it's doing yet
 * */

//#include <llvm/ir>
#include <memory>
#include <utility>
#include <tuple>
#include <map>

namespace Fluster {

//void compile(const AST&);

struct Parameter
{
    Type type;
    Defaulted<Value> default_argument;
};

using ParameterSpec = std::vector<Parameter>;

class Parametric
{
    default 
    virtual compile(std::vector<ParametricArgs> paramtArgs);
    final compile();
};

class Construct : public Parametric
{
    using Ptr = Parametric*
    virtual void compile();
};

class Function : public Construct
{
};


}; //namespace Fluster

int main()
{
    yyparse();
    return 0;
}


