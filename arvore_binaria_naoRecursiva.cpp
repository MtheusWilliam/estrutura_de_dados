#include <stdio.h>
#include <malloc.h>
/*Esse c�digo n�o permite inser��o de n�s com mesmo valor*/
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
int contaNos(NO *raiz){
	if(raiz == NULL){ return 0; }
	return(contaNos(raiz->esq) + 1 + contaNos(raiz->dir));
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

//fun��o de busca n�o dinamica utilizada pela fun��o removeNo
PONT buscaNo2(PONT raiz, int val, PONT *pai){
	PONT atual = raiz;
	*pai = NULL;
	while(atual != NULL){
		if(atual->valor == val) return(atual);
		*pai = atual;
		if(val < atual->valor) atual = atual->esq;
		else atual = atual->dir;
	}
	return(NULL);
}

PONT removeNo(PONT raiz, int val){
	PONT pai, no, p, q;
	no = buscaNo2(raiz, val, &pai);
	if(no==NULL) return(raiz);
	if(!no->esq || !no->dir){
		if(!no->esq) q = no->dir;
		else q = no->esq;
	}
	else{
		p = no;
		q = no->esq;
		while(q->dir){
			p = q;
			q = q->dir;
		}
		if(p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
	if(!pai){
		free(no);
		return(q);
	}
	if(val < pai->valor) pai->esq = q;
	else pai->dir = q;
	free(no);
	return(raiz);
}

void exibirArvore(NO *raiz){
	if(raiz != NULL){
		printf("%i", raiz->valor);
		printf("(");
		exibirArvore(raiz->esq);
		exibirArvore(raiz->dir);
		printf(")");
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
	removeNo(a1.raiz, 12);
	
	int num = contaNos(a1.raiz);
	//printf("%i", num);
	exibirArvore(a1.raiz);
	return 0;
}
