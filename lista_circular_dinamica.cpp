#include <stdio.h>
#include <malloc.h>

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
} REGISTRO;

typedef struct tempRegistro{
	REGISTRO reg;
	struct tempRegistro* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
	PONT cabeca;
} LISTA;

void inicializarLista(LISTA *l){
	l->cabeca = (PONT) malloc(sizeof(ELEMENTO));
	l->cabeca->prox = l->cabeca;
}

int tamanho(LISTA *l){
	PONT end = l->cabeca->prox;
	int tam = 0;
	
	while(end != l->cabeca){
		tam++;
		end = end->prox;
	}
	return tam;
}

void exibirLista(LISTA *l){
	PONT end = l->cabeca->prox;
	printf("Lista: \" ");
	while(end != l->cabeca){
		printf("%i", end->reg.chave);
	}
	printf("\"\n");
}

PONT buscaSentinela(LISTA *l, TIPOCHAVE ch){
	PONT pos = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while(pos->reg.chave != ch){
		pos = pos->prox;
	}
	if(pos != l->cabeca) return pos;
	return NULL;
}

PONT buscaSeqExc(LISTA *l, TIPOCHAVE ch, PONT *ant){
	*ant = l->cabeca;
	PONT atual = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while(atual->reg.chave<ch){
		*ant = atual;
		atual = atual->prox;
	}
	if(atual != l->cabeca && atual->reg.chave == ch) return atual;
	return NULL;
}

int main(){
	
	return 0;
}
