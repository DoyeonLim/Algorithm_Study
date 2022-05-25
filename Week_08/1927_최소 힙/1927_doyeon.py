from sys import stdin
import heapq

heap = []
n = int(stdin.readline())

for _ in range(n):
    m = int(stdin.readline())
    if m == 0:
        if heap:
            print(heapq.heappop(heap))
        else:
            print("0")
    else:
        heapq.heappush(heap, m)