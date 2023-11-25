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

int ll_get(LinkedList *list, size_t index)
{
  Node *walker = list->head;

  for (size_t i = 0; i < index; i++)
  {
    walker = walker->next;
  };

  return walker->value;
}

void ll_unshift(LinkedList *list, int value)
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
    Node *previousHead = list->head;
    newNode->next = previousHead;
    list->head = newNode;
  }

  list->length++;
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

int ll_shift(LinkedList *list)
{
  if (list->length == 0)
  {
    return 0;
  }

  Node *res = list->head;
  list->head = res->next;
  list->length--;

  return res->value;
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
    list->length--;
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

void ll_addRange(LinkedList *list, int *range, size_t rangeLength)
{
  Node *nodes = malloc(sizeof(Node) * rangeLength);

  for (size_t i = 0; i < rangeLength; i++)
  {
    nodes[i].value = range[i];
  }

  list->tail->next = &nodes[0];
  list->tail = &nodes[rangeLength - 1];
  list->length += rangeLength;

  for (size_t i = 0; i < rangeLength - 1; i++)
  {
    nodes[i].next = &nodes[i + 1];
  }
}

// LinkedList *ll_join(LinkedList *left, LinkedList *right)
// {
//   Node *leftTail = left->tail;
//   leftTail->next = right->head;
//   right->head = left->head;
//   left->tail = right->tail;

//   return left;
// }

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