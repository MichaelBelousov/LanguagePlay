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
    unsigned int bytes_len;
    unsigned int length;
    unsigned char* bytes;
    BitBuffer(int in_bits)
        : bytes_len(std::ceil(in_bits/8.f))
        , length(in_bits)
        , bytes(new unsigned char[bytes_len])
    {
        std::memset(bytes, 0, sizeof(unsigned char)*bytes_len);
    }
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
    cuint left_bound = bit_offset % 8;
    cuint right_byte_id = (bit_offset-1+bits_len)/8;
    cuint right_bound = (bit_offset-1+bits_len) % 8;

    if (left_byte_id == right_byte_id)
    {
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
    }
    else
    {
        bytes[right_byte_id] |= bits << (8-(right_bound+1));
        bytes[left_byte_id] |= bits >> (left_bound - (8-bits_len));
    }
}


//TODO: bake prefix into template param? too bad it's a string...
template<int base>
BitBuffer loadAsciiBitLiteral(const std::string& literal, const std::string& prefix)
{
    static_assert(base <= 36, "only 26 letters + 10 numbers supported");

    const int bits_per_char = std::log2(base);
    const int bit_amt = (literal.length() - prefix.length()) * bits_per_char;
    const int byte_amt = std::ceil(bit_amt/8.f);

    auto result = BitBuffer(bit_amt);

    const int bit_padding = (byte_amt*8) - bit_amt;
    int depth = bit_padding;
    for (auto itr = literal.cbegin()+prefix.length(); 
         itr != literal.cend();
         ++itr, depth+=bits_per_char)
    { 
        unsigned char bits;
        if (*itr  <= 57) //is an ascii number
             bits = *itr  - 48;
        else            //is an ascii letter
            bits = (*itr | (1<<5)) - 87;
        setBits(depth, bits_per_char, bits, result.bytes);
    }
    return result;
}

bool test_hex_standard1() {
    //still need to decide on endianness...
    std::cout << ("testing 0x0a0f5c...") << std::endl;
    bool result = true;
    unsigned char expected[] = {0x0a, 0x0f, 0x5c};
    auto actual = loadAsciiBitLiteral<16>("0x0a0f5c", "0x");
    for (int i = 0; i < 3; ++i)
        if (actual.bytes[i] != expected[i])
        {
            std::cerr << Bits(actual.bytes[i])
                      << " != " 
                      << Bits(expected[i])
                      << std::endl;
            result = false;
        }
    if (result) std::cout << ("test successful") << std::endl;
    return result;
}

bool test_oct_standard1() {
    std::cout << ("testing 0o777...") << std::endl;
    bool result = true;
    unsigned char expected[] = {01, 0377};
    auto actual = loadAsciiBitLiteral<8>("0o777", "0o");
    for (int i = 0; i < 2; ++i)
        if (actual.bytes[i] != expected[i])
        {
            std::cerr << "byte " << i << ": "
                      << Bits(actual.bytes[i])
                      << " != " 
                      << Bits(expected[i])
                      << std::endl;
            result = false;
        }
    if (result) std::cout << ("test successful") << std::endl;
    return result;
}

bool test_bin_standard1() {
    auto test_str = "0b100101";
    std::cout << "testing " << test_str << std::endl;
    bool result = true;
    unsigned char expected[] = {045};
    auto actual = loadAsciiBitLiteral<2>(test_str, "0b");
    for (int i = 0; i < 1; ++i)
        if (actual.bytes[i] != expected[i])
        {
            std::cerr << "byte " << i << ": "
                      << Bits(actual.bytes[i])
                      << " != " 
                      << Bits(expected[i])
                      << std::endl;
            result = false;
        }
    if (result) std::cout << ("test successful") << std::endl;
    return result;
}


int do_assert(bool result, const std::string& msg)
{
    if (!result)
    {
        std::cerr << msg << std::endl;
        exit(100);
    }
    return 0;
}


int main(int argc, char* argv[])
{
    int failed = 0;
    failed += do_assert(test_hex_standard1(), 
                        "failed loading 0xa0f5c");
    failed += do_assert(test_oct_standard1(), 
                        "failed loading 0o777");
    failed += do_assert(test_bin_standard1(), 
                        "failed loading 0b100101");

    if (!failed)
        std::cout << "passed all tests" << std::endl;
}
