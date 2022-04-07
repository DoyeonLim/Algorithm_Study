from sys import stdin

k, n = map(int, input().split())
arr = [int(stdin.readline()) for _ in range(k)]
start, end = 1, max(arr)

while start <= end:
    mid = (start + end) // 2
    line = 0
    for i in arr:
        line += i // mid #이 부분을 잘 모르겠..왜?

    if line >= n:
        start = mid + 1
    else:
        end = mid - 1

print(end)