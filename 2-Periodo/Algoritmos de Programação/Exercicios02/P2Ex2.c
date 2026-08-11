#include <stdio.h>
int idade = 0;
double peso = 0;

int main()
{
    printf("Entre com sua idade: ");
    scanf("%d", &idade);
    printf("Entre com o seu peso: ");
    scanf("%lf", &peso);
    if ((idade >= 16 && idade <= 69) && (peso >= 50))
    {
        printf("Você está apto a doar sangue!");
    }
    else
    {
        printf("Você não está apto a doar sangue!");
    }
    return 0;
}