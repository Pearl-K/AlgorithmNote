# 모든 간선을 다 체크해줘야 하기 때문에 O(VE)로 시간 복잡도 높음
# 음수 간선이 없다면 더 효율적인 다익 등을 사용하는게 좋음

def bellman_ford(start):
    dist[start] = 0

    for i in range(N):
        for j in range(M):
            now = edge[j][0]
            next = edge[j][1]
            w = edge[j][2]

            if dist[now] != INF and dist[next] > dist[now] + w:
                dist[next] = dist[now] + w

                if i == N-1:
                    return False
    return True
