senha = input('Entre com uma senha: ')
for i in range(3):
    senhaT = input('Digite novamente a senha: ')
    if senhaT != senha:
        print('Senha incorreta.')
    else:
        print('Senha correta.')
        break
    