#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[50];
    int contv = 0, contc = 0;
    printf("Entre com uma string: ");
    scanf(" %[^\n]", &string);
    for(int i = 0; i < strlen(string); i++)
    {
        if(toupper(string[i]) == 'A' || toupper(string[i]) == 'E' || toupper(string[i]) == 'I' || toupper(string[i]) == 'O' || toupper(string[i]) == 'U')
        {
            contv++;
        }
        else
        {
            contc++;
        }
    }
    printf("Quantidade de vogais: %d\nQuantidade de consonantes: %d",contv,contc);
    return 0;
}
