#include <stdio.h>
	
int main()
{
	int n;
	scanf("%d", &n);

	int R[n][n], T[n][n];
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int t;
			scanf("%d", &t);
			R[i][j] = t;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			for(int k = 0; k < n; ++k)
				T[j][k] = R[j][k] | (R[j][i] & R[i][k]);
		}
		for(int a = 0; a < n; ++a)
			for(int j = 0; j < n; ++j)
				R[a][j] = T[a][j];
	}

	printf("\n");
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			printf("%d ", T[i][j]);
		printf("\n");
	}
}
