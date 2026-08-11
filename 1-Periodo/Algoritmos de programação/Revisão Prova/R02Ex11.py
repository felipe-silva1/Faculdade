'''11. Calculadora de IMC:
• Crie uma função chamada calc1 que receba o peso (em kg) e a altura (em metros) de uma
pessoa. A função deve calcular o Índice de Massa Corporal (IMC) e retornar o resultado.
• IMC = peso / (altura * altura)
• Chame a função passando os argumentos por posição.'''
def calc1(peso,altura):
    IMC = peso / (altura * altura)
    return IMC

weight = float(input('Entre com o peso: '))
height = float(input('Entre com a altura: '))

print(f'IMC:{calc1(weight,height) : .2f}')