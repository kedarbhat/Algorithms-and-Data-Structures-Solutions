#!/usr/bin/python3

def find_runner_up(arr):
    arr = tuple(sorted(set(arr), reverse=True))
    return arr[1]

if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())
    print(find_runner_up(arr))
