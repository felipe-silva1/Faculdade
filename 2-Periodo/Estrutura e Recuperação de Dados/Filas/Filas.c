#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int valor;
    struct No* next;
} No;

typedef struct Queue
{
    struct No* first;
    struct No* last;
} Queue;

No* create_node(int valor)
{
    No* novo_no = (No*) malloc(sizeof(No*));
    novo_no->valor = valor;
    novo_no->next = NULL;
    return novo_no;
}

Queue* insert_node(Queue *q, int valor)
{
    No* novo_no = create_node(valor);
    if(q->last == NULL)
    {
        q->first = novo_no;
        q->last = novo_no;
    } else {
        q->last->next = novo_no;
        q->last = novo_no;
    }

    return q;
}

Queue* remove_node(Queue *q)
{
    if(q->first == NULL) return q;

    No* temp = q->first;
    q->first = q->first->next;

    if(q->first == NULL) q->last = NULL;
    
    free(temp);
    return q;
}