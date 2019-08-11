
# Guide

## _Scope Expressions_ and _Properties_

Constructs in programs have properties, and a name. Assuming a C++ program, for instance, you may have some construct with a name, `MyClass`,
which has the property of being a class. You could have a construct, named `MyConstant`, that has the property of its
`type` which has a value of `int`, and has the property of being `const`, so its boolean `const` property has a value of `true`.


These properties are gathered by a _language backend_ for Sizr, a program that parses a specific language's source, and creates a database of identifiers, their properties,
and scope links. Properties are _language specific_, and even though several languages are similar enough to share constructs, it's not a guarantee and many will
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

We can combine scope expressions with these operators to describe collections of code. Take the following C++ examples:

A function named `begin` in a struct named `ListNode` in a class named `LinkedList` in a namespace named `data`:
```
namespace data . class LinkedList . struct ListNode . func begin
```

A function named `print` with an argument named myArgument
```
print ( myArgument
```

The struct named `MyStruct` following a template `MyTemplate` with an argument `ContainedType`
```
MyTemplate < ContainedType ; struct MyStruct
```

A class, `MyClass` with a third inheritance base of `Serializable`
```
class MyClass : , , Serializable
```

### Empty Scope Expressions

An empty scope expression is a wildcard, and nesting wildcard scopes is imporant because it _requires_
the existence of such a scope. You can see our first example of an empty scope expression taking place in the most recent
example which had two empty scope expressions around the argument nesting operators.


Take another example, if you have a query:
```
class MyClass . myFunction ( {
```
There is no scope expression between the argument scope nesting operator and the implementation scope nesting operator, and 
there is also no scope expression following the implementation scope nesting operator.


This is important, because even though the argument scope could contain anything, and the implementation scope could contain anything,
a name without any of those scopes will not be matched by the query. A variable named `myFunction` will not be matched, and a function
without an implementation, such as an abstract function, will not be matched. This becomes more imporant when we start not just finding
specific constructs, but capturing constructs with these queries, where we won't know the name of the member of MyClass, but we'll be searching
for all callable members with an implementation.


### restricting to fully qualified names


If an empty scope expression takes place before the member access nesting operator in a query, it signifies that the query is nested in the global
scope. Normally, queries do not need to be fully scope-qualified: a query, `class MyClass` will find _any_ class named `MyClass` in the source,
regardless of whether it is nested within a namespace or some other scope.
To nest in the global scope explicitly, and therefore require fully qualified names, start the query with a member access operator to indicate accessing
the global scope:


Capture any identiifer that is a class named `MyClass`:
```
class MyClass
```


Capture an identifier in the global scope that is a class named `MyClass`:
```
. class MyClass
```

### specially linked scopes


Some scopes have special links to other scopes. For instance, the argument scope of a construct is still linked to the implementation scope. So the following
query looks for the implementation of the function `myFunction`, not for the implementation of its argument `myArgument`:
```
myFunction ( myArgument {
```

This also applies specifically to the per-argument nesting operators, `,`, which allows you to access the next per-argument scope, and still allows you to 
refer to the parent construct's implementation and members. For instance, take this query that selects a C++ templated type, `List`, with a second template argument
named `Type`, and having a nested struct named `IteratorType`
```
List < , , Type . struct IteratorType
```
We have 5 scope expressions there. The first finds an identifier named `List`. The second is an argument scope wildcard, the third is an empty per-argument scope
expression (the first argument), and the fourth is a second per-argument scope for an identifier named `Type`. Finally, the last scope expression refers to the
member scope of the original `List` template, and specifies a struct named IteratorType there.


## _Captures_


So far, we have only seen for the most part, how to specify points in the code, singular constructs identified by their name and the scope
in which they were identified. The more interesting part of Sizr however is where we don't constrain our query to specific names, or even
specific properties. We do this with the power of _captures_.


Captures specify another wild card in the code, but this time we can specify properties on the wildcard, and even give the capture a name
for future reference. Let's start simply:
```
class $
```


Any empty scope expression is equivalent to an unnamed capture:
```
class MyClass . myFunction ( $
```

The `$` is the common denominator of all capture operators; alone, it is an unnamed capture, which is a lot of like a wildcard because
this query will match any identifier in the source code that is a class. Since we're not restricting to global scope, it will match any
class anywhere with any other properties. We can name our capture, which matches the same thing but will be useful when we actually
start using our captures to do things:
```
class $captured_class
```


That query matches every class in the source, but the capture can be referred to by that name, `captured_class` later.


Here are all of the capture types, some of which we'll go over:
- `$NAME` identifier capture
- `$/pattern/NAME` regex capture
- `$_NAME` whitespace capture
- `$%NAME` operator capture
- `$...NAME` operator fold capture


The first special capture is the regex capture, which allows you to do needlessly complex regular expression matching for
identifiers. For instance, select all functions prefixed with `log_`. Later we'll use that selection to extract those functions
to a Logger class, and we'll finally be using Sizr for real.
```
$/log_.*/ (
```
In that query, we're capturing all identifiers that match the regular expression `log_.*`, and have a runtime argument scope.
So in our current program's source, we'd be capturing functions such as `log_debug`, `log_warning`, and `log_error`.


You can use multiple capture operators to capture nested forms.
Here we capture all constant member variables of subclasses of `Shape`, and capture the class they are in.
```
class $captured_class : Shape . const var $captured_member
```
The most deeply nested capture is what's actually captured, while the previous captures are parent captures.

<!--
Create an image here illustrating source scopes
-->

We'll ignore the remaining capture operator types for now.


## _Assertions_


There is a thing about these queries, they're not just selectors. They're also _assertions_.
Queries are a double sided tool, because in Sizr, in some contexts, a query is used as an assertion.
Assertions use the language backend to write changes based on properties and scope expressions.


Let's suppose we have a class, `MyClass`, with abstract (pure virtual) functions in C++, which we would select
with the following query:
```
class MyClass . abstract $ (
```


Then we write an assertion that makes all functions in `MyClass` concrete:
```
class MyClass . !abstract $ (
```


In an asserting context, the language backend will write back to the source the transformation of removing the
abstract property. It's language-dependent, but in C++ that will probably involve removing any implementation
and setting the function declaration equal to 0 as is customary in C++.


Already you can probably see that we need to combine selectors and assertions, and that's where we finally
get to the main, and broadest element of Sizr, _transformations_.


## _Transformations_


Transformers help us use selectors to capture constructs, and then reference those captures in assertions.


### _Chaining_

`;;;`


### _Destructive transformations_

`>>!`

### _Markers_


Markers allow your queries to query locations. They are versatile and essential even, in some languages.


### Source Mode


