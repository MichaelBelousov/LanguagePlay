
# Iterables

# Finite and Infinite iterators

`_finite`

`Unbounded: Type`

# Iterable Interface

```TypeScript

interface Iterable<T: Type>
    meth begin(): Iterator
    meth end(): Iterator
    length: meth(): uint32 | infinity

```

# Iterator Interface

```TypeScript

interface Iterator<T: Type>
    is Iterable<T>
    iterable: Iterable
    meth begin(): Iterator
        return this
    meth next(): T

```

# Reversible Iterator interface


