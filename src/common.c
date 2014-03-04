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
  printf("eval was hit\n");
  while (!stack_is_empty(&s)){
    printf("eval/while was hit\n");
    ParseValue pv;
    stack_pop(&s, &pv);
    switch(pv.tdata){
      case (T_ID):
        printf("id was hit\n");
        break;
      case (T_NUMBER):
        printf("number was hit\n");
        break;
      case (T_STRING):
        printf("string was hit\n");
        break;
      default:
        printf("the unthinkable has happened\n");
    }
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
