from sys import stdin
n = stdin.readline()
n_list = sorted(map(int,stdin.readline().split()))
m = stdin.readline()
m_list = map(int,stdin.readline().split())

def binary_search(target, n_list, start, end):
    if start > end:
        return 0
    mid = (start+end)//2
    if target == n_list[mid]:
        return n_list[start:end+1].count(target)
    elif target < n_list[mid]:
        return binary_search(target, n_list, start, mid-1)
    else:
        return binary_search(target, n_list, mid+1, end)

n_list_dic = {}
for i in n_list:
    start = 0
    end = len(n_list) - 1
    if n not in n_list_dic:
        n_list_dic[i] = binary_search(i, n_list, start, end)

print(' '.join(str(n_list_dic[x]) if x in n_list_dic else '0' for x in m_list ))