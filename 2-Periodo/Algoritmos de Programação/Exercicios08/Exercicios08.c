#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool func1(int num)
{
    bool _ehPar = true;
    if (num % 2 != 0)
    {
        _ehPar = false;
    }
    return _ehPar;
}

double func2()
{
    double _num = 0;
    printf("Entre com um numero real: ");
    scanf("%lf",&_num);
    return _num;
}

double func3(double num)
{
    int _numInteiro = (int) num;
    return ((double) num - (int) _numInteiro);
}

int func4(int num)
{
    int _somaFat = 1;
    for(int i = num;i > 0; i--)
    {
        _somaFat *= i;
    }
    return _somaFat;
}

int func5(int a, int b)
{
    if (a < b)
    {
        for(int i = a; i <= b;i++)
        {
            if(i % 2 == 0)
            {
                printf("%d ",i);
            }
        }
    }
    else
    {
        for(int i = b; i <= a; i++)
        {
            if(i % 2 == 0)
            {
                printf("%d ",i);
            } 
        }
    }
    return 0;
}

int func6(const char *str)
{
    int tamanho = 0;
    while(str[tamanho] != '\0')
    {
        tamanho++;
    }
    return tamanho;
}

int func7(const char *str, char ch)
{
    int tamanho = 0,contador = 0; 
    while(str[tamanho] != '\0')
    {
        if(str[tamanho] == ch) contador++;
        tamanho++;
    }
    return contador;
}

void func8(const char *str, char *copia)
{
    int tamanho = 0;
    while(str[tamanho] != '\0')
    {
        copia[tamanho] = str[tamanho];
        tamanho++;
    }
    copia[tamanho] = '\0';
}

