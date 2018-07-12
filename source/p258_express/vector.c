#include "vector.h"

vector* vector_create() {
  vector* vec = malloc(sizeof(vector));

  vec->size = 0;
  vec->capacity = MIN_CAP;
  vec->body = malloc(sizeof(VECTOR_TYPE) * MIN_CAP);

  return vec;
}

void vector_destroy(vector* vec) {
  free(vec->body);
  free(vec);
}

VECTOR_TYPE vector_get_element_at(vector* vec, int index) {
  if (index < vec->size) {
    return vec->body[index];
  }
}

void vector_set_element_at(vector* vec, int index, VECTOR_TYPE val) {
  if (index < vec->capacity) {
    vec->body[index] = val;
  }
}

int vector_push_back(vector* vec, VECTOR_TYPE val) {
  if (vec->size < vec->capacity) {
    vec->body[vec->size] = val;
    vec->size++;
    return 0;
  } else {
    if (vector_grow(vec) == 1) {
      return vector_push_back(vec, val);
    }
    else {
      return 1;
    }
  }
}

int vector_grow(vector* vec) {
  VECTOR_TYPE* body_buf = realloc(vec->body, sizeof(VECTOR_TYPE) * vec->capacity * 1.5);
  if (body_buf != NULL) {
    vec->body = body_buf;
    vec->capacity *= 1.5;
    return 1; // SUCCESS
  } else {
    return 0;
  }
}
