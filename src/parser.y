%{
#include <stdio.h>
#include <string.h>
extern int yylex(void);
void yyerror(const char *str){
  fprintf(stderr, "error:%s\n", str);
}
int yywrap(){ return 1; }
%}

%token OPAREN CPAREN PLUS MULT NUMBER

%%

int: NUMBER{
   printf("%d\n", $1);
   }
   ;

%%
