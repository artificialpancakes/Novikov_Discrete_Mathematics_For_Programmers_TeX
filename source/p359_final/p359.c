#include <stdio.h>

int min(int p, int A[p])
{
	for(int i = 0; i < p; ++i)
		if(A[i] != -1)
			return A[i];
	return 0;
}

void coloring_graph(int p, int G[p][p], int C[p])
{
	for(int v = 0; v < p; ++v)
		C[v] = 0;
	for(int v = 0; v < p; ++v)
	{
		int A[p];
		for(int i = 0; i < p; ++i)
			A[p] = p;
		for(int u = 0; u < p; ++u)
		{
			if(G[v][u] == 0) continue;
			for(int i = 0; i < p; ++i)
			{
				if(A[i] == C[u])
					A[i] = -1;
			}
		}
		C[v] = min(p, A);
	}
}

int main()
{
	int p;
	int G[p][p], C[p];
	coloring_graph(p, G, C);
}
