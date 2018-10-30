
/* Defs */

%top{
#include <string>
#include <memory>

//move this to a seperate translation unit and link
struct Lexeme {
    template<typename T, typename String>
    Lexeme(T in_type, String&& in_source)
        : type(static_cast<int>(in_type))
        , source(std::forward(in_source)) {}
    int type;
    std::string source;
};

namespace toks {

    //namespace spc {
    enum spc {
        newline,
        tab,
        indent_space
    }; //};

    enum ops {
        rangle = indent_space+1,
        lteq,
        eq,
        ptreq,
        approxeq,
        spaceship,
        similar,
        neq,
        gteq,
        langle,
        plus,
        minus,
        times,
        div,
        divfloor,
        percent,
        mod,
        pow,
        root,
        type,
        has,
        is,
        and_,
        or_,
        xor_,
        rshift,
        lshift,
        implies,
        assign,
        assignplus,
        assignminus,
        assigntimes,
        assigndiv,
        assigndivfloor,
        assignpow,
        assignroot,
        assignand,
        assignor,
        assignrshift,
        assignlshift,
        assignimplies,
        larrow,
        ellipse,
        in,
        contains,
        assert,
        lbrack,
        rbrack,
        lpar,
        rpar,
        dot,
        comma,
        bigrarrow,
        ques,
    };

    enum kwords {
        if_ = ques+1,
        else_,
        elif_,
        for_,
        while_,
        until_,
        try_,
        catch_,
        throw_,
        with_,
        struct_,
        class_,
        const_,
        typeof_,
        cloneof_,
        import_,
        export_
    };

    enum lits {
        int_ = export_+1,
        float_,
        byte_,
        bit_,
        octal_,
        string_,
        string_raw_
    };
};

%}

%class{
    int block_step;
    bool block_step_set;
    int current_depth;
    //line_depth //(for string dedenting)
%}

%init{
    block_step = 0;
    block_step_set = false;
    current_depth = 0;
%}

ident               [_a-zA-Z][_a-zA-Z0-9]*
digit               [0-9]
bit                 [01]
hex                 [0-9a-fA-F]
octal               [0-7]
decnum_start        [1-9]+
decint              {decnum_start}{digit}*
any                 .|\n
string_content      {any}*[^\\]

%%

/*** indentation ***/

\n      return toks::newline;
\t      return toks::tab;
^" "*   return toks::indent_space;

/*** operators ***/

"<"             return toks::rangle;
"<="            return toks::lteq;
"=="            return toks::eq;
"#="            return toks::ptreq;
"<=>"           return toks::spaceship;
"~="            return toks::approxeq;
"~"             return toks::similar;
"!="            return toks::neq;
">="            return toks::gteq;
">"             return toks::langle;
"+"             return toks::plus;
"-"             return toks::minus;
"*"             return toks::times;
"/"             return toks::div;
"//"            return toks::divfloor;
"%"             return toks::percent;
\<mod\>         return toks::mod;
"^^"            return toks::pow;
"^/"            return toks::root;
":"             return toks::type;
\<has\>         return toks::has;
\<is\>          return toks::is;
"&"             return toks::and_;
"|"             return toks::or_;
"^"             return toks::xor_;
">>"            return toks::rshift;
"<<"            return toks::lshift;
"->"            return toks::implies;
"="             return toks::assign;
"+="            return toks::assignplus;
"-="            return toks::assignminus;
"*="            return toks::assigntimes;
"/="            return toks::assigndiv;
"//="           return toks::assigndivfloor;
"^^="           return toks::assignpow;
"^/="           return toks::assignroot;
"&="            return toks::assignand;
"|="            return toks::assignor;
">>="           return toks::assignrshift;
"<<="           return toks::assignlshift;
"->="           return toks::assignimplies;
"$"             return toks::assign;
"<-"            return toks::larrow;
"..."           return toks::ellipse;
\<in\>          return toks::in;
\<contains\>    return toks::contains;
\<assert\>      return toks::assert;
"["             return toks::lbrack;
"]"             return toks::rbrack;
"("             return toks::lpar;
")"             return toks::rpar;
"."             return toks::dot;
","             return toks::comma;
"=>"            return toks::bigrarrow;
"?"             return toks::ques;
\<if\>          return toks::if_;
\<else\>        return toks::else_;
\<elif\>        return toks::elif_;
\<for\>         return toks::for_;
\<while\>       return toks::while_;
\<until\>       return toks::until_;
\<try\>         return toks::try_;
\<catch\>       return toks::catch_;
\<throw\>       return toks::throw_;
\<with\>        return toks::with_;
\<struct\>      return toks::struct_;
\<class\>       return toks::class_;
\<const\>       return toks::const_;
\<typeof\>      return toks::typeof_;
\<cloneof\>     return toks::cloneof_;
\<import\>      return toks::import_;


{ident} {
}

/*** literals ***/

/* int literals */
{decint}                                    return toks::int_;

/* float literal */
{decint}(\.{digit}+)?([Ee][+-]?{decint})?   return toks::float_;

/* byte literals */
0x{hex}*                                    return toks::byte_;

/* bit literal */
0b{bit}*                                    return toks::bit_;

/* octal literal */
0o{octal}                                   return toks::octal_;

/* string literal */
\"{string_content}\"                        return toks::string_;

/* raw string literal */
\`{string_content}\`                        return toks::string_raw_;

/* multiline comment */
"/*"(.|\n)*?"*/"                            return 0;

/* eol comment */
"//".*                                      return 0;

/* eof */
<<EOF>>                                     return 0;

%%

int main()
{
    return Lexer().lex();
}
