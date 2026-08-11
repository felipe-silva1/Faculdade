#include <stdio.h>
#include <stdbool.h>

int somaRec(int n)
{
    if (n == 1) return 1;
    else return (n + somaRec(n - 1));
}

int fatorialRec(int n)
{
    if (n == 1) return 1;
    else return(n * fatorialRec(n - 1));
}

bool ehPrimoRec(int n,int div)
{
    if (div == 1) return true;
    else if(n % div == 0) return false;
    else return ehPrimoRec(n,div-1);
}

bool ehPrimo(int n)
{
    if (n < 2) return (n == 2);
    else return ehPrimoRec(n,n-1);
}

int encontrarPrimoRec(int vetorEntrada[], int sz, int indiceAtual, int vetorPrimos[], int indiceSaida)
{
    if(indiceAtual == sz) return indiceSaida;
    int numeroAtual = vetorEntrada[indiceAtual];
    if(ehPrimo(numeroAtual))
    {
        vetorPrimos[indiceSaida] = numeroAtual;
        return encontrarPrimoRec(vetorEntrada, sz, indiceAtual + 1,vetorPrimos, indiceSaida + 1);
    }
    else return encontrarPrimoRec(vetorEntrada, sz, indiceAtual + 1, vetorPrimos, indiceSaida);
}

int encontrarPrimos(int vetorEntrada[], int sz, int vetorPrimos[])
{
    return encontrarPrimoRec(vetorEntrada, sz, 0, vetorPrimos,0);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void ordenarVetorRec(int vet[], int n)
{
    if(n == 1) return;
    for(int i = 0; i < n - 1; i++)
    {
        if (vet[i] > vet[i+ 1])
        {
            swap(&vet[i], &vet[i+1]);
        }
    }
    ordenarVetorRec(vet,n - 1);
}

void imprimirVetor(int vetor[],int sz)
{
    for(int i = 0; i < sz; i++)
    {
        printf("%d\t",vetor[i]);
    }
}


int main(int argc, char const *argv[])
{
    int num = 5;
    printf("A soma de todos os numeros de 1 ate %d eh de: %d.\n", num,somaRec(num));
    printf("O fatorial de %d eh: %d.\n", num, fatorialRec(num));
    if(ehPrimo(num))
    {
        printf("O numero %d eh primo.\n",num);
    }
    else
    {
        printf("O numero %d nao eh primo.\n",num);
    }
    int vet[20] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int tamanho = 20;
    int vetPrimos[20];

    printf("Vetor Original: \n");
    imprimirVetor(vet,tamanho);
    ordenarVetorRec(vet,tamanho);
    printf("\nVetor Ordenado: \n");
    imprimirVetor(vet,tamanho);
    int totalPrimos = encontrarPrimos(vet,tamanho,vetPrimos);
    printf("\nVetor Primos: \n");
    imprimirVetor(vetPrimos, totalPrimos);

    return 0;
}
