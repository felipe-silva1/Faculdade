#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20}, aux;
    bool mustStop = false;
    while(mustStop == false)
    {
        mustStop = true;
        for(int i = 0; i < 20; i++)
        {
            if(vetor[i] < vetor[i + 1])
            {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;
                mustStop = false;
            }
        }
    }
    for(int i = 0; i < 20; i++)
    {
        printf("%d\n",vetor[i]);
    }
    return 0;
}
