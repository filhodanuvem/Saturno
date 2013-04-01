import unittest
import lp.matrix.decomplu as m

class ValidateMethodsLU(unittest.TestCase):

    def test_matrix_mult(self):
        a = [
            [2, 1],
            [1, 2],
        ]
        b = [ 
            [3, 5], 
            [1, 2]
        ]

        found = [
            [7, 12],
            [5,  9]
        ]

        self.assertEqual(m.matrix_mult(a, b), found)