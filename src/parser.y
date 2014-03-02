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
%token<id> OPAREN CPAREN PLUS MULT NEWLINE ID STR
%start program
%%

program: slist
       ;

slist: slist sexpr 
     | sexpr
     ;

sexpr: atom                 {printf("matched sexpr\n");}
     | list
     ;

list: OPAREN members CPAREN       {printf("matched list\n");}
    | OPAREN CPAREN                {printf("matched empty list\n");}
    ;

members: sexpr              {printf("members 1\n");}
       | sexpr members         {printf("members 2\n");}
       ;

atom: ID                    {printf("ID\n");}
    | NUMBER                   {printf("NUM\n");}
    | STR                   {printf("STR\n");}
    ;
%%
