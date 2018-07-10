#include <stdio.h>
#include <string.h>

char D[100][50];
int d;

int Length(int i)
{
	return strlen(D[i]);
}

int FD(int k, char *f)
{
	int l = 0, p = 0;
	for(int i = 0; i < d; ++i)
	{
		int m = Length(i);
		char s[m];
		for(int j = 0; j < m; ++j)
			s[j] = f[k + j];
		if((m > l) && (strcmp(D[i], s) == 0))
		{
			p = i;
			l = m;
		}
	}
	return p;
}

void pack(int n, char *f)
{
	D[0][0] = '\0';
	d = 0;
	int k = 0;
	while(k < n)
	{
		int p = FD(k, f);
		int l = Length(p);
		printf("%d %c\n", p, f[k + l]);
		d = d + 1;
		strcpy(D[d], D[p]);
		D[d][l] = f[k + l];
		k = k + l + 1;
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	char f[n];
	for(int i = 0; i < n; ++i)
	{
		char t;
		scanf("%c", &t);
		f[i] = t;
	}

	pack(n, f);
}
