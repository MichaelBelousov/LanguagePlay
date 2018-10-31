
/* Fluster Bison Grammar */

/***********
 Definitions
 ***********/

%{
  #include <stdio.h>
  #include <math.h>
  #include <ctype.h>
  void yyerror(char const *);
  int yylex(void);

  /*
  double add(double, double);
  double sub(double, double);
  double neg(double);
  double mul(double, double);
  double div(double, double);
  double divfloor(double, double);
  double exp_(double);
  double pow_(double, double);
  double root(double, double);
  double sqrt_(double);

  //enum op_toks { PLUS, STAR, DASH, FSLASH, CARET };

  const struct {char*, int} bops[]
  { 
    {"+", PLUS}, 
    {"-", DASH}, 
    {"*", STAR}, 
    {"/", FSLASH}, 
    {"//", TWOFSLASH}, 
    {"^", CARET}, 
    {"^/", CARETFSLASH}, 
  };

  const struct {char*, double(*)(double)} uops[]
  { 
    {"-", DASH}, 
    {"^", CARET}, 
    {"^/", CARETFSLASH}, 
  };
  */

%}

/*%define api.pure full*/
%define api.value.type {double}

%token NUM
/* ops */
/*
%token PLUS 
%token DASH
%token STAR 
%token FSLASH 
%token TWOFSLASH 
%token CARET
*/
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

class:
  CLASS IDENT arglist NEWLINE
  

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


