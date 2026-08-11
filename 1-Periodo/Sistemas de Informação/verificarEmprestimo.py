def verificarElegibilidade(idade,rendaMensal,inadimplentes,nome, escolaridade):
    elegivel = True
    motivos = []
    if idade < 18:
        elegivel = False
        motivos.append("Menor de idade.")
    if rendaMensal < 2000:
        elegivel = False
        motivos.append("Renda mensal menor do que R$2000,00.")
    if nome in inadimplentes:
        elegivel = False
        motivos.append("Está na lista de inadimplentes.")
    if escolaridade != "Superior":
        elegivel = False
        motivos.append("Não possui ensino superior!")
    return elegivel,motivos

lista_negra = ['Jorge','Roberto', 'Jessica']
idade = int(input('Entre com a sua idade: '))
rendaMensal = float(input('Ent/re com a sua renda mensal: '))
nome = input('Entre com o seu nome: ')
escolaridade = input('Entre com a sua escolaridade: ')
elegivel, motivos =  verificarElegibilidade(idade,rendaMensal,lista_negra,nome, escolaridade)
if elegivel:
    print("Você é elegível para o empréstimo!")
else:
    print("Você não é elegível para o empréstimo!\nMotivos:",motivos)