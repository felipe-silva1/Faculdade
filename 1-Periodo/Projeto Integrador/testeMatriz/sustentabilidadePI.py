programaAtivo = True
i = 0
matriz = []

while programaAtivo:
    opc = int(input(f'\n--------------------Menu---------------------\n|\t[ 1 ] Fornecer Registro de Consumo. |\n|\t[ 2 ] Apagar Registro de Consumo.   |\n|\t[ 3 ] Ver Registro de Consumo.      |\n|\t[ 0 ] Sair.                         |\n---------------------------------------------\n'))

    match opc:
        case 1:
            print(f'\nResponda o questionário a seguir: ')
            data = input(f'\tQual é a data? ')
            agua = float(input(f'\tQuantos litros de água você consumiu hoje? (Aprox. em litros) '))
            eEle = float(input(f'\tQuantos kWh de energia elétrica você consumiu hoje? '))
            nRec = float(input(f'\tQuantos kg de resíduos não recicláveis você gerou hoje? '))
            pRec = float(input(f'\tQual a porcentagem de resíduos reciclados no total (em %)? '))
            
            if pRec < 0 or pRec > 100:
                print('Entre com um valor de 0 a 100 (em %)!')
                continue
            tran = int(input(f'\tQual o meio de transporte você usou hoje? \n\t\t1. Transporte público (ônibus, metrô, trem)\n\t\t2. Bicicleta\n\t\t3. Caminhada\n\t\t4. Carro (combustível fóssil)\n\t\t5. Carro Elétrico\n\t\t6. Carona Compartilhada\n'))
            if tran < 1 or tran > 6:
                print('Entre com uma opção de 1 a 6! ')
                continue 
            matriz.append([data, agua, eEle, nRec, pRec, tran])
            i += 1
        case 2:
            pass
        case 3:
            pesq = int(input('Digite o usuário que você deseja pesquisar: '))
            if pesq < 0 or pesq >= i:
                print('Digite um usuário válido!')
                continue
            else:
                print(f'{"Data" :<10}  {"Água Utilizada" :<5}  {"Energia Elétrica" : <5}  {"Lixo Não Reciclavel": <5}  {"Lixo Reciclavel": <5}  {"Transporte":<5}')
                for j in range(len(matriz[pesq])):
                    print(f'{matriz[pesq][j] :<17}', end=" ")
                print(f'\n\nClassificação de sustentabilidade\nConsumo da água')
                if matriz[pesq][1] < 150:
                    print(f'\n\tAlta Sustentabilidade')
                elif matriz[pesq][1] <= 200 and matriz[pesq - 1][1] >= 150:
                    print(f'\n\tModerada Sustentabilidade')
                else:
                    print(f'\n\tBaixa Sustentabilidade')
                print(f'\nGeração de Resíduos Não Recicláveis')
                if matriz[pesq][4] > 50:
                    print(f'\n\tAlta Sustentabilidade')
                elif matriz[pesq][4] <= 50 and matriz[pesq - 1][4] > 20:
                    print(f'\n\tModerada Sustentabilidade')
                else:
                    print(f'\n\tBaixa Sustentabilidade')
                print(f'\nConsumo de Enegia Elétrica')
                if matriz[pesq][2] < 5:
                    print(f'\n\tAlta Sustentabilidade')
                elif matriz[pesq][2] >= 5 and matriz[pesq][2] <=10:
                    print(f'\n\tModerada Sustentabilidade')
                else:
                    print(f'\n\tBaixa Sustentabilidade')
                print(f'\nUso de Transporte')
                if matriz[pesq][5] == 1 or matriz[pesq][5] == 2 or matriz[pesq][5] == 5:
                    print(f'\n\tAlta Sustentabilidade')          
        case 0:
            print('Fechando programa...')
            programaAtivo = False
