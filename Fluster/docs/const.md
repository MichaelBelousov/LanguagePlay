
# Constness

const is used in C/C++ to demonstrate immutable data, as well as
immutable references and functions that do not mutate data

```TypeScript

malloc, move = import memory

//naive struct implementation
struct vector<T>
    // flat array of values, fast and effective
    // dynamic high-level array

    has iterable

    //members are public by default!

    struct Iterator
        is .iterator
        private
            end: ptr<T> = null
            p: ptr<T> = null
        meth next() \ return (++p): Iterator
        meth done() \ return p == end

    struct SafeIterator
        is .iterator
        merges Iterator
        private
            owner: vector
            p: ptr<T> = null
        meth next() 
            return (++p): Iterator
        meth done()
            return p == owner.end

    meth iterator()
        # get an iterator for this vector
        return (data, data + size): Iterator

    static
        doubleable_size: uint32 = 100000
        huge_increment: uint32 = 1000

    private
        size: uint32 = 0
        data: ptr<T> = null
        end: ptr<T> = null
        IndexType = int32

    meth grow(): void
        # reallocate the data to a larger array
        if size < 8
            size = 8
        elif size < doublable_size
            size ^^= 2
        else 
            size += large_increment
        newbuff = malloc(size * sizeof T)
        copy(data, newbuff + 1)

    meth fit(): void
        newbuff = malloc(size * sizeof T)
        copy(data, newbuff)

    meth append(T t): void
        
    meth prepend(T t): void

    @const 
    op get(i: IndexType): T
        if i < 0
            return (end + i).val
        else \ return data[i]

    op get(i: IndexType): ref<T>
        if i < 0
            return end + i
        else 
            return ref<data[i]>
        

```
