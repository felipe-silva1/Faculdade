#include <stdio.h>

double A = 0;
double B = 0;
double C = 0;
int valido = 0;

int main()
{
    printf("A: ");
    scanf("%lf", &A);
    printf("B: ");
    scanf("%lf", &B);
    printf("C: ");
    scanf("%lf", &C);
    if(A < (B + C) && B < (A + C) && C < (A + B))
    {
        printf("Triangulo valido!");
    }
    else
    {
       printf("Triangulo invalido!"); 
    }
}