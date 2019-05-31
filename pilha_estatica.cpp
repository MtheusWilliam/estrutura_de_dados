#include <stdio.h>
#define MAX 20

#define true 1
#define false 0
typedef int boolean;

typedef struct {
	int A[MAX];
	int topo;
} PILHA;

/* */
void inicializarPilha(PILHA *p){
	p->topo = -1;
}

int tamPilha(PILHA *p){
	int numElementos = p->topo + 1;
	printf("Essa pilha possui %i elementos \n", numElementos);
	return numElementos;
}
void exibirPilha(PILHA *p){
	printf("Pilha: \n");
	int i;
	for(i=p->topo; i >= 0; i--){
		printf("| %i |\n", p->A[i]);
	}
	printf("\n");
}

bool push(PILHA *p, int valor){
	if(p->topo == MAX){
		printf("Impossivel inserir no momento, pilha cheia");
		return false;
	}
	p->topo = p->topo+1;
	p->A[p->topo] = valor;
	return true;
}

bool pop(PILHA *p){
	if(p->topo == -1){
		printf("Impossivel remover algum elemento, pilha vazia");
		return false;
	}
	
	p->topo = p->topo-1;
	return true;
}

int main(){
	PILHA p1;
	inicializarPilha(&p1);
	push(&p1, 2);
	push(&p1, 3);
	push(&p1, 1);
	push(&p1, 7);
	pop(&p1);
	exibirPilha(&p1);
	return 0;
}
