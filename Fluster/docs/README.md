
# Fluster

A general programming language with an emphasis on minimality
(not in features) and abstraction.

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
val: byte[4] = 0x00fa43fc
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
for easy code reuse

```TypeScript

class A
    is B            // inheritance
    has C           // delegation
    has D as d      // delegation with accessible 
                    // object, d
    has E.g as g    // single function delegation
    has F.h as f.h  // single function delegation 
                    // with accessible object f

```

Fluster code supports every level of abstraction, with strong
code generation and static reflection, or runtime reflection
only when you need it.

```TypeScript

tran flag_enum<target: Enum>
    for i, m in enumerate(target._members)
        m._value = 2^^i

@flag_enum
enum FileOpenFlags
    read
    write
    append

Flags.append == 0b00000100
Flags.read | Flags.write == 0b00000011


Str = String
tran require_user_pass<target: Func, 
                       log_msg: Str = "access fail by {{usr}}">
    func _(usr: Str, psw: Password, ...args: Args)
        if authorize(usr, psw) 
            return target(...args)
        else 
            log.warn(fmt(log_msg, usr, ...args))
            throw 403
    target <- _

@require_user_pass<"bad auth by {{usr}} when searching {{id}}">
func search_user(id: String)
    ...

```

Fluster can even let you modify modules to add appropriate 
functions, transform others, or even ignore other people's 
demented casing choices.

```TypeScript

snake_caser, = import casing

aclass, b_class, cClass = import gross.bile

tran bile2_name_fix<target: Module>
    module _
        AClass = aclass
        aclass <-
    target <- module

@snake_caser 
@bile2_name_fix
import gross.bile2

```

<!-- create Named packs in pack.md -->

