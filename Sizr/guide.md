
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
- `(` run-time construct parameter scope
- `<` compile-time construct parameter scope
- `{` implementation scope 
- `[` element scope
- `;` following declaration scope
- `,` following parameter scope
- `#` preprocessor scope
- `@` annotation scope
- `:` inheritance scope

We can combine scope expressions with these operators to describe collections of code. Take the following C++ examples:

A function named `begin` in a struct named `ListNode` in a class named `LinkedList` in a namespace named `data`:
```
namespace data . class LinkedList . struct ListNode . func begin
```

A function named `print` with an parameter named myArgument
```
print ( myArgument
```

The struct named `MyStruct` following a template `MyTemplate` with an parameter `ContainedType`
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
example which had two empty scope expressions around the parameter nesting operators.


Take another example, if you have a query:
```
class MyClass . myFunction ( {
```
There is no scope expression between the parameter scope nesting operator and the implementation scope nesting operator, and 
there is also no scope expression following the implementation scope nesting operator.


This is important, because even though the parameter scope could contain anything, and the implementation scope could contain anything,
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


Some scopes have special links to other scopes. For instance, the parameter scope of a construct is still linked to the implementation scope. So the following
query looks for the implementation of the function `myFunction`, not for the implementation of its parameter `myArgument`:
```
myFunction ( myArgument {
```

This also applies specifically to the per-parameter nesting operators, `,`, which allows you to access the next per-parameter scope, and still allows you to 
refer to the parent construct's implementation and members. For instance, take this query that selects a C++ templated type, `List`, with a second template parameter
named `Type`, and having a nested struct named `IteratorType`
```
List < , , Type . struct IteratorType
```
We have 5 scope expressions there. The first finds an identifier named `List`. The second is an empty (wildcard) parameter scope, the third is an empty per-parameter scope
expression (the first parameter), and the fourth is a second per-parameter scope for an identifier named `Type`. Finally, the last scope expression refers to the
member scope of the original `List` template, and specifies a struct named IteratorType there.


## _Captures_


So far, we have only seen for the most part, how to select specific elements in the code, singular constructs identified by their name and the scope
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
You could omit that capture and it would be an implied anonymous wildcard, so the omitting version of the query would be equivalent.
```
class MyClass . myFunction (
```

The dollar sign, `$` is the common denominator of all capture operators; alone, it is an unnamed capture, which is a lot of like a wildcard because
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
In that query, we're capturing all identifiers that match the regular expression `log_.*`, and have a runtime parameter scope.
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


Transformers help us use selectors to capture program elements, and then construct assertions based on them. They let
us transform portions of our code into something else, change our code, or even just add additional code or delete
existing code. The syntax is as follows:
```
SELECTOR >>> ASSERTION
```


Remember that our selectors and assertions have the same syntax, they're all just scope queries, potentially with captures.
If the selector to the left of the transformation operator, `>>>`, is omitted, it signifies a pure create rule. Normally if there is
a selector, it will be used to control the assertion when we start using _back references_.


For an example of a pure creation rule, let's add a class to our source:
```
>>> class NewClass
```

Let's add a function to that class now:
```
>>> class NewClass . func newFunction (
```

If the assertion is omitted instead, then you effectively have a delete rule, except that the normal transformation operator doesn't
delete selected program elements. So, omitting the assertion is a no-op Instead, if you use the _destructive transformation_ operator,
`>>!`, to indicate that after the transformation is complete, the selected program elements will be deleted, you can have a delete
rule. The use of a different operator makes it explicit that source will be deleted which is not necessarily reversible, even when the
Sizr client caches altered files. You should really be using a source version control software (aka git, hg, svn, etc) anyway
to prevent losing source revisions.


Here is an example of deleting the function we just made, which keeps the parent (now empty) class.
```
class NewClass . func newFunction >>!
```


But the final and most important usage is with both a selector and an assertion. Then, for each capture, we can make an assertion.
Let's capture functions prefixed with `log\_`, and for each one, move it to a namespace. Then, we'll try moving it that logging logic
to a `Logger` class.


First:
```
$/log_(.*)/ (
>>>
namespace logging . $/\1/
```


Note that we have a regex capture group in our selector, a common regular expression concept, and we use a backreference in the
assertion to reference it.


To disect that transformation, we need to realize that captures in an assertion mean something different. They are not
captures, or wildcards, they are references to the captures of the selection, and _the assertion is ran for each
capture it references_. Recall that the actual capture in the selector is the most deeply nested capture operation, which is always
syntactically the right-most capture, and trivially the only capture in this selector. So since we're capturing all functions prefixed
by `log_`, we're asserting once for each of those functions, asserting that there exists a function named by that backreference from
the regex capture, in a namespace named `logging`.


To make this better, let's alter the transformation to remove the replaced functions after, by using the destructive transformation
operator.
```
$/log_(.*)/ (
  >>! namespace logging . $/\1/
```


