
#ifndef FLUSTER_LEXER_TOKENS_H
#define FLUSTER_LEXER_TOKENS_H

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
        indent,
        outdent
    }; };

    namespace ops { enum ops {
        rangle = spc::outdent+1,
        langleeq,
        doubleeq,
        hasheq,
        tildeeq,
        langleeqrangle,
        tilde,
        bangeq,
        rangleeq,
        langle,
        plus,
        dash,
        star,
        fslash,
        doublefslash,
        percent,
        caret,
        caretfslash,
        type,
        has,
        is,
        ampersand,
        pipe,

        doublerangle,
        doublelangle,
        dashrangle,
        eq,
        pluseq,
        dashwq,
        stareq,
        fslashwq,
        doublefslasheq,
        careteq,
        caretfslasheq,
        ampersandeq,
        pipeeq,
        doublerangleeq,
        doublelangleeq,
        dashrangleeq,
        langledash,
        dotdotdot,
        lbrack,
        rbrack,
        lbrace,
        rbrace,
        lpar,
        rpar,
        dot,
        comma,
        eqrangle,
        ques,
    }; };

    namespace kwords { enum kwords {
        in_ = ops::ques+1,
        contains_,
        assert_,
        mod_,
        if_,
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
        export_,
    }; };

    namespace lits { enum lits {
        int_ = kwords::export_+1,
        float_,
        byte_,
        bit_,
        octal_,
        string_,
        string_raw_
    }; };
};


#endif //FLUSTER_LEXER_TOKENS_H
