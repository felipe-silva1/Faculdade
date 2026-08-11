#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char str1[10],str2[10];
    int len, j = 0;
    printf("Entre com uma string: ");
    scanf(" %[^\n]",&str1);
    len = strlen(str1); 
    while(len > 10)
    {
        printf("Entre com uma string: ");
        scanf(" %[^\n]",&str1);    
    }
    for(int i = len; i >= 0; i--)
    {
        str2[j] = str1[i];
        j++;
    }


    printf("String 1: %s\nString 2: %s",str1,str2);
    return 0;
}
