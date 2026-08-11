'''Desenvolva uma função gera3 que receba um valor inicial, um valor final e um passo (com valor
padrão de 1). A função deve retornar uma lista contendo a sequência de números gerada.'''
def gera3(valorInicial, valorFinal, passo = 1):
    lista = []
    for i in range(valorInicial, valorFinal, passo):
        lista.append(i)
    return lista
inicial = int(input('Entre com um valor inicial: '))
final = int(input('Entre com um valor final: '))
passo = int(input('Entre com o passo: '))
print(gera3(inicial,final,passo))