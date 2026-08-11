soma_total = 0

def valor():
    num = int(input('Entre com um valor inteiro: '))
    return num

def soma(soma_atual, num):
    soma_atual += num
    return soma_atual

for i in range(3):
    num = valor()
    soma_total = soma(soma_total, num)

print(soma_total)