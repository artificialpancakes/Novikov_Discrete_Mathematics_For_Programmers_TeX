#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *r, *l;
	int i;
} node;

node *NewNode(int a)
{
	node *p = malloc(sizeof(node));
	p->i = a;
	p->l = NULL;
	p->r = NULL;
	return p;
}

node *add_node(node *T, int a)
{
	if(T == NULL)
	{
		T = NewNode(a);
		return T;
	}
	node *p = T;
	while(1)
	{
		if(a == p->i)
			return T;
		if(a < p->i)
		{
			if(p->l == NULL)
			{
				p->l = NewNode(a);
				return T;
			}
			else
				p = p->l;
		}
		else if(a > p->i)
		{
			if(p->r == NULL)
			{
				p->r = NewNode(a);
				return T;
			}
			else
				p = p->r;
		}
	}
}

int main()
{
	node *T = NULL;
	int a;
	T = add_node(T, a);
}
