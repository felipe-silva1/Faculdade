horasT = float(input('Quantidade de horas trabalhadas: '))
salaH = float(input('Salário p/ hora trabalhada: '))
if horasT <= 40:
    salario = salaH * horasT
else:
    salario = (salaH * 40) + ((horasT - 40) * 1.5 * salaH)
print(f'Salário total: R${salario : .2f}')
