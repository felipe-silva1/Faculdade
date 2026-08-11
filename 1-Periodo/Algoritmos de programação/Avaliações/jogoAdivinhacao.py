import random

programaAtivo = 1

while programaAtivo == 1:
    nSec = random.randint(1000,9999)
    nSec1 = nSec // 1000
    nSec2 = (nSec // 100) % 10
    nSec3 = (nSec // 10) % 10
    nSec4 = nSec % 10

    i = 10
    tent = 0

    n1 = 0
    n2 = 0
    n3 = 0
    n4 = 0

    milhar_descoberta = 0
    centena_descoberta = 0
    dezena_descoberta = 0
    unidade_descoberta = 0

    err_milhar = 0
    err_centena = 0
    err_dezena = 0
    err_unidade = 0

    print(f"Bem vindo(a) ao Jogo da Adivinhação!\n\nVocê terá 10 tentativas para adivinhar uma senha aleatória de 4 digitos (entre 1000 e 9999).\nA partir da 5ª tentativa o jogo irá te dar dicas sobre os números não descobertos.\n\n")
    input(f"<<< Pressione Enter >>>")
    while i > 0:
        acert = 0
        dica = 1

        nAdv = int(input('Digite a sua tentativa de senha: '))
        while nAdv < 1000 or nAdv > 9999:
            print(f'\t\tATENÇÃO!!!\n\t\t\tSenha inválida!\n\t\t\tDigite um Valor Entre 1000 e 9999.')
            nAdv = int(input('Digite a sua tentativa de senha: '))

        nAdv1 = nAdv // 1000
        nAdv2 = ((nAdv // 100) % 10)
        nAdv3 = ((nAdv // 10) % 10)
        nAdv4 = nAdv % 10

        print(f"Sua senha é: ", end="")

        if nSec1 == nAdv1:
            n1 = nSec1
            milhar_descoberta = 1
            print(n1, end=" ")
            acert += 1
        elif milhar_descoberta == 0 and i <= 6 and dica == 1:
            print("Par" if nSec1 % 2 == 0 else "Ímpar", end=" ") if i % 2 == 0 else print(">=5" if nSec1 >= 5 else "<5", end=" ")
            err_milhar += 1
            if err_milhar >= 2:
                milhar_descoberta = 1
            dica = 0
        else:
            if n1 == 0:
                print('_', end=" ")
            else:
                print(n1,end=" ")

        if nSec2 == nAdv2:
            n2 = nSec2
            centena_descoberta = 1
            print(n2, end=" ")
            acert += 1
        elif milhar_descoberta == 1 and centena_descoberta == 0 and i <= 6 and dica == 1:
            print("Par" if nSec2 % 2 == 0 else "Ímpar", end=" ") if i % 2 == 0 else print(">=5" if nSec2 >= 5 else "<5", end=" ")
            err_centena += 1
            if err_centena >= 2:
                centena_descoberta = 1
            dica = 0
        else:
            if n2 == 0:
                print('_', end=" ")
            else:
                print(n2,end=" ")

        if nSec3 == nAdv3:
            n3 = nSec3
            dezena_descoberta = 1
            print(n3, end=" ")
            acert += 1
        elif centena_descoberta == 1 and dezena_descoberta == 0 and i <= 6 and dica == 1:
            print("Par" if nSec3 % 2 == 0 else "Ímpar", end=" ") if i % 2 == 0 else print(">=5" if nSec3 >= 5 else "<5", end=" ")
            err_dezena += 1
            if err_dezena >= 2:
                dezena_descoberta = 1
            dica = 0
        else:
            if n3 == 0:
                print('_', end=" ")
            else:
                print(n3,end=" ")

        if nSec4 == nAdv4:
            n4 = nSec4
            unidade_descoberta = 1
            print(n4)
            acert += 1
        elif dezena_descoberta == 1 and unidade_descoberta == 0 and i <= 6 and dica == 1:
            print("Par" if nSec4 % 2 == 0 else "Ímpar") if i % 2 == 0 else print(">=5" if nSec4 >= 5 else "<5")
            err_unidade += 1
            if err_unidade >= 2:
                unidade_descoberta = 1
            dica = 0
        else:
            if n4 == 0:
                print('_')
            else:
                print(n4)

        tent += 1
        if nSec == ((n1 * 1000) + (n2 * 100) + (n3 * 10) + (n4 * 1)):
            i = -1
        else:
            i -= 1
            if acert == 0:
                print('\nVocê não acertou nenhum dígito...')
            else:
                print(f'\nVocê acertou {acert} dígito(s)...')
            print(f'Restam {i} tentativas...')
            input(f'\t\t\t<<< Pressione Enter >>>')
    else:
        if i == 0:
            print(f'Número de Tentativas Excedidas!!!\n\nVOCÊ PERDEU!\nA SENHA ERA: {nSec}')
            input(f'\n\t\t\t<<< Pressione Enter >>>')
        else:
            print(f'\n\tP A R A B É N S ! ! !\n\n\t\tVocê adivinhou a senha: {nSec}\n\tem {tent} tentativas...')
            input(f'\n\t\t\t<<< Pressione Enter >>>')
        programaAtivo = int(input('Jogar De Novo? 1=SIM E 0=NÃO\n'))
