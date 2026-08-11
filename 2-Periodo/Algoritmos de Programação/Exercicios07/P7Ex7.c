#include <stdio.h>

int Soma(int a, int *b)
{
    return(a + *b);
}

int main(int argc, char const *argv[])
{
    int num1 = 3, num2 = 4;
    int *p = &num2;
    int s = Soma(num1, p);
    printf("soma = %d",s);
    return 0;
}
