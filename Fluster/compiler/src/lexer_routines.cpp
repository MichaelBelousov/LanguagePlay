
  yy::parser::symbol_type 
  make_DECIMINTEGER (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_DECIMFLOAT(const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_HEXBYTES (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_BINARYBITS (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_OCTALBITS (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_STRING (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_UNICODESTRING (const std::string &s, const yy::parser::location_type& loc);
  yy::parser::symbol_type 
  make_RAWSTRING (const std::string &s, const yy::parser::location_type& loc);

/* byte literals */
0x{hex}*    {
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

/* bit literal */
0b{bit}*    {
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

/* octal literal */
0o{octal}   {
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
    yylval.bytes = bytes;
    return toks::lits::byte_;
}

/* string literal */
\"{string_content}\"                        return toks::lits::string_;

/* unicode literal */
u\"(?u:{string_content})\"                  return toks::lits::string_unicode_;

/* raw string literal */
\`{string_content}\`                        return toks::lits::string_raw_;



/*** miscellanious ***/


/* multiline comment */
"/*"(.|\n)*?"*/"                            //ignore

/* eol comment */
"//".*                                      //ignore

/* eof */
<<EOF>>                                     return -1;



/*** indentation ***/

^\h*\i          return toks::spc::indent;

^\h*\j          return toks::spc::outdent;

\j              return toks::spc::outdent;

(?^\\\n\h*)     //ignore space after line-end backslash

\\              return toks::spc::indent; //add indent after in-line backslash


/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
%%
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 


int main()
{
    return Lexer().lex();
}