Next, let's try to turn the `log_` functions into methods. Once we have chaining, we can do a more intense and practical example where
we extract the `log_` function parameters to constructor parameters of the `Logger` object, and strip those parameters from the methods.
```
$/log_(.*)/ (
  >>! class Logger . $/\1/
```


### _Chaining_


What if we want to make multiple assertions from one selection, however? To do that, we simply chain assertions,
which allows us to combine the effect of multiple rules by reusing our selection and captures. The operator looks like `;;;`,
and we can for example assert something additional about our generated class.
```
$/log_(.*)/ (
  >>! class Logger . $/\1/
  ;;; class Logger . Logger ( const ref type=std::string filepath
```
Because no captures are referenced in that assertion, it only occurs once naturally.

<!-- moe this somewhere else -->
Next, we'll do some parameter extraction to that constructor, but first, let's work with a rule that has multiple captures.
Though it's a bit contrived, let's take every class in the source, and each of its functions, and make everything abstract:
```
class $c . $f (
abstract $c . abstract $f
```


Even though the real capture is the deep one, all functions of classes, which we capture as `f`, we keep a captured reference
to each's outer class. That way we can refer to it in the assertion, by its captured name, `c`. That is our backreference,
which we can use to assert properties, like here this query, where we assert everything to be an abstract class.


With that out of the way, let's finish our transformation lecture with a full C++ example.

<!-- first do describe expression mode in the assertion section -->
Suppose our source is the following in a simple file, logging.cpp:
```Cpp
void log_debug(char* msg, const char* logpath) {}
void log_warning(char* msg, const char* logpath) {}
void log_error(char* msg, const char* logpath) {}
```

We want to transform it into the following C++:
```Cpp
class Logger() {
    std::string logpath;
public:
    Logger(const std::string& in_logpath) { logpath = in_logpath; }
    debug(char* msg) {}
    warning(char* msg) {}
    error(char* msg) {}
}
```


<!-- the last scope expression _is the main capture_ -->
Let's start by taking our existing transformation, and extracting the parameters to our constructor:
```
$/log_(.*)/ ( logpath
  >>! class Logger . $/\1/
  ;;; class Logger . Logger ( const ref type=std::string logpath
  ;;; class Logger . type=std::string logpath
```
We added a member `logpath` of type `std::string` to our Logger class with an assertion, and we added an
parameter scope capture to capture the parameter named `logpath` of each log function and instead move it
to the constructor assertion. By specifying a value for the `type` property, we override its original type
as well, allowing us to move from using pointers to characters to C++'s standard dynamic string type, `std::string`.

But this will still be confusing, because even though we're capturing the logpath argument for each function, we're
actually not removing it from the functions, which is incorrect and confuses which reference should be used in the
functions since now a reference exists in the object as well. So, we use an assertion to remove that argument
```
$/log_(.*)/ ( logpath
  >>! class Logger . $/\1/ ( !logpath
  ;;; class Logger . Logger ( const ref type=std::string in_logpath
  ;;; class Logger . type=std::string logpath
```

Now, the references are resolved since there is only one place that those functions can reach the moved reference.
Almost done, let's assert that the constructor uses in_logpath to construct the logpath member.
<!--
TODO: need to come up with a standard for constructor initializer list...
maybe: class C { impl : init1, init2, etc
maybe: class C { C ( func : init1, init2, etc
maybe: class C { func C : func : init1, init2, etc
-->

```
$/log_(.*)/ ( logpath
  >>! class Logger . $/\1/ ( !logpath
  ;;; class Logger . Logger ( const ref type=std::string in_logpath { `logpath = in_logpath;`
  ;;; class Logger . type=std::string logpath
```

And finally, the only thing we lack is setting everything to public.
That will leave us with our complete transformation; capturing the concept of extracting functions
prefixed with `log_` and containing a `logpath` parameter, to a `Logger` object.

```
$/log_(.*)/ ( logpath
  >>! class Logger . public $/\1/ ( !logpath
  ;;; class Logger . public Logger ( const ref type=std::string in_logpath { `logpath = in_logpath;`
  ;;; class Logger . type=std::string logpath
```

And done, with the boolean property `public` on the necessary members, the exact class (without the formattting
component perhaps) is asserted as a result, and the original functions deleted with our destructive transformation.

<!-- TODO: standardize scope deletion for assertions -->

<!-- We add a name to our regex capture to make it clear which capture we're backreferencing in the assertion.
In this case, it isn't actually necessary since by default backreferences are in global appearance order so
`\1` still refers to the capture clause in the `log_(.*)`, but having the name would normally guarantee local
appearance order for that regex capture backreference. -->

## _Markers_


Markers allow your queries to query locations. They are versatile and essential even, in some languages.
Each marker is indicated by starting with the symbol, `@`.


## Raw Mode


