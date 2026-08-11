#include <stdio.h>
#include <stdbool.h>

bool mustStop = false;
int num1, num2, num3, num4, num5, aux;

int main()
{
    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);
    printf("Numero 3: ");
    scanf("%d", &num3);
    printf("Numero 4: ");
    scanf("%d", &num4);
    printf("Numero 5: ");
    scanf("%d", &num5);
    while(mustStop == false)
    {
        mustStop = true;
        if(num1 > num2)
        {
            aux = num2;
            num2 = num1;
            num1 = aux;
            mustStop = false;
        }
        if(num2 > num3)
        {
            aux = num3;
            num3 = num2;
            num2 = aux;
            mustStop = false;
        }
        if(num3 > num4)
        {
            aux = num4;
            num4 = num3;
            num3 = aux;
            mustStop = false;
        }
        if(num4 > num5)
        {
            aux = num5;
            num5 = num4;
            num4 = aux;
            mustStop = false;
        }
    }
    printf("%d,%d,%d,%d,%d",num1,num2,num3,num4,num5);
    return 0;
}