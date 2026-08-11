#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 10, num2 = 5;
    printf("%d\t%d",num1,num2);
    int *pt1 = &num1, *pt2 = &num2;
    int temp = num1;
    *pt1 = &num2;
    *pt2 = &temp;
    printf("\n%d\t%d",num1,num2);
    return 0;
}
