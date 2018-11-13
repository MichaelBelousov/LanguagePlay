
#include <cmath>

#include <cmath>

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

yy::parser::symbol_type 
make_DECIMINTEGER (const std::string &s, const yy::parser::location_type& loc)
{
    errno = 0;
    long long n = strtoll (s.c_str(), NULL, 10);
    if (! (INT_MIN <= n && n <= INT_MAX && errno != ERANGE))
        throw yy::parser::syntax_error (loc, "integer is out of range: " + s);
    return yy::parser::make_NUMBER(n, loc);
}

yy::parser::symbol_type 
make_DECIMFLOAT(const std::string &s, const yy::parser::location_type& loc) {
}

/* byte literals */
yy::parser::symbol_type 
make_HEXBYTES (const std::string &s, const yy::parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<16>(s, "0x");
    yylval.bytes = Buffer.bytes;
    return toks::lits::byte_;
}
yy::parser::symbol_type 
make_BINARYBITS (const std::string &s, const yy::parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<2>(s, "0b");
    yylval.bytes = bytes;
    return toks::lits::bit_;
}

yy::parser::symbol_type 
make_OCTALBITS (const std::string &s, const yy::parser::location_type& loc)
{
    auto Buffer = loadAsciiBitLiteral<8>(s, "0o");
    yylval.bytes = Buffer.bytes;
    return toks::lits::oct_;
}

//yy::parser::symbol_type 
//make_STRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_UNICODESTRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_RAWSTRING (const std::string &s, const yy::parser::location_type& loc);
