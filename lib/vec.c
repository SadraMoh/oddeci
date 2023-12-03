#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
  int *src;
  size_t capacity;
  size_t length;
} Vector;

Vector *vec_new()
{
  Vector *vec = malloc(sizeof(Vector));
  vec->src = NULL;
  vec->capacity = 0;
  vec->length = 0;

  return vec;
}

Vector *vec_withCapacity(size_t capacity)
{
  Vector *vec = malloc(sizeof(Vector));
  vec->src = NULL;
  vec->capacity = capacity;
  vec->length = 0;

  if (capacity > 0)
  {
    int *src = malloc(capacity * sizeof(int));
    vec->src = src;
  }

  return vec;
};

// Vector *vec_from(int *range);

void vec_push(Vector *vec, int value)
{
  if (vec->length + 1 > vec->capacity)
  {
    int *newAlloc = realloc(vec->src, (vec->capacity + 1) * sizeof(int));
    vec->src = newAlloc;
    vec->capacity += 1;
  };

  vec->src[vec->length] = value;
  vec->length++;
}

int *vec_collect(Vector *vec)
{
  int *res = malloc(sizeof(int) * vec->length);
  memcpy(res, vec->src, vec->length);

  return res;
}

// int vec_pop(Vector *vec);

// void vec_addRange(Vector *vec, int *range);