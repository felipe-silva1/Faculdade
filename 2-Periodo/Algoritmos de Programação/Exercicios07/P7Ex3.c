#include <stdio.h>

int main(int argc, char const *argv[])
{
    double num1 = 10, num2 = 5, res = 0;
    double *pt1 = &num1, *pt2 = &num2;
    res = *pt1 * *pt2;
    pt2 = &res;
    printf("num1: %lf\nnum2: %lf\nres: %lf\n*pt1: %lf\n*pt2: %lf",num1,num2,res,*pt1,*pt2);
    return 0;
}
