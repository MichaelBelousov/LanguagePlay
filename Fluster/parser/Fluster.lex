
/* This is very early/broken, I'm very new to scanner generation */
/* I plan on using RE/flex for C++, linked with the lex output */

/* Defs */

{%
#include <stdio.h>
%}

%option noyywrap
%option c++

ident               [_a-zA-Z][_a-zA-Z0-9]*
string_content      [.|\n]*[^\]

%%
/*** Rules ***/

{ident} {
}

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
"if"            return stmt_if
"else"          return stmt_else
"elif"          return stmt_elif
"for"           return stmt_for
"while"         return stmt_while
"until"         return stmt_until
"try"           return stmt_try
"catch"         return stmt_catch
"throw"         return stmt_throw
"with"          return stmt_with
"struct"        return stmt_struct
"class"         return stmt_class
"const"         return stmt_const
"typeof"        return stmt_typeof
"cloneof"       return stmt_cloneof
"import"        return stmt_import

/*** literals ***/

/* int literals */
-?[1-9][0-9]* {
}

/* float literal */
(-?[1-9][0-9]*\.[0-9+])([Ee][+-?][1-9][0-9]*)? {
}

/* byte literals */
0x[0-9a-fA-F] {
}

/* bit literal */
0b[01] {
}

/* octal literal */
0o[0-7] {
}

/* string literal */
\"{string_content}\" {
}

/* raw string literal */
\`{string_content}\` {
}

/* lbrack */
"[" {
}

/* rbrack */
"]" {
}


/* */


%%

void* setUpBuffer(char const* text)
{
    YY_BUFFER_STATE buffer  = yy_scan_string(text);
    yy_switch_to_buffer(buffer);

    return buffer;
}

void tearDownBuffer(void* buffer)
{
    yy_delete_buffer((YY_BUFFER_STATE)buffer);
}

int main()
{
    yylex();
    return 0;
}
