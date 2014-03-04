#include <stdio.h>
#include <string.h>
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


void parse_string(char * s){
    ParseValue pv = {
      .idata = 0,
      .cdata = "\0",
      .tdata = T_STRING
    };
    pv.cdata = strdup(s);
    stack_push(&parse_stack, &pv);

}
void parse_int(int i){
    ParseValue pv = {
      .idata = 0,
      .cdata = "\0",
      .tdata = T_NUMBER
    };
    memcpy(&pv.idata, &i, sizeof(int)+1);
    stack_push(&parse_stack, &pv);
}

void eval(Stack s){
  printf("eval was hit\n");
  while (!stack_is_empty(&s)){
    printf("eval/while was hit\n");
    ParseValue pv;
    stack_pop(&s, &pv);
    switch(pv.tdata){
      case (T_ID):
        printf("got %s\n", pv.cdata);
        printf("id was hit\n");
        break;
      case (T_NUMBER):
        printf("got %d\n", pv.idata);
        printf("number was hit\n");
        break;
      case (T_STRING):
        printf("string was hit\n");
        break;
      default:
        printf("the unthinkable has happened\n");
    }
  }
}
