#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

typedef struct list_node_ adj_list;
struct list_node_ {
  int v;
  adj_list *n;
};

#endif
