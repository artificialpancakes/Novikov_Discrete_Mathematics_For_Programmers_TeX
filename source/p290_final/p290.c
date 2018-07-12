#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

int main()
{
	int p;
	scanf("%d", &p);

	int C[p][p], T[p];
	for(int i = 0; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
		{
			int t;
			scanf("%d", &t);
			C[i][j] = t;
		}
	}

	for(int i = 0; i < p; ++i)
		T[i] = C[1][i];
	for(int i = 1; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
		{
			if(C[j][i] == 0 || C[j][i] == INT_MAX) continue;
			T[i] = min(T[i], T[j] + C[j][i]);
		}
	}

	printf("\n");
	for(int i = 0; i < p; ++i)
		printf("%d ", T[i]);
	printf("\n");
}
