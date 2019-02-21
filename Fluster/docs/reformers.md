
# Composers

Let's rename transformers to reformers?
Maybe composers? Sounds like fun.
Maybe recomposers?

So what problems can we solve with
them?
And which ones should we try to
solve...

## aspect oriented programming

## garbage collection

try to  steal bits from pointers
or maybe just add garbage 
collection flags?

## runtime constraints

```TypeScript
comp constraint<target: Type>()
@constraint<f>
struct Celsius
    is float32
```

## compile time code generation

let's try to maybe... Generate
a compile time look up table

## where can I use these?

```TypeScript

//on structures

// recall that a class is a reference typed dynamic structure

@here
class A
    pass

@here
struct B
    pass
// is it even necessary to use a
// pass clause or can I just have
// an empty structure in the 
// grammar?                                 

@here
func C<>(): void
    pass

//imports
@here
import('hello')

```
