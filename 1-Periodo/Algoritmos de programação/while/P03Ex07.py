sala = int(input('Entre com o salário: '))
plan = int(input('Etre com o plano de salário: '))
if plan <= 3 and plan >= 1:
    if plan == 1:
        nSal = sala * 1.1
    elif plan == 2:
        nSal = sala * 1.15
    else:
        nSal = sala * 1.2
    print(nSal)
else:
    print('Entre um plano válido.')