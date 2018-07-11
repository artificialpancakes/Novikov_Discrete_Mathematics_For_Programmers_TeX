#include <stdio.h>

int check_equality_word(int s, int t, char a[s], char b[t])
{
	if(a[0] != b[0])
		return 0;
	int N_a = 0;
	for(int i = 1; i < s; ++i)
	{
		if(a[i] != a[i - 1])
			N_a = N_a + 1;
	}
	int N_b = 0;
	for(int i = 1; i < t; ++i)
	{
		if(b[i] != b[i - 1])
			N_b = N_b + 1;
	}
	if(N_a == N_b) return 1;
	return 0;
}

int main()
{
	int s, t;
	scanf("%d %d ", &s, &t);

	char a[s], b[t];
	for(int i = 0; i < s; ++i)
	{
		char p;
		scanf("%c", &p);
		a[i] = p;
	}
	scanf(" ");
	for(int i = 0; i < t; ++i)
	{
		char p;
		scanf("%c", &p);
		b[i] = p;
	}

	printf("%d\n", check_equality_word(s, t, a, b));
}
