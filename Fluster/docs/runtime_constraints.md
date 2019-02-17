
# Runtime Type Constraints

suppose you have a numeric type, such as temperature which must be > -273

```TypeScript
type Celsius
    is float32
    constraint (this: &This)
        this >= -273.3

room_temp: Celsius = 20
```

The constraints can be compiled in in debug mode and caught as exceptions, but otherwise
the constraints are assumed to be met by other code treating it correctly
