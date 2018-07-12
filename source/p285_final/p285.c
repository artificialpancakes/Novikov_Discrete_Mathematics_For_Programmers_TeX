#include <stdio.h>
#include <limits.h>

int main()
{
	int p;
	scanf("%d", &p);

	int C[p][p], T[p][p], H[p][p];
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
	{
		for(int j = 0; j < p; ++j)
		{
			T[i][j] = C[i][j];
			if(C[i][j] == INT_MAX)
				H[i][j] = 0;
			else
				H[i][j] = j;
		}
	}

	for(int i = 0; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
		{
			for(int k = 0; k < p; ++k)
			{
				if(i != j && T[j][i] != INT_MAX && i != k && T[i][k] != INT_MAX && (T[j][k] == INT_MAX || T[j][k] > (T[j][i] + T[i][k])))
				{
					H[j][k] = H[j][i];
					T[j][k] = T[j][i] + T[i][k];
				}
			}
		}
		for(int j = 0; j < p; ++j)
		{
			if(T[j][j] < 0)
				return 1;
		}
	}

	printf("\n");
	for(int i = 0; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
			printf("%d ", T[i][j]);
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < p; ++i)
	{
		for(int j = 0; j < p; ++j)
			printf("%d ", H[i][j]);
		printf("\n");
	}
}
