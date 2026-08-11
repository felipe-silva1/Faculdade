nAlunos = int(input("Entre com um número de alunos: "))
registro = []
maiorN = 0
menorN = 10
melhorA = 0
piorA = 0
somaA = 0
for i in range(nAlunos):
    aluno = []
    teorica = []
    pratica = []
    medias = []

    nome = input(f"Entre com o nome do {i + 1}º aluno: ")

    notaT1 = float(input(f"Entre com a nota da primeira prova teórica do(a) {nome}: "))
    notaT2 = float(input(f"Entre com a nota da segunda prova teórica do(a) {nome}: "))
    teorica.append(notaT1)
    teorica.append(notaT2)

    notaP1 = float(input(f"Entre com a nota do primeiro projeto do(a) {nome}: "))
    notaP2 = float(input(f"Entre com a nota do segundo projeto do(a) {nome}: "))
    pratica.append(notaP1)
    pratica.append(notaP2)

    mediaT = (0.4 * notaT1) + (0.6 * notaT2)
    mediaP = (notaP1 + notaP2) / 2
    medias.append(mediaT)
    medias.append(mediaP)

    if mediaT > 5 and mediaP > 5:
        mediaF = (0.3 * mediaP) + (0.7 * mediaT)
        somaA += 1
    else:
        if mediaT > mediaP:
            mediaF = mediaP
        else:
            mediaF = mediaT

    if mediaF > maiorN:
        maiorN = mediaF
        melhorA = i

    if mediaF < menorN:
        menorN = mediaF
        piorA = i

    aluno.append(nome)
    aluno.append(teorica)
    aluno.append(pratica)
    aluno.append(medias)
    aluno.append(mediaF)
    registro.append(aluno)
pAluno = (somaA / nAlunos) * 100
menuAtivo = 1
while menuAtivo == 1:
    menu = int(input(f"---------Menu---------\n1. Boletim de médias de todos alunos\n2. Mostrar todas informações de um aluno\n3. Aluno com maior Média Final\n4. Aluno com menor Média Final\n5. Percentual de alunos com Média Final superior a 5\n0.Finalizar programa\n"))
    if menu == 0:
        menuAtivo = 0
    elif menu == 1:
        print("Registro de Médias Geral:")
        for i in range(nAlunos):
            print(f"\n\tNome: {registro[i][0]}\n\tMédia Teórica: {registro[i][3][0] : .1f}\n\tMédia Prática: {registro[i][3][1] : .1f}\n\tMédia Final: {registro[i][4] : .1f}")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
    elif menu == 2:
        nomeB = input("Entre com o nome que você deseja buscar: ")
        encontrado = 0
        for i in range(nAlunos):
            if nomeB.lower() == registro[i][0].lower():
                print(f"\n\tNome: {registro[i][0]}\n\tNotas Teóricas: {registro[i][1]}\n\tNotas Práticas: {registro[i][2]}\n\tMédias Teórica/Prática {registro[i][3]}\n\tMédia Final: {registro[i][4] : .1f}")
                encontrado = 1
        if encontrado == 0:
            print(f"\tAluno não encontrado.")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
    elif menu == 3:
        print(f"\tO Aluno de Maior Média Final é o(a) {registro[melhorA][0]}, com Média Final de {registro[melhorA][4] : .1f}.")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
    elif menu == 4:
        print(f"\tO Aluno de Menor Média Final é o(a) {registro[piorA][0]}, com Média Final de {registro[piorA][4] : .1f}.")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
    elif menu == 5:
        print(f"\tO percentual de alunos com média final superior a 5 é de {pAluno:.1f}%")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
    else:
        print("\tDigite uma opção válida!")
        input(f"\n\t\t===>Pressione Enter Para Continuar")
            