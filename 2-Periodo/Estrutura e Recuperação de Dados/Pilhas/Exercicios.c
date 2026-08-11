#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

typedef struct Pilha {
    struct No* topo;
} Pilha;

No* criarNo(int valor)
{
    No* novo_no = (No*) malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->prox = NULL;
    return novo_no;
}

Pilha* push(Pilha* p, int valor)
{
    No* novo_no = criarNo(valor);
    novo_no->prox = p->topo;
    p->topo = novo_no;
    return p;
}

bool verificarSeAPilhaEstaVazia(Pilha* p)
{
    if(p->topo == NULL) return true;
    return false;
}

Pilha* pop(Pilha* p)
{
    if(verificarSeAPilhaEstaVazia(p)) return p;
    No* temp = p->topo;
    p->topo = p->topo->prox;
    free(temp);
    return p;
}

void ExibirPilha(Pilha* p)
{
    if(verificarSeAPilhaEstaVazia(p))
    {
        printf("Pilha vazia.\n");
        return;
    }
    No* atual = p->topo;
    printf("Pilha: ");
    while(atual != NULL)
    {
        printf("%d ",atual->valor);
        atual = atual->prox;
    }
    printf("NULL.\n");
}

void Menu()
{
    int opc, valor;
    bool programaAtivo = true;
    Pilha* minhaPilha = (Pilha*) malloc(sizeof(Pilha));
    minhaPilha->topo = NULL;
    
    while(programaAtivo)
    {
        printf("---------------Menu---------------\n");
        printf("1. Push.\n");
        printf("2. Pop.\n");
        printf("3. Exibir Pilha.\n");
        printf("4. Encerrar Programa.\n");
        scanf(" %d",&opc);
        switch (opc)
        {
            case 1:
                printf("Entre com um valor a ser adicionado no topo: ");
                scanf(" %d", &valor);
                minhaPilha = push(minhaPilha,valor);
                break;
            case 2:
                minhaPilha = pop(minhaPilha);
                break;
            
            case 3:
                ExibirPilha(minhaPilha);
                break;
            case 4:
                printf("Encerrando program...");
                return;
            default:
                printf("Opcao Invalida.");
                break;
        } 
    }
}

int main(int argc, char const *argv[])
{
    Menu();
    return 0;
}
