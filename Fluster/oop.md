
# Object Oriented Design Features

declarative composition

```Fluster
class A
    is B
    has C as c      //composition
    has D.f as d.f  //composition of one function
    has E.g as g    //anonymous composition of one function
```

## interfaces

```TypeScript
interface Configurable
    meth load(path: String): void
    meth dump(path: String): void
```

## anonymous implementations

## virtual functions and type dispatch
