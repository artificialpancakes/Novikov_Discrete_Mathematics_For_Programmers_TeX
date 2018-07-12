#include <stdio.h>

typedef struct node
{
	struct node *r, *l;
	int i;
} node;

node *search_node(node *T, int a)
{
	node *p = T;
	while(p != NULL)
	{
		if(a < p->i)
			p = p->l;
		else if(a > p->i)
			p = p->r;
		else
			return p;
	}
	return NULL;
}

int main()
{
	node *T;
	int a;
	node *t = search_node(T, a);
}
