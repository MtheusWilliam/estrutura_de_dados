#include <stdio.h>
#include <malloc.h>

typedef struct aux{
	int valor;
	struct aux* prox;
} ELEMENTO;

typedef ELEMENTO *PONT;

typedef struct{
	PONT inicio;
	PONT fim;
}FILA;

/* */
void inicializarFila(FILA *f){
	f->inicio = NULL;
    f->fim = NULL;
}

bool filaVazia(FILA *f){
	if(f->inicio == NULL && f->fim == NULL){
		return true;
	}else{
		return false;
	}
}

int tamFila(FILA *f){
	PONT end = f->inicio;
	int tam = 0;
    while(end->prox != NULL){
    	tam++;
    	end = end->prox;
	}

	/*printf("Essa fila possui %i elementos \n", tam);*/
	return tam;
}
void exibirFila(FILA *f){
	if(filaVazia(f)){
		printf("fila vazia!\n");
	}
	else{
		PONT end = f->inicio;
		printf("Fila: |");
	    while(end != NULL){
	    	printf(" %i ", end->valor);
	    	end=end->prox;
    	}
    	printf("|\n");
	}

}

bool enqueue(FILA *f, int valor){
	PONT novo = (PONT) malloc(sizeof(ELEMENTO));;
	novo->valor = valor;
	novo->prox = NULL;
    if(f->inicio == NULL){
        f->inicio = novo;
    }
    else{
    	f->fim->prox = novo;
	}
	f->fim = novo;
	return true;
}

bool dequeue(FILA *f){
	if(filaVazia(f)){
		printf("Impossivel remover algum elemento, fila vazia");
		return false;
	}
	int valor = f->inicio->valor;
	PONT apagar = f->inicio;
	f->inicio = apagar->prox;
	if(apagar->prox == NULL){
		f->fim = NULL;
	}
	free(apagar);
	return true;
}

int main(){
	
	// Código main que realiza as principais operações da fila
    FILA f1;
    inicializarFila(&f1);
    enqueue(&f1,3);
    enqueue(&f1,4);
    enqueue(&f1,5);
    dequeue(&f1);
    exibirFila(&f1);
  	
  	
	return 0;
}
