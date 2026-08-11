def verificarAceitacao(nome,idade,sexo):
    if idade < 25 and sexo == 'F':
        print(f'{nome} você foi ACEITA!')
    else:
        print(f'Acesso NEGADO!')
nome = input('Entre com o seu nome: ')
idade = int(input('Entre com sua idade: '))
sexo = input('Entre com o seu sexo: (M) ou (F)').upper()
while sexo != 'M' and sexo != 'F':
    sexo = input('Entre com o seu sexo: (M) ou (F)')
verificarAceitacao(nome,idade,sexo)