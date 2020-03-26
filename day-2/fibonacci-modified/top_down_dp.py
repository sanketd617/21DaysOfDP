# Problem : https://www.hackerrank.com/challenges/fibonacci-modified/problem
# NON_DP

def solve(a, b, n):
    ans = a + b * b
    a = b
    b = ans
    for i in range(3, n):
        ans = a + b * b
        a = b
        b = ans
    return ans

a, b, n = [int(x) for x in input().strip().split(' ')]

print(solve(a, b, n))