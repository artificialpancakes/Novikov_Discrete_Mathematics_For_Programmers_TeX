// TODO

#include "adj_list.h"

vector* construct_euler_cycle(int p, adj_list **G) {
  vector *out = vector_create();
  stack *S = stack_create(); /* стек для хранения вершин */
  if (p < 1) {
    return out;
  }
  stack_push(S, 0); /* положить произвольную вершину в стек */
  while (stack_size(S) != 0) {
    int v = stack_peek(S); /* v - верхний элемент стека */
    if (G[v] == NULL) {
      /* очередная вершина эйлерова цикла */
      stack_pop(S);
      vector_push_back(out, v);
    }
    else {
      int u = G[v]->v; /* взять первую вершину из списка смежности */
      stack_push(S, u); /* положить u в стек */
      adj_list_remove(G[v], u); /* удалить ребро (v, u) */
      adj_list_remove(G[u], v);
    }
  }
}

int main() {
  return 0;
}
