
# Metatypes

## Type Classes

```
Var: Type
typeof Var == Type
Var != Type

MyTypeClass = cloneof Type
typeof MyTypeClass != Type

//the *is* operator returns a typeclass containing all types
//implicitly convertible to the argument type
//Type is the typeclass containing all types
Number: Type = is float64

op convert (from: Person, to: float64)
    return Person: byte[8]: float64
    //very stupid conversion, but now:
Number: Type = is float64

String<> = String<encoding=ascii>

//this is just an example, don't do this
op plus (lhs: Number, rhs: String)
    return "{{lhs}}{{rhs}}"
    //should I remove the + overload for strings...?

now since there exists a conversion from person to float64 which is
used to define the numbers, Person is in Number which Person can be added
to a String


```
