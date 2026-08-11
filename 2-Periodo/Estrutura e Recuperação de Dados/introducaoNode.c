#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    char nome[100];
    long CPF, contato;
    struct Node* next;
} Node;

Node* create_node(char nome,long CPF, long contato)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node -> nome = nome;
    

}

void CadastrarCliente()
{

}

void ExcluirCliente()
{

}

void ExibirClientes()
{

}

void ConsultaPorCPF()
{

}

void Menu()
{

}

int main(int argc, char const *argv[])
{
    
    return 0;
}
