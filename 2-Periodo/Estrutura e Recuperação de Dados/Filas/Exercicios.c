#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No {
    char nome[50];
    int idade;
    int id;
    struct No* prox;
} No;

typedef struct Fila {
    struct No* first;
    struct No* last;
} Fila;

No* CriarNo(const char* nome,int idade,int id)
{
    No* novo_no = (No*) malloc(sizeof(No));
    strcpy(novo_no->nome, nome);
    novo_no->idade = idade;
    novo_no->id = id;
    novo_no->prox = NULL;
    return novo_no;
}

Fila* AdicionarPaciente(Fila* f, const char* nome,int idade,int id)
{
    No* novo_no = CriarNo(nome,idade,id);
    if(f->last == NULL)
    {
        f->first = novo_no;
        f->last = novo_no;
    }
    else
    {
        f->last->prox = novo_no;
        f->last = novo_no;
    }
    
    return f;
}

Fila* AtenderProxPaciente(Fila* f)
{
    if(f->first == NULL) return f;
    printf("Proximo Paciente:\n");
    printf("Numero de Chamada: %d.\n",f->first->id);
    printf("Nome: %s.\n",f->first->nome);
    No* temp = f->first;
    f->first = f->first->prox;

    if(f->first == NULL) f->last = NULL;

    free(temp);
    return f;
}

void ExibirFila(Fila* f)
{
    int index = 0;
    No* atual = f->first;
    printf("Fila: \n");
    while(atual != NULL)
    {
        printf("%d da fila:\n",(index+1));
        printf("Nome: %s.\n",atual->nome);
        printf("Numero da Chamada: %d.\n",atual->id);
        printf("Idade: %d.\n",atual->idade);
        printf("-------------------------\n");
        atual = atual->prox;
        index++;
    }
}

void ProcurarPacienteMaisIdoso(Fila* f)
{
    int maiorIdade = 0;
    No* atual = f->first;
    while(atual != NULL)
    {
        if(atual->idade >= maiorIdade) maiorIdade = atual->idade;
        atual = atual->prox;
    }
    printf("Paciente(s) mais idoso(s): (%d anos) ",maiorIdade);
    atual = f->first;
    while(atual != NULL)
    {
        if(atual-> idade == maiorIdade) printf("%s, ", atual->nome);
        atual = atual->prox;
    }
    printf("\n");
}

void Menu()
{
    int opc, idade,id;
    char nome[50];
    bool programaAtivo = true;
    Fila* minhaFila = (Fila*) malloc(sizeof(Fila));
    minhaFila->first = NULL;
    minhaFila->last = NULL;
    while(programaAtivo)
    {
        printf("----------------------Menu----------------------\n");
        printf("1. Adicionar Paciente.\n");
        printf("2. Atender Proximo Paciente.\n");
        printf("3. Exibir Fila.\n");
        printf("4. Procurar Paciente(s) Mais Idoso(s).\n");
        printf("5. Sair do programa.\n");
        scanf(" %d", &opc);
        switch (opc)
        {
        case 1:
            printf("-------------Adicionar Paciente-------------\n");
            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("Idade: ");
            scanf(" %d", &idade);
            printf("Numero de Chamada: ");
            scanf(" %d", &id);
            minhaFila = AdicionarPaciente(minhaFila, nome,idade,id);
            break;
        case 2:
            printf("-------------Atender proximo Paciente-------------\n");
            minhaFila = AtenderProxPaciente(minhaFila);
            break;
        case 3:
            printf("-------------Exibir Fila-------------\n");
            ExibirFila(minhaFila);
            break;
        case 4:
            printf("-------------Exibir Fila-------------\n");
            ProcurarPacienteMaisIdoso(minhaFila);
            break;
        case 5:
            printf("Encerrando programa...");
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
