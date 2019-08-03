
# Practical Examples

-----------------------

## C++


#### Add copyright notice

````
@.
@^^
>>>
```
// Copyright SomeCompany 2019
```
````

#### Extract named class methods to interface and implementation

```
## capture class by regex
class $/NameOfClass/class . $func (
## use it to create a new interface
  >>> struct NewInterface . virtual $func (
  ;;; $class . $func override
## make the captures class implement the new interface
>>> class $class : NewInterface
```

-----------------------

## Python

-----------------------

## JavaScript

#### Replace all `+` concatenated strings with formatted multiline strings

```
## directives for simpler conversion
#=str   std::string
#$a     conversions.includes=str op.add.ret.type=str

## transformation
`$a + $...rest`
>>> ` \`\${a} \${rest} \` `
```
