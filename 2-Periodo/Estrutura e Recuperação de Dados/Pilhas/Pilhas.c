#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Pilha {
    struct No* topo;
} Pilha;

No* CriarNo(int valor)
{
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no; 
}

Pilha* push(Pilha* p, int valor)
{
    No* novo_no = CriarNo(valor);
    novo_no->prox = p->topo;
    p->topo = novo_no;
    return p;
}

Pilha* pop(Pilha* p)
{
    if(p->topo == NULL) return p;
    No* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    return p;
}