% {
#include <stdio.h>
#include "y.tab.h"
    %
  } %
        % [0 - 9] +
    yylval.num = atoi(yytext);
return NUMBER;
\(yylval.id = yytext; return OPAREN;
\)yylval.id = yytext;
return CPAREN;
\+ yylval.id = yytext;
return PLUS;
\* yylval.id = yytext;
return MULT;
.;
% %
