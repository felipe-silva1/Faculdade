#include <stdio.h>

int senha = 1234,tenta;

int main()
{
    for(int i = 1; i <=3; i++)
    {
        printf("\nTentativa %d de 3\nDigite a senha: ",i);
        scanf("%d", &tenta);
        if(senha == tenta)
        {
            printf("Acesso liberado!");
            break;
        }
        else
        {
            printf("Acesso negado!");
        }
    }
    return 0;
}