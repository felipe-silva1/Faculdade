#dicio = {}
#dicio = dict()
#Atribuição/alteraração = dicio[chave] = valor
#Remoção = del dicio[chave]
#pop remove por pos
#unir dois dicionarios = dict.update()
#verificacao = chave in dict
#obter o valor de uma chave específica = dict.get()
dicio = dict()
i =0
while i < 2:
    nome = input("Entre com o nome: ")
    if nome in dicio.keys():
        print("Nome já existente")
    else:
        idade = int(input("Entre com a idade: "))
        cidade = input("Entre com a cidade: ")
        dicio[nome] = [idade,cidade]
        i += 1
nomeB = input("Entre com um nome que você deseja buscar: ")
if nomeB in dicio.keys():
    print(nomeB,dicio[nomeB][0])
    nome = input("Entre o nome novo: ")
    idade = int(input("Entre a idade nova: "))
    cidade = input("Entre a nova cidade: ")
    dicio[nome] = [idade,cidade]
    print(dicio[nomeB])
else:
    print("Nome não encontrado")