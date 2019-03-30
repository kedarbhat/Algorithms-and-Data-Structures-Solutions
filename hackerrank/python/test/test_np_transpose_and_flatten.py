import unittest

import numpy as np

from hackerrank.python.src import np_transpose_and_flatten


class HackerrankTestCase(unittest.TestCase):
    def test(self):
        data = (["1", "2"], ["3", "4"])
        transposed, flattened = np_transpose_and_flatten.transpose_and_flatten(data)
        self.assertTrue(np.array_equal(transposed, np.array(data, dtype=int).transpose()))
        self.assertTrue(np.array_equal(flattened, np.array(data, dtype=int).flatten()))


if __name__ == '__main__':
    unittest.main()
