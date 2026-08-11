programaAtivo = 1
voos = dict()
passageiros = dict()
disponiveis = []
compra = []

while programaAtivo == 1:
    print(f'''
------- Menu -------
1. Cadastrar Voo.
2. Consultar um Voo.
3. Informar o Voo com Menor Escala.
4. Listar Passageiros de um Voo.
5. Venda de Passagem.
6. Cancelamento de Passagem.
0. Encerrar programa.
--------------------''')
    
    menu = int(input('Escolha uma opção: '))

    if menu == 1:
        print("\n--- Cadastro de Voo ---")
        nVoo = int(input('Entre com o número do voo: '))
        if nVoo in voos:
            print(f"Erro: O voo número {nVoo} já existe.")
            continue
        cidadeO = input('Entre com a cidade de origem: ')
        cidadeD = input('Entre com a cidade de destino: ')
        nEscala = int(input('Entre com o número de escalas: '))
        preco = float(input('Entre com o preço da passagem: '))
        lugares = int(input('Entre com o número de lugares: '))
        if lugares < 0 or nEscala < 0 or preco < 0:
            print("Erro: Número de escalas, preço e lugares não podem ser negativos.")
            continue
        
        voos[nVoo] = [cidadeO, cidadeD, nEscala, preco, lugares]
        if lugares > 0:
            disponiveis.append(voos[nVoo])
        print(f"Voo {nVoo} cadastrado com sucesso!")

    elif menu == 2:
        print("\n--- Consulta de Voo ---")
        consulta = int(input(f'Tipos de Consulta\n1. Código do voo.\n2. Cidade Origem.\n3. Cidade Destino.\nEscolha o tipo de consulta: '))
            
        if consulta == 1:
            codigo = int(input('Entre o código que você deseja buscar: '))
            if codigo in voos:
                detalhes = voos[codigo]
                print(f"Detalhes do Voo {codigo}: Origem: {detalhes[0]}, Destino: {detalhes[1]}, Escalas: {detalhes[2]}, Preço: R${detalhes[3]:.2f}, Lugares: {detalhes[4]}")
            else:
                print('Voo não encontrado.')
        elif consulta == 2:
            cidadeOB = input('Entre a cidade de origem que você deseja buscar: ')
            encontrado = False
            for n_voo, voo_detalhes in voos.items():
                if voo_detalhes[0].lower() == cidadeOB.lower():
                    print(f"Voo {n_voo}: Origem: {voo_detalhes[0]}, Destino: {voo_detalhes[1]}, Escalas: {voo_detalhes[2]}, Preço: R${voo_detalhes[3]:.2f}, Lugares: {voo_detalhes[4]}")
                    encontrado = True
            if not encontrado:
                print(f'Nenhum voo encontrado com origem em {cidadeOB}.')
        elif consulta == 3:
            cidadeDB = input('Entre com a cidade de destino que você deseja buscar: ')
            encontrado = False
            for n_voo, voo_detalhes in voos.items():
                if voo_detalhes[1].lower() == cidadeDB.lower():
                    print(f"Voo {n_voo}: Origem: {voo_detalhes[0]}, Destino: {voo_detalhes[1]}, Escalas: {voo_detalhes[2]}, Preço: R${voo_detalhes[3]:.2f}, Lugares: {voo_detalhes[4]}")
                    encontrado = True
            if not encontrado:
                print(f'Nenhum voo encontrado com destino para {cidadeDB}.')
        else:
            print("Tipo de consulta inválido.")

    elif menu == 3:
        print("\n--- Voo com Menor Número de Escalas ---")
        cidadeOB = input('Entre a cidade de origem que você deseja: ')
        cidadeDB = input('Entre a cidade de destino que você deseja: ')
        
        menor_n_escalas = float('inf')
        voo_com_menor_escala = None
        rota_encontrada = False

        for n_voo, detalhes_voo in voos.items():
            if detalhes_voo[0].lower() == cidadeOB.lower() and detalhes_voo[1].lower() == cidadeDB.lower():
                rota_encontrada = True
                if detalhes_voo[2] < menor_n_escalas:
                    menor_n_escalas = detalhes_voo[2]
                    voo_com_menor_escala = (n_voo, detalhes_voo)
        
        if voo_com_menor_escala:
            n_voo, detalhes = voo_com_menor_escala
            print(f"\nVoo com menor número de escalas ({menor_n_escalas}) de {cidadeOB} para {cidadeDB}:")
            print(f"Número do Voo: {n_voo}, Origem: {detalhes[0]}, Destino: {detalhes[1]}, Escalas: {detalhes[2]}, Preço: R${detalhes[3]:.2f}, Lugares: {detalhes[4]}")
        elif rota_encontrada:
            print(f"Foram encontrados voos de {cidadeOB} para {cidadeDB}, mas não foi possível determinar o de menor escala.")
        else:
            print(f"Nenhum voo encontrado de {cidadeOB} para {cidadeDB}.")

    elif menu == 4:
        print("\n--- Listar Passageiros de um Voo ---")
        voo_codigo = int(input('Digite o número do voo para listar os passageiros: '))
        if voo_codigo in voos:
            print(f'\nPassageiros do voo {voo_codigo}:')
            algum_passageiro_encontrado = False
            for cpf, dados_passageiro in passageiros.items():
                if dados_passageiro[2] == voo_codigo:
                    print(f"CPF: {cpf}, Nome: {dados_passageiro[0]}, Telefone: {dados_passageiro[1]}, Quantidade: {dados_passageiro[3]}")
                    algum_passageiro_encontrado = True
            if not algum_passageiro_encontrado:
                print(f"Nenhum passageiro encontrado para o voo {voo_codigo}.")
        else:
            print('Voo não encontrado.')

    elif menu == 5:
        print("\n--- Venda de Passagem ---")
        print("Voos com lugares disponíveis:")
        
        mapa_opcao_para_voo = {}
        contador_opcao = 1
        
        for detalhes_voo_ref in disponiveis: 
            if detalhes_voo_ref[4] > 0:
                num_voo_atual = None
                for n_voo, det_v in voos.items():
                    if det_v is detalhes_voo_ref:
                        num_voo_atual = n_voo
                        break
                
                if num_voo_atual is not None:
                    print(f"{contador_opcao}. Voo {num_voo_atual}: {detalhes_voo_ref[0]} para {detalhes_voo_ref[1]}, Lugares: {detalhes_voo_ref[4]}, Preço: R${detalhes_voo_ref[3]:.2f}")
                    mapa_opcao_para_voo[contador_opcao] = num_voo_atual
                    contador_opcao += 1
        
        if not mapa_opcao_para_voo:
            print("Nenhum voo com lugares disponíveis no momento (verifique cadastros e vendas anteriores).")
            continue

        escolha_opcao_lista = int(input("Escolha o número do voo da lista acima para comprar: "))
        voo_escolhido_num = mapa_opcao_para_voo.get(escolha_opcao_lista)

        if voo_escolhido_num is None:
            print("Seleção inválida.")
            continue
    
        cpf = input('Entre com o seu CPF: ')
        if cpf in passageiros and passageiros[cpf][2] == voo_escolhido_num:
             print(f"CPF {cpf} já possui passagem(ns) para o voo {voo_escolhido_num}. Para comprar mais, cancele e compre novamente a quantidade total desejada.")
             continue

        nome = input('Entre com o seu nome: ')
        tel = input('Entre com o seu número de telefone: ')
        
        passagens_a_comprar = int(input(f'Quantas passagens para o voo {voo_escolhido_num} (Disponíveis: {voos[voo_escolhido_num][4]})? '))

        if passagens_a_comprar <= 0:
            print("Número de passagens deve ser positivo.")
            continue

        if voos[voo_escolhido_num][4] >= passagens_a_comprar:
            voos[voo_escolhido_num][4] -= passagens_a_comprar
            passageiros[cpf] = [nome, tel, voo_escolhido_num, passagens_a_comprar]
            compra.append(list(passageiros[cpf]))
            print(f"{passagens_a_comprar} passagem(ns) comprada(s) com sucesso para o voo {voo_escolhido_num}!")
        else:
            print(f"Não há {passagens_a_comprar} lugares disponíveis. Apenas {voos[voo_escolhido_num][4]}.")
        
    elif menu == 6:
        print("\n--- Cancelamento de Passagem ---")
        cpf_cancelar = input('Entre com o CPF do comprador para cancelar a passagem: ')

        if cpf_cancelar in passageiros:
            dados_compra_passageiro = passageiros[cpf_cancelar]
            nome_p, tel_p, nVoo_p, qtd_p = dados_compra_passageiro

            print(f"\nPassageiro: {nome_p}")
            print(f"Voo: {nVoo_p} ({voos[nVoo_p][0]} para {voos[nVoo_p][1]})")
            print(f"Quantidade de passagens: {qtd_p}")
            
            confirmacao = input("Deseja realmente cancelar esta(s) passagem(ns)? (s/n): ").lower()

            if confirmacao == 's':
                voos[nVoo_p][4] += qtd_p
                del passageiros[cpf_cancelar]
                
                registro_compra_para_remover = [nome_p, tel_p, nVoo_p, qtd_p]
                if registro_compra_para_remover in compra:
                    compra.remove(registro_compra_para_remover)
                else:
                    print("Aviso: O registro da compra não foi encontrado na lista 'compra' para remoção exata, mas o passageiro foi removido e os assentos devolvidos.")

                print("Passagem(ns) cancelada(s) com sucesso!")
            else:
                print("Cancelamento não efetuado.")
        else:
            print("CPF não encontrado ou sem passagens compradas para cancelar.")

    elif menu == 0:
        print("Encerrando programa...")
        programaAtivo = 0
    
    else:
        print("Opção inválida. Tente novamente.")

    if programaAtivo != 0:
        input("\nPressione Enter para continuar...")

print("Programa encerrado.")
