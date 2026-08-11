'''Faça um programa, com uma função que necessite de um argumento. A função retorna o valor de
caractere ‘P’, se seu argumento for positivo, e ‘N’, se seu argumento for zero ou negativo.'''
def verificacao(num):
    valor = ''
    if num > 0:
        valor = 'P'
        return valor
    else:
        valor = 'N'
        return valor
n = int(input('Entre com um número: '))
print(verificacao(n))