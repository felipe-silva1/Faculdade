programaAtivo = 1
boletim = []
registro = []
T = []
P = []
M = []
nAlunos = 0
while programaAtivo == 1:
    nome = input("Entre com o nome do aluno: ")
    T1 = float(input("Entre com a nota da primeira prova teórica: "))
    T.append(T1)
    T2 = float(input("Entre com a nota da segunda prova teórica: "))
    T.append(T2)
    P1 = float(input("Entre com a nota do primeiro projeto: "))
    P.append(P1)
    P2 = float(input("Entre com a nota do segundo projeto: "))
    P.append(P2)
    MT = (0.4 * T1) + (0.6 * T2)
    M.append(MT)
    MP = (P1 + P2) / 2
    M.append(MP)
    if MP > 5 and MT > 5:
        MF = (0.3 * MP) + (0.7 * MT)
    else:
        if MP > MT:
            MF = MT
        elif MP < MT:
            MF = MP
        else:
            MF = MP
    registro.append([nome,T,P,M,MF])
    nAlunos += 1
    menu = int(input(f"Boletim dos alunos(as)\n\t1. Boletim completo de todos alunos\n\t2. Imprimir Boletim de um aluno por nome\n\t3.Aluno Com a Maior Média\n\t4. Aluno Com a Menor Média\n\t5. Percentual Dos Alunos com média superior a 5\n\t0. Encerrar Programa"))
    while menu != 0 and menu != 1 and menu != 2 and menu != 3 and menu != 4 and menu != 5:
        menu = int(input(f"Boletim dos alunos(as)\n\t1. Boletim completo de todos alunos\n\t2. Imprimir Boletim de um aluno por nome\n\t3.Aluno Com a Maior Média\n\t4. Aluno Com a Menor Média\n\t5. Percentual Dos Alunos com média superior a 5\n\t0. Encerrar Programa"))  
    if menu == 1:
        for i in range(nAlunos):
            for j in range(len(registro)):
                print(registro[i][j])
