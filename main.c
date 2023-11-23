#include <stdio.h>
#include "lib/lib.h"

int main() {

  const int len = 8;
  int arr[] = { 1,2,3,4,5,6,7,8 };

  int res = largest(arr, len);

  printf("---> %d\n", res);

  return 0;
}