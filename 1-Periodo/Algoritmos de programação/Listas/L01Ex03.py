v = []
maiorE = 0
menorE = 0
somaE = 0
qntdE = 0
for i in range(10):
    n = float(input('Entre com um número real: '))
    somaE += n
    if maiorE == 0:
        maiorE = n
    else:
        if maiorE < n:
            maiorE = n
    if menorE == 0:
        menorE = n
    else:
        if menorE > n:
            menorE = n
    if n > 29:
        qntdE += 1
    v.append(n)
print(f"Média dos Elementos: {somaE / 10}\nMaior Número: {maiorE} Menor Número: {menorE}\nQuantidade de números maiores que 29: {qntdE}")
print(v)