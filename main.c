#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/linked_list.h"
#include "lib/vec.h"

#pragma region Linked_List

// int main()
// {

//   LinkedList *list = ll_create();

//   ll_push(list, 1);
//   ll_push(list, 2);
//   ll_push(list, 3);

//   int *all = ll_collect(list);

//   printf("%lu\n", list->length);
//   printf("%d, %d, %d\n", all[0], all[1], all[2]);

//   int nums[] = {5, 6, 7, 8};

//   ll_addRange(list, nums, 4);

//   all = ll_collect(list);

//   printf("%d, %d, %d, %d, %d, %d, %d\n", all[0], all[1], all[2], all[3], all[4], all[5], all[6]);

//   return 0;
// }

#pragma endregion Linked_List

#pragma region Vector

int main()
{

  // int *src = malloc(sizeof(int) * 3);
  // src[0] = 1;
  // src[1] = 2;
  // src[2] = 3;

  // int *dest = malloc(sizeof(int) * 4);
  // memcpy(dest, src, 3 * sizeof(int));
  // dest[3] = 4;

  // printf("[%d, %d, %d, %d]", dest[0], dest[1], dest[2], dest[3]);

  // return 0;

  Vector *vec = vec_new();

  vec_push(vec, 33);
  vec_push(vec, 22);
  vec_push(vec, 11);

  // int *col = vec_collect(vec);

  for (size_t i = 0; i < vec->length; i++)
  {
    printf("%d ", vec->src[i]);
  };
  printf("\n");

  return 0;
}

#pragma endregion Vector

#pragma region WASI

int hello(char *subject, size_t length)
{
  return 1;
}

#pragma endregion WASI