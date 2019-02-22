
# type operators

```TypeScript
//mutable type
x: !int
//array of type
arr: []int
//reference of type
r: &int = x
//reference to?
r2: & = x
//pointer to?
p: *int = #x
//structural union
q: Pickupable | Targetable

//structural intersection (disjunction)
LinkedList<T> = T & {next_node: *T}
s: LinkedList<Person>

x: ! = 100
y: []!float = [1.2, 0, 3.4, -1.2e24]
horror: &[]!float = y
better: & = y
```
