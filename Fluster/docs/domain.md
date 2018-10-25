
type domains with conversion trees and promotion?

```TypeScript
domain Number
    int8, uint8 >
    int16, uint16 >
    int, int32, uint32 >
    int64, uint64 >
    integer >
    float32 >
    float64

convert a: int8 > int16
    //hexadecimals are bytestring literals, must be coerced to int
    //could do 0x0 too, as long as it isn't > 8 bits
    //assume network/TCP endian-ness? probably better 
    //to have a built-in
    bytes = 0x00, a   //hexadecimals are byte string literals

    return bytes(...a) to int16

```
