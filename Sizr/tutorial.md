
# Tutorial

## _Scope Expressions_ and _Properties_

Constructs in programs have properties, and a name. Assuming a C++ program, for instance, you may have some construct with a name, `MyClass`,
which has the property of being a class. You could have a construct, named `MyConstant`, that has the property of its
`type` which has a value of `int`, and has the property of being `const`, so its boolean `const` property has a value of `true`.


These properties are gathered by a _language backend_ for Sizr, a program that parses a specific language's source, and creates a database of identifiers, their properties,
and scope links. Properties are _language specific_, and even though several languages are similar enough to share keywords, it's not a guarantee and many will
have vastly different and unique properties of many kinds of values.


The core syntax of Sizr is comprised of nestable _scope expressions_. The concept of a scope in Sizr extends more than in most
programming contexts, to really any structural region of a program that can name an identifier.
When nested with _nesting operators_, scope expressions allow us to describe structures in our programs generically and simply.


For a first example, let's look at a query for a class nested in a namespace, in the C++ language.


```
namespace MyNamespace . class MyClass
```


There are actually two scope expressions there, separated by a nesting operator,  `.`, the nested member scope operator.


All scope expressions are a space-separated list of _property qualifiers_ followed by an identifier. In the above query, the first scope expression
`namespace MyNamespace` has the _boolean propery_, namespace, and the identifier `MyNamespace` .
If instead we wanted a non-boolean property, we'd have to specify a value for that property in the scope, with the `=` operator, like:


```
type=int !static MyConstant
```


The `!` operator restricts the query to matching identifiers where the boolean property `static` is false, and the `=` operator has a property, `type`,
of value `int`. Together, that scope expression refers to an identifier with a type of int, that is not static, and is named MyConstant.


## _Nesting Operators_

We've already seen the nested member scope operator, but there are several scopes that Sizr recognizes, anywhere a program could have an identifier
- `.` member scope
- (implicit) global scope
- `(` run-time construct argument scope
- `<` compile-time construct argument scope
- `{` implementation scope 
- `[` element scope
- `;` following declaration scope
- `,` following argument scope
- `#` preprocessor scope
- `@` annotation scope
- `:` inheritance scope

We can combine scope expressions with these operators to describe collections of code.

## _Captures_


## _Assertions_


## _Transformations_


### _Destructive transformations_


### _Markers_



