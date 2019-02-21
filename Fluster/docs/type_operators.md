
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
s: Person & ListNode
```
