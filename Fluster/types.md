
# Types

stuff about types

## Naming

by convention, types use capitalized names

## Utilities

the `typeof` language feature.

the `Type` type.

the `sizeof` language feature


### Type Aliases

The same type, different name

types attempt to be used like values. They have operators, a `Type` type 
for instructing the compiler/analyzer, and aliases use the assignment 
operator

```TypeScript
MyNewType = SomeOtherType
//you can optionally indicate it being a Type
//but it will be deduced
MyType1: Type = AnotherType  
MyType2 = ParametrizedType<AnotherType>.InnerType
a: float32 = 5.6
MyType3 = typeof a
MyType4  //I'm forgetting one other good example...
```

### Type Clones

Different type, different name, same implementation

```TypeScript
struct AnotherType
    meth f(this: This)
        return 5

MyType5 = cloneof AnotherType
MyType5 != AnotherType

MyType5().f() == 5
AnotherType().f() == 5
```

## Type Operations

### Type Union

```TypeScript
T = U | V
```

T's possible instance set is the union of the instance
sets of the operands.
Thus, anything that could be a U or could be a V

The confusing part, is that the resulting type's fields
are the _intersection_ of the fields in the operands

### Type Intersection

```TypeScript
T = U & V
```

The opposite of a type union. To be classified as type U & V,
a type must have all fields declared in both U & V.

The result is the equivalent to the merging V over U

I'm not sure these will actually be useful

<!-- but what about field order... 
how is that preserved? -->

### Type Difference

```TypeScript
T = U - V
```

Fields of U without the fields of V

### OOP types

```TypeScript
T is U
```

## Conversion

### Type Domains?

## Parametric Constructs (Generics/Templates)

type arguments

```TypeScript
struct Node<T: Type>
    value: T
    next: ptr<Node<T>>
```

value arguments

```TypeScript
func hello<prefix: String>()
    return prefix + 'hello'
```

### Specialization

A completely contrived (and bad) specialization

```TypeScript
struct Node<bit>
    value: bit
    next: ptr<Node<bit>>
```

An example null specialization
```TypeScript
struct Node<Null>
    assert false
```

## The `Type` Type

for type-taking declarations and constructs, the type, `Type`, is used to 
indicate a non-value argument
