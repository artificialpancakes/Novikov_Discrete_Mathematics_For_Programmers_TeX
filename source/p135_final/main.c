#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "vector.h"

vector* pdnf_construction(int n, char **x, int *F) {
  /* последовательность символов,
  образующих запись формулы СДНФ для заданной функции. */
  vector *out = vector_create();
  bool f = false; /* признак присутствия левого операнда дизъюнкции */
  for (int i = 0; i < pow(2, n); i++) {
    if (F[i] == 1) {
      if (f) {
        vector_push_back(out, "   |   "); /* добавление в формулу знака дизъюнкции */
      } else {
        f = true; /* это первое слагаемое в дизъюнкции */
      }
      bool g = false; /* признак присутствия левого операнда конъюнкции */
      for (int j = 1; j <= n; j++) {
        if (g) {
          vector_push_back(out, " & "); /* добавление в формулу знака конъюнкции */
        } else {
          g = true; /* это первый сомножитель в конъюнкции */
        }
        int v = (i >> (j - 1)) % 2;
        if (v == 0) {
          vector_push_back(out, "!"); /* добавление в формулу знака отрицания */
        }
        /* добавление в формулу идентификатора переменной */
        vector_push_back(out, x[j - 1]);
      }
    }
  }
  return out;
}

int main() {
  int n = 0;
  printf("%s\n", "Enter number of vars:");
  if (fscanf(stdin, "%d", &n) == 1) {
    char* x[n];
    int *F = malloc(sizeof(int) * n);
    printf("%s\n", "Enter var names:");
    for (int i = n-1; i >= 0; i--) {
      x[i] = malloc(32);
      if (fscanf(stdin, "%s", x[i]  ) == 0) {
        printf("%s\n", "error!");
        return -1;
      }
    }
    printf("%s\n", "Enter function result:");
    for (int i = 0; i < pow(2, n); i++) {
      if (fscanf(stdin, "%d", &(F[i])) == 0) {
        printf("%s\n", "error!");
        return -1;
      }
    }

    vector *out = pdnf_construction(n, x, F);
    for (int i = 0; i < out->size; i++) {
      printf("%s", vector_get_element_at(out, i));
    }
    printf("%s\n", "");
  }
  return 0;
}
