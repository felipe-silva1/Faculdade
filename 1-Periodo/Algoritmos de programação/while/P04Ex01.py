n = int(input('Entre com um número inteiro: '))
cont1 = 0
cont2 = 0
cont3 = 0
cont4 = 0
while n >= 0:
    if n >= 0 and n <= 100:
        if n <= 25:
            cont1 += 1
        elif n <= 50:
            cont2 += 1
        elif n <= 75:
            cont3 += 1
        else:
            cont4 += 1
    n = int(input('Entre com um número inteiro: '))
print(f'\n\tPrimeiro intervalo: {cont1}.\n\tSegundo intervalo: {cont2}.\n\tTerceiro intervalo: {cont3}.\n\tQuarto intervalo: {cont4}.')