%{
#include <stdio.h>
#include "y.tab.h"
extern YYSTYPE yylval;
%}

%%
[0-9]+                { yylval=atoi(yytext); return NUMBER; };
\(                    return OPAREN;
\)                    return CPAREN;
\+                    return PLUS;
\*                    return MULT;
.                     ;
%%
