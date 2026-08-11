#include <stdio.h>
#include <stdbool.h>

bool programAtivo = true;
int i, max = -999999, min = 999999,num;

int main()
{
    while(programAtivo)
    {
        printf("Entre com um numero: ");
        scanf("%d", &num);
        if(num == 0)
        {
            break;
        }
        if(num > max)
        {
            max = num;
        }
        if(num < min)
        {
            min = num;
        }
        i++;
    }
    printf("\n\tNumeros digitados: %d\n\tMaior numero: %d\n\tMenor numero: %d",i,max,min);
    return 0;
}