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
  elem *pa = a, *pb = b, *c = NULL, *e = NULL; /* инициализация~*/

  while ((pa != NULL) && (pb != NULL)) {
    int d;
    if (pa->i < pb->i) {
      d = pa->i; /* добавлению подлежит элемент множества А~*/
      pa = pa->n;
    }
    else if (pa->i > pb->i) {
      d = pb->i; /* добавлению подлежит элемент множества В~*/
      pb = pb->n;
    }
    else {
      d = pa->i; /* здесь pa.i = pb.i, и можно взять любой из элементов~*/
      pa = pa->n; pb = pb->n; /* продвижение в обоих множествах~*/
    }
    append(&c, &e, d); /* добавление элемента d в конец списка с~*/
  }

  elem *p = NULL; /* указатель «хвоста»~*/
  if (pa != NULL) {
    p = pa; /* нужно добавить в результат оставшиеся элементы множества А~*/
  }
  if (pb != NULL) {
    p = pb; /* нужно добавить в результат оставшиеся элементы множества В~*/
  }
  while (p != NULL) {
    append(&c, &e, p->i); /* добавление элемента pa.i в конец списка с~*/
    p = p->n; /* продвижение указателя «хвоста»~*/
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
