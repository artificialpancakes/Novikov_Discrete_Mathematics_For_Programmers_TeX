#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Med(double *P, int b, int e){
	double d;
	double Se;
	double Sb = 0;
	for(int i = b; i < e; i++){
		Sb = Sb + P[i];
	}
	Se = P[e];
	int m = e;
	do{
		d = abs(Sb - Se);
		m--;
		Sb = Sb - P[m];
		Se = Se + P[m];
	}while(abs(Sb - Se) >= d);
	return m;
}

void Fano(double *P, int **C, int b, int e, int k){
	int *C_arr = (int*)C;
	if(e > b){
		k++;
		int m = Med(P, b, e);
		for(int i = b; i <= e; i++){
			if(i > m)
				C_arr[k * e + i] = 1;
			else
				C_arr[k * e + i] = 0;
		}
		Fano(P, (int**)C, b, m, k);
		Fano(P, (int**)C, m + 1, e, k);
	}
}

int main(){
	return 0;
}
