# Problem : https://www.hackerrank.com/challenges/fibonacci-modified/problem
# NON_DP

def solve(a, b, n):
    if n == 0:
        return a
    if n == 1:
        return b
    if n == 2:
        return a + b * b
    t = solve(a, b, n - 1)
    return t * t + solve(a, b, n - 2)

a, b, n = [int(x) for x in input().strip().split(' ')]

print(solve(a, b, n - 1))