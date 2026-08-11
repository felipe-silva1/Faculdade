#include <stdio.h>

int main(int argc, char const *argv[])
{
    double M[5][5],maiorN = -999999;
    int posi,posj;
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5; j++)
        {
            printf("Entre com o elemento da linha %d, coluna %d: ",i,j);
            scanf("%lf",&M[i][j]);
            if(M[i][j] > maiorN)
            {
                maiorN = M[i][j];
                posi = i;
                posj = j;
            }
        }
    }
    printf("Matriz: \n");
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            printf("%lf\t",M[i][j]);
        }
        printf("\n");
    }
    printf("O maior numero da matriz digitada e o %lf que ocupa a linha %d, coluna %d.",maiorN,posi,posj);
    return 0;
}
