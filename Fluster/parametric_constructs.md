
## Parametric Constructs (Generics/Templates)

### Generics vs Templates

A generic uses tables, pointers, and implicit type arguments to use the 
same code across all types

A template generates new code for each type argument instance.


### Syntax

Functions:

```
```

Classes/Structs

```
```

Aliases

### Specialization

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

### Array Types

The length of an array is part of the type of the array.

```
int[5] != int[4]
```

All array types have a length, if the length was omitted during initialization, 
then it must be inferred.

```
t: int[] = [1, 2, 3]
type t == int[3]
```

Array types can be parametrized using the array syntax in the
structure declaration, and specialized using the, `_len` parameter
and the array type declaration syntax.

```TypeScript
struct bool[]<_len: int32>:
    Array<bool>
```

one can specialize lengths as well

```TypeScript
struct bool[]<_len=8>:
    private
        int32: content
    op get (bool[]<_len=8> b, idx: uint32): bool
        return (content >> 24 >> idx) % 1
    op get (bool[]<_len=8> b, idx: uint32, bool val): bool
        return content |= idx << 24
```

and one can transform specializations

```TypeScript
@per_primitive
struct bool[]<_len=8>:
    private
        int32: content
    op get (bool[]<_len=8> b, idx: uint32): bool
        return (content >> 24 >> idx) % 1
    op get (bool[]<_len=8> b, idx: uint32, bool val): bool
        return content |= idx << 24
```

### Specialization

A completely contrived (and bad) specialization

```TypeScript
struct Array<bit>
    value: bit
    next: ptr<Node<bit>>
```

An example null specialization
```TypeScript
struct Array<bytes>
    is Null
```
