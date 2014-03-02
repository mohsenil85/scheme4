#include <stdio.h>

#include "y.tab.h"
#include "stack.h"
#include "common.h"

extern Stack parse_stack;
extern int yyparse(void);

int main() {
  printf("starting...\n");
  printf("\n");
  setup();
  yyparse();
}
