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
  char* str;
}
%token<num> NUMBER 
%token<str> STR
%token OPAREN CPAREN PLUS MULT NEWLINE ID EXIT 
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

atom: ID {
    printf("ID\n"); 
    ParseValue pv = {
      .idata = 0,
      .cdata = "\0"
    };
    pv.cdata = strdup($1);
    stack_push(&parse_stack, &pv);
    }
    | NUMBER {
    printf("NUM\n"); 
    ParseValue pv;
    memcpy(&pv.idata, &$$, sizeof(int)+1);
    stack_push(&parse_stack, &pv);
    }
    | STR  {
    printf("STR\n");
    ParseValue pv = {
      .idata = 0,
      .cdata = "\0"
    };
    pv.cdata = strdup($1);
    stack_push(&parse_stack, &pv);
    }
    | members {printf("members sub atom\n");}
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
