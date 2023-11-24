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

void ll_push(LinkedList *list, int value);

int ll_pop(LinkedList *list);

int *ll_collect(LinkedList *list);

#endif
