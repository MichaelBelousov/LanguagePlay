
#include <iostream>

struct Lexeme
{
};

struct Construct
{
};

//something like
Construct() = { "[", Commalist, "]", 
                "(", Commalist, ")", 
                "=>",
                Expr};

