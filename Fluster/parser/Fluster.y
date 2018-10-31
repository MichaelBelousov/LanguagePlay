
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
%}

%define api.value.type {double}
%token NUM
/*
%token <double> NUM
%token <double> VAR FNCT

%precedence '='
%left '-' '+'
%left '*' '/'
%precedence NEG
%right '^'
*/

%%

/**************************
 Grammer Rules and Actions
 **************************/

input:
  %empty
| input line
;

line:
  '\n'
| exp '\n'  { printf("%.10g\n", $1); }
;

exp:
  NUM             { $$ = $1; }
| exp exp '+'     { $$ = $1 + $2; }
| exp exp '-'     { $$ = $1 - $2; }
| exp exp '*'     { $$ = $1 * $2; }
| exp exp '/'     { $$ = $1 / $2; }
| exp exp '^'     { $$ = pow($1, $2); }
| exp 'n'         { $$ = -$1; }
;

%%

/****************
 Additional Code
 ****************/

//lexer
int yylex(void) {

  int c;
  //skip Ws
  while ((c=getchar()) == ' ' || c == '\t')
    continue;

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


