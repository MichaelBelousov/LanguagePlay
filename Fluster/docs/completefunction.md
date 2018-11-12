
# Completeness as Functions

Fluster constructs should practically be expressible as functions, but
where do static constraints fit into that and class specific declarations?

Unfortunately, I don't think I'll be making a struct+function abstraction
language until I stop marrying C. For this language I'll just keep
classes and structs as builtins

```TypeScript

class B
    id: int32

// the class declaration becomes a function trimmed of all static
// statements, and returning the scope as an object

class C (in_x = 0, in_y = 0)
    is B
    x: float32 = in_x
    y: float32 = in_y
    nbrs: C[]

//methods are just members of a scope taking an implicity
//this parameter from the dereference object

class D

```

function reference type and function casting:

```TypeScript

stdout, = import "io"  //string import argument?

func hello(audience: String): void
    stdout.print('hello', audience)'hello', audience)

//nonsensical interprettation of ints as strings
map(hello: func(String): void, [1, 5, 10, 20, 0])

//full on typing of a function declaration maybe?
func hello: func(String):void (audience: String): void
    stdout.print('hello', audience)'hello', audience)

function type uses the func expression without an identifier and in
a type context

```

