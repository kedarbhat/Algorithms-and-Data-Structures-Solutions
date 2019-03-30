import numpy as np


# https://www.hackerrank.com/challenges/np-arrays/problem


def arrays(elements: str) -> np.array:
    return np.array(elements.split()[::-1], dtype=float)
