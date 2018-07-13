#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int i;
	int j;
}pair;

typedef struct{
	int size;
	pair* body;
}vector;

vector* create(int p){
	vector* v = (vector*)malloc(sizeof(vector));
	int size = 0;
	v->body = (pair*)malloc(sizeof(pair) * p);
	return v;
}

void push(vector* E, int i, int j){
	E->body[E->size].i = i + 1;
	E->body[E->size].j = j + 1;
	E->size++;
}

int min(int p, int* B, int* A, int i){
	for(int j = 0; j < p; j++){
		if(B[j] == 2)
			continue;
		for(int k = i; k < p - 1; k++){
			if(j == A[k]){
				B[j] = 0;
				break;
			}
			else
				B[j] = 1;
		}
		if(B[j] == 1)
			return j;
	}
}

void del(int* B, int v){
	B[v] = 2;
}

int main(){
	int p;
	int v;
	scanf("%d", &p);
	int A[p - 1];
	for(int i = 0; i < p - 1; i++){
		scanf("%d", &A[i]);
	}
	for(int i = 0; i < p - 1; i++){
		A[i]--;
	}
	printf("\n");
	vector* E = create(p);
	int B[p];
	for(int i = 0; i < p - 1; i++){
		v = min(p, B, A, i);
		push(E, v, A[i]);
		del(B, v);
	}
	for(int k = 0; k < p - 1; k++)
		printf("%d %d\n", E->body[k].i, E->body[k].j);
	return 0;
}
