#include <stdio.h>
#include <stdlib.h>


// Estrutura do nó
typedef struct Node 
{
    int value;
    struct Node* next;
}Node;


// Criar nó
Node* create_node(int value)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

// Inserir nó no começo
Node* insert_front(Node* head, int value)
{
    Node* new_node = create_node(value);
    new_node->next = head;
    return new_node;
}

// Inserir nó no final
Node* insert_back(Node* head, int value)
{
    Node* new_node = create_node(value);
    if(head == NULL) return new_node;

    Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = new_node;
    return head;    
}

// Inserir no meio
Node* insert_at(Node* head, int value, int pos)
{
    if(pos <= 0 || head == NULL) return insert_front(head,value);

    Node* current = head;
    int index = 0;

    while(current->next != NULL && index != pos-1)
    {
        current = current->next;
        index++;
    }

    Node* new_node = create_node(value);
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// Remover no começo
Node* remove_front(Node* head)
{
    if(head == NULL) return NULL;
    Node* temp = head;
    head = head-> next;
    free(temp);
    return head;
}

//Remover no final
Node* remove_back(Node* head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return head;
    }
    Node* current = head;
    while(current->next->next != NULL) current = current->next;
    free(current->next);
    current->next = NULL;
    return head;
}

//Remover no meio
Node* remove_at(Node* head, int pos)
{
    if(head == NULL || pos < 0) return head;
    if(pos == 0) return remove_front(head);

    Node* current = head;
    int index = 0;
    while(current->next != NULL && index < pos-1)
    {
        current = current->next;
        index++;
    }

    if(current->next == NULL) return head;
    Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

Node* search(Node* head, int value)
{
    Node* current = head;
    while(current->next != NULL)
    {
        if(current->value == value)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void free_list(Node* head)
{
    Node* current = head;
    while(current->next != NULL)
    {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_list(Node*head)
{
    Node* current = head;
    printf("Lista: ");
    while(current->next != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
