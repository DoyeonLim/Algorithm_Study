n = int(input())

for i in range(n):
    str = input()
    lis = list(str)
    sum = 0
    for j in lis:
        if j == '(':
            sum += 1
        elif j == ')':
            sum -= 1
        if sum < 0:
            print('NO')
            break
    if sum > 0:
        print('NO')
    elif sum == 0:
        print('YES')