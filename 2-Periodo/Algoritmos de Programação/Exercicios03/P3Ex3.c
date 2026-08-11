#include <stdio.h>
#include <stdbool.h>

bool programaAtivo = true;
int num, res = 1;

int main()
{
    while(programaAtivo)
    {
        res = 1;
        printf("\nEntre com um numero: ");
        scanf("%d",&num);
        if(num < 0)
        {
            break;
        }
        for(int i = num; i > 0; i--)
        {
            res *= i;
        }
        printf("O fatorial de %d e: %d",num,res);
    }
    return 0;
}