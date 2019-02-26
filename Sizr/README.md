
# Sizr

A generic source pattern matching language focused on the C language family
with an emphasis on terseness but completeness, ala regular expressions

Lift all functions prefixed with "log\_" to a class named logger
```Cpp
func "log_$" (
>>>
class Logger :: $
```

Lift a global to the same class

```Cpp
:: log_file_path
>>>
class Logger :: $
```

Lift an implementation constant

```Cpp
func "log_*" ( { `flags.write | flags.append`
>>>
class Logger :: var log_write_flags = $
```

Replace a commonly inlined formula with a function call, using
named captures

```Cpp
`1/2 * $base * $height`
>>>
namespace MathUtil :: TriangleArea ( $base, $height { $
```

Replace a common sequence with an object
```Cpp
std::vector * $vec ; $vec . reserve ( $amt
>>>
ReservingVector ( $amt
\`\`\` //the supplement
### FILE($vec)
namespace util :: class ReservingVector : private std::vector \
    ( amount { `this.reserve`
\`\`\`
```
<!--
how are will I assert the file location of transformations?
-->

<!--
Calling a class is the constructor
Might need a separate "obj" or "inst" instead of class to access
call operators e.g. "inst MyFunctor ("
-->

<!--
how can this apply generically to reference and pointer types?
how can it be reasoned that we're dealing only with the life of $vec,
and ignoring any things that don't mutate it ocurring between those two
statements?
-->
