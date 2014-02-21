%{
#include <stdio.h>
#include <string.h>
void yyerror(const char *str){
  fprintf(stderr, "error:%s", str);
}
int yywrap(){ return 1; }
extern int yyparse();
int main(){ yyparse(); }
%}

%token OPAREN CPAREN PLUS MULT NUMBER

%%

expression: /* empty */
          | list
          | atom
          ;
list: OPAREN head tail CPAREN {
    printf("this was hit\n");
    };

head: PLUS
    | MULT
    ;

tail: /* empty */
    | list 
    | atom
    ;

atom: NUMBER {
    printf("this was hit\n");
    }
    ;



%%
