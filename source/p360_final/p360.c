#include <stdio.h>

int empty(int p, int V[p])
{
	for(int i = 0; i < p; ++i)
		if(V[i] != -1)
			return 0;
	return 1;
}

void improved_coloring_graph(int p, int G[p][p], int V[p], int C[p])
{
	sort(p, V);
	int c = 1;
	for(int v = 0; v < p; ++v)
		C[v] = 0;
	while(!empty(p, V))
	{
		for(int v = 0; v < p; ++p)
		{
			int flag = 0;
			for(int u = 0; u < p; ++u)
			{
				if(G[v][u] == 0) continue;
				if(C[u] == c) flag = 1;
			}
			if(flag) continue;
			C[v] = c;
			V[v] = -1;
		}
		c = c + 1;
	}
}

int main()
{
	int p;
	int G[p][p], V[p], C[p];
	improved_coloring_graph(p, G, V, C);
}
