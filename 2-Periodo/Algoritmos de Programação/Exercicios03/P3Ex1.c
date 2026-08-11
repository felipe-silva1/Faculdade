#include <stdio.h>
#include <stdbool.h>


bool eh_primo = true;
int num;

int main(){
    printf("Digite um numero: ");
    scanf("%d", &num);
    for (int i = 2; i < num; i++)
    {
        if(num % i == 0)
        {
            eh_primo = false;
            break;
        }
    }
    if(eh_primo)
    {
        printf("O numero e primo!");
    }
    else
    {
        printf("O numero nao e primo!");
    }
    return 0;
}