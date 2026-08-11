dias = int(input('Entre com a quantidade de dias trabalhados: '))
pag = (30 * dias) - (30 * dias * 0.08)
print(f'O pagamento líquido do encanador é de: {pag : .2f}R$')