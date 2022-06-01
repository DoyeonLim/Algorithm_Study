import sys
import heapq

input = sys.stdin.readline
n = int(input())
m = int(input())
INF = sys.maxsize
s = [[] for i in range(n + 1)]
dp = [INF for i in range(n + 1)]

for i in range(m):
    a, b, w = map(int, input().split())
    s[a].append([b, w])

start, end = map(int, input().split())

def dijkstra(start):
    dp[start] = 0
    heap = []
    heapq.heappush(heap, [0, start])
    while heap:
        w, n = heapq.heappop(heap)
        if dp[n] < w:
            continue
        for next, weight in s[n]:
            next_weight = w + weight
            if dp[next] > next_weight:
                dp[next] = next_weight
                heapq.heappush(heap, [next_weight, next])

dijkstra(start)

print(dp[end])