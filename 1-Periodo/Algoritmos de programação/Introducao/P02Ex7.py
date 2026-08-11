comp = float(input('Entre com o comprimento do terreno: '))
larg = float(input('Entre com a largura do terreno: '))
prec = float(input('Entre com o custo da tela: '))
cust = ((2 * comp) + (2 * larg)) * prec
print(f'O preço para cercar esse terreno de tela é de: R${cust : .2f}.')