#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void algorithm_prima(int p, int C[p][p], set T)
{
	int a[p], b[p];
	int u = rand() % p;
	set S = create();
	S = add(S, u);
	T = empty();
	for(int v = 0; v < p; ++v)
	{
		if(v == u) continue;
		if(C[u][v] != 0)
		{
			a[v] = u;
			b[v] = C[u][v];
		}
		else
		{
			a[v] = 0;
			b[v] = INT_MAX;
		}
	}
	for(int i = 0; i < p - 1; ++i)
	{
		int x = INT_MAX, w;
		for(int v = 0; v < p; ++v)
		{
			if(include(S, v)) continue;
			if(b[v] < x)
			{
				w = v;
				x = b[v];
			}
		}
		S = add(S, w);
		T = add(T, a[w], w);
		for(int v = 0; v < p; ++v)
		{
			if(C[v][w] == 0) continue;
			if(!include(S, v))
			{
				if(b[v] > C[v][w])
				{
					a[v] = w;
					b[v] = C[v][w];
				}
			}
		}
	}
}

int main()
{
	
}
