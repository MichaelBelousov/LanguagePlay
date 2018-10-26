
# Streams


```TypeScript

struct Stream<>
    fail

tran stream_impl<target: is Stream>
    struct _
        is Iterator
        next
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
struct Stream<func: Func<T: Type, T>, 
              init: T,
              check_stop: Func<bool, T>>
    _finite = 
    private
        state: T = init
        did_init: bool = false
    func next(): T
        if ~did_init
            did_init = true
            return init
        else
            state = func(state)
            return state
```

