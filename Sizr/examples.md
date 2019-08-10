
# Practical Examples

-----------------------

## C++


#### Add copyright notice

````
>>>
@.
@^^
```
// Copyright SomeCompany 2019
```
````

#### Extract named class methods to interface and implementation

```
## Capture members of MyClass ( should better be a class but the query just asks for anything in global scope capable of having members and named "MyClass"
MyClass . $captured_func (
## create a new interface at a path
  >>> @./util/myclass_interface.hpp
      struct MyClassInterface . abstract $captured_func ( ## abstract is pure virtual in C++
## make the captures class implement the new interface
  ;;; MyClass : MyClassInterface
## make sure each captured function has the override property
  ;;; MyClass . override $captured_func

```

#### Move a class to a new namespace

```
class MyClass
```

-----------------------

## Python

-----------------------

## JavaScript

#### Replace all `+` concatenated strings with formatted multiline strings

```JavaScript
let hello = 'world ' + 5 + ' yum';
let _hello = `world ${5} yum`;
```

```
## directives for simpler conversion
#=str   std::string
#$a     conversions.includes=str op.add.ret.type=str

## transformation
`$a + $...rest`
>>> ` \`\${a} \${rest} \` `
```