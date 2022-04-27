n, m = list(map(int, input().split()))
s = []

def dfs(number):
    if len(s) == m:
        print(' '.join(map(str, s)))
        return

    for i in range(number, n + 1):
        if i not in s:
            s.append(i)
            dfs(i + 1)
            s.pop()

dfs(1)