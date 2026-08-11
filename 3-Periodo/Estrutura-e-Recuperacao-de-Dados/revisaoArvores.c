#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore {
    NoArv* raiz;
} Arvore;

typedef struct NoArv {
    int valor;
    struct NoArv* esq;
    struct NoArv* dir;
}NoArv;

Arvore* criarArvore() {
    Arvore* arvore = (Arvore*) malloc(sizeof(Arvore));
    if(!arvore) {
        printf("Erro ao alocar arvore na memoria.");
    }
    arvore->raiz = NULL;
    return arvore;
}

NoArv* criarNoArv(int valor) {
    NoArv* novoNo = (NoArv*) malloc(sizeof(NoArv));
    if(!novoNo) {
        printf("Erro ao alocar no na memoria.");
    }
    novoNo->dir = NULL;
    novoNo->esq = NULL;
    novoNo->valor = valor;
    return novoNo;
}

NoArv* inserir(Arvore* arvore, int valor) {
    NoArv* novoNo = criarNoArv(valor);
    if(arvore->raiz == NULL) {
        arvore->raiz = novoNo;
        return novoNo;
    }
    NoArv* atual = arvore->raiz;
    NoArv* pai = NULL;
    while(atual != NULL) {
        pai = atual;
        if(valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    if(valor < pai->valor) {
        pai->esq = novoNo;
    } else {
        pai->dir = novoNo;
    }
    return novoNo;
}

NoArv* buscar(Arvore* arvore, int valor) {
    NoArv* atual = arvore->raiz;
    while(atual != NULL) {
        if(valor == atual->valor) {
            return atual;
        } else if(valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    return NULL;
}

void removoer(Arvore* arvore, int valor) {
    NoArv* atual = arvore->raiz;
    NoArv* pai = NULL;
    while(atual != NULL && atual->valor != valor) {
        pai = atual;
        if(valor < atual->valor) {
            atual = atual->esq;
        } else {
            atual = atual->dir;
        }
    }
    if(atual == NULL) {
        printf("Valor %d nao encontrado.\n", valor);
        return;
    }
    if(atual->esq == NULL || atual->dir == NULL) {
        NoArv* temp = (atual->esq != NULL) ? atual->esq : atual->dir;

        if(pai == NULL) {
            arvore->raiz = temp;
        } else if(pai->esq == atual) {
            pai->esq = temp;
        } else {
            pai->dir = temp;
        }
        free(atual);
    } else {
        NoArv* sucessorPai = atual;
        NoArv* sucessor = atual->dir;
        
        while(sucessor->esq != NULL) {
            sucessorPai = sucessor;
            sucessor = sucessor->esq;
        }

        if(sucessorPai != atual) {

        }
    }
}

int menorABB(NoArv *raiz) {
    NoArv* atual = raiz;
    NoArv* pai = NULL;
    if(atual == NULL) {
        return NULL;
    }
    while(atual != NULL) {
        pai = atual;
        atual = atual->esq;
    }

    return pai->valor;
}