#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char nome_completo[100],iniciais[10];
    int j = 0;
    printf("Entre com o seu nome completo: ");
    scanf(" %[^\n]", nome_completo);
    iniciais[0] = '\0';
    for(int i = 0; i < strlen(nome_completo);i++)
    {
        if(nome_completo[i - 1] == ' ' || i == 0)
        {
            iniciais[j] = nome_completo[i];
            j++;
        }
    }
    iniciais[j] = '\0';
    printf("%s",iniciais);
    return 0;
}
