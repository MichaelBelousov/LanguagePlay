
# Fluster

A multi-level language for general programming

## Introduction

Fluster code constructs can be made parametric
uniformly and effortlessly

```TypeScript

struct PriorityQueue<ContainerType: Container<T: Type>, 
                     weight: Func<R: ComparableType, T>>
    private
        container: ContainerType
    @public meth add(t: T): void
        i = container.length
        for x: T in container.backwards()
            if weight(t) > weight(x)
                continue
            else
                container.insert(t)
                return
            i--

List2D<T: Type> = List<List<T>>
mylist: List2D<char>
mylist = [['h', 'y'], ['n', 'n'], []]

```

Fluster code is strongly typed and heavily inferred.
Value idioms and constructs are used on types wherever appropriate
including operators.

```TypeScript

val: int = 4          //typed declaration
MyFloat: Type = float64 //type alias
decimal = val: float64  //casting is the same syntax

```

Fluster code is expressive and readable with core data structure
literals, idiomatic byte literals, and more.

```TypeScript

vals: int[] = 1, 5, 10, -4
val: byte[7] = 0x00fa43fc
val: byte[1] = 0b11010100
string_array = a["foo", "bar"]
string_list = ["foo", "bar"]
string_map: Map<String, int32>  = {"foo" = 40}

struct Person
    name: char[10]
    age: uint8

mike = 0x6d696b6500000000000014: Person

```

Fluster code has granular declarative composition

```TypeScript

class A
    is B            // inheritance
    has C           // delegation
    has D as d      // delegation with accessible obj, d
    has E.g as g    // single function delegation
    has F.h as f.h  // single function delegation with accessible obj

```

Fluster code supports every level of abstraction, with strong
code generation and static reflection, or runtime reflection
only when you need it.

```TypeScript

enum Flags
    for i, name in enumerate("read", "write", "append")
        name = 2^^i

tran require_auth(f: Func, err: String)
    func _(...args: Args)
        if authorize() \ return f(...args)
        else \ throw 401, err
    f <- _

@require_auth("bad auth")
func find_user(id: String)
    ...

```

