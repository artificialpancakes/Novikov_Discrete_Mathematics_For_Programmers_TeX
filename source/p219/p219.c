#include<stdio.h>
#include<stdlib.h>
const int size = 7;

void fun(int** C){
        int *C_arr = (int*)C;
        for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
			if(C_arr[i * size + j] != 2)
                                printf("%d", C_arr[i * size + j]);
			else
				break;
                }
                printf("\n");
        }
        printf("\n");
}

int Up(double *P, int n, double q){
	int j = 0;
	for(int i = n - 1; i >= 1; i--)
		if(P[i - 1] < q)
			P[i] = P[i - 1];
		else{
			j = i;
			break;
		}
	P[j] = q;
	return j;
}

void Down(int** C_arr, int *L, int n, int j){
	int *C = (int*)C_arr;
	int c[size];
	for(int i = 0; i < size; i++)
		c[i] = C[j * size + i];
	int l = L[j];
	for(int i = j; i <= n - 1; i++){
		for(int k = 0; k < size; k++){
			C[i * size + k] = C[(i + 1) * size + k];
		}
		L[i] = L[i + 1];
	}
	for(int i = 0; i < size; i++){
		C[(n - 1) * size + i] = c[i];
		C[(n) * size + i] = c[i];
	}
	C[(n - 1) * size + (l)] = 0;
	C[(n) * size + (l)] = 1;
	L[n - 1] = l + 1;
	L[n] = l + 1;
}

int Huffman(double *P, int** C_arr, int *L, int n){
	int *C = (int*)C_arr;
	double q;
	int j;
	if(n == 1){
		C[0 * size + 0] = 0, L[0] = 1;
                C[1 * size + 0] = 1, L[1] = 1;
        }
        else{
                q = P[n - 1] + P[n];
                j = Up(P, n, q);
                Huffman(P, (int**)C, L, n - 1);
                Down((int**)C, L, n, j);
        }
}

int main(){
	int n;
	scanf("%d", &n);
	double P[n];
	for(int i = 0; i < n; i++)
		scanf("%lf", &P[i]);
	int C[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			C[i][j] = 2;
	int L[n];
	int j;
	Huffman(P, (int**)C, L, n - 1);
	fun((int**)C);
	return 0;
}
