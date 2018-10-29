
# Factory

Classes and Structs are both Factories

Class is a reference factory
struct is a value factory
both create data  with functions, methods, fields, scopes accessibility

I've decided to not add metaclasses/scope creation yet for simplicity


## Structs

a namespace with the call operator implemented to generate an 
instance on the stack.

## Classes

a class is a struct with dynamic dispatch (vtable) and inheritance


## Low-level abstraction

the vtable, inheritance, polymorphism, dynamic dispatch,
factories, classes, metaclasses, etc should ideally all be implemented in
Fluster instead of language features by using operator overloading


## Custom namespaces

Should be ideally syntactic sugar for a transformer applied to a namespace

```TypeScript

malloc, copy, free = import

tran struct<Target: Type>
    namespace _
        merges Target
        op call (...args: Args): Target
            // get the non-static members of the namespace
            // return by value (copy)
            inst = _._members: Target
            inst._op.call(...args) //should I make this an explicit argument?
            return inst
    Target <- _

tran class<Target: Type>
    namespace _
        merges Target
        static
            vt = VTable<Type>
        op call (...args: Args): Target
            // get the non-static members of the namespace
            // return by value (copy)
            inst = malloc(sizeof _._members members): ptr<Target>
            copy(_._members, inst)
            inst._op.call(...args)
        op leave ()
            free(this)
        for i, m in this._methods
            m = (...args) => vt[i](...args)  //do a real vtable building

    Target <- _

@struct
namespace Vec2D
    x: float32 = 0
    y: float32 = 0
    meth size(Vec2D v): float32 
        return ^/(x^^2 + y^^2)


op meta<$class, target> 
    return @class target
    
class Worker
    meth work()
        ...
    //meth is just syntactic sugar for a function taking a this argument

```

## malloc

have malloc standard lib function for allocating memory

```

//declare a construct
op construct<name: Name = "scope">

enum access
    public
    protected
    private

```
