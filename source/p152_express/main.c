#include <stdbool.h>
#include <stdio.h>

enum formula_type { IMPL, NEG, VAR };

typedef struct formula_ formula;
struct formula_ {
  formula *l;
  formula *r;
  char *var;
  enum formula_type type;
};

typedef struct list_node_ list_node;
struct list_node_ {
  char *index;
  formula *f;
  list_node *next;
};

formula* list_get(list_node *ln, char *index) {
  return NULL;
}

void list_set(list_node *ln, char *index, formula *F) {
  ;
}

int f(formula *F) {
  return 0;
}

formula* l(formula *F) {
  return NULL;
}

formula* r(formula *F) {
  return NULL;
}

list_node *S;
bool Unify(formula *A, formula *B) {
  if (f(A) == VAR) {
    char *v = A->var; /* переменная */
    formula *permutation = list_get(S, v);
    if (permutation == NULL) {
      list_set(S, v, B); /* то есть добавляем подстановку {B//v} */
    }
    else {
      /* либо эта подстановка уже есть, либо унификация невозможна */
      return permutation == B;
    }
  }
  if (f(A) != f(B)) {
    /* главные операции различны — унификация невозможна */
    return false;
  }
  if (f(A) == NEG) {
    /* пытаемся унифицировать операнды отрицаний */
    return Unify(r(A), r(B));
  }
  if (f(A) == IMPL) {
    /* пытаемся унифицировать операнды импликаций */
    return Unify(l(A), l(B)) && Unify(r(A), r(B));
  }
}

int main() {
  return 0;
}
