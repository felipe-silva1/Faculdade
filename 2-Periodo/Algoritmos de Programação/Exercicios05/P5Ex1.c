#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N  = 0;
    while (N < 1 || N > 20 )
    {
        printf("Entre com o tamanho da matriz quadrada: ");
        scanf("%d",&N);
    }
    double M[N][N], soma = 0;
    for(int i = 0; i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            printf("Entre com o elemento da linha %d coluna %d: ",i,j);
            scanf("%lf",&M[i][j]);
            if(i == j)
            {
                soma += M[i][j];
            }
        }
    }

    printf("Matriz Quadrada: \n");
    for(int i = 0; i < N;i++)
    {
        for(int j = 0;j < N;j++)
        {
            printf("%lf\t",M[i][j]);
        }
        printf("\n");
    }
    printf("A soma dos elementos da diagonal principal e de: %lf",soma);
    return 0;
}
