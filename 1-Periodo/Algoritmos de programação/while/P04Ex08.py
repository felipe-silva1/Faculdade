N = int(input('Entre com um número inteiro: '))
anterior1 = 3
anterior2 = 2
x = 0
S = 5
print(f'{anterior2} {anterior1}', end=" ")
for i in range(1, N - 1):
    aux = anterior1
    x = anterior1 + anterior2
    S += x
    anterior1 = x
    anterior2 = aux
    print(x, end=" ")
print(f'= {S}')
