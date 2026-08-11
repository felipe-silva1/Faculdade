#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char frase[50];
    printf("Entre com uma frase: ");
    scanf(" %[^\n]", &frase);
    for(int i = 0;i < strlen(frase);i++)
    {
        if(frase[i] == ' ')
        {
            frase[i] = '\n';
        }
    }
    printf("%s",frase);
    return 0;
}
