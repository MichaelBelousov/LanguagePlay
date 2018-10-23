
# Merging & Redeclaration

when there are multiple declarations, structures *merge*. Some
merging is very useful for separating or transforming concerns of
a declaration, while some can be considered dangerous and may
generate warnings.

##  Redeclaration

Variables and functions can be redeclared. Variables can have different
types (functions can too but their signature is part of their name due to overloading)

A declaration of the same name to an existing name will
overwrite the previous 

```C
func foo(a: int32, b: float32): float32
    return b^^a

foo(1,2)

func food(a: int32, b: float32): float32
    return a^^b

foo(2,1)
```

## Variable Redeclaration


```TypeScript
a: int = 5
a == 5
a: float = 10.0
a == 10.0
```

## Merging

### Class/Struct merging

```TypeScript
class A
    merges B
```
