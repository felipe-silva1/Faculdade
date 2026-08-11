#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Fila {
    No* primeiro;
    No* ultimo;
    int tamanho;
} Fila;

No* criarNo(int valor) {
    No* novoNo = (No*) malloc(sizeof(No));
    if(!novoNo) {
        printf("Erro ao alocar memória para o no.");
    }
    novoNo->prox = NULL;
    novoNo->valor = valor;
    return novoNo;
}

Fila* criarFila() {
    Fila* novaFila = (Fila*) malloc(sizeof(Fila));
    if(!novaFila) {
        printf("Erro ao alocar memória para a fila.");
    }
    novaFila->primeiro = NULL;
    novaFila->ultimo = NULL;
    novaFila->tamanho = 0;
    return novaFila;
}

Fila* inserir(Fila* f, int valor) {
    No* novoNo = criarNo(valor);
    if(f->primeiro == NULL)
    {
        f->primeiro = novoNo;
        f->ultimo = novoNo;
    }else {
        f->ultimo->prox = novoNo;
        f->ultimo = novoNo;
    }
    return f;
}

Fila* remover(Fila* f) {
    if(f->primeiro == NULL) return f;
    No* temp = f->primeiro;
    f->primeiro = f->primeiro->prox;
    if(f->primeiro == NULL)
    {
        f->primeiro = NULL;
        f->ultimo = NULL;
    }
    free(temp);
    return f;
}