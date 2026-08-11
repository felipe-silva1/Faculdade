comp = float(input('Entre com o comprimento da sala: '))
larg = float(input('Entre com a largura da sala: '))
prec = float(input('Entre com o custo por m² de carpete: '))
cust = comp * larg * prec
print(f'O custo total para forrar o piso da sala é de: {cust: .2f}R$.')