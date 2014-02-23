%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
extern int yylex(void);
void yyerror(const char *str){
  fprintf(stderr, "error: %s\n", str);
}
int yywrap(){ return 1; }
%}

%union{
int num;
char *id;
}

%token <num> NUMBER 
%token <id> OPAREN CPAREN PLUS MULT NEWLINE 
%type <num> exp
%start exp

%%

exp: NUMBER { /*printf("%d\n", $1); */}
   | PLUS exp exp {
   $$ = $2 + $3;
   printf("plus: %d\n", $$);
   }
   |MULT exp exp{
   $$ = $2 * $3;
   if($$ >= INT_MAX){
     printf("error, int max exceeded\n");
   } else {
     printf("mult: %d\n", $$);
   }
   }
   ;

%%
