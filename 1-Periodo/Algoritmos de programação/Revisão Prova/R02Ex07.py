'''Elabore um programa que leia um número inteiro e construa duas funções: uma que some os dígitos desse número inteiro e outra que determine o maior digito desse número. Exemplo: número = 1063, então a soma =1+ 0 +6 + 3 =10 e o maior dígito é 6
'''
def soma(num):
    milhar = num // 1000
    centena = num // 100 % 10
    dezena = num // 10 % 10
    unidade = num % 10
    somaN = milhar + centena + dezena + unidade
    print(somaN)

def maior(num):
    milhar = num // 1000
    centena = num // 100 % 10
    dezena = num // 10 % 10
    unidade = num % 10

    if milhar > centena and milhar > dezena and milhar > centena:
        print(milhar)
    elif centena > dezena and centena > unidade:
        print(centena)
    elif dezena > unidade:
        print(dezena)
    elif unidade > dezena:
        print(unidade)
    else:
        print('Digite números diferentes!')

n = int(input('Entre com um número de 4 digitos: '))
soma(n)
maior(n)