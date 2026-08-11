'''Um número é perfeito se a soma dos seus divisores, com exceção dele mesmo, é igual a ele.
Exemplo: número 6, os divisores de 6 são 1, 2, 3 e 6. Somando-se 1 + 2 + 3 =6. Portanto 6 é um
número perfeito. Elabore um programa que leia um número e usando uma função determine se
ele é perfeito'''
def nPerfeito(num):
    soma = 0
    for i in range(1, num):
        if num % i == 0:
            soma += i
    if soma == num:
        print('Número perfeito!')
    else:
        print('Número imperfeito!')

n = int(input('Entre com o número desejado: '))
nPerfeito(n)