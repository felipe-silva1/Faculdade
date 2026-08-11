n = int(input('Entre com um número: '))
i = 0
j = 0
x = 0
aux = 0
while n >= i:
    if i == 0:
        x = 2
    elif i > 2:
        x *= i
    i += 1
print(f'{n}! = {x}')