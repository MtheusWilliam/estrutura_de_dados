#include <stdio.h>

#define MAX 50
#define INVALIDO -1

typedef int TIPOCHAVE;
typedef struct{
	TIPOCHAVE chave;
}REGISTRO;

typedef struct{
	REGISTRO reg;
	int prox;
} ELEMENTO;

typedef struct{
	ELEMENTO A[MAX];
	int inicio;
	int dispo;
} LISTA;

void iniciaLista(LISTA *l){
	int i;
	for(i=0; i<MAX-1; i++){
		l->A[i].prox = i + 1;
	}
	l->A[MAX-1].prox=INVALIDO;
	l->inicio=INVALIDO;
	l->dispo=0;
	printf("Lista inicializada com sucesso! \n");
}

void exibirLista(LISTA *l){
	int i = l->inicio;
	printf("Lista: \" ");
	while(i!=INVALIDO){
		printf("%i ", l->A[i].reg.chave);
		i = l->A[i].prox;
	}
	printf("\"\n");
}

int buscaSequencialOrd(LISTA *l, TIPOCHAVE ch){
	int i=l->inicio;
	while(i != INVALIDO && l->A[i].reg.chave < ch){
		i = l->A[i].prox;
	}
	if(i != INVALIDO && l->A[i].reg.chave == ch){
			return i;
		}
	else return INVALIDO;
	
}

int obterNo(LISTA *l){
	int resultado = l->dispo;
	if(l->dispo != INVALIDO){
		l->dispo = l->A[l->dispo].prox;
	}
	return resultado;
}

bool inserirElemListaOrd(LISTA *l, REGISTRO reg){
	if(l->dispo == INVALIDO) return false;
	int ant = INVALIDO;
	int i = l->inicio;
	TIPOCHAVE ch = reg.chave;
	while((i!= INVALIDO) && (l->A[i].reg.chave<ch)){
		ant = i;
		i = l->A[i].prox;
	}
	if(i!=INVALIDO && l->A[i].reg.chave==ch) return false;
	i = obterNo(l);
	l->A[i].reg = reg;
	if(ant == INVALIDO){
		l->A[i].prox = l->inicio;
		l->inicio = i;
	}else{
		l->A[i].prox = l->A[ant].prox;
		l->A[ant].prox = i;
	}
}

void devolverNo(LISTA *l, int j){
	l->A[j].prox = l->dispo;
	l->dispo = j;
}

bool excluirElemLista(TIPOCHAVE ch, LISTA *l){
	int ant = INVALIDO;
	int i =l->inicio;
	while((i != INVALIDO) && (l->A[i].reg.chave < ch)){
		ant = i;
		i = l->A[i].prox;
	}
	
	if(i==INVALIDO || l->A[i].reg.chave!=ch) return false;
	if(ant==INVALIDO) l->inicio = l->A[i].prox;
	else l->A[ant].prox = l->A[i].prox;
	devolverNo(l,i);
	return true;
}



int main(){
	LISTA l1;
	REGISTRO r1, r2, r3;
	r1.chave = 12;
	r2.chave = 7;
	r3.chave = 9;
	iniciaLista(&l1);
	inserirElemListaOrd(&l1, r1);
	inserirElemListaOrd(&l1, r2);
	inserirElemListaOrd(&l1, r3);
	exibirLista(&l1);
	return 0;
}
