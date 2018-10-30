
#include "bison_parse.h"

Expr::Expr(toks::TokenType in_type, void* in_value, 
            Ptr* in_left, Ptr* in_right)
    : type(in_type)
    , value(in_value)
    , left(in_left)
    , right(in_right) {}

