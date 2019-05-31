#include <stdio.h>
#include <malloc.h>

typedef struct aux{
	int valor;
	struct aux* ant;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
	PONT cabeca;
} DEQUE;

/* */
void inicializarDeque(DEQUE *d){
	d->cabeca = (PONT) malloc(sizeof(ELEMENTO));
	d->cabeca->prox = d->cabeca;
	d->cabeca->ant = d->cabeca;
}

int tamDeque(DEQUE *d){
	PONT end = d->cabeca->prox;
	int tam = 0;
	while(end != d->cabeca){
		tam++;
		end = end->prox;
	}
	/*printf("Tamanho do deque = %i \n", tam);*/
	return tam;
}

bool dequeVazio(DEQUE *d){
	if(d->cabeca->prox == d->cabeca){
		printf("Este deque esta vazio!\n");
		return true;
	}
	return false;
}

void exibirDeque(DEQUE *d){
	PONT end = d->cabeca->prox;
	printf("Deque: \n");
	while(end != d->cabeca){
		printf("%i ", end->valor);
		end = end->prox;
	}
	printf("\n");
}

bool inserirInicio(DEQUE *d, int valor){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->valor = valor;
	novo->ant = d->cabeca;
	novo->prox = d->cabeca->prox;
	d->cabeca->prox = novo;
	novo->prox->ant = novo;
	
	return true;
}

bool inserirFim(DEQUE *d, int valor){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));
	novo->valor = valor;
	novo->ant = d->cabeca->ant;
	novo->prox = d->cabeca;
	d->cabeca->ant = novo;
	novo->ant->prox = novo;
	
	return true;
}

bool popInicio(DEQUE *d){
	if(dequeVazio(d)){
		printf("Impossivel remover algum elemento, pilha vazia\n");
		return false;
	}
	int valor = d->cabeca->prox->valor;
	PONT apagar = d->cabeca->prox;
	d->cabeca->prox = apagar->prox;
	free(apagar);
	
	return true;
}

bool popFim(DEQUE *d){
	if(dequeVazio(d)){
		printf("Impossivel remover algum elemento, pilha vazia\n");
		return false;
	}
	int valor = d->cabeca->ant->valor;
	PONT apagar = d->cabeca->ant;
	d->cabeca->ant = apagar->ant;
	free(apagar);
	
	return true;
}

int main(){
	DEQUE d1;
	inicializarDeque(&d1);
	inserirInicio(&d1, 1);
	inserirFim(&d1, 2);
	inserirFim(&d1, 3);
	inserirFim(&d1, 1);
	popInicio(&d1);
	exibirDeque(&d1);
	return 0;
}
