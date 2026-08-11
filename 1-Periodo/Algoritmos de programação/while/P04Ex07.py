n = int(input('Entre com um número inteiro: '))
sPar = 0
sGer = 0
qPar = 0
qImp = 0
qRoG = 0
qRoP = 0
while n != 0:
    if n % 2 == 0:
        qPar += 1
        sPar += n
        qRoP += 1
    else:
        qImp += 1
    sGer += n
    qRoG += 1
    n = int(input('Entre com um número inteiro: '))
print(f'\n\tQuantidade de números pares: {qPar}.\n\tQuantidade de números impares: {qImp}.\n\tMédia dos números pares: {sPar / qRoP}.\n\tMédia Geral: {sGer / qRoG}')