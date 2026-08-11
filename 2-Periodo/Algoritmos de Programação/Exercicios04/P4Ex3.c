#include <stdio.h>

int main(int argc, char const *argv[])
{
    int X[20], N = 0, maior, menor,posMaior,posMenor;
    while (N < 1 || N > 20)
    {
        printf("Entre um numero entre 1 e 20: ");
        scanf("%d", &N);
    }
    for(int i = 0; i < N;i++)
    {
        printf("Entre o %d numero do vetor: ", i+1);
        scanf("%d", &X[i]);
        if(i == 0)
        {
            maior = X[i];
            menor = X[i];
        }
        else
        {
            if(X[i] > maior)
            {
                maior = X[i];
                posMaior = i;
            }
            if(X[i] < menor)
            {
                menor = X[i];
                posMenor = i;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        printf("%d\n",X[i]);
    }
    printf("Maior numero do vetor e o %d  e ele esta na posicao %d do vetor\nMenor numero do vetor e o %d e ele esta na posicao %d",maior, posMaior,menor, posMenor);
    return 0;
}
