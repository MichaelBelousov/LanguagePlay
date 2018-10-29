
# Iterables

# Finite and Infinite iterators

`_finite`

`Unbounded: Type`

# Iterable Interface

```TypeScript

interface Iterable<T: Type>
    meth getIterator(): Iterator

```

# Iterator Interface

```TypeScript

interface Iterator<T: Type>
    meth next(): T
    meth done(): bool

```

# Reversible Iterator interface


