
/*** RE/flex Preamble ***/

/*** Definitions ***/


id                  [_a-zA-Z][_a-zA-Z0-9]*
digit               [0-9]
bit                 [01]
hex                 [0-9a-fA-F]
octal               [0-7]
decnum_start        [1-9]+
decint              {decnum_start}{digit}*
any                 .|\n
string_content      {any}*[^\\]


/*** Options***/

%o debug
%o outfile="lexer.cpp"
%o lexer=Lexer
%o noyywrap nounput noinput batch debug
%o tabs=4


%%


/*** operators ***/

"<"             return LESS_THAN
"<="            return LESS_THAN_OR_EQUAL
"="             return EQUAL
"!="            return NOT_EQUAL
"<="            return GREATER_THAN_OR_EQUAL
"<"             return GREATER_THAN
"\""            return QUOTE
"\\"            return WRAP
"#"             return CONDITION
":"             return OTHERWISE
"?"             return THEN
"$"             return CONTEXT

"\S*"           return any


/*** miscellaneous ***/

/* multiline comment */
"/*"(.|\n)*?"*/"                            #ignore

/* to eol comment */
"//".*                                      #ignore

/* eof */
<<EOF>>                                     return make_END


%%
