#include <stdio.h>

int main()
{
	int k, n, res = 0;
	scanf("%d%d", &k, &n);
	int f[k][n], x[n];
	
	for(int i = 0; i < k; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			int t;
			scanf("%d", &t);
			f[i][j] = t;
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int t;
		scanf("%d", &t);
		x[i] = t;
	}

	for(int i = 0; i < k; ++i)
	{
		int flag = 0;
		for(int j = 0; j < n; ++j)
		{
			if(f[i][j] != x[j])
				flag = 1;
		}
		if(flag) continue;
		res = 1;
	}

	printf("%d\n", res);
}
