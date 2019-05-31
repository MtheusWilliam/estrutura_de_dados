#include <stdio.h>
#include <malloc.h>

typedef struct aux{
	int valor;
	int indice;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
	PONT topo;
} PILHA;

/* */
void inicializarPilha(PILHA *p){
	p->topo = NULL;
}

int tamPilha(PILHA *p){
	PONT end = p->topo;
	int tam = 0;
	while(end != NULL){
		tam++;
		end = end->prox;
	}
	/*printf("Tamanho da pilha = %i \n", tam);*/
	return tam;
}

bool pilhaVazia(PILHA *p){
	if(p->topo == NULL){
		printf("Esta piha esta vazia!\n");
		return true;
	}
	return false;
}

void exibirPilha(PILHA *p){
	PONT end = p->topo;
	printf("Pilha: \n");
	while(end != NULL){
		printf("%i \n", end->valor);
		end = end->prox;
	}
	printf("\n");
}

bool push(PILHA *p, int valor){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->indice = tamPilha(p);
	novo->valor = valor;
	novo->prox = p->topo;
	p->topo = novo;
	
	return true;
}

bool pop(PILHA *p){
	if(pilhaVazia(p)){
		printf("Impossivel remover algum elemento, pilha vazia\n");
		return false;
	}
	int valor = p->topo->valor;
	PONT apagar = p->topo;
	p->topo = p->topo->prox;
	free(apagar);
	
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
	pop(&p1);

	exibirPilha(&p1);
	return 0;
}
