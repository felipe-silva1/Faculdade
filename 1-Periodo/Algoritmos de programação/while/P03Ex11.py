programaAtivo = True
while programaAtivo:
    a = int(input('Entre o valor A: '))
    b = int(input('Entre o valor B: '))
    c = int(input('Entre o valor C: '))
    d = int(input('Entre o valor D: '))
    e = int(input('Entre o valor E: '))
    f = int(input('Entre o valor F: '))
    if a == 0 and b == 0 and c == 0 and d == 0 and e == 0 and f == 0:
        programaAtivo = False
    else:
        cim1 = c * e - b * f
        cim2 = a * f - c * d
        bai1 = a * e - b * d
        bai2 = a * e - b * d
        if cim1 != 0 and bai1 != 0:
            x = cim1 / bai1
        else:
            print('Não é possível realizar essa divisão.')
        if cim2 !=0 and bai2 !=0:
            y = cim2 / bai2
        else:
            print('Não é possível realizar essa divisão.')
        print(f'\n\tX = {x}\n\tY = {y}')
        
