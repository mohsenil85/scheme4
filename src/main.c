#include <stdio.h>
#include "y.tab.h"
extern int yyparse(void);
int main(){
  printf("starting...\n");
  yyparse();
}
