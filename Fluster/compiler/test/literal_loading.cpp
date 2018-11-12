/*
 * C++ test cases for literal loading
 */

#include <iostream>
#include <cstdio>
#include <cmath>

//#include "lexer_routines.h"
//#include "parser.h"

struct Bits
{
    char _;
    Bits(char __): _(__) {}
};

std::ostream& operator<<(std::ostream& os, Bits b) 
{
    for (int i = 0; i < 8; ++i) {
        os << static_cast<int>(b._ >= 0x80);
        b._ <<= 1;
    }
    return os;
}

struct BitBuffer
{
    unsigned int length;
    unsigned char* bytes;
    BitBuffer(int in_bits)
        : length(in_bits)
        , bytes(new unsigned char[std::ceil(in_bits/8.f)])
    {}
    ~BitBuffer() { delete[] bytes; }
};

std::ostream& operator<<(std::ostream& os, const BitBuffer& b) 
{
    for (int i = 0; i < std::ceil(b.length/8); ++i) 
        os << Bits(b.bytes[i]);
    return os;
}


//XXX: assumes the bits are unset, would need masking otherwise
void setBits(unsigned bit_offset, unsigned int bits_len, unsigned char bits, unsigned char bytes[])
{
    using cuint = const unsigned;
    cuint left_byte_id = bit_offset/8;
    std::cout << "left_byte_id"  << left_byte_id;
    cuint left_bound = bit_offset % 8;
    std::cout << "left_bound"  << left_bound;
    cuint right_byte_id = (bit_offset+bits_len)/8;
    std::cout << "right_byte_id"  << right_byte_id;
    cuint right_bound = (bit_offset+bits_len) % 8;
    std::cout << "right_bound"  << right_bound;
    std::cout << Bits(bits) << " ";

    if (left_byte_id == right_byte_id)
    {
        bytes[right_byte_id] |= bits << right_bound;
        std::cout << Bits(bytes[left_byte_id]) 
                 << std::endl;
    }
    else
    {
        bytes[right_byte_id] |= bits << right_bound;
        bytes[left_byte_id] |= bits >> (8-left_bound);
        std::cout << Bits(bytes[left_byte_id]) 
                 << Bits(bytes[right_byte_id])
                 << std::endl;
    }
}


template<int base>
BitBuffer loadAsciiBitLiteral(const std::string& literal, const std::string& prefix)
{
    static_assert(base <= 36, "only 26 letters + 10 numbers supported");

    const int bits_per_char = std::log2(base);
    const int bit_amt = (literal.length() - prefix.length()) * bits_per_char;
    const int byte_amt = std::ceil(bit_amt / 8);

    auto result = BitBuffer(bit_amt);

    int depth = 0;
    for (auto itr = literal.cbegin()+prefix.length(); 
         itr != literal.cend();
         ++itr, depth+=bits_per_char)
    { 
        //std::cout << result << std::endl;
        unsigned char bits;
        if (*itr  <= 57) //is an ascii number
             bits = *itr  - 48;
        else            //is an ascii letter
            bits = (*itr | (1<<5)) - 87;
        std::cout << *itr << " " << static_cast<int>(bits) << " ";
        setBits(depth, bits_per_char, bits, result.bytes);
    }
    return result;
}

auto make_HEXBYTES = [](const std::string& literal){
    return loadAsciiBitLiteral<16>(literal, "0x");
};

int do_assert(bool result, const std::string& msg)
{
    if (!result)
    {
        std::cerr << msg << std::endl;
        exit(100);
    }
    return 0;
}

bool test_hex_standard1() {
    //still need to decide on endianness...
    std::cout << ("0x0a0f5c") << std::endl;
    unsigned char expected[] = {0x0a, 0x0f, 0x5c};
    auto actual = make_HEXBYTES("0x0a0f5c"); //a0f5c
    for (int i = 0; i < 3; ++i)
        if (actual.bytes[i] != expected[i])
        {
            std::cout << "actual: " 
                << Bits(actual.bytes[i]) 
                << std::endl;
            std::cout << "expected: " 
                << Bits(expected[i])
                << std::endl;
            std::cerr << static_cast<int>(actual.bytes[i])
                      << " != " 
                      << static_cast<int>(expected[i])
                      << std::endl;
            //return false;
        }
    return true;
}

int main(int argc, char* argv[])
{
    do_assert(test_hex_standard1(), 
            std::string("failed loading 0xa0f5c"));
}
