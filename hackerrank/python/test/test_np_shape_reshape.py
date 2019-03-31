import unittest

import numpy as np

from hackerrank.python.src import np_shape_reshape


class HackerrankTestCase(unittest.TestCase):
    def test(self):
        self.assertTrue(np.array_equal(np_shape_reshape.shape_reshape("1 2 3 4 5 6 7 8 9"),
                                       np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])))


if __name__ == '__main__':
    unittest.main()
