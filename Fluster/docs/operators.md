
# Operators

### C Operators

arithmetic + bitwise ones
not logical or pointer

### Exponentiation & Rooting

```TypeScript
2 ^^ 5  // the fifth power of 2
2 ^/ 5  // the fifth root of 2
^/10    // when unary, the square root
```

### Cast

```TypeScript
0b10110110: uint8
```

### Replace

```TypeScript
<-
```

### instance equality

```TypeScript
a #= b
//same as ptr<a> == ptr<b>
```

### Operator names

<!--
|           |                   |
- add latex integration for mathematical formula
- add modifiable check mark?
-->

| operation | identifier        | description |
|-----------|-------------------|-------------|
| *comparison* |||
| `a < b`     | lt                | less than |
| `a <= b`    | lteq              | less than or equal to |
| `a == b`    | eq                | equal to |
| `a <=> b`   | spaceship         | negative if *a* < *b*, positive if *a* > *b*, 0 if *a* == b
| `a != b`    | eq                | not equal to |
| `a >= b`    | gteq              | greater than or equal to |
| `a > b`     | gt                | greater than |
||||
| *arithmetic* |||
| `a + b`     | add (a, b)        | addition |
| `a - b`     | sub (a, b)        | subtraction |
| `-a`        | sub (a)           | negation |
| `a * b`     | mul (a, b)        | multiplication |
| `a / b`     | div               | division |
| `a // b`    | floordiv          | floored division
| `a ^^ b`    | pow               | n-th power. Unary uses the natural base, *e* |
| `^^a`       | pow               | Unary uses the natural base, *e* |
| `b ^/ a`    | root              | bth-root of *a* |
| `^/a`       | root              | square root of *a* |
||||
| *assignment* |||
| `a = b`     | assign            | introduce *a* variable or copy a new one |
| `a += b`    | addeq             | add to self |
||||
| *typing*     |||
| `a: B`      | cast              | cast expression *a* to type B |
| `a: B = c`  | type              | assert type is of B |
| `a has b`   | addeq             | *a* contains a *b* object |
| `a is b`    | addeq             | add to self |
||||
| *bitwise*    |||
| `a & b`     | and               | the bitwise AND of *a* and *b* |
| `a | b`     | or                | the bitwise OR of *a* and *b* |
| `~a`        | complement        | the bitwise complement of *a* |
| `a ^ b`     | xor               | the bitwise XOR of *a* and *b* |
| `a >> b`    | rshift            | rightshift *a*'s content by *b* bits and 0-pad |
| `a << b`    | lshift            | leftshift *a*'s content by *b* bits and 0-pad |
||||
| *logical*    |||
| `a & b`     | and               | the logical AND of *a* and *b* |
| `a | b`     | or                | the logical OR of *a* and *b* |
| `~a`        | complement        | the logical complement of *a* |
| `a ^ b`     | xor               | the logical XOR of *a* and *b* |
||||
| *memory*     |||
| `~a OR $a`  | copy              | copy of *a* |
| `a <- b`    | replace           | name replacement of *a* |
| `a <`-      | remove            | name deletion of *a* |
||||
| *packing*    |||
| `a,...c = d`| pack              | *a* is single-packed while c is packed from d |
| `...a`      | unpack            | *a* is pack-expanded in the expression |
||||
| *special*    |||
|             | create            | when an object is created, this operation is invoked |
|             | delete            | when an object is deleted (goes out of scope), this operation is invoked |
| `assert`    | assert            | when an object is deleted (goes out of scope), this operation is invoked |
||||
| *access*     |||
| `a[k]`      | get (k)           | execute the get operation of *a*'s type on *a* with k |
| `a[k] = b`  | set (k, b)        | execute the set operation of *a*'s type on *a* with k being set to *b* |
||||
| *other*      |||
| `c ? a : b` | ternary (c, a, b) | if c: *a*, else *b* |

<!-- 
add a copy operator? 
since all slices will be views?
-->

### Type Operators

```TypeScript
t = -132
type t == int32
```
