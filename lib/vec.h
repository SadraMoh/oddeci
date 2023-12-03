#ifndef VECTOR_GUARD
#define VECTOR_GUARD

typedef struct
{
  int *src;
  size_t capacity;
  size_t length;
} Vector;

Vector *vec_new();

Vector *vec_withCapacity(size_t capacity);

Vector *vec_from(int *range);

void vec_push(Vector *vec, int value);

int vec_pop(Vector *vec);

void vec_addRange(Vector *vec, int *range);

int *vec_collect(Vector *vec);

#endif