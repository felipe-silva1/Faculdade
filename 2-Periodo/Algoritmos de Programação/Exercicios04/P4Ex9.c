#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vetor[10], i;
    for(i = 0; i < 10; i++)
    {
        printf("Entre com um numero positivo: ");
        scanf("%d", &vetor[i]);
        if(vetor[i] < 0)
        {
            break;
        }
    }
    for(int j = 0; j < i; j++)
    {
        printf("\n%d", vetor[j]);
    }
    return 0;
}
