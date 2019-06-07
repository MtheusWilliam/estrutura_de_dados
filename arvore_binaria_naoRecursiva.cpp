#include <stdio.h>
#include <malloc.h>
/*Esse código não permite inserção de nós com mesmo valor*/
typedef struct aux{
	int valor;
	struct aux* esq;
	struct aux* dir;
} NO;

typedef NO *PONT;

typedef struct{
	PONT raiz;
} ARVORE;

void inicializa(ARVORE *a){
	a->raiz = NULL;
}

bool buscaNo(ARVORE *a, int val){
	bool definicao = false;
	if(a->raiz == NULL){printf("arvore vazia"); return false;}
	if(a->raiz->valor == val){printf("elemento encontrado"); return true;}
	PONT aux = a->raiz;

	while(!definicao){
		if(val < aux->valor){
			if(aux->esq == NULL){
				printf("Elemento nao existe\n");
				return false;
			}
			else if(aux->esq->valor == val){
				printf("Elemento encontrado");
				return true;
			}
			else{
				aux = aux->esq;
			}
		}
		else{
			if(aux->dir == NULL){
				printf("Elemento nao existe\n");
				return false;
			}
			else if(aux->dir->valor == val){
				printf("Elemento encontrado");
				return true;
			}
			else{
				aux = aux->dir;
			}
		}
	}	
}

void insereNo(ARVORE *a, int val){
	PONT aux = (PONT) malloc(sizeof(NO));
	aux = a->raiz;
	PONT novo = (PONT) malloc(sizeof(NO));
	novo->valor = NULL;
	if(aux == NULL){
		novo->valor = val;
		
		a->raiz = novo;
		novo->dir = NULL;
		novo->esq = NULL;
		printf("Elemento inserido como raiz\n");
	}
	else{
		while(novo->valor == NULL){
			if(aux->valor == val){break;}
			if(val < aux->valor){
				if(aux->esq == NULL){
					novo->valor = val;
					novo->esq = NULL;
					novo->dir = NULL;
					aux->esq = novo;
					printf("Elemento inserido");
				}
				else if(aux->esq->valor == val){
					printf("Impossivel inserir, elemento ja existe na arvore");
					break;
				}
				else{
					aux = aux->esq;
				}
				printf("\n");
			}
			else{
				if(aux->dir == NULL){
					novo->valor = val;
					novo->esq = NULL;
					novo->dir = NULL;
					aux->dir = novo;
					printf("Elemento inserido");
				}
				else if(aux->dir->valor == val){
					printf("Impossivel inserir, elemento ja existe na arvore");
					break;
				}
				else{
					aux = aux->dir;
				}
				printf("\n");
			}
		}
	}
}


int main(){
	
	ARVORE a1;
	inicializa(&a1);
	insereNo(&a1, 5);
	insereNo(&a1, 2);
	insereNo(&a1, 7);
	insereNo(&a1, 12);
	insereNo(&a1, 11);
	insereNo(&a1, 5);
	buscaNo(&a1, 15);
	return 0;
}
