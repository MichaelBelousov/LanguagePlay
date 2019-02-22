
# Sizr

A generic source pattern matching language focused on the C language family
with an emphasis on terseness but completeness, ala regular expressions

Lift all functions prefixed with "log\_" to a class named logger
```Cpp
func "log_$" (
>>>
class Logger :: $
```

Lift a global to the same class

```Cpp
:: log_file_path
>>>
class Logger :: $
```

Lift an implementation constant

```Cpp
func "log_*" ( { `flags.write | flags.append`
>>>
class Logger :: var log_write_flags = $
```


