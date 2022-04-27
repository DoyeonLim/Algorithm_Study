import sys
from itertools import combinations

input = sys.stdin.readline #시간 초과로 인해 찾은 추가 코드 부분

n, m = map(int, input().split())
list = list(map(int, input().split()))
cnt = 0

for i in range(1, n+1):
    c = combinations(list, i)
    for j in c:
        if sum(j) == m:
            cnt += 1

print(cnt)