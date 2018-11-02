
/* Defs */

/*%o outfile="lexer.cpp" header-file="lexer.h"*/
%o noyywrap 
%o bison

%top{
  #define YY_EXTERN_C extern "C"
  #define YYSTYPE int
  #include "tokens.h"
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

\n      return toks::spc::newline;
\t      return toks::spc::tab;
^" "*   return toks::spc::space;
^\h*\i  return toks::spc::indent;
^\h*\j  return toks::spc::outdent;

/*** operators ***/

"<"             return toks::ops::rangle;
"<="            return toks::ops::lteq;
"=="            return toks::ops::eq;
"#="            return toks::ops::ptreq;
"<=>"           return toks::ops::spaceship;
"~="            return toks::ops::approxeq;
"~"             return toks::ops::similar;
"!="            return toks::ops::neq;
">="            return toks::ops::gteq;
">"             return toks::ops::langle;
"+"             return toks::ops::plus;
"-"             return toks::ops::minus;
"*"             return toks::ops::star;
"/"             return toks::ops::div;
"//"            return toks::ops::divfloor;
"%"             return toks::ops::percent;
\<mod\>         return toks::ops::mod;
"^^"            return toks::ops::pow;
"^/"            return toks::ops::root;
":"             return toks::ops::type;
\<has\>         return toks::ops::has;
\<is\>          return toks::ops::is;
"&"             return toks::ops::and_;
"|"             return toks::ops::or_;
"^"             return toks::ops::xor_;
">>"            return toks::ops::rshift;
"<<"            return toks::ops::lshift;
"->"            return toks::ops::implies;
"="             return toks::ops::assign;
"+="            return toks::ops::assignplus;
"-="            return toks::ops::assignminus;
"*="            return toks::ops::assigntimes;
"/="            return toks::ops::assigndiv;
"//="           return toks::ops::assigndivfloor;
"^^="           return toks::ops::assignpow;
"^/="           return toks::ops::assignroot;
"&="            return toks::ops::assignand;
"|="            return toks::ops::assignor;
">>="           return toks::ops::assignrshift;
"<<="           return toks::ops::assignlshift;
"->="           return toks::ops::assignimplies;
"$"             return toks::ops::assign;
"<-"            return toks::ops::larrow;
"..."           return toks::ops::ellipse;
"["             return toks::ops::lbrack;
"]"             return toks::ops::rbrack;
"("             return toks::ops::lpar;
")"             return toks::ops::rpar;
"."             return toks::ops::dot;
","             return toks::ops::comma;
"=>"            return toks::ops::bigrarrow;
"?"             return toks::ops::ques;

\<in\>          return toks::kwords::in;
\<contains\>    return toks::kwords::contains;
\<assert\>      return toks::kwords::assert;
\<if\>          return toks::kwords::if_;
\<else\>        return toks::kwords::else_;
\<elif\>        return toks::kwords::elif_;
\<for\>         return toks::kwords::for_;
\<while\>       return toks::kwords::while_;
\<until\>       return toks::kwords::until_;
\<try\>         return toks::kwords::try_;
\<catch\>       return toks::kwords::catch_;
\<throw\>       return toks::kwords::throw_;
\<with\>        return toks::kwords::with_;
\<struct\>      return toks::kwords::struct_;
\<class\>       return toks::kwords::class_;
\<const\>       return toks::kwords::const_;
\<typeof\>      return toks::kwords::typeof_;
\<cloneof\>     return toks::kwords::cloneof_;
\<import\>      return toks::kwords::import_;


{ident} {
}

/*** literals ***/

/* int literals */
{decint}                                    return toks::lits::int_;

/* float literal */
{decint}(\.{digit}+)?([Ee][+-]?{decint})?   return toks::lits::float_;

/* byte literals */
0x{hex}*                                    return toks::lits::byte_;

/* bit literal */
0b{bit}*                                    return toks::lits::bit_;

/* octal literal */
0o{octal}                                   return toks::lits::octal_;

/* string literal */
\"{string_content}\"                        return toks::lits::string_;

/* raw string literal */
\`{string_content}\`                        return toks::lits::string_raw_;

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
