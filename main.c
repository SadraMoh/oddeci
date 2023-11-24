#include <stdio.h>
#include "lib/linked_list.h"

int main()
{

  LinkedList *list = ll_create();

  ll_push(list, 1);
  ll_push(list, 2);
  ll_push(list, 3);

  int *all = ll_collect(list);

  printf("%lu\n", list->length);
  printf("%d, %d, %d\n", all[0], all[1], all[2]);

  int popped = ll_pop(list); // ---

  all = ll_collect(list);

  printf("%lu\n", list->length);
  printf("%d, %d\n", all[0], all[1]);
  printf("%d\n", popped);

  return 0;
}