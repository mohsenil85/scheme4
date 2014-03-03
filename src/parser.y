%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "common.h"
#define _POSIX_C_SOURCE 1

extern Stack parse_stack;
extern int yylex(void);
void yyerror(const char * str) { fprintf(stderr, "error: %s\n", str); }
int yywrap() { return 1; }

//%type<num> exp 
%}


%union {
  int num;
  char* id;
}
%token<num> NUMBER 
%token OPAREN CPAREN PLUS MULT NEWLINE STR ID EXIT
%type<id> ID atom
%start program
%%

program: slist
       ;

slist: slist sexpr 
     | sexpr
     ;

sexpr: atom                 {printf("matched sexpr\n");}
     | list
     | exit
     ;

list: open members close       {printf("matched list\n");}
    | open close                {printf("matched empty list\n");}
    ;

members: sexpr              {printf("members 1\n");}
       | sexpr members         {printf("members 2\n");}
       | function members     {printf("function, members \n");}
       ;

atom: ID                    {printf("ID\n");}
    | NUMBER                {printf("NUM\n"); stack_push(&parse_stack, &$$);}
    | STR                   {printf("STR\n");}
    ;

function: MULT              {printf("mult\n");}
        | PLUS              {printf("plus\n");}
        ;

open: OPAREN {printf("open paren\n");}
    ;

close: CPAREN {printf("close paren\n");}
     ;

exit: EXIT {YYACCEPT;}
    ;
%%
