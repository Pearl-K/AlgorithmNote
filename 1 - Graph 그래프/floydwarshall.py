def Floyd_W(graph, n):
    for k in range(n):
        for p in range(n):
            for q in range(n):
                if graph[p][q] > graph[p][k] + graph[k][q]:
                    graph[p][q] = graph[p][k] + graph[k][q]
