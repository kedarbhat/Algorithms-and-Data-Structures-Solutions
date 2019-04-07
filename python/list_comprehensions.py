#! /usr/bin/env python3
# coding=utf-8


"""
Copyright (C) 2019 Kedar R. Bhat

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""


def get_list_comprehension(a: int, b: int, c: int, d: int) -> list:
    """

    :param a: int
    :param b: int
    :param c: int
    :param d: int
    :return: list
    """
    list_comprehension = [[i, j, k] for i in range(a + 1) for j in range(b + 1) for k in range(c + 1) if i + j + k != d]
    return list_comprehension


if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    print(get_list_comprehension(x, y, z, n))
