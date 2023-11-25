#ifndef LINKEDLIST_GUARD
#define LINKEDLIST_GUARD

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
  Node *tail;
  size_t length;
} LinkedList;

LinkedList *ll_create();

int ll_get(LinkedList *list, size_t index);

void ll_push(LinkedList *list, int value);

void ll_addRange(LinkedList *list, int *range, size_t rangeLength);

int ll_pop(LinkedList *list);

int ll_shift(LinkedList *list);

int ll_unshift(LinkedList *list, int value);

int *ll_collect(LinkedList *list);

#endif
