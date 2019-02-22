
# Static Reflection

## struct

*`_outer: Scope`*

*`_is: []Type`*
*`_has: []Type`*
*`_fields: [](Name, Type)`*
*`_conversions_to: {Name=Func<This>}`*
*`_functions: {Name=Func<...>}`*
*`_methods: {Name=Func<This,...>}*
*`_ops: {...}`*
*`_is_final: bool*

## class

*`_outer: Scope`*

*`_is: []Type`*
*`_has: []Type`*
*`_fields: [](Name, Type)`*
*`_conversions_to: {Name=Func<This>}`*
*`_functions: {Name=Func<...>}`*
*`_methods: {Name=Func<This,...>}*
*`_ops: {...}`*
*`_is_final: bool*

## variable

*`_type: Type`*
*`_outer: Scope`*

## function

*`_type: Type`*
*`_outer: Scope`*

*`_params: [](Name, Type)`*
*`_is_variadic: bool*
*`_return_type: Type`*

## method

*`_type: Type`*
*`_outer: Scope`*

*`_params: [](Name, Type)`*
*`_is_variadic: bool*
*`_return_type: Type`*

*`_overrided: Method`*
