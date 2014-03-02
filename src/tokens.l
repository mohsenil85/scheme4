%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "y.tab.h"
#define _POSIX_C_SOURCE 1
%} 

%option noinput
%option nounput

%%

[0-9]+          yylval.num = atoi(yytext); return NUMBER;
\(              yylval.id = yytext; return OPAREN;
\)              yylval.id = yytext; return CPAREN;
\+              yylval.id = yytext; return PLUS;
\*              yylval.id = yytext; return MULT;
\"[^\"\n]*\"                        return STR; 
[a-zA-Z][a-zA-Z0-9]*                return ID; 
.               ;
%%
