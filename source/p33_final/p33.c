#include<stdio.h>
#include<stdlib.h>

typedef struct q_el{
	double val;
	size_t numb;
	struct q_el* next;
}q_el;

typedef struct que{
	q_el* front;
	q_el* back;
}que;

que* create(){
	que* q = (que*) malloc(sizeof(que));
	q->front = NULL;
	q->back = NULL;
	return q;
}

int is_empty(que* q){
	return q->front == NULL;
}

void push(que* q, double v, size_t n){
	q_el* p = (q_el*) malloc(sizeof(q_el));
	p->val = v;
	p->numb = n;
	p->next = NULL;
	if(q->back == NULL){
		q->back = p;
		q->front = p;
	}
	else{
		q->back->next = p;
		q->back = p;
	}
}

double pop(que* q){
	q_el* p = q->front;
	double v = q->front->val;
	q->front = q->front->next;
	if(q->front == NULL)
		q->back == NULL;
	free(p);
	return v;
}

void dest(que* q){
	while(!is_empty){
		pop(q);
	}
	free(q);
}

int main(){
	que* A = create();
	que* B = create();
        double v;
        while(1==scanf("%lf",&v)){
                push(A,v,0);
        }
				int i = 0;
				double x;
        while(!is_empty(A)){
                i++;
								x = pop(A);
								push(B,x,i);
        }
	return 0;
}
