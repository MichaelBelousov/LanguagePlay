
using Address = std::size_t;
struct Addressable {
    Address address;
    Addressable(Address in_addr): address(in_addr);
};
//TODO: a feature, need to be able to make constructors automatically
//add parent functions
// i.e. function
//NOTE: are executables always addressable?
class StackExecutable 
    : public Value
    , public Executable
    , public Addressable 
{
    StackExecutable(Address in_addr)
        : Value()
        , Executable()
        , Addressable(addr)
    {}
};
