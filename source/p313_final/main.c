#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

static struct node *newNode(int data){
	node *newnode = malloc(sizeof(node));
	if( newnode ) {
		newnode->data = data;
		newnode->left = NULL;
		newnode->right = NULL;
	}
	return newnode;
}

static struct node *insert(node **node, int data){
	if( !*node )  {
		*node = newNode(data );
		return *node;
	}
	if( data <= (*node)->data ) {
		return insert( &(*node)->left, data);
	}
	return insert( &(*node)->right, data);
}

typedef struct el_st{
	node* p;
	struct el_st* prev;
}el_st;

typedef struct steck{
	el_st* back;
}steck;

steck* create(){
	steck* T = (steck*)malloc(sizeof(steck));
	T->back = NULL;
}

void push(steck* T, node* t){
	el_st* el = (el_st*)malloc(sizeof(el_st));
	el->p = t;
	el->prev = T->back;
	T->back = el;
}

int is_empty(steck* T){
	return T->back == NULL;
}

node* pop(steck* T){
	el_st* s = T->back;
	node* t = s->p;
	T->back = s->prev;
	free(s);
	return t;
}

int main(){
	int n;
	struct node *root = NULL;
	while( scanf( "%d", &n ) != EOF && n ) {
		if( !insert( &root, n ) ) {
		perror( "Node creation" );
		break;
		}
	}
	steck* T = create();
	node* p = root;
	while(1){
		if(p == NULL){
			if(is_empty(T))
				break;
			else{
				p = pop(T);
				printf("%d", p->data);
				p = p->right;
			}
		}
		else{
			push(T, p);
			p = p->left;
		}
	}
	return 0;
}
