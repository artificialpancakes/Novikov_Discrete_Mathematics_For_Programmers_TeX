#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);

	int s = pow(2, n), m[s];
	for(int i = 0; i < pow(2, n); ++i)
		m[i] = i; //код очередного подмножества

	for(int i = 0; i < s; ++i)
		printf("%d\n", m[i]);
}
