#include <stdio.h>

int check_bracket(int n, char s[n])
{
	int p = 0;
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == '(')
			p = p + 1;
		if(s[i] == ')')
			p = p - 1;
		if(p < 0)
			return i + 1;
	}
	if(p == 0)
		return 0;
	else
		return n + 1;
}

int main()
{
	int n;
	scanf("%d ", &n);

	char s[n];
	for(int i = 0; i < n; ++i)
	{
		char t;
		scanf("%c", &t);
		s[i] = t;
	}

	printf("%d\n", check_bracket(n, s));
}
