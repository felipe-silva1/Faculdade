#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    Node* Left;
    Node* Right;
} Node;

typedef struct Tree {
    Node* root;
} Tree;

Tree* CreateTree() 
{
    Tree* new_tree = (Tree*) malloc(sizeof(Tree));
    new_tree->root = NULL;
    return new_tree;
}

Node* insert_node(Node* no,int value)
{
    if(no == NULL)
    {
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->value = value;
        new_node->Right = NULL;
        new_node->Left = NULL;
        return new_node;
    }
    if(value < no->value)
    {
        no->Left = insert_node(no->Left,value);
    }
    else if(value > no->value)
    {
        no->Right = insert_node(no->Right,value);
    }
    return no;
}

void Insert(Tree* Tree, int value)
{
    Tree->root = insert_node(Tree->root,value);
}

void PrintNode(Node* no,int level)
{
    if(no != NULL)
    {
        char txt[100];
        txt[0] = '\0';

        for(int i = 0; i < level - 1;i++)
        {
            strcat(txt, "  ");
        }
        if(level > 0) strcat(txt,"|..");
        printf("%s%d\n",txt,no->value);
        PrintNode(no->Left,level+1);
        PrintNode(no->Right,level+1);
    }
}

void Print(Tree* Tree)
{
    PrintNode(Tree->root,0);
    printf("\n");
}

bool SearchNode(Node * no,int value)
{
    if(no == NULL) return false;
    if(no->value == value) return true;
    if(value < no->value) return SearchNode(no->Left,value);
    else return SearchNode(no->Right,value);
}

bool Search(Tree * Tree, int value)
{
    return SearchNode(Tree->root,value);
}

Node* RemoveNode(Node* no,int value)
{
    if(no==NULL) return NULL;
    if(value < no->value) no->Left = RemoveNode(no->Left,value);
    else if(value > no->value) no->Right = RemoveNode(no->Right,value);
    else
    {
        if(no->Left == NULL)
        {
            Node * temp = no->Right;
            free(no);
            return temp;
        }
        else if(no->Right == NULL)
        {
            Node * temp = no->Left;
            free(no);
            return temp;
        }

        Node * temp = no->Right;
        while(temp && temp->Left != NULL)
        {
            temp = temp->Left;
        }
        no->value = temp->value;
        no->Right = RemoveNode(no->Right,temp->value);
    }
    return no;
}

void RemoveTree(Tree * Tree, int value)
{
    Tree->root = RemoveNode(Tree->root,value);
}