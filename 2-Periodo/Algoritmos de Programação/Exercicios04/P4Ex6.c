#include <stdio.h>

int main(int argc, char const *argv[])
{
    double vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20},soma = 0, media = 0, menor = 0;
    for(int i = 0; i < 20; i ++)
    {
        soma += vetor[i];
    }
    media = soma / 20;
    for(int i = 0; i < 20; i++)
    {
        if(vetor[i] < media)
        {
            menor++;
        }
    }
    printf("A media de todos os numeros do vetor e de %lf e %lf numeros estao abaixo dela!", media, menor);
    return 0;
}
