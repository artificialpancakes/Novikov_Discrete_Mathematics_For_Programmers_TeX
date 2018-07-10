#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include "bitset.h"

#define MIN_CAP 6

struct vector {
  int size;
  int capacity;
  bitset **body;
};

typedef struct vector vector;

vector* vector_create();
void vector_destroy(vector*);
bitset* vector_get_element_at(vector*, int);
void vector_set_element_at(vector*, int, bitset*);
int vector_push_back(vector*, bitset*);
int vector_grow(vector*);

#endif
