string1 = input('Entre com a primeira string: ')
string2 = input('Entre com a segunda string: ')

if len(string2) < len(string1) and string1[-len(string2):] == string2:
    print('A segunda string está contida na primeira!')
else:
    print('A segunda string não está contida na primeira!')