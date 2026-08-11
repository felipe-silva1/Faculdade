maiorSalario = 0
somaSalario = 0
somaFilhos = 0
cont1 = 0
cont2 = 0
salario = float(input('Salário: '))
while salario >= 0:
    nFilhos = int(input('Número de Filhos: '))
    somaSalario += salario
    somaFilhos += nFilhos
    if salario > maiorSalario:
        maiorSalario = salario
    if salario < 1500:
        cont2 += 1
    cont1 += 1
    salario = float(input('Salário: '))
print(f'\na) R${somaSalario / cont1 : .2f}.\nb) {somaFilhos / cont1} filhos.\nc) R${maiorSalario : .2f}.\nd) {(cont2 / cont1) * 100}%')