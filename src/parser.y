%{
#include <stdio.h>
#include <string.h>
#define YYSTYPE int;
extern int yylex(void);
void yyerror(const char *str){
  fprirtf(stderr, "error: %s\n", str);
}
int yywrap(){ return 1; }
%}

%union{
int num;
char *id;
}

%token <num> NUMBER
%token <id> OPAREN CPAREN PLUS MULT NEWLINE

%%

start : line
      | start line
      ;

line: NUMBER { 
    printf("%d\n", $1);
    }
    ;

%%
