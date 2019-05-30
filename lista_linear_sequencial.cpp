#include <stdio.h>

#define MAX 50

typedef int TIPOCHAVE;
typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO A[MAX];
	int numElem;
} LISTA;

void iniciaLista(LISTA *l){
	l->numElem = 0;
	printf("Lista inicializada com sucesso! \n");
}

int tamanhoLista(LISTA *l){
	printf("Essa lista possui %d elementos! \n", l->numElem);
	return l->numElem;
}

void exibirLista(LISTA *l){
	int i;
	printf("Lista: \" ");
	for(i=0; i < l->numElem; i++){
		printf("%i ", l->A[i].chave);
	}
	printf("\"\n");
}

int buscaSequencial(LISTA *l, TIPOCHAVE ch){
	int i=0;
	while(i < l->numElem){
		if(ch == l->A[i].chave){
			return i;
		}
		else{
			i++;
		}
	}
	return -1;
}

bool inserirElemLista(LISTA *l, REGISTRO reg, int i){
	int j;
	if((l->numElem == MAX) || (i < 0) || (i > l->numElem)){
		return false;
	}
	for(j = l->numElem; j > i; j--){
		l->A[j] = l->A[j-1];
	}
	l->A[i] = reg;
	l->numElem++;
	return true;
}

int buscaSequencial(TIPOCHAVE ch, LISTA *l){
	int i = 0;
	while(i < l->numElem){
		if(ch == l->A[i].chave) return i;
		else i++;
	}
	return -1;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA *l){
	int pos, j;
	pos = buscaSequencial(l,ch);
	if(pos == -1) return false;
	for(j = pos; j < l->numElem-1; j++)
		l->A[j] = l->A[j+1];
	l->numElem--;
	return true;
}

int main(){
	LISTA l1;
	iniciaLista(&l1);
	tamanhoLista(&l1);
	
	return 0;
}
