#include <stdio.h>

int main(int argc, char const *argv[])
{
    int X[20], Y[20], N = 0;
    while(N < 1 || N > 20)
    {
        printf("Entre com um numero de 1 a 20: ");
        scanf("%d", &N);
    }
    for(int i = 0;i < N; i++)
    {
        printf("Entre com o %d numero do vetor: ",i+1);
        scanf("%d", &X[i]);
    }
    for(int i = 0; i< N; i++)
    {
        Y[i] = X[(N - 1) - i];
    }
    printf("Vetores:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d\t%d\n",X[i], Y[i]);
    } 
    return 0;
}
