#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char nome[50];
    char cpf[12];
} Pessoa;

typedef struct 
{
    char titulo[50];
    char autor[50];
    int anoPublicacao;
    int id;
    int qntdDisponivel;
    Pessoa pessoas[10];
    int qntdPessoas;
} Livro;

typedef struct 
{
    Livro livros[100];
    int qntdLivros;
} Biblioteca;

void CadastroDeLivros(Biblioteca *b)
{
    if(b->qntdLivros >= 100)
    {
        printf("Biblioteca Cheia!\n");
        return;
    }
    Livro l;
    printf("-------------Cadastro de Livros-------------\n");
    printf("Entre com o ID do livro a ser adicionado:\n");
    scanf("%d",&l.id);
    for(int i = 0; i < b->qntdLivros; i++)
    {
        if(l.id == b->livros[i].id)
        {
            printf("ID ja registrado!");
            return;
        }
    }
    printf("Titulo do livro: \n");
    scanf(" %[^\n]", l.titulo);
    printf("Autor: \n");
    scanf(" %[^\n]", l.autor);
    printf("Ano de publicacao:\n");
    scanf("%d", &l.anoPublicacao);
    printf("Quantidade disponivel: (max: 10)\n");
    scanf("%d", &l.qntdDisponivel);
    while(l.qntdDisponivel > 10 || l.qntdDisponivel < 0)
    {
        printf("Quantidade disponivel: (max: 10)\n");
        scanf("%d", &l.qntdDisponivel);       
    }
    l.qntdPessoas = 0;
    b->livros[b->qntdLivros] = l;
    b->qntdLivros++;
}

void ConsultaDeLivros(Biblioteca *b)
{
    int opc;
    printf("-------------Consulta de Livros-------------\n");
    printf("\t1. Listar todos os livros cadastrados \n\t2. Buscar um livro especifico por ID\n");
    scanf("%d", &opc);
    switch (opc)
    {
        case 1:
            if(b->qntdLivros == 0)
            {
                printf("Nenhum livro cadastrado na biblioteca.\n");
            }
            else
            {
                for(int i = 0; i < b->qntdLivros;i++)
                {
                    printf("%s\n\tAutor: %s\n\tAno de Publicacao: %d\n\tCodigo Unico(ID): %d\n\tQuantidade Disponivel: %d\n",b->livros[i].titulo,b->livros[i].autor,b->livros[i].anoPublicacao,b->livros[i].id,b->livros[i].qntdDisponivel);
                }
            }
            break;
        case 2:
            {
                int idBusca;
                bool livroEncontrado = false;
                printf("Entre com o ID do livro que voce deseja consultar: \n");
                scanf("%d",&idBusca);
                for(int i = 0; i < b->qntdLivros;i++)
                {
                    if(idBusca == b->livros[i].id)
                    {
                        printf("%s\n\tAutor: %s\n\tAno de Publicacao: %d\n\tCodigo Unico(ID): %d\n\tQuantidade Disponivel: %d\n",b->livros[i].titulo,b->livros[i].autor,b->livros[i].anoPublicacao,b->livros[i].id,b->livros[i].qntdDisponivel);
                        livroEncontrado = true;
                        break;
                    }
                }        
                if (livroEncontrado == false)
                {
                    printf("Erro: Livro com ID %d nao encontrado!\n",idBusca);
                }
                break;
            }
        default:
            printf("Erro: Entre uma opcao valida!\n");
            break;
    }
}

void EmprestimoDeLivros(Biblioteca *b)
{
    Pessoa p;
    int idBusca;
    bool livroEncontrado = false;
    printf("-------------Emprestimo de Livros-------------\n");
    printf("Entre com o ID do livro que voce deseja pegar emprestado: \n");
    scanf("%d", &idBusca);
    for(int i = 0; i < b->qntdLivros; i++)
    {
        if(idBusca == b->livros[i].id)
        {
            livroEncontrado = true;
            if(b->livros[i].qntdDisponivel == 0)
            {
                printf("Livro fora de estoque!\n");
                return;
            }
            else{
                bool pessoaEncontrada = false;
                printf("Entre com o seu nome: \n");
                scanf(" %[^\n]", p.nome); 
                printf("Entre com o seu CPF: \n");
                scanf(" %[^\n]", p.cpf);
                for(int j = 0; j < b->livros[i].qntdPessoas;j++)
                {
                    if(strcmp(p.cpf, b->livros[i].pessoas[j].cpf) == 0)
                     {
                        pessoaEncontrada = true;
                        break;
                    }
                }
                if(pessoaEncontrada)
                {
                    printf("O livro ja foi emprestado para o mesmo CPF!\n");
                }
                else
                {
                    b->livros[i].pessoas[b->livros[i].qntdPessoas] = p;
                    b->livros[i].qntdDisponivel--;
                    b->livros[i].qntdPessoas++;
                }
            }
            break;
        }
    }
    if(livroEncontrado == false)
    {
        printf("Livro nao encontrado!\n");
    }
}

