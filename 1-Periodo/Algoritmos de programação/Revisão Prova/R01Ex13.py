qntdI = 0
somaH = 0
qntdH = 0
qntdP = 0
for i in range(1,26):
    idade = int(input(f'Entre com a idade da {i}º pessoa: '))
    altura = float(input(f'Entre com a altura da {i}º pessoa: '))
    peso = float(input(f'Entre com o peso da {i}º pessoa: '))
    if idade > 50:
        qntdI +=1
    if idade >= 10 and idade <= 20:
        somaH += altura
        qntdH += 1
    if peso < 40:
        qntdP += 1
print(f'\n\t{qntdI} pessoas.\n\ta.{somaH / qntdH : .2f} m.\n\tb. {(qntdP / 25) * 100 : .1f}%.')