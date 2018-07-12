
#include<stdio.h>
#include<stdlib.h>

typedef struct el_d{
        double val;
        struct el_d* next;
        struct el_d* prev; 
}el_d;

typedef struct deck{
        el_d* front;
        el_d* back;
}deck;

deck* create(){
        deck* d = (deck*) malloc(sizeof(deck));
        d->front = NULL;
        d->back = NULL;
        return d;
}

int is_empty(deck* d){
        return d->front == NULL;
}

void push_front(deck* d, double v){
        el_d* p = (el_d*) malloc(sizeof(el_d));
        p->val = v;
        p->next = d->front;
        p->prev = NULL;
        if(d->front == NULL){
                d->front = p;
                d->back = p;
        }
        else{
                d->front->prev = p;
                d->front = p;
        }
}

void push_back(deck* d, double v){
        el_d* p = (el_d*) malloc(sizeof(el_d));
        p->val = v;
        p->next = NULL;
        p->prev = d->back;
        if(d->back == NULL){
                d->front = p;
                d->back = p;
        }
        else{
                d->back->next = p;
                d->back = p;
        }
}

double pop_front(deck* d){
        double v = d->front->val;
        if(d->front->next == NULL){
                free(d->front);
                d->front = NULL;
                d->back = NULL;
        }
        else{
                d->front = d->front->next;
                free(d->front->prev);
                d->front->prev = NULL;
        }
        return v;
}

double pop_back(deck* d){
        double v = d->back->val;
        if(d->back->prev == NULL){
                free(d->back);
                d->front = NULL;
                d->back = NULL;
        }
        else{
                d->back = d->back->prev;
                free(d->back->next);
                d->back->next = NULL;
        }
        return v;
}

el_d* min(deck* U){
        el_d* m = U->front;
        for(el_d* i = U->front; i != NULL; i = i->next){
                if(i->val < m->val)
                        m = i;
        }
        return m;
}

void pop(deck* U, el_d* m){
        if(m->next == NULL)
                pop_back(U);
        else
                if(m->prev == NULL)
                        pop_front(U);
                else{
                        m->next->prev = m->prev;
                        m->prev->next = m->next;
                }
}
int main(){
        deck* U = create();
        deck* W = create();
        el_d* m;
        double v;
        while(scanf("%lf",&v) != EOF){
                push_back(U,v);
        }
        while(!is_empty(U)){
                m = min(U);
                push_back(W, m->val);
                pop(U, m);
        }
        while(!is_empty(W))
                printf("%.3lf ", pop_front(W));
        return 0;
}


