import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def dijkstra():
    q = []
    heapq.heappush(q, (graph[0][0], 0, 0))
    distance[0][0] = 0
    while q:
        cost, x, y = heapq.heappop(q)
        if x == n - 1 and y == n - 1:
            print(f'Problem {count}: {distance[x][y]}')
            break
        for i in range(4):
            x_next = x + dx[i]
            y_next = y + dy[i]
            if 0 <= x_next < n and 0 <= y_next < n:
                new_cost = cost + graph[x_next][y_next]
                if new_cost < distance[x_next][y_next]:
                    distance[x_next][y_next] = new_cost
                    heapq.heappush(q, (new_cost, x_next, y_next))

count = 1

while True:
    n = int(input())
    if n == 0:
        break
    graph = [list(map(int, input().split())) for _ in range(n)]
    distance = [[INF] * n for _ in range(n)]
    dijkstra()
    count += 1