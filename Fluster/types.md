
# Types

stuff about types

## Utilities


### Type Aliases

The same type, different name

### Type Clones

Different type, different name, same implementation

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
