#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int s = pow(2, n), m[s];
	for(int i = 0; i < s; ++i)
		m[i] = 0;

	for(int i = 0; i < pow(2, n); ++i)
	{
		int t = i, p = 1;
		while(t) //код очередного подмножества
		{
			m[i] += t % 2 * p;
			t /= 2;
			p *= 10;
		}
	}

	for(int i = 0; i < s; ++i)
		printf("%d\n", m[i]);
}
