#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define VECTOR_TYPE int
#define MIN_CAP 6

struct vector {
  int size;
  int capacity;
  VECTOR_TYPE *body;
};

typedef struct vector vector;

vector* vector_create();
void vector_destroy(vector*);
VECTOR_TYPE vector_get_element_at(vector*, int);
VECTOR_TYPE vector_pop(vector*);
void vector_set_element_at(vector*, int, VECTOR_TYPE);
int vector_push_back(vector*, VECTOR_TYPE);
int vector_grow(vector*);
int vector_size(vector*);
#endif
