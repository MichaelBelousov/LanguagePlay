

```Python

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
    op geq (lhs: Vec3D, rhs: number)
        return Vec.size() >= number
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

        @combine_after  //combine_before should exist
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

if entrypoint
    blah
    
```

