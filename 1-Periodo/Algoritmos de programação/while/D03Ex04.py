N = 10
i = 0
maiorN = -999999
menorN = 9999999
while i < N:
    x = int(input(f'Entre com o {i + 1}º número: '))
    if x > maiorN:
        maiorN = x
    if x < menorN:
        menorN = x
    i += 1
print(f'\n\tMaior número: {maiorN}\n\tMenor número: {menorN}')
