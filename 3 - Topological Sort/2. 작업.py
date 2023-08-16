#백준 2056 작업 : https://www.acmicpc.net/problem/2056
#위상정렬과 DP를 같이 사용

import sys
input = sys.stdin.readline
N = int(input())
degree = [0]*(N+1)
dp = [0]*(N+1)
graph = [[] for i in range(N+1)]

time = [0]
for i in range(1, N+1):
    now = list(map(int, input().split()))
    time.append(now[0])

    if now[1] != 0:
        for j in range(2, len(now)):
            graph[now[j]].append(i)
            degree[i] += 1

from collections import deque
Q = deque()

for i in range(1, N+1):
    if degree[i] == 0:
        Q.append(i)
        dp[i] = time[i]

while Q:
    node = Q.popleft()
    for i in graph[node]:
        degree[i] -= 1
        dp[i] = max(dp[node]+time[i], dp[i])
        if degree[i] == 0:
            Q.append(i)

print(max(dp))
