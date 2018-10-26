
# Move Semantics

As implicit as possible.

Copying from an rvalue object will grab all of the
objects

## Compiler generates rvalue overloads

The compiler will generate rvalue constructors for the same types and constructs
for other types, not related by construct, you would need to use the magic rval<> construct


## `rval<>` in case you really really want it...

you 

## `<-` move operator

Probably don't need this to do such
the replacement operator is also the move operator

```TypeScript

class Image
    static
        types = ["jpg", "png"]
    public
        width: uint32 = 0 //these could be construct parameters
        height: uint32 = 0
        meth blit(this: This, x: int32, y: int32): void
            # show on the screen
            gpu.blit(this.data)
    private
        data: byte[width][height]
    outer
        op delete()
            gpu.refresh()

```

<!--
do exactly as the programmer says, no more, no less

maybe, if all arrays are references, then that'll make it
easier to have move semantics
-->
