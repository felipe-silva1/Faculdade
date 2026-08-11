num = int(input('Entre com um número inteiro de três digitos: '))
centenas = num // 100
dezenas = (num // 10) % 10
unidade = num % 10
print(f'\n\tNúmero Lido: {num}\n\tNúmero Gerado: {unidade}{dezenas}{centenas}')