
/* Sizr Format Bison Grammar */

/***********
 Definitions
 ***********/

/* options */

/* tokens */

%define api.token.prefix {TOK_}
%token
    END     0       "end of file"
    EQ              "="
    LANGLE          "<"
    LANGLEEQ        "<="
    DOUBLEEQ        "=="
    HASHEQ          "#="
    LANGLEEQRANGLE  "<=>"
    TILDE           "~"
    TILDETILDE      "~~"
    BANGEQ          "!="
    RANGLEEQ        ">="
    RANGLE          ">"
    PLUS            "+"
    DASH            "-"
    STAR            "*"
    FSLASH          "/"
    DOUBLEFSLASH    "//"
    PERCENT         "%"
    CARET           "^"
    CARETFSLASH     "^/"
    HAS             "has"
    IS              "is"
    AMPERSAND       "&"
    PIPE            "|"
    DOUBLERANGLE    ">>"
    DOUBLELANGLE    "<<"
    DASHRANGLE      "->"
    EQ              "="
    PLUSEQ          "+="
    DASHEQ          "-="
    STAREQ          "*="
    FSLASHEQ        "/="
    DOUBLEFSLASHEQ  "//="
    CARETFSLASHEQ   "^/="
    CARETEQ         "^="
    AMPERSANDEQ     "&="
    PIPEEQ          "|="
    TILDEEQ         "~="
    DOUBLERANGLEEQ  ">>="
    DOUBLELANGLEEQ  "<<="
    DASHRANGLEEQ    "->="
    DOLLAR          "$"
    LANGLEDASH      "<-"
    DOTDOTDOT       "..."
    LBRACK          "["
    RBRACK          "]"
    LBRACE          "{"
    RBRACE          "}"
    LPAR            "("
    RPAR            ")"
    DOT             "."
    COMMA           ","
    EQRANGLE        "=>"
    COLON           ":"
    AT              "@"
    QUES            "?"
    IN              "in"
    CONTAINS        "contains"
    ASSERT          "assert"
    MOD             "mod"
    IF              "if"
    ELSE            "else"
    ELIF            "elif"
    FOR             "for"
    WHILE           "while"
    UNTIL           "until"
    TRY             "try"
    CATCH           "catch"
    THROW           "throw"
    WITH            "with"
    STRUCT          "struct"
    CLASS           "class"
    CONST           "const"
    TYPEOF          "typeof"
    CLONEOF         "cloneof"
    IMPORT          "import"
;

%token <std::string> ID "id"
%token <std::string> CLASS STRUCT FUNC
%token EQRANGLE COMMA STAR MESSAGE COLON DOT
%token LANGLE RANGLE LBRACK RBRACK LPAR RPAR LBRACE RBRACE
%token INDENT OUTDENT
%token <long long> INTEGER "integer"  /* switch to uint64_t */
%token <double> FLOAT "float"
/* TODO: use std::bitset or something */
%token <char[]> BYTES "bytes"
%token <char[]> BITS "bits"
/*%type exp*/

%printer { yyo << $$; } <*>;


%%

/**************************
 Grammer Rules and Actions
 **************************/

%start input

/* ops */
/* %left PLUS DASH               /*|   + -       |*/
/* %left STAR FSLASH TWOFSLASH   /*|   * / //    |*/
/* %right CARET CARETFSLASH      /*|   ^ ^/      |*/
/* %precedence UNARY             /*|   ^ ^/ -    |*/

input:
  %empty
  | code input
;

code:
  '\n' 
  | any
  | error '\n'    
    { yyerrok; } 
;

any:
  lit
| class
| struct_decl
| func_decl;

lit:
  INTEGER
| FLOATING
| BYTES
| BITS
;

/*
| exp PLUS exp                
| exp DASH exp              
| DASH exp %prec UNARY     
| exp STAR exp            
| exp FSLASH exp         
| exp TWOFSLASH exp     
| exp CARET exp        
| CARET exp %prec UNARY
| exp CARETFSLASH exp
| CARETFSLASH exp %prec UNARY
| '(' exp ')'
| lambda
;
*/

/*
lambda: 
  caparglist parlist EQRANGLE exp
  ;
*/

commalist:
  %empty
  | commalist COMMA
    /*{ $$ += $2; }*/
  | commalist ID
    /*{ $$ += $2; }*/
  ;

parlist:    LPAR   commalist RPAR
/*
//not used yet
bracklist:  LBRACK commalist RBRACK
bracelist:  LBRACE commalist RBRACE
*/
anglelist:  LANGLE commalist RANGLE

class:
  CLASS decl INDENT body
  {
    #ifdef DEBUG
        //cout << "class:" << $2 << endl;
    #endif
  }
;

body:
  any 
  | body any
;

struct_decl:
  STRUCT decl INDENT
;

func_decl: 
  FUNC decl parlist INDENT
;

/*
method: %empty;
assert: %empty;
*/
    
decl:
  ID
  | ID anglelist
;
  

%%

