#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct tree_node_ tree_node;
struct tree_node_ {
  tree_node *l;
  tree_node *r;
  int i;
};

int calc_func(tree_node *T, int n, int *x) {
  for (int i = 0; i < n + 1; i++) {
    if ((T->l == NULL) && (T->r == NULL)) {
      return T->i; /* листовой узел — возвращаем значениe */
    }
    else {
      if (x[i] == 1) {
        T = T->r; /* 1 — переход вправо */
      } else {
        T = T->l; /* 0 — переход влево */
      }
    }
  }
  printf("%s\n", "LOL");
}

/* complete shit, but works */
void gen_tree(tree_node *tn, int level, int n, int *arr, int index) {
  int index_left = index << 1, index_right = (index << 1) + 1;
  if (level == 0) {
    if (arr[index_left] == arr[index_right]) {
      (tn)->i = arr[index_left];
      (tn)->l = NULL;
      (tn)->r = NULL;
    }
    else {
      tn->l = malloc(sizeof(tree_node));
      tn->r = malloc(sizeof(tree_node));
      tn->l->i = arr[index_left];
      tn->r->i = arr[index_right];
      tn->l->l = NULL;
      tn->l->r = NULL;
      tn->r->l = NULL;
      tn->r->r = NULL;
    }
    return;
  }
  (tn)->l = malloc(sizeof(tree_node));
  gen_tree((tn)->l, level-1, n, arr, index_left);
  (tn)->r = malloc(sizeof(tree_node));
  gen_tree((tn)->r, level-1, n, arr, index_right);
}

int main() {
  int n;
  printf("%s\n", "enter amount of vars: ");
  scanf("%d", &n);

  /* nasty */
  printf("%s\n", "enter function out: ");
  int k = pow(2, n);
  int arr[k];
  for (int i = 0; i < k; i++) {
    scanf("%d", arr + i);
  }

  tree_node *tn = malloc(sizeof(tree_node));
  gen_tree(tn, n - 1, k, arr, 0);

  while (1) {
    printf("%s\n", "enter args to calc: ");
    int x[n];
    for (int i = 0; i < n; i++) {
      scanf("%d", x + i);
    }
    printf("%d\n", calc_func(tn, n, x));
  }

  return 0;
}
