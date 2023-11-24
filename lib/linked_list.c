#include <stdlib.h>
#include <stdio.h>

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

LinkedList *ll_create()
{
  LinkedList *p_linkedList = malloc(sizeof(LinkedList));
  p_linkedList->length = 0;

  return p_linkedList;
}

void ll_push(LinkedList *list, int value)
{
  Node *newNode = malloc(sizeof(Node));
  newNode->value = value;

  if (list->length == 0)
  {
    list->head = newNode;
    list->tail = newNode;
  }
  else
  {
    list->tail->next = newNode;
    list->tail = newNode;
  }

  list->length++;
}

int ll_pop(LinkedList *list)
{
  if (list->length == 0)
  {
    return 0;
  }

  if (list->length == 1)
  {
    int res = list->tail->value;
    list->head = NULL;
    list->tail = NULL;
    return res;
  }

  Node *walker = list->head;

  for (size_t i = 0; i < list->length - 2; i++)
  {
    walker = walker->next;
  };

  list->tail = walker;
  list->length--;
  int res = walker->next->value;

  free(walker->next);

  return res;
}

int *ll_collect(LinkedList *list)
{
  int *res = malloc(sizeof(int) * list->length);

  Node *walker = list->head;

  for (size_t i = 0; i < list->length; i++)
  {
    res[i] = walker->value;
    walker = walker->next;
  };

  return res;
}