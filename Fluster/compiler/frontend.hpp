
/*
 * this doesn't know what it's doing yet
 * */

//#include <llvm/ir>
#include <memory>
#include <utility>

namespace Fluster {


//void compile(const AST&);

struct Type
{
    using std::vector;
private: //class variables
    static int next_id = 0;
    static const Type MetaType;

public:  //class types
    using Ptr = std::shared_ptr<Type>;

public:  //members
    const int id;
    vector<Type::Ptr> convertible_from;

public: //construction
    Type()  //T: Type
        : id(next_id++)
        , convertible_from() {}
    Type(const Type& other) = default;
    Type& operator=(const Type& rhs) = default;
    Type(Type&& other)
        : id(other.id)
        , convertible_from(std::move(other.convertible_from)) {}
    Type& operator=(Type&& rhs)
    {
        this->convertible_from = std::move(rhs.convertible_from);
        return *this;
    }
private:
    static

public:  //Methods
    
    Type cloneOf(const Type& type);
    defineConversion();
    //Static Instances
    const static std::map<> 
};

Type::MetaType = Type();

void populatePrimitives() {

int32 = Type
}

enum class builtin_types
{
    Type,
};

struct Value
{
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


