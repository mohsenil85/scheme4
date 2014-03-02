#include <stdio.h>
#include "y.tab.h"
#include "stack.h"
extern int yyparse(void);


int main() {
  printf("starting...\n");
  printf("\n");
  yyparse();
}
