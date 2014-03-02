#ifndef COMMON_H
#define COMMON_H

#include "stack.h"
//extern  Stack parse_stack;

typedef union {
  int idata;
  char * cdata;
} ParseValue;

void setup();
void teardown();

#endif /* COMMON_H */
