
# Advanced Type Stuff

## EmptyUniqueType

```TypeScript
MyType: Type
```

you can use type operators, type aliases, and type

## Type Classes

you can define a type class by cloning the `Type` type

```TypeScript
MyTypeClass = cloneof Type

to declare the type
```
<!-- 
maybe have class/struct both be able to change their metatype?
-->

this is useful for parameterics

## Type Operations and User Operators

```TypeScript
op add (A: MyTypeClass, B: MyTypeClass): MyTypeClass
    class result
        merges A
        merges B
    return result
```

