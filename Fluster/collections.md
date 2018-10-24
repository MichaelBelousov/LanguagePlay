
# Collections

### Lists

```TypeScript
mylist: List = []
//List<int32, String>
mylist: List = [1, "heterogeneous"]
```

### Arrays

```TypeScript
myarr: Array<int32> = a[]
myarr2: int[] = a[]
```

### Packs

A Tuple clone

```TypeScript
```

### Sets

use for uniqueness and sub/superset operations

```TypeScript
myset: Set = {1,2,3}
```

### Mappings (Maps)

```TypeScript
mymap: Map = {}
//type is deduced to be per name
mymap2: Map = {
    "foo" = 'bar',
    "foobar" = a['a', 'b'],  //a char array (could just do 'ab')
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
0x0, 0xff, 0xa4, 0xc == a[0x0, 0xff, 0xa4, 0xc] == 0x00ffa40c
```
