
/* Fluster Bison Grammar */

/***********
 Definitions
 ***********/

%{
  #include <stdio.h>
  #include <cmath.h>
  #include <ctype.h>
  extern "C" int yylex(void);
  extern "C" int yyparse();
  extern "C" FILE* yyin;
  void yyerror(char const *);
%}

/*%define api.pure full*/
/*%define api.value.type {double}*/

%union {
    long long   integer;
    long double floating;
    char*       bytes;
}

/* tokens */

%token <integer> INTEGER
%token <floating> FLOATING
%token <bytes> BYTES

/* ops */
%left PLUS DASH               /*|   + -       |*/
%left STAR FSLASH TWOFSLASH   /*|   * / //    |*/
%right CARET CARETFSLASH      /*|   ^ ^/      |*/
%precedence UNARY             /*|   ^ ^/ -    |*/

%%

/**************************
 Grammer Rules and Actions
 **************************/

input: 
     %empty | input line ;

line:
  '\n' 
| exp '\n'      { printf("%.10g\n", $1);    }
| error '\n'    { yyerrok;                  } 
;

exp:
  NUM                         { $$ = $1;                }
| exp PLUS exp                { $$ = $1 + $3;           }
| exp DASH exp                { $$ = $1 - $3;           }
| DASH exp %prec UNARY        { $$ = -$2;               }
| exp STAR exp                { $$ = $1 * $3;           }
| exp FSLASH exp              { $$ = $1 / $3;           }
| exp TWOFSLASH exp           { $$ = (int)$1 / (int)$3; }
| exp CARET exp               { $$ = pow($1, $3);       }
| CARET exp %prec UNARY       { $$ = exp($2);           }
| exp CARETFSLASH exp         { $$ = pow($3, 1/$1);     }
| CARETFSLASH exp %prec UNARY { $$ = sqrt($2);          }
| '(' exp ')'                 { $$ = $2;                }
| lambda                      {}
;

lambda: 
  caplist arglist BIGRARROW expr    {}
  ;

commalistaux: 
  expr
  | commalistaux ','
  ;
commalist: 
  commalistaux 
  | expr
  ;
trailingcommalist:
  commalist ','
  ;

callarglist: '(' commalist ')'
pramarglist: '<' commalist '>'

class:
  CLASS decl NEWLINE
;

struct:
  STRUCT decl NEWLINE
;

function:;
method:;
assert:;
struct:;
    
decl:
  IDENT pramarglist
  | IDENT;
  

%%

/****************
 Additional Code
 ****************/

int lex_op(char c) {
  switch(c)
  {
    case '+':
      return PLUS;
    case '-':
      return DASH;
    case '*':
      return STAR;
    case '/':
      if ((c=getchar()) == '/')
        return TWOFSLASH;
      else
        return ungetc(c, stdin), FSLASH;
    case '^':
      if ((c=getchar()) == '/')
        return CARETFSLASH;
      else
        return ungetc(c, stdin), CARET;
    default:
      return 0;
  }
}

//lexer
int yylex(void) {

  int c;

  //skip Ws
  while ((c = getchar()) == ' ' || c == '\t')
    continue;

  //scan for ops
  int op = lex_op(c);
  if (op)
    return op;

  //lex any digit/decimal as a number
  if (c == '.' || isdigit(c))
  {
    ungetc(c, stdin);
    scanf("%lf", &yylval);
    return NUM;
  }

  //return 0 on end of input
  if (c == EOF)
    return 0;

  return c;
}

//called on error
void yyerror(char const *s)
{
  fprintf( stderr, "%s\n", s);
}

int main(void)
{
  return yyparse();
}


