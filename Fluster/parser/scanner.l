
/* Defs */

/*%o outfile="lexer_core.cpp" header-file="lexer_core.h"*/
%o noyywrap 
%o bison

%top{
  /*#include "y.tab.h"*/
  #define YY_EXTERN_C extern "C"
  #define YYSTYPE int
  #include "parser.h"
%}

%class{
  static const int tab_width = 2;
  int scope_depth;
  private:
    int column;
  public:
    setColumn(int in_col);
%}

%init{
  scope_depth = 0;
  column = 1;
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

/*** States ***/

%x <Start>
%x <ScanIndent>
%x <Normal>

%%

/*** indentation ***/

\n      return toks::newline;
\t      return toks::tab;
^" "*   return toks::space;
^\h*\i  return toks::indent;
^\h*\j  return toks::outdent;

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
"*"             return toks::star;
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
