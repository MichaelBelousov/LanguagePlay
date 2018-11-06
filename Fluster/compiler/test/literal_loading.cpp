/*
 * C++ test cases for literal loading
 */

#include <iostream>
#include <cstdio>

#include "lexer_routines.h"
#include "parser.h"

int assert(bool result, const std::string& msg)
{
    if (!result)
    {
        std::cerr << msg << std::endl;
        exit(100);
    }
}

bool test_hex_standard1() {
    //still need to decide on endianness...
    char expected[] = {0x0a, 0x0f,0x5c};
    auto actual= make_HEXBYTES("0xa0f5c")
    for (int i = 0; i < 3; ++i)
        if (actual[i] != expected[i])
        {
                std::cerr << actual[i] 
                          << " != " 
                          << expected[i] 
                          << std::endl;
                return false;
        }
}

int main(int argc, char* argv[])
{
    assert(test_hex_standard1(), std::string("failed loading 0xa0f5c"));
}
