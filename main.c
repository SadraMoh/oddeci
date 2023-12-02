#include <stdio.h>
#include <stdlib.h>
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

  int nums[] = {5, 6, 7, 8};

  ll_addRange(list, nums, 4);

  all = ll_collect(list);

  printf("%d, %d, %d, %d, %d, %d, %d\n", all[0], all[1], all[2], all[3], all[4], all[5], all[6]);

  return 0;
}

int hello(char *subject, size_t length)
{
  return 1;
}
