num = int(input())
n = 666
count = 0

while True:
    if '666' in str(n):
        count += 1
    if count == num:
        print(n)
        break
    n += 1   