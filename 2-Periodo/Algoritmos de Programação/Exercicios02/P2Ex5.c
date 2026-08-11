#include <stdio.h>

int opcao;
double num1 = 0, num2 = 0, res = 0;

int main()
{
    do
    {
        printf("\n==========Calculadora Zica==========\n\t1. Adicao\n\t2. Subtracao\n\t3. Multiplicacao\n\t4. Divisao\n\t5. Sair\n\t");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Numero 1: ");
            scanf("%lf", &num1);
            printf("Numero 2: ");
            scanf("%lf", &num2);
            res = num1 + num2;
            printf("Resultado: %lf",res);
            break;
        case 2:
            printf("Numero 1: ");
            scanf("%lf", &num1);
            printf("Numero 2: ");
            scanf("%lf", &num2);
            res = num1 - num2;
            printf("Resultado: %lf",res);
            break;
        case 3:
            printf("Numero 1: ");
            scanf("%lf", &num1);
            printf("Numero 2: ");
            scanf("%lf", &num2);
            res = num1 * num2;
            printf("Resultado: %lf",res);
            break;
        case 4:
            printf("Numero 1: ");
            scanf("%lf", &num1);
            printf("Numero 2: ");
            scanf("%lf", &num2);
            res = num1 / num2;
            printf("Resultado: %lf",res);
            break;
        case 5:
            printf("Saindo do programa...");
            break;
        default:
            printf("Opcao invalida!");
            break;
        }
    } while (opcao != 5);
    return 0;
}