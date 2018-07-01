/* this is program, tex.c is what should be written in the book */

list_node* calc_merge(list *A, list *B) {
  list_node *pa = A->head;
  list_node *pb = B->head;
  list_node *e = NULL;
  list_node *c = malloc(sizeof(list));

  while (pa != NULL) & (pb != NULL) {
    list_node *d;
    if (pa->i < pb->i) {
      d = pa->i;
      pa = pa->next;
    }
    else if (pa->i > pb->i) {
      d = pb->i;
      pb = pb->next;
    }
    else {
      d = pa->i;
      pa = pa->next;
      pb = pb->next;
    }
    Append(c, e, d);
  }
  list_node *p = NULL;
  if (pa != NULL) {
    p = pa;
  }
  if (pb != NULL) {
    p = pb;
  }
  while (p != NULL) {
    Append(c, e, p.i);
    p = p->next;
  }
}
