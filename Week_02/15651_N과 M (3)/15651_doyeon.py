from itertools import product

n, m = map(int, input().split())
list = [i for i in range(1, n+1)]

for i in product(list, repeat=m):
    print(' '.join(map(str, i)))