def fatoracao(num):
    fat = 1
    for num in range(num, 1, -1):
        fat *= num
        print(fat) 
num = int(input('Entre com um número: '))
fatoracao(num)
