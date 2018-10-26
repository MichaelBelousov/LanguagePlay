
# Streams


<!--
add a bit clumping reoder
-->

```TypeScript

tran has_sink<Target: Factory>
    target._construct _
        merges target
        static
            sink: Symbol
        sink: bit = 0b0
        op eq (left: Target, right: sink)
            return truth(left.sink)
    target <- Scope

struct Stream<>
    fail

tran stream_impl<target: is Stream>
    struct _
        is Iterator
        @public next
        meth begin()
            return this
        meth end()
            return unbounded
        merges target
    target <- _

@stream_impl
struct Stream<func: Func<T: Type>>
    func next()
        return func()

@stream_impl
struct Stream<func: Func<T: Type, T>, 
              init: T>
    private
        state: T = init
        private did_init: bool = false
    func next(): T
        if ~did_init
            did_init = true
            return init
        else
            state = func(state)
            return state

@stream_impl
@has_sink
struct Stream<func: Func<T: Type, T>, 
              init: T,
              check_stop: Func<bool, T>>
    private
        state: T = init
        did_init: bool = false
    func next(): T
        if ~did_init
            did_init = true
            return init
        state = func(state)
        if check_stop(state)
            return This.sink
        else
            return state
```

