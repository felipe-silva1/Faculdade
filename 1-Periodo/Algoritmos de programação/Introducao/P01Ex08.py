valor = float(input('Entre com o valor do prêmio do concurso: '))
prim = valor * 0.46
segu = valor * 0.32
terc = valor * 0.22
print(f'O valor do prêmio será divido da seguinte forma: \n\tPrimeiro: {prim : .2f}R$.\n\tSegundo: {segu: .2f}R$.\n\tTerceiro: {terc : .2f}R$.')