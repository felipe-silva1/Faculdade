somaV = 0
for i in range(1, 11):
    V = float(input(f'Entre com o {i}º valor: '))
    somaV += V
print(f'Média aritmética dos valores:{somaV / 10 : .1f}')