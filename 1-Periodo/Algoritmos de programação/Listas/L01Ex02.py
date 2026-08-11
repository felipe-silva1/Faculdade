l = []
for i in range(15):
    n = int(input('Entre com um número inteiro: '))
    l.append(n)
num = int(input('Digite um número que você deseja pesquisar: '))
if l.count(num) == 0:
    print('Esse número não existe na lista. ')
else:
    print(f'Esse número aparece {l.count(num)} vezes na lista. ')