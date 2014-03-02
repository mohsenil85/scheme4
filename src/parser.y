%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

extern Stack parse_stack;
stack_new(&parse_stack, sizeof(ParseValue), NULL);
extern int yylex(void);
void yyerror(const char * str) { fprintf(stderr, "error: %s\n", str); }
int yywrap() { return 1; }
%}


%union {
  int num;
  char* id;
}
%token<num> NUMBER 
%token<id> OPAREN CPAREN PLUS MULT NEWLINE 
%type<num> exp 
%start exp 
%%

exp : NUMBER{ /*printf("%d\n", $1); */ } 
    | PLUS exp exp 
    {
      $$ = $2 + $3;
      printf("plus: %d\n", $$);
    }
    | MULT exp exp
    {
        $$ = $2 * $3;
        stack_push(&parse_stack, &$$);
        printf("mult: %d\n", $$);
    }
    ;

%%
