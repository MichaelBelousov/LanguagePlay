
# Factory

Classes and Structs are both Factories

Class is a reference factory
struct is a value factory
both create data  with functions, methods, fields, scopes accessibility

```TypeScript

//e.g. namespace
namespace blah
    x: int32 = 4
    func hello() / print("hello")

malloc, copy = import memory

metatype type
    pass

namespace blah
    op call<call

//maybe make types have a domain iterator operation?
//to iterate through bits 0b0, 0b1, 0b10, 0b100, etc
//0, 1, 2, 3, 4 for unsigned int
enum blah2: flags
    write
    read

//named namespaces are types and values
class = cloneof Type
op namespace <decl=$struct, Target: Namespace>
    op call<class: Target> (class: Target, ...args: Args)
        //try this...?
        class._op.namespace.without_static()
        class._op.call(...args)

op namespace <decl=$class, Target: Namespace>
    op call (class: Target, ...args: Args)
        mem = malloc(sizeof Target)
        copy(Target, mem)

//a class is a namespace with a call operator that copies the namespace
//to a malloc'd area and sets up inheritance

```

## Structs

a namespace with the call operator implemented to generate an 
instance on the stack.

## Classes

a class is a struct with dynamic dispatch (vtable) and inheritance


## Low-level abstraction

the vtable, inheritance, polymorphism, dynamic dispatch,
factories, classes, metaclasses, etc should ideally all be implemented in
Fluster instead of language features

## malloc

have malloc standard lib function for allocating memory

```

//declare a construct
op construct<name: Name = "scope">

enum access
    public
    protected
    private

//specializations vs defaults?
//probably just require explicit typing
//Name<T>

//specialize the scope operator for the name, class
op scope<scope_name=n"class", name: Name>
    @outer cls_name: Type
    op call (lhs: $cls_name
        object

//need to formalize metatypes...
//could be used to define enums, classes, etc
op scope<decl='class', Target: Struct>
    op call (lhs: is Target)
        ptr<x> = malloc(lhs)
    struct _
        vtable: Func[]
        merges Target
    target <- ref<_>

//probably start with struct and create a class from it is better

class hello
    x: int32

scope class
    op scope (this: This)
        
    op call (lhs: This, ...args): T
        lhs._members
    
```
