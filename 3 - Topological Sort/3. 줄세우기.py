# 백준 2252 줄세우기 : https://www.acmicpc.net/problem/2252

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
degree = [0]*(N+1)
graph = [[] for i in range(N+1)]

for i in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    degree[b] += 1

from collections import deque
Q = deque()

for i in range(1, N+1):
    if degree[i] == 0:
        Q.append(i)

res = []
while Q:
    node = Q.popleft()
    res.append(node)

    for i in graph[node]:
        degree[i] -= 1
        if degree[i] == 0:
            Q.append(i)

print(*res)
