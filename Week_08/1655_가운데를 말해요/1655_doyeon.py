import heapq
import sys

n = int(sys.stdin.readline())

left = []
right = []

for i in range(n):
    num = int(sys.stdin.readline())

    if len(left) == len(right): #leftheap에 넣기
        heapq.heappush(left, -num)
    else: #rightheap에 넣기
        heapq.heappush(right, num)

    if right and right[0] < -left[0]: #right에 작은 값이 들어갈 경우 교환
        left_val = heapq.heappop(left)
        right_val = heapq.heappop(right)

        heapq.heappush(left -right_val)
        heapq.heappush(right, -left_val)

    print(-left[0])