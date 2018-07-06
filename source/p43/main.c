// TODO

#include <stdlib.h>
#include <stdio.h>

typedef struct elem_ elem;

struct elem_ {
  int i;
  elem *n;
};

void list_print(elem *head) {
  while (head != NULL) {
    printf("%d ", head->i);
    head = head->n;
  }
}

void append(elem **c, elem **e, int d) {
  elem *q = malloc(sizeof(elem)); /* новый элемент списка~*/
  q->i = d; q->n = NULL;
  if ((*c) == NULL) {
    (*c) = q; /* пустой список~*/
  }
  else {
    (*e)->n = q; /* непустой список~*/
  }
  (*e) = q;
}

elem* calc_join(elem *a, elem *b) {
  elem *pa = a, *pb = b, *c = NULL, *e = NULL; /* инициализация */

  while ((pa != NULL) && (pb != NULL)) {
    int d;
    if (pa->i < pb->i) {
      d = pa->i;
      pa = pa->n;
    }
    else if (pa->i > pb->i) {
      d = pb->i;
      pb = pb->n;
    }
    else {
      d = pa->i;
      pa = pa->n;
      pb = pb->n;
    }
    append(&c, &e, d);
  }

  elem *p = NULL;
  if (pa != NULL) {
    p = pa;
  }
  if (pb != NULL) {
    p = pb;
  }
  while (p != NULL) {
    append(&c, &e, p->i);
    p = p->n;
  }
  return c;
}

int main() {
  elem *a = NULL, *b = NULL;
  elem *pa = a, *pb = b;

  int d;
  fprintf(stdout, "%s\n", "enter list a:");
  while (fscanf(stdin, "%d", &d) == 1) {
    append(&a, &pa, d);
  }

  fprintf(stdout, "%s\n", "enter list b:");
  while (fscanf(stdin, "%d", &d) == 1) {
    append(&b, &pb, d);
  }

  elem *res = calc_join(a, b);
  list_print(res);

  return 0;
}
