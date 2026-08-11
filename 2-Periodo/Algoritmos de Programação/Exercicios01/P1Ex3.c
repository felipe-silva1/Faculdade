#include <stdio.h>
double salario_inicial = 0;
double percentual = 0;

int main(){
    printf("Entre com o salário inicial: ");
    scanf("%lf", &salario_inicial);
    printf("Entre com o percentual de reajuste: ");
    scanf("%lf", &percentual);
    double salario_final = salario_inicial * (1 + percentual / 100);
    printf("Salário após reajuste: %lf", salario_final);
}