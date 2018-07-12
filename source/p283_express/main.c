// TODO: stack, adj_list, убрать костыль deleted, но это не обязательно

#include "stack.h"
#include "adj_list.h"

#ifdef TEST

list* find_strongly_connected_components(int p, adj_list **G) {
  stack *T = stack_create();
  list *C = list_create();
  adj_list *M[p];
  int e[p];
  /* используем этот указатель, чтобы пометить вершину как удалённую из V */
  adj_list *deleted = malloc(sizeof(adj_list));
  for (int v = 0; v < p; v++) {
    /* M[v] список узлов, входящих в ту же КСС, что и v */
    adj_list_add(M[v], v);
    e[v] = 0; /* все узлы не рассмотрены */
  }
  for (int i = 0; i < p; i++) {
    if (G[i] == deleted) {
      continue; /* узел удалён */
    }
    int v = i;
    stack_push(T, v);
    e[v] = 1;
    /* SCC; вызов процедуры КСС */
  }
  free(deleted);
  stack_destroy(T);
  return C;
}

void SCC() {
while (true) {
  if (stack_size(T) == 0) {
    break; /* негде выделять */
  }
  int v = stack_peek(T); /* v — верхний элемент стека */
  if (G[v] == NULL) {
    list_add(C, M[v]); /* это КСС */
    stack_pop(T); /* снять узел v со стека */
    continue; /* возврат из тупика */
  }
  else {
    list_node *u_list = G[v];
    while (u_list != NULL) {
      int u = u_list->v;
      u_list = u_list->n;
      if (e[u] == 0) {
        stack_push(T, u); /* положить узел u в стек */
        e[u] = 1; /* отметить узел u */
      }
      else {
        int w;
        adj_list *buf = NULL
        do {
          w = stack_pop(T); /* w — склеиваемый узел */
          buf = G[w];
          G[w] = deleted; /* удалить узел */
          adj_list_append(G[u], G[w]); /* запомнить смежность */
          adj_list_append(M[u], M[w]); /* склеивание узлов */
        } while (u != w);
        stack_push(st, w); /* чтобы не убрать тот узел, */
        G[v] = buf; /* с которого начали */
      }
      continue; /* поиск в глубину */
    }
  }
}
}

#endif
