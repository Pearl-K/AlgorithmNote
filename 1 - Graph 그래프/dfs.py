#백준 1012 유기농 배추 코드 : https://www.acmicpc.net/source/56602341

def dfs(x, y):
    dx = [0, 0, -1, 1]
    dy = [-1, 1, 0, 0]

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (0 <= nx < N) and (0 <= ny < M):
            if graph[nx][ny] == 1:
                graph[nx][ny] = 0
                dfs(nx, ny)
