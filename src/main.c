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
    if (i.idata){
      printf("int:  stack had this on it: %d\n", i.idata);
    } else if (i.cdata) {
      printf("string :stack had this on it: %s\n", i.cdata);
    } else {
      printf("unknown data type...\n");
    }
  }
  printf("about to teardown...\n");
  teardown();
  printf("ending...\n");
}
