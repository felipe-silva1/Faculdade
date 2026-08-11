n1 = int(input('Entre com um número: '))
n2 = int(input('Entre com um número: '))
n3 = int(input('Entre com um número: '))
if n1 != n2 and n1 != n3 and n2 != n3:
    if n1 > n2:
        if n1 > n3:
            print('1º')
        else:
            print('3º')
    elif n2 > n1:
        if n2 > n3:
            print('2º')
        else:
            print('3º')
else:
    print('Entre números diferentes.')