#ifndef LIST_H
#define LIST_H
#include <stdbool.h>
typedef void (*freeFunction) (void *);

typedef bool (*listIterator) (void *);

typedef struct Node {
  void *data;
  struct Node *next;
} Node;

typedef struct List {
  int logicalLength;
  int elementSize;
  Node *head;
  Node *tail;
  freeFunction freeFn;
} List;

void list_new(List *list, int elementSize, freeFunction freeFn);
void list_destroy(List *list);

void list_prepend(List *list, void *element);
void list_append(List *list, void *element);
int list_size(List *list);

void list_for_each(List *list, listIterator iter);
void list_head(List *list, void *element, bool removeFromList);
void list_tail(List *list, void *element);
#endif /* LIST_H */