bool func9(const char *str)
{
    char stringReversa[100];
    int j = 0;
    for(int i = func6(str) - 1;i >= 0; i--)
    {
        stringReversa[j] = str[i];
        j++;
    }
    stringReversa[j] = '\0';
    if (strcmp(str,stringReversa) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void func10(char *str)
{
    int tamanho = 0;
    while(str[tamanho] != '\0')
    {
        str[tamanho] = toupper(str[tamanho]);
        tamanho++;
    }
}

void PrintVector(int sz,int vec[sz])
{
    for(int i = 0; i < sz; i++)
    {
        printf("%d\n",vec[i]);
    }
}

void Swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void OrdenarCrescente(int sz, int vec[sz])
{
    bool mustStop = false;
    while (mustStop == false)
    {
        mustStop = true;
        for(int i = 0; i < sz - 1;i++)
        {
            if(vec[i] > vec[i+1])
            {
                Swap(&vec[i],&vec[i+1]);
                mustStop = false;
            }
        }
    }
}

void SeparaParImpar(int sz,int vec[sz],int vPar[],int vImpar[], int *szPar, int *szImpar)
{
    for(int i = 0; i < sz;i++)
    {
        if(vec[i] % 2 == 0)
        {
            vPar[*szPar] = vec[i];
            (*szPar)++;
        }
        else
        {
            vImpar[*szImpar] = vec[i];
            (*szImpar)++;
        }
    }
}

void PrintMatrix(int nRows, int nCols, int matrix[nRows][nCols])
{
    for(int i = 0; i < nRows; i++)
    {
        for(int j = 0; j < nCols; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

bool MultMatrix(int linhasA, int colunasA, int A[linhasA][colunasA],int linhasB, int colunasB, int B[linhasB][colunasB],int Mult[linhasA][colunasB]){
    if (colunasA != linhasB)
    {
        printf("Não é possivel realizar a multiplicação de matrizes com as matrizes fornecidas.");
        return false;
    }
    else
    {
        for(int i = 0;i < linhasA;i++)
        {
            for(int j = 0; j < colunasB;j++)
            {
                Mult[i][j] = 0;
                for(int k = 0; k < colunasA;k++)
                {
                    Mult[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return true; 
    }
}

void EscolherExercicio()
{
    bool programaAtivo = true;
    while(programaAtivo)
    {
        int ex,N,N2, vet[100], m1Linha,m2Linha, m1Coluna, m2Coluna;
        double nReal,fReal;
        char stringUsuario[100], stringCopia[100], caracter;
        printf("=========================================================================\nEscolha o Exercicio que deseja rodar:\n\n1 - Retorna se inteiro eh par.\n2 - Le um numero real e retorna a parte fracionaria.\n3 - Retorna o fatorial de um inteiro positivo.\n4 - Escreve pares entre a e b.\n5 - Retorna tamanho de string.\n6 - Retorna a qtd de vezes que um caractere aparece na string.\n7 - Copia uma string para outra.\n8 - Retorna se a string eh um palindromo.\n9 - Converte todos os caracteres de uma string para maiusculos.\n10 - Imprime vetor.\n11 - Faz swap entre dois inteiros.\n12 - Ordenacao crescente de vetor.\n13 - Separa elementos de um vetor em pares e impares.\n14 - Imprime uma matriz.\n15 - Multiplicacao de matrizes.\n=========================================================================\n");
        scanf("%d",&ex);
        getchar();
        switch (ex)
        {
        case 1:
            printf("Entre com um valor inteiro: ");
            scanf("%d",&N);
            if (func1(N)) printf("O numero eh par.\n");
            else printf("O numero eh impar.\n");
            break;
        case 2:
            nReal = func2();
            fReal = func3(nReal);
            printf("A parte fracionada de %lf eh %lf\n",nReal,fReal);
            break;
        case 3:
            printf("Entre com um valor inteiro: ");
            scanf("%d",&N);
            printf("O fatorial de %d eh %d.\n",N,func4(N));
            break;
        case 4:
            printf("Entre com o primero valor inteiro: ");
            scanf("%d", &N);
            printf("Entre com o segundo valor inteiro: ");
            scanf("%d", &N2);
            printf("Os valores pares do intervalo de %d e %d sao: ",N,N2);
            func5(N,N2);
            printf("\n");
            break;
        case 5:
            printf("Entre com uma string: ");
            scanf("%[^\n]",stringUsuario);
            getchar();
            printf("O tamanho dessa string eh de: %d.\n",func6(stringUsuario));
            break;
        case 6:
            printf("Entre com uma string: ");
            scanf("%[^\n]", stringUsuario);
            getchar();
            printf("Entre com um caracter: ");
            scanf("%c", &caracter);
            printf("O caracter %c aparece %d vezes na string.\n",caracter,func7(stringUsuario,caracter));
            break;
        case 7:
            printf("Entre com uma string: ");
            scanf("%[^\n]", stringUsuario);
            getchar();
            func8(stringUsuario,stringCopia);
            printf("String Copiada: %s\n",stringCopia);
            break;
        case 8:
            printf("Entre com uma string: ");
            scanf("%[^\n]", stringUsuario);
            getchar();
            if(func9(stringUsuario))
            {
                printf("A funcao eh um palindromo.\n");
            }
            else
            {
                printf("A funcao nao eh um palindromo.\n");
            }
            break;
        case 9:
            printf("Entre com uma string: ");
            scanf("%[^\n]", stringUsuario);
            getchar();
            func10(stringUsuario);
            printf("String convertida para maiusculo: %s\n",stringUsuario);
            break;
        case 10:
            printf("Entre com o tamanho do vetor desejado: (max 100) ");
            scanf("%d", &m1Coluna);
            for(int i = 0; i < m1Coluna; i++)
            {
                printf("Entre com o valor do %d elemento do vetor: ", i);
                scanf("%d", &vet[i]);
            }
            printf("Vetor na vertical: \n");
            PrintVector(m1Coluna,vet);
            break;
        case 11:
            printf("Entre com um valor inteiro: ");
            scanf("%d", &N);
            printf("Entre com outro valor inteiro: ");
            scanf("%d", &N2);
            Swap(&N,&N2);
            printf("Valor 1: %d\nValor 2: %d\n",N,N2);
            break;
        case 12:
            printf("Entre com o tamanho do vetor desejado: (max 100) ");
            scanf("%d", &m1Coluna);
            for(int i = 0;i < m1Coluna;i++)
            {
                printf("Entre com o valor do %d elemento do vetor: ", i);
                scanf("%d", &vet[i]);
            }
            OrdenarCrescente(m1Coluna,vet);
            printf("Vetor em ordem crescente: ");
            for(int i = 0; i < m1Coluna;i++)
            {
                printf("%d ",vet[i]);
            }
            printf("\n");
            break;
        case 13:
        {            
            printf("Entre com o tamanho do vetor desejado: (max100) ");
            scanf("%d", &m1Coluna);
            for(int i = 0; i < m1Coluna;i ++)
            {
                printf("Entre com o valor do %d elemento do vetor: ", i);
                scanf("%d", &vet[i]);
            }
            int vetP[m1Coluna], vetI[m1Coluna], m1P = 0, m1I = 0;
            SeparaParImpar(m1Coluna,vet,vetP,vetI,&m1P,&m1I);
            printf("Vetor par: ");
            for(int i = 0; i < m1P;i++)
            {
                printf("%d ",vetP[i]);
            }
            printf("\nVetor impar: ");
            for(int i = 0; i < m1I; i++)
            {
                printf("%d ",vetI[i]);
            }
            printf("\n");
            break;
        }
        case 14:
        {
            printf("Entre com o numero de linhas da matriz: ");
            scanf("%d",&m1Linha);
            printf("Entre com numero de colunas da matriz: ");
            scanf("%d",&m1Coluna);
            int mat1[m1Linha][m1Coluna];
            for(int i = 0;i < m1Linha;i++)
            {
                for(int j = 0; j < m1Coluna; j++)
                {
                    printf("Entre com o elemento da linha %d coluna %d: ",i,j);
                    scanf("%d", &mat1[i][j]);
                }
            }
            PrintMatrix(m1Linha,m1Coluna,mat1);
            break;
        }
        case 15:
        {            
            printf("Entre com o numero de linhas da matriz: ");
            scanf("%d",&m1Linha);
            printf("Entre com numero de colunas da matriz: ");
            scanf("%d",&m1Coluna);
            printf("Entre com o numero de linhas da matriz: ");
            scanf("%d",&m2Linha);
            printf("Entre com numero de colunas da matriz: ");
            scanf("%d",&m2Coluna);  
            int mat1[m1Linha][m1Coluna], mat2[m2Linha][m2Coluna], mat3[m1Linha][m2Coluna];
            for(int i = 0; i < m1Linha; i++)
            {
                for(int j = 0; j < m1Coluna; j++)
                {
                    printf("Entre com o elemento da linha %d coluna %d: ",i,j);
                    scanf("%d", &mat1[i][j]);                    
                }
            }
            for(int i = 0; i < m2Linha; i++)
            {
                for(int j = 0; j < m2Coluna; j++)
                {
                    printf("Entre com o elemento da linha %d coluna %d: ",i,j);
                    scanf("%d", &mat2[i][j]);                    
                }
            }
            MultMatrix(m1Linha,m1Coluna,mat1,m2Linha,m2Coluna,mat2,mat3);
            for(int i = 0; i < m1Linha; i++)
            {
                for(int j = 0; j < m2Coluna; j++)
                {
                    printf("%d\t",mat3[i][j]);               
                }
                printf("\n");
            }
            break;
        }
        default:
            programaAtivo = false;
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    EscolherExercicio();
    return 0;
}
