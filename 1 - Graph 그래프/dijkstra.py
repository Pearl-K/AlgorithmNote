#백준 5972 택배 배송 : https://www.acmicpc.net/problem/5972

import sys
input = sys.stdin.readline

N, M = map(int, input().split())
graph = [[]*(N+1) for i in range(N+1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    # PQ 우선순위를 위해 가중치를 먼저 넣기
    graph[u].append((w, v))
    graph[v].append((w, u))

import heapq as hq
INF = sys.maxsize

def dijkstra(start):
    dist = [INF]*(N+1)
    dist[start] = 0
    PQ = []
    hq.heappush(PQ, (0, start))

    while PQ:
        now_d, node = hq.heappop(PQ)

        if dist[node] < now_d:
            continue

        for n in graph[node]:
            alt = n[0] + now_d
            if alt < dist[n[1]]:
                dist[n[1]] = alt
                hq.heappush(PQ, (alt, n[1]))
    return dist
