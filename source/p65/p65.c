#include<stdio.h>
#include<stdlib.h>

const int min_cap = 10;

typedef struct vec{
	int cap;
	int size;
	double* body;
	struct vec* set;
}vec;

vec* create(){
	vec* v = (vec*)malloc(sizeof(vec));
	v-> body = (double*)malloc(sizeof(double) * min_cap);
	v->cap = min_cap;
	v->size = 0;
	v->set = NULL;
	return v;
}

vec* resize(vec* v,size_t cap){
	v->body = (double*)realloc(v->body, sizeof(double) * cap);
	v->cap = cap;
	return v;
}

void push(vec* v, double val){
	if(v->cap - 1 == v->size)
		v = resize(v, v->cap * 3/2);
	v->body[v->size] = val;
	v->size++;
}

double sel(vec* v){
	return v->body[0];
}

int ec(int a, int b){
	return (int)a % 2 == (int)b % 2;
}

int main(){
	vec* M = create();
	double b;
	while(scanf("%lf", &b) != EOF){
		push(M, b);
	}
//	for(int i = 0; i < M->size; i++)
//		printf("%.0lf ", M->body[i]);
//	printf("\n%d\n", M->size);
	int p;
	vec* Bet = create();
	vec* K = Bet;
	for(int a = 0; a < M->size; a++){
		p = 0;
		for(vec* B = Bet->set; B != NULL; B = B->set){
			b = sel(B);
			if(ec(M->body[a], b)){
				p = 2;
				push(B, M->body[a]);
				break;
			}
		}
		if(p == 0){
			vec* class_a = create();
			K->set = class_a;
			K = class_a;
			push(class_a, M->body[a]);
		}
	}
	for(vec* i = Bet->set; i != NULL; i = i->set){
		for(int j = 0; j < i->size; j++){
			printf("%.0lf ", i->body[j]);
		}
		printf("\n");
	}
	return 0;
}
