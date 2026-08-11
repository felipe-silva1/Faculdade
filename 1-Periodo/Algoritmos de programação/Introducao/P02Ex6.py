temp = float(input('Entre com o tempo gasto na viagem em horas: '))
vel = float(input('Entre com a velocidade média do automóvel: '))
dist = vel * temp
cons = dist / 12
print(f'\n\tVelocidade média: {vel : .1f}km/h\n\tTempo gasto na viagem: {temp : .2f}h\n\tDistância percorrida: {dist : .1f}km\n\tQuantidade de combustível consumido: {cons : .1f}L')