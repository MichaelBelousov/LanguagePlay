
#include <cmath>

struct BitBuffer
{
    int length;
    char* bytes;
    BitVuffer(int in_bits)
        : length(in_bits)
        , bytes(new char[std::ceil(in_bits/8.f)])
    {}
    ~BitBuffer() { delete[] bytes; }
};

//XXX: assumes the bits are unset, would need masking otherwise
setBits(unsigned bit_offset, int bits_len, char bits, char bytes[])
{
    using cuint = const unsigned;
    cuint left_byte_id = bit_offset/8;
    cuint left_bound = bit_offset % 8;
    cuint right_byte_id = (bit_offset+bits_len)/8;
    cuint right_bound = (bit_offset+bits_len) % 8;

    if (left_byte_id == right_byte_id)
    {
        bytes[right_byte_id] |= bits << right_bound;
    }
    else
    {
        bytes[right_byte_id] |= bits << right_bound;
        bytes[left_byte_id] |= bits >> 8-left_bound;
    }
}


template<int base>
BitBuffer loadAsciiBitLiteral(const std::string& literal, const std::string& prefix)
{
    static_assert(base <= 36, "only 26 letters + 10 numbers supported");

    const int bits_per_char = std::log2(base);
    const int bit_amt = (literal.length() - prefix.length()) * bits_per_char;
    const int byte_amt = ceil(bit_amt / 8);

    auto result = BitBuffer(bit_amt);

    int depth = 0;
    for (auto itr = literal.cbegin(); 
         itr != literal.cend();
         ++itr, depth+=bits_per_char)
    { 
        char bits;
        if (p[i] <= 57) //is an ascii number
             bits = p[i] - 48
        else            //is an ascii letter
            bits = (p[i] | (1<<5)) - 87
        setBits(depth, bit_per_char, bits, result.bytes)
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
    return yy::parser::make_NUMBER (n, loc);
}

yy::parser::symbol_type 
make_DECIMFLOAT(const std::string &s, const yy::parser::location_type& loc);

/* byte literals */
yy::parser::symbol_type 
make_HEXBYTES (const std::string &s, const yy::parser::location_type& loc)
{
    char bytes[] = new char[ceil((strlen(text())-2)/2.0)];
    bool do_load = false; //could move this to the oddness of i
    char byte;
    for (int i = 0; p[i]; ++i, commit = !commit) 
    { 
        char val;
        if (do_load) {  //we're loading the first hex numeral
            if (p[i] <= 57) //is an ascii number
                val = p[i] - 48;
            else            //is an ascii letter
                val = (p[i] | (1<<5)) - 87;
            byte = val;
        }
        else {
            if (p[i] <= 57) //is an ascii number
                val = p[i] - 48
            else            //is an ascii letter
                val = (p[i] | (1<<5)) - 87;
            byte |= val << 4;  //add the more significant nibble
            bytes[i/2] = byte;  //relying on floor division
        }
    }
    yylval.bytes = bytes;
    return toks::lits::byte_;
}
yy::parser::symbol_type 
make_BINARYBITS (const std::string &s, const yy::parser::location_type& loc)
{
    //FIXME: untested and I may have loaded the byte stream backwards
    //just use rshift and reverse the process. Maybe make all this
    //repetitive code into a procedure, too
    char bytes[] = new char[ceil((strlen(text())-2)/8.0)];
    char byte;
    //TODO: replace depthmax literal with constexpr var
    for (int i=0, depth=0; p[i]; ++i, depth=(++depth%8))
    { 
        byte |= (p[i] - 48) << depth;
        //TODO: package in a lambda for reuse
        if (depth == 7) {
            bytes[i/2] = byte; //relying on floor division
            byte = 0;
        }
    }
    if (depth) {
        bytes[i/2] = byte; //relying on floor division
        byte = 0;
    }
    yylval.bytes = bytes;
    return toks::lits::bit_;
}

yy::parser::symbol_type 
make_OCTALBITS (const std::string &s, const yy::parser::location_type& loc)
{
    //FIXME: untested and I may have loaded the byte stream backwards
    //TODO: account for endianness
    char bytes[] = new char[ceil((strlen(text())-2)/3.0)];
    char* head = bytes;
    char word[4];  //32 bit buffer for 24 bit chunks
    int& wordval = reinterpret_cast<int&>(&wordbyte);
    //TODO: replace depthmax literal with constexpr var
    for (int i=0, depth=0; p[i]; ++i, depth=(++depth%8))
    { 
        //TODO: package in a lambda for reuse
        wordval |= (p[i] - 48) << depth*3;
        if (depth == 7) {
            head[i] = word[0];
            head[i+1] = word[1];
            head[i+2] = word[2];
            wordval = 0;
            head += 3;
        }
    }
    //FIXME: optimize using a lambda or (god-forbid) a **label+goto**
    if (depth) {
        //FIXME: switch to full 32-bit word load
        head[i] = word[0];
        head[i+1] = word[1];
        head[i+2] = word[2];
        wordval = 0;
        head += 3;
    }
    return bytes;
}

//yy::parser::symbol_type 
//make_STRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_UNICODESTRING (const std::string &s, const yy::parser::location_type& loc);

//yy::parser::symbol_type 
//make_RAWSTRING (const std::string &s, const yy::parser::location_type& loc);