void DevolucaoDeLivros(Biblioteca *b)
{
    int idBusca;
    char cpfBusca[12]; 
    bool cpfEncontrado = false;
    bool livroEncontrado = false;
    int indicePessoa;
    printf("-------------Devolucao de Livros-------------\n");
    printf("Entre com o ID do livro que voce deseja devolver: \n");
    scanf("%d", &idBusca);
    for(int i = 0; i < b->qntdLivros; i++)
    {
        if(idBusca == b->livros[i].id)
        {
            livroEncontrado = true;

            if(b->livros[i].qntdPessoas == 0)
            {
                printf("Erro: Este livro(%s) nao possui emprestimos ativos.\n",b->livros[i].titulo);
                break;
            }
            printf("Digite o seu CPF: \n");
            getchar();
            scanf(" %[^\n]", cpfBusca);
            for(int j = 0; j < b->livros[i].qntdPessoas;j++)
            {
                if(strcmp(cpfBusca, b->livros[i].pessoas[j].cpf) == 0)
                {
                    cpfEncontrado = true;
                    indicePessoa = j;
                    break;
                }
            }
            if(cpfEncontrado)
            {
                for(int k = indicePessoa; k < b->livros[i].qntdPessoas - 1; k ++)
                {
                    b->livros[i].pessoas[k] = b->livros[i].pessoas[k + 1];
                }
                b->livros[i].qntdDisponivel++;
                b->livros[i].qntdPessoas--;
                printf("Devolucao realizada com sucesso!\n");
                }
                else
                {
                    printf("Erro: CPF %s nao encontrado na lista de emprestimo deste livro.\n",cpfBusca);
                }
                break;
        }
       
    }
    if(livroEncontrado == false)
    {
        printf("Erro: Livro com o ID %d nao encontrado!\n",idBusca);
    }
}

void RemocaoDeLivros(Biblioteca *b)
{
    int idBusca;
    bool livroEncontrado = false;
    int indiceLivro = -1;
    char tituloRemovido[50];
    printf("-------------Remocao de Livros-------------\n");
    if(b->qntdLivros == 0)
    {
        printf("Erro: A biblioteca esta vazia. Nenhum livro para remover.\n");
        return;
    }
    printf("Entre com o ID do livro que voce deseja remover: \n");
    scanf("%d", &idBusca);
    for(int i = 0; i < b->qntdLivros;i++)
    {
        if(idBusca == b->livros[i].id)
        {
            livroEncontrado = true;
            indiceLivro = i;
            strcpy(tituloRemovido, b->livros[i].titulo);
            break;
        }
    }
    if(livroEncontrado == false)
    {
        printf("Erro: Livro com ID %d nao encontrado!\n",idBusca);
        return;
    }
    if (b->livros[indiceLivro].qntdPessoas > 0)
    {
        printf("Erro: O livro '%s' (ID %d) nao pode ser removido.\n",tituloRemovido,idBusca);
        printf("Motivo: Ha %d emprestimo(s) ativo(s) para este livro.\n",b->livros[indiceLivro].qntdPessoas);
        return;
    }

    for(int j = indiceLivro; j < b->qntdLivros - 1; j++)
    {
        b->livros[j] = b->livros[j + 1];
    }
    b->qntdLivros--;
    printf("Livro '%s' (ID %d) removido com sucesso!\n",tituloRemovido,idBusca);
}

void Menu()
{
    bool programaAtivo = true;
    Biblioteca biblioteca;
    biblioteca.qntdLivros = 0;
    while(programaAtivo)
    {
        int opc;
        printf("------------------Menu------------------\n");
        printf("1. Cadastro de Livros.\n");
        printf("2. Consulta de Livros.\n");
        printf("3. Emprestimo de Livros.\n");
        printf("4. Devolucao de Livros.\n");
        printf("5. Remocao de Livros.\n");
        printf("6. Encerrar o program.\n");
        scanf("%d",&opc);
        switch (opc)
        {
        case 1:
            CadastroDeLivros(&biblioteca);
            break;
        case 2:
            ConsultaDeLivros(&biblioteca);
            break;
        case 3:
            EmprestimoDeLivros(&biblioteca);
            break;
        case 4:
            DevolucaoDeLivros(&biblioteca);
            break;
        case 5:
            RemocaoDeLivros(&biblioteca);
            break;
        case 6:
            printf("Encerrando programa...");
            programaAtivo = false;
            break;
        default:
            break;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    Menu();
    return 0;
}
