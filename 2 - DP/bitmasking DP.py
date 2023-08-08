#백준 1562 계단수 : https://www.acmicpc.net/problem/1562

import sys
input = sys.stdin.readline

MOD = 1000000000
N = int(input())
B = (1<<10)-1

dp = [[0]*(B+1) for i in range(10)]

for i in range(1, 10):
    dp[i][1<<i] = 1

for _ in range(2, N+1):
    res = [[0]*(B+1) for i in range(10)]

    for i in range(10):
        for j in range(B+1):
            if i > 0:
                res[i][j|(1<<i)] = (res[i][j|(1<<i)] + dp[i-1][j])%MOD
            if i < 9:
                res[i][j|(1<<i)] = (res[i][j|(1<<i)] + dp[i+1][j])%MOD
    dp = res

result = sum(dp[i][B] for i in range(10))%MOD
print(result)
