
# Arrays

everything about arrays

## Array Type

Arrays are a parametric type, `int[]` is not a legal type, since
no length (the parameter) is provided.

```TypeScript
a: int[3] = [1,2,3]            //legal, identical array lengths 
                                //(and types)
b: int[3] = [1,2,3,4]          //illegal, wrong length
c: int[2], ...rest = [1,2,3,4] //legal, pack expression divides array
d: int[0]                       //legal, length is defined; default init
e: char[] = 'hello'             //legal, length is inferred
f: char[] = ['a', 'b', 'c']    //legal, length is inferred
g: byte[] = 0x00ffbef82         //legal, length is inferred
h: int[]                        //illegal, length is not inferred or given
```
