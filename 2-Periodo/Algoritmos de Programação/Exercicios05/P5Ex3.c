#include <stdio.h>
int main(int argc, char const *argv[])
{
    int M[5][3],Mt[3][5];
    for(int i = 0; i < 5;i++)
    {
        for(int j = 0; j < 3;j++)
        {
            printf("Entre com o elemento da linha %d, coluna %d: ",i,j);
            scanf("%d",&M[i][j]);
            Mt[j][i] = M[i][j];
        }
    }
    printf("Matriz Original: \n");
    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            printf("%d\t",M[i][j]);
        }
        printf("\n");
    }
    printf("Matriz Transposta: \n");
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 5; j++)
        {
            printf("%d\t",Mt[i][j]);
        }
        printf("\n");
    }
    return 0;
}
