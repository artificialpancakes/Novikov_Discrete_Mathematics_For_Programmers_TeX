#include <limits.h>
#include <stdlib.h>
#include "bitset.h"

// TODO: bitset_copy is inefficient

bitset* bitset_create(int size_in_bits) {
  //int size = size_in_bits % CHAR_BIT == 0 ? size_in_bits / (CHAR_BIT) : size_in_bits / (CHAR_BIT) + 1;

  int size = size_in_bits / CHAR_BIT;
  if (size_in_bits % CHAR_BIT != 0) {
    size++;
  }

  bitset *bset = malloc(sizeof(bitset));
  if (bset != NULL) {
    bset->size = size_in_bits;
    bset->body = malloc(size);

    if (bset->body != NULL) {
      return bset;
    }
    else {
      return NULL;
    }
  }
}

void bitset_destroy(bitset *bset) {
  if (bset != NULL) {
    if (bset->body != NULL) {
      free(bset->body);
    }

    free(bset);
  }
}

int bitset_get(bitset *bset, int index) {
  int offset = index / CHAR_BIT;
  int i = index - offset * CHAR_BIT;

  return bset->body[offset] & (1 << i) ? 1 : 0;
}

void bitset_set(bitset *bset, int index, bool b) {
  int offset = index / CHAR_BIT;
  int i = index - offset * CHAR_BIT;

  if (b) {
    bset->body[offset] = bset->body[offset] | (1 << i);
  }
  else {
    bset->body[offset] = bset->body[offset] & ~(1 << i);
  }
}

void bitset_copy_1(bitset **to, bitset *from) {
  if ((*to) == NULL) {
    (*to) = bitset_create(1);
  }
  if ((*to)->size < from->size) {
    char *new_body = realloc((*to)->body, from->size);
    if (new_body != NULL) {
      (*to)->body = new_body;
    }
    else {
      return;
    }
  }
  (*to)->size = from->size;

  for (int i = 0; i < from->size; i++) {
    bool b = bitset_get(from, i);
    bitset_set((*to), i, b);
  }
}

void bitset_copy(bitset *to, bitset *from) {
  if (to == NULL) {
    to = bitset_create(1);
  }
  if (to->size < from->size) {
    char *new_body = realloc(to->body, from->size);
    if (new_body != NULL) {
      to->body = new_body;
    }
    else {
      return;
    }
  }
  to->size = from->size;

  for (int i = 0; i < from->size; i++) {
    bool b = bitset_get(from, i);
    bitset_set(to, i, b);
  }
}
