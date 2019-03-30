import numpy


# https://www.hackerrank.com/challenges/np-shape-reshape/problem


def shape_reshape(elements: str) -> numpy.array:
    return numpy.reshape(numpy.array(elements.split(), dtype=int), (3, 3))
