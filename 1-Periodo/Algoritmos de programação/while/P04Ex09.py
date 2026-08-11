sal = 0
cid = 0
sSal = 0
sFil = 0
mSal = -999999
cont = 0
while sal >= 0:
    sal = float(input(f'Entre o salário: '))
    fil = int(input(f'Entre a quantidade de filho: '))
    sSal += sal
    sFil += fil
    if sal > mSal:
        mSal = sal
    if sal < 100:
        cont += 1
    cid += 1
print(f'\n\ta. {sSal / cid}\n\tb. {sFil / cid}\n\tc. {mSal}\n\td. {(cont / cid) * 100}%')
