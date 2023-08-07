#백준 7569번 3차원 토마토 : https://www.acmicpc.net/problem/7569

import sys
from collections import deque
input = sys.stdin.readline
M, N, H = map(int, input().split())
graph = []

for i in range(H):
    floor = []
    for j in range(N):
        floor.append(list(map(int, input().split())))
    graph.append(floor)

dz = [1, -1, 0, 0, 0, 0]
dx = [0, 0, 1, -1, 0, 0]
dy = [0, 0, 0, 0, 1, -1]

Q = deque()
for i in range(H):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 1:
                Q.append((i, j, k))
cnt = 0
while Q: #BFS
    z, x, y = Q.popleft()

    for i in range(6):
        nz, nx, ny = z+dz[i], x+dx[i], y+dy[i]

        if 0<=nz<H and 0<=nx<N and 0<=ny<M and graph[nz][nx][ny] == 0 :
            graph[nz][nx][ny] = graph[z][x][y] + 1
            Q.append((nz, nx, ny))
