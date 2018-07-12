#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node *r, *l;
	int i;
} node;

void Find(node *T, int a, node **p, node **q, int s)
{
	*p = T;
	*q = NULL;
	s = 0;
	while(*p != NULL)
	{
		if((*p)->i == a)
			return;
		*q = *p;
		if(a < (*p)->i)
		{
			*p = (*p)->l;
			s = -1;
		}
		else
		{
			*p = (*p)->r;
			s = +1;
		}
	}
}

void Delete(node *p1, node *p2, node *p3, int s)
{
	if(s == -1)
		p2->l = p3;
	if(s == +1)
		p2->r = p3;
	free(p1);
}

node *remove_node(node *T, int a)
{
	node *p, *q;
	int s;
	Find(T, a, &p, &q, s);
	if(p == NULL)
		return T;
	if(p->r == NULL)
		Delete(p, q, p->l, s);
	else
	{
		node *u = p->r;
		if(u->l == NULL)
		{
			u->l = p->l;
			Delete(p, q, u, s);
		}
		else
		{
			node *w = u, *v = u->l;
			while(v->l != NULL)
			{
				w = v;
				v = v->l;
			}
			p->i = v->i;
			Delete(v, w, v->r, -1);
		}
	}
	return T;
}

int main()
{
	node *T;
	int a;
	T = remove_node(T, a);
}
