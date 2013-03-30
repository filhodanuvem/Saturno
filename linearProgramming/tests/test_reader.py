import unittest
from os import path
from lp.matrix.file import Reader

class ValidateReader(unittest.TestCase):

    def test_if_file_exists(self):
        file_path = path.abspath('./tests/foo')
        reader = Reader(file_path)
        
        return True

    def test_if_file_not_found(self):
        file_path = path.abspath('./tests/bar')
        self.assertRaises(OSError, Reader, file_path)


    def test_get_size_matrix(self):
        file_path = path.abspath('./tests/foo')
        reader = Reader(file_path)
        order = reader.getOrder()

        self.assertEqual([3, 6], order);


    def test_get_matrix_order_quad(self):
        """this method reads a file with matrix 2x2 
	   but your first line had only a number 2"""
        
        file_path = path.abspath('./tests/fooquad')
        reader = Reader(file_path)
        order = reader.getOrder()

        self.assertEqual([2, 2], order);


    def test_get_matrix(self):
        file_path = path.abspath('./tests/foo')
        reader = Reader(file_path)
        
        expected = [
            [2, 1, 1, 1, 0, 0],
            [1, 2, 3, 0, 1, 0],
            [2, 2, 1, 0, 0, 1],
        ]
        found = reader.getMatrix()
        self.assertEqual(expected, found)

    def test_get_b(self):
        file_path = path.abspath('./tests/foo')
        reader = Reader(file_path)
        
        expected = [2, 5, 6]
        found = reader.getB()
        self.assertEqual(expected, found)

    def test_get_c(self):
        file_path = path.abspath('./tests/foo')
        reader = Reader(file_path)
        
        expected = [-3, -1, -3, 0, 0, 0]
        found = reader.getC()
        self.assertEqual(expected, found)









