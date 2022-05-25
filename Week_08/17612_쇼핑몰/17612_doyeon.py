import heapq
import sys

input = sys.stdin.readline
n, k = map(int, input().split())

customer_lis = []
item_lis = []

for _ in range(n):
    customer, item = map(int, input().split())
    customer_lis.append(customer)
    item_lis.append(item)

counter = []
for i in range(k):
    heapq.heappush(counter, (0, i))

time = [0] * k

finished = []
for i in range(n):
    t, x = heapq.heappop(counter)
    time[x] += item_lis[i]
    heapq.heappush(counter, (time[x], x))
    finished.append((time[x], -x, i))

print(sum(customer_lis[t[2]] * (i+1) for i, t in enumerate(sorted(finished))))