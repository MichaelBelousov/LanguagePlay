no language really matches this of course, I'll need to come up with my own
color coding. Unless github has some way to submit languages for markdown

parsing.
```C

//type coercion and domains? e.g. overlapping and specializing domains?
//e.g. number domain with int specialization

//snakecase vars, camelcase functions, pascalcase types, [lowercase primitives]
from renameutil import ClassicNamer 

transform more_math(module: Import)
    type module _  //use "type" keyword to get the scope type from an argument
        merges module

        //obviously the lib ClassicNamer would have a Reformer for this
        //can this be replaced with merging and some kind of macro? :(
        for member in module:
            name = ClassicNamer.name(member, member._name)
            this.members.add(name, member)  //could cause collisions!

        func sum(args: Args<...Number>): Number
            result = 0
            for arg in Args
                result += arg
            return result

    module <- _


@more_math
from math import sum

domain number  //type domains for conversions and type trees...?
    int32
    int64
    int
    float32
    float64

//scopes have a reflection reference to the outer scope, '_outer'
scope MyScope
    blah: int32

interface MyInterface
    blah: int64
    func example(a: int32, b: int)

struct Vec3D
    implements comp
    x: float32
    y: float32
    z: float32
    op unpack (target: Vec3D)  //return value is deducible: tuple(float32, float32, float32)
        return x, y, z
    op gteq (lhs: Vec3D, rhs: number)
        return lhs.size() >= rhs
    meth size(this: Vec3D)  //this parameter type must be type of outer construct
        // get the size of the 
        return math.sqrt(sum(...v**2))
    meth norm(this): Vec3D
        sz: float32 = this.size()
        if sz == 0 
            return v
        else 
            return Vec3D(...v/sz)
    static
        zero_vec: Vec3D = Vec3D(0,0,0)

    func dotprod(u: Vec3D, v: Vec3D): float32
        # return the dot
        return sum(...u*v)  //all packs must be the same type in an expression
    
    innerprod = dotprod


//maybe change class to "factory"?
@Layout
class ProjectileMovementComponent
    is MovementComponent as Super
    has MovementComponentUtils  //absorbs by composition
    has Utils.serializeToJSON as serializeToJSON
    has Utils.serialize as utils.serialize
    implements ProjectileComponent

    @public speed: float32

    static
        initialVelocity: Vec3D

    public
        projectile: PhysicsActor

        meth construct(this): void  //implicit and deducible
            this.velocity = Vec3D.zero_vec
            this.acceleration = Vec3D.zero_vec

        meth destroy(this): void
            this.owner.release

        @before_super //after_super should exist
        meth tick (this, delta: float32): void
            velocity += delta*acceleration
            physics.move(this.projectile, 
                    this.location + velocity*delta)

        op equals (lhs: ProjectileMovementComponent, rhs: ProjectileMovementComponent): bool
            PMC = ProjectileMovementComponent
            return ptr<PMC> == ptr<PMC>

    private
        location: Vec3D
        velocity: Vec3D
        acceleration: Vec3D


// maybe call these "reformers"?
// decorator specialization
decor Layout(ProjectileMovementComponent)
    class _
        merges ProjectileMovementComponent  //merges keyword overrides
        @align(64) projectile: PhysicsActor
        speed: float32  //doesn't change type, just for declaration
        location: Vec3D
        velocity: Vec3D
        acceleration: Vec3D
        pad: byte[16]
        //redeclaring a name changes only what's added, e.g. the new order,
        //potentially a different type and additional decorators/reformers
    ProjectileMovementComponent <- _
        

decor logCall(f: Func<...any>) //warning, untyped function
    //Args is a builtin type, a packable list of named arguments
    func decorator(args: Args)
        result = f(...args)
        log.info('logging call', f._name, result=result)
        return result
    f <- decorator  //replacement operator

decor combine_after(m: Meth<...any>)
    meth decorator(this, args: Args)
        //if there is no overided method, it will complain
        m._overided()  
        return m(this, ...args)
    m <- decorator

//solo backslash is a newline
class Example \ is ExampleParent
    pass
    //need a null expression?

//solo backslash at the _end_ of the line is a continuation
class Example
    is ExampleParent
    type_name: String = "hello this is a \
                         long name and is dedented"
    other_name = 'dedented
                  blah etc'  //char array literal
    blah: char = 'c'  //char literal
    raw_name = `this is a 
                non-dedented string (it'll have that long space)`
    format_str = "this is a !format~ string" <- {format: 'formatted'}


if _entry
    blah // equivalent to Python __name__ == '__main__' idiom

@Ops.reflexive
op add (A: Matrix, B: ptr<Matrix>)
    for row_a, row_b in a, b.get()  //returns an object of ptrs
        for a, b in row_a, row_b
            b.set(b.get() + a)
            b *+= a?
    %`
    //bytecode literal?
    mov
    `%
    return B

" string literals
 are multiline
I think"

cast operator?:

5 to int128
5 as int128
5 -> int128
5->int128
int128<-5 //reflected, could work since lhs must be a type
(int128) 5  //(c-style) let's not use multiple cast operators...
//we can't be giving programmers choices, can we?
5->int28
Dog<-cat.chew() //turn the cat into a dog then chew...?
5: int128 //if not in a declaration (e.g. parameter or var decl)

//assignment is an expression btw ofc

    
```
