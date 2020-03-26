# Problem : https://www.hackerrank.com/challenges/fibonacci-modified/problem
# NON_DP

def solve(n):
    if n < 0:
        return 0
    if memo[n] != -1:
        return memo[n]
    t = solve(n - 1)
    memo[n] = t * t + solve(n - 2)
    return memo[n]

a, b, n = [int(x) for x in input().strip().split(' ')]

memo = [-1 for _ in range(n + 1)]
memo[0] = a
memo[1] = b
memo[2] = a + b * b

print(solve(n - 1))