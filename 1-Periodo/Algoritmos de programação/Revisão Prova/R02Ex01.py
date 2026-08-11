'''Programa 1
def proc7(msg = "Olá", repetir = 1):
    for _ in range(repetir):
        print(msg + "!")
proc7()
#Olá!
proc7(msg="Mundo")
#Mundo!
proc7(repetir=4)
#Olá!
#Olá!
#Olá!
#Olá!
proc7(msg="Python", repetir=2)
#Python!
#Python!'''

'''Programa 2
def func10(inicial, ajuste=0, multiplicar_por=1):
    valor_final = (inicial + ajuste) * multiplicar_por
    return valor_final

final11 = func10(10)
#10
final12 = func10(inicial=5, ajuste=2)
#7
final13 = func10(2, multiplicar_por=5)
#10
final14 = func10(inicial=1, ajuste=-3,multiplicar_por=10)
#-20
print(f"Resultados da função 10: {final11}, {final12}, {final13}, {final14}")'''