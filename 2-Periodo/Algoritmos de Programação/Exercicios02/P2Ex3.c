#include <stdio.h>

double nota = 0;

int main()
{
    printf("Entre com sua nota: ");
    scanf("%lf", &nota);
    if (nota > 0 && nota < 5)
    {
        printf("Insuficiente!");
    }
    else if(nota >= 5 && nota < 7)
    {
        printf("Regular!");
    }else if(nota >= 7 && nota < 9)
    {
        printf("Bom!");
    }
    else if(nota >= 9 && nota <= 10)
    {
        printf("Excelente!");
    }
    else
    {
        printf("Nota inválida");
    }
    return 0;
}