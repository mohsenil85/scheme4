#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack.h"
void stack_new(Stack *s, int elementSize, freeFunction freeFn)
{
s->list = malloc(sizeof(List));
// make sure the malloc call didn't fail...
assert(s->list != NULL);
list_new(s->list, elementSize, freeFn);
}
void stack_destroy(Stack *s)
{
list_destroy(s->list);
free(s->list);
}
void stack_push(Stack *s, void *element)
{
list_prepend(s->list, element);
}
void stack_pop(Stack *s, void *element)
{
// don't pop an empty stack!
assert(stack_size(s) > 0);
 
list_head(s->list, element, true);
}
void stack_peek(Stack *s, void *element)
{
assert(stack_size(s) > 0);
list_head(s->list, element, false);
}
int stack_size(Stack *s)
{
return list_size(s->list);
}
