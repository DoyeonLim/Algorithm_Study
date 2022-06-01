import sys
import heapq

input = sys.stdin.readline
INF = sys.maxsize
n, e = map(int, input().split())

k = int(input())

dp = [INF]*(n+1)
heap = []
graph = [[] for _ in range(n + 1)]

for _ in range(e):
    u, v, w = map(int, input().split())
    graph[u].append((w, v))

def dijkstra(start):
    dp[start] = 0
    heapq.heappush(heap,(0, start))
    while heap:
        weight, now = heapq.heappop(heap)
        if dp[now] < weight:
            continue
        for w, next in graph[now]:
            next_weight = w + weight
            if next_weight < dp[next]:
                dp[next] = next_weight
                heapq.heappush(heap,(next_weight,next))

dijkstra(k)

for i in range(1,n+1):
    print("INF" if dp[i] == INF else dp[i])