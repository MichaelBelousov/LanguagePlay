
#ifndef FLUSTER_BISON_PARSER_H
#define FLUSTER_BISON_PARSER_H

#include "parse.h"

struct Expr
{
    using Ptr = Expr*;
    toks::TokenType type;
    void* value;  //use RTTI?
    Ptr* left;
    Ptr* right;
    Expr(toks::TokenType in_type, void* in_value, 
            Ptr* in_left, Ptr* in_right);
};


#endif //FLUSTER_BISON_PARSER_H
