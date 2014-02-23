%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[0-9]+                return NUMBER;
\(                    return OPAREN;
\)                    return CPAREN;
\+                    return PLUS;
\*                    return MULT;
.                     ;
%%
