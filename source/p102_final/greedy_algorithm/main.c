// TODO: write a normal programm!!

#include "vector.h"
#include "stdio.h"

int vector_compare(vector *a, vector *b) {
  if (vector_size(a) != vector_size(b)) {
    return 1;
  }
  for (int i = 0; i < vector_size(a); i++) {
    int el1, el2;
    el1 = vector_get_element_at(a, i);
    el2 = vector_get_element_at(b, i);
    if (el1 != el2) {
      return 2;
    }
  }
  return 0;
}

vector *greedy_algorithm(vector *E, int n, vector **Eps) {
  vector *X = vector_create();
  for (int i = 0; i < vector_size(E); i++) {
    int e = vector_get_element_at(E, i);
    vector_push_back(X, e);
    int flag = 0;
    for (int j = 0; j < n; j++) {
      vector *subset = Eps[j];
      if (vector_compare(subset, X) == 0) { // B + e in Eps
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      vector_pop(X);
    }
  }
  return X;
}

int main() {
  int n;
  printf("%s\n", "enter number of elements: ");
  scanf("%d", &n);
  vector *E = vector_create();
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    vector_push_back(E, d);
  }
  printf("%s\n", "enter number of subsets: ");

  int k;
  scanf("%d", &k);

  int i = -1;
  char ch;
  vector *Eps[k];
  Eps[0] = vector_create();
  while (scanf("%c", &ch) == 1) {
    if (ch == '\n') {
      printf("%s%d\n", "I: ", i);
      i++;
      if (i == k) {
        break;
      }
      Eps[i] = vector_create();
      continue;
    }
    ungetc(ch, stdin);
    int l;
    scanf("%d", &l);
    vector_push_back(Eps[i], l);
  }

  vector *out = greedy_algorithm(E, k, Eps);
  printf("%s\n", "Result: ");
  for (int i = 0; i < vector_size(out); i++) {
    printf("%d ", vector_get_element_at(out, i));
  }

  return 0;
}
