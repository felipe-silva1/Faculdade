#include <stdio.h>

int main(int argc, char const *argv[])
{
    int num1 = 3,num2 = 4,num3 = 5;
    int *pt1 = &num1, *pt2 = &num2, *pt3 = &num3;
    *pt1 = 6;
    printf("pt1: %d, pt2: %d, pt3: %d",*pt1,*pt2,*pt3);
    *pt1 = *pt2;
    printf("\npt1: %d, pt2: %d, pt3: %d",*pt1,*pt2,*pt3);
    *pt1 = *pt3;
    printf("\npt1: %d, pt2: %d, pt3: %d",*pt1,*pt2,*pt3);
    return 0;
}
