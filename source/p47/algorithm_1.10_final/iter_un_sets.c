#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
	int i;
	struct elem *n;
} elem;

elem *add(elem *l, int v)
{
	elem *t = malloc(sizeof(elem)), *p = l;
	t->n = NULL;
	t->i = v;

	if(l == NULL) return t;
	while(l->n != NULL) l = l->n;
	l->n = t;

	return p;
}

void iter_un_sets(elem *X, elem *Y)
{
	for(elem *x = X; x != NULL; x = x->n)
	{
		printf("%d", x->i);
   }
	for(elem *y = Y; y != NULL; y = y->n)
	{
	  printf("%d ", y->i);
  }
}

int main()
{
	elem *a = NULL, *b = NULL;

	int v;
	while(scanf("%d", &v) != EOF) a = add(a, v);
	while(scanf("%d", &v) != EOF) b = add(b, v);

	iter_un_sets(a, b);
}
