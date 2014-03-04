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

void eval(Stack s){
  while (!stack_is_empty(&s)){
    ParseValue pv;
    stack_pop(&s, &pv);
    //switch() 
  }
  /*
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
     */
}
