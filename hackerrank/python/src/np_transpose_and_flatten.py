from typing import Tuple

import numpy as np


# https://www.hackerrank.com/challenges/np-transpose-and-flatten/problem


def transpose_and_flatten(data: tuple) -> Tuple:
    arr = np.array(data, dtype=int)
    return arr.transpose(), arr.flatten()
