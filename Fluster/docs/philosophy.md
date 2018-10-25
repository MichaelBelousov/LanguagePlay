
# Philosophy

Some philosophy for the design choices of this language.

## interact with C

should be able to link C/C++ libraries, can only transform
the names and scopes etc

can reimplement the import operator to use import C++ headers
that should be part of the cpp module

```TypeScript

import cpp

/*
op import<_=cpp.lib> (path: ImportPath)
    fullpath = findLib<path>
    return CPPLib<fullpath>

op import<lib: CPPLib>(path: ImportPath): Module
    return lib.include(path)
*/

import<cpp.lib> stdcpp
import<stdcpp> vector
import<cpp.h> myheader

```

<!--
//DOC: op load defines the parameters for loading a module
-->

``` TypeScript


/*
op import<_=c.lib> (path: ImportPath)
    fullpath = findLib<path>
    return CLib<fullpath>

op import<lib: CLib>(path: ImportPath): Module
    return lib.include(path)
*/

fluster_case, = import casing
import c(lib_case=fluster_case)

tran fix_sdl2(target: Module)
    module _
        merges target
        for name, val in target._members
            name.withoutPrefix("SDL_") <- val
            name <- 
    target <- _

sdl2lib = import<c.lib> sdl2
import<sdl2lib> sdl2

//now we can use sdl
sdl2.init()

```

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


