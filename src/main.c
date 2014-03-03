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
  printf("about to parse...\n");
  yyparse();
  if (!stack_is_empty(&parse_stack)){
    ParseValue i;
    stack_pop(&parse_stack, &i);
    printf("stack had this on it: %d\n", i);
  }
  printf("about to teardown...\n");
  teardown();
  printf("ending...\n");
}
