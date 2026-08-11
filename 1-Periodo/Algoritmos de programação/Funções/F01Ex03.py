def somaImposto(taxaImposto,custo):
    custoFinal = custo * (1 + (taxaImposto / 100))
    return custoFinal
taxa = float(input('Entre com a taxa de imposto atual: '))
custo = float(input('Entre o custo do produto: '))
print(f"R${somaImposto(taxa,custo) : .2f}")
