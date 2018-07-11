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

int check_inclusion(elem *a, elem *b)
{
	elem *pa = a, *pb = b;

	while(pa != NULL && pb != NULL)
	{
		if(pa->i < pb->i)
			return 0;
		else if(pa->i > pb->i)
			pb = pb->n;
		else
		{
			pa = pa->n;
			pb = pb->n;
		}
	}

	return pa == NULL;
}

int main()
{
	elem *a = NULL, *b = NULL;

	int v;
	while(scanf("%d", &v) != EOF) a = add(a, v);
	while(scanf("%d", &v) != EOF) b = add(b, v);

	printf("%d\n", check_inclusion(a, b));
}
