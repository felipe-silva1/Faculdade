import unittest
from verificarEmprestimo import verificarElegibilidade
inadimplentes = ['Jorge','Roberto','Jessica']
class TestVerificarElegibilidade(unittest.TestCase):
    def test_elegivel(self):
        self.assertEqual(verificarElegibilidade(20, 3000, inadimplentes, "Cecilia","Superior"), (True, []))
    def test_menor_idade(self):
        self.assertEqual(verificarElegibilidade(15, 3000, inadimplentes, "Cecilia", "Superior" ), (False, ["Menor de idade."]))
    def test_renda_menor(self):
        self.assertEqual(verificarElegibilidade(20, 1750, inadimplentes, "Cecilia", "Superior"), (False, ["Renda mensal menor do que R$2000,00."]))
    def test_lista_negra(self):
        self.assertEqual(verificarElegibilidade(20, 3000, inadimplentes, "Jorge", "Superior"), (False, ["Está na lista de inadimplentes."]))
    def test_escolaridade(self):
        self.assertEqual(verificarElegibilidade(20, 3000, inadimplentes, "Cecilia", "Medio"), (False, ["Não possui ensino superior!"]))
suite = unittest.TestLoader().loadTestsFromTestCase(TestVerificarElegibilidade)
if __name__ == '__main__':
    unittest.main()