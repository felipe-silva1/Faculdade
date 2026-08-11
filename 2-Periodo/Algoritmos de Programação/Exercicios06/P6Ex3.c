#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char palavra[100];
    int len;
    bool ehPalindromo = true;
    printf("Entre com uma palavra: ");
    scanf(" %[^\n]", &palavra);
    len = strlen(palavra);
    for(int i = 0; i < len / 2;i++)
    {
        if(palavra[i] != palavra[len-i-1])
        {
            ehPalindromo = false;
            break;
        }
    }
    
    if(ehPalindromo == true)
    {
        printf("Essa palavra e um palindromo.");
    }
    else
    {
        printf("Essa palavra nao e um palindromo.");
    }
    return 0;
}
