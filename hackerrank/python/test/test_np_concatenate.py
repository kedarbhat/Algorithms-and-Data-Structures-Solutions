import unittest

import numpy as np

from hackerrank.python.src import np_concatenate


class HackerRankTestCase(unittest.TestCase):
    def test(self):
        n, m = 4, 3
        n_data = tuple([(1, 2)] * n)
        m_data = tuple([(3, 4)] * m)
        concatenated = np_concatenate.concatenate(n_data, m_data)
        self.assertTrue(
            np.array_equal(concatenated, np.concatenate((np.array(n_data, dtype=int), np.array(m_data, dtype=int)))))


if __name__ == '__main__':
    unittest.main()
