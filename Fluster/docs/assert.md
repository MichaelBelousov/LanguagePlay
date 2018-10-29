
# Assertions

asserts are scopes in Fluster, with code that runs and must be satisfied

```TypeScript

struct IPLiteral
    is StringLiteral
    @static assert InvalidIPAddress
        all(
            map((x) => (x>= 0 & x < 256),
                map(parse.int, 
                    this.content.split('.'))))

```

They can be made static by existing in a static scope, and they are named.
