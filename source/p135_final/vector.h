#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define MIN_CAP 6

struct vector {
  int size;
  int capacity;
  char **body;
};

typedef struct vector vector;

vector* vector_create();
void vector_destroy(vector*);
char* vector_get_element_at(vector*, int);
void vector_set_element_at(vector*, int, char*);
int vector_push_back(vector*, char*);
int vector_grow(vector*);

#endif
