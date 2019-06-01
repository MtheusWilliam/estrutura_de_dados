#include <stdio.h>

#define MAX 20

#define true 1
#define false 0
typedef int boolean;

typedef struct {
	int A[MAX];
	int inicio;
    int fim;
} FILA;

/* */
void inicializarFila(FILA *f){
	f->inicio = -1;
    f->fim = -1;
}

int tamFila(FILA *f){
    if (f->inicio == 0 && f->fim == 0){
       int numElementos = 1;
       return numElementos;
    }
	int numElementos = f->fim - f->inicio;
	/*printf("Essa fila possui %i elementos \n", numElementos);*/
	return numElementos;
}
void exibirFila(FILA *f){
	printf("Fila: |");
    int tam = tamFila(f);
	int i;
	for(i=f->inicio; i <= f->fim; i++){
		printf(" %i ", f->A[i]);
	}
	printf("|\n");
}

bool enqueue(FILA *f, int valor){
	if(tamFila(f) == MAX){
		printf("Impossivel inserir no momento, fila cheia");
		return false;
	}
    if(tamFila(f) == 0){
        f->inicio = 0;
        f->fim = 0;
        f->A[f->inicio] = valor;
        f->A[f->fim] = valor;
        return true;
    }
	f->fim = f->fim+1;
	f->A[f->fim] = valor;
	return true;
}

bool dequeue(FILA *f){
	if(tamFila(f) == 0){
		printf("Impossivel remover algum elemento, fila vazia");
		return false;
	}
	if(tamFila(f) == 1){
        f->inicio = -1;
        f->fim = -1;
        return true;
    }
	f->inicio = f->inicio+1;
	return true;
}

int main(){
	
	// Código main que realiza as principais operações da fila
    FILA f1;
    int num;
    inicializarFila(&f1);
    for(int i =0;i<5;i++){
        printf("%d. Entre com um numero: ",i);
        scanf("%d", &num);
        enqueue(&f1,num);
    }
    dequeue(&f1);
    exibirFila(&f1);
  	
  	
	return 0;
}
