#ifndef EVAL_H
#define EVAL_H

#include "stack.h"
//extern  Stack parse_stack;

enum TypeValue {
  T_STRING,
  T_ID,
  T_NUMBER,
  T_FUN
};

typedef struct {
  int idata;
  char * cdata;
  enum TypeValue tdata;
} ParseValue;



void setup();
void teardown();
void parse_string(char * s);
void parse_int(int i);
void push_on_eval(Stack s);
//void eval(Stack parse_stack);
#endif /* EVAL_H */
