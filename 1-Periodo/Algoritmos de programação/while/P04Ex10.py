n = int(input('Entre com um número inteiro: '))
F = 1
while n > 0:
    for i in range(1,n + 1):
        F *= i
    print(f'{n}! = {F}')
    F = 1
    n = int(input('Entre com um número inteiro: '))