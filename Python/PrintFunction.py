#!/usr/bin/python3

def print_fn(n: int) -> None:
    print(*(i for i in range(1,n+1)), sep='')

if __name__ == '__main__':
    print_fn(int(input()))

