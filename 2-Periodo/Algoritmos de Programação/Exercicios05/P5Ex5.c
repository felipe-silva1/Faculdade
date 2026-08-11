#include <stdio.h>

int main(int argc, char const *argv[])
{
    int Ai, Aj, Bi, Bj;
    printf("Entre com a quantidade de linhas da matriz A: ");
    scanf("%d", &Ai);
    printf("Entre com a quantidade de colunas da matriz A: ");
    scanf("%d", &Aj);
    printf("Entre com a quantidade de linhas da matriz B: ");
    scanf("%d", &Bi);
    printf("Entre com a quantidade de colunas da matriz B: ");
    scanf("%d", &Bj);
    double A[Ai][Aj], B[Bi][Bj],C[Ai][Bj],soma = 0;
    if(Ai == Bj)
    {
        for(int i = 0;i < Ai; i++)
        {
            for(int j = 0;j < Aj;j++)
            {
                printf("Entre com o elemento A[%d][%d]",i,j);
                scanf("%lf",&A[i][j]);
            }
        }
        for(int i = 0;i < Bi; i++)
        {
            for(int j = 0;j < Bj;j++)
            {
                printf("Entre com o elemento B[%d][%d]",i,j);
                scanf("%lf",&B[i][j]);
            }
        }
        for(int i = 0;i < Ai; i++)
        {
            for(int j = 0;j < Bj;j++)
            {
                soma = 0;
                for(int k = 0; k < Aj;k++)
                {
                    soma += A[i][k] * B[k][j];
                }
                C[i][j] = soma;
            }
        }
        for(int i = 0;i < Ai; i++)
        {
            for(int j = 0;j < Bj;j++)
            {
                printf("%lf\t", C[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Nao e possivel realizar essa multiplicacao de matriz.");
    }
    return 0;
}
