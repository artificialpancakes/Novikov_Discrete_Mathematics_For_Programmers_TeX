// TODO
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "vector.h"
#include "bitset.h"

int Q(int i) {
  int q = 0; int j = i;
  while (j % 2 == 0) {
    j = j / 2; q++;
  }
  return q;
}

vector* gray_binary_code(int n) { /* n >= 0 - мощность множества~*/
  vector *out = vector_create(); /* последовательность кодов подмножеств B~*/
  bitset *B = bitset_create(n); /* битовая шкала для представления подмножеств~*/
  for (int i = 0; i < n; i++) {
    bitset_set(B, i, 0); /* инициализация~*/
  }
  vector_push_back(out, B); /* пустое множество~*/

  for (int i = 1; i < pow(2, n); i++) {
    int p = Q(i); /* определение номера элемента, подлежащего добавлению или удалению~*/
    bitset_set(B, p, 1 - bitset_get(B, p)); /* добавление или удаление элемента~*/
    vector_push_back(out, B); /* добавление или удаление элемента~*/
  }

  return out;
}

void bitset_print(bitset *bset) {
  if (bset == NULL) {
    printf("%s\n", "err");
    return;
  }
  for (int i = 0; i < bset->size; i++) {
    int c = bitset_get(bset, i);
    fprintf(stdout, "%d", c);
  }
}

int main() {
  int n;
  fprintf(stdout, "%s\n", "enter power of set: ");
  while (fscanf(stdin, "%d", &n) == 1) {
    vector *res;
    res = gray_binary_code(n);
    fprintf(stdout, "%s%d\n", "size: ", res->size);
    for (int i = 0; i < res->size; i++) {
      bitset_print(res->body[i]);
      fprintf(stdout, "%s\n", "");
    }


    vector_destroy(res);
  }

  return 0;
}
