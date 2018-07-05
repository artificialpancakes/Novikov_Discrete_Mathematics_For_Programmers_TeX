#ifndef BITSET_H
#define BITSET_H

#include <stdbool.h>

typedef struct {
  int size;
  char *body;
} bitset;

bitset* bitset_create(int size_in_bits);
void bitset_destroy(bitset *bset);

void bitset_set(bitset *bset, int index, bool b);
int bitset_get(bitset *bset, int index);
void bitset_copy(bitset *to, bitset *from);
void bitset_copy_1(bitset **to, bitset *from);

#endif
