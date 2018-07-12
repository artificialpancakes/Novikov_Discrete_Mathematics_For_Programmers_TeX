#ifndef STACK_H
#define STACK_H

typedef struct stack_ stack;
typedef struct stack_node_ stack_node;

#define STACK_TYPE int

struct stack_ {
  int size;
  stack_node* head;
};

struct stack_node_ {
  STACK_TYPE item;
  stack_node *prev;
};

stack* stack_create();
void stack_destroy(stack *st);

STACK_TYPE stack_pop(stack *st);
void stack_push(stack *st, STACK_TYPE item);

int stack_is_empty(stack *st);

#endif
