
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

| syntactic | operation         | description |
|-----------|-------------------|-------------|
| *comparison* |||
| `a < b`     | lt (a, b)         | *a* is less than *b* |
| `a <= b`    | lteq (a, b)       | *a* is less than or equal to *b* |
| `a == b`    | eq (a, b)         | *a* is equal to *b* |
| `a #= b`    | ptreq (a, b)      | `ptr<a> == ptr<b>`, *a*'s address is equivalent to the address of *b* |
| `a <=> b`   | spaceship (a, b)  | result is negative if `a < b`, positive if `a > b`, 0 if `a == b` |
| `a ~= b`    | approxeq\<epsilon\> (a, b)   | *a* is approximately equal to *b*, which is idoimatically modified in your scope |
| `a ~ b`    | similar \<epsilon\> (a, b)   | *a* is similar to *b* |
| `a != b`    | neq (a, b)        | *a* is not equal to *b* |
| `a >= b`    | gteq (a, b)       | *a* is greater than or equal to *b* |
| `a > b`     | gt (a, b)         | *a* is greater than *b* |
||||
| *mathematical* |||
| `a + b`     | plus (a, b)       | addition *(rename to plus vs minus?)* |
| `a - b`     | minus (a, b)      | subtraction |
| `-a`        | minus (a)         | negation |
| `a * b`     | times (a, b)      | multiplication |
| `a / b`     | over (a, b)       | division |
| `a // b`    | floor (a, b)      | floored division |
| `a % b`     | modulo (a, b)     | remainder |
| `a mod b`   | modulo (a, b)     | remainder |
| `a ^^ b`    | pow (a, b)        | n-th power. Unary uses the natural base, *e* |
| `^^a`       | pow (a)           | Unary uses the natural base, *e* |
| `b ^/ a`    | root (a, b)       | bth-root of *a* |
| `^/a`       | root (a)          | square root of *a* |
||||
| *typing*     |||
| `a: B`      | cast (a, B)       | cast expression *a* to type B |
| `a: B = ...`| typedecl (a, B)   | declare the type of name *a* to be *B* |
| `A has B`   | has (A, B)        | type *A*'s composition contains a *B* object |
| `A is B`    | is (A, B)         | type *A* is of type *B* |
||||
| *bitwise*    |||
| `a & b`     | and               | the bitwise AND of *a* and *b* |
| `a \| b`     | or                | the bitwise OR of *a* and *b* |
| `~a`        | complement        | the bitwise complement of *a* |
| `a ^ b`     | xor               | the bitwise XOR of *a* and *b* |
| `a >> b`    | rshift            | rightshift *a*'s content by *b* bits and 0-pad |
| `a << b`    | lshift            | leftshift *a*'s content by *b* bits and 0-pad |
||||
| *logical*    |||
| `a & b`     | and               | the logical conjunction of *a* and *b* |
| `a \| b`     | or                | the logical disjunction of *a* and *b* |
| `~a`        | complement        | the logical negation of *a* |
| `a ^ b`     | xor               | the logical exclusive or of *a* and *b* |
| `a -> b`    | implies           | the logical implication of *a* and *b* |
||||
| *assignment* |||
| `a = b`     | assign (a, b)     | *a* copies *b* or *a* is introduced as a copy of *b* |
| `a += b`    | assignplus (a, b) | `a = a + b` |
| `a -= b`    | assignminus (a, b)| `a = a - b` |
| `a *= b`    | assigntimes (a, b)| `a = a * b` |
| `a /= b`    | assigndiv (a, b)  | `a = a / b` |
| `a //= b`   | assignfloordiv (a, b) | `a = a // b` |
| `a ^^= b`   | assignpow         | `a = a ^^ b` |
| `a ^/= b`   | assignroot        | `a = a ^/ b` |
| `a &= b`    | assignand         | `a = a & b` |
| `a |= b`    | assignor          | `a = a | b` |
| `a >>= b`   | assignrshift      | `a = a >> b` |
| `a <<= b`   | assignlshift      | `a = a << b` |
||||
| *memory*     |||
| `$a`        | copy              | copy of *a* |
| `a <- b`    | replace           | name replacement of *a* |
| `a <-`      | remove            | name deletion of *a* |
||||
| *iteration*    |||
| `a,...c = d`| pack              | *a* is single-packed while c is packed from d |
| `...a`      | unpack            | *a* is pack-expanded in the expression |
||||
| *special*    |||
|             | create            | when an object is created, this operation is invoked |
|             | delete            | when an object is deleted (goes out of scope), this operation is invoked |
| `assert a, b` | assert          | assert the `truth(a)` and fail with error *b* if false |
||||
| *access*     |||
| `a[k]`      | get (a, k)        | execute the get operation of *a*'s type on *a* with k |
| `a[k] = b`  | set (a, k, b)     | execute the set operation of *a*'s type on *a* with k being set to *b* |
| `a.b`       | member (a, b)     | access the name *b* in *a*
||||
| *function*   |||
| `[...captures](...args) => expr` | lambda (...args): b | create a struct containing the captures objects, and a function with a reference to the struct over arguments `args` |
||||
| *other*      |||
| `c ? a : b` | ternary (c, a, b) | if c: *a*, else *b* |
| if a        | truth             | conversion of a to bool type |
| while a     | truth             | conversion of a to bool type |
| until a     | truth             | conversion of a to bool type |
||||
| *compiler*      |||
| import name    | import<...Ts>(path: ImportPath, ...args) | import a package with import arguments *args* |
| load (...args) | load (...args) | code with arguments for when the module is loaded |



<!-- 
add a copy operator? 
since all slices will be views?
-->

### Type Operators

```TypeScript
t = -132
typeof t == int32
MyType = cloneof float32
MyType != float32
```

