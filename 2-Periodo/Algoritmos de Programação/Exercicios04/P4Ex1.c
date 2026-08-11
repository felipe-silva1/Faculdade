#include <stdio.h>

int main()
{
    int X[20], Y[20], Z[20];
    int tamanho;

    printf("Digite o tamanho dos vetores (max 20): ");
    scanf("%d", &tamanho);
    while(tamanho > 20 || tamanho < 1)
    {
        printf("Digite um numero entre 1 e 20! ");
        scanf("%d", &tamanho);
    }
    for(int i = 0; i < tamanho; i++)
    {
        printf("Entre com o %d numero do vetor X: ",i+1);
        scanf("%d", &X[i]);
        printf("Entre com o %d numero do vetor Y: ", i+1);
        scanf("%d", &Y[i]);
        Z[i] = X[i] * Y[i];
    }
    printf("\nVetores:\n");
    for(int i = 0; i < tamanho; i++)
    {
        printf("\n%d * %d = %d",X[i], Y[i], Z[i]);
    }
    return 0;
}