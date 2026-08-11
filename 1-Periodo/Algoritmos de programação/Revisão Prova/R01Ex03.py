A = int(input('A: '))
B = int(input('B: '))
C = int(input('C: '))

if A != B and A != C and B !=C:
    if A > B and A > C:
        if B > C:
            print(f'{A}, {B}, {C}')
        else:
            print(f'{A}, {C}, {B}')
    elif B > C:
        if A > C:
            print(f'{B}, {A}, {C}')
        else:
            print(f'{B}, {C}, {A}')
    else:
        if A > B:
            print(f'{C}, {A}, {B}')
        else:
            print({C}, {B}, {A})
else:
    print('Digite números diferentes!')