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


class ArithmeticOperators:
    """
    class for integral arithmetic operations
    """

    @classmethod
    def add(cls, lhs: int, rhs: int) -> int:
        """
        integral addition
        :param lhs: int
        :param rhs: int
        :return: integral sum of lhs and rhs
        """
        return lhs + rhs

    @classmethod
    def subtract(cls, lhs: int, rhs: int) -> int:
        """
        integral subtraction
        :param lhs: int
        :param rhs: int
        :return: integral difference of lhs and rhs
        """
        return lhs - rhs

    @classmethod
    def multiply(cls, lhs: int, rhs: int) -> int:
        """
        integral product
        :param lhs: int
        :param rhs: int
        :return: integral product of lhs and rhs
        """
        return lhs * rhs


if __name__ == '__main__':
    a: int = int(input())
    b: int = int(input())
    for f in (ArithmeticOperators.add, ArithmeticOperators.subtract, ArithmeticOperators.multiply):
        print(f(a, b))
