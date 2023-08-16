#백준 1005 : https://www.acmicpc.net/problem/1005

from collections import deque
import sys
input = sys.stdin.readline
T = int(input())

for i in range(T):
    N, K = map(int, input().split())
    cost = [0] + list(map(int, input().split()))
    degree = [[] for x in range(N+1)]
    cnt_d = [-1] + [0]*N

    for j in range(K):
        a, b = map(int, input().split())
        degree[a].append(b)
        cnt_d[b] += 1

    goal = int(input())

    dp = [0]*(N+1)
    Q = deque()

    for l in range(1, N+1):
        if cnt_d[l] == 0: #진입 차수 0
            Q.append(l)
            dp[l] = cost[l]

    while Q:
        cur_node = Q.popleft()
        for node in degree[cur_node]:
            cnt_d[node] -= 1
            dp[node] = max(dp[node], dp[cur_node] + cost[node])
            if cnt_d[node] == 0:
                Q.append(node)
        if cnt_d[goal] == 0:
            print(dp[goal])
            break
