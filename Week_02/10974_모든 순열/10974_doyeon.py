from itertools import permutations

n = int(input())
arr = [i for i in range(1, n+1)]

for numbers in list(permutations(arr)):
    for num in numbers:
        print(num, end=' ')
    print()