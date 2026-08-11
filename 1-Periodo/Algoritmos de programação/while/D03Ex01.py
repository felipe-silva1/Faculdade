n1 = float(input('Entre com a primeiro nota: '))
n2 = float(input('Entre com a segunda nota: '))
p1 = float(input('Entre com o primeiro peso: '))
p2 = float(input('Entre com o segundo peso: '))
sp = p1 + p2
m = ((n1 * p1) + (n2 * p2)) / sp
if m == 10:
    print('Aprovado com Distinção. ')
elif m >= 7:
    print('Aprovado.')
else:
    print('Reprovado.')