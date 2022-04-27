n = int(input())
number = 0

for i in range(1, n+1):
    lis = list(map(int, str(i)))
    if i < 100:
        number += 1
    elif lis[0]-lis[1] == lis[1]-lis[2]:
        number += 1

print(number)