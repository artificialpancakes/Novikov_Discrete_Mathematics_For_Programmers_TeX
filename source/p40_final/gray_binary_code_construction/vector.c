#include "vector.h"

vector* vector_create() {
  vector* vec = malloc(sizeof(vector));

  vec->size = 0;
  vec->capacity = MIN_CAP;
  vec->body = malloc(sizeof(bitset*) * MIN_CAP);

  return vec;
}

void vector_destroy(vector* vec) {
  if (vec != NULL) {
    if (vec->body != NULL) {
      for (int i = 0; i < vec->size; i++) {
        bitset *bset = vector_get_element_at(vec, i);
        bitset_destroy(bset);
      }
      free(vec->body);
    }

    free(vec);
  }
}

bitset* vector_get_element_at(vector* vec, int index) {
  if (index < vec->size) {
    return vec->body[index];
  }
}

void vector_set_element_at(vector* vec, int index, bitset *bset) {
  if (index < vec->capacity) {
    bitset_copy(vec->body[index], bset);
  }
}

int vector_push_back(vector* vec, bitset *bset) {
  if (vec->size < vec->capacity) {
    bitset_copy_1(&vec->body[vec->size], bset);
    vec->size++;
    return 0;
  } else {
    if (vector_grow(vec) == 1) {
      return vector_push_back(vec, bset);
    }
    else {
      return 1;
    }
  }
}

int vector_grow(vector* vec) {
  bitset** body_buf = realloc(vec->body, sizeof(bitset*) * vec->capacity * 1.5);
  if (body_buf != NULL) {
    vec->body = body_buf;
    vec->capacity *= 1.5;
    return 1; // SUCCESS
  } else {
    return 0;
  }
}
