
# Laziness

streams are the basis for generation/generators and laziness

{0,1}^^2 = {t[0,0], t[0,1], t[1,0], t[1,1]} 

## Streams

```TypeScript

Nats = Stream<[count=0]() => count++>
nats = Nats()

// you can use a capture list or last-output argument
// to maintain a state
boolflip = Stream<(last) => not last, 0>

evens = Filter<nats, (a) => a&1==0>()
odds  = Filter<nats, (a) => a&1==1>()

a, b, c, ...rest = odds
a == 1
b == 3
c == 5
rest == Filter<nats, (a) => a&1==1, _last=5>  //rest is the stream after the state change

```
