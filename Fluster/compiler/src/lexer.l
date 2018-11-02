
/*** RE/flex Preamble ***/

%top{
  #include "tokens.h"
%}

%class{
%}

%init{
%}

/*** Definitions ***/


ident               [_a-zA-Z][_a-zA-Z0-9]*
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

%o outfile="lexer.cpp" header-file="lexer.h"
%o yylineno
%o bison

%o tabs=4


/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
%%
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 
/* ********************************************************************************** */ 



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

/* unicode literal */
u\"(?u:{string_content})\"                       return toks::lits::string_unicode_;

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

