#ifndef COMMON_H
#define COMMON_H

#include "stack.h"
//extern  Stack parse_stack;

typedef struct {
  int idata;
  char * cdata;
} ParseValue;

void setup();
void teardown();

#endif /* COMMON_H */
