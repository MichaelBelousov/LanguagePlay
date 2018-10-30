
#ifndef FLUSTER_LEXER_PARSE_H
#define FLUSTER_LEXER_PARSE_H
#include <string>
#include <memory>

using cstr = char*;

//move this to a seperate translation unit and link
struct Lexeme {
    template<typename T, typename String>
    Lexeme(T in_type, String&& in_source)
        : type(static_cast<int>(in_type))
        , source(std::forward(in_source)) {}
    int type;
    const cstr source;
};

namespace toks {

    using TokenType = int;

    namespace spc { enum spc {
        newline,
        tab,
        indent_space
    }; };

    namespace { enum ops {
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
        star,
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
    }; };

    namespace { enum kwords {
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
    }; };

    namespace { enum lits {
        int_ = export_+1,
        float_,
        byte_,
        bit_,
        octal_,
        string_,
        string_raw_
    }; };
};


/*
 * ideally parallelizable parser
 * */
struct Parser
{
    struct Context
    {
    };
    Context ctx;

    void admitLexeme(const Lexeme& lexeme)
    {
    }
};

#endif //FLUSTER_LEXER_PARSE_H
