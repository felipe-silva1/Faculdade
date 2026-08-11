#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 64

typedef struct Node {
    char text[MAX_WORD_SIZE];
    struct Node *next;
} Node;

typedef struct Pilha {
    Node *top;
} Pilha;

Pilha* createStack() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->top = NULL;
    return p;
}

int isEmpty(Pilha *p) {
    return (p->top == NULL);
}

void push(Pilha *p, const char *text) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->text, text, MAX_WORD_SIZE - 1);
    newNode->text[MAX_WORD_SIZE - 1] = '\0';

    newNode->next = p->top;
    p->top = newNode;
}

char* pop(Pilha *p) {
    if (isEmpty(p)) {
        return NULL;
    }

    Node *temp = p->top;
    char *word = (char*)malloc(MAX_WORD_SIZE * sizeof(char));
    strncpy(word, temp->text, MAX_WORD_SIZE);
    
    p->top = temp->next;
    free(temp);

    return word;
}

void clearRedo(Pilha *p) {
    char *word;
    while (!isEmpty(p)) {
        word = pop(p);
        free(word);
    }
}

void insertString(Pilha *undo, Pilha *redo) {
    char input[MAX_WORD_SIZE];
    printf("Digite a nova palavra da frase: ");
    if (scanf("%s", input) == 1) {
        push(undo, input);
        printf("Ação: INSERIR \"%s\"\n", input);
        clearRedo(redo); // Esvazia REDO ao inserir nova string
    } else {
        printf("Erro de leitura.\n");
    }
}

void undoAction(Pilha *undo, Pilha *redo) {
    if (isEmpty(undo)) {
        printf("Aviso: Não há nada a desfazer (pilhaUNDO vazia).\n");
        return;
    }

    char *word = pop(undo); // Desempilha de UNDO
    if (word != NULL) {
        push(redo, word); // Empilha em REDO
        printf("Ação desfeita: \"%s\"\n", word);
        free(word);
    }
}

void redoAction(Pilha *undo, Pilha *redo) {
    if (isEmpty(redo)) {
        printf("Aviso: Não há nada a refazer (pilhaREDO vazia).\n");
        return;
    }

    char *word = pop(redo); // Desempilha de REDO
    if (word != NULL) {
        push(undo, word); // Empilha em UNDO
        printf("Ação refeita: \"%s\"\n", word);
        free(word);
    }
}

// Implementação da função auxiliar para imprimir da base ao topo
void imprimirRec(Node* no) {
    if (no == NULL) return;
    imprimirRec(no->next);
    printf("%s ", no->text);
}

// Imprime a frase atual (base da pilhaUNDO até o topo)
void ImprimirTexto(Pilha* p) {
    printf("\n> Frase atual: ");
    if (isEmpty(p)) {
        printf("[Frase vazia]");
    } else {
        imprimirRec(p->top);
    }
    printf("\n");
}

void freeStack(Pilha *p) {
    char *word;
    while (!isEmpty(p)) {
        word = pop(p);
        free(word);
    }
    free(p);
}

void printMenu() {
    printf("\n--- Editor de Texto (Undo/Redo) ---\n");
    printf("Digite a opção desejada:\n");
    printf("0 - Digitar nova palavra da frase\n");
    printf("1 - Desfazer (Undo)\n");
    printf("2 - Refazer (Redo)\n");
    printf("3 - Imprimir a frase\n");
    printf("4 - Sair\n");
    printf("Qual opção? ");
}

int main() {
    Pilha *pilhaUNDO = createStack();
    Pilha *pilhaREDO = createStack();
    int option;

    do {
        printMenu();
        if (scanf("%d", &option) != 1) {
            while (getchar() != '\n');
            option = -1;
            printf("\nOpção inválida. Tente novamente.\n");
            continue;
        }

        switch (option) {
            case 0:
                insertString(pilhaUNDO, pilhaREDO);
                break;
            case 1:
                undoAction(pilhaUNDO, pilhaREDO);
                break;
            case 2:
                redoAction(pilhaUNDO, pilhaREDO);
                break;
            case 3:
                ImprimirTexto(pilhaUNDO);
                break;
            case 4:
                printf("\nSaindo do editor. Memória liberada.\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (option != 4);

    freeStack(pilhaUNDO);
    freeStack(pilhaREDO);

    return 0;
}