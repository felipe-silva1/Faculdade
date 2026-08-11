mNum = 0
qntdN = 0
qntdM = 0
lista = []
for i in range(3):
    num = int(input('Entre com um número: '))
    if num > 30:
        mNum += num
        qntdM += 1
    if num % 2 == 0 and num > 24:
        qntdN += 1
    lista.append(num)
print(f"""Resultado:
    \tMedia de números maiores que 30: {mNum / qntdM}
    \tQuantidade de números pares maiores que 24: {qntdN}
    \tLista: {lista}""")