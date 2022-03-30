n, r, c = map(int, input().split())
count = 0

while n != 0:
    n -= 1

    #제1사분면
    if r < 2**n and c < 2**n:
        count += (2**n) * (2**n) * 0

    #제2사분면
    elif r < 2**n and c >= 2**n:
        count += (2**n) * (2**n) * 1
        c -= (2**n)

    #제3사분면
    elif r >= 2**n and c < 2**n:
        count += (2**n) * (2**n) * 2
        r -= (2**n)

    #제4사분면
    else:
        count += (2**n) * (2**n) * 3
        r -= (2**n)
        c -= (2**n)

print(count)