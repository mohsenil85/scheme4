#include <stdio.h>
#include "stack.h"
#include "common.h"

Stack parse_stack;

/*
   typedef union {
   int idata;
   char * cdata;
   } ParseValue;
 */

void setup() {
  printf("setup...\n");
  printf("\n");
  Stack parse_stack;
  stack_new(&parse_stack, sizeof(ParseValue), NULL );
}
