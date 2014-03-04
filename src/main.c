#include <stdio.h>

#include "y.tab.h"
#include "stack.h"
#include "common.h"

extern Stack parse_stack;
extern Stack eval_stack;
extern int yyparse(void);

int main() {
  printf("starting...\n");
  printf("\n");
  setup();
  printf("about to parse...\n");
  yyparse();
  printf("about to eval...\n");
  eval(parse_stack);
  printf("about to teardown...\n");
  teardown();
  printf("ending...\n");
}
