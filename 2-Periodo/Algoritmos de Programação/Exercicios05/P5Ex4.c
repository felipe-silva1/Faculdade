#include <stdio.h>

int main(int argc, char const *argv[])
{
    double M[10][10], soma = 0, menor = 9999999, maior = -99999999,posi,posj;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("Entre com o elemento da linha %d, coluna %d: ",i,j);
            scanf("%lf",&M[i][j]);
            if (i == 4)
            {
                soma += M[i][j];
            }
            if(j == 5 && M[i][j] < menor)
            {
                menor = M[i][j];
            }
            if(i == j & M[i][j] > maior)
            {
                maior = M[i][j];
                posi = i;
                posj = j;                
            }
        }
    }
    printf("Matriz: \n");
    for(int i = 0; i < 10;i++)
    {
        for(int j = 0;j < 10;j++)
        {
            printf("%lf\t",M[i][j]);
        }
        printf("\n");
    }
    printf("A soma da linha 4 e de %lf\nO menor elemento da coluna 5 e o %lf\nO maior elemento da diagonal principal e o %lf que esta na linha %lf, coluna %lf",soma,menor,maior,posi,posj);
    return 0;
}
