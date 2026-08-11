qntdP = 0
qntdA = 0
qntdI = 0
cont = 0
for i in range(0,25):
    idade = int(input(f'Entre com a idade da {i + 1}ª pessoa: '))
    altura = float(input(f'Entre com a altura da {i + 1}ª pessoa: '))
    peso = float(input(f'Entre com o peso da {i + 1}ª pessoa: '))
    if peso < 50:
        qntdP += 1
    if idade >= 10 and idade <=20:
        cont += 1
        qntdA += altura
    elif idade > 50:
        qntdI += 1
print(f'\n\tQuantidade de pessoas com idade superior a 50 anos: {qntdI}\n\tMédia das alturas das pessoas entre 10 e 20 anos: {qntdA / cont}\n\tPercentual de pessoas com peso inferior a 50 quilos: {(qntdP / 25) * 100}')
