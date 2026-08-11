#include <stdio.h>
int seg = 0;
int resto_min = 0;
int min = 0;
int resto_hrs = 0;
int hrs = 0;
int main(){
    printf("Entre com a quantidade de segundos que você deseja: ");
    scanf("%i",&seg);
    min = seg / 60;
    resto_min = seg % 60;
    hrs = min / 60;
    resto_hrs = min % 60;
    printf("Segundos: %i\nMinutos: %i:%i\nHoras: %i:%i", seg, min, resto_min, hrs, resto_hrs);
}