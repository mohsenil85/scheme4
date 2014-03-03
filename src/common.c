#include <stdio.h>
#include "stack.h"
#include "common.h"

Stack parse_stack;
Stack eval_stack;

void setup() {
  printf("setup...\n");
  printf("\n");
  stack_new(&parse_stack, sizeof(ParseValue), NULL );
  stack_new(&eval_stack, sizeof(ParseValue), NULL );
}

void teardown(){
  stack_destroy(&parse_stack);
  stack_destroy(&eval_stack);
}
