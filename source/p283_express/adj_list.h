#ifndef ADJ_LIST_H
#define ADJ_LIST_H

typedef struct adj_list_node_ adj_list_node;
typedef struct list_node_ list_node;

struct adj_list_node_ {
  int v;
  adj_list_node *n;
  list_node *l;
};

struct list_node_ {
  int v;
  list_node *n;
};

#endif
