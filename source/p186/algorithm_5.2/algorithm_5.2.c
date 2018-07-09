#include <stdio.h>

void print(int n, int *P)
{
	for(int i = 0; i < n; ++i)
		printf("%d ", P[i]);
	printf("\n");
}

void swap(int *P, int i, int j)
{
	int t = P[i];
	P[i] = P[j];
	P[j] = t;
}

void Reverse(int k, int *P)
{
	int j = 0;
	while(j < k)
	{
		swap(P, j, k);
		j = j + 1;
		k = k - 1;
	}
}

void Antilex(int m, int n, int *P)
{
	if(m == 1)
		print(n, P);
	else
	{
		for(int i = 0; i < m; ++i)
		{
			Antilex(m - 1, n, P);
			if(i < m - 1)
			{
				swap(P, i, m - 1);
				Reverse(m - 2, P);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int P[n];
	for(int i = 0; i < n; ++i)
		P[i] = i;

	Antilex(n, n, P);
}
