pMaiorN = -999999
sMaiorN = -999999
for i in range (3):
    n = int(input('Entre com um número inteiro: '))
    if n > pMaiorN:
        pMaiorN = n
    elif n > sMaiorN:
        sMaiorN = n
print(f'\n\tMaior número: {pMaiorN}.\n\tSegundo maior número: {sMaiorN}.')