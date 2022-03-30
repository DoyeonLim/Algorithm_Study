n = int(input())
count = 0

def star(n):
    result = []
    for i in range(len(n) * 3):
        if i // len(n) == 1:
            result.append(n[i % len(n)] + " " * len(n) + n[i % len(n)])
        else:
            result.append(n[i % len(n)] * 3)
    return result

list_star = ["***", "* *", "***"]

while n != 3:
    n //= 3
    count += 1

for _ in range(count):
    list_star = star(list_star)

for j in list_star:
    print(j)