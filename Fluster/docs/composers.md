
# Composers

Let's rename transformers to reformers?
Maybe composers? Sounds like fun.
Maybe recomposers?

So what problems can we solve with
them?
And which ones should we try to
solve...

## aspect oriented programming

```TypeScript
comp log_results<>

comp email_result
```

## garbage collection

try to  steal bits from pointers
or maybe just add garbage 
collection flags?

## runtime constraints

```TypeScript
comp constrain_celsius<target: Type>
  Target = typeof target
  class _
    merges Target
    op add (x: Target, 
            y: Target)
      // check that x and y
      // are still legal
      res = Target._ops.add(x,y)
      if res < -273.3
        raise {desc = 'invalid temperature'}
      return result;
  if ~DEBUG
    target <- _

@constrain_celsius
struct Celsius
    is float32

comp constraint<target: Type, 
                constraint_func: Function<Result: typeof target>
                msg: String>
  for m in target._meths
    //how do I handle template functions?
    meth _(this, ...args)
      res = m(this, ...args)
      if ~constraint_func(this)
        raise {desc=msg}
      return res
    m <- _
    //must include member accessors to maintain constraint

@constraint<c => c > 273.3, 
            'Invalid Temperature'>
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

//functions
@here
func C<>(): void
    pass

//imports
@here
D = import("d")

//declarations

@force_clrf
Q = File()

//parameters

func E<@comp def result: Type = default>()
func F(@notnull instance)

//arguments
G(@allow<x => x.id > 5> process, action)
H<@gc_ed class_>()

//literals
I = {
  @constraint<p => p > 10>
  p = 10,
  q = 5
}
J = (1, 5, @constraint<prime> 3)
//why would you ever do this?
K = [1, 2, @constraint 3]

// TODO: how do you make composers only apply 
// to specific types nondynamically?
comp example<target: typeof int>
// applies to only int-typed values
comp example<target: Type>
// applies to all types
comp example<target: typeof SomeClass>
// applies to all descendent subclasses
comp example<target: typeof SomeStruct>
// applies to only SomeStruct-typed values

```
