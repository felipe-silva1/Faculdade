N = int(input('Entre com a quantidade de vezes que a sequência será rodada: '))
anterior1 = 2
anterior2 = 1
x = 0
print(f'{anterior2} {anterior1}',end=" ")
for i in range(1, N - 1):
    aux = anterior1
    x = 2 * anterior1 + anterior2
    anterior1 = x
    anterior2 = aux
    print(x, end=" ")