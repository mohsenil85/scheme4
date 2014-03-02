#ifndef __STACK_H
#define __STACK_H

// from previous post on linked-list implementation
// in C
#include "list.h"
typedef struct {
  List* list;
} Stack;
void stack_new(Stack* s, int elementSize, freeFunction freeFn);
void stack_destroy(Stack* s);
void stack_push(Stack* s, void* element);
void stack_pop(Stack* s, void* element);
void stack_peek(Stack* s, void* element);
int stack_size(Stack* s);

#endif
