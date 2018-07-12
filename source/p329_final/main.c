#include "vector.h"

vector* kruskal_algorithm(int p, edge **E) {
  vector *T = vector_create();
  int k = 0;
  for (int i = 0; i < p - 1; i++) {
    while (1) {
      vector_push_back(T, E[k]);
      k++;
      if (dfs(T)) {
        break;
      }
      else {
        vector_pop_back(T);
      }
    }
  }
  return T;
}

int main() {
  return 0;
}
