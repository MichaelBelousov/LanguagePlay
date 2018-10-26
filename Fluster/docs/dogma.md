
# Philosophy

Some philosophy for the design choices of this language.

## just a language

Fluster is not a runtime, Fluster is not a platform.
Fluster isn't opinionated and you can write your code however you like.
Fluster may, however, be opionated about how to design programming languages.

Fluster is just a way to write complicated assembly code, and tools
will need to be developed separately and modularly around it to use
it in JIT-compilers, code analysis, parallelism, with packages etc. 
But with the LLVM platform and its many levels of compiler and code 
abstraction, that shouldn't be too hard.

## abstract as \*\*\*\*

provide all possible abstractions as simply as possible

## no magic

As much of the language as possible without losing expressiveness
can, should, and will be implemented within the language itself.

language features should be a small core set which can in theory
be abandoned.

## interact with low-level code

should be able to link objects and libraries, 
and apply possible transformations, additions, added scopes, etc.

for example, the cpp and c modules have a user import operator 
that allows you to import C++ headers for their types, and libraries
as well as objects for their code


```TypeScript

import cpp

import<cpp.lib> stdcpp
import<stdcpp> vector
import<cpp.h> myheader

```

<!--
//DOC: op load defines the parameters for loading a module
-->

Here we can already start using c code, such as the library SDL2.

``` TypeScript


fluster_case, = import casing
import c(lib_case=fluster_case)

sdl2lib = import<c.lib> sdl2
import<sdl2lib> sdl2

//now we can use sdl
sdl2.SDL_Init()

```

In the C interaction section, you can see a quick example on how to remove the SDL prefix
for your own code.
<!-- add a link -->

## Fix conventions

## Power

You should be able to do a _lot_

like inline intermediate code

## hyper-level programming

all patterns need to be extractable, abstractable, and reusable

## separate as much as you want

## hardcore statics

## Math

C operators, but with some extras

^^ for exponentiation

^/ for roots (unary is square root)

## pack that

packing for intense code

## interactive and self-documenting

interactive programming is awesome,
don't let certain features get in the way

## Readability

things should just come naturally

## Declarative super powered OOP

granular declarative composition and inheritance

static duck typing, interfaces with defaults

## Get Typed

types as far as the eye can see

templated/generic types (or both!)

type domains and conversion trees with promotion

## Functional

filter, map, lambda, keys, min, max etc

## Iterables

no counters, except a lazy range iterable of course

## Error Handling

Exceptions and error control flow

## Anonymous constructs

somethings deserve no names

## Powerful Builtins

builtin arrays, lists, maps, sets

## Idiom of locality

encourage local changes to the outside environment,
like partial functions via lambdas and module patching, etc

## Idiom of scripting

entry point should be the source code itself, like a script

constructs can be imported, exported and included

## Static Reflection (declarative)

reflecting in the source declaratively includes the ability to reflect,
but it is preferred to do it during compile time

## compile time completeness

code can be interpretted at compile time for code generation
the compiler or runtime should be your friend, don't work around it

## \*\*\*\* underscores

privacy is declared, and underscores are unidiomatic names

## Patching & Renamers

transformers can go as far as renaming module layouts in case you
prefer a certain naming scheme, or adding functions if you think
they are appropriate

## function composition

patch a function so that code runs before or after it

## Scopes and contexts are cool

scopes are an important language feature


