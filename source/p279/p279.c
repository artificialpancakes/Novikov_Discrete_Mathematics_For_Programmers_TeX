#include <stdio.h>
#include <float.h>

typedef struct flow
{
	char s;
	int n;
	double d;
} flow;

double min(double a, double b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	int p, s, t, a;
	scanf("%d %d %d", &p, &s, &t);

	int N[p], S[p];
	double C[p][p], F[p][p];
	flow P[p];

	for(int i = 0; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
		{
			double t;
			scanf("%lf", &t);
			C[i][j] = t;
		}
	}

	for(int u = 0; u < p; ++u)
		for(int v = 0; v < p; ++v)
			F[u][v] = 0;
	M:
	for(int v = 0; v < p; ++v)
	{
		S[v] = 0;
		N[v] = 0;
		P[v].s = '+';
		P[v].n = 0;
		P[v].d = 0;
	}

	S[s] = 1;
	P[s].s = '+';
	P[s].n = 0;
	P[s].d = DBL_MAX;

	do
	{
		a = 0;
		for(int v = 0; v < p; ++v)
		{
			if(S[v] == 1 && N[v] == 0)
			{
				for(int u = 0; u < p; ++u)
				{
					if(C[v][u] == 0) continue;
					if((S[u] == 0) && (F[v][u] < C[v][u]))
					{
						S[u] = 1;
						P[u].s = '+';
						P[u].n = v;
						P[u].d = min(P[v].d, C[v][u] - F[v][u]);
						a = 1;
					}
				}
				for(int u = 0; u < p; ++u)
				{
					if(C[u][v] == 0) continue;
					if((S[u] == 0) && (F[u][v] > 0))
					{
						S[u] = 1;
						P[u].s = '-';
						P[u].n = v;
						P[u].d = min(P[v].d, F[u][v]);
						a = 1;
					}
				}
				N[v] = 1;
			}
		}
		if(S[t])
		{
			int x = t;
			int d = P[t].d;
			while(x != s)
			{
				if(P[x].s == '+')
					F[P[x].n][x] = F[P[x].n][x] + d;
				else
					F[x][P[x].n] = F[x][P[x].n] - d;
				x = P[x].n;
			}
			goto M;
		}
	} while(a != 0);

	for(int u = 0; u < p; ++u)
	{
		for(int v = 0; v < p; ++v)
			printf("%f ", F[u][v]);
		printf("\n");
	}
}
