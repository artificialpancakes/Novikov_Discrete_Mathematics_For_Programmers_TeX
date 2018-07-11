#include<stdio.h>
#include<math.h>
#include<stdlib.h>

double modul(double a){
	if(a > 0)
		return a;
	else
		return (-1) * a;
}

int Med(double *P, int b, int e){
	double d;
	double Sb = 0;
	for(int i = b; i < e; i++){
		Sb += P[i];
	}
	double Se = P[e];
//	printf("%lf %lf/n", Sb, Se);
	int m = e;
	do{
//		printf("%.2lf %.2lf ", Sb, Se);
		d = modul(Sb - Se);
//		printf("%.2lf \n", d);
		m--;
		Sb = Sb - P[m];
		Se = Se + P[m];
	}while(modul(Sb - Se) < d);
	return m;
}

void Fano(double *P, int **C, int b, int e, int k, int n){
	int *C_arr = (int*)C;
	if(e > b){
		int m = Med(P, b, e);
		for(int i = b; i <= e; i++){
			if(i > m)
				C_arr[i * n + k] = 1;
			else
				C_arr[i * n + k] = 0;
		}
		Fano(P, (int**)C, b, m, k + 1, n);
		Fano(P, (int**)C, m + 1, e, k + 1, n);
	}
}
void fun(double* P,int** C, int n){
	int *C_arr = (int*)C;
	double Sum = 0;
	printf("P_i\tC[i]\tl_i\tP_i*l_i\n");
	for(int i = 0; i < n; i++){
		printf("%.2lf:\t", P[i]);
		for(int j = 0; j < n; j++){
			if(C_arr[i * n + j] != 2)
				printf("%d", C_arr[i * n + j]);
			else{
				P[i] *= (double)j;
				Sum += P[i];
				printf("\t%d\t%.2lf", j, P[i]);
				break;
			}
		}
		printf("\n");
	}
	printf("l(P)\t\t\t%.2lf\n", Sum);
}

int main(){
	int n;
	scanf("%d", &n);
	double P[n];
	int C[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			C[i][j] = 2;
	}
	for(int i = 0; i < n; i++){
			scanf("%lf", &P[i]);
	}
	Fano(P, (int**)C, 0, n - 1, 0, n);
	fun(P, (int**)C, n);
	return 0;
}
