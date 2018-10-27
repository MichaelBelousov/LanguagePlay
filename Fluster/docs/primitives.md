
# Primitive Types

### Integers

```TypeScript
int  //alias for int32
int8
uint8
int16
uint16
int32
uint32
int64
uint64
Integer  //unbounded nonprimitive length integer
```

### Floating-Point Numbers

```TypeScript
float  //alias for float32
float32
float64
Rational  //unbounded nonprimitive length rational (fp) number
infinity: float
```

numeric literals always compile to the smallest possible unsigned holder
that is at least as large as int32

### Bytes

The `byte` is a type and it can be initialized from character 
literals, integer literals, or hexadecimal, octal and binary literals. 

Non-decimal number literals
are not the same type as decimal literals at all, more on that below.

```TypeScript
b1: byte = 1
b2: byte = 'c'
b3: byte, = 0x81
b4: byte, = 0b10000001
bar1: byte[] = 1, 2, 3
bar2: byte[] = 'hello'
bar3: byte[] = 0x12af
bar4: byte[3] = 0x12af
```

##### Byte Literals

Hexadecimal, octal, and binary literals are not interpretted as integers.
The type of any of those literals is a byte array with inferred-minimum
length of the literal content.

```TypeScript
bar5: byte[] = 0x00ff
```

A byte pack is equivalent to a byte array

```TypeScript
0x0, 0x5, 0xaaff == 0x0005aaff
```

`byte` arrays are like regular arrays in that they can be initialized 
from any iterable of bytes (or convertible thereof).
Often however, you want the left to be padded when initializing a
non-inferred-length array from a byte literal, instead of the right which
is the default behavior of any collection initialization from a literal.
For this, use the `bytes[]` type, which does exactly that

<!-- maybe just have it be bytes? -->

```TypeScript
bar3: byte[] = 0x12af  // == [0x12, 0xaf]
bar4: byte[3] = 0x12af // == [0x12, 0xaf, 0x00]
bar5: bytes[4] = 0x12af // == [0x00, 0x00, 0x12, 0xaf]
other: int[5] = 12,   // == [12, 0, 0, 0, 0]
```

It is considerable to alter the default behavior of array initialization
as a specialization for `byte` arrays, however adding the `bytes[]` 
type is a cheap sacrifice for consistency of array initialization
Note that the `bytes` type doesn't have a legal non-array form


#### Conversions

`byte`'s and `byte` arrays can be cast to any data type that can fit
the size of the array. 

```TypeScript
i1 = 0x00020005: int32
i2: int64 = 0xffffffff
i3: int8 = 0b11011011  //signed negative two's complement integer

func factorial(n: int): int
    return n ? n * factorial(--n) : 1

n = factorial(0x14: int32)  //cast byte array to int32

struct Vec2D
    x: float32
    y: float32
    meth magnitude(this): float32
        return (x*x + y*y)^^0.5

v = 0xffffffffaaaaaaaa: Vec2D
```

As you can see in the last example. `byte` arrays can be simply
converted to whole structs.

### `Bit`s

like bitflags in C

```TypeScript
flags1: bit[5]
flags2: bit[3]
flags3 = 0b11 //bit array literal
```

need magic to combine and save space


### `bool`s

`bool`s are a primitive boolean type

true and false literals could be entirely non-magical global values

```TypeScript
true  = 1: bool
false = 0: bool
```
