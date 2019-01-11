#!/bin/python3

def is_leap(year: int) -> str:
    return f'{"True"}' if ((year % 4 == 0) and ((year % 100 != 0) or (year % 400 == 0))) else f'{"False"}'

if __name__ == '__main__':
    print(is_leap(int(input())))
