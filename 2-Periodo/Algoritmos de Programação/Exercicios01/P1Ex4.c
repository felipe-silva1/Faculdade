#include <stdio.h>
double peso = 0;
double altura = 0;
double IMC = 0;

int main(){
    printf("Entre com o seu peso: ");
    scanf("%lf", &peso);
    printf("Entre ecom a sua altura: ");
    scanf("%lf", &altura);
    IMC = peso / (altura * altura);
    printf("IMC: %lf",IMC);
}