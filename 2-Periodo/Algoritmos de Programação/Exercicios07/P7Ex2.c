#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 10, num2 = 5, num3 = 0;
    int *pt1 = &num1, *pt2 = &num2;
    pt1 = &num3;
    *pt1 = num1 + num2;
    printf("num1: %d\nnum2: %d\nnum3: %d\npt1: %d\npt2: %d",num1,num2,num3,*pt1,*pt2);
    return 0;
}
