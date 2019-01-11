#!/bin/python3

def get_list_comprehension(x: int, y: int, z: int, n: int) -> list:
    list_comprehension = [[i,j,k] for i in range(x+1) for j in range(y+1) for k in range(z+1) if i+j+k != n]
    return list_comprehension

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    print(get_list_comprehension(x,y,z,n))


