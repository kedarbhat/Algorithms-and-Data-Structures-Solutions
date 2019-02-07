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


class IsLeapYear:
    """ Class to check if a given year is a leap year """
    @classmethod
    def is_leap_year(cls, year: int) -> str:
        """
        Check if a year (integer) is a leap year
        :param year:
        :return: 'True' if year is a leap year, otherwise 'False'
        """
        return f'{"True"}' if ((year % 4 == 0) and ((year % 100 != 0) or (year % 400 == 0))) else f'{"False"}'


if __name__ == '__main__':
    print(IsLeapYear.is_leap_year(int(input())))
