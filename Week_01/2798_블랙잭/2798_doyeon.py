n, total = map(int, input().split())
a = list(map(int, input().split()))
length = len(a)
sum = 0

for i in range(0, length - 2):
        for j in range(i + 1, length - 1):
                for k in range(j + 1, length):
                        if a[i] + a[j] + a[k] > total:
                                continue
                        else:
                                sum = max(sum, a[i] + a[j] + a[k])
print(sum)