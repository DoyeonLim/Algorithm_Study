from sys import stdin
import heapq

heap = []
n = int(stdin.readline())

for _ in range(n):
    m = int(stdin.readline())
    if m == 0:
        if heap:
            print((-1)*heapq.heappop(heap)) #최소 힙 -> 최대 힙(음수 변환)
        else:
            print("0")
    else:
        heapq.heappush(heap, -m) #다시 양수 변환