#include <stdio.h>
#include <malloc.h>

typedef struct tempNo{
	float valor;
	int coluna;
	struct tempNo* prox;	
}NO;

typedef NO* PONT;

typedef struct{
	PONT *A;
	int linhas;
	int colunas;
}MATRIZ;

void inicializaMatriz(MATRIZ *m, int linhas, int colunas){
	int i;
	m->linhas = linhas;
	m->colunas = colunas;
	m->A = (PONT*) malloc (linhas*sizeof(PONT));
	for(i=0;i<linhas;i++){
		m->A[i] = NULL;
	}
	
}
bool atribuiMatriz(MATRIZ *m, int lin, int col, float valor){
	if(lin > m->linhas || lin < 0 ||
	   col > m->colunas || col < 0){
	   	printf("Impossivel inserir valor, posicao indisponivel. \n\n");
		return false;
	}
	float val = valor;
	PONT ant = NULL;
	PONT atual = m->A[lin];
	while(atual != NULL && atual->coluna < col){
		ant = atual;
		atual = atual->prox;
	}
	if(atual != NULL && atual->coluna == col){
		printf("substituindo valor\n\n");
		if(val == 0){
			if(ant == NULL) m->A[lin] = atual->prox;
			else ant->prox = atual->prox;
			free(atual);
		}else{
			atual->valor = val;	
		}
	}
	else{
		PONT novo = (PONT) malloc(sizeof(NO));
		novo->coluna = col;
		novo->valor = val;
		novo->prox = atual;
		if(ant == NULL){
			 m->A[lin] = novo;
			 //printf("%f \n", m->A[lin]->valor);
		}
		else{
			ant->prox = novo;
			//printf("2parou aqui");
		} 
	}
	return true;
}

float valorMatriz(MATRIZ *m, int lin, int col){
	if(lin<0 || lin>=m->linhas ||
		col<0 || col>=m->colunas){
		printf("Posicao invalida \n");
		return 0;
	}
	PONT atual = m->A[lin];
	while(atual != NULL && atual->coluna < col){
		atual = atual->prox;
	}
	if(atual != NULL && atual->coluna == col){
		return atual->valor;
	}
	return 0;
}

void exibeMatriz(MATRIZ *m){
	int numColunas = m->colunas;
	int numLinhas = m->linhas;
	int i, j;
	for(i = 0; i < numLinhas; i++){
		for(j = 0; j < numColunas; j++){
			printf(" %.2f ", valorMatriz(m, i, j));
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
	//codigo main testando as principais funcoes da matriz esparsa
	int i ;
	MATRIZ m1;
	inicializaMatriz(&m1, 4, 4);

	atribuiMatriz(&m1, 0, 0, 2);
	atribuiMatriz(&m1, 0, 1, 1);
	atribuiMatriz(&m1, 2, 1, 8);
	
	exibeMatriz(&m1);
	
	atribuiMatriz(&m1, 0, 1, 2);
	atribuiMatriz(&m1, 2, 1, 0);
	atribuiMatriz(&m1, 3, 1, 0);
	atribuiMatriz(&m1, 4, 6, 10);
	
	exibeMatriz(&m1);
	
	return 0;
}

