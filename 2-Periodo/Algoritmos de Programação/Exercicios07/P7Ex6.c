#include <stdio.h>

int Soma(int a, int *b)
{
    return(a + *b);
}
int main(int argc, char const *argv[])
{
    int num1 = 3,num2 = 4;
    int s = Soma(num1,&num2);
    printf("soma = %d",s);
    return 0;
}
