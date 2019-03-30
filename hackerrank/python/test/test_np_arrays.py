import unittest

import numpy as np

from hackerrank.python.src import np_arrays


class HackerrankTestCase(unittest.TestCase):
    def test(self):
        self.assertTrue(
            np.array_equal(np_arrays.arrays("1 2 3 4 -8 -10"),
                           np.array("-10.  -8.   4.   3.   2.   1.".split(), dtype=float)))


if __name__ == '__main__':
    unittest.main()
