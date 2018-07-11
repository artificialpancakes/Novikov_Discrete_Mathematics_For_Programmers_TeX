#include "vector.h"

vector* vector_create() {
  vector* vec = malloc(sizeof(vector));

  vec->size = 0;
  vec->capacity = MIN_CAP;
  vec->body = malloc(sizeof(char*) * MIN_CAP);

  return vec;
}

void vector_destroy(vector* vec) {
  if (vec != NULL) {
    if (vec->body != NULL) {
    }

    free(vec);
  }
}

char* vector_get_element_at(vector* vec, int index) {
  if (index < vec->size) {
    return vec->body[index];
  }
}

void vector_set_element_at(vector* vec, int index, char *str) {
  if (index < vec->capacity) {
    vec->body[index] = str;
  }
}

int vector_push_back(vector* vec, char *str) {
  if (vec->size < vec->capacity) {
    vec->body[vec->size] = str;
    vec->size++;
    return 0;
  } else {
    if (vector_grow(vec) == 1) {
      return vector_push_back(vec, str);
    }
    else {
      return 1;
    }
  }
}

int vector_grow(vector* vec) {
  char** body_buf = realloc(vec->body, sizeof(char*) * vec->capacity * 1.5);
  if (body_buf != NULL) {
    vec->body = body_buf;
    vec->capacity *= 1.5;
    return 1; // SUCCESS
  } else {
    return 0;
  }
}
