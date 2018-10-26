
# Collections

### Lists

```TypeScript
mylist: List = (,)
//List<int32, String>
mylist: List = 1, "heterogeneous"
```

### Arrays

```TypeScript
myarr: Array<int32> = []
myarr2: int[] = []
```

### Structs

Unnamed arguments are given a name of `_i` where `i` is replaced with
its index as an argument.

```TypeScript

x = Struct("foo", 'fizz', bar=5, baz=5: float)

x._1 == "foo"
x.bar == 5
x._2 = 'fizz'
x.baz == 5.0

typeof x == Struct<String, char[4],  _bar=int, _baz=float>

```

### Packs

A Struct clone with the get `[]` operator implemented

```TypeScript

typeof (2, 2) = Pack<int, int>

Pack = cloneof Struct

//index access
op get<n: uint32>(pack: Pack, n: uint32)
    return pack._get_by_index<n>()

//type access
op get<T: Type>(pack: Pack, T: Type)
    return pack._get_by_type<T>()

```

### Sets

use for uniqueness sub/superset operations, and crossing

```TypeScript
myset: Set = {1,2,3}
```

```TypeScript
a | b  // union
a + b  // union
a & b  // intersection
a - b  // difference
a > b  // proper superset
a >= b // superset
a <= b // subset
a < b  // proper subset
a * b  // cartesian product
a / b  // cartesian quotient (remove all tuples with blah)
       // {(1,8), (1,9), (2,8), (2,9)} / (8,9) = {1, 2}
a ^^ n // cartesian power
a ^/ n // catesian root
       // {(0,0), (0,1), (1,0), (1,1)} ^/ 2 == {0, 1}
```

### Tuples

```TypeScript

Tuple: Type = cloneof Pack

Tuple(1, 2, 3)

```

### Mappings (Maps)

```TypeScript
mymap: Map = {}
//type is deduced to be per name
mymap2: Map = {
    "foo" = 'bar',
    "foobar" = ['a', 'b'],  //a char array (could just do 'ab')
    "hello" = world
}
```

### Structures/Objects

raw structure literal:
```TypeScript
{
    foo: Baz = bar,
    foobar='buzz',
    hello=[world, fizz]
}
```

### String

source string literals are unindented during parsing

```TypeScript
mystr: String = "hello"

mystr: String = "goodbye
                 my dear friend""
```

'raw' string literals preserve whitespace

```TypeScript
mystr: String = `hello`
mystr: String = `goodbye
                 my dear friend`
```

### Streams

a functional stream, takes a single argument used 
to produce the next element. It can be used to make
cool iterables:

```TypeScript
ones = Stream<()=>1>()
naturals = Stream<[i=0]()=>i++>()  //captures i as 0, and 
                                   //returns + increments it
                                   //each invocation
```

### A note on packs

Thanks to conversion, packs are often equivalent to arrays
and with bytes that includes byte literals

```TypeScript
0x0, 0xff, 0xa4, 0xc == [0x0, 0xff, 0xa4, 0xc] == 0x00ffa40c
```
