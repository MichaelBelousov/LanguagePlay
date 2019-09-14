
# Practical Examples

-----------------------

## C++


```
name: '$value'

class: 
'''
$attributes
class $name $finality {
    /// Private Fields
    $members[...]
    $members[private|protected][callable][!static]

    /// Interface
    $members[public][callable]
    $members[public][...]

    $members[static][callable]
    $members[static][...]

    /// Construction
    $members[constructors]
    $members[constructors]
};
'''

member:
'$value\n'

member_variable:
'''
$type $name _ #=type[, $name]
'''

```

<!-- //how to allow?
struct {
    float x, y, z;
};

perhaps the above collapse clause operator?

#=type[EXPR]  (collapse on types are equal, where EXPR is the collapsed format)

is extendable to collapse on other properties with other operators i.e. <,~,!, etc...

-->
