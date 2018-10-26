
# Enumerations

```TypeScript
enum Blah
    a
    b
    c
    h = 10

h == 10  //type error!

enum Blah: int32
    a
    b
    h = 10
    c

h == 10  //fine
```

comparable with declared types and if reflection is used,
the necessary code can be included/generated
