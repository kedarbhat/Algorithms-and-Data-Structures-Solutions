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

from operator import itemgetter


def find_runner_up(scores: map) -> int:
    """
    Find the second place score
    :param scores: map object
    :return: int
    """
    return itemgetter(1)(tuple(sorted(set(scores), reverse=True)))


if __name__ == '__main__':
    n: int = int(input())
    scores_map: map = map(int, input().split())
    print(find_runner_up(scores_map))
