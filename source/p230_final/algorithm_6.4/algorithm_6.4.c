#include <stdio.h>
#include <string.h>

typedef struct pair
{
	int p;
	char q;
} pair;

void unpack(int m, pair *g)
{
	char D[100][50];
	D[0][0] = '\0';
	int d = 0;
	for(int k = 0; k < m; ++k)
	{
		int p = g[k].p;
		int q = g[k].q;
		printf("%s %c\n", D[p], q);
		d = d + 1;
		strcpy(D[d], D[p]);
		int l = strlen(D[d]);
		D[d][l] = q;
	}
}

int main()
{
	int m;
	scanf("%d", &m);

	pair g[m];
	for(int i = 0; i < m; ++i)
		scanf("%d %c", &(g[i].p), &(g[i].q));

	unpack(m, g);
}
