S = 0
for i in range(1,11,2):
    if i % 2 == 0:
        S -= (i / i**2)  
    else:
        S += (i / i**2)
print(f'{S : .3f}')