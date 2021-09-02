
# thoughts on another language after reading some zig and reflections on rust

## NOTE, THIS IS ALL SUBJECT TO CHANGE, SEE ITERATION2.md

Basically I want to use a fully variant-based type system with compile-time values for constant folding built into the language
similarly to comptime in zig, but using "widened" and "narrowed" types

## structs

```rust
# struct literal
{
  member = "hello",
  size = (5) # closure returning 5
}

# struct type literal
{
  member: Str,
  size: (int)[] # closure returning 5
}
```

one way of merging tuple+struct syntax as record syntax, is making "name declarations" separate from assignment operations

for instance, a struct property declaration could use the following `#` syntax

```rust
{ #member = 5; #fn = (member) }
```

then you can tell apart unnamed struct fields:

```rust
{ 5u32, 0.5, #named = 20, annoying_unnamed = "hello" }
```

- another option is separating declaration and initialization (annoyingly non-terse)
- another option is separating assignment operation syntax from declaration... this is ideal but deviates from C-family further

```rust
{
  #prop1 = "hello"
  #hello = 5
}
```

## closures

```rust
// closures
($1 + $2) // unnamed ordered arguments
() // empty closure
// expression chaining operator used
f = ($name, $desc); f(name="hello", desc="world")
```

```rust
# function/closure types
f: (i32) // returns int
f: (i32)[i32,i32] // returns int, takes two ints
f: (i32){x: f32, y: f32} // returns int, takes two named arguments x, y?
f: (i32)[i32, f32]{x: f32, y: f32} // returns int, takes two unnamed arguments, and two named arguments
```

```rust
# block/closure
(
  x = 4 + 4
  x += 3
  y = x + 2
  x + y // last is returned
)
```

```rust
# the issue with the closure syntax:
# what type is being passed to this function?
f[(4)]
# is the argument a closure or a value?
# I suppose, once it is fully bound without arguments, it is implicitly evaluable, which makes it work
# but what about nested closures, what does $1 reference?
f[($1 * ($2 + $3)]
# sure, the `*` operator may not make much sense against a closure, but let's find an example that does...
# this takes a closure argument and applies two other arguments to it
($1[$2, $3])
#looks like you have to alias to use nested args, like aliasing `this` when nesting methods in javascript
createAddMapper = (
  add = $1: int
  ($1 + add)
)
```

### problems with closure binding

```rust
# so does the input variable propagate to the outer closure?
# does this cause ambiguities at all?
f = (2 * ($1 + 3))
# if the outer closure has a collision with the inner closure, that may be an ambiguity
f = ($1 * ($1 + 2)) # ambiguous, does the inner closure imply the need of a second argument
f = ($1 * ($1 + 2)[$1]) # explicitly bind $1 from the outer closure to the inner closure
# where is the scope of a closure parameter determined? At the furthest name/binding?
```

## tuples

```rust
# tuple syntax
[1i32, 2.0f64, "string literal"]
```

```rust
map = (
  $1: Iter
  fn = $2: ($U: Type)[$T: Type]
  # haskell cons operator for pattern-matching
  match $1
    first :: rest -> fn[first] :: map[rest, fn]
    _ -> []

)
# in practice, I think tuple mapping isn't really helpful, better to have an array of a tagged union, to avoid the need for statically overloaded functions
[1, 2, 3.2]: []float
```

## constructor stuff

```rust
# honestly, why even have an `fn` keyword when closures are so easy to make?
arr = (`${$name} + ${$desc}`)

# how do you impose limitations on $T?
concept/type/interface Arr<T: > = {
  buff = [~int]T,
  size = (~int)[] # takes no args, returns int variant 
}
# the ~ operator is the type narrowing operator, it requires a variant of the given metatype/typeclass

# constructor again?
Arr[T: Type, size: ^int, alloc: (*byte)] = {
  buff: alloc[size * sizeof(T)];
  size: (size) # closure returning size, implicitly makes this struct copy the value of "size", also has implicit empty tuple argument
  map: (Arr[$V, size, alloc])[(V)[T]] # closure returning size, implicitly makes this struct copy the value of "size"
}

arr = Arr[i32, 10, malloc]
assert arr.size[] == 10

# ^ is the narrowed type (variant) operator, meaning the type isn't an int, but rather some variant of int, and therefore it's a constant because
# it's a value. Should check how this integrated with tagged unions/enums, i.e. variant type but still multiple values can exist

# so then after this, how are effects handled? e.g. async/await and monadic early return?
```

## coroutines

I consider coroutines to be important, and relevant to async programming, so how do we make ergonomically yielding closures?
could just use the yield keyword to start...

```rust
filter = (
  $1: Iter
  $2: (bool)[$T: Type]
  for item in $1 (
    if $2[item] (
      yield item
    )
  )
)
```

maybe closures that can be rebound somehow?

```rust
my_closure = (
  yield 1
  yield 2
  yield 3
)

filter[[1,2,3], my_closure]
```

