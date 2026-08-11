'''Faça um programa com uma função chamada somaImposto. A função possui dois parâmetros
formais: taxaImposto, que é a quantia de imposto sobre vendas expressa em porcentagem e custo,
que é o custo de um item antes do imposto. A função “altera” o valor de custo para incluir o imposto
sobre vendas.'''
def incluirImposto(preco,imposto):
    precofinal = preco * (1 + imposto)
    return precofinal

custo = float(input('Entre com o valor do item: '))
imposto = float(input('Entre com a porcentagem de imposto sobre esse item: '))
print(f'R${incluirImposto(custo,(imposto / 100)) : .2f}')