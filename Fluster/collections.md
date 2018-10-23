
# Collections

### Lists

```C
mylist: List = []
//List<int32, String>
mylist: List = [1, "heterogeneous"]
```

### Arrays

```C
myarr: Array<int32> = a[]
myarr2: int[] = a[]
```

### Packs

```TypeScript
```

### Sets

use for uniqueness and sub/superset operations

```C
myset: Set = {1,2,3}
```

### Mappings (Maps)

```C
mymap: Map = {}
//type is deduced to be per name
mymap2: Map = {
    "foo": 'bar',
    "foobar": a['a', 'b'],  //a char array (could just do 'ab')
    "hello": world
}
```

### Structures/Objects

raw structure/object literal:
```C
{
    foo='bar',
    foobar='buzz',
    hello=world
}
```

### String

source string literals are unindented during parsing

```C
mystr: String = "hello"

mystr: String = "goodbye
                 my dear friend""
```

'raw' string literals preserve whitespace

```C
mystr: String = `hello`
mystr: String = `goodbye
                 my dear friend`
```

### A note on packs

some types' pack operations return arrays
e.g. bytes

```C
0x0, 0xff, 0xa4, 0xc == a[0x0, 0xff, 0xa4, 0xc] == 0x00ffa40c
```
