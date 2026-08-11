#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int valor;
    struct No *next;
} No;

typedef struct Pilha {
    struct No *topo;
} Pilha;

typedef struct Fila {
    struct No *first;
    struct No *last;
} Fila;

void inserirComeco(No *lista, int valor)
{
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->next = lista;
}

void inserirFinal(No *lista,int valor)
{
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->next = NULL;
    No* atual = lista;
    while(atual->next != NULL) atual = atual->next;

    atual->next = novo_no;
}

int remover(struct Fila *minhaFila)
{
    if(minhaFila == NULL) return -1;
    if(minhaFila->first == NULL) return -1;
    No* temp = minhaFila->first;
    minhaFila->first = minhaFila->first->next;
    int valor = temp->valor;
    if(minhaFila->first == NULL) minhaFila->last == NULL;
    free(temp);
    return valor;
}

int pop(Pilha *minhaPilha)
{
    if(minhaPilha == NULL) return -1;
    if(minhaPilha->topo == NULL) return-1;
    No* temp = minhaPilha->topo;
    int valor = temp->valor;
    minhaPilha->topo = minhaPilha->topo->next;
    free(temp);
    return valor;
}

void printLista(No *lista)
{
    No* atual = lista;
    printf("Lista: ");
    while(atual != NULL)
    {
        printf("%d ", atual->valor);
        atual = atual->next;
    }
}

int main(int argc, char const *argv[])
{
    
}
