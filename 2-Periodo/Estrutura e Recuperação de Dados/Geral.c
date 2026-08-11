#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node* next;
} Node;

typedef struct Queue {
    struct Node* first;
    struct Node* last;
} Queue;

typedef struct Stack {
    struct Node* top;
} Stack;

// Criação de nós

Node* create_node(int valor)
{
    // Alocação do nó na memoria
    Node* new_node = (Node*) malloc(sizeof(Node));
    // Definição de valores
    new_node->valor = valor;
    new_node->next = NULL;
    return new_node;
}

// Listas Encadeadas

Node* insert_front(Node* head,int valor)
{
    // Criação de um novo nó
    Node* new_node = create_node(valor);
    // Se a lista estiver vazia acrescenta o novo nó e sai da função
    if(head == NULL) return new_node;
    // Liga o next do novo nó com a cabeça da lista, assim se tornando a nova cabeça e tomando o primeiro lugar da lista.
    new_node->next = head;
    return head;
}

Node* insert_back(Node* head,int valor)
{
    // Criação de um novo nó
    Node* new_node = create_node(valor);
    // Se a lista estiver vazia ascrescenta o novo nó e sai da função
    if(head == NULL) return new_node;
    // Inicializa o current na 'cabeça' da lista
    Node* current = head;
    // Loop para percorrer toda a função até o ultimo elemento da mesma
    while(current->next != NULL) current = current->next;
    // Liga o ultimo elemento da lista ao novo nó, assim o novo nó se torna o último elemento da lista
    current->next = new_node;
    return head;
}

Node* insert_at(Node* head,int valor,int pos)
{
    // Criação de um novo nó
    Node* new_node = create_node(valor);
    // Verifica se a lista ou está vazia ou a posição que o usuário inseriu e menor ou igual a 0, se as condições forem satisfeitas a função simplesmente retorna o insert_front e não executa mais nada.
    if(head == NULL || pos <= 0) return insert_front(head,valor);
    // Inicializa o current na 'cabeça' da lista
    Node* current = head;
    // Inicializa a variável index para ser usada como controle da posição que o loop deve parar
    int index = 0;
    // Loop para percorrer a lista e parar um indice antes da posição desejada
    while(current->next != NULL && index != pos-1)
    {
        current = current->next;
        index++;
    }
    // Liga o novo nó ao próximo elemento 
    new_node->next = current->next;
    // Liga o elemento que o loop parou ao novo nó assim fazendo o novo nó tomar seu lugar 
    current->next = new_node;
    return head;
}

Node* delete_front(Node* head)
{
    // A função não fará nada se a lista estiver vazia.
    if(head == NULL) return NULL;
    // Cria uma variável temp para limpar da memória o item deletado após a execução da função.
    Node* temp = head;
    // Define o segundo elemento como o novo primeiro elemento.
    head = head->next;
    // Libera da memória o primeiro elemento deletado.
    free(temp);
    return head;
}

Node* delete_back(Node* head)
{
    // A função não fará nada se a lista estiver vazia.
    if(head == NULL) return NULL;
    // Verifica se a função não possui apenas um elemento.
    if(head->next == NULL)
    {
        // Se a condição for satisfeita
        free(head);
        head = NULL;
        return head;
    }
    // Inicializa o current como a 'cabeça' da lista.
    Node* current = head;
    // Loop para percorrer toda lista até o penúltimo elemento.
    while(current->next->next != NULL) current = current->next;
    // Libera da memória o último elemento.
    free(current->next);
    // Liga o agora atual último elemento a nada, indicando que é o atual último elemento
    current->next = NULL;
    return head;
}

Node* delete_at(Node* head, int pos)
{
    // Verifica se a lista não está vazia ou a posição inserida não é negativa, caso a condição for satisfeita apenas sai da função para evitar erro.
    if(head == NULL || pos < 0) return head;
    // Se a posição for igual a 0 isso seria mesma coisa que deletar o primeiro elemento portando a função delete_front é chamada e para de executar a atual função.
    if(pos == 0) return delete_front(head);
    // Inicializa o current como a 'cabeça' da lista.
    Node* current = head;
    // Inicializa a variável index para ser usada como controle da posição que o loop deve parar.
    int index = 0;
    // Loop para percorrer a lista e parar um indice antes da posição desejada;
    while(current->next != NULL && index != pos-1)
    {
        current = current->next;
        index++;
    }
    // Sai da função se não achar a posição inserida dentro da lista.
    if(current->next == NULL) return head;
    // Cria uma variável temp para limpar da memória o item deletado após a execução da função.
    Node* temp = current->next;
    // Define o elemento a ser apagado como o elemento na frente dele.
    current->next = temp->next;
    // Libera da memoria o elemento apagado.
    free(temp);
    return head;
}

// Filas
// P.S Filas diferente de listas encadeadas, utilizam o conceito de FIFO(First in First out) ou seja,SEMPRE inserem e deletam itens da última e primeira posição respectivamente, como numa fila real que quando uma pessoa entra na fila ela entra no final e quando sai da fila é porque ela é a primeira pessoa e foi chamada.

Queue* insert_queue(Queue* q, int valor)
{
    // Criação de nó
    Node* new_node = create_node(valor);
    // Se a fila estiver vazia inicializa o novo nó como tanto o primeiro quanto o último elemento.
    if(q == NULL)
    {
        q->first = new_node;
        q->last = new_node;
    }
    else
    {
        // Liga o antigo último elemento ao novo nó.
        q->last->next = new_node;
        // Define o último elemento como o novo nó.
        q->last = new_node;
    }
    return q;
}

Queue* delete_queue(Queue* q)
{
    // Verifica se a fila não está vazia, se estiver escapa da função.
    if(q == NULL) return q;
    // Cria uma variável temp para limpar da memória o item deletado após a execução da função
    Node* temp = q->first;
    // Primeiro elemento recebe o valor do segundo.
    q->first = q->first->next;
    // Verifica se após deletar esse elemento a lista não ficará vazia, se sim ele reseta a fila para que ela não aponte para nada.
    if(q->first == NULL) q->last = NULL;
    // Libera da memória o item deletado.
    free(temp);
    return q;
}

// Pilhas
// P.S Pilhas também diferentemente de listas, utilizam o conceito de LIFO(Last in First out) ou seja, as Pilhas SEMPRE inserem e deletam elementos do mesmo lugar que é definido como topo, como numa pilha de louça que o último prato colocado será o primeiro a ser lavado.

Stack* insert_stack(Stack* s, int valor)
{
    // Criação de um novo nó.
    Node* new_node = create_node(valor);
    // Liga o novo nó ao primeiro elemento da pilha.
    new_node->next = s->top;
    // Define o novo nó como o primeiro elemento da pilha, que agora está ligado ao antigo primeiro elemento.
    s->top = new_node;
    return s;
}
Stack* delete_stack(Stack* s)
{
    // Verifica se a pilha não está vazia, se sim escapa da função.
    if(s == NULL) return s;
    // Cria uma variável temp para limpar da memória o item deletado após a execução da função.
    Node* temp = s->top;
    // Define o segundo elemento como o novo topo da pilha.
    s->top = s->top->next;
    // Deleta da memória o antigo primeiro elemento.
    free(temp);
    return s;
}