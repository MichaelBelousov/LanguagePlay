
# Formatting and String Comprehension

## Evaluation strings (e-strings)

Evaluated-strings or e-strings are a syntax for standardized
string comprehension and construction

```TypeScript
f: float = 32.101243701
mystr: String = e"A long float might look like {{f}}"
mystr2: String = e"5 to the power of f is: {{5^^f}}"
```

## Formatting

The semicolon separates the formatting expression from the 
formatter/representer being used, and it can be omitted to use
a default. The representer controls the actual string 
representation of the result of the expression. 

The following example shows ways it can be used. Read the evaluation
interface section to see how to define representers.

```TypeScript
mystr3 = e"${{f;2}}" // == 
```
$32.10

```TypeScript
fmt = ".1E"
mystr4 = e"{{f;fmt}} mol" 
```
3.2 x 10<sup>1</sup>

```TypeScript
sci_not = Decimal.Format.ScientificNotation
mystr5 = e"{{f;sci_not}}" 
```
3.2101243701 x 10<sup>1</sup>

##### Representers

The string formatting expression delimiters are considered an operation
with the "format" operator, the format operator. Format operator 
implementations can take arguments of any type and return a `String`.

The Base looks like such:

```Typescript
op format (e: ExprType, n: Representer): String
    ...
```

A couple of contrived and inconsistent 
float format operators using integers and custom objects 
would look like the following:

```Typescript
op format (f: float, n: int): String
    full  = f.toStr()   //suppose such a function exists
    point_idx = full.find('.')
    return full[:point_idx + n]

op format (f: float, repr: Decimal.SciNot): String
    return repr.represent(f)
```

These could be used, respectively, to format mystr3, and mystr5

