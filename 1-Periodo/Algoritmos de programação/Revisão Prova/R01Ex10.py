alunos = int(input('Quantidade de Alunos: '))
somaNotas = 0
for i in range(0,alunos):
    nota = float(input(f'Nota do {i+1}º aluno: '))
    somaNotas += nota
print(f'Nota média da classe: {somaNotas / alunos : .1f}')