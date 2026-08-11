nLivros = int(input('Entre com o número de livros que você deseja inserir: '))
livros = dict()

# Inserir livros
for codigo in range(nLivros):
    titulo = input('Entre com o título do livro: ')
    nAutores = int(input('Entre com o número de autores: '))
    autores = []
    for j in range(nAutores):
        autor = input(f'Entre com o nome do {j+1}º autor: ')
        autores.append(autor)  # Adicionando o autor à lista
    preco = float(input('Entre com o preço do livro: '))
    livros[codigo] = [titulo, autores, preco]

# Buscar livro por título
tituloB = input('Entre com o livro que você deseja buscar: ')
encontrado = False
for livro in livros.values():
    if livro[0] == tituloB:  # O título está na posição 0 de cada valor no dicionário
        print(livro)
        encontrado = True
        break

if not encontrado:
    print('Livro não encontrado.')

# Buscar livro por código
codigoB = int(input('Entre com o código que você deseja buscar: '))  # Convertendo para inteiro
if codigoB in livros:
    print(livros[codigoB])
else:
    print('Código não encontrado.')

# Verificar livros com preço maior que 500
for livro in livros.values():
    if livro[2] > 500:  # O preço está na posição 2 de cada valor no dicionário
        print(livro)
