sal = float(input('Entre com o salário do funcionário: '))
reaj = float(input('Entre com o reajuste do salário em porcentagem: '))
nSal = sal * (1 + reaj / 100)
print(f'\n\tSalário Antigo: {sal : .2f}R$.\n\tSalário Novo: {nSal : .2f}R$.')