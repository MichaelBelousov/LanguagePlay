
## Parametric Constructs (Generics/Templates)

### Name

Parameteric Constructs, or "Parametrics" for short

### Generics vs Templates

A generic uses tables, pointers, and implicit type arguments to use the 
same code across all types

A template generates new code for each type argument instance.

### Default Types, and arguments

The default type of a parametric construct argument is `Type`, so
type arguments (non-value arguments) are inferred for untyped template
definitions.

When instantiating a parametric, parameters can be in the declaration 
order or named, so long as it is unambiguous. Parameter declaration 
rules are identical to those of functions except that `Type` type 
parameters are allowed.

### Syntax

Parametrics are indicated by an angle-bracket parameter list
declaration after the identifier of the construct.

_Functions:_

```
func toBytes<T>(b: T): byte[]
    return T: byte[]
class A
    meth m<a: int>(b: float)
        return a * b
```

_Classes/Structs_

```
class ObjectList<T is Class>
    private 
        head: T
    @public meth add(t: T): void
        if head == null
            head = t
        else
            cur = head
            while cur.next != null
                cur = cur.next
            cur.next = t
```

_Aliases_

types attempt to be used like values. They have operators, the metatype, `Type` for
inference, and a lot of advanced crap.

```TypeScript
```

### Nested Parameters

Parametric parameters to parameters are possible

```TypeScript

func map<IterType: Iterable<T: Type>, 
         FuncType: Func<R: Type, T>>
        (f: FuncType, iter: IterType): Stream<R>
    Stream<() => f(iter.next())>  //iter is implicitly captured by reference

a = 2
map([a](x)=>x+a, 
    [5, 10, 2]) // == Stream(5, 10, 2)

```

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

Here, we reimplement the default bool array to be an array of bits

```TypeScript
struct bool[]<_len: int32>:
    has bit[_len]  //could use `is`
```

you can specialize over the length parameter.

```TypeScript
struct bool[]<_len=8>:
    private
        //an idiom for wordy type names, uppercase This type
        This: Type = bool[]<_len=8>
        content: int32
    op get (b: This, idx: uint32): bool
        return (content >> idx) & 0x1
    op set (b: This, idx: uint32, bool val): void
        if val / content |= 1 << idx
        else / content &= ~(1 << idx)
```

and you can add your own parameters

```TypeScript
struct bool[]<_len=8, Store: Type>:
    private
        This: Type = bool[]<_len=8>
        content: Store
    //...

b: bool[34]<int64> = 0xff324021
```

And then use transformations or macros for more fine-grained
high-level designs


#### Syntactic Sugar

```TypeScript

//comparing parametrics
Array<int> == int[]
a: Array<int>
b: int[]
typeof a == typeof b

//comparing example atomic types
Array<int, 6> == int[6]

Array<int, _len=6> == int[6]

The Array is a type alias
Array<T: Type, _len: uint32> = T[_len]

arr1: int[]
op get(t: Type): Type
    return Array<T>

arr2: int[4]
op get(T: Type, n: Int): Type
    return Array<T, n>
```

### Specialization

A completely contrived (and bad) specialization

```TypeScript
struct Array<bit>
    value: bit
    next: ptr<Node<bit>>
```

#### Illegal Specializations

illegal specializations or fail specialization are used to force 
the compiler to fail when a type is used

An example null specialization

```TypeScript
struct Array<bytes>
    fail
```

### Overloading


