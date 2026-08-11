#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct 
{
    char nome[50];
    int idade;
}Pessoa;


void receberPessoa(Pessoa *p1)
{
    printf("Entre com o nome da pessoa que voce deseja inserir: ");
    scanf(" %49[^\n]", p1->nome);
    getchar();
    printf("Entre com a idade da pessoa que voce deseja inserir: ");
    scanf("%d", &p1->idade);
    printf("Nome: %s\nIdade: %d\n",p1->nome,p1->idade);
}

const char* PessoaMaisVelha(const Pessoa *p1,const Pessoa *p2)
{
    if(p1->idade > p2->idade)
    {
        return p1->nome;
    }
    else
    {
        return p2->nome;
    }
}

bool MaiorDeIdade(Pessoa *p1)
{
    if(p1->idade >= 18)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MostrarNomesCadastrados(int sz, Pessoa **pessoas)
{
    printf("\n--- Nomes Cadastrados ---\n");
    for(int i = 0; i < sz; i++)
    {
        printf("Nome da pessoa %d: %s\n",i + 1,pessoas[i]->nome);
    }
}

void ProcurarPorNome(int sz, Pessoa **pessoas,Pessoa *p1)
{
    bool pessoaEncontrada = false;
    for(int i = 0; i < sz; i++)
    {
        if(strcpy(p1->nome,pessoas[i]->nome) == 0)
        {
            printf("Nome: %s\nIdade: %d\n",pessoas[i]->nome,pessoas[i]->idade);
            pessoaEncontrada = true;
        }
    }
    if(pessoaEncontrada == false)
    {
        printf("Pessoa nao encontrada");
    }
}

int main(int argc, char const *argv[])
{
    Pessoa *pessoa1 = malloc(sizeof(Pessoa));
    Pessoa *pessoa2 = malloc(sizeof(Pessoa));
    receberPessoa(pessoa1);
    receberPessoa(pessoa2);

    const char* nomeMaisVelho = PessoaMaisVelha(pessoa1,pessoa2);
    printf("A pessoa mais velha eh o(a) %s.\n",nomeMaisVelho);

    if(MaiorDeIdade(pessoa1))
    {
        printf("O(A) %s eh maior de idade.\n",pessoa1->nome);
    }
    else
    {
        printf("O(A) %s nao eh maior de idade.\n",pessoa1->nome);
    }

    Pessoa *pessoaVec[3];
    for(int i = 0;i<3;i++)
    {
        pessoaVec[i] = malloc(sizeof(Pessoa));
        if (pessoaVec[i] == NULL)
        {
            printf("Erro de alocacao de memoria!\n");
            return 1;
        }
        receberPessoa(pessoaVec[i]);
    }
    MostrarNomesCadastrados(3,pessoaVec);
    ProcurarPorNome(3,pessoaVec,pessoa1);
    free(pessoa1);
    free(pessoa2);
    for(int i = 0;i < 3;i++)
    {
        free(pessoaVec[i]);
    }
    return 0;
}
