#include<stdio.h>
#include<stdlib.h>

int minim = 100;

int d(int** C, int n, int i){
	int* V = (int*)C;
	int S = 0;
	for(int j = 0; j < n; j++){
		S += V[i * n + j];
	}
	return S;
}

int dnf(int** V_arr, int n, int i){
	int* V = (int*)V_arr;
	if(d((int**)V, n, i) == 0){
		if(i < minim)
			minim = i;
	}
	else{
		for(int j = 0; j < n; j++){
			if(V[i * n + j] == 1)
				dnf((int**)V, n, j);
		}
	}
}

int min(int** V_arr, int n){
	minim = 100;
	int* V = (int*)V_arr;
	int S = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			S += V[j * n + i];
		}
		if(S == 0){
			dnf((int**)V, n, i);
			return minim;
		}
		else
			S = 0;
	}
}

int G(int** V_arr, int n, int v){
	int* V = (int*)V_arr;
	for(int i = 0; i < n; i++){
		if(V[i * n + v] == 1)
			return i + 1;
	}
}

void del(int** V_arr, int n, int v);

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	int V[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			V[i][j] = 0;
	}
	int j,k;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &j, &k);
		V[j - 1][k - 1] = 1;
	}
	int v;
	int p = n;
	int A[p - 2];
	for(int i = 0; i < p - 2; i++){
		v = min((int**)V, n); /* выбираем вершину v - висячую с наименьшим номером */
		A[i] = G((int**)V, n, v); /* заносим в код номер единственной вершины, смежной с v */
		V[A[i] - 1][v] = 0; /* удаляем вершину v из дерева */
	}
	for(int i = 0; i < p - 1; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	return 0;
}
