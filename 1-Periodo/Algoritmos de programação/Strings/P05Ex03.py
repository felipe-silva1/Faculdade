nome = input('Entre com seu nome: ')
sexo = ''
while sexo != 'M' and sexo != 'F':
    sexo = input('Entre com seu genero (M ou F): ')
idade = int(input('Entre com a sua idade: '))
if sexo == 'F' and idade < 25:
    print("ACEITA")
else:
    print("NÃO ACEITA")