%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "eval.h"
#define _POSIX_C_SOURCE 1

extern Stack parse_stack;
extern int yylex(void);
void yyerror(const char * str) { fprintf(stderr, "error: %s\n", str); }
int yywrap() { return 1; }

%}


%union {
  int num;
  char* id;
  char* str;
  char* syn;
  char* fun;
}
%token<num> NUMBER 
%token<str> STR
%token OPAREN CPAREN PLUS MULT NEWLINE ID EXIT 
%type<id> ID atom 
%type<syn> OPAREN CPAREN
%type<fun> MULT PLUS

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
    parse_string($1);
    }
    | NUMBER {
    printf("NUM\n"); 
    parse_int($1);
    }
    | STR  {
    printf("STR\n");
    parse_string($1);
    }
    ;

function: MULT  {
        parse_syn($1);
        printf("mult\n");
        }
        | PLUS {
        parse_syn($1);
        printf("plus\n");
        }
        ;

open: OPAREN {
    printf("open paren\n");
    parse_string($1);
    }
    ;

close: CPAREN {
     printf("close paren\n");
     push_on_eval(parse_stack);
     }
     ;

exit: EXIT {YYACCEPT;}
    ;
%%
