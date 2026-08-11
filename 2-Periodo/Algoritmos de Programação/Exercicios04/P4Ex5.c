#include <stdio.h>

int main(int argc, char const *argv[])
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, par = 0, mult = 0;
    for(int i = 0; i < 20; i++)
    {
        if(vetor[i] % 2 == 0)
        {
            par++;
        }
        if(vetor[i] % 5 == 0)
        {
            mult++;
        }
    }
    printf("Esse vetor possui %d numeros pares e %d multiplos de 5!", par, mult);
    return 0;
}
