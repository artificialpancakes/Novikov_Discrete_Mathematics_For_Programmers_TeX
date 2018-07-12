#define T stack

#include "graph_list.h"
#include "stack.h"
#include "vector.h"

#define create(T) T ## _create()
#define destroy(T, t) T ## _destroy(t)
#define push(T, t, i) T ## _push(t, i)
#define pop(T, t) T ## _pop(t)
#define is_empty(T, t) T ## _is_empty(t)
vector* graph_search(int p, adj_list **G) {
  vector *out = vector_create();
  T *t = create(stack);
  int x[p];
  for (int i = 0; i < p; i++) {
    x[i] = 0;
  }
  push(stack, t, 0);
  x[0] = 1;
  do {
    int u = pop(stack, t);
    vector_push_back(out, u);
    list_node *iter = G[u];
    while (iter != NULL) {
      int w = iter->v;
      iter = iter->n;
      if (x[w] == 0) {
        push(stack, t, w);
        x[w] = 1;
      }
    }
  } while (is_empty(stack, t) != 0);
  destroy(stack, t);
  return out;
}

#ifdef TEST
vector* graph_search(int p, adj_list **G) {
  vector *out = vector_create();
  T *t = T_create();
  int x[p];
  for (int i = 0; i < p; i++) {
    x[i] = 0; /* вначале все вершины не отмечены */
  }
  int v = 0; /* начало обхода - произвольная вершина */
  T_push(t, v); /* помещаем v в структуру данных T... */
  x[v] = 1; /* ...и отмечаем вершину v */
  do {
    int u = T_pop(t); /* извлекаем вершину из структуры данных Т... */
    /* ... и возвращаем её в качестве очередной пройденной вершины */
    vector_push_back(out, u);
    list_node *iter = G[u];
    while (iter != NULL) {
      int w = iter->v;
      iter = iter->n;
      if (x[w] == 0) {
        T_push(t, w); /* помещаем w в структуру данных Т... */
        x[w] = 1; /* ... и отмечаем вершину w */
      }
    }
  } while (T_is_empty(t) != 0);
  T_destroy(t);
  return out;
}
#endif

int main() {
  return 0;
}
