#include <stdio.h>
int A = 20; 
int B = 0; 
int C = 1; 
int D = 10;

int main()
{
    if((A - B + D) >= C)
    {
        printf("Condicao 1 Verdadeira!");
    }
    else
    {
        printf("Condicao 1 Falsa!");
    }
    if(A > (A + D) || (C > B))
    {
        printf("Condicao 2 Verdadeira!");
    }
    else
    {
        printf("Condicao 2 Falsa!");
    }
    if((A * D) > (C + A) && (A > B))
    {
        printf("Condicao 3 Verdadeira!");
    }
    else
    {
        printf("Condicao 3 Falsa!");
    }
    if((((A + B) / C) >= 0.9) && ((B * D) < 0))
    {
        printf("Condicao 4 Verdadeira!");
    }
    else
    {
        printf("Condicao 4 Falsa!");
    }
    if(((A + C) / D) > 0.3 && (((B - C) < 0) || (C + A) > D)) 
    {
        printf("Condicao 5 Verdadeira!");
    }
    else
    {
        printf("Condicao 5 Falsa!");
    }
    if(((A + C) / D > 0.3) && ((B - C) < 0) || ((C + A) > D))
    {
        printf("Condicao 6 Verdadeira!");
    }
    else
    {
        printf("Condicao 6 Falsa!");
    }
    return 0;
}