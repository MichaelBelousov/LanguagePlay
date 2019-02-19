
# Classes and Structs

## Classes

A class is a reference type
and can multiply inherit.
All instances of class descendents
of some class or interface, are 
considered values of that type.

## Structs

Structs can inherit from
classes, other structs, and 
extend interfaces, 
but there is no parent-child
relationship, abstraction, or
dynamic typing. A struct S inheriting from a class C cannot be passed as
an argument to any function taking a value of type C as an argument.

```TypeScript
interface Serializable
    meth serialize(this: This)

struct A
    is Serializable
```

## The `Class` Interface

```TypeScript
interface Class
    parent: Class | null
```
