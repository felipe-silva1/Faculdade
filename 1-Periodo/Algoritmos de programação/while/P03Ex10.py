n = int(input('Entre quantas vezes você quer rodar o programa: '))
i = 0
sumP = 0
qtdI = 0
while i < n:
    num = int(input('Entre com um número: '))
    if num % 2 == 0:
        sumP += num
    else:
        qtdI += 1
    i += 1
print(f'\n\tSoma dos pares: {sumP}\n\tQuantidade de Impares: {qtdI}')