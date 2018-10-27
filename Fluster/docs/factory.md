
# Factory

Classes and Structs are both Factories

Class is a reference factory
struct is a value factory
both create data  with functions, methods, fields, scopes accessibility

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
