hR = float(input('Hora Aula: '))
nA = float(input('Número de Aulas: '))
pI  = float(input('INSS: '))
print(f'Salário líquido = {hR * nA * (1 - (pI / 100)) : .2f}R$')