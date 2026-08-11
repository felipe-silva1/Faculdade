#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct No
{
    char nome[50];
    long cpf;
    long celular;
    struct No* prox;
} No;

No* CriarNo(const char* nome, long cpf,long celular)
{
    No* novo_no = (No*) malloc(sizeof(No));
    strcpy(novo_no->nome, nome);
    novo_no->cpf = cpf;
    novo_no->celular = celular;
    novo_no->prox = NULL;
    return novo_no;
}

No* CadastrarClienteFrente(No* cabeca, const char* nome, long cpf, long celular)
{
    No* novo_no = CriarNo(nome,cpf,celular);
    novo_no->prox = cabeca;
    return novo_no;
}

No* CadastrarClienteFim(No* cabeca, const char* nome, long cpf, long celular)
{
    No* novo_no = CriarNo(nome,cpf,celular);
    if(cabeca == NULL) return novo_no;

    No* atual = cabeca;
    while(atual->prox != NULL) atual = atual->prox;
    atual->prox = novo_no;
    return cabeca;
}

No* CadastrarClienteMeio(No* cabeca, const char* nome, long cpf, long celular, int pos)
{
    if(cabeca == NULL || pos <= 0) return CadastrarClienteFrente(cabeca,nome,cpf,celular);
    

    No* atual = cabeca;
    int index = 0;
    while(atual->prox != NULL && index < pos - 1)
    {
        atual = atual->prox;
        index++;
    }

    No* novo_no = CriarNo(nome,cpf,celular);
    novo_no->prox = atual->prox;
    atual->prox = novo_no;
    return cabeca;
}

No* ExcluirClienteFrente(No* cabeca)
{
    if(cabeca == NULL) return cabeca;
    No* temp = cabeca;
    cabeca = cabeca->prox;
    free(temp);
    return cabeca;
}

No* ExcluirClienteFim(No* cabeca)
{
    if(cabeca == NULL) return cabeca;
    if(cabeca->prox == NULL)
    {
        free(cabeca);
        cabeca = NULL;
        return cabeca;
    }
    No* atual = cabeca;
    while(atual->prox->prox != NULL) atual = atual->prox;
    free(atual->prox);
    atual->prox = NULL;
    return cabeca;
}

No* ExcluirClienteMeio(No* cabeca, int pos)
{
    if(cabeca == NULL) return cabeca;
    if(pos == 0) return ExcluirClienteFrente(cabeca);

    No* atual = cabeca;
    int index = 0;
    while(atual->prox != NULL && index < pos - 1)
    {
        atual = atual->prox;
        index++;
    }
    if(atual->prox == NULL) return cabeca;
    No* temp = atual->prox;
    atual->prox = temp->prox;
    free(temp);
    return cabeca;
}

void ExibirClientes(No* cabeca)
{
    No* atual = cabeca;
    printf("--------------Clientes--------------\n");
    if(atual == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    while(atual != NULL)
    {
        printf("\tNome: %s\n",atual->nome);
        printf("\tCPF: %ld\n", atual->cpf);
        printf("\tCelular: %ld\n",atual->celular);
        printf("------------------------------\n");
        atual = atual->prox;
    }
}

No* ConsultarClientesPorCPF(No* cabeca, long cpf)
{
    No* atual = cabeca;
    printf("--------------Consulta por CPF--------------\n");
    if(atual == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        return NULL;
    }
    while(atual != NULL)
    {
        if(atual->cpf == cpf)
        {
            printf("Cliente encontrado:\n");
            printf("\tNome: %s\n",atual->nome);
            printf("\tCPF: %ld\n", atual->cpf);
            printf("\tCelular: %ld\n",atual->celular);         
            return atual;   
        }
        atual = atual->prox;
    }
    printf("Nenhum cliente com o CPF %ld foi encontrado.\n",cpf);
    return NULL;
}

No* CadastrarCliente(No* cabeca)
{
    int opc,pos;
    char nome[50];
    long cpf,celular;
    printf("--------------Cadastrar Cliente--------------\n");
    printf("Nome: ");
    scanf(" %[^\n]", nome);
    printf("CPF: ");
    scanf(" %ld",&cpf);
    printf("Celular: ");
    scanf(" %ld",&celular);
    printf("1. Cadastrar Cliente no Comeco.\n");
    printf("2. Cadastrar Cliente no Final.\n");
    printf("3. Cadastrar Cliente no Meio.\n");
    scanf(" %d",&opc);
    switch (opc)
    {
    case 1:
    
        cabeca = CadastrarClienteFrente(cabeca, nome,cpf,celular);
        break;
    case 2:
        cabeca = CadastrarClienteFim(cabeca,nome,cpf,celular);
        break;
    case 3:
        printf("Digite a posicao que o cliente deve ser inserido: ");
        scanf(" %d", &pos);
        cabeca = CadastrarClienteMeio(cabeca,nome,cpf,celular,pos);
        break;
    default:
        printf("Opcao invalida.");
        break;
    }
    return cabeca;
}

No* ExcluirCliente(No* cabeca)
{
    int opc,pos;
    printf("--------------Excluir Cliente--------------\n");
    printf("1. Excluir Cliente no Comeco.\n");
    printf("2. Excluir Cliente no Final.\n");
    printf("3. Excluir Cliente no Meio.\n");
    scanf(" %d",&opc);
    switch (opc)
    {
    case 1:
        cabeca = ExcluirClienteFrente(cabeca);
        break;
    case 2:
        cabeca = ExcluirClienteFim(cabeca);
        break;
    case 3:
        printf("Entre com a posicao a ser excluida: ");
        scanf(" %d", &pos);
        cabeca = ExcluirClienteMeio(cabeca,pos);
        break;
    default:
        printf("Opcao invalida.");
        break;
    }
    return cabeca;
}

void Menu()
{
    No* noPrincipal = NULL;
    bool programaAtivo = true;
    long cpf;
    while(programaAtivo)
    {
        int opc;
        printf("--------------------Menu--------------------\n");
        printf("1. Cadastrar Cliente.\n");
        printf("2. Excluir Cliente.\n");
        printf("3. Exibir Clientes.\n");
        printf("4. Consultar Clientes Pelo CPF.\n");
        printf("5. Sair do Programa.\n");
        scanf(" %d", &opc);
        switch (opc)
        {
        case 1:
            noPrincipal = CadastrarCliente(noPrincipal);
            break;
        case 2:
            noPrincipal = ExcluirCliente(noPrincipal);
            break;
        case 3:
            ExibirClientes(noPrincipal);
            break;
        case 4:
            printf("Entre com o CPF do cliente que você deseja procurar: ");
            scanf(" %ld",&cpf);
            ConsultarClientesPorCPF(noPrincipal,cpf);
            break;
        case 5:
            printf("Saindo do programa...");
            return;    
        default:
            printf("Opcao invalida.");
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    Menu();
    return 0;
}
