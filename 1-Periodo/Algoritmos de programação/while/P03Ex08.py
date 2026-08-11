x = 2
n = 4
i = 0
v = 1
while i < n:
    if i == 0:
        v *= (x * x)
    else:
        v *= x
    i = i + 1
print(f'{x} ^ {n} = {v}')