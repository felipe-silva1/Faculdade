#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char frase[20], caracter;
    int cont = 0,len;

    printf("Entre com uma frase: ");
    scanf(" %[^\n]",&frase);
    len = strlen(frase);
    while (len > 20)
    {
        printf("Entre com uma frase: ");
        scanf(" %[^\n]",&frase);
    }


    
    printf("Entre com um char: ");
    scanf(" %c",&caracter);

    for(int i = 0; i < len; i++)
    {
        if (frase[i] == caracter)
        {
            cont++;
        }
        
    }
    
    printf("O caracter %c aparece %d vezes na frase %s.",caracter,cont,frase);

    return 0;
}
