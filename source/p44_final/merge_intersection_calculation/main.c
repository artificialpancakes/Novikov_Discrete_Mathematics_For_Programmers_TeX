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
  elem *q = malloc(sizeof(elem)); /* новый элемент списка */
  q->i = d; q->n = NULL;
  if ((*c) == NULL) {
    (*c) = q; /* пустой список */
  }
  else {
    (*e)->n = q; /* непустой список */
  }
  (*e) = q;
}

elem* calc_intersection(elem *a, elem *b) {
  elem *pa = a, *pb = b, *c = NULL, *e = NULL; /* инициализация */
  while ((pa != NULL) && (pb != NULL)) {
    if (pa->i < pb->i) {
      pa = pa->n; /* элемент множества А пе принадлежит пересечению */
    }
    else if (pa->i > pb->i) {
      pb = pb->n; /* элемент множества В не принадлежит пересечению */
    }
    else {
      /* здесь pa.i = pb.i — данный элемент принадлежит пересечению */
      append(&c, &e, pa->i); /* добавление элемента */
      pa = pa->n;
      pb = pb->n;
    }
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

  elem *res = calc_intersection(a, b);
  list_print(res);

  return 0;
}
