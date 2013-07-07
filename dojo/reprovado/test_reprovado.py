import unittest
from reprovador import R

class TestSpoj1734(unittest.TestCase): 

    def test_ler_numero_alunos(self):
        reprovador = R('./_instancia1')
        numAlunos = reprovador.getNumAlunos()

        expected = 4
        self.assertEquals(expected, numAlunos)


    def test_ler_numero_alunos_negativo(self):
        reprovador = R('./instancia2')
        self.assertRaise(ValueError,reprovador.getNumAlunos())
