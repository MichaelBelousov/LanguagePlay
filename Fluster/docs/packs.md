
# Packs & Structs

Packs compile to anonymous Structs with named members.

## Unpacking

Three operations are used by the language when unpacking

```TypeScript

//ordered unpacking (e.g. lists)
op unpack<n: uint32> (pack: Pack)
    ...

//named unpacking (e.g. modules)
op unpack<name: Name> (pack: Pack)
    ...

//full unpack
op unpack (pack: Pack)
    ...
    
```

### Ordered Packs

Ordered unpacking uses the parametric of the
unpacking operation that takes an integer argument,
corresponding logically to the index of the identifier 
to unpack into. For example:

```TypeScript

IndexPack: Type

op unpack<n: uint32> (pack: IndexPack)
    return n

x, y, z = IndexPack()

x == 0
y == 1
z == 2

```

### Named Packs

Named packs, instead of containing a certain sequence, contain
a set of names which can be unpacked into the local scope

An example, is modules. Module objects have named packs by default,
which can be used to extract specific names during imports

for example:

```TypeScript

ceil, floor = import math
...import math.stats

```

Ordered packing takes precendence over named packing, using
both is not a good idea generally since parameteric arguments to
an unpacking operation aren't pretty

An example  named pack can be implemented by the following 
unpack operation

```TypeScript

op unpack<name: Name> (target: Module)
    return pack[name]

```

### Unpacking Parameters

Should you need it, there *is* a syntax for arbitrary parameteric
arguments to unpacking operations.

For example:

```
Multiple: Type

op unpack<_index: uint32, a: int32> (pack: Multiple): int32
    return _index*a

a, b, c = ...<-4>Multiple()
a ==  0
b == -4
c == -8

op unpack<_index: uint32, bytes: byte[]> (pack: String): bool
    return bytes & pack[n]

// get the fifth bit
capitals: bool[] = ...<0b00100000>"HeLLo"


// named parametric unpack
op unpack<_name: Name, suffix: Name> (pack: Module)
    return pack[suffix+_name]

quick, merge, bubble = ...<"_sort">import algorithm


```

<!-- use _left and _right as special names of binary arguments
-->

## Packing

Packs are almost exactly Structs, which are analagous to 
the struct declaration. The only difference is that Packs
have the get `[]` operator implemented by default, to use
for accessing by type and by index. For instance:

```TypeScript
x = 1, "hello", 7.3
typeof x == Pack<int32, String, float32>

x[0] == 1
x[1] == "hello"
x[2] == 7.3
x[3]  //won't compile
x[String] == "hello"
```

raw Structs can be accessed via integer arguments

<!--
maybe allow a sort of function scope that can be merged/transformed
for reordering of local variables?
-->

