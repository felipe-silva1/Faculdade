#include <stdio.h>

int A = 13;
int B = 5;
int aux = 0;

int main()
{
    aux = A;
    A = B;
    B = aux;
    printf("A = %i \nB = %i",A, B);
}