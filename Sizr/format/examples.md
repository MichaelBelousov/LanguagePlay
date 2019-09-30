
# Practical Examples

-----------------------

So the goal of this "layout language" is just to allow _some_
restrictions and deterministic layout of language constructs. For instance,
it is impossible for the formatter to be able to tell that a programmer would
want the following member variable groupings, unless the programmer explicitly used
some type alias to separate them:

```Cpp
struct Vert {
    float x, y, z;
    float r, g, b; //vert color
};
```

It is plausible that type aliases be an idiom for separating such:

```Cpp
typedef float ColorChannel;
struct Vert {
    float x, y, z;
    ColorChannel r, g, b;
};
```

## C++


```
name: '$value'

class:
'''
$attributes
class $name $finality {
    /// Private Interface
    $members...
    $members[private|protected][callable][!static]...

    /// Interface
    $members[public][callable]...
    $members[public][...]

    $members[static][callable]...
    $members[static][...]

    /// Construction
    $members[constructors]
    $members[constructors]
};
'''

member:
'$value'

member_variable_decl:
'''
$type $name#(==type[, $name]);
'''

assigning_decl:
'''
$type $name = \
    $expr
'''

assigning_decl:
'''
$type $name = \
"\n" $expr
#\1?"\n";
'''

tuple:
'''
[" " #wraps?"\n" $vals #wraps?"\n" " "]
'''

comma_list:
'''
$first #rest.len>0?"," #wraps?"\n":\ " " $rest
'''


binary_op:
'''
$left \?" " > "  " $op " " $right
'''

```

```

// elm format
function_call:
'''
$func " " ( $args #wraps?"\n":" " )
'''

// elm format
func_args:
'''
#i!=1?"," " " $first #wraps?"\n":\ $rest
'''

```

* the `$` operator gets the value of a key in the context
* the `#COND?IF:ELSE` ternary condition has optional ?IF and :ELSE branches
* the `""` operator inserts literal text, often used for whitespace which is usually ignored
* the `\` operator inserts a wrap break, which allows text to wrap by breaking at that point,
  it can also be followed by a ternary expression based on whether it was or wasn't inserted, e.g. `\?"x":"xy"`
* the `#\1` condition where 1 could be replaced with any number is a backreference to the expressions'
  wrap breaks. It yields true if a break was inserted at that wrap break.
* the `>` operator asserts the indentation level to the previous lines'


<!-- //how to allow?
struct {
    float x, y, z;
};

perhaps the above collapse clause operator?

#=type[EXPR]  (collapse on types are equal, where EXPR is the collapsed format)

is extendable to collapse on other properties with other operators i.e. <,~,!, etc...

-->

## Implementation plan:
- prototype in Python3
- rewrite in either Go, Rust, or Haskell
