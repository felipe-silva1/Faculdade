#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int vetor[] = {20, 19, 18, 17, 16, 8, 14, 13, 12, 11, 10, 9, 15, 7, 6, 5, 4, 3, 2, 1}, aux;
    bool mustStop = false;
    while(mustStop == false)
    {
        mustStop = true;
        for(int i = 0; i < 20; i++)
        {
            if(vetor[i] > vetor[i + 1])
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
