#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Lista {
    No* inicio;
    int tamanho;
} Lista;

Lista* criarLista() {
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if (lista){
        lista->inicio = NULL;
        lista->tamanho = 0;
    }
    return lista;
}

void inserirInicio(Lista* lista,int v) {
    No* novo = (No*) malloc(sizeof(No));
    if(novo) {
        novo->valor = v;
        novo->prox = lista->inicio;
        lista->inicio = novo;
        lista->tamanho++;
    }
}

void inserirFim(Lista* lista, int v) {
    No* novo = (No*) malloc(sizeof(No));
    if(novo) {
        novo->valor = v;
        novo->prox = NULL;
        if(lista->inicio == NULL) {
            lista->inicio = novo;
        } else {
            No* temp = lista->inicio;
            while(temp->prox != NULL) {
                temp = temp->prox;
            }
            temp->prox = novo;
        }
        lista->tamanho++;
    }
}

void buscar(Lista* lista, int valor) {
    No* temp = lista->inicio;
    while(temp != NULL) {
        if(temp->valor == valor) {
            return temp;
        }
        temp = temp->prox;
    }
    return NULL;
}

No* remover(Lista* lista, int valor) {
    No* anterior = NULL;
    No* remover = lista->inicio;
    if(lista->inicio) {
        while(remover != NULL) {
            if(remover->valor == valor) {
                if(anterior == NULL) {
                    lista->inicio = remover->prox;
                } else {
                    anterior->prox = remover->prox;
                }
                lista->tamanho--;
                return remover;
            }
            anterior = remover;
            remover = remover->prox;
        }
    }
    return NULL;
}

void imprimirLista(const Lista* lista) {
    No* temp = lista->inicio;
    while(temp->prox != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->prox;
    }
    printf("NULL\n");
}

void liberarLista(Lista* lista) {
    No* atual = lista->inicio;
    while(atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(lista);
}