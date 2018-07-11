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

elem *calc_intersection(elem *a, elem *b)
{
	elem *pa = a, *pb = b, *c = NULL;

	while(pa != NULL && pb != NULL)
	{
		if(pa->i < pb->i)
			pa = pa->n;
		else if(pa->i > pb->i)
			pb = pb->n;
		else
		{
			c = add(c, pa->i);
			pa = pa->n;
			pb = pb->n;
		}
	}

	return c;
}

int main()
{
	elem *a = NULL, *b = NULL;

	int v;
	while(scanf("%d", &v) != EOF) a = add(a, v);
	while(scanf("%d", &v) != EOF) b = add(b, v);

	elem *c = calc_intersection(a, b);
	for(elem *t = c; t != NULL; t = t->n) printf("%d ", t->i);
	printf("\n");
}
