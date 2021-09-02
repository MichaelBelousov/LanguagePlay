
# Iteration 2

fixing the ambiguities of using parentheses as grouping syntax AND closure syntax.
this is mostly done by switching from parentheses to braces, and using brackets for records

## closures

- use braces to specify a closure
- NOTE: what do variadics look like?

```rust
closure1 = { $1 + 2 }
closure2 = { $name + ":" + $body }
typed_args_closure = {
  name = $1: Str
  body = $2: Str
  name + ":" + body
}

```

## function application

```rust
{ "%$name + %{$body}" }[#name=5, #body=2]
[1,2,3]:Array[i32].map[{$1 * 2}]
```

## function currying/partial-binding

```rust
createAdder = {
  // does type assertion operator on the left not force lossy casting?
  toAdd: i32 = $1
  {$1 + toAdd}
}
```

## Records

```rust
// anonymous fields
[1, 5.0f32, "hello"]
// named fields
[ #a = 5, #b = 5 ]
// mixed
[1, #field = 5.0f32, "hello"]
```

## function types

```rust
// how do we make this generic...?
// it might be a problem that parameters come after the return type, because they may depend in the reverse direction
vec: {
  // maybe whatever type logic we want (i.e. for params or generics) can happen in the closure body, so long as it returns the type literal?
  [
  #item_type = Type,
  #buf = *item_type,
  #size = {u32}, // method returning u32
  #push = {}[item_type], // method taking an item_type and returning nothing
]}[
  #item_type = item_type,
  #alloc = Allocator,
]

// NOTE:, if possible, unary `:` would make a good type widening operator

vec = {
  item_type = $1: Type
  alloc = $1: Allocator = heap_alloc
  // how are optional arguments baked into the language?
  // we can't keep partial-binding perfect while allowing implicit optionals...
  capacity = $starting_capacity or 5
  // maybe: $?starting_capacity, which automatically becomes a "Some" type and there is an idiom for unwrapping the value with a default (e.g. `or` or `??`)
  [
    #item_type,
    #buf: alloc[sizeof[item_type] * 5],
    #_size: 0u32,
    size: {_size}
  ]
}
// there are so many `#`, it would be much prettier methinks if I separated the assignment operation without a prefix to record keys
```

## tagged unions and pattern matching

```rust
WriteCmd =
  | Str Str
  | Indent i32
  | Outdent i32
  | Seq vec[WriteCmd]

val = WriteCmd.Str["hello"]
val = WriteCmd.Str "hello"
```

```rust
my_closure = {
  match val
    | a :: b :: [] -> {}
    | [a,b,c] -> {}
    | [a,b,..] -> {}
    | [a,b,..] -> {}
    | [#h,..] -> {}
}
```
