#include <stdbool.h>

typedef struct tree_node_ tree_node;
struct tree_node_ {
  tree_node *l;
  tree_node *r;
  int i;
};

bool calc_func(tree_node *T, int n, int *x) {
  for (int i = 0; i < n; i++) {
    if (T->l == NULL && T->r == NULL) {
      return T->i; /* листовой узел — возвращаем значениe */
    }
    else {
      if (x[i]) {
        T = T->r; /* 1 — переход вправо */
      } else {
        T = T->l; /* 0 — переход влево */
      }
    }
  }
}

int main() {
  return 0;
}
