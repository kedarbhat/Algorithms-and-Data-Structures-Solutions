import numpy as np


# https://www.hackerrank.com/challenges/np-concatenate/problem


def concatenate(n_tuple: tuple, m_tuple: tuple) -> np.array:
    return np.concatenate((np.array(n_tuple, dtype=int), np.array(m_tuple, dtype=int)))
