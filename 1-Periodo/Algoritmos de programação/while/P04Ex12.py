n = int(input('Entre com um número inteiro: '))
cont = 0
for i in range(1,n+1):
    if i != 1 and i != n:
        if n % i == 0:
            cont = 1
if cont == 0:
    print('Esse número é Primo!')
else:
    print('Esse número não é Primo!')     