
# CFFI

## C++

```TypeScript

op import<_=cpp.lib> (path: ImportPath)
    fullpath = findLib<path>
    return CPPLib<fullpath>

op import<lib: CPPLib>(path: ImportPath): Module
    return lib.include(path)

```

And now we can include C++ types, templates, data, etc

```TypeScript

import cpp

import<cpp.lib> stdcpp
import<stdcpp> vector
import<cpp.h> myheader

```

## C

``` TypeScript


op import<_=c.lib> (path: ImportPath)
    fullpath = findLib<path>
    return CLib<fullpath>

op import<lib: CLib>(path: ImportPath): Module
    return lib.include(path)

```

And now we can use our C libraries, here's an example
with some advanced fun:

``` TypeScript

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



