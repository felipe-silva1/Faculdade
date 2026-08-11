#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo;
    int tamanho;
} Pilha;

Pilha* criarPilha() {
    Pilha* novaPilha = (Pilha*) malloc(sizeof(Pilha));
    if(!novaPilha) {
        printf("Erro ao alocar memória para a pilha.\n");
    }
    novaPilha->topo = NULL;
    novaPilha->tamanho = 0;
    return novaPilha;
}
No* criarNo(int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    if(!novoNo) {
        printf('Erro ao alocar memória para o no.\n');
    }
    novoNo->prox = NULL;
    novoNo->valor = valor;
    return novoNo;
}

void empilhar(Pilha* pilha, int valor) {
    No* novoNo = criarNo(valor);
    novoNo->prox = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}

void desempilhar(Pilha* pilha) {
    if(pilha->topo == NULL) return pilha;
    No* temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    return pilha;
}