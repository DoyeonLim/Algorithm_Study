from itertools import combinations

n, m = map(int, input().split())
list = [i for i in range(1, n+1)]

for i in combinations(list, m):
    print(' '.join(map(str, i)))