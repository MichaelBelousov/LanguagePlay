
/* This is very early/broken, I'm very new to scanner generation */
/* I plan on using RE/flex for C++, linked with the lex output */

/* Defs */

/*
{%
#include <stdio.h>
%}
%option noyywrap
*/

ident               [_a-zA-Z][_a-zA-Z0-9]*
string_content      [.|\n]*[^\\]

%%


/*** operators ***/

"<"             return op_rangle
"<="            return op_lteq
"=="            return op_eq
"#="            return op_ptreq
"<=>"           return spaceship
"~="            return op_approxeq
"~"             return op_similar
"!="            return op_neq
">="            return op_gteq
">"             return op_langle
"+"             return op_plus
"-"             return op_minus
"*"             return op_times
"/"             return op_div
"//"            return op_divfloor
"%"             return op_percent
"mod"           return op_mod
"^^"            return op_pow
"^/"            return op_root
":"             return op_type
"has"           return op_has
"is"            return op_is
"&"             return op_and
"|"             return op_or
"^"             return op_xor
">>"            return op_rshift
"<<"            return op_lshift
"->"            return op_implies
"="             return op_assign
"+="            return op_assignplus
"-="            return op_assignminus
"*="            return op_assigntimes
"/="            return op_assigndiv
"//="           return op_assigndivfloor
"^^="           return op_assignpow
"^/="           return op_assignroot
"&="            return op_assignand
"|="            return op_assignor
">>="           return op_assignrshift
"<<="           return op_assignlshift
"->="           return op_assignimplies
"$"             return op_assign
"<-"            return op_larrow
"..."           return op_ellipse
"in"            return op_in
"contains"      return op_contains
"assert"        return op_assert
"["             return op_lbrack
"]"             return op_rbrack
"("             return op_lpar
")"             return op_rpar
"."             return op_dot
","             return op_comma
"=>"            return op_bigrarrow
"?"             return op_ques
"if"            return keyword_if
"else"          return keyword_else
"elif"          return keyword_elif
"for"           return keyword_for
"while"         return keyword_while
"until"         return keyword_until
"try"           return keyword_try
"catch"         return keyword_catch
"throw"         return keyword_throw
"with"          return keyword_with
"struct"        return keyword_struct
"class"         return keyword_class
"const"         return keyword_const
"typeof"        return keyword_typeof
"cloneof"       return keyword_cloneof
"import"        return keyword_import


{ident} {
}

/*** literals ***/

/* int literals */
-?[1-9][0-9]*   return lit_int

/* float literal */
(-?[1-9][0-9]*\.[0-9+])([Ee][+-?][1-9][0-9]*)?  return lit_float

/* byte literals */
0x[0-9a-fA-F]   return lit_byte

/* bit literal */
0b[01]  return lit_bit

/* octal literal */
0o[0-7]     return lit_octal

/* string literal */
\"{string_content}\"    return lit_str

/* raw string literal */
\`{string_content}\`    return lit_strraw

/* */


%%

Lexeme emit {
}

int main()
{
    yylex();
    return 0;
}
