vc = int(input('Entre com o valor da compra: '))
vp = int(input('Entre com o valor pago pelo cliente: '))
troco = vp - vc
print(f'\nCompra: R${vc}.\nPagamento: R${vp}.\nTroco: R${troco}.')
tcem = troco // 100
troco = troco % 100
tcinq = troco // 50
troco = troco % 50
tvin = troco // 20
troco = troco % 20
tdez = troco // 10
troco = troco % 10
tcinc = troco // 5
troco = troco % 5
tum = troco // 1
print(f'\nEm: \n\tR$100,00: {tcem} células.\n\tR$50,00: {tcinq} células.\n\tR$20,00: {tvin} células.\n\tR$10,00: {tdez} células.\n\tR$5,00: {tcinc} células.\n\tR$1,00: {tum} células.')