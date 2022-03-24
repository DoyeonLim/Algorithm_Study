k = int(input())

sign = list(map(str, input().split()))
chk = [False] * 11
minResult = ""
maxResult = ""

def possible(i, j, sign):
    if sign == '>':
        return i > j
    else:
        return i < j

def solve(depth, s):
    global minResult, maxResult

    if depth == k + 1:
        if len(minResult) == 0:
            minResult = s
        else:
            maxResult = s
        return

    for i in range(10):
        if not chk[i]:
            if depth == 0 or possible(s[len(s) - 1], str(i), sign[depth - 1]):
                chk[i] = True
                solve(depth + 1, s + str(i))
                chk[i] = False

solve(0, "")
print(maxResult)
print(minResult)