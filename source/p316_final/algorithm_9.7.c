#include <stdio.h>

typedef struct record
{
	int k;
	int i;
} record;

int bin_search(int n, record A[n], int a)
{
	int b = 0;
	int e = n - 1;
	while(b <= e)
	{
		int c = (b + e)/2;
		if(A[c].k > a)
			e = c - 1;
		else if(A[c].k < a)
			b = c + 1;
		else
			return c + 1;
	}
	return 0;
}

int main()
{
	int n, a;
	scanf("%d%d", &n, &a);

	record A[n];
	for(int i = 0; i < n; ++i)
	{
		int t, p;
		scanf("%d%d", &t, &p);
		A[i].k = t;
		A[i].i = p;
	}

	printf("%d\n", bin_search(n, A, a));
}
