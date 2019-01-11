#!/bin/python3

def print_squares(n: int) -> None:
    s = '\n'.join((str(x**2) for x in range(n)))
    print(f'{s}')

if __name__ == '__main__':
    print_squares(int(input()))

